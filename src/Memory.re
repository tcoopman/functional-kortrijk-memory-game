[@react.component]
let make = () => {
  let cards =
    Belt.Array.range(0, 15)->Belt.Array.map(_ => <div className="card" />);
  <div className="app"> <div className="board"> {cards |> ReasonReact.array} </div> </div>;
};