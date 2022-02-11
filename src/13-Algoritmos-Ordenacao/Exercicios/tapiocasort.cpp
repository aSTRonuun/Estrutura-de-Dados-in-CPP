#include <iostream>
#include <vector>
using namespace std;

int maior(vector<int> vec, int tam) {
    int maior = 0;
    for (int i = 1; i <= tam; i++)
        if (vec[i] > vec[maior])
            maior = i;
    return maior;
};

bool ordenado(vector<int> vec) {
    int tam = vec.size() - 1;
    for (int i = 0; i < tam; i++)
        if (vec[i] > vec[i + 1])
            return false;
    return true;
};

void inverter(vector<int> &vec, int index) {
    for (int i = 0, j = index; i < j; i++, j--)
        swap(vec[i], vec[j]);
};

void print(vector<int> &vec) {
    int n = vec.size();
    for (int i = 0; i < n; i++)
        cout << vec[i] << " ";
    cout << "0" << endl;
};

void viradaTapioca(vector<int> &vec) {
    int countViradas = 0;
    int tam = vec.size() - 1;
    bool estaOrdenado = false;
    vector<int> vecAux;
    while (!estaOrdenado) {
        int maiorNum = maior(vec, tam);
        if(maiorNum == 0) {
            inverter(vec, tam);
            countViradas++;
            vecAux.push_back(vec.size() - 1);
        }else {
            inverter(vec, maiorNum);
            countViradas++;
            vecAux.push_back(maiorNum);
        }

        if(ordenado(vec)) {
            estaOrdenado = true;
        }
    }
    cout << countViradas << endl;

};

int main() {
    int n;
    cin >> n;
    vector<int> tapiocas;
    for (int i = 0; i < n; i++)
        cin >> tapiocas[i];
    viradaTapioca(tapiocas);
}