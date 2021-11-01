#include <iostream>
#include <iomanip>

using namespace std;

struct Aluno {
    float nota[3];
    float media;
};

void calcula_media(Aluno *aluno) {
    double soma = 0, media = 0;

    for(int i=0; i<3; i++){
        soma += aluno->nota[i];
    }

    media = soma / 3;
    aluno->media = media;
}

void calcula_media_turma(Aluno turma[], int n) {
    for(int i=0; i<n; i++){
        calcula_media(&turma[i]);
    }
}

int main() {

    int n;

    cin >> n;
    Aluno turma[n];

    for (int j = 0; j < n; j++)
      for (int i = 0; i < 3; i++)
         std::cin >> turma[j].nota[i];
    
    calcula_media_turma(turma, n);

    for (int j = 0; j < n; j++) {
      std::cout << std::fixed;
      std::cout << std::setprecision(1) << turma[j].media << " ";
    }

    return 0;
}