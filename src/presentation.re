open BsSpectacle;

let component = ReasonReact.statelessComponent("Presentation");

let make = _children => {
  ...component,
  render: _self =>
    <Deck transition=[|Zoom, Slide|]>
      <Slide transition=[|Zoom|]>
        <Heading size=1>
          {ReasonReact.string("Compiler is your friend")}
        </Heading>
        <Heading size=6>
          {
            ReasonReact.string(
              "...but would you go to a pub with each one of them?",
            )
          }
        </Heading>
      </Slide>
      <Slide transition=[|Slide|]>
        <Heading size=1> {ReasonReact.string("Jakub Korzeniowski")} </Heading>
        <List>
          <ListItem>
            {ReasonReact.string("Vortexa, Intelligent Energy Markets: ")}
            <Link href="https://www.vortexa.com" target="_blank">
              {ReasonReact.string("https://www.vortexa.com")}
            </Link>
          </ListItem>
          <ListItem>
            {ReasonReact.string("Twitter: ")}
            <Link href="https://twitter.com/carkujon" target="_blank">
              {ReasonReact.string("@carkujon")}
            </Link>
          </ListItem>
          <ListItem>
            {ReasonReact.string("Github: ")}
            <Link href="https://github.com/kujon" target="_blank">
              {ReasonReact.string("@kujon")}
            </Link>
          </ListItem>
        </List>
      </Slide>
    </Deck>,
};