#include <iostream>
using namespace std;

void print_vetor(int vet[], int n) {
    for(int i=0; i<n; i++) {
        if(i == 0)
            cout << "[";
        if(i<n-1)
            cout << vet[i] << ", ";
        else
            cout << vet[i] << "]" << endl;
    }
}

void triangulo_recursivo(int vet[], int n){
    if(n >= 0){
        //Precisa-se criar um vetor e atribuir os elementos somando
        int vet2[n-1];
        for(int i=0; i<n-1; i++){
            vet2[i] = vet[i] + vet[i+1];
        }

        triangulo_recursivo(vet2, n-1);
        print_vetor(vet, n);
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