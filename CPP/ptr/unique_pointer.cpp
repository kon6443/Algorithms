#include <iostream>

using namespace std;

void demonstrateUniquePtr();
void demonstrateSharedPtr();
void demonstrateWeakPtr();

void smart_pointer();

int main() {

    demonstrateUniquePtr();
    demonstrateSharedPtr();

    return 0;
}

/**
 * There are three commonly used types of smart pointers in C++:
 * `std::unique_ptr` `std::shared_ptr` `std::weak_ptr`.
 */

/**
 * Only one unique_ptr can own the object at a time, and when the unique_ptr goes out of scope, 
 * it automatically deallocates the memory. It is lightweight and efficient.
 * 한 번에 하나의 unique_ptr만이 객체를 소유할 수 있으며, 
 * unique_ptr이 범위를 벗어나면 자동으로 메모리 할당을 해제합니다. 이는 가볍고 효율적입니다.
 */
void demonstrateUniquePtr() {
    cout<<"----------Demonstration of unique_ptr----------"<<endl;
    // Two ways of creating a `std::unique_ptr`. 
    unique_ptr<int> ptr1(new int(5));
    auto ptr2 = make_unique<int>(10);
   
    cout<<"unique_ptr<int> ptr1(new int(5));"<<endl; 
    cout<<"auto ptr2 = make_unique<int>(10);"<<endl; 

    cout<<"*ptr1: "<<*ptr1<<endl; // 5 
    cout<<"*ptr2: "<<*ptr2<<endl<<endl; // 10
    
    // Below causes an error because only one unique_ptr can own the object at a time.
    // ptr2 = ptr1;
    ptr2 = std::move(ptr1);
    cout<<"ptr2 = ptr1; // will cause an error so you need to use move() function just like below."<<endl;
    cout<<"ptr2 = std::move(ptr1); // This will move the ownership of the object from `ptr1` to `ptr2`."<<endl;
    cout<<"*ptr1: // will cause an error since ptr1's object has been moved to ptr2 and ptr1 no longer exists."<<endl;
    cout<<"*ptr2: "<<*ptr2<<endl<<endl;
}

/**
 * This smart pointer allows multiple shared_ptr instances to share ownership of the same object. 
 * It keeps track of the reference count internally, and when the last shared_ptr owning the object goes out of scope, 
 * the memory is deallocated. It provides automatic memory management for shared ownership scenarios.
 * 하나의 객체를 하나의 포인터만 가리키던 유니크 포인터와 달리,
 * 하나의 객체를 여러 포인터가 가리킬 수 있는 포인터 입니다.
 */ 
void demonstrateSharedPtr() {
    cout<<"----------Demonstration of shared_ptr----------"<<endl;
    shared_ptr<int> ptr1(new int(5));
    cout<<"shared_ptr<int> ptr1(new int(5));"<<endl;
    cout<<"ptr1.use_count(): "<<ptr1.use_count()<<endl<<endl;

    auto ptr2 = ptr1;
    cout<<"auto ptr2 = ptr1;"<<endl;
    cout<<"ptr1.use_count(): "<<ptr1.use_count()<<endl<<endl;
}

void demonstrateWeakPtr() {
}
