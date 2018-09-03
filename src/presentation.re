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
          <p> {s("Meet our first friend, Java")} </p>
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
        <Heading size=1> {s("Unboxed vs. Boxed")} </Heading>
        <Notes>
          <p>
            {s("Ok, so let's learn about some features of this type system.")}
          </p>
          <p>
            {
              s(
                "Out of the box, Java has got 2 classes of types: unboxed and boxed.",
              )
            }
          </p>
        </Notes>
      </Slide>
      <Slide>
        <Text> {s("Unboxed types (primitves) are pure values.")} </Text>
        <CodePane
          textSize={24 |> string_of_int}
          lang="java"
          source=Examples.javaUnboxedToString
        />
        <Text>
          {s("They behave like like values when it comes to equality.")}
        </Text>
        <CodePane
          textSize={24 |> string_of_int}
          lang="java"
          source=Examples.javaUnboxedValueEquality
        />
        <Notes>
          <p> {s("Unboxed types (primitves) are pure values.")} </p>
          <p> {s("They've got no methods.")} </p>
          <p> {s("and they follow structural equality.")} </p>
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
                "Boxed types is something that you're going to be familar with, if you're coming from JavaScript background where everything is an object.",
              )
            }
          </p>
          <p> {s("You can call methods on it.")} </p>
          <p>
            {
              s(
                "They also mostly behave like objects (or reference types) when it comes to equality.",
              )
            }
          </p>
          <p>
            {
              s(
                "I'm saying mostly, because JVM optimises certain common cases into singletons (e.g. numbers below 128), which is similar to yet another language (Python), but that's a topic for another talk.",
              )
            }
          </p>
        </Notes>
      </Slide>
      <Slide>
        <Heading size=1> {s("null")} </Heading>
        <BlockQuote>
          <Quote textColor="white">
            {s("I call it my billion-dollar mistake")}
          </Quote>
          <Cite> {s("Tony Hoare, inventor of NULL reference")} </Cite>
        </BlockQuote>
        <Notes>
          <p>
            {
              s(
                "Where those two differ the most is in representing the concept of no value.",
              )
            }
          </p>
          <p>
            {
              s(
                "This BTW is the quote by Tony Hoare, inventor of ALGOL and null reference itself.",
              )
            }
          </p>
        </Notes>
      </Slide>
      <Slide>
        <Text> {s("You can assign null to a boxed type")} </Text>
        <CodePane
          textSize={24 |> string_of_int}
          lang="java"
          source=Examples.javaBoxedNull
        />
        <Text> {s("But you cannot do the same to unboxed type")} </Text>
        <CodePane
          textSize={24 |> string_of_int}
          lang="java"
          source=Examples.javaUnboxedNull
        />
        <Text> {s("This can result in null pointer exceptions.")} </Text>
        <CodePane
          textSize={24 |> string_of_int}
          lang="java"
          source=Examples.javaNullPointer
        />
        <Notes>
          <p> {s("This can result in null pointer exceptions.")} </p>
          <p>
            {
              s(
                "The most important takeway here is that null doesn't have a type, meaning it is assignable to any boxed type.",
              )
            }
          </p>
          <p>
            {
              s(
                "Compiler doesn't try to do anything about this, so the only way you're gonna know about it is runtime.",
              )
            }
          </p>
        </Notes>
      </Slide>
      <Slide>
        <Heading> {s("Type erasure")} </Heading>
        <Notes>
          <p> {s("Type erasure.")} </p>
          <p>
            {
              s(
                "Java needs type information at runtime, otherwise it's unable to choose e.g. the correct overloads.",
              )
            }
          </p>
          <p>
            {
              s(
                "At the same time it's got type erasure, meaning that all generic types are treated as the same type at runtime.",
              )
            }
          </p>
        </Notes>
      </Slide>
      <Slide>
        <CodePane
          textSize={24 |> string_of_int}
          lang="java"
          source=Examples.javaErasure
        />
        <Notes>
          <p>
            {
              s(
                "Consider this simple printList example. List is a parameterised type and Java is unable to tell which one of the methods will be called at runtime, because both Integer and Long are considered the same type.",
              )
            }
          </p>
        </Notes>
      </Slide>
      <Slide>
        <Heading size=1> {s("Local type inference")} </Heading>
        <Notes>
          <p>
            {
              s(
                "In Java 10 the story of local type inference has improved dramatically.",
              )
            }
          </p>
          <p>
            {s("and this is because they've introduced the var keyword")}
          </p>
          <p>
            {
              s(
                "it allows the type of the local variables to be inferred automatically.",
              )
            }
          </p>
        </Notes>
      </Slide>
      <Slide>
        <Text> {s("`var` keyword")} </Text>
        <CodePane
          textSize={24 |> string_of_int}
          lang="java"
          source=Examples.javaVarString
        />
        <Text> {s("it doesn't work for all cases")} </Text>
        <CodePane
          textSize={24 |> string_of_int}
          lang="java"
          source=Examples.javaVarLambda
        />
        <Notes>
          <p>
            {
              s(
                "one of the examples where it doesn't work is lambdas. and sticking to the theme of this compiler which doesn't make bold claims about its capabilities, it will simply tell you that it can't do it.",
              )
            }
          </p>
          <p> {s("I quite like this honesty.")} </p>
        </Notes>
      </Slide>
      <Slide>
        <Text>
          {
            s(
              "Java very likeable. Not the sharpest, but very self-aware and honest about it.",
            )
          }
        </Text>
        <Notes>
          <p>
            {
              s(
                "Java very likeable. Not the sharpest, but very self-aware and honest about it.",
              )
            }
          </p>
        </Notes>
      </Slide>
      <Slide>
        <Heading size=1> {s("Let's catch up with TypeScript")} </Heading>
        <Notes>
          <p> {s("Let's catch up with TypeScript...")} </p>
          <p>
            {s("... which immediately strikes you as much more refined.")}
          </p>
        </Notes>
      </Slide>
      <Slide>
        <Heading> {s("--strictNullChecks")} </Heading>
        <Notes>
          <p>
            {s("The features TypeScript promises are much more advanced.")}
          </p>
          <p> {s("One of those things is null safety.")} </p>
        </Notes>
      </Slide>
      <Slide>
        <CodePane
          textSize={24 |> string_of_int}
          lang="typescript"
          source=Examples.tsNullSafety
        />
      </Slide>
      <Slide>
        <CodePane
          textSize={24 |> string_of_int}
          lang="typescript"
          source=Examples.tsNotWorkingNullSafety
        />
      </Slide>
      <Slide>
        <CodePane
          textSize={24 |> string_of_int}
          lang="typescript"
          source=Examples.tsUnions
        />
      </Slide>
      <Slide>
        <CodePane
          textSize={24 |> string_of_int}
          lang="typescript"
          source=Examples.tsPatternMatching
        />
      </Slide>
      <Slide>
        <CodePane
          textSize={24 |> string_of_int}
          lang="typescript"
          source=Examples.tsBrokenPatternMatching
        />
      </Slide>
      <Slide>
        <Heading size=1> {s("Chatting to the outside world")} </Heading>
        <Notes>
          <p>
            {
              s(
                "One of the things we do quite often is talking to the server.",
              )
            }
          </p>
          <p>
            {
              s(
                "We are dealing with data sent to us by a 3rd party, so the safety at this boundary is paramount.",
              )
            }
          </p>
          <p>
            {
              s(
                "To parse server responses you could use vanilla JSON.parse, which in TypeScript allows you to simply claim the response is of a certain type, without checking.",
              )
            }
          </p>
          <p> {s("This can lead to interesting scenarios.")} </p>
        </Notes>
      </Slide>
      <Slide>
        <CodePane
          textSize={24 |> string_of_int}
          lang="typescript"
          source=Examples.tsJsonParse
        />
      </Slide>
    </Deck>,
};