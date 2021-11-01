#include <iostream>
using namespace std;

void print_vetor(int vet[], int n) {
    for(int i=0; i<n; i++){
        if(i<n-1)
            cout << vet[i] << ", ";
        else
            cout << vet[i];
    }
}

void soma_vetor_novo(int vet1[], int vet2[], int n) {
    if(n>1){
        vet2[0] = vet1[0] + vet1[1];
        soma_vetor_novo(vet1+1, vet2+1, n-1);
    }
}

void triangulo_recursivo(int vet[], int n){
    if(n > 0 && vet != nullptr){
        
        int vet2[n-1];
        soma_vetor_novo(vet, vet2, n);

        triangulo_recursivo(vet2, n-1);
        cout << "["; 
        print_vetor(vet, n);
        cout << "]" << endl;
    }
}

int main() {

    int n;
    cin >> n;
    int vet[n];

    for(int i=0; i<n; i++) {
        cin >> vet[i];
    }

    triangulo_recursivo(vet, n);

    return 0;
}