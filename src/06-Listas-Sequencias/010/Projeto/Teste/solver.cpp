#include <iostream>
#include "SeqList2.h"

using namespace std;

int main(){

    SeqList2 list(4); // cria SeqList com capacidade == 4

    for(int i = 1; i <= 35; i++) {
        list.push_back(i);
    }

    cout << list << endl; // imprime os números de 1 a 35 na tela

    // a linha abaixo deve imprimir na tela um número maior que 35
    cout << "Capacidade: " << list.capacity() << endl;

    cout << endl; 

    for(int i = 1; i <= 33; i++) {
        list.remove_back();
    }

    cout << list << endl; // imprime os números de 1 a 35 na tela

    // a linha abaixo deve imprimir na tela um número maior que 35
    cout << "Capacidade: " << list.capacity() << endl;

    cout << endl; 

    return 0;
}