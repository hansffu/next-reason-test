open Jest;
open Expect;
open! Expect.Operators;

let () =
  describe("Yahtzee", () =>
    describe("calculate sum", () => {
      test("ones", () =>
        expect(Yahtzee.calculateThrow(Yahtzee.Ones(3))) |> toBe(3)
      );

      test("twos", () =>
        expect(Yahtzee.calculateThrow(Yahtzee.Twos(3))) |> toBe(6)
      );

      test("threes", () =>
        expect(Yahtzee.calculateThrow(Yahtzee.Threes(3))) |> toBe(9)
      );

      test("fours", () =>
        expect(Yahtzee.calculateThrow(Yahtzee.Fours(3))) |> toBe(12)
      );

      test("fives", () =>
        expect(Yahtzee.calculateThrow(Yahtzee.Fives(3))) |> toBe(15)
      );

      test("sixes", () =>
        expect(Yahtzee.calculateThrow(Yahtzee.Sixes(3))) |> toBe(18)
      );

      describe("three equal", () => {
        test("some fives", () => {
          let throw = Some(Yahtzee.Five);
          expect(Yahtzee.calculateThrow(Yahtzee.ThreeEqual(throw))) === 15;
        });

        test("none", () =>
          expect(Yahtzee.calculateThrow(Yahtzee.ThreeEqual(None))) === 0
        );
      });

      describe("four equal", () => {
        test("some fives", () => {
          let throw = Some(Yahtzee.Five);
          expect(Yahtzee.calculateThrow(Yahtzee.FourEqual(throw))) === 20;
        });

        test("none", () =>
          expect(Yahtzee.calculateThrow(Yahtzee.FourEqual(None))) === 0
        );
      });

      describe("full house", () => {
        test("some fives", () => {
          let throw = Some((Yahtzee.Five, Yahtzee.Two));
          expect(Yahtzee.calculateThrow(Yahtzee.FullHouse(throw))) === 19;
        });

        test("none", () =>
          expect(Yahtzee.calculateThrow(Yahtzee.FourEqual(None))) === 0
        );
      });
    })
  );