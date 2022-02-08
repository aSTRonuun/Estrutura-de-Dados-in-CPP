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