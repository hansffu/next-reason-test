/*
    This is the set of action messages which are produced by this component.
    * Add updates the components internal state.
 */
type action =
  | Add;

/*
   This is the components internal state representation. This state object
   is unique to each instance of the component.
 */
type state = {count: int};

let counterReducer = (state, action) =>
  switch (action) {
  | Add => {count: state.count + 1}
  };

let renderOption = opt =>
  (
    switch (opt) {
    | Some(component) => [|component|]
    | None => [||]
    }
  )
  |> ReasonReact.array;

[@react.component]
let make = () => {
  let (state, dispatch) = React.useReducer(counterReducer, {count: 0});
  let (globalState, globalDispatch) = GlobalCount.useGlobalCount();

  let countMsg = "Count: " ++ string_of_int(state.count);
  let persistentCountMsg = "Persistent Count " ++ string_of_int(globalState);

  let globalButton = action => {
    let label =
      switch (action) {
      | GlobalCount.Increment => "Add"
      | GlobalCount.Decrement => "Sub"
      };
    <button onClick={_ => globalDispatch(action)}>
      {React.string(label)}
    </button>;
  };

  let decrementButton =
    switch (globalState) {
    | 0 => None
    | _ => Some(globalButton(GlobalCount.Decrement))
    };

  <div>
    <p> {ReasonReact.string(countMsg)} </p>
    <button onClick={_ => dispatch(Add)}> {React.string("Add")} </button>
    <p> {ReasonReact.string(persistentCountMsg)} </p>
    {globalButton(GlobalCount.Increment)}
    {decrementButton |> renderOption}
  </div>;
};

let default = make;