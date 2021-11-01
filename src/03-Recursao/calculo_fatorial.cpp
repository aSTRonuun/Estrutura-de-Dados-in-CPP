#include <iostream>

using namespace std;

int fatorial_recursivo(int n) {
    if(n == 1 || n == 0) return 1;
    return n * fatorial_recursivo(n - 1);
}

int main() {

    int n;
    cin >> n;

    cout << fatorial_recursivo(n) << endl;

    return 0;
}