#include <iostream>

using namespace std;

// Funcao para comparar as sting, de acordo com a função strcmp do C++
int strcmp(char *a, char *b) {
    for(int i=0; a[i] || b[i]; i++) {
        if(a[i] < b[i]) return -1;
        if(a[i] > b[i]) return 1;
    }
    return 0;
}

// Funcao para imprimir as strings
void imprimiString(char *string) {
    for(int i=0; string[i]; i++) {
        cout << string[i];
    }
    cout << endl;
}

// Funcao para ordenar as strings
void ordenaString(char **vetor, int size) {
    for(int i=0; i<size - 1; i++) {
        for(int j=0; j<size - 1; j++) {
            if(strcmp(vetor[j], vetor[j + 1]) == 1) {
                char *aux = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = aux;
            }
        }
    }
}

int main(){
    int n;
    cin >> n;
    
    char **vetor = new (nothrow) char*[n];
    if(vetor == nullptr) {
        cout << "Erro ao alocar memoria" << endl;
    }
    for(int i=0; i<n; i++){
        int size = 0;
        cin >> size;
        vetor[i] = new (nothrow) char[size];
        if(vetor[i] == nullptr) {
            cout << "Erro ao alocar memoria" << endl;
        }
        cin.ignore();
        cin.get(vetor[i], size+1);
    }

    ordenaString(vetor, n);

    for(int i=0; i<n; i++){
        imprimiString(vetor[i]);
    }

    // libera a momeria alocada para o vetor de string em cada posicao do vetor
    for(int i=0; i<n; i++){
        delete[] vetor[i]; 
    }

    // libera a memoria alocada
    delete[] vetor; 
    return 0;
}