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

    bool verificar_aprovacao(){
        if(nota >= 7)
            return true;
        else
            return false;
    }
};

int main() {

    Aluno aluno1;

    aluno1.recebe_dados();

    if(aluno1.verificar_aprovacao()){
        std::cout << aluno1.nome << " aprovado(a) em " << aluno1.disciplina << std::endl; 
    }else{
        std::cout << aluno1.nome << " reprovado(a) em " << aluno1.disciplina << std::endl;
    }
    
}   