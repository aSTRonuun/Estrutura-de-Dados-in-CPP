#include <iostream>
#include <vector>

using namespace std;

void array_input(vector<int> &array) {
    for (int i = 0; i < array.size(); i++) {
        cin >> array[i];
    }
}
void show(vector<int> &array) {
    for (int i = 0; i < array.size(); i++) {
        cout << array[i] << " ";
    }
    cout << endl;
}

void retira_da_fila(vector<int> &fila, vector<int> &fila_retirada) {
    for(int i=0; i<fila_retirada.size(); i++) {
        for(int j=0; j<fila.size(); j++) {
            if(fila_retirada[i] == fila[j]) {
                fila.erase(fila.begin()+j);
            }
        }
    }
}

int main() {

    
    int qtd_pessoas, qtd_saiu;
    cin >> qtd_pessoas;
    vector<int> fila(qtd_pessoas); 

    array_input(fila);

    cin >> qtd_saiu;
    vector<int> fila_saidos(qtd_saiu);

    array_input(fila_saidos);



    retira_da_fila(fila, fila_saidos);

    show(fila);

    return 0;
}