#include <iostream>
#include <vector>
#include <map>
#include <ctime>
#include <numeric> // iota();

using namespace std;

bool isPrime(int n);
vector<int> getPrime(int range); 
vector<int> sieveOfEratosthenes(int range);

int main() {
    
    int range = 1000000;

    clock_t start = clock();
    vector<int> prime = getPrime(range);
    clock_t end = clock();
    double time = double(end-start)/CLOCKS_PER_SEC;
    cout<<"Time taken by getPrime function using normal way: "<<time<<endl;
    cout<<"Number of prime number using getPrime():"<<prime.size()<<endl;

    start = clock();
    vector<int> eratosthenes = sieveOfEratosthenes(range);
    end = clock();
    time = double(end-start)/CLOCKS_PER_SEC;
    cout<<"Time taken by Sieve of Eratosthenes algorithms: "<<time<<endl;
    cout<<"Number of prime number using Sieve of Eratosthenes:"<<eratosthenes.size()<<endl;

    return 0;
}

bool isPrime(int n) {
    if(n<2) return false;
    for(int i=2;i*i<=n;i++) {
        if(n%i==0) return false;
    }
    return true;
}

vector<int> getPrime(int range) {
    vector<int> numbers(range+1);
    // Initializing the vector with values equal to their indices.
    iota(numbers.begin(), numbers.end(), 0);

    vector<int> prime;
    for(int i=2;i<=range;i++) {
        if(isPrime(numbers[i])) {
            prime.push_back(i);
        }
    } 
    return prime;
}

vector<int> sieveOfEratosthenes(int range) {
    vector<bool> numbers(range+1, true);
    for(int i=2;i*i<=range;i++) {
        if(numbers[i]) {
            // j=i*i since k*i(k<i) are already calculated priorly.
            for(int j=i*i;j<=range;j+=i) {
                numbers[j] = false;
            }
        }
    }

    vector<int> prime;
    for(int i=2;i<=range;i++) {
        if(numbers[i])
            prime.push_back(i);
    }
    return prime;
}

