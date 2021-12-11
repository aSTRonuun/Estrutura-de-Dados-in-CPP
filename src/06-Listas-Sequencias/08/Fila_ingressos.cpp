#include <iostream>
#include <vector>

using namespace std;

int main() {

    vector<int> fila;
    int qtd_pessoas, qtd_saiu;
    cin >> qtd_pessoas;

    for(int i=0; i<qtd_pessoas; i++){
        int identificador;
        cin >> identificador;
        fila.push_back(identificador);
    }

    cin >> qtd_saiu;

    for(int i=0; i<qtd_saiu; i++) {
        int identificador;
        cin >> identificador;
        for(int i=0; i<fila.size(); i++) {
            if(fila[i] == identificador) {
                fila.erase(fila.begin() + i);
            }
        }
    }

    for(int i=0; i<fila.size(); i++) {
        cout << fila[i] << " ";
    }

    return 0;
}