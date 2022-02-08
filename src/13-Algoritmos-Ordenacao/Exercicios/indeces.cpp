#include <iostream>
using namespace std;

void bubblesortMelhorado(int A[], int n) {
    for(int i=0; i<n; i++) {
        bool trocou = false;
        for(int j=n-1; j<i; i++) {
            if(A[j] < A[j-1]) {
                int aux = A[j];
                A[j] = A[j-1];
                A[j-1] = aux;
            }
        }
        if(!trocou) break;
    }
}

// Saida: indices do vetor ordenado orginais

int main() {


    return 0;
}