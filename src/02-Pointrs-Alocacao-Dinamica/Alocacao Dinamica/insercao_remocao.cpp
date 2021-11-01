#include <iostream>
#include <cstdlib>
#include <iomanip>
using namespace std;

struct aluno {
   int matricula;
   char nome[50];
   float media;
};

aluno le_aluno()
{
    aluno a;
    cin >> a.matricula;
    cin.ignore(); // lê e descarta o caractere '\n' do buffer 
    cin.get(a.nome, 50);
    cin >> a.media;
    return a;
}

/* 
Recebe vetor de alunos e novo aluno, e insere o novo aluno no final do vetor.
- v: vetor de alunos
- n: tamanho do vetor de alunos (passado por referência)
- novo: novo aluno a ser inserido no final do vetor.
*/

aluno* insere_aluno(aluno *v, int *n, aluno novo) {
   if(*n == 0) {
      v = new aluno[1];
      *n = *n + 1;
   }else {
      *n = *n + 1;
      aluno *alunos_novo = new (nothrow) aluno[*n];
      if(alunos_novo == nullptr) {
         cout << "Erro ao alocar memoria" << endl;
         return 0;
      }
      for(int i=0; i<*n; i++) {
         alunos_novo[i] = v[i];
      }
      delete[] v;
      v = alunos_novo;
   }
   v[*n-1] = novo;
   return v;
}

/*
Recebe vetor de alunos, e retira do vetor o primeiro aluno com matrícula igual à
matrícula passada como parâmetro.
- v: vetor de alunos
- n: tamanho do vetor de alunos (passado por referência)
- matricula: matrícula do aluno a ser removido.
*/

aluno* remove_aluno(aluno *v, int *n, int matricula) {
   for(int i=0; i<*n; i++) {
      if(v[i].matricula == matricula) {
         v[i] = v[*n-1];
         *n = *n - 1;
         aluno *alunos_atualizado = new (nothrow) aluno[*n];
         if(alunos_atualizado == nullptr) {
            cout << "Erro ao alocar memoria" << endl;
            return 0;
         }
         for(int j=0; j<*n; j++) {
            alunos_atualizado[j] = v[j];
         }
         delete[] v;
         v = alunos_atualizado;
         break;
      }
   }
   return v;
}

int main()
{
   int num_oper = 0, i, n = 0;
   cin >> num_oper;
   aluno *v = nullptr;

   for (i = 0; i < num_oper; i++) {
      cin.ignore(); // lê e descarta o caractere '\n' do buffer 
      char oper;
      cin >> oper;
      if (oper == 'i') {
         aluno a = le_aluno();
         v = insere_aluno(v, &n, a);
      } else {
         int mat;
         cin >> mat;
         v = remove_aluno(v, &n, mat);
      }
   }

   for (i = 0; i < n; i++) {
      cout << v[i].matricula << "\n" << v[i].nome << "\n" << std::fixed << setprecision(1) << v[i].media << "\n";
   }
   
   delete[] v;
   
   return 0;
}