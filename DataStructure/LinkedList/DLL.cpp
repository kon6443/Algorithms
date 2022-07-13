#include <iostream>

using namespace std;

class Node {
    friend class DLL;
private:
    int data;
    Node* pNext;
    Node* pPrev;
public:
    Node();
    Node(int data);
    ~Node();
};

class DLL {
private: 
    Node* pHead;
    Node* pTail;
    Node* pCursor;
public:
    DLL();
    ~DLL();
    void insertion(int);
    void deletion(int);
    void traversal();
    void reverseTraversal();
    int size();
};

Node::Node() {
    this->pPrev = NULL;
    this->pNext = NULL;
}

Node::Node(int data) {
    this->data = data;
    this->pPrev = NULL;
    this->pNext = NULL;
}

Node::~Node() {}

DLL::DLL() {
    pHead = new Node(); 
    pTail = new Node();
    pCursor = new Node();
    pHead->pNext = pTail;
    pTail->pPrev = pHead;
}

DLL::~DLL() {}

void DLL::insertion(int data) {
    Node* temp = new Node(data);
    pCursor = pHead->pNext;
    pHead->pNext = temp;
    temp->pNext = pCursor;
    pCursor->pPrev = temp;
    temp->pPrev = pHead;
}

void DLL::deletion(int data) {
    if(pHead->pNext == pTail) cout<<"No node exists"<<endl;
    else {
        pCursor = pHead->pNext;
        while(pCursor != pTail) {
            if(pCursor->data == data) {
                pCursor->pPrev->pNext = pCursor->pNext;
                pCursor->pNext->pPrev = pCursor->pPrev;
                delete pCursor;
                return ;
            } else {
                pCursor = pCursor->pNext;
            }
        }
    }
}

void DLL::traversal() {
    if(pHead->pNext == pTail) cout<<"No node exists"<<endl;
    else {
        pCursor = pHead->pNext;
        while(pCursor != pTail) {
            cout<<pCursor->data<<" ";
            pCursor = pCursor->pNext;
        }
        cout<<endl;
    }
}

void DLL::reverseTraversal() {
    if(pTail->pPrev == pHead) cout<<"No node exists"<<endl;
    else {
        pCursor = pTail->pPrev;
        while(pCursor != pHead) {
            cout<<pCursor->data<<" ";
            pCursor = pCursor->pPrev;
        }
        cout<<endl;
    }
}

int DLL::size() {
    int size = 0;
    if(pHead->pNext == pTail) return size;
    else {
        pCursor = pHead->pNext;
        while(pCursor != pTail) {
            size++;
            pCursor = pCursor->pNext;
        }
        return size;
    }
}

int main() {

    DLL dll;
    dll.insertion(1);
    dll.insertion(2);
    dll.insertion(3);
    dll.traversal();
    dll.reverseTraversal();
    cout<<"After deletion"<<endl;
    dll.deletion(3);
    dll.traversal();
    dll.reverseTraversal();
    cout<<"size: "<<dll.size()<<endl;

    return 0;
}

