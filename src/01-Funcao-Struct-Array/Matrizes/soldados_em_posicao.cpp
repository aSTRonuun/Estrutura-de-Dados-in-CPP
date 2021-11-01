#include <iostream>

using namespace std;

int cont_soldados(int matriz[3][3]){
    int count = 0;
    for(int l=0; l<2; l++){
        for(int c=0; c<3; c++){
            if(matriz[l][c] > matriz[l + 1][c]){
                count++;
            }
        }
    }
    return count;
}

int main() {
    int matriz[3][3];

    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            cin >> matriz[i][j];
        }
    }

    cout << cont_soldados(matriz);

    return 0;
}