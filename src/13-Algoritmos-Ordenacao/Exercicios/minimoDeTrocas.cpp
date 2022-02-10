#include <iostream>

using namespace std;

int selectionSort(int A[], int n) {
    int trocas = 0;
    for(int i=0; i<n-1; i++) {
        int min = i;
        for(int j=i+1; j<n; j++) {
            if(A[j] < A[min]){
                min = j;
            }
        }
        if(A[min] != A[i]) {
            int aux = A[i];
            A[i] = A[min];
            A[min] = aux;
            trocas++;
        }
    }
    return trocas;
}

int main() {

    int n;
    cin >> n;
    int A[n];

    for(int i=0; i<n; i++) {
        cin >> A[i];
    }

    cout << selectionSort(A, n) << endl;

    return 0;
}