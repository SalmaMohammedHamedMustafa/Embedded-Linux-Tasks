# Introduction
## C++ 
- is an extension of the C programming language
- Object-Oriented language
- statically-typed language
- we will work with C++14 and C++17 in this course 
- c++ is the same as c in basic data types 

## C basic data types 
- integer: signed/unsigned & int/short int/long int
- floating point: float/double/long double
- character: char/signed char/unsigned char
- the size of any data type is directly dependent on the compiler along with the target processor


```c
unsigned char x = -1;
printf("%d",x);
```
- this outputs 255 as -1 is full ones and in unsigned char that represents 255


```c
char x = 255;
printf("%d",x);
```
- this outputs -1 as char is signed by defualt so 255 "ful ones" represents -1

```c
char x = 128;
printf("%d",x);
```
- this outputs -128 as char is signed by defualt and 128 represents -128

```c
char x = 258;
printf("%d",x);
```
- this outputs -2 as char is stored in one byte and 258 binary representation is 100000010 so the MSB is ignored and 00000010 is left which is 2


## c++ input & output

```cpp
#include <iostream>
int main()
{
    int x;
    std::cin>>x;
    std::cout<<x<<"\n";
    return 0;
}
```

## c++ manipulators 
- check cpprefrence.com::input/output manipulators 
- focus on the manipulators of diffrent number bases
- rembeber to reset the manipulator as you finish using it
- example on manipulators:
```cpp
#include <iostream>
#include <iomanip>

int main() {
    int num = 255;
    std::cout << std::hex << num << std::endl; // Outputs in hexadecimal
    std::cout << std::dec << num << std::endl; // Outputs in decimal
    return 0;
}
```


## C++ memory sections same as C

## C++ operators same as C

## C++ conditional statements same as C

## C++ loops same as C except ranged based loop
```cpp
#include <iostream>
#include <vector>
int main()
{
    std::vector<int> numbers = {1, 2, 3, 4, 535};
    for (int num : numbers) 
    {
        std::cout<<num<<"\n";
    }
    return 0;
}
```



# Derived
# Functions
## basic function
- basic functions as same as C
- Except that we can add defualt parameters
```cpp
#include <iostream>
void printMessage(std::string message = "Hello, World!") {
std::cout << message << std::endl;
}

int main() {
printMessage(); // Prints default message
printMessage("Hi there!"); // Prints custom message
return 0;
}

``` 
- tricky:
```cpp
#include <iostream>
void fun(int x = 2, int y);
void fun(int x, int y) {
    std::cout << x << " " << y << std::endl;
}

int main() {
    fun(2);
    return 0;
}
```
- this code results an error as when you add default paramter the following parameters must have default values also
- correct code 

```cpp
#include <iostream>
void fun(int y, int x=2);
void fun(int y, int x) {
    std::cout << x << " " << y << std::endl;
}

int main() {
    fun(3);
    return 0;
}
```
- output: 2 3

## Function overloading 
- Function overloading allows multiple functions to have the same name with different parameters. The correct function to be called is determined by the arguments provided.
```cpp
#include <iostream>

void print(int i) {
    std::cout << "Integer: " << i << std::endl;
}

void print(double f) {
    std::cout << "Double: " << f << std::endl;
}

void print(const std::string &s) {
    std::cout << "String: " << s << std::endl;
}

int main() {
    print(10);
    print(3.14);
    print("Hello, World!");
    return 0;
}
```
## Ambiguous function call
```cpp
void fun(int x, int y = 3){
std::cout << x <<" " << y << std::endl;
}
void fun(int x, float y = 3){
std::cout << x <<" " << y << std::endl;
}
int main()
{
    fun(2);
    return 0;
}
```
- the function call is ambiguous


## Mangling 
- Name mangling is the process where the compiler generates unique names for each function based on their parameters. This allows function overloading to work. Mangled names are often compiler-specific.
##Demangling
- to see how your functions are mangled 
- seeing mangling: grep on your function name in the objdump file 
```
objdump -t --demangle | grep fun_name
```
-demangling: using c++filt tool
```
c++filt mangled_name_of_function
```

#Arrays
## Declaration
To declare an array, specify the type of elements and the number of elements in brackets.

```cpp
int numbers[6]; // Declare an integer array with 6 elements
```
## Initialization
- Arrays can be initialized when declared.
```cpp
int numbers[6] = {2, 4, 8, 12, 16, 18}; // Initialize array elements
```
- or 
```cpp
int numbers[] = {2, 4, 8, 12, 16, 18}; // Compiler determines the size
```
## Accessing Elements
```cpp
for (int i = 0; i < 6; ++i) {
    cout << numbers[i] << " ";
}
```
- or use ranged loop
```cpp
int numbers[] = {0, 1, 2, 3, 4, 5};
for (int value : numbers) {
    std::cout << value << " ";
}
```
## Memory Layout
- Memory layout of arrays in C++ involves contiguous memory allocation for array elements.

# Pointers
- it have tha same rules as c pointers
## pointer to function syntax
```cpp
#include <iostream>
void greet() {
    std::cout << "Hello, World!" << std::endl;
}
int main() {
    void (*funcPtr)() = greet;
    funcPtr();
    return 0;
}
```
## Arrays and Pointers

- Arrays are closely related to pointers:

```cpp
int arr[5] = {1, 2, 3, 4, 5};
int *ptr = arr; // Pointer points to the first element of the array

## Pointer Arithmetic
```cpp
int *nextPtr = ptr + 1; // Points to the next element in the array
```

# References
- References are aliases(another names) for other variables.
```cpp
#include <iostream>
int main() {
    int a = 10;
    int &b =a;
    b=8;
    std::cout << a << " ";
    std::cout << b << "\n";
    return 0;
}
```
- output: 8 8

## Calling By References
```cpp
#include <iostream>

void byValue(int x) {
    x = 100;
}

void byPointer(int *x) {
    *x = 100;
}

void byReference(int &x) {
    x = 100;
}

int main() {
    int a = 10;
    byValue(a);
    std::cout << "By value: " << a << std::endl;

    byPointer(&a);
    std::cout << "By pointer: " << a << std::endl;

    byReference(a);
    std::cout << "By reference: " << a << std::endl;

    return 0;
}
```
- output: By value: 10
- By pointer: 100
- By reference: 100

## Null Pointer
- The diffrence between nullptr and NULL
- using NULL
```cpp
#include <iostream>

void foo(int) {
    std::cout << "Called foo(int)" << std::endl;
}

void foo(char*) {
    std::cout << "Called foo(char*)" << std::endl;
}

int main() {
    foo(NULL); // Ambiguous: could call either foo(int) or foo(char*)
    return 0;
}
```
- using nullptr
```cpp
#include <iostream>

void foo(int) {
    std::cout << "Called foo(int)" << std::endl;
}

void foo(char*) {
    std::cout << "Called foo(char*)" << std::endl;
}

int main() {
    foo(nullptr); // Unambiguous: calls foo(char*)
    return 0;
}
```
## Dynamic Memory Allocation
- Allocation:
```cpp
int *ptr = new int;
*ptr = 43;
```
- Deallocation
```cpp
delete ptr;
ptr = nullptr;
```

## auto keyword
```cpp
auto var = 10;
auto var2 = 10.5;

auto var3 = 'a';
auto var4 = const char*;
auto var5 = std::string("hello String ");

// with const
const int x = 10;
auto var6 = x; // var is int
//** to make it const
const auto var7 = x;
// with referance const works as expectd 
auto &var8 = x;
// with pointer const works as expectd  
auto ptr = &;

// std::initliaizer_list
auto Ist = {1, 2, 3, 4, 5};
// error
// auto lst{l, 2, 3, 4};
return 0;
```

# Casting in C++
## C style Cast
- c style cast can cause many problems as it allows casting between any type of pointers without compiler checking 
```cpp
char c = 'a';
int * ptr = (int*)&c;
```
- In c style cast this will not cause error, and it can cause many problems as the pointer ptr is accessing more 3 pytes after the char c and it can be an important part of memory

## static_cast
- whenever you need to use c style cast use static cast instead 
```cpp
char c = 'a';
int * ptr = (int*)&c;  //no error
int* ptr2 = static_cast<int*>(&c);   //error
```

## const_cast
- const_cast is used to cast away the constness of variables
- Rule 5-2-5 (Required) A cast shall not remove any const or volatile qualification from the type of a pointer or reference.
- So, it is a bad practice 
```cpp
#include <iostream>
int main() {
    const int val = 10;
    const int* ptr = &val;
    //int *ptr2 = ptr;   //error
    int* ptr2 = const_cast<int*>(ptr);
    *ptr2=100;
    std::cout<<*ptr2<<" ";
    std::cout<<*ptr<<" ";
    std::cout<<val<<"\n";
 
    return 0;
}
```
- output: 100 100 10

## reinterpret_cast
- reinterpret_cast should be used with extreme caution. It allows casting between any types of pointers, but it
does not check the compatibility of the types, leading to potential errors and undeﬁned behavior. Always
ensure that the types are compatible and the casting is safe when using reinterpret_cast.
- it is like c style cast
- example:
```cpp
#include <iostream>
struct data {
int x = 10;
int y = 100;
char c =0;
bool b = false;
};

int main() {
data d;
// int *p = static_cast<int *>(&d);  #ERROR
int *p = reinterpret_cast<int *>(&d);
std::cout << *p++ << " ";
std::cout << *p++ << " ";
std::cout << *p << "\n";
return 0;
}
```
- output: 10 100 0

## dynamic_cast
- postponed

# Lambda Expressions
## Syntax
- Lambda expressions provide a concise way to create anonymous function objects. The basic syntax is:

```cpp
auto func = []() {
    // function body
};
```
- You can also capture variables, pass parameters, and specify the return type:

```cpp
auto func = [captured_variables](parameters) -> return_type {
    // function body
};
```
## Capture List
- [captured_variables]: This is the capture list, which allows the lambda to access variables from its enclosing scope.

- [&] captures all variables by reference.
- [=] captures all variables by value.
- Specific variables can be captured by listing them, like [x, &y].
## Mutable Variables
- The mutable keyword allows modifying captured variables within the lambda
```cpp
[temp] mutable {
    return x + y;
};
```

## Return Type
- -> return_type: This specifies the return type of the lambda function. If omitted, the return type is deduced automatically.
## Implementation 

```cpp
// Lambda expression
auto lambda = [](int a, int b) -> int {
    return a + b;
};
```
## Auto type detection 
- Auto type detection in c++ is available in c++14 and above
## When we use it ?
- passing function as argument
```cpp
    auto sort_with_lambda = [](int input_arr[], int output_arr[], int order, size_t size) {
        std::copy(input_arr, input_arr + size, output_arr);}
```
- traceability
- return function


# Const vs Constexpr
## const
The const keyword is used to declare variables whose value cannot be changed after initialization. It can be used with variables, pointers, and member functions:

```cpp
const int x = 10;          // constant variable
const int* ptr = &x;       // pointer to a constant integer
int* const ptr2 = &x;      // constant pointer to an integer
```
## constexpr
The constexpr keyword is used to declare variables, functions, and objects that can be evaluated at compile time. This allows for optimizations and ensures that the value is constant:

```cpp
constexpr int y = 20;      // constant expression

constexpr int add(int a, int b) {
    return a + b;
}

constexpr int result = add(3, 4); // evaluated at compile time
```

### Differences
- const ensures that the value cannot be changed, but the value might be determined at runtime.
- constexpr ensures that the value is constant and can be evaluated at compile time.
```cpp
const int a = 5;
constexpr int b = 10;

int array1[a];           // This may not compile, depending on the compiler
int array2[b];           // This will always compile

constexpr int add(int x, int y) {
    return x + y;
}

int result = add(a, b);  // This will be evaluated at compile time
```

# OOP
## Initialization Types in C++

### Value Initialization:

- Initializes a variable to a known value.
- Example: int x{}; (x is initialized to 0).

### Direct Initialization:

- Calls the constructor directly.
- Example: int x(5); (x is initialized to 5).

### Copy Initialization:

- Initializes a variable using the value of another variable.
- Example: int x = 5; (x is initialized to 5).

### Uniform Initialization (C++11 and later):

- Uses curly braces {} for initializing variables.
- Prevents narrowing conversions.
- Example: int x{5}; (x is initialized to 5).

### the diffrence between them 
- in trivial datatypes {int,float,char,double,bool,struct variables}
- the diffrence will be in the folowing case:
```cpp
int main() {
int value1;//garbage
int value2{};//zero 
//another way for value initialization
int value3 = int{};
std::cout << value1<< " ";
std::cout << value3<< " ";
std::cout << value2 << "\n";
return 0;
}
```
- output: garbage value  0 0
- the same behavior will be will struct variables

- In vectors:
```cpp
 #include <iostream>
#include <iterator>
#include <vector>

/*ignore the detailes of this function for now */
template <typename T> void print(T data) {

std::copy(std::begin(data), std::end(data),std::ostream_iterator<int>(std::cout," "));
std::cout << std::endl;

}

int main() {
std::vector<int>v(12,3); //copy intializatin
std::vector<int>v2{12,3}; //value initialization
print(v);
print(v2);
return 0;
}
```
- output: 3 3 3 3 3 3 3 3 3 3 3 3 
12 3 

- you cannot use direct initailization ike that 
```cpp
int value(); //vexing parse
```
- it works like a function decleration 
### the best of them?
- in trivial data types the best is uniform initialization (value)
### narrow conversion 
```cpp
float decimal = 4.5;
int number = decimal; //no error (implicit casting)
int number2{decimal}; //error as the unifoem initialization cannot do implicit casting
```

## Enum
### C-Style Enum
- In C, enums are a way to assign names to integral constants, which makes the code more readable. However, they are not type-safe and can lead to naming conflicts.

```cpp
enum Color { RED, GREEN, BLUE };
Color color = RED;
```
### C++-Style Enum (enum class)
- C++ introduces enum class, which provides type safety and prevents naming conflicts. enum class members must be accessed using the scope resolution operator.

```cpp
enum class Color { RED, GREEN, BLUE };
Color color = Color::RED;
```
### C enum rules
```cpp
#include <iostream>
enum Traffic
{
    RED,
    YELLOW, // 1 i
    GREEN
};
int main() {
Traffic obj{};
std::cout << obj << " "; //can be printer like any integer
std::cout << Traffic::YELLOW << " ";
int number = RED; // convert from data type to another date type
// Traffic obj2 = 2; ERROR 
std::cout << sizeof(obj) <<"\n"; //4 and we didn't need all 4 bytes
}
```
- output: 0 1 4

### enum class rules 

```cpp
#include <iostream>
enum class Traffic : unsigned char          // 1 - specify size optional
{
    RED,
    YELLOW,
    GREEN
};

int main()
{
    Traffic obj;

    // std::cout << obj << std::endl;        // 2 - cannot print obj till operator overloading exist
    std::cout << (int)obj << " ";     // 3 - to print use casting *** till we exploit static_cast<int>(obj)

    //std::cout << RED << std::endl;          // 4 - ERROR you cannot access literals without class name
    std::cout << (int) Traffic::RED <<" "; // 5 - access enum class

    // int x = Traffic::RED;                 // 6 - cannot convert from enum to int
    // Traffic obj2 = 1;                     // 7 - ERROR cannot convert int to classic enum

    int y= static_cast<int>(Traffic::RED);
    Traffic obj2 = static_cast<Traffic>(1);
    std::cout << (int)obj2<<" "<<y<<"\n";

    // auto complet
    return 0;
}
```
- output: garbage 0 1 0

## Class and Struct
- they are the same only for now

### Encapsulation
- Encapsulation is the bundling of data and methods that operate on that data within a single unit or class, and restricting access to some of the object's components.
### class
- can contain functions and variabes 
- in memory members will be created acoording to the scope of the object as the normal variables 
- Stack Segment: Local variables, including object instances, are stored here.
- Heap Segment: Dynamically allocated memory (using new and delete).
- Text Segment: Stores compiled code (the program's executable instructions).
- BSS Segment: Uninitialized global and static variables.
- functions will be in .txt section
- only one function for the whole class
- when you create an object the constructor is called and stack frame is created
- stack frame contains the variables
- when the object scope is over the desctrutor is called
### Access Modifiers
- Public: Members are accessible from outside the class.
- Private: Members are only accessible from within the class itself.
- Protected: Members are accessible within the class and by derived class instances.

### the only diffrence between class and struct
- struct members are public bt default
- class members are private by defualt

### Functions
- when functions are defined inside the class definition it does not exist in the .txt except when you create an object of the class and use the function  
- when it's defined outside it exists
- it's better for the debugging proccess to write function definitions outsode the class definition 

### Constructors
#### Default Constructor: A constructor that takes no arguments.
- if no constructor is created by yu the compiler will creat a defualt one
 ```cpp
class MyClass {
public:
    MyClass() {}  // Default constructor
};
```
#### vexing parse
-  if you call the defualt constructor like this it is vexing parse
```cpp
MyClass obj();
```
#### How to call the  Default constructor
```cpp
MyClass obj1; //copy
MyClass obj2{}; //value
MyClass obj3 = MyClass(); //Direct
```

#### Parameterized Constructor: A constructor that takes one or more arguments.
- as you've defined a Parameterized Constructor the compiler will not generate default one
- in this case if you want to create en instance of your class with out parameters you need to define a defualt constructor your self
```cpp
class MyClass {
public:
    MyClass(int value) {}  // Parameterized constructor
};
```
#### This Pointer
this is an implicit pointer in C++ that points to the object for which a member function is called. It is used within a class's member functions to refer to the invoking object.

```cpp
class MyClass {
    int value;
public:
    void setValue(int value) {
        this->value = value;
    }
};
```
#### Important example on Parameterized Constructor
```cpp
class myData {
    public:
    // Default constructor
    myData() {
        std::cout << "default constructor" << std::endl;
    }

    // Parameterized constructor 1
    myData(int a) {
        std::cout << "parameterized constructor 1" << std::endl;
        this->a = a;
    }

    // Parameterized constructor 2
    myData(int a, int b) : myData(a) {
        std::cout << "parameterized constructor 2" << std::endl;
        this->b = b;
    }

    int a;
    int b;
};

int main() {
    // Example usage
    myData my2( 2,  3);
    std::cout << my2.a << " " << my2.b << std::endl;

    return 0;
}
```
- output: 
parameterized constructor 1
parameterized constructor 2
2 3

#### aggregate initialization 
- if yu do not have Parameterized Constructor you still can give the Default Constructor parameters and the compiler may be smart enough to understand
- It is a bad practise 
- example:
```cpp
class myData {
    // Default constructor
    myData() {
        std::cout << "default constructor" << std::endl;
    }


    int a;
    int b;
};

int main() {
    // Example usage
    myData my(a: 2, b: 3);
    std::cout << my2.a << " " << my2.b << std::endl;

    return 0;
}
```

#### Initializer List
- example:
```cpp
#include <iostream>

class myData {
    public:
    // Parameterized constructor 
    myData(int a,int b) 
    :a(a),b(b)
    {
        std::cout << "parameterized constructor 1" << std::endl;
    }

    int a;
    int b;
};

int main() {
    // Example usage
    myData my2( 2,  3);
    std::cout << my2.a << " " << my2.b << std::endl;

    return 0;
}
```
- output: 
parameterized constructor 1
2 3

- Put yur class vaiables in the initializer list in order
##### Cases where you need to use initializer list
```cpp
#include <iostream>

class myData {
public:
    // Parameterized constructor
    myData(int a, int b, int c, int d) 
    : a(a), b(b), internalC(c), c(internalC), d(d)
    {
        std::cout << "parameterized constructor" << std::endl;
    }

    int a;
    int b;
    int internalC;  // Internal storage for reference member
    int &c;         // Reference to internalC
    const int d;    // Constant member 
    const int e = 0; //or just initialize constant variables

};

int main() {
    // Example usage
    myData my2(2, 3, 4, 5);
    std::cout << my2.a << " " << my2.b << " " << my2.c << " " << my2.d << std::endl;

    return 0;
}
```

### const method
- 1- you cannot modify any variable(members)
- 2- you can create local variables and change them
- 3- you can modify the parameter value as well
- 4- you can modify static member (for future)
    4.1- you can modify reference member (for future)
    4.2- this doesn't match with the pointers
- 5- you can use mutable if you would like to modify the variable
- 6- const instance can only call const member functions
- 7- non-const instance can call both const and non-const member functions
- 8- non-const instance will call non-const methods even if there is const one
- const member functions shall not return non-cost reference or pointer to the class members

```cpp
#include <iostream>

class myData {
public:
    myData(int a, int b) : a(a), b(b), ptr(&this->a), number(this->b) {
        std::cout << "Parameterized constructor called." << std::endl;
    }

    int getter(int temp) const {
        std::cout << "Const getter called with temp = " << temp << std::endl;
        // a = 10; 1- you cannot modify any variable(members)
        // std::cout << "Trying to modify a non-mutable member: a = 10;" << std::endl;

        // 2- you can create local variables and change them
        int myvalue = 10;
        myvalue++;
        std::cout << "Local variable myvalue incremented: " << myvalue << std::endl;

        // 3- you can modify the parameter value as well
        temp++;
        std::cout << "Parameter temp incremented: " << temp << std::endl;

        // 4- you can modify static member (for future)
        classmember++;
        std::cout << "Static member classmember incremented: " << classmember << std::endl;

        // 4.1- you can modify reference member (for future)
        number = 100;
        std::cout << "Reference member number modified: " << number << std::endl;

        // 4.2- this doesn't match with the pointers
        // ptr = &a; 
        // std::cout << "Trying to modify pointer to member: ptr = &a;" << std::endl;

        return a;
    }

    void fun() const {
        std::cout << "Const fun called." << std::endl;
    }

    void test() {
        std::cout << "Non-const test called." << std::endl;
    }

    int getter(int temp) {
        std::cout << "Non-const getter called with temp = " << temp << std::endl;
        return a;
    }

private:
    int a; // 5- you can use mutable if you would like to modify the variable #bad practice
    int b;
    int* ptr;
    int& number;
    static int classmember;
};

int myData::classmember = 0;

int main() {
    // 6- const instance can only call const member functions
    const myData data(1, 2);
    std::cout << "Const instance data created." << std::endl;
    // data.test(); // error
    data.getter(5); // Calls const getter

    // 7- non-const instance can call both const and non-const member functions
    myData data2(2, 2);
    std::cout << "Non-const instance data2 created." << std::endl;
    data2.getter(5); // Calls non-const getter
    data2.fun(); // Calls const fun
    data2.test(); // Calls non-const test

    // 8- non-const instance will call non-const methods even if there is a const one
    std::cout << "Non-const getter result: " << data2.getter(5) << std::endl;

    return 0;
}
```
- output: Parameterized constructor called.
Const instance data created.
Const getter called with temp = 5
Local variable myvalue incremented: 11
Parameter temp incremented: 6
Static member classmember incremented: 1
Reference member number modified: 100
Parameterized constructor called.
Non-const instance data2 created.
Non-const getter called with temp = 5
Const fun called.
Non-const test called.
Non-const getter result: Non-const getter called with temp = 5
2

### Delete
```cpp
#include <iostream>
class Data {
public:
    bool flag = 1;
    int value = 0;

    Data() = delete;
    Data(int flag);
    void PrintInt();
};

Data::Data() {
    std::cout << "Default" << std::endl;
}

Data::Data(int flag) {
    // Implementation of the constructor
}
int main() {
    Data d; // Error: Attempting to use the deleted default constructor
    return 0;
}
```
- Error: Attempting to use the deleted default constructor
### Friend class
- A class that can be Access the private members of another class
- the class firendship is not mutual 
```cpp
#include <iostream>

// Forward declaration of RectangleAreaCalculator
class RectangleAreaCalculator;

class Rectangle {
private:
    double length;
    double width;

public:
    // Constructor to initialize the rectangle
    Rectangle(double l, double w) : length(l), width(w) {}

    // Declare RectangleAreaCalculator as a friend class
    friend class RectangleAreaCalculator;
};

class RectangleAreaCalculator {
public:
    // Method to calculate the area of the rectangle
    double calculateArea(const Rectangle& rect) {
        return rect.length * rect.width;
    }
};

int main() {
    // Create a Rectangle object
    Rectangle myRectangle(5.0, 3.0);

    // Create a RectangleAreaCalculator object
    RectangleAreaCalculator calculator;

    // Calculate and display the area
    double area = calculator.calculateArea(myRectangle);
    std::cout << "Area of the rectangle: " << area << std::endl;

    return 0;
}
```

### Friend function 
- a function or operator overloading that can access the private members of a class
```cpp
#include <iostream>

class temp; // forward declaration
void fun(); // forward declaration

class myData {
public:
    myData(int a, int b) : a(a), b(b) {}

private:
    int a;
    int b;
    friend void fun(); // 2- friend function

    // friend operator overloading (for future)
    friend std::ostream& operator<<(std::ostream& os, const myData& data) {
        os << data.a << " " << data.b;
        return os;
    }
};

void fun() {
    myData data(1, 2);
    std::cout << data.a << std::endl;
    std::cout << data.b << std::endl;
}

int main() {
    // Using the friend function
    fun();
    // Using the friend operator overloading
    myData data(3, 4);
    std::cout << data << std::endl;

    return 0;
}
```
### Static class member
- Static member is not related to instance, it is related to the class itself
- If a static data member of integral or enumeration type is declared const (and not volatile ), it can be initialized with an initializer in which every expression is a constant expression, right inside the class definition
```cpp
#include <iostream>
class myData {
public:
    myData() { counter++; }

    static int counter;
    static const int MAX = 5; // 4- it is related to class and also it is constant //spectial initialization for static const int as it is not exist in .rodata and we cannot send refrence to it (it is just an alias)
    static const int MIN;
    static const float PI;
    // static const int temp; // 7- Error if you would like to define in constructor

private:
    // Static member is not related to instance, it is related to the class itself
    int n;
};

// 1- Definition should be outside the class
int myData::counter = 0;

// 6- It should be initialized outside the class
const int myData::MIN = 0;

// 6.1- It should be initialized outside the class & not integral data type
const float myData::PI = 3.14;

int main() {
    // Creating a vector of myData objects
    // std::vector<myData> v(5);

    myData d1;
    myData d2;
    myData d3;
    myData d4;
    myData d5;

    // Accessing and printing static members
    std::cout << myData::counter << std::endl; // 2- You can access the static member from the class name
    std::cout << d1.counter << std::endl;      // 3- You can access the static member object
    std::cout << myData::MAX << std::endl;
    std::cout << d1.MIN << std::endl;
    std::cout << myData::PI << std::endl;

    return 0;
}

```

### Memory Layout
![Alt text](classMemory.png)

### Static method
- 1- static function is not realted to instance it is realted to class
```cpp
#include <iostream>

class myData {
public:
    myData() {}

    static void myfun() { // 1- static function is not realted to instance it is realted to class

        std::cout << "Hello World" << std::endl;
        // temp = 10; // 2- Еггor cannot acces to (this)
        number = 20; // 3- OK

    }                  

    static void test();
    int temp;
    static int number;
};
int myData::number = 10;

void myData::test() {} // take care there is no static word outside the class
int main() {

    myData data;
    myData data2;
    myData::myfun(); // 4- calling from class name and from instance name
    data.myfun();
    return 0;

}
```
### Some new things in c++
```cpp
- 1
#include <iostream>
#include <regex>
#include <string>

int main() {
    std::string frame = "mynumber is 01112932885, myemail is eng.moatasem.9@gmail.com";
    std::regex pattern("([a-zA-Z0-9.%+-]+@[a-zA-Z0-9.-]+\\.[a-zA-Z]{2,6})");
    std::smatch match;
    std::regex_search(frame, match, pattern);
    std::cout << match.str() << std::endl;
    return 0;
}
```
- 2
```cpp
#include <iostream>
#include <sstream>
#include <string>

int main() {
    std::string name;
    int ID;
    float score;
    std::string frame = "Moatasem 1234 99.9";
    std::stringstream st(frame);
    st >> name >> ID >> score;
    std::cout << name << std::endl; // Moatasem
    std::cout << ID << std::endl;   // 1234
    std::cout << score << std::endl; // 99.9
    return 0;
}
``` 
- 3-  Indicates that the included header file cfile.h contains C code. SO the g++ doesnot mangle the functions in it.
```cpp
#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>

extern "C" {
    #include "cfile.h"
}

using namespace std;

void fun(int x) {
    std::cout << "hello world" << std::endl;
}

void fun(int x, int y) {
    std::cout << "hello world" << std::endl;
}

int main() {
    fun(2);
    fun(2, 3);
    display();

    return 0;
}
```

## Operator Overloading
- Operator overloading in C++ is a feature that allows developers to redefine the behavior of operators for user-defined types (such as classes and structs). This means that you can define how operators like +, -, *, ==, etc., work when applied to objects of your own classes.
- By overloading operators, you can make your custom types behave more like built-in types, which can make your code more intuitive and easier to read. For example, you might overload the + operator for a Complex class to add two complex numbers, or the << operator to output a class object to a stream.
- Detailed Example:
```cpp
#include <iostream>

class ImaginaryNumbers {
public:
    double real;
    double imaginary;

    // Default constructor
    ImaginaryNumbers() : real(0), imaginary(0) {
        std::cout << "constructor called\n";
    }

    // Parameterized constructor
    ImaginaryNumbers(double r, double i) : real(r), imaginary(i) {
        std::cout << "parameterized constructor called\n";
    }

    // Destructor
    ~ImaginaryNumbers() {
        std::cout << "Destructor called\n";
    }
    // Pre-increment operator overloading (++obj)
    ImaginaryNumbers& operator++();
    // Post-increment operator overloading (obj++)
    ImaginaryNumbers operator++(int);
    // Friend function to overload the + operator
    friend ImaginaryNumbers operator+(const ImaginaryNumbers& num1, const ImaginaryNumbers& num2);
    // Friend function to overload the - operator
    friend ImaginaryNumbers operator-(const ImaginaryNumbers& num1, const ImaginaryNumbers& num2);
    // Friend function to overload the << operator
    friend std::ostream& operator<<(std::ostream& os, const ImaginaryNumbers& num);
    // Friend function to overload the >> operator
    friend std::istream& operator>>(std::istream& is, const ImaginaryNumbers& num);
    };
//Operator overloading for ++obj
ImaginaryNumbers& ImaginaryNumbers::operator++() {
    ++real;
    ++imaginary;
    return *this; // Return the incremented object
}
// Post-increment operator overloading (obj++)
ImaginaryNumbers ImaginaryNumbers::operator++(int) {
    ImaginaryNumbers temp = *this; // Copy current state
    real++;
    imaginary++;
    return temp; // Return the old state
}
// Operator overloading for +
ImaginaryNumbers operator+(const ImaginaryNumbers& num1, const ImaginaryNumbers& num2) {
    return ImaginaryNumbers(num1.real + num2.real, num1.imaginary + num2.imaginary);
}
// Operator overloading for -
ImaginaryNumbers operator-(const ImaginaryNumbers& num1, const ImaginaryNumbers& num2) {
    return ImaginaryNumbers(num1.real - num2.real, num1.imaginary - num2.imaginary);
}
// Operator overloading for <<
std::ostream& operator<<(std::ostream& os, const ImaginaryNumbers& num) {
    os << num.real << " + " << num.imaginary << "i\n";
    return os;
}
// Operator overloading for >>
std::istream& operator>>(std::istream& is, ImaginaryNumbers& num) {
    std::cout << "Enter real part: ";
    is >> num.real;
    std::cout << "Enter imaginary part: ";
    is >> num.imaginary;
    return is;
}

int main() {
    ImaginaryNumbers number1;
    ImaginaryNumbers number2;
    ImaginaryNumbers summation;
    ImaginaryNumbers Diff;
    std::cin>>number1;
    std::cin>>number2;
    summation = number1 + number2;
    Diff = number1 - number2;
    std::cout << "Summation: " << summation << std::endl;
    std::cout << "diffrence: " << Diff << std::endl;
    ++summation;
    ImaginaryNumbers temp = summation++;
    std::cout<<summation;
    std::cout<<temp;
    return 0;
}
```
### explicit
- Rule 12-1-3
This rule states that all constructors that can be called with a single argument of a fundamental type (like int) should be declared explicit. This helps prevent unintended implicit conversions, making the code safer and more predictable. 
```cpp
class Complex {
private:
    int real;
    float img;
public:
    Complex() = default;
    explicit Complex(int real) : real(real), img(0) {}  // Explicit to prevent implicit conversions
    Complex(int real, float img) : real(real), img(img) {}

    void print() {
        std::cout << "Real is " << real << " Img is " << img << std::endl;
    }

    int operator+(int v) {
        return real + v;
    }

    friend int operator+(int value, Complex c);
};

int operator+(int value, Complex c) {
    return value + c.real;
}

int main() {
    Complex B(2, 2.5);
    Complex A = Complex(2);  // Works, explicit call
    Complex C = 2;  // Error, cannot implicitly convert int to Complex due to explicit constructor
}
```

### functor
### Conversion

## Copy Constructor 

```cpp
#include <iostream>
class String {
    char* str=nullptr;
    int size;

public:
    String(char *str) : str(str) {}

    /* 
    Implicit constructor is created
    // 1- Why the copy constructor is must to be reference?
    // 2- Why the copy constructor is must to be const?
    */
    void fun() { std::cout << str << std::endl; }
    void setchar(char value) { *str = value; }
};

int main() {
    char array[] = "hello";
    String t1(array);

    String t2(t1);
    t1.setchar('A');
    t2.fun();

    return 0;
}
```
- output: Aello
- in this case the compiler will create a copy constructor which will create a shallow copy from t1 in t2 
- the implementation of the copy constructor the compiler will generate is:
```cpp
String(const String &obj) {
    str = obj.str;
    size = obj.size;
    }
```
- t2.str wil be equal to t1.str so they both will point to the same memory address (shalow copy)
- this problrm will not happen with trivial data types (int, float, double, bool, (struct, class) without any constructors or functions )
#### why copy constructor must be by refrence?
- not using the refrence in copy constructor implementation will cause an error 
- String(String obj) means obj=t1 which calls the copy constructor 
- So, using the refrence wil avoid infinitly stucking the the copy constructor 
#### why copy constructor must be const?
```cpp 
#include <iostream>
#include <cstring>
class String {
    char* str=nullptr;
    int size;

public:
    String(char *str) : str(str) {}

    String(const String &obj) {
        size = obj.size;
        str = new char[size]; // allocating in heap section respected to the size
        strcpy(str, obj.str); // copy data from obj.str to this->str
        // memory leakage
        //ignore this issue for now
    }

    void fun() { std::cout << str << std::endl; }
    void setchar(char value) { *str = value; }
};
String  get_instance() {
    static char array[] = "hello";
    String t1(array); // instance
    return t1;
}

int main() {
    char array[] = "hello";
    String t1(array);

    // get_instance() will return a temporary object which means this one will be
    // RVALUE
    // const T&
    // T&&
    String t2(get_instance());
    t1.setchar('A');
    t1.fun();
    t2.fun();

    return 0;
}
```
- in this code we are passing a RVALUE to the copy constructor ( get_instance() will return a temporary object)
- the RVALUE needs to be called passed as const T&

### fixing memory leakage 
- to analyze memory run the command tldr valgring
- get the right command you will find memory leakage
- to fix this we need to delete the memory allocated in the heap in the destructor
```cpp
#include <iostream>
#include <cstring>
class String {
    char* str=nullptr;
    int size;

public:
    String(char *str) : str(str) {}

    String(const String &obj) {
        size = obj.size;
        str = new char[size]; // allocating in heap section respected to the size
        strcpy(str, obj.str); // copy data from obj.str to this->str
    }
    ~ String()
    {
        delete [] str;
        str =nullptr;
    }
    void fun() { std::cout << str << std::endl; }
    void setchar(char value) { *str = value; }
};
String  get_instance() {
    static char array[] = "hello";
    String t1(array); // instance
    return t1;
}

int main() {
    char array[] = "hello";
    String t1(array);

    // get_instance() will return a temporary object which means this one will be
    // RVALUE
    // const T&
    // T&&
    String t2(get_instance());
    t1.setchar('A');
    t1.fun();
    t2.fun();

    return 0;
}
```
- output: Aello
hello
free(): invalid size
Aborted (core dumped)
- when calling the destructor for the normal constructor the delete is trying to delete a pointer points to the stack 
- corrected version: 
```cpp
#include <iostream>
#include <cstring>
class String {
    char* str=nullptr;
    int size;

public:
        String(char *input_str) {
        size = std::strlen(input_str) + 1;  // get size including null terminator
        str = new char[size];               // allocate memory on heap
        std::strcpy(str, input_str);        // copy the input string
    }

    String(const String &obj) {
        size = obj.size;
        str = new char[size]; // allocating in heap section respected to the size
        strcpy(str, obj.str); // copy data from obj.str to this->str
    }
    ~ String()
    {
        delete [] str;
        str =nullptr;
    }
    void fun() { std::cout << str << std::endl; }
    void setchar(char value) { *str = value; }
};
String  get_instance() {
    static char array[] = "hello";
    String t1(array); // instance
    return t1;
}

int main() {
    char array[] = "hello";
    String t1(array);

    // get_instance() will return a temporary object which means this one will be
    // RVALUE
    // const T&
    // T&&
    String t2(get_instance());
    t1.setchar('A');
    t1.fun();
    t2.fun();

    return 0;
}
```


## Elide Constructor 
```cpp
#include <iostream>
// The <type_traits> header included in the original image is not used, so it is omitted here.

class String {
private:
public:
    String() { std::cout << "Default constructor" << std::endl; }
    ~String() { std::cout << "Destructor" << std::endl; }
    String(const String &obj) { std::cout << "Copy constructor" << std::endl; }
};

String get_instance() {
    String t1; // 1 Default constructor
    return t1; // 2 Copy constructor commented out, actually returns address of local object temp(t2)
    // Destructor -> (1)
}

int main() {
    String t2(get_instance()); // 3 t2(temp)
    return 0;
}
```
- command : g++ try.cpp && ./a.out  output: 
Default constructor
Destructor
- command: g++ -g  try.cpp -std=c++14 -fno-elide-constructors -O0 && ./a.out  output:
Default constructor
Copy constructor
Destructor
Copy constructor
Destructor
Destructor
- c++ compiler have the concespt of Elide Constructor which is an optimization technique used by compilers to eliminate the copying and moving of objects where possible, which can significantly improve performance by reducing unnecessary operations.

## overLoading assignment operator 
```cpp
     // Assignment Operator
    String& operator=(const String& obj) {

        // Self-assignment check
        if (this == &obj) {
            return *this;
        }
        // Clean before starting
        delete this->str;
        // Deep copy
        this->size = obj.size;
        this->str = new char[size];
        std::strcpy(this->str, obj.str);

        return *this;
        }
```
## Value Categories 
```cpp
#include <iostream>
#include <type_traits>
int& fun() {
    static int moatasem = 5;
    return moatasem;
}
//in Data segment 
// a = 5

int /*temp*/ fun2() {
    static int a = 5;
    return a;
}

int main() {
    fun() /*Lvalue*/ = 10 /*Rvalue*/;
    int x /*Lvalue*/ = fun() /*Rvalue*/;  // what is the fun return? Lvalue
    x = 100;
    std::cout << fun() << std::endl;
    // fun2() /*Rvalue*/ = 10;  ERROR
    int left = fun2();
    return 0;
}
```
```cpp
#include <iostream>
int main() {
    std::string name = "moatasem";  // name is an lvalue
    std::string name2 = std::move(name);  // name2 is now the owner of the string

    std::cout << name2 << std::endl;  // it works, prints "moatasem"
    std::cout << name << std::endl;   // it is empty, it is moved, so let's consider that name is now an xvalue

    // Example with move semantics:
    // T = A
    // B = move(A)
    // What is the value category of A and B?
    // B is an lvalue
    // A was lvalue then it is xvalue
    return 0;
}
```
#### Lvalue : it is one of the value category
- name + address
- example : name2
#### Rvalue: it is one of the value category
- temporary + no name
- example : 4 , 3.5, fun2()
#### Xvalue : it is one of the value category
- Identity + moved
<div style="display: flex;">
  <img src="vauluetable.png" alt="Image 1" style="width: 45%; margin-right: 10px;">
  <img src="values.png" alt="Image 2" style="width: 45%;">
</div>

#### More reading 
- [Value Categories](https://en.cppreference.com/w/cpp/language/value_category)

## Type Category

### Reference Types

- **Lvalue Reference**: Denoted by `&`, can bind to lvalues.
- **Rvalue Reference**: Denoted by `&&`, can bind to rvalues.

```cpp
int y = 10;
int &x = y; // x is an lvalue reference to y
int &&rvalueRef = 10; // rvalueRef is an rvalue reference to a temporary
printf("The address of rvalue ref is : %p\n", &rvalueRef);
```
- **`int &x = y;`**: `x` is an lvalue reference to `y`, meaning `x` can be used to modify `y`.
- **`int &&rvalueRef = 10;`**: `rvalueRef` is an rvalue reference initialized with a temporary value.

```cpp
void fun(int x) {}

int main() {
    int var = 10;
    int &ref = var; // ref is an lvalue reference to var

    fun(1); // 1 is an rvalue
    fun(var); // var is an lvalue
    fun(ref); // ref is an lvalue
}
```
- **`fun(1);`**: `1` is an rvalue.
- **`fun(var);`**: `var` is an lvalue.
- **`fun(ref);`**: `ref` is also an lvalue.
```cpp
// lvalue refrence
void fun(int &x) {}

int main() {
    int var = 10;
    int &ref = var; // ref is an lvalue reference to var

    //fun(1); // 1 is an rvalue //ERROR
    fun(var); // var is an lvalue
    fun(ref); // ref is an lvalue
}
```
```cpp
// Rvalue refrence can hold temporary also 
void fun(const int &x) {}

int main() {
    int var = 10;
    int &ref = var; // ref is an lvalue reference to var

    fun(1); // 1 is an rvalue 
    fun(var); // var is an lvalue
    fun(ref); // ref is an lvalue
}
```
- from the **`String`** class example
```cpp
int main() {
    /*
    the type Category is Rvalue refrence
    it just points to the temporary instance from the function 
    that results in a performance enhancement*/
    String &&t2(get_string());
return 0;
}
```
Sure! Here's a detailed explanation of the move constructor and move assignment operator implementations for your `String` class:

## Move Constructor

The move constructor is a special type of constructor used to transfer the resources of a temporary object (rvalue) to a new object. This avoids unnecessary copying, which can improve performance when dealing with resource-intensive objects. Here's a breakdown of your move constructor:

```cpp
String::String(String &&obj) {
    // for the new instance
    this->size = obj.size;
    this->str = obj.str;
    // for the old instance
    obj.size = 0;
    obj.str = nullptr;
}
```

#### Explanation:

- **Parameter**: `String &&obj` is an rvalue reference to the object that is being moved.
- **New Instance Setup**:
  - `this->size = obj.size;`: The size of the new instance is set to the size of the old instance. This transfers the size value from the old object to the new one.
  - `this->str = obj.str;`: The `str` pointer of the new instance is set to the `str` pointer of the old instance, transferring ownership of the memory.
- **Old Instance Cleanup**:
  - `obj.size = 0;`: The size of the old instance is set to 0, marking it as an empty or default state.
  - `obj.str = nullptr;`: The `str` pointer of the old instance is set to `nullptr`, ensuring the destructor of the old instance doesn't delete the memory that was just transferred.

### Move Assignment Operator

The move assignment operator is used to transfer resources from one object to another when both objects have already been constructed. This operator is similar to the move constructor but works with existing instances.

```cpp
String& String::operator=(String&& obj)
{
    if (*this == obj)
    {
        return *this;
    }
    // for the new instance
    this->size = obj.size;
    delete [] this->str;
    this->str = obj.str;
    // for the old instance
    obj.size = 0;
    obj.str = nullptr;
    return *this;
}
```

#### Explanation:

- **Self-Assignment Check**:
  - `if (*this == obj) { return *this; }`: Checks if the object being assigned to (`*this`) is the same as the object being moved from (`obj`). If so, it returns the current object to prevent unnecessary operations.
  
- **New Instance Setup**:
  - `this->size = obj.size;`: Assigns the size from the `obj` to the current instance.
  - `delete [] this->str;`: Frees the memory currently held by the `str` pointer in the current instance to prevent memory leaks.
  - `this->str = obj.str;`: Transfers the `str` pointer from `obj` to the current instance, giving ownership of the memory.

- **Old Instance Cleanup**:
  - `obj.size = 0;`: Resets the size of the old instance to zero, marking it as empty.
  - `obj.str = nullptr;`: Sets the `str` pointer of the old instance to `nullptr` to prevent the destructor from attempting to free the memory again.

- **Return**:
  - `return *this;`: Returns the current instance to allow for chained assignments.

Here's a markdown explanation for the concepts of the Rule of Five and Rule of Zero in C++ as outlined in the slides:

---

## The Rule of Five

The Rule of Five is an extension of the Rule of Three in C++. It dictates that if a class manages resources (such as dynamic memory, file handles, network connections, etc.), and it defines one of the following special member functions, it should define all five to ensure correct copy semantics and resource management:

- **Copy Constructor:** Creates a new object as a copy of an existing object. It must also copy the resources to ensure that each object manages a separate copy of the resource.

- **Copy Assignment Operator:** Assigns the contents of one object to another existing object. Similar to the copy constructor, it must handle the resources carefully to avoid resource leaks and ensure that each object maintains a separate copy.

- **Destructor:** Frees the resources owned by the object when it goes out of scope or is deleted. It is crucial for avoiding resource leaks.

- **Move Constructor:** Transfers the resources from a temporary object (rvalue) to a new object. This is more efficient than copying for temporary objects.

- **Move Assignment Operator:** Transfers resources from one object to another existing object, typically when dealing with temporary values. This should also clean up the resources of the assigned object before the transfer.

These five functions are essential for safe and efficient management of resources in user-defined types, ensuring deep copying and proper move semantics.

## Rule of Zero

The Rule of Zero complements the Rule of Five by promoting the use of system-defined versions of resource management functions. According to this rule, classes that do not manage any resources should not define custom destructors, copy/move constructors, or copy/move assignment operators. Instead, they should rely on the default versions provided by the compiler.

**Implications:**
- **Encourages Simplicity:** By relying on compiler-generated functions, code remains simple and less prone to errors associated with manual resource management.
- **Use of Smart Pointers:** This rule encourages the use of standard library types like `std::unique_ptr` or `std::shared_ptr` for resource management, which automatically handle resource allocation and deallocation.
- **Maintainability and Safety:** Reduces boilerplate code and makes the class naturally safe against memory leaks, dangling pointers, and other resource mismanagement issues.

**Example:**

```cpp
class RuleOfZeroExample {
public:
    std::string name;  // Uses default destructor, copy/move constructors, and copy/move assignment operators
};
```

When a class does not manage any resources directly (it contains objects such as `std::string` or smart pointers that manage resources themselves), it should not define any of the five special member functions, allowing the class to be simpler and safer.

The code snippets you've shown demonstrate two different approaches to managing class functions in C++. Let's break down each one:

### Base of Five Defaults

```cpp
class base_of_five_defaults
{
public:
    base_of_five_defaults(const base_of_five_defaults&) = default;
    base_of_five_defaults(base_of_five_defaults&&) = default;
    base_of_five_defaults& operator=(const base_of_five_defaults&) = default;
    base_of_five_defaults& operator=(base_of_five_defaults&&) = default;
    virtual ~base_of_five_defaults() = default;
};
```

#### Explanation:
- This class explicitly defaults all five of the special member functions (copy constructor, move constructor, copy assignment operator, move assignment operator, and destructor). 
- Marking these as `default` tells the compiler to generate the default implementations for these functions. This approach is used when the default behavior (shallow copying for constructors and assignment operators, doing nothing for the destructor) is suitable for the class.
- The destructor is declared as `virtual`, which is crucial for a class intended to be a base class. This ensures that the destructor of any derived class will be called, even when an object is deleted through a pointer of this base class type, enabling proper cleanup of derived class resources.

### MyBaseClass

```cpp
class MyBaseClass
{
public:
    virtual ~MyBaseClass() = default;
    MyBaseClass(MyBaseClass const &) = delete;
    MyBaseClass(MyBaseClass &&) = delete;
    MyBaseClass& operator=(MyBaseClass const &) = delete;
    MyBaseClass& operator=(MyBaseClass &&) = delete;
};
```

#### Explanation:
- This class takes a different approach by deleting the copy and move constructors, as well as the copy and move assignment operators. This means objects of this class cannot be copied or moved.
- Deleting these functions is useful when the class manages resources that should not be copied or moved automatically, or when the class should be unique and not shareable.
- The destructor is defaulted and virtual. Defaulting the destructor is sufficient for classes that do not need to perform any special cleanup upon object destruction, but making it virtual ensures that any subclass destructors are called appropriately.

#### Use Cases:
- **base_of_five_defaults** might be used when class instances need to be easily copied or moved, and the default behavior correctly handles all member data (like primitives, or simple aggregates of other classes that correctly handle their own copying and moving).
- **MyBaseClass** might be used in contexts where class instances manage unique resources that require careful control over how they are handled, such as file handles or network connections, or when the class is used as a base class for a hierarchy representing non-copyable and non-movable entities.

## C++ core guidlines
- Avoid non-const global variables
- Alternative: If you use global (more generally namespace scope) data to avoid copying, consider passing the data as an object by reference to const. Another solution is to define the data as the state of some object and the operations as member functions.

## Inheritance
- The idea of inheritance implements the is a relationship
### Single Inheritance
- Example
```cpp
#include <iostream>
// Base class
class Vehicle {
public:
std::string brand = "Ford";
Vehicle (){
    std::cout<<"Vehicle Constructor\n";
}
~ Vehicle (){
    std::cout<<"Vehicle Destructor\n";
}
void honk() {
std::cout << "Tuut, tuut! \n" ;}

};

// Derived class
class Car: public Vehicle {
public:
Car()
{
    std::cout<<"Car Constructor\n";
}
~Car()
{
    std::cout<<"Car Destructor\n";
}
std::string model = "Mustang";
};

int main() {
Car myCar;
myCar.honk() ;
std::cout << myCar.brand <<" \n";
return 0;
}
```
- output:
Vehicle Constructor
Car Constructor
Tuut, tuut! 
Ford 
Car Destructor
Vehicle Destructor

### Multilevel Inheritance
- Example
```cpp
#include <iostream>

class Base {
public:
    // Constructor
    Base() {
        std::cout << "Base Constructor" << std::endl;
    }
    
    // Destructor
    ~Base() {
        std::cout << "Base Destructor" << std::endl;
    }

    void fun() {
        std::cout << "Base fun" << std::endl;
    }
};

class child1 : public Base {
public:
    // Constructor
    child1() {
        std::cout << "child1 Constructor" << std::endl;
    }
    // Destructor
    ~child1() {
        std::cout << "child1 Destructor" << std::endl;
    }
    void fun() {
        std::cout << "child fun" << std::endl;
    }
};

class child2 : public child1 {
public:
    // Constructor
    child2() {
        std::cout << "child2 Constructor" << std::endl;
    }
    // Destructor
    ~child2() {
        std::cout << "child2 Destructor" << std::endl;
    }
};

int main() {
    child2 obj;   // Constructs child2, which constructs child1 and Base
    obj.fun();    // Calls child1's fun
    obj.Base::fun(); // Calls Base's fun
    return 0;
}
```
- output:
Base Constructor
child1 Constructor
child2 Constructor
child fun
Base fun
child2 Destructor
child1 Destructor
Base Destructor

### Multiple inheritance
```cpp
#include <iostream>

class Base {
public:
    // Constructor
    Base() {
        std::cout << "Base Constructor" << std::endl;
    }
    
    // Destructor
    ~Base() {
        std::cout << "Base Destructor" << std::endl;
    }
    
    void fun() {
        std::cout << "Base fun" << std::endl;
    }
};

class Base2 {
public:
    // Constructor
    Base2() {
        std::cout << "Base2 Constructor" << std::endl;
    }
    
    // Destructor
    ~Base2() {
        std::cout << "Base2 Destructor" << std::endl;
    }
    
    void fun() {
        std::cout << "Base2 fun" << std::endl;
    }
};

class child2 : public Base, public Base2 {
public:
    // Constructor
    child2() {
        std::cout << "child2 Constructor" << std::endl;
    }
    
    // Destructor
    ~child2() {
        std::cout << "child2 Destructor" << std::endl;
    }
};

int main() {
    child2 obj;          // Constructs child2, which constructs Base and Base2
    obj.Base::fun();    // Calls Base's fun
    obj.Base2::fun();   // Calls Base2's fun

    return 0;
}
```
- If you didn't tell wich fun to use that will result in an error (Ambiguous function call)
- output: 
Base Constructor
Base2 Constructor
child2 Constructor
Base fun
Base2 fun
child2 Destructor
Base2 Destructor
Base Destructor

### Hybrid Inheritance 

- Hybrid inheritance in C++ is a combination of more than one type of inheritance. The provided code snippets demonstrate hybrid inheritance with and without virtual inheritance, and the implications of each approach.

#### Without Virtual Inheritance

```cpp
class ClassA {
public:
    int a;
};

class ClassB : public ClassA {
public:
    int b;
};

class ClassC : public ClassA {
public:
    int c;
};

class ClassD : public ClassB, public ClassC {
public:
    int d;
};

int main() {
    ClassD obj;
    // obj.a = 10;  // Statement 1, Error
    // obj.a = 100; // Statement 2, Error

    obj.ClassB::a = 10; // Statement 3
    obj.ClassC::a = 100; // Statement 4
}
```

- **Explanation**:
  - `ClassD` inherits from both `ClassB` and `ClassC`.
  - Since `ClassB` and `ClassC` both inherit from `ClassA`, `ClassD` ends up with two copies of `ClassA` (one from each path).
  - This leads to ambiguity when accessing members of `ClassA` through `ClassD`.
  - For example, `obj.a = 10;` (Statement 1) results in a compilation error due to ambiguity.
  - To resolve this, the members of `ClassA` must be accessed explicitly through `ClassB` or `ClassC`, as shown in Statements 3 and 4.

#### With Virtual Inheritance

```cpp
class ClassA {
public:
    int a;
};

class ClassB : virtual public ClassA {
public:
    int b;
};

class ClassC : virtual public ClassA {
public:
    int c;
};

class ClassD : public ClassB, public ClassC {
public:
    int d;
};

int main() {
    ClassD obj;

    obj.a = 10;  // Statement 3
    obj.a = 100; // Statement 4
}
```

- **Explanation**:
  - Here, `ClassB` and `ClassC` inherit `ClassA` using virtual inheritance.
  - Virtual inheritance ensures that there is only one instance of `ClassA` in `ClassD`, eliminating ambiguity.
  - Statements 3 and 4 compile without error because `obj.a` refers to the single instance of `ClassA` that is shared between `ClassB` and `ClassC`.

### abstract class and interface class 
- you cannot creat instanse from the abtract or interface classes 
- abstract class example
```cpp
#include <iostream>
#include <fstream>
#include <stdexcept>
#include <string>

class Logger {
public:
    enum Level { Info, Warning, Error };
    static constexpr const char *PASSWORD = "Moatasem";

    virtual void log(Level level, const std::string &message) = 0;
    void help() { std::cout << "help" << std::endl; }
};

class FileSystem : public Logger {
public:
    FileSystem(std::string password) {
        if (password != Logger::PASSWORD) {
            throw std::runtime_error("Invalid password");
        }
    }

    void log(Level level, const std::string &message) override {
        std::fstream fs("log.txt", std::ios::app);
        fs << message << std::endl;
        fs.close();
    }
};

int main() {
    // Calling the base class constructor explicitly using 'using'
    FileSystem log_handler(Logger::PASSWORD);

    log_handler.log(Logger::Level::Info, "This is an info message");
    return 0;
}
```
- interface class example
```cpp
#include <iostream>

class Shape {
public:
    virtual void draw() = 0; // Pure virtual function, making Shape an abstract class
};

class Circle : public Shape {
public:
    void draw() override {
        std::cout << "Drawing a circle." << std::endl;
    }
};

class Square : public Shape {
public:
    void draw() override {
        std::cout << "Drawing a square." << std::endl;
    }
};

int main() {
    Circle circle;
    Square square;

    Shape* shapes[] = { &circle, &square };

    for (Shape* shape : shapes) {
        shape->draw(); // Using abstraction to draw different shapes
    }

    return 0;
}
```

# STL
## Containters
### Strings
#### Code
```cpp
#include <iostream>
#include <string>

void string_functions() {
    std::string s = "Hello, World!";

    // Print the size of the string
    std::cout << s.size() << std::endl;

    // Print the length of the string
    std::cout << s.length() << std::endl;

    // Print the capacity of the string
    std::cout << s.capacity() << std::endl; // Capacity is the internal storage allocated for the string

    // Print the maximum size the string can grow to
    std::cout << s.max_size() << std::endl;

    // Finding a substring
    auto it = s.find("World");
    if (it == std::string::npos) {
        std::cout << "not found" << std::endl;
    } else {
        std::cout << "found at " << it << std::endl;
    }

    // Extract a substring starting at position 7 with length 5
    std::cout << s.substr(7, 5) << std::endl;

    // Replace part of the string starting at position 7, removing 5 characters, and inserting "C++"
    s.replace(7, 5, "C++");
    std::cout<<s<<"\n";

    // Insert "World" at the end of the string
    s.insert(s.length(), "World");
    std::cout<<s<<"\n";

    // Erase 3 characters starting from position 7
    s.erase(7, 3);
    std::cout<<s<<"\n";

    // Append "!" to the string
    s.append("!");
    std::cout<<s<<"\n";

    // Attempt to resize the string to length 5 and fill with 'a'
    s.resize(5, 'a');
    

    // Print the final string
    std::cout << s << std::endl;
}

int main() {
    string_functions();
    return 0;
}
```

#### Explanation

- **`s.size()` and `s.length()`**: Both return the number of characters in the string.
- **`s.capacity()`**: Returns the size of the storage space currently allocated to the string, which may be equal or greater than the string size.
- **`s.max_size()`**: Returns the maximum possible number of characters that the string can hold.
- **`s.find("World")`**: Searches for the substring "World" in `s` and returns the position of the first character of the substring. If the substring is not found, it returns `std::string::npos`.
- **`s.substr(7, 5)`**: Extracts a substring from `s` starting at position 7 with a length of 5 characters.
- **`s.replace(7, 5, "C++")`**: Replaces 5 characters in `s` starting at position 7 with "C++".
- **`s.insert(s.length(), "World")`**: Inserts "World" at the end of the string.
- **`s.erase(7, 3)`**: Removes 3 characters from `s` starting at position 7.
- **`s.append("!")`**: Appends the character "!" to the end of the string.
- **`s.resize(5, 'a')`**: Resizes the string to a length of 5. If the current length is shorter, 'a' is used to fill the additional spaces.

Here's an explanation of the concepts shown in the image in Markdown format:

---

#### Joining String Literals

In C++, when string literals are only separated by whitespace, the compiler automatically joins them into a single string. This is a convenient feature for organizing long strings across multiple lines for readability. Here’s how it works:

#####Example

```cpp
std::string s = 
    "This is one literal "
    "split into several "
    "source code lines!";
```

The above code will result in `s` being `"This is one literal split into several source code lines!"`.

#### Raw String Literals

Raw string literals are a feature introduced in C++11 that allows you to include special characters in strings without needing to escape them. This is particularly useful for strings containing characters like backslashes or quotes, which typically require escaping.

##### Syntax

The syntax for a raw string literal is:

```
R"delimiter(characters...)delimiter"
```

Where `delimiter` is a sequence of 0 to 16 characters (excluding spaces, parentheses, and backslashes) that serves as a boundary between the raw string content and the rest of the code.

##### Example

```cpp
const char* path = R"(C:\users\joe)";
std::string raw_str = R"delim(raw "std"-string c:\users\moe)delim";
```
#### Update the string class
- we can add methods to the string class
##### Exmaple
```cpp
#include <iostream>
#include <algorithm>
#include <string>

class EnhancedString : public std::string {
public:
    // Inherit constructors from std::string
    using std::string::string;

    void reverse() { 
        std::reverse(this->begin(), this->end()); 
    }

    void toUpperCase() {
        std::transform(this->begin(), this->end(), this->begin(), ::toupper);
    }

    void toLowerCase() {
        std::transform(this->begin(), this->end(), this->begin(), ::tolower);
    }

    template <typename T> 
    T from() { 
        return T(); 
    }
};

template <> 
int EnhancedString::from<int>() { 
    return std::stoi(*this); 
}

template <> 
float EnhancedString::from<float>() { 
    return std::stof(*this); 
}

int main() {
    EnhancedString str("Hello World");
    str.toUpperCase(); // HELLO WORLD
    std::cout << str << std::endl;

    str.reverse(); // DLROW OLLEH
    std::cout << str << std::endl;

    str.toLowerCase(); // dlrow olleh
    std::cout << str << std::endl;

    EnhancedString str2("123");
    std::cout << str2.from<int>() << std::endl; // 123

    str2.assign("123.5");
    std::cout << str2.from<float>() << std::endl; // 123.5

    return 0;
}
```
#### geline()
- you can read strings using getline
```cpp
std::string s;
getline(std::cin, s); // read entire line
getline(std::cin, 5s, '\t'); // read until next tab
getline(std::cin, s, ‘a'); // read until next ‘a’
```
### C++ core guidelines
 
- SL.con.2: Prefer using STL vector by default unless you have a reason
to use a different container

- vector and array are the only standard containers that offer the following
advantages:
-  the fastest general-purpose access (random access, including being vectorization-
friendly);
- the fastest default access pattern (begin-to-end or end-to-begin is prefetcher-
friendly);
- the lowest space overhead (contiguous layout has zero per-element overhead, which
is cache-friendly).

- Usually you need to add and remove elements from the container, so use vector by
default; if you don’t need to modify the container’s size, use array.

### C++ Arrays
- like c arrays but with some methods
```cpp
#include <iostream>
#include <array>
int main()
{
    std::array <int,5> numbers = {1,2,3,4,5};
}
```
### std::vectors
```cpp
#include <iostream>
#include <vector>
#include <array>
#include <utility>
#include <initializer_list>

int main() {
    std::vector<int> vec1; // default constructor, creates an empty vector

    std::vector<int> vec2(5); // {0,0,0,0,0}

    std::vector<int> vec3(3, 10); // {10,10,10}

    std::array<int, 5> arr = {1, 2, 3, 4, 5};
    std::vector<int> vec4(arr.begin(), arr.end()); // constructor with iterators, creates a vector with elements from the array

    std::vector<int> vec5(vec4); // copy constructor, creates a vector with the same elements as vec4

    std::vector<int> vec6(std::move(vec5)); // move constructor, creates a vector by moving the elements from vec5

    std::initializer_list<int> initList = {1, 2, 3, 4, 5};
    std::vector<int> vec7(initList);

    return 0;
}
```
### Associative containers Vs unordered Associative containers
- This means that the elements in a container are sorted according to a strict weak ordering criterion indicated by its comparison function(tree).
- while the elements in an unordered_map are not ordered and can be retrieved in any order(hash table)
#### Associative Containers

Associative containers store elements in a sorted order based on their keys. Some commonly used associative containers in C++ are:

- `std::set`: Stores a collection of unique elements in a sorted order.
- `std::map`: Stores key-value pairs in a sorted order based on the keys.
- `std::multiset`: Stores a collection of elements in a sorted order, allowing duplicates.
- `std::multimap`: Stores key-value pairs in a sorted order based on the keys, allowing duplicates.

These containers provide efficient search, insertion, and deletion operations, but they have a higher memory overhead compared to unordered containers.

#### Unordered Containers

Unordered containers store elements in an unordered manner (Hash yable based), providing fast access to elements based on their keys. Some commonly used unordered containers in C++ are:

- `std::unordered_set`: Stores a collection of unique elements in an unordered manner.
- `std::unordered_map`: Stores key-value pairs in an unordered manner.
- `std::unordered_multiset`: Stores a collection of elements in an unordered manner, allowing duplicates.
- `std::unordered_multimap`: Stores key-value pairs in an unordered manner, allowing duplicates.

These containers provide constant-time average complexity for search, insertion, and deletion operations, but they have a slightly higher memory overhead compared to associative containers.

### Difference between set and multiset

- `set` and `multiset` are both associative containers in C++ that store elements in a sorted order based on their keys.
- The main difference between `set` and `multiset` is that `set` only allows unique elements, while `multiset` allows duplicate elements.
- In a `set`, each element is unique, and duplicate elements are automatically rejected when inserting.
- In a `multiset`, duplicate elements are allowed, and all elements are stored in the container.
- Both `set` and `multiset` provide efficient search, insertion, and deletion operations, with a time complexity of O(log n) on average.
- When searching for an element in a `set`, it returns either 0 or 1, indicating whether the element is present or not.
- When searching for an element in a `multiset`, it returns the count of occurrences of that element.
- `set` is commonly used when uniqueness is required, while `multiset` is used when duplicate elements need to be stored.
- The choice between `set` and `multiset` depends on the specific requirements of the problem at hand.

### map

The `map` container in C++ is an associative container that stores key-value pairs. It is implemented as a balanced binary search tree, which allows for efficient search, insertion, and deletion operations.

Here are some key features of the `map` container:

- Each element in the `map` is a pair consisting of a key and a value.
- The keys in a `map` are unique, meaning that no two elements can have the same key.
- The elements in a `map` are automatically sorted based on the keys.
- The keys in a `map` are constant, meaning that they cannot be modified once they are inserted.
- The values in a `map` can be modified.

Here's an example of how to use the `map` container:

```cpp
#include <iostream>
#include <map>

int main() {
    std::map<int, std::string> studentMap;

    // Inserting elements into the map
    studentMap.insert(std::make_pair(1, "John"));
    studentMap.insert(std::make_pair(2, "Alice"));
    studentMap.insert(std::make_pair(3, "Bob"));

    // Accessing elements in the map
    std::cout << "Student with ID 2: " << studentMap[2] << std::endl;

    // Modifying values in the map
    studentMap[3] = "Charlie";

    // Iterating over the elements in the map
    for (const auto& pair : studentMap) {
        std::cout << "ID: " << pair.first << ", Name: " << pair.second << std::endl;
    }

    return 0;
}
```
### multimap
```cpp
#include <iostream>
#include <map>

int main() {
    // Create a multimap
    std::multimap<int, std::string> myMultimap;

    // Insert elements into the multimap
    myMultimap.insert(std::make_pair(1, "Apple"));
    myMultimap.insert(std::make_pair(2, "Banana"));
    myMultimap.insert(std::make_pair(2, "Blueberry"));
    myMultimap.insert(std::make_pair(3, "Cherry"));

    //myMultimap[1] = "blueberry";    //ERROR: multimap does not support [] operator
    // Iterate over the multimap and print its contents
    for (const auto& pair : myMultimap) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }

    // Find all elements with key 2
    auto range = myMultimap.equal_range(2);
    std::cout << "Elements with key 2:" << std::endl;
    for (auto it = range.first; it != range.second; ++it) {
        std::cout << it->first << ": " << it->second << std::endl;
    }

    return 0;
}
```
### Best way to study rest of the containers 

- [hackingcpp containers](https://hackingcpp.com/cpp/std/containers.html)


## Algorithms
### Iterator ranges
- begin: pointer to te first element
- end: pointer to the element after the last element
### Best way to understand algorithms
- [hackingcpp algorithms](https://hackingcpp.com/cpp/std/algorithms.html)

### Notes
- To effectively remove elements from a C++ vector using std::remove
```cpp
 // std::remove  removes all occurrences of value
 // std::erase erases the "removed" elements
v.erase(std::remove(v.begin(), v.end(), value), v.end());
```

## Try/Catch

### Overview
- **Exceptions** in C++ are used for handling errors or other exceptional conditions that disrupt the normal flow of a program.
- The **C++ standard library** uses inheritance in its exception handling, where all standard exception types are derived from `std::exception`.

### Standard Exception Types
- Some common exception types include:
  - `std::logic_error`: For logical errors (e.g., incorrect use of a function).
  - `std::domain_error`: Thrown when a mathematical domain error occurs.
  - `std::invalid_argument`: Thrown for invalid arguments.
  - `std::out_of_range`: Thrown when an argument is out of a valid range.
  - `std::runtime_error`: For runtime errors that aren't necessarily logic errors.
  - `std::overflow_error`: For arithmetic overflow.
  - `std::underflow_error`: For arithmetic underflow.

### Example of Handling Exceptions
```cpp
try {
    throw std::domain_error("Error Text");
} 
catch (std::invalid_argument const& e) {
    // Handle only invalid_argument exception
} 
catch (std::exception const& e) {
    // Catch all other std exceptions
    std::cout << e.what(); // Outputs the exception message
}
```
- In this code, there is a try block that contains the code that might throw an exception. In this case, the code is throwing a std::domain_error exception with the message "Error Text".
- Following the try block, there are two catch blocks. The first catch block catches the std::invalid_argument exception. If this exception is thrown, the code inside this block will be executed. This allows you to handle specific exceptions differently.
- The second catch block catches the std::exception base class, which is a catch-all for any other standard exceptions that are not caught by the previous catch blocks. Inside this block, the code outputs the exception message using e.what(). The what() function returns a string that describes the exception.
- By using multiple catch blocks, you can handle different types of exceptions separately and provide appropriate error handling or recovery mechanisms based on the specific exception type.
- It's important to note that the order of the catch blocks is significant. If the order of the catch blocks were reversed, the std::invalid_argument catch block would never be reached because std::invalid_argument is derived from std::exception.
- output: Caught exception: Error Text

### Using Wide Contract Functions
- **Wide contract functions** in the standard library, such as `std::vector::at`, offer safety by throwing exceptions when invalid input is provided.
- Example:
  ```cpp
  std::vector<int> v = {0, 1, 2, 3};
  int x = v.at(6); // Throws std::out_of_range
  ```
### Main and Exception Handling
- **Exception Handling in `main()`**: You can wrap the entire `main()` function with a `try-catch` block to catch and handle any exceptions that occur during the program's execution.
- Example:
  ```cpp
  void fun() { throw "test"; }
  
  int main() try {
      fun();
      return 0;
  } 
  catch (const char* e) // catches any type of exceptions
  {
      std::cout << e << std::endl; // Outputs: test
  }
  ```

### Re-Throwing Exceptions
- **Re-throwing** an exception allows it to propagate up to a higher level of the program, where it can be handled in a broader context.
- Example:
  ```cpp
  try {
      // potentially throwing code
  } 
  catch (std::exception const& e) {
      throw; // Re-throw the caught exception
  }
  ```

### Centralized Exception Handling
- **Centralizing exception handling** avoids duplicating code when the same exception types are thrown in different parts of a program. 
- This approach is useful when converting exceptions into error codes or performing uniform logging of errors.
- Example:
  ```cpp
  void handle_init_errors() {
      try { throw; } // Re-throw
      catch (err::device_unreachable const& e) { ... }
      catch (err::bad_connection const& e) { ... }
  }

  void initialize_server() {
      try { ... }
      catch (...) { handle_init_errors(); }
  }
  ```

### Catching All Exceptions
- To handle all exceptions (including unknown ones), you can use an ellipsis `...` in a `catch` block.
- Example:
  ```cpp
  try {
      // potentially throwing code
  } 
  catch (...) {
      // Handle any type of exception
  }
  ```

  Here’s an explanation of the two slides about **Namespaces** and **Namespace Aliases** in Markdown format:

---

## NameSpace

### Overview
- **Namespaces** are used in C++ to avoid name collisions and organize code into distinct logical parts, especially in large projects where multiple libraries might define classes, functions, or variables with the same name.

### Basic Usage
- You can define a namespace using the `namespace` keyword:
  ```cpp
  namespace my {
      class vector { /*...*/ };
  }
  ```
  - In this example, the `vector` class is part of the `my` namespace.

- **Using Namespaces:**
  - If you want to use the `vector` 55555 from the `my` namespace, you have to qualify it with the namespace:
    ```cpp
    my::vector v2;
    ```
  - This ensures that there is no confusion with other `vector` classes (e.g., `std::vector`).

### Multiple Files
- Namespaces can be split across multiple files:
  - `vec.h` might define a `vector` class in the `my` namespace.
  - `set.h` might define a `set` class in the same `my` namespace and another function `cut` in the `tools` namespace.
  - In `main.cpp`, you can include these headers and use the classes/functions with their respective namespace qualifiers.

### Nested Namespaces
- C++ supports nested namespaces, where you define a namespace within another namespace:
  ```cpp
  namespace std {
      namespace chrono {
          class system_clock { /*...*/ };
      }
  }
  ```
  - To access `system_clock`, you would use the fully qualified name:
    ```cpp
    auto t1 = std::chrono::system_clock::now();
    ```

### Using Declarations

- You can make a single symbol usable without fully qualifying it using the `using` keyword:

  ```cpp
  using std::chrono::system_clock;
  auto t1 = system_clock::now();
  ```

### Namespace Aliases

- **Namespace Aliases** allow you to create shorter or more convenient names for namespaces, making the code cleaner and easier to read.

- **Defining an Alias:**
  - You can define an alias for a namespace like this:

    ```cpp
    namespace sc = std::chrono;
    auto t1 = sc::system_clock::now();
    ```

  - In this example, `sc` is an alias for `std::chrono`, so you can access `system_clock` through `sc` instead of typing out the full `std::chrono` each time.

# RAII

- RAII ensures that resources, such as memory or file handles, are properly managed and released when they are no longer needed, regardless of how the block of code exits (e.g., through normal execution, exceptions, or early returns).
- This helps prevent resource leaks and makes code more robust and easier to maintain.
- In C++, RAII is commonly implemented using constructors and destructors of objects. When an object is created, it acquires the necessary resources, and when it goes out of scope or is explicitly destroyed, it releases the resources.
- By using RAII, the burden of managing resources is shifted from the programmer to the language itself, resulting in safer and more reliable code.
Here's an explanation of the RAII (Resource Acquisition Is Initialization) concept based on the image, formatted as a markdown file:

## RAII vs C-style Resource Handling

### C-style Resource Handling Example

In traditional C-style programming, resources such as file handles or database connections are managed manually. Below is an example:

```cpp
void add_to_database(database const& db, std::string_view filename) {
    DBHandle h = open_database_connection(db);
    auto f = open_file(filename);
    
    // If 'open_file' throws an exception, the connection is not closed!
    
    // Perform operations...
    
    close_database_connection(h); // This might not be reached if an exception is thrown
}
```

### Problems with C-style Resource Handling

- **Exception Safety**: If an exception occurs (e.g., when opening a file), the function may not reach the cleanup code (`close_database_connection(h)`), leading to resource leaks.
- **Manual Management**: The programmer must manually ensure that each resource is released, increasing the chance of errors.

### Manual Memory Management

#### Heap Allocation

When you allocate memory on the heap using `new`, you create a pointer that "owns" that memory:

```cpp
int* p = new int(5);
delete p; // Frees the allocated memory
```

- **Ownership**: The pointer `p` is an owning raw pointer, meaning it is responsible for managing the memory it points to.

#### Array Allocation

Similarly, for arrays, you can allocate memory like this:

```cpp
int* p = new int[3]{1, 2, 3};
delete[] p; // Use delete[] for arrays
```

- **Ownership**: Here, `p` still acts as an owning raw pointer for the allocated array.

#### The Nightmare of Raw Pointers

Using owning raw pointers can lead to significant issues:

```cpp
int* p = new int(5);
// some code ...
delete p; // Memory is freed
// more code ...
*p = 7; // Potentially dangerous!
```

### Common Problems

1. **Dangling Pointers**: If `p` is used after being deleted, it points to invalid memory.
2. **Memory Leaks**: If you forget to call `delete`, the allocated memory remains inaccessible.
3. **Double Deletion**: Deleting the same pointer multiple times can cause undefined behavior.
4. **External Memory**: If `p` points to memory used by other processes, accessing it can lead to crashes.

### Conclusion

- Managing memory manually with raw pointers is error-prone and can lead to hard-to-catch bugs. It is generally recommended to use smart pointers like `std::unique_ptr` or `std::shared_ptr` in C++ to handle memory automatically and reduce the risk of these issues.

### RAII-Based Resource Handling

With RAII, resources are tied to the lifetime of an object:

```cpp
class DBConnector {
    DBHandle handle_;
public:
    explicit DBConnector(Database& db) : handle_(make_database_connection(db)) {}

    ~DBConnector() { 
        close_database_connection(handle_); 
    }

    // Making the connector non-copyable
    DBConnector(DBConnector const&) = delete;
    DBConnector& operator=(DBConnector const&) = delete;
};

void add_to_database(database const& db, std::string_view filename) {
    DBConnector connector(db);
    
    auto f = open_file(filename);
    // If 'open_file' throws, the destructor for 'connector' is still called,
    // ensuring the database connection is closed.
    
    // Perform operations...
    
    // Connection automatically closed when 'connector' goes out of scope
}
```

# Smart Pointers 
## Smart Pointer: `unique_ptr`

`unique_ptr` is a smart pointer introduced in C++11 that manages a dynamically allocated object. It provides automatic memory management and ensures that:

- **Ownership**: Only one `unique_ptr` can own an object at any time.
- **Automatic Destruction**: When the `unique_ptr` goes out of scope, the associated object is automatically destroyed.

### Basic Usage

```cpp
#include <memory>

void foo() {
    std::unique_ptr<int> p = std::make_unique<int>(); // Allocates int on Heap
    *p = 5; // Use the pointer
    // No need to manually delete; the int is destroyed automatically!
}
```

### Key Features

- **Not Copyable**: You cannot copy a `unique_ptr`. Attempting to do so results in a compile-time error.
  
  ```cpp
  void foo() {
      auto p1 = std::make_unique<int>();
      // auto p2 = p1; // ERROR: can't copy
  }
  ```

- **Movable**: You can transfer ownership of a `unique_ptr` using `std::move`.

  ```cpp
  void foo() {
      auto p1 = std::make_unique<int>();
      auto p3 = std::move(p1); // p3 now owns the object
      // p1 is now empty; p3 manages the object
  }
  ```

## Implementing a Custom Unique Pointer

### Example: My Smart `unique_ptr`

You can create your own version of a unique pointer by implementing move semantics and proper resource management.

```cpp
namespace std {
    class MyIntUniquePtr {
    public:
        MyIntUniquePtr(int* ptr = nullptr) : m_ptr(ptr) {}
        
        // Destructor
        ~MyIntUniquePtr() {
            if (m_ptr) {
                std::cout << "Free" << std::endl;
                delete m_ptr; // Free the allocated memory
            }
        }
        // Delete copy constructor and copy assignment operator
        MyIntUniquePtr(const MyIntUniquePtr&) = delete; // Prevent copying
        MyIntUniquePtr& operator=(const MyIntUniquePtr&) = delete; // Prevent assignment
        // Move constructor
        MyIntUniquePtr(MyIntUniquePtr&& other) noexcept : m_ptr(other.m_ptr) {
            other.m_ptr = nullptr; // Transfer ownership
        }

        // Move assignment operator
        MyIntUniquePtr& operator=(MyIntUniquePtr&& other) noexcept {
            if (this != &other) {
                reset(); // Free the current resource
                m_ptr = other.m_ptr; // Transfer ownership
                other.m_ptr = nullptr;
            }
            return *this;
        }

        // Reset pointer
        void reset(int* ptr = nullptr) {
            if (m_ptr) {
                delete m_ptr; // Free old memory
            }
            m_ptr = ptr; // Assign new pointer
        }

        // Overloaded dereference operator
        int& operator*() const {
            return *m_ptr;
        }

    private:
        int* m_ptr; // Raw pointer
    };
}
```

# template

## 1. Basic Template with Single Argument

```cpp
template <typename T> 
T division(T x, T y) { 
    return x / y; 
}
```

- This template function `division` takes two arguments of the same type `T` and returns their division. The template type `T` allows the function to operate on different data types like `int`, `float`, etc.

## 2. Basic Template with Multiple Arguments

```cpp
template <typename T, typename U> 
auto division(T x, U y) { 
    return x / y; 
}
```

- This version of the `division` function is a template that can accept two arguments of different types `T` and `U`. The return type is automatically deduced using the `auto` keyword.

## 3. Class Template

```cpp
template <typename T> 
class container {
public:
    T value;
    container(T val) : value(val) {}
    void print() { 
        std::cout << value << std::endl; 
    }
};
```

- This `container` class is a template class that stores a value of type `T`. It has a constructor that initializes the value and a `print` method to display it.

## 4. Class Template with Standalone Function

```cpp
template <typename T> 
class container2 {
public:
    T value;
    container2(T val) : value(val) {}
    
    template <typename U> 
    void add(U val) { 
        value += val; 
    }
    
    void print() { 
        std::cout << value << std::endl; 
    }
};
```

- The `container2` class template is similar to `container`, but it includes an `add` method that allows adding a value of type `U` (which can be different from `T`) to the `value`.

## 5. Explicit Specialization

```cpp
template <> 
class container<float> {
public:
    float value;
    container(float val) : value(val + 1) {
        std::cout << "Specialized constructor" << std::endl;
    }
};
```

- This is an explicit specialization of the `container` class template for the type `float`. In this specialized version, the constructor adds `1` to the passed value and prints a message.

## 6. Partial Specialization

```cpp
template <typename T, typename U> 
struct array {
    array(T t, U u) { 
        std::cout << "Primary template" << std::endl; 
    }
};

template <typename T> 
struct array<T, T> { 
    array(T t, T u) { 
        std::cout << "Partial specialization" << std::endl; 
    }
};
```

- The `array` struct template demonstrates partial specialization. The primary template can handle two different types, `T` and `U`. The partially specialized template is used when both types are the same (`T, T`), and it prints a different message.

## 7. Default Template Arguments

```cpp
template <typename T, typename U = int> 
class A {
public:
    T t;
    U u;
    A(T t, U u) : t(t), u(u) {}
};
```

- The `A` class template has a default template argument `U`, which defaults to `int` if not specified. This allows for flexibility when creating objects of this class template.

## 8. Const Template Expression

```cpp
template <typename T, int Size> 
class MyArray {
public:
    T data[Size];
    MyArray() {
        for (int i = 0; i < Size; i++) {
            data[i] = i;
        }
    }
};
```

- The `MyArray` class template uses a constant expression as a template parameter (`int Size`) to define the size of an internal array. The constructor initializes this array with values from `0` to `Size-1`.

## Main Function

```cpp
int main() {
  MyArray<int, 5>arr;
  A<int> a4(2, 3);              // default
  A<int, double> a3(2, 3.5);   // explicit
  array<int, float> a(1, 2.5); // primary
  array<int, int> a2(1, 2);    // partial
  container2<int> c3(10);      // auto dedctuion in c++17
  c3.add<float>(5.5);                 // auto deduction from c++14
  c3.print();

  std::cout << division(3, 2) << std::endl;
  std::cout << division(3.5, 2.2) << std::endl;
  std::cout << division(3.5f, 2.2f) << std::endl;
  std::cout << division(3.5f, 2) << std::endl;

  container<float> c(15.5);           // specialized constructor
  container<std::string> c2("Hello"); // class template
  c2.print();
  return 0;
}
```

- This function tests the templates defined above:

  - `MyArray<int, 5> arr;` creates an `MyArray` object of size `5` with `int` type elements.
  - `A<int, double> a3(2, 3.5);` creates an `A` object with `int` and `double` types.
  - `array<int, float> a(1, 2.5);` creates an `array` object with different types, invoking the primary template.
  - `array<int, int> a2(1, 2);` creates an `array` object with the same types, invoking the partially specialized template.
  - `container2<int> c3(10);` creates a `container2` object with an initial value of `10`. The `add` method is used to add `5.5` to this value.
  - Several calls to the `division` function demonstrate the use of templates with different types.
  - The `container<float> c(15.5);` creates a `container` object with a specialized constructor for `float`.
  - The `container<std::string> c2("Hello");` creates a `container` object for `std::string` and prints the value.

The image provides an example of a variadic function template in C++. Here's an explanation of the code:

## Variadic Function Template

A variadic template allows a function or a class to accept an arbitrary number of arguments. This feature is especially useful when the number of parameters is not fixed.

#### Function to Print Multiple Arguments (IS it Recursiv؟)

```cpp
#include <iostream>

// Base case: Function to print a single argument
template <typename T>
void print(T arg) {
    std::cout << arg << " ";
}

// Recursive case: Function to print multiple arguments
template <typename T, typename... Args>
void print(T arg, Args... args) {
    std::cout << arg << " ";
    print(args...);  // Recursive call with the remaining arguments
}

int main() {
    print(1, 2.5, "hello", 'A');
    return 0;
}
```

- This function template accepts a first argument of type `T` and a parameter pack `Args...`, which can contain any number of additional arguments of varying types.
- It prints the first argument and then it calls another version of itself with the remaining arguments using the syntax `print(args...)`.
- The `main` function demonstrates how the `print` function is called with different types of arguments: an `int`, a `double`, a `const char*` (string), and a `char`.
- The `print` function processes each argument in the list by recursively calling itself until all arguments have been printed.

### How the Variadic Function Works

- The first call to `print(1, 2.5, "hello", 'A')` prints the first argument `1` and then calls `print(2.5, "hello", 'A')`.
- This process continues, reducing the argument list until only one argument remains, at which point the base case `print(T arg)` is invoked to print the final argument.
- The result is that all arguments are printed in order, separated by spaces.

The image provides examples of using `std::tuple` and `std::pair` in C++. Here's an explanation of each in Markdown format:

# `std::tuple`

```cpp
#include <iostream>
#include <tuple>
#include <string>
#include <typeinfo>

int main() {
    // Creating a tuple
    // array wih any datatype
    std::tuple<int, std::string, double> myTuple(42, "Hello", 3.14);

    // Accessing tuple elements using std::get
    int intValue = std::get<0>(myTuple);
    std::string stringValue = std::get<1>(myTuple);
    double doubleValue = std::get<2>(myTuple);

    std::cout << "Tuple elements: " << intValue << ", " << stringValue << ", " << doubleValue << std::endl;

    // Modify tuple elements using std::get and assignment
    std::get<0>(myTuple) = 100;
    std::get<2>(myTuple) = 2.71;

    std::cout << "Modified tuple elements: " << std::get<0>(myTuple) << ", " << std::get<1>(myTuple) << ", " << std::get<2>(myTuple) << std::endl;

    // Tuple size using std::tuple_size
    std::cout << "Tuple size: " << std::tuple_size<decltype(myTuple)>::value << std::endl;

    // Tuple element types using std::tuple_element
    typedef std::tuple_element<0, decltype(myTuple)>::type firstElementType;
    typedef std::tuple_element<1, decltype(myTuple)>::type secondElementType;
    typedef std::tuple_element<2, decltype(myTuple)>::type thirdElementType;

    std::cout << "Tuple element types: " << typeid(firstElementType).name() << ", " 
              << typeid(secondElementType).name() << ", " << typeid(thirdElementType).name() << std::endl;

    return 0;
}
```

### Output Explanation

- **Tuple Creation:** A `std::tuple` is created with three elements: an `int`, a `std::string`, and a `double`.
- **Element Access:** Elements are accessed using `std::get` with the index of the element.
- **Element Modification:** Tuple elements can be modified by accessing them through `std::get` and assigning a new value.
- **Tuple Size:** The size of the tuple is determined using `std::tuple_size`.
- **Tuple Element Types:** The types of the tuple elements are retrieved using `std::tuple_element` and displayed using `typeid`.

### Expected Output

```
Tuple elements: 42, Hello, 3.14
Modified tuple elements: 100, Hello, 2.71
Tuple size: 3
Tuple element types: i, NSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE, d
```

# `std::pair`


```cpp
#include <iostream>
#include <utility>

int main() {
    // Creating a pair
    std::pair<int, std::string> myPair(42, "Hello");

    // Accessing pair elements using member variables
    int intValue = myPair.first;
    std::string stringValue = myPair.second;

    std::cout << "Pair elements: " << intValue << ", " << stringValue << std::endl;

    // Modifying pair elements using member variables
    myPair.first = 100;
    myPair.second = "World";

    std::cout << "Modified pair elements: " << myPair.first << ", " << myPair.second << std::endl;

    return 0;
}
```

### Output Explanation

- **Pair Creation:** A `std::pair` is created with two elements: an `int` and a `std::string`.
- **Element Access:** Elements are accessed using the member variables `first` and `second`.
- **Element Modification:** Pair elements can be modified directly through `first` and `second`.

### Expected Output

```
Pair elements: 42, Hello
Modified pair elements: 100, World
```
