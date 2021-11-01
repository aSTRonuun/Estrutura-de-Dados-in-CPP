#include <iostream>

using namespace std;

int main() {

    int size, flag = false;
    cin >> size;

    int dominos[size];

    for(int i=0; i<size; i++) {
        cin >> dominos[i];
    }

    for(int i=0; i<size - 1; i++) {
        if(dominos[i] > dominos[i + 1]) {
            flag = true;
        }   
    }

    if(flag)
        cout << "precisa de ajuste" << endl;
    else
        cout << "ok" << endl;



    return 0;
}