#include <iostream>

using namespace std;

void selectionsort(int A[], int n) {
    for(int i=0; i<n-1; i++) {
        int min = i;
        for(int j=i+1; j<n; j++) {
            if(A[j] < A[min])
                min = j;
        }
        if(A[min] != A[i]) {
            int aux = A[i];
            A[i] = A[min];
            A[min] = aux;
        }
    }
}

bool verificaVacina(int A[], int B[], int n) {
    for(int i=0; i<n; i++) {
        if(A[i] < B[i]){
            return false;
        }
    }
    return true;
}

int main() {

    int n;
    cin >> n;
    int vacinas[n], pacientes[n];
    
    for(int i=0; i<n; i++) {
        cin >> vacinas[i];
    }
    for(int i=0; i<n; i++) {
        cin >> pacientes[i];
    }

    selectionsort(vacinas, n);
    selectionsort(pacientes, n);

    if(verificaVacina(vacinas, pacientes, n)) {
        cout << "Yes" << endl;
    }else {
        cout << "No" << endl;
    }


    return 0;
}