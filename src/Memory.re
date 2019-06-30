type state = {
    grid: array((int, Card.state))
};
type action = Turn(int);

let reducer = (state, action) => {
    switch (action) {
        | Turn(i) => 
        let newGrid = state.grid->Belt.Array.map(((index, cardState)) => {
            if (index == i) {
                (index, Card.Visible)
            } else {
                (index, cardState)
            }
        });
        {...state, grid: newGrid}
    };
};

let initialState = () => {
    let grid = Belt.Array.range(0, 15) -> Belt.Array.map(i => (i, Card.Hidden));
    {grid: grid}
};

[@react.component]
let make = () => {
    let (state, dispatch) = React.useReducer(reducer, initialState());
  let cards =
    state.grid
    ->Belt.Array.map(((i, cardState)) =>
        <Card
          state=cardState
          handleClick={() => dispatch(Turn(i))}
          value={ReasonReact.string(string_of_int(i))}
        />
      );
  <div className="app">
    <div className="header">
      <h1> {ReasonReact.string("Functional Kortrijk Memory")} </h1>
    </div>
    <div className="board"> {cards |> ReasonReact.array} </div>
  </div>;
};