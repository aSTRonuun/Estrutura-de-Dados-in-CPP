#include <iostream>
#include <cstring>

using namespace std;

int soma_recursiva_char(char string[], int n, char c) {
    if(n == 1){ 
        if(string[0] == c) return 1;
        else return 0;
    }
    int soma = soma_recursiva_char(string, n - 1, c);
    return soma;
}

int main()
{
    char s[102], c;

    cin.get(s, 102);
    cin.ignore();
    cin >> c;

    int n = strlen(s); // pega número de caracteres de s

    // Chame a função aqui para imprimir na tela o número de ocorrências
    cout << soma_recursiva_char(s, n, c);
    return 0;
}
