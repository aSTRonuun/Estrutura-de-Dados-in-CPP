#include <iostream>

int sum_row(int matriz[3][3]) {
    int sum = 0;
    for(int i=0; i<3; i++)
        sum += matriz[i][0];

    return sum;
}

int sum_col(int matriz[3][3]) {
    int sum = 0;
    for(int i=0; i<3; i++){
        sum += matriz[0][i];
    }
    return sum;
}

int sum_dia_main(int matriz[3][3]) {
    int sum = 0;
    for(int i=0; i<3; i++){
        sum += matriz[i][i];
    }

    return sum;
}

int sum_dia_secund(int matriz[3][3]) {
    int sum = 0, j = 2;
    for(int i=0; i<3; i++){
        sum += matriz[i][j];
        j--;
    }
        
    return sum;
}


int main() {
    int matriz[3][3];
    bool magico = false;

    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            std::cin >> matriz[i][j];
        }
    }
    int sum1 = sum_col(matriz);
    int sum2 = sum_row(matriz);
    int sum3 = sum_dia_main(matriz);
    int sum4 = sum_dia_secund(matriz);

    if(sum1 == sum2 && sum1 == sum3 && sum1 == sum4){
        magico = true;
    }

    if(magico) std::cout << "sim" << std::endl;
    else std::cout << "nao" << std::endl;

    return 0;
}