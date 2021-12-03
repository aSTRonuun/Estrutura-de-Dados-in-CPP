// Implementacao do TAD Matriz
#include <iostream>
#include <iomanip>
#include "Matriz.h"

// Aloca espaco para matriz n por m
Matriz::Matriz(int n, int m) {
	this->lin = n;
	this->col = m;
	matriz = new (std::nothrow) int*[n];
	if(matriz == nullptr){
		return;
	}
	for(int i=0; i<lin; i++){
		matriz[i] = new int[m];
	}
}   

// Destrutor: Libera a memoria da matriz
Matriz::~Matriz() {
	for(int i=0; i< lin; i++){
		delete[] matriz[i];
		matriz[i] = nullptr;
	}
	delete[] matriz;
	matriz = nullptr;
	std::cout << "matriz liberada" << std::endl;
}     

// Retorna o valor do elemento [i][j]
int Matriz::valor(int i, int j) {
	return matriz[i][j];
} 

// Atribui valor ao elemento [i][j]
void Matriz::atribui(int valor, int i, int j) {
	matriz[i][j] = valor;
}

// Retorna o numero de linhas da matriz
int Matriz::linhas() {
	return lin;
} 

// Retorna o numero de colunas da matriz
int Matriz::colunas() { 
	return col;
}

// Imprime matriz --- Ja esta codificado 
void Matriz::imprime(int largura) {
	for (int linha = 0; linha < lin; linha++) {
		for (int coluna = 0; coluna < col; coluna++) {
			std::cout << std::setw(largura) << matriz[linha][coluna];
		}
		std::cout << std::endl;
	}
}

// Soma matrizes
Matriz *Matriz::soma(Matriz *B){
	// Verifica se as matrizes tem extamente as mesmas dimenssões
	if (B->linhas() == lin && B->colunas() == col){
		//Aloca a matriz C
		Matriz *C = new (std::nothrow) Matriz(lin, col);
		if (C == nullptr){
			return nullptr;
		}
		//Matriz na posição [i][j] recebe a soma dos elementos da matriz A com os elementos da matriz B		
		for (int i = 0; i < lin; i++){
			for (int j = 0; j < col; j++){
				C->matriz[i][j] = matriz[i][j] + B->matriz[i][j];
			}
		}
		return C;
	}
	return nullptr;
}

// Multiplica matrizes
Matriz *Matriz::multiplica(Matriz *B) {
	// Verifica se a quantidades de linhas da matriz B é exatamente igual a quantidade de colunas da matriz A
	if(B->linhas() == col){
		//Aloca a matriz C		
		Matriz *C = new (std::nothrow) Matriz(lin, B->colunas());
		if (C == nullptr){
			return nullptr;
		}
		//
		//Na nova matiz C na posicao matriz[l][c] adiciona a multiplicação e soma dos elementos da linha de A e dos elementos da coluna de B
		for(int l=0; l<C->linhas(); l++){
			for(int c=0; c<C->colunas(); c++){
				int somaTotal = 0;
				for(int i=0; i<C->linhas(); i++){
					somaTotal += matriz[l][i] * B->matriz[i][c];
				}
				C->matriz[l][c] = somaTotal;
			}
		}
		return C;
	}
	return nullptr;
}
