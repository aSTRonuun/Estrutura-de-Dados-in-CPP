#include <iostream>
#include <iomanip>

struct Aluno {
    char nome[100];
    char disciplina[120];
    int matricula;
    double nota;

    void recebe_dados() {
        std::cin >> nome;
        std::cin >> matricula;
        std::cin.ignore();
        std::cin >> disciplina;
        std::cin >> nota;
    }

    void imprimir_dados(){
        std::cout << nome << std::endl;
        std::cout << matricula << std::endl;   
        std::cout << disciplina << std::endl;
        std::cout << nota << std::endl;
    }
};

void comparar_maior(Aluno aluno1, Aluno aluno2){
    if(aluno1.nota > aluno2.nota){
        std::cout << aluno1.nome << " , " << std::fixed << std::setprecision(1) << aluno1.nota << std::endl;
    }else if(aluno1.nota < aluno2.nota){
        std::cout << aluno2.nome << " , " << std::fixed << std::setprecision(1) << aluno2.nota << std::endl;
    }else {
        std::cout << aluno1.nome << " e " <<  aluno2.nome << " , " << std::fixed << std::setprecision(1) << aluno2.nota << std::endl;
    }
}

int main() {

    Aluno aluno1, aluno2;

    aluno1.recebe_dados();
    aluno2.recebe_dados();
    

    comparar_maior(aluno1, aluno2);
}   