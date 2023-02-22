#include <iostream>

using namespace std;

// There is a promise that people decided to refer an interface starting with letter 'I'. 
// Thus, notice below "ICamera" is an interface.  
struct ICamera   
{
    virtual void take() = 0;
};

class People
{
public:    
    void useCamera(ICamera* p) { p->take();}
};

class Camera : public ICamera
{
public:
    void take() 
    {
         cout<<"Take a picture."<<endl; 
    }
};

class BetterCamera : public ICamera
{
public:
    void take() 
    {
         cout<<"Take a better picture."<<endl; 
    }
};

int main()
{
    People p;
    Camera c1;
    p.useCamera(&c1);
    
    BetterCamera bc;
    p.useCamera(&bc);

    return 0;

}

