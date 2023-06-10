#include <iostream>

using namespace std;

class Prac {
    private:
        int num; 
        shared_ptr<Prac> ptr;
    public:
        Prac(int num) {
            this->num = num;
            cout<<this->num<<" has been created.\n";
        }

        ~Prac() {
            cout<<this->num<<" has been destroyed.\n";
        }

        void setPtr(shared_ptr<Prac> ptr) {
            this->ptr = ptr;
        }
};

void demonstrateSharedPtr();
void demonstrateSharedPtr2();

int main() {

    demonstrateSharedPtr();
    demonstrateSharedPtr2();

    return 0;
}

/**
 * This smart pointer allows multiple shared_ptr instances to share ownership of the same object.
 * It keeps track of the reference count internally, and when the last shared_ptr owning the object goes out of scope,
 * the memory is deallocated. It provides automatic memory management for shared ownership scenarios.
 * 하나의 객체를 하나의 포인터만 가리키던 유니크 포인터와 달리,
 * 하나의 객체를 여러 포인터가 가리킬 수 있는 포인터 입니다.
 */
void demonstrateSharedPtr() {
    cout<<"---------- shared_ptr demonstration 1  ----------\n";
    shared_ptr<int> ptr1(new int(5));
    cout<<"shared_ptr<int> ptr1(new int(5));"<<endl;
    cout<<"ptr1.use_count(): "<<ptr1.use_count()<<endl<<endl;

    auto ptr2 = ptr1;
    cout<<"auto ptr2 = ptr1;"<<endl;
    cout<<"ptr1.use_count(): "<<ptr1.use_count()<<endl<<endl;
}

void demonstrateSharedPtr2() {
    cout<<"---------- shared_ptr demonstratin 2 ----------\n";
    shared_ptr<Prac> obj1 = make_shared<Prac>(5);
    shared_ptr<Prac> obj2 = make_shared<Prac>(10);

    cout<<"\nshared_ptr<Prac> obj1 = make_shared<Prac>(5);\n";
    cout<<"shared_ptr<Prac> obj2 = make_shared<Prac>(10);\n\n";

    obj1->setPtr(obj2);
    obj2->setPtr(obj1);
    obj1.reset();

    cout<<"obj1->setPtr(obj2);\n";
    cout<<"obj2->setPtr(obj1);\n";
    cout<<"obj1.reset();\n\n";

    cout<<"obj1's desctructor is not called yet which implies that there is a memory leak.\n\n";

}

