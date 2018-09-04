open BsSpectacle;

let s = ReasonReact.string;

let component = ReasonReact.statelessComponent("Presentation");

let make = _children => {
  ...component,
  render: _self =>
    <Deck transition=[|Zoom, Slide, Fade|]>
      <Slide transition=[|Zoom|]>
        <Heading size=1> {s("Compiler is your friend")} </Heading>
      </Slide>
      <Slide transition=[|Slide|]>
        <Heading size=1> {s("Jakub Korzeniowski")} </Heading>
        <List>
          <ListItem textSize="32">
            {s("Vortexa, Intelligent Energy Markets: ")}
            <Link href="https://www.vortexa.com" target="_blank">
              {s("https://www.vortexa.com")}
            </Link>
          </ListItem>
          <ListItem textSize="32">
            {s("Twitter: ")}
            <Link href="https://twitter.com/carkujon" target="_blank">
              {s("@carkujon")}
            </Link>
          </ListItem>
          <ListItem textSize="32">
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
          <p>
            {
              s(
                "I want to talk to you about various type systems today. Specifically about how, 3 widly different languages, Java, TypeScript and OCaml approach type safety.",
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
        <Cite textSize="40">
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
                "We can speculate whether it's there because of the opposition to nuclear power.",
              )
            }
          </p>
          <p>
            {
              s(
                "But I'd suggest it's because it would be really dangerous to control a nuclear facility with Java.",
              )
            }
          </p>
          <p> {s("And that's the theme of this compiler: honesty.")} </p>
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
          textSize={20 |> string_of_int}
          lang="java"
          source=Examples.javaUnboxedToString
        />
        <Text>
          {s("They behave like like values when it comes to equality.")}
        </Text>
        <CodePane
          textSize={20 |> string_of_int}
          lang="java"
          source=Examples.javaUnboxedValueEquality
        />
        <Notes>
          <p>
            {
              s(
                "Unboxed types (primitves) are pure values, not backed by Java classes.",
              )
            }
          </p>
          <p> {s("They've got no methods.")} </p>
          <p> {s("and they follow structural equality.")} </p>
        </Notes>
      </Slide>
      <Slide>
        <Text> {s("Boxed types have got methods.")} </Text>
        <CodePane
          textSize={20 |> string_of_int}
          lang="java"
          source=Examples.javaBoxedMethodCall
        />
        <Text>
          {s("They mostly behave like objects when it comes to equality.*")}
        </Text>
        <CodePane
          textSize={20 |> string_of_int}
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
          textSize={20 |> string_of_int}
          lang="java"
          source=Examples.javaBoxedNull
        />
        <Text> {s("But you cannot do the same to unboxed type")} </Text>
        <CodePane
          textSize={20 |> string_of_int}
          lang="java"
          source=Examples.javaUnboxedNull
        />
        <Text> {s("This can result in null pointer exceptions.")} </Text>
        <CodePane
          textSize={20 |> string_of_int}
          lang="java"
          source=Examples.javaNullPointer
        />
        <Notes>
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
                "Compiler cannot to do anything about this, so the only way you're gonna know about it is runtime.",
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
                "At the same time it's got type erasure, meaning that all generic types become unknown at runtime.",
              )
            }
          </p>
        </Notes>
      </Slide>
      <Slide>
        <CodePane
          textSize={20 |> string_of_int}
          lang="java"
          source=Examples.javaErasure
        />
        <Notes>
          <p> {s("Consider this simple printList example.")} </p>
          <p>
            {
              s(
                "List is a parameterised type and Java is unable to tell which one of the methods will be called at runtime, because both Integer and Long are gone at runtime.",
              )
            }
          </p>
          <p>
            {
              s(
                "The nice thing is that it notifies you about the difficulties it's having.",
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
          textSize={20 |> string_of_int}
          lang="java"
          source=Examples.javaVarString
        />
        <Text> {s("it doesn't work for all cases")} </Text>
        <CodePane
          textSize={20 |> string_of_int}
          lang="java"
          source=Examples.javaVarLambda
        />
        <Notes>
          <p>
            {
              s(
                "So if you assign a string to a variable, it will know it's a string.",
              )
            }
          </p>
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
          <p>
            {
              s(
                "and it's even more remarkable, because it's trying to type JavaScript which is the wildest west possible.",
              )
            }
          </p>
        </Notes>
      </Slide>
      <Slide>
        <Heading> {s("--strictNullChecks")} </Heading>
        <Notes>
          <p>
            {s("One of the more advanced features is strict null checks.")}
          </p>
        </Notes>
      </Slide>
      <Slide>
        <Text> {s("null safety")} </Text>
        <CodePane
          textSize={20 |> string_of_int}
          lang="typescript"
          source=Examples.tsNullSafety
        />
        <Notes>
          <p>
            {
              s(
                "Here's a quick example of how TypeScript will prevent you from doing something silly.",
              )
            }
          </p>
          <p>
            {
              s(
                "In the first example, we forgot to guard against null and the compiler didn't grant us permission to move forward.",
              )
            }
          </p>
          <p>
            {
              s(
                "Big improvement over Java, and given than this feature is so awesome, you end up relying on it.",
              )
            }
          </p>
        </Notes>
      </Slide>
      <Slide>
        <Text> {s("null safety?")} </Text>
        <CodePane
          textSize={20 |> string_of_int}
          lang="typescript"
          source=Examples.tsNotWorkingNullSafety
        />
        <Notes>
          <p> {s("That is until it doesn't work.")} </p>
          <p>
            {
              s(
                "The only difference in this example is the order of checks and TS gets confused. And so do you.",
              )
            }
          </p>
          <p>
            {
              s(
                "It's a common occurrence. There are tons of powerful features that make you trust your new friend, and then they become quite unreliable.",
              )
            }
          </p>
        </Notes>
      </Slide>
      <Slide>
        <Heading size=4 textColor="white">
          {s("Unions and \"Pattern matching\"")}
        </Heading>
        <Notes>
          <p>
            {
              s(
                "Another super cool feature are unions, which allow you to represent a concept of a type or another type.",
              )
            }
          </p>
        </Notes>
      </Slide>
      <Slide>
        <Text> {s("Exhaustiveness")} </Text>
        <CodePane
          textSize={20 |> string_of_int}
          lang="typescript"
          source=Examples.tsUnions
        />
        <Notes>
          <p>
            {
              s(
                "TypeScript, similarly to OCaml enforces exhaustiveness of your checks for you.",
              )
            }
          </p>
          <p>
            {
              s(
                "So if you forget to guard against the case like in the first example, you'll get an error.",
              )
            }
          </p>
        </Notes>
      </Slide>
      <Slide>
        <Text> {s("\"Pattern matchin\"")} </Text>
        <CodePane
          textSize={20 |> string_of_int}
          lang="typescript"
          source=Examples.tsPatternMatching
        />
        <Notes>
          <p>
            {
              s(
                "We really quite like this feature, so we decided to flip it on its head by doing the switch (true) construct.",
              )
            }
          </p>
          <p>
            {
              s(
                "This allowed us to do more advanced checks akin to pattern matching.",
              )
            }
          </p>
        </Notes>
      </Slide>
      <Slide>
        <Text> {s("Not exhaustive")} </Text>
        <CodePane
          textSize={20 |> string_of_int}
          lang="typescript"
          source=Examples.tsBrokenPatternMatching
        />
        <Notes>
          <p>
            {
              s(
                "However, when you apply this to our original union example, the compiler gets confused.",
              )
            }
          </p>
          <p>
            {
              s(
                "and forces you to add a default case, which turns of exhaustiveness checks.",
              )
            }
          </p>
        </Notes>
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
        <Text>
          {
            s(
              "Dr. undefined works during those hours: function shift() { [native code] }",
            )
          }
        </Text>
        <CodePane
          textSize={20 |> string_of_int}
          lang="typescript"
          source=Examples.tsJsonParse
        />
        <Notes>
          <p>
            {
              s(
                "Simply getting an array instead of an object from the server can lead to scenarios like this.",
              )
            }
          </p>
        </Notes>
      </Slide>
      <Slide>
        <Text>
          {
            s(
              "TypeScript is very capable and confident, but struggles when pressed.",
            )
          }
        </Text>
        <Notes>
          <p>
            {
              s(
                "Which leads me to the conclusion that TypeScript is incredible capable and confident, but struggles when pressed.",
              )
            }
          </p>
        </Notes>
      </Slide>
      <Slide>
        <Heading> {s("Hello OCaml")} </Heading>
        <Notes> <p> {s("Let's move to the last one, OCaml.")} </p> </Notes>
      </Slide>
      <Slide>
        <Heading> {s("All-encompasing type inference")} </Heading>
        <Notes>
          <p>
            {
              s(
                "You could theoretically write your program without any type annotations and get full type coverage.",
              )
            }
          </p>
          <p>
            {
              s(
                "Whereas in Java or TypeScript your operations can be unchecked, OCaml won't compile unless it knows the type of each expression.",
              )
            }
          </p>
        </Notes>
      </Slide>
      <Slide>
        <Text> {s("Inferring everything from usage")} </Text>
        <CodePane
          textSize={20 |> string_of_int}
          lang="reason"
          source=Examples.reasonInference
        />
        <Notes>
          <p>
            {
              s(
                "For example, this reasonably complex function doesn't need a single annotation.",
              )
            }
          </p>
          <p> {s("Everything is inferrered from the usage.")} </p>
        </Notes>
      </Slide>
      <Slide>
        <Heading> {s("Less is more - Variants")} </Heading>
        <Notes>
          <p> {s("Variants are similar to typescripts unions")} </p>
        </Notes>
      </Slide>
      <Slide>
        <Text> {s("Exhaustiveness checks")} </Text>
        <CodePane
          textSize={20 |> string_of_int}
          lang="reason"
          source=Examples.reasonVariantWarning
        />
        <Notes>
          <p>
            {
              s(
                "Very similarly to typescript, OCaml will give you warnings about non exhaustive matches.",
              )
            }
          </p>
        </Notes>
      </Slide>
      <Slide>
        <Text> {s("which you address by checking for all the cases")} </Text>
        <CodePane
          textSize={20 |> string_of_int}
          lang="reason"
          source=Examples.reasonWorkingVariant
        />
        <Notes>
          <p>
            {s("Which you address by checking for all possible cases.")}
          </p>
          <p>
            {
              s(
                "One of the differences is that there's no concept of type narrowing.",
              )
            }
          </p>
          <p>
            {
              s(
                "Type constructor of a variant cannot live in isolation, e.g. you couldn't have a function taking just foo",
              )
            }
          </p>
          <p> {s("Side-note: polymorphic variants are quite different.")} </p>
        </Notes>
      </Slide>
      <Slide>
        <Text> {s("Getting the value out")} </Text>
        <CodePane
          textSize={20 |> string_of_int}
          lang="reason"
          source=Examples.reasonRemoveOptionals
        />
        <Notes>
          <p>
            {
              s(
                "Therefore your only option to get the value out is to pattern match.",
              )
            }
          </p>
          <p>
            {
              s(
                "I quite like the fact that OCaml humbly provides you only one reliable option to do that.",
              )
            }
          </p>
        </Notes>
      </Slide>
      <Slide>
        <Heading> {s("Mutable vs. Immutable")} </Heading>
        <Notes>
          <p>
            {s("Another thing is that, everything is immutable by default.")}
          </p>
          <p>
            {
              s(
                "Mutability can be a useful tool though, and the compiler allows it.",
              )
            }
          </p>
          <p>
            {
              s(
                "However, mutable and immutable types are not compatible with each other, so you will never accidentally end up converting one to the other",
              )
            }
          </p>
        </Notes>
      </Slide>
      <Slide>
        <Text> {s("Different syntax")} </Text>
        <CodePane
          textSize={20 |> string_of_int}
          lang="reason"
          source=Examples.reasonMutability
        />
        <Notes>
          <p>
            {
              s(
                "You can achieve mutability by either using the mutable keyword...",
              )
            }
          </p>
          <p> {s("...or the reference type.")} </p>
          <p>
            {
              s(
                "As you can see, the reference type is not only incompatible with its immutable equivalent, but it's even got a different assignment syntax.",
              )
            }
          </p>
          <p> {s("hard to cheat in such environment.")} </p>
        </Notes>
      </Slide>
      <Slide>
        <Heading> {s("PPX")} </Heading>
        <Notes>
          <p> {s("PPX is the coolest of the features IMHO.")} </p>
          <p> {s("It allows for syntactic extensions of the language.")} </p>
          <p> {s("e.g. JSX could be implemented using it.")} </p>
          <p>
            {
              s(
                "One of the coolest uses of it is dropping in the type system into strings which represent e.g. a different language.",
              )
            }
          </p>
        </Notes>
      </Slide>
      <Slide>
        <Text> {s("GraphQL PPX")} </Text>
        <Image src="graphql.gif" />
        <Notes>
          <p> {s("This is an example of a GraphQL PPX in action.")} </p>
          <p>
            {
              s(
                "All of this is really a string, but due to the PPX you get autocompletion and OCaml type checking inside of it, as it it was proper language.",
              )
            }
          </p>
          <p>
            {
              s(
                "And all of this type checking happens against the schema of your own server.",
              )
            }
          </p>
        </Notes>
      </Slide>
      <Slide>
        <Text> {s("ppx_bs_css")} </Text>
        <Image src="ppx_bs_css.png" />
        <Notes>
          <p> {s("Another really good example is CSS PPX")} </p>
          <p>
            {
              s(
                "It let's you drop in a string with CSS in it and have it type check as if it was OCaml code.",
              )
            }
          </p>
        </Notes>
      </Slide>
      <Slide>
        <Text> {s("OCaml is simply a reliable and humble friend.")} </Text>
        <Notes> <p> {s("And this is what I think of OCaml")} </p> </Notes>
      </Slide>
      <Slide> <Text> {s("Thank you!")} </Text> </Slide>
    </Deck>,
};