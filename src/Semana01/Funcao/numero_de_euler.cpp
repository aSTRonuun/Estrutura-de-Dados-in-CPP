#include <iostream>
#include <iomanip>

using namespace std;

double calcular_fatorial(int inteiro);


double calcular_euler(int inteiro) {
    double count = 1;
    for(int i=1; i<=inteiro; i++){
        count += (1 / calcular_fatorial(i));
    }

    return count;
}

double calcular_fatorial(int inteiro) {
    double count = 1;
    
    for(int i=1; i<= inteiro; i++){
        count *= i;
    }

    return count;
}



int main() {

    int inteiro;

    cin >> inteiro;

    cout << fixed << setprecision(6) << calcular_euler(inteiro) << endl;

    return 0;
}