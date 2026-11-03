#include<iostream>
using namespace std;

int fibonacci (int n) {
    if (n <= 1) return n;
    int a=0, b=1, c;
    for (int i=2; i<=n; i++) {
        c = a + b;
        a = b;
        b = c;
    }
    return c;
}

// Recursive function to calculate Fibonacci number
int fibonacci(int n) {
    if (n <= 1) return n;
    return fibonacci(n-1) + fibonacci(n-2);
}


int main() {

    int n;
    cout<<"Enter ith index of Fibonacci series : ";
    cin>>n;
    cout<<"Fibonacci series is : "<<endl;
    for (int i=0; i<n; i++) {
        cout<<fibonacci(i)<<" ";
    }

    return 0;
}