#include <iostream>

using namespace std;

void imprimiString(char *string) {
    for(int i=0; string[i]; i++) {
        cout << string[i];
    }
    cout << endl;
}

int main(){
    int n;
    cin >> n;
    
    char **vetor = new char*[n];
    for(int i=0; i<n; i++){
        int size = 0;
        cin >> size;
        vetor[i] = new char[size];
        cin.ignore();
        cin.get(vetor[i], size+1);
    }

    for(int i=0; i<n; i++){
        imprimiString(vetor[i]);
    }

    for(int i=0; i<n; i++){
        delete[] vetor[i]; // libera a momeria alocada para o vetor de string em cada posicao do vetor
    }

    delete[] vetor; // libera a memoria alocada
    return 0;
}