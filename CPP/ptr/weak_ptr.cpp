#include <iostream>

using namespace std;

class Prac {
    private:
        int num;
        weak_ptr<Prac> ptr;
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

void demonstrateWeakPtr();

int main() {

    demonstrateWeakPtr();

    return 0;

}

/**
 * This smart pointer works in conjunction with shared_ptr and provides a non-owning, weak reference to an object. 
 * It doesn't affect the reference count, and it allows checking whether the object still exists before accessing it. 
 * It is useful for breaking potential reference cycles between objects.
 * weak_ptr은 shared_ptr와 함께 작동하며 약한 참조를 제공합니다. 
 * 참조 수에 영향을 미치지 않으며, 객체에 접근하기 전에 객체가 여전히 존재하는지 확인할 수 있습니다. 
 * 또한 객체 사이의 잠재적인 순환참조를 깨는 데 유용합니다.
 */
void demonstrateWeakPtr() {
    cout<<"---------- weak_ptr demonstration ----------\n";
    shared_ptr<Prac> ptr1 = make_shared<Prac>(5);
    shared_ptr<Prac> ptr2 = make_shared<Prac>(10);
    
    ptr1->setPtr(ptr2);
    ptr2->setPtr(ptr1);

    cout<<"\nptr1->setPtr(ptr2);\n";
    cout<<"ptr2->setPtr(ptr1);\n\n";

    ptr1.reset();
    cout<<"ptr1.reset();\n\n";

    cout<<"The destrucor has been called.\n";
    
}

