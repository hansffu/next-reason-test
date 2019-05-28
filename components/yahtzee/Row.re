let rowStyle =
  ReactDOMRe.Style.make(~border="1px solid black", ~display="flex", ());
let rowTypeStyle =
  ReactDOMRe.Style.make(~flexGrow="1", ~background="lightcyan", ());
let cellStyle =
  ReactDOMRe.Style.make(
    ~border="1px solid black",
    ~width="30px",
    ~padding="10px",
    ~textAlign="center",
    (),
  );
[@react.component]
let make = (~rowName) => {
  <div style=rowStyle>
    <div style=rowTypeStyle> {ReasonReact.string(rowName)} </div>
    <div style=cellStyle> {ReasonReact.string("3")} </div>
    <div style=cellStyle> {ReasonReact.string("2")} </div>
  </div>;
};