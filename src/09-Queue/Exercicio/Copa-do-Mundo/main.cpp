#include <iostream>
#include <string>
#include "Queue.h"

using namespace std;

int main() {
    Queue<char> fila;
    fila.push_back('A');
    fila.push_back('B');
    fila.push_back('C');
    fila.push_back('D');
    fila.push_back('E');
    fila.push_back('F');
    fila.push_back('G');
    fila.push_back('H');
    fila.push_back('I');
    fila.push_back('J');
    fila.push_back('K');
    fila.push_back('L');
    fila.push_back('M');
    fila.push_back('N');
    fila.push_back('O');
    fila.push_back('P');

    for(int i=0; i<15; i++) {
        int gols1, gols2;
        cin >> gols1 >> gols2;

        char time1, time2;
        time1 = fila.front();
        fila.pop_front();

        time2 = fila.front();
        fila.pop_front();

        if(gols1 > gols2) {
            fila.push_back(time1);
        }else{
            fila.push_back(time2);
        }
    }

    cout << fila.front() << endl;

}