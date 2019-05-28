type dice =
  | One
  | Two
  | Three
  | Four
  | Five
  | Six;

type throw = list(dice);

type row =
  | Ones(int)
  | Twos(int)
  | Threes(int)
  | Fours(int)
  | Fives(int)
  | Sixes(int)
  | ThreeEqual(option(dice))
  | FourEqual(option(dice))
  | FullHouse(option((dice, dice)))
  | SmallStraight(bool)
  | LargeStraight(bool)
  | Yahtzee(bool)
  | Chance(list(dice));

let diceValue = dice =>
  switch (dice) {
  | One => 1
  | Two => 2
  | Three => 3
  | Four => 4
  | Five => 5
  | Six => 6
  };

let sumDices = dices =>
  dices
  |> List.map(dice => diceValue(dice))
  |> List.fold_left((a, b) => a + b, 0);

let calculateSimple = (requiredDice, throw) =>
  diceValue(requiredDice) * throw;

let calculateThreeEqual = throw =>
  switch (throw) {
  | Some(dice) => 3 * diceValue(dice)
  | None => 0
  };

let calculateFourEqual = throw =>
  switch (throw) {
  | Some(dice) => 4 * diceValue(dice)
  | None => 0
  };

let calculateFullHouse = throw =>
  switch (throw) {
  | Some((three, two)) => 3 * diceValue(three) + 2 * diceValue(two)
  | None => 0
  };

let calculateSmallStraight = throw => 0;
let calculateLargeStraight = throw => 0;
let calculateYahtzee = throw => 0;
let calculateChance = throw => 0;

let calculateThrow = (row: row) =>
  switch (row) {
  | Ones(matchingDice) => calculateSimple(One, matchingDice)
  | Twos(matchingDice) => calculateSimple(Two, matchingDice)
  | Threes(matchingDice) => calculateSimple(Three, matchingDice)
  | Fours(matchingDice) => calculateSimple(Four, matchingDice)
  | Fives(matchingDice) => calculateSimple(Five, matchingDice)
  | Sixes(matchingDice) => calculateSimple(Six, matchingDice)
  | ThreeEqual(dice) => calculateThreeEqual(dice)
  | FourEqual(dice) => calculateFourEqual(dice)
  | FullHouse(throw) => calculateFullHouse(throw)
  | SmallStraight(success) => calculateSmallStraight(success)
  | LargeStraight(success) => calculateLargeStraight(success)
  | Yahtzee(success) => calculateYahtzee(success)
  | Chance(throw) => calculateChance(throw)
  };

[@react.component]
let make = () => <div> <Board /> </div>;