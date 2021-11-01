#include <iostream>
#include <cstring>

using namespace std;

//Observando o vetor de trás para frente
int soma_recursiva_char(char string[], int n, char c) {
    if(n<1){
        return 0;
    }else{
        if(c == string[n-1]){
            return 1 + soma_recursiva_char(string, n-1, c);
        }else{
            return 0 + soma_recursiva_char(string, n-1, c);
        }
    }
}

//Observando o vetor de frente para trás
int soma_recursiva_char_v2(char string[], int n, char c) {
    if(n<1){
        return 0;
    }else{
        if(string[0] == c){
            return 1 + soma_recursiva_char_v2(string+1, n-1, c);
        }else{
            return 0 + soma_recursiva_char_v2(string+1, n-1, c);
        }
    }
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
    cout << soma_recursiva_char_v2(s, n, c);
    return 0;
}
