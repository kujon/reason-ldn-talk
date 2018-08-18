open BsSpectacle;

let component = ReasonReact.statelessComponent("Presentation");

let make = _children => {
  ...component,
  render: _self =>
    <Deck transition=[|Zoom, Slide|]>
      <Slide transition=[|Zoom|]>
        <Heading> {ReasonReact.string("Compiler is your friend")} </Heading>
      </Slide>
      <Slide transition=[|Slide|]>
        <Heading> {ReasonReact.string("Jakub Korzeniowski")} </Heading>
        <List>
          <ListItem>
            {ReasonReact.string("Twitter: ")}
            <Link href="https://twitter.com/carkujon">
              {ReasonReact.string("@carkujon")}
            </Link>
          </ListItem>
          <ListItem>
            {ReasonReact.string("Github: ")}
            <Link href="https://github.com/kujon">
              {ReasonReact.string("@kujon")}
            </Link>
          </ListItem>
          <ListItem>
            {ReasonReact.string("Work: ")}
            <Link href="https://www.vortexa.com" target="_blank">
              {ReasonReact.string("https://www.vortexa.com")}
            </Link>
          </ListItem>
        </List>
      </Slide>
    </Deck>,
};