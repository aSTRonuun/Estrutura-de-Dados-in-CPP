#include <iostream>
using namespace std;

void bubblesort(int A[], int n) {
    for(int i=0; i<n; i++){
        for(int j=n-1; j<i; j--) {
            if(A[j] < A[j-1]) {
                int aux = A[j];
                A[j] = A[j-1];
                A[j-1] = aux;
            }
        }
    }
}

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

void insertionsort(int A[], int n) {
    for(int j=1; j<n; j++) {
        int key = A[j];
        int i = j-1;
        while(i>=0 && A[i] > key) {
            A[i+1] = A[i];
            i--;
        }
        A[i+1] = key;
    }
}

void selectionsort(int A[], int n) {
    for(int i=0; i<n-1; i++) {
        int min = i;
        for(int j=i+1; j<n; j++) {
            if(A[j] < A[min])
                min = j;
        }
        int aux = A[i];
        A[i] = A[min];
        A[min] = aux;
    }
}

/* A funcao recebe vetores crescentes A[p..q] e A[q+1..r] 
 * e rearranja A[p..r] em ordem crescente */
void Intercala (int A[], int p, int q, int r) {
  int *W = new int[r-p+1]; // Vetor auxiliar  
  int i = p;
  int j = q+1;
  int k = 0;
  
  // Intercala A[p..q] e A[q+1..r]
  while (i <= q && j <= r) {
    if (A[i] <= A[j])
      W[k++] = A[i++];
    else
      W[k++] = A[j++];
  }
  while (i <= q) W[k++] = A[i++];
  while (j <= r) W[k++] = A[j++];
  
  // Copia vetor ordenado W para o vetor A
  for (i = p; i <= r; i++)
    A[i] = W[i-p];
    
  delete[] W; // libera memoria alocada
}

void mergesort(int A[], int p, int r) {
    if (p < r) {
        // Dividir
        int q = (p + r) / 2; 
        // Conquistar
        mergesort(A, p, q);
        mergesort(A, q + 1, r);
        // Combinar
        Intercala(A, p, q, r);
    }
}

int separa (int A[], int p, int r) {
    int c = A[r];
    int j = p;
    for(int k=p; k<r; k++) {
        if(A[k] <= c) {
            std::swap(A[k], A[j]);
            j++;
        }
    }
    A[r] = A[j];
    A[j] = c;
    return j;
}

void quicksort(int A[], int p, int r) {
    if (p < r) {
        int i = separa(A, p, r);
        quicksort(A, p, i-1);
        quicksort(A, i+1, r);
    }
}