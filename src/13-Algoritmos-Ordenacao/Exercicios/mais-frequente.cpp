#include <iostream>

using namespace std;

void bubblesortMelhorado(int A[], int n) {
    for(int i=0; i<n; i++) {
        bool trocou = false;
        for(int j=n-1; j>i; j--) {
            if(A[j] < A[j-1]) {
                int aux = A[j];
                A[j] = A[j-1];
                A[j-1] = aux;
                trocou = true;
            }
        }
        if(!trocou) break;
    }
}

int main() {
    int n;
    cin >> n;
    int A[n];
    for(int i=0; i<n; i++) {
        cin >> A[i];
    }

    bubblesortMelhorado(A, n);

    for(int i=0; i<n; i++) {
        cout << A[i] << " ";
    }

    int mais_frequente = A[0];
    int count_mais_frequente = 1; 
    int count_atual = 1;
    for(int i=0; i<n; i++) {
        if(A[i] == A[i+1]) {
            count_atual++;
        }else{
            if(count_atual > count_mais_frequente) {
                count_mais_frequente = count_atual;
                mais_frequente = A[i];
                count_atual = 1;
            }
        }
    }

    cout << mais_frequente << " " << count_mais_frequente << endl;

}