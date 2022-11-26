#include <iostream>

using namespace std;

int gcd(int, int);
int lcm(int, int);

int main() {
    int a = 6;
    int b = 10;
    cout<<"GCD of "<<a<<" and "<<b<<" is: "<<gcd(a, b)<<endl;
    cout<<"LCM of "<<a<<" and "<<b<<" is: "<<lcm(a, b)<<endl; 
    return 0;
}

// Greatest common divisor
int gcd(int a, int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
 
// Least common multiple
int lcm(int a, int b) {
    return (a/gcd(a, b)) * b;
}
