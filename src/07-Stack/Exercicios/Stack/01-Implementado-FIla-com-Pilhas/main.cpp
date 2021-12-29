#include <iostream>
#include "Stack.h"

using namespace std;

int main() {
    Stack<int> deposito;
    Stack<int> prateleira;

    int operations;
    cin >> operations;
    for(int i=0; i<operations; i++) {
        int oprt;
        cin >> oprt;
        if(oprt == 1){
            int value;
            cin >> value;
            deposito.push(value);
        }else if(oprt == 2) {
            if(prateleira.empty()){
                while(!deposito.empty()){
                    prateleira.push(deposito.top());
                    deposito.pop();
                }
            }
            prateleira.pop();
        }else if(oprt == 3) {
            if(prateleira.empty()) {
                while(!deposito.empty()) {
                    prateleira.push(deposito.top());
                    deposito.pop();
                }
            }
            cout << prateleira.top() << endl;
        }
    }
}