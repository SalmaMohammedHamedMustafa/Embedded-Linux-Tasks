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

