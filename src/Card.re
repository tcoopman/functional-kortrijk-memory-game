type state =
  | Hidden
  | Visible;

[@react.component]
let make = (~state, ~value, ~handleClick) => {
  switch (state) {
  | Hidden => <div className="card card-hidden" onClick={_ => handleClick()} />
  | Visible => <div className="card card-visible sprite sprite-5-5" onClick={_ => handleClick()} />
  };
};