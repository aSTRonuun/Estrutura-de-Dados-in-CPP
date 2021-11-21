#include <iostream>
using namespace std;

bool verifica_ordem(int array[], int n) {
    for(int i=0; i<n-1; i++){
        if(array[i] > array[i+1]){
            return false;
        }
    }
    return true;
}

int main() {

    int n;
    cin >> n;

    int array[n];
    for(int i=0;i<n;i++){
        cin >> array[i];
    }

    if(verifica_ordem(array, n)){
        cout << "Vetor esta em ordem crescente" << endl;
    }else {
        cout << "Vetor nao esta em ordem crescente" << endl;
    }

    return 0;
}