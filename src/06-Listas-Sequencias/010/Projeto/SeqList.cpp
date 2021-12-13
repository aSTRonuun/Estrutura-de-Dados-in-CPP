#include <iostream>
#include <stdexcept>
#include "SeqList.h"

using namespace std;

// Construtor
SeqList::SeqList(int capacity) { // O(1)
    m_capacity = capacity;
    m_size = 0;
    m_array = new int[m_capacity];
}

// Destrutor
SeqList::~SeqList() { // O(1)
    delete[] m_array;
}

// Limpa a lista deixando-a vazia, com zero elementos
void SeqList::clear() { // O(1)
    m_size = 0; 
}

// Retorna true se e somente se a lista estiver cheia
bool SeqList::full() const { // O(1)
   return (m_capacity == m_size);
}

// Adiciona um elemento ao final da lista
// Este método deve aumentar o tamanho da lista caso seja necessário
// Agora a lista não tem tamanho limitado
void SeqList::push_back(int elemento) { 
    if(!full()){
        m_array[m_size] = elemento;
        m_size++;
        return;
    }
    m_capacity *= 2;
    int *array_new =  new (nothrow) int[m_capacity];
    if(array_new == nullptr){
        cout << "Error ao alocar mémoria" << endl;
        return;
    } 
    for(int i=0; i<m_size; i++) {
        array_new[i] = m_array[i];
    }
    delete[] m_array;
    m_array = array_new;
    m_array[m_size] = elemento;
    m_size++;

}

// Retorna o tamanho (o número de elementos atualmente) da lista
int SeqList::size() const { // O(1)
    return m_size;
}

// Retorna a capacidade total da lista
int SeqList::capacity() const { // O(1)
    return m_capacity;
}

// Retorna uma referência para o elemento na primeira posição
int& SeqList::front() { // O(1)
    if(m_size == 0) { // lista vazia: erro
        throw new std::runtime_error("fail: lista vazia");
    }
    return m_array[0];
}

// Retorna uma referência para o elemento na última posição
int& SeqList::back() { // O(1)
    if(m_size == 0) { // lista vazia: erro
        throw new std::runtime_error("fail: lista vazia");
    }
    return m_array[m_size-1];
}

void SeqList::check_range(int i) const {
    if(i < 0 || i >= m_size) { // O(1)
        throw new std::runtime_error("fail: índice fora do intervalo");
    }
}

// Retorna o valor do elemento no índice i
int SeqList::get(int i) const {
    check_range(i); // O(1)
    return m_array[i];
}

// Remove o elemento na última posição da lista
// Deve ajustar(diminuir) o tamanho da lista caso 
// ela fique grande demais e com poucos elementos
void SeqList::remove_back() {
    // Se o vetor tive no maximo 5 elementos a menos do que a capacidade, realoca o vetor para compartar capacidade - 5
    if(this->m_capacity - this->m_size < 6){
        m_array[m_size] = 0;
        m_size--;
        return;
    }
    m_capacity -= 5;
    int *new_array = new (nothrow) int[m_capacity];
    if(new_array == nullptr){
        cout << "Error ao alocar mémoria" << endl;
        return;
    } 
    for(int i=0; i<m_size; i++){
        new_array[i] = m_array[i];
    }
    delete[] m_array;
    m_array = new_array;
    m_size--;
}

// operador[] sobrecarregado como uma função-membro da classe SeqList
int& SeqList::operator[](int index) { // O(1)
    check_range(index);
    return m_array[index];
}

// operador<< sobrecarregado como uma função global usando friend
std::ostream& operator<<(std::ostream& out, const SeqList& list) { // O(n)
    out << "[ ";
    for(int i = 0; i < list.size(); i++) {
        out << list.m_array[i] << " ";
    }
    out << "]";
    return out;
}