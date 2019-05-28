let names = () => {
  let rowStyle =
    ReactDOMRe.Style.combine(
      Row.rowStyle,
      ReactDOMRe.Style.make(
        ~border="2px solid black",
        ~background="lightgray",
        (),
      ),
    );
  let rowTypeStyle =
    ReactDOMRe.Style.combine(
      Row.rowTypeStyle,
      ReactDOMRe.Style.make(~background="initial", ()),
    );
  <div style=rowStyle>
    <div style=rowTypeStyle> {ReasonReact.string("Name")} </div>
    <div style=Row.cellStyle> {ReasonReact.string("HF")} </div>
    <div style=Row.cellStyle> {ReasonReact.string("H")} </div>
  </div>;
};

[@react.component]
let make = () => {
  let style = ReactDOMRe.Style.make(~display="grid", ());

  <div style>
    {names()}
    <Row rowName="Ones" />
    <Row rowName="Twos" />
    <Row rowName="Threes" />
    <Row rowName="Fours" />
    <Row rowName="Fives" />
    <Row rowName="Sixes" />
  </div>;
};