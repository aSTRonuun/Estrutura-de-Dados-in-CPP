#include <iostream>
using namespace std;

/**
 * Classe SeqList, que encapsula uma lista linear de inteiros.
 * A lista linear é implementada usando alocação dinâmica sequencial.
 * Para isso, a estrutura usada como base é um array de inteiros.
 */
class SeqList2 {
private:
    int m_capacity; // capacidade total da lista
    int m_size;     // numero de elementos na lista
    int* m_array;   // ponteiro para o array de inteiros 

    // Função privada que checa se o índice i passado como argumento
    // está dentro do intervalo válido
    // Lança uma exceção caso o índice esteja fora do intervalo.
    void check_range(int i) const{
        if(i < 0 || i >= m_size) { // O(1)
            throw new std::runtime_error("fail: índice fora do intervalo");
    }
}

public:
    // Construtor
    SeqList2(int capacity){ // O(1)
        m_capacity = capacity;
        m_size = 0;
        m_array = new int[m_capacity];
    }

    // Destrutor
    ~SeqList2(){ // O(1)
        delete[] m_array;
    }

    // Limpa a lista deixando-a vazia, com zero elementos
    void clear(){ // O(1)
        m_size = 0; 
    }

    // Retorna true se e somente se a lista estiver cheia
    bool full() const { // O(1)
        return (m_capacity == m_size);
    }

    // Adiciona um elemento ao final da lista
    // Este método deve aumentar o tamanho da lista caso seja necessário
    // Agora a lista não tem tamanho limitado
    void push_back(int elemento) { 
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

    // Retorna o tamanho da lista
    int size() const { // O(1)
        return m_size;
    }

    // Retorna a capacidade total da lista
    int capacity() const { // O(1)
        return m_capacity;
    }

    // Retorna uma referência para o elemento na primeira posição
    int& front(){ // O(1)
        if(m_size == 0) { // lista vazia: erro
            throw new std::runtime_error("fail: lista vazia");
        }
        return m_array[0];
    }

    // Retorna uma referência para o elemento na última posição
    int& back(){ // O(1)
        if(m_size == 0) { // lista vazia: erro
            throw new std::runtime_error("fail: lista vazia");
        }
        return m_array[m_size-1];
    }

    // Retorna o valor do elemento no índice i
    int get(int i) const {
        check_range(i); // O(1)
        return m_array[i];
    }

    // Remove o elemento na última posição da lista
    void remove_back() {
        // TODO
    }

    // operador[] sobrecarregado como uma função-membro da classe SeqList
    int& operator[](int index){ // O(1)
        check_range(index);
        return m_array[index];
    }
    
    // operador<< sobrecarregado como uma função global usando friend
    friend std::ostream& operator<<(std::ostream& out, const SeqList2& list){ // O(n)
        out << "[ ";
        for(int i = 0; i < list.size(); i++) {
            out << list.m_array[i] << " ";
        }
        out << "]";
        return out;
    }
};