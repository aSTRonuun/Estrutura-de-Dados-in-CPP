#include <iostream>

using namespace std;

int fibonacci_recursivo(int n) {
    if(n == 0) return 0;
    if(n == 1 || n == 2) return 1;
    return fibonacci_recursivo(n-1) + fibonacci_recursivo(n-2);
}

int main() {


    int n;
    cin >> n;

    cout << fibonacci_recursivo(n) << endl;

    return 0;
}