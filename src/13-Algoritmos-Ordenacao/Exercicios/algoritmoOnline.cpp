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

int main() {

    int n;
    cin >> n;
    int A[100];
    int size = 0;

    for(int i=0; i<n; i++) {
        int operacao;
        cin >> operacao;

        switch (operacao)
        {
        case 1:
            cin >> A[size];
            size++;
            mergesort(A, 0, size-1);
            break;
        case 2:
            int k;
            cin >> k;
            cout << A[k] << endl;
            break;
        default:
            break;
        }
    }

    return 0;
}