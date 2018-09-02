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