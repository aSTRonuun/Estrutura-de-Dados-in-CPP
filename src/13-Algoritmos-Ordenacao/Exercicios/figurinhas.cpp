#include <iostream>
using namespace std;

void Intercala (int A[], int p, int q, int r) {
    int *W = new int[r-p+1]; // Vetor auxiliar
    int i = p;
    int j = q+1;
    int k = 0;

    // Intercala A[p...q] e A[q+1...r]
    while(i <= q && j <= r) {
        if(A[i] <= A[j])
            W[k++] = A[i++];
        else
            W[k++] = A[j++];
    }
    while(i <= q) W[k++] = A[i++];
    while(j <= r) W[k++] = A[j++];

    // Copia vetor ordenado W para o vetor A
    for(int i = p; i <= r; i++) {
        A[i] = W[i-p];
    }

    delete[] W;
}

void mergesort(int A[], int p, int r) {
    if(p < r) {
        // Dividir
        int q = (p+r) / 2;
        // Conquistar
        mergesort(A, p, q);
        mergesort(A, q+1, r);
        // Combinar
        Intercala(A, p, q, r);
    }
}

bool verificaIguais(int A[], int B[], int n) {
    for(int i = 0; i < n; i++) {
        if(A[i] != B[i])
            return false;
    }
    return true;
}

int main() {

    int n;
    cin >> n;

    int figs1[n];
    int figs2[n];

    for(int i =0; i < n; i++) {
        cin >> figs1[i];
    }

    for(int i =0; i < n; i++) {
        cin >> figs2[i];
    }

    mergesort(figs1, 0, n-1);
    mergesort(figs2, 0, n-1);

    if(verificaIguais(figs1, figs2, n)) {
        cout << 1 << endl;
    }else {
        cout << 0 << endl;
    }


}