#include <iostream>

using namespace std;

void hanoi(int n, char origem, char auxiliar, char destino) {
    if(n >= 1) {
        hanoi(n-1, origem, destino, auxiliar);
        cout << origem << " -> " << destino << endl;
        hanoi(n-1, auxiliar, origem, destino);
    }
}


int main() {

    int n;
    char a, b, c;
    cin >> n;

    hanoi(n, 'A', 'B', 'C');

    return 0;
}