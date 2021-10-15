#include <iostream>
#include <iomanip>

using namespace std;

struct Aluno {
    int matricula;
    char nomeCompleto[100];
    double media;

    void recebe_dados() {
        cin >> matricula;
        cin.ignore();
        cin.getline(nomeCompleto, 100);
        cin >> media;
    }
};


int main() {

    int quantidade, varLocalizar;
    bool encontrou{false};
    cin >> quantidade;

    Aluno alunos[5];

    for(int i=0; i<quantidade; i++) {
        alunos[i].recebe_dados();
    }

    cin >> varLocalizar;

    for(int i=0; i<quantidade; i++) {
        if(alunos[i].matricula == varLocalizar){ 
            cout << alunos[i].nomeCompleto << endl;
            cout << fixed << setprecision(1) << alunos[i].media << endl;
            encontrou = true;
            break;
        }
    }

    if(!encontrou)
        cout << "NAO ENCONTRADA" << endl;

    return 0;
}