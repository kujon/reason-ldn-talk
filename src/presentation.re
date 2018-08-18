open BsSpectacle;

let component = ReasonReact.statelessComponent("Presentation");

let make = _children => {
  ...component,
  render: _self =>
    <Deck>
      <Slide> <Text> {ReasonReact.string("Hello")} </Text> </Slide>
    </Deck>,
};