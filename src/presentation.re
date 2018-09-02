open BsSpectacle;

let s = ReasonReact.string;

let component = ReasonReact.statelessComponent("Presentation");

let make = _children => {
  ...component,
  render: _self =>
    <Deck transition=[|Zoom, Slide, Fade|]>
      <Slide transition=[|Zoom|]>
        <Heading size=1> {s("Compiler is your friend")} </Heading>
        <Heading size=6>
          {s("...but would you go to a pub with each one of them?")}
        </Heading>
        <Notes>
          <p>
            {
              s(
                "I want to talk to you about various type systems today. Specifically about how, 3 widly different languages, Java, TypeScript and OCaml approach type safety.",
              )
            }
          </p>
        </Notes>
      </Slide>
      <Slide transition=[|Slide|]>
        <Heading size=1> {s("Jakub Korzeniowski")} </Heading>
        <List>
          <ListItem>
            {s("Vortexa, Intelligent Energy Markets: ")}
            <Link href="https://www.vortexa.com" target="_blank">
              {s("https://www.vortexa.com")}
            </Link>
          </ListItem>
          <ListItem>
            {s("Twitter: ")}
            <Link href="https://twitter.com/carkujon" target="_blank">
              {s("@carkujon")}
            </Link>
          </ListItem>
          <ListItem>
            {s("Github: ")}
            <Link href="https://github.com/kujon" target="_blank">
              {s("@kujon")}
            </Link>
          </ListItem>
        </List>
        <Notes>
          <p> {s("My name is Jakub Korzeniowski and I work for Vortexa")} </p>
          <p>
            {
              s(
                "We use machine learning to provide traders with a global, real-time view of the supply in the energy markets",
              )
            }
          </p>
          <p>
            {
              s(
                "You can find me on the Interwebs using the handles displayed on the screen.",
              )
            }
          </p>
          <p> {s("without further ado, let's get into it:")} </p>
        </Notes>
      </Slide>
      <Slide transition=[|Fade|]>
        <Heading size=1> {s("Meet Java (10)")} </Heading>
        <Notes>
          <p>
            {
              s(
                "I'm going to be specifically talking about Java 10, since it's a really big improvement to the type system.",
              )
            }
          </p>
        </Notes>
      </Slide>
      <Slide>
        <Cite>
          {
            s(
              "You acknowledge  that Licensed  Software is not designed or
            intended for use in the design, construction, operation or maintenance
            of any nuclear facility.",
            )
          }
        </Cite>
        <Notes>
          <p> {s("This is a quote from a Java licence.")} </p>
          <p>
            {
              s(
                "It could be there in author's opposition to nuclear power, or because the theme of this compiler is to not make bold claims about safety.",
              )
            }
          </p>
        </Notes>
      </Slide>
      <Slide>
        <Heading size=1> {s("Boxed vs. Unboxed")} </Heading>
        <Notes>
          <p>
            {s("Ok, so let's learn about some features of this type system.")}
          </p>
          <p> {s("Out of the box, Java has got 2 classes of types")} </p>
        </Notes>
      </Slide>
      <Slide>
        <Text> {s("Boxed types have got methods.")} </Text>
        <CodePane
          textSize={24 |> string_of_int}
          lang="java"
          source=Examples.javaBoxedMethodCall
        />
        <Text>
          {s("They mostly behave like objects when it comes to equality.*")}
        </Text>
        <CodePane
          textSize={24 |> string_of_int}
          lang="java"
          source=Examples.javaBoxedReferenceEquality
        />
        <Notes>
          <p>
            {
              s(
                "The first class is something that you're going to be familar with, if you're coming from JavaScript background where everything is an object. They're called boxed types.",
              )
            }
          </p>
          <p> {s("You can call methods on it.")} </p>
        </Notes>
      </Slide>
    </Deck>,
};