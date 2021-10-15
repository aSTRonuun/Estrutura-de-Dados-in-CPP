#include <iostream>
using namespace std;
int main()
{
  const int TAM = 80;
  char guarda[TAM];
  int quantidade;
  cout << "Digite uma frase com espaços: " << endl;
  
  cin >> quantidade;

  cin.get();
  
  
  cin.getline(guarda, TAM);
  
  
  
  
  cout << "A frase digitada é: \n" << guarda << endl;
  return 0;
}