

#include <iostream> 
using namespace std; 
  
class Test { 
private: 
    int x; 
public: 
    Test(int x = 0) : x(x) {} // Use member initializer list

    // Change the value of x to that of another Test object
    void change(Test *t) { 
        this->x = t->x; 
    } 

    void print() { 
        cout << "x = " << x << endl; 
    } 
}; 
  
int main() { 
    Test obj(5); 
    Test *ptr = new Test(10); 
    obj.change(ptr); // Change obj's x to ptr's x
    obj.print();     // Should output x = 10

    delete ptr; // Deallocate memory to prevent memory leak
    return 0; 
} 
