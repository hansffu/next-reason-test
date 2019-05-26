/*
    ## Global Count
    This captures the count globally so that it will be persisted across
    the `Index` and `About` pages.  This replicates the functionality
    of the shared-modules example.
 */
type t = ref(int);

type action =
  | Increment
  | Decrement;

let current = ref(0);

let increment = () => {
  current := current^ + 1;
  current;
};

let decrement = () => {
  current := current^ - 1;
  current;
};

let reducer = (_state, action) => {
  switch (action) {
  | Increment =>
    let updated = increment();
    updated^;
  | Decrement =>
    let updated = decrement();
    updated^;
  };
};

let useGlobalCount = () => React.useReducer(reducer, current^);