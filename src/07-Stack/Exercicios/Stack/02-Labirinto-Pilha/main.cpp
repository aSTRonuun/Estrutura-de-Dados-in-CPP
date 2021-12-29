#include <iostream>
#include <vector>
#include <string>
#include "Stack.h"
using namespace std;

struct Pos{
    int l;
    int c;
};

void show(vector<string> &matriz){
    for(string line : matriz){
        cout << line << endl;
    }
    getchar();
}

//retorna um vetor com todos os vizinhos da posição p
vector<Pos> get_vizinhos(Pos p){
    return {{p.l, p.c - 1}, {p.l - 1, p.c}, {p.l, p.c + 1}, {p.l + 1, p.c}};
}

bool valid_path(vector<string> &matriz, Pos p){
    int cont = 0;
    for(Pos vizinho : get_vizinhos(p)){
        if(matriz[vizinho.l][vizinho.c] == '#') 
            cont++;
    }
    if(cont >= 3){
        return true;
    }
    return false;
}



bool rota_fuga(vector<string> &matriz, Pos inicio, Pos fim) {
    Stack<Pos> pilha;
    pilha.push(inicio);
    matriz[inicio.l][inicio.c] = '.';
    while(!pilha.empty()){
        Pos p = pilha.top();
        if(p.l == fim.l && p.c == fim.c){
            return true;
        }
        vector<Pos> vizinhos;
        for(Pos vizinho : get_vizinhos(p)){
            if(matriz[vizinho.l][vizinho.c] == ' '){
                vizinhos.push_back(vizinho);  
            }
        }
        if(vizinhos.size() == 0){
            matriz[p.l][p.c] = 'x';
            pilha.pop();
        }else{
            Pos vizinho = vizinhos[rand() % vizinhos.size()];
            matriz[vizinho.l][vizinho.c] = '.';
            show(matriz);
            pilha.push(vizinho);
        }
         
    }
    return false;
}

void remover_x(vector<string> &matriz){
    for(int i = 0; i < matriz.size(); i++){
        for(int j = 0; j < matriz[i].size(); j++){
            if(matriz[i][j] == 'x'){
                matriz[i][j] = ' ';
            }
        }
    }
}


int main(){
    int nl = 0, nc = 0;
    cin >> nl >> nc;
    vector<string> mat(nl, ""); //começa com nl strings ""
    getchar();//remove \n after nc
    Pos inicio, fim;

    //carregando matriz
    for(int i = 0; i < nl; i++)
        getline(cin, mat[i]);

    //procurando inicio e fim e colocando ' ' nas posições iniciais
    for(int l = 0; l < nl; l++){
        for(int c = 0; c < nc; c++){
            if(mat[l][c] == 'I'){
                mat[l][c] = ' ';
                inicio = Pos {l, c};
            }
            if(mat[l][c] == 'F'){
                mat[l][c] = ' ';
                fim = Pos {l, c};
            }
        }
    }

    rota_fuga(mat, inicio, fim);

    remover_x(mat);

    for(string line : mat)
        cout << line << endl;
}