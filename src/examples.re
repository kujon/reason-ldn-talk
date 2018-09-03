let javaUnboxedToString = "int a = 42;

System.out.println(Integer.toString(a)); // > \"42\"
";

let javaUnboxedValueEquality = "long a = 1234567L;
long b = 1234567L;

System.out.println(a == b); // > true
";

let javaBoxedMethodCall = "Integer a = 42;

System.out.println(a.toString()); // > \"42\"
";

let javaBoxedReferenceEquality = "Long a = 1234567L;
Long b = 1234567L;

System.out.println(a == b); // > false
";

let javaBoxedNull = "Long foo = null; // > :)";

let javaUnboxedNull = "long bar = null; // > java: incompatible types: <nulltype> cannot be converted to long";

let javaNullPointer = "Long foo = null;
long bar = foo; // > NullPointerException

System.out.println(foo.toString()); // > NullPointerException
";

let javaErasure = "class ListStuff {
    // java: name clash: printList(java.util.List<java.lang.Long>) and printList(java.util.List<java.lang.Integer>) have the same erasure
    public void printList(List<Integer> ls) {

    }

    public void printList(List<Long> ls) {

    }
  }
  ";

let javaVarString = "var foo = \"forty two\";
// Infers to: String foo = \"forty two\";
";

let javaVarLambda = "// java: cannot infer type for local variable bar
// (lambda expression needs an explicit target-type)
var bar = () -> \"bar\";
";

let tsNullSafety = "type A = { id: string | null; type: 'bar' };
type B = { id: string | null; type: 'foo'; };

type C = A | B;

function unsafeSometimesIdToString(value: C): string {
    // Type 'string | null' is not assignable to type 'string'.
    return value.type == 'foo' ?
        value.id :
        '';
}

function safeSometimesIdToString(value: C): string {
    return value.type == 'foo' && value.id !== null ?
        value.id :
        '';
}
";

let tsNotWorkingNullSafety = "function superSafeSometimesIdToString(value: C): string {
    // Type 'string | null' is not assignable to type 'string'.
    return value.id !== null && value.type == 'foo' ?
        value.id :
        '';
}
";

let tsUnions = "type myUnion = 'foo' | 'bar';

// Function lacks ending return statement and
// return type does not include 'undefined'.
function brokenHelloUnion(value: myUnion): string {
    switch (value) {
        case 'foo':
            return 'Hello Foo!';
    }
}

function workingHelloUnion(value: myUnion): string {
    switch (value) {
        case 'foo':
            return 'Hello Foo!';
        case 'bar':
            return 'Hello Bar!';
    }
}
";

let tsPatternMatching = "function patternMatching(value: number): string {
    switch (true) {
        case value >= 0 && value < 0.1:
            return 'Tiny';
        case value < 0:
            return 'Negative';
        default:
            return 'Large';
    }
}
";

let tsBrokenPatternMatching = "// Function lacks ending return statement and
// return type does not include 'undefined'.
function unionPatternMatching(value: myUnion): string {
    switch (true) {
        case value === 'foo':
            return 'Hello Foo!';
        case value === 'bar':
            return 'Hello Bar!';
    }
}
";

let tsJsonParse = "type Doctor = {
    name: string;
    shift: string;
};

const renderDoctor = (doc: Doctor) =>
    `Dr. ${doc.name} works during those hours: ${doc.shift}`;

const doctor: Doctor = JSON.parse('[{ \"name\": \"Who\", \"shift\": \"24/7\" }]');

renderDoctor(doctor);
// Dr. undefined works during those hours: function shift() { [native code] }

";