#include <iostream>

using namespace std;

bool verificar_primo(int inteiro) {
        for(int i=2; i<inteiro; i++) {
            if(inteiro % i == 0) {
                return false;
            }
        }
        return true;
}


int main() {

    int a, b;

    cin >> a >> b;

    for(auto i=a; i <= b; i++) {
        if(verificar_primo(i))
            
            cout << i << endl;
    }

    return 0;
}