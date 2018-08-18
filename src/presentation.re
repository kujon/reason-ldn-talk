open BsSpectacle;

let component = ReasonReact.statelessComponent("Presentation");

let make = _children => {
  ...component,
  render: _self =>
    <Deck transition=[|Zoom, Slide, Fade|]>
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
        <Notes>
          <p>
            {
              ReasonReact.string(
                "I want to talk to you about various type systems today. Specifically about how, 3 widly different languages, Java, TypeScript and OCaml approach type safety.",
              )
            }
          </p>
        </Notes>
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
        <Notes>
          <p>
            {
              ReasonReact.string(
                "My name is Jakub Korzeniowski and I work for Vortexa",
              )
            }
          </p>
          <p>
            {
              ReasonReact.string(
                "We use machine learning to provide traders with a global, real-time view of the supply in the energy markets",
              )
            }
          </p>
          <p>
            {
              ReasonReact.string(
                "You can find me on the Interwebs using the handles displayed on the screen.",
              )
            }
          </p>
          <p>
            {ReasonReact.string("without further ado, let's get into it:")}
          </p>
        </Notes>
      </Slide>
      <Slide transition=[|Fade|]>
        <Heading size=1> {ReasonReact.string("Meet Java (10)")} </Heading>
        <Notes>
          <p>
            {
              ReasonReact.string(
                "I'm going to be specifically talking about Java 10, since it's a really big improvement to the type system.",
              )
            }
          </p>
        </Notes>
      </Slide>
      <Slide>
        <Heading> {ReasonReact.string("Boxed vs. Unboxed")} </Heading>
        <Notes>
          <p>
            {
              ReasonReact.string(
                "Out of the box, Java has got 2 classes of types",
              )
            }
          </p>
          <p>
            {
              ReasonReact.string(
                "The first class is something that you're going to be familar with, if you're coming from JavaScript background where everything is an object. They're called boxed types.",
              )
            }
          </p>
        </Notes>
      </Slide>
    </Deck>,
};