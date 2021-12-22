#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <stdexcept>
#include <iostream>

// Define um tipo de dado chamado Item,
// que é apenas um apelido para int
typedef int Item;

/*******************************************
 * Definição do struct Node
 *******************************************/
struct Node {
    Item data;    
    Node *next;  

    // Construtor do struct Node
    // Obs.: Em C++ os structs tambem podem ter construtores,
    // destrutores ou quaisquer outras funcoes que voce quiser.
    Node(const Item& k, Node *nextnode = nullptr) {
        data = k;
        next = nextnode;
    }
};

/*****************************************
 * Declaração da classe LinkedList
 *****************************************/
class LinkedList {
private:
    Node* m_head; // ponteiro para o primeiro elemento
    int m_size;   // número de elementos na lista

public:
    // Construtor
    LinkedList(); 

    // Destrutor
    ~LinkedList(); 

    // Devolve true se e somente se a lista estiver cheia
    bool empty();

    // Deixa a lista vazia, com zero elementos
    void clear();

    // Retorna o número de elementos atualmente na lista 
    int size();

    // adiciona elemento no final da lista
    void push_back(Item data);

    // remove elemento do final da lista
    void pop_back();

    // insere um elemento na posição index
    void insert(int index, Item data);

    // remove o elemento na posição index
    void remove(int index);
    
    // operador de indexação sobrecarregado como função-membro da classe
    Item& operator[](int index);

    // operador<< sobrecarregado como função global friend 
    friend std::ostream& operator<<(std::ostream& out, const LinkedList& l);  

    
    void concat(LinkedList& lst);
    
    void removeAll(const Item& x);
    
    LinkedList *clone();
    
    void appendArray(Item v[], int n);
    
    bool equals(const LinkedList& lst);
    
    void reverse();
};

/***************************************************
 * Implementação das funções-membro da classe
 ***************************************************/

// Constructor: the linked list
// initializes empty
LinkedList::LinkedList() {
    m_size = 0;
    m_head = nullptr;
}

// Returs true if and only if the 
// list is empty
bool LinkedList::empty() {
    return m_head == nullptr;
}

// Empty the list and frees memory
void LinkedList::clear() {
    while(m_head != nullptr) {
        Node *temp = m_head;
        m_head = m_head->next;
        delete temp;
    }
    m_size = 0;
}

// Returns the size of the list
int LinkedList::size() {
    return m_size;
}

// Adds an element at the end of the list
void LinkedList::push_back(Item data) {
    Node *newnode = new Node(data, nullptr);
    if(m_head == nullptr) {
        m_head = newnode;
    } else {
        Node *current = m_head;
        while(current->next != nullptr) {
            current = current->next;
        }
        current->next = newnode;
    }
    m_size++;
}

// Deletes an element from the end of the list
void LinkedList::pop_back() {
    if(m_head == nullptr) {
        throw std::underflow_error("empty list");
    }
    if(m_head->next == nullptr) {
        delete m_head;
        m_head = nullptr;
        m_size = 0;
        return;
    }
    Node *current = m_head;
    while(current->next->next != nullptr) {
        current = current->next;
    }
    delete current->next;
    current->next = nullptr;
    m_size--;
}

// Inserts data at any position in the range [0..size()]
void LinkedList::insert(int index, Item data) {
    if(index < 0 || index > m_size) {
        throw std::out_of_range("index out of range");
    }
    if(index == 0) {
        Node *newnode = new Node(data, m_head);
        m_head = newnode;
        m_size++;
        return;
    }
    int counter = 0;
    Node *current = m_head;
    while(counter < index-1) {
        counter++;
        current = current->next;
    }
    Node *newnode = new Node(data, current->next);
    current->next = newnode;
    m_size++;
}

// Deletes data at any position in the range [0..size()-1]
void LinkedList::remove(int index) {
    if(index < 0 || index >= m_size) {
        throw std::out_of_range("index out of range");
    }
    if(index == 0) {
        Node *temp = m_head;
        m_head = m_head->next;
        delete temp;
        m_size--;
        return;
    }
    int counter = 0;
    Node *current = m_head;
    while(counter < index-1) {
        counter++;
        current = current->next;
    }
    Node *temp = current->next;
    current->next = current->next->next;
    delete temp;
    m_size--;
}

// Destructor
LinkedList::~LinkedList() {
    clear();
}

// operator[] overloaded
Item& LinkedList::operator[](int index) {
    if(index < 0 || index >= m_size) {
        throw std::out_of_range("index out of range");
    }
    int counter = 0;
    Node *current = m_head;
    while(counter < index) {
        counter++;
        current = current->next;
    }
    return current->data;
}

// operator<< overloaded
std::ostream& operator<<(std::ostream& out, const LinkedList& list) {
    Node *current = list.m_head;
    out << "[ ";
    while(current != nullptr) {
        out << current->data << " ";
        current =current->next;
    }
    out << "]";
    return out;
}


// Concatena a lista atual com a lista lst passada por parametro.
// A lista lst nao eh modificada nessa operacao. Ela permanece intacta ao final.
// Por exemplo, sejam l1 = [ 1 2 3 4 ] e l2 = [ 7 9 8 ]
// Após fazer l1.concat(l2) você deve obter
// l1 = [ 1 2 3 4 7 9 8 ] e l2 = [ 7 9 8 ]
// Restrição: está proibido usar funções auxiliares nesta questão,
// inclusive qualquer dos operadores sobrecarregados
void LinkedList::concat(LinkedList& lst) {
    if(lst.m_head == nullptr) {
        throw std::underflow_error("empty list");
    }
    Node *current = m_head;
    Node *current2 = lst.m_head;
    // Se o primeiro elemento da lista atual for nulo, concatena o primeiro 
    // elemento da lista lst para a primeira posicao da lista atual
    if(current == nullptr) {
        current = new Node(current2->data, nullptr);
        current2 = current2->next;
        m_head = current;
        while(current2 != nullptr) {
            current->next = new Node(current2->data, nullptr);
            current = current->next;
            current2 = current2->next;
            m_size++;
        }
        return;
    }
    // Se a lista tiver pelo menos um elemento, concatena a lista lst ao final da lista atual
    while(current->next != nullptr) {
        current = current->next;
    }
    while(current2 != nullptr) {
        current->next = new Node(current2->data, nullptr);
        current = current->next;
        current2 = current2->next;
        m_size++;
    }
    return;
}

// Remove da lista todas as ocorrencias do Item x.
// Se a lista estiver vazia, esta funcao nao faz nada;
// Restricao: Esta funcao deve ter complexidade O(n) no pior caso.
// Restrição: está proibido usar funções auxiliares nesta questão,
// inclusive qualquer dos operadores sobrecarregados
void LinkedList::removeAll(const Item& x) {
    if(m_head == nullptr) {
        throw std::underflow_error("empty list");
    }
    Node *current = m_head;
    Node *previous = nullptr;
    while(current != nullptr) {
        if(current->data == x) {
            if(previous == nullptr) {
                m_head = current->next;
                delete current;
                current = m_head;
                previous = nullptr;
            } else {
                previous->next = current->next;
                delete current;
                current = previous->next;
            }
        } else {
            previous = current;
            current = current->next;
        }
    }
}


// Devolve um ponteiro para uma copia desta lista.
// Veja que uma copia nao eh a mesma lista, ela contem uma copia dos dados
// Esta funcao deve ter complexidade O(n) no pior caso
// Restrição: está proibido usar funções auxiliares nesta questão,
// inclusive qualquer dos operadores sobrecarregados
LinkedList *LinkedList::clone() {
    if(m_head == nullptr) {
        throw std::underflow_error("empty list");
    }
    LinkedList *newLinkedList = new LinkedList();
    newLinkedList->m_size = m_size;
    Node *current = m_head;
    newLinkedList->m_head = new Node(current->data, nullptr);
    current = current->next;
    Node *newCurrent = newLinkedList->m_head;
    while(current != nullptr) {
        newCurrent->next = new Node(current->data, nullptr);
        current = current->next;
        newCurrent = newCurrent->next;
    }
    return newLinkedList;
}


// Copia os elementos do array v[0..n-1] para o final da lista. 
// Esta funcao deve ter complexidade O(n) no pior caso
// Restrição: está proibido usar funções auxiliares nesta questão,
// inclusive qualquer dos operadores sobrecarregados
void LinkedList::appendArray(Item v[], int n) {
    Node *current = m_head;
    // Se a lista estiver vazia, entao o primeiro elemento sera o primeiro da lista
    if(current == nullptr) {
        m_head = new Node(v[0], nullptr);
        m_size++;
        current = m_head;
        for(int i=1; i<n; i++) {
            current->next = new Node(v[i], nullptr);
            current = current->next;
            m_size++;
        }
        return;
    }
    // Se a lista nao estiver vazia, o primeiro elemento da lista v para o final
    while(current->next != nullptr) {
        current = current->next;
    }
    for(int i=0; i<n; i++) {
        current->next = new Node(v[i], nullptr);
        current = current->next;
        m_size++;
    }
}

// Determina se a lista lst, passada por parametro, eh igual 
// a lista em questao. Duas listas sao iguais se elas tem o mesmo tamanho 
// e o valor do k-esimo elemento da primeira lista eh igual ao 
// k-esimo valor da segunda lista.
// Restrição: está proibido usar funções auxiliares nesta questão,
// inclusive qualquer dos operadores sobrecarregados
bool LinkedList::equals(const LinkedList& lst) {
    if(lst.m_size == 0) {
        return false;
    }
    if(m_size != lst.m_size) {
        return false;
    }
    Node *current = m_head;
    Node *otherCurrent = lst.m_head;
    while(current != nullptr) {
        if(current->data != otherCurrent->data) {
            return false;
        }
        current = current->next;
        otherCurrent = otherCurrent->next;
    }
    return true;
}

// Inverte a ordem dos nós (o primeiro node passa a ser o último, 
// o segundo passa a ser o penultimo, etc.) 
// Restricao: Essa operacao faz isso sem criar novos nodes, apenas altera os ponteiros.
// Voce pode criar ponteiros auxiliares (um número constante deles), 
// mas nao pode alocar novos nós.
// Repetindo: está proibido chamar o operador new nesta questão.
// Restrição: Também não é permitido usar funções auxiliares nesta questão
void LinkedList::reverse() {
    if(m_head == nullptr) {
        throw std::underflow_error("empty list");
    }
    Node *previus, *current, *next;
    previus = nullptr;
    current = m_head;
    while(current != nullptr) {
        next = current->next;
        current->next = previus;
        previus = current;
        current = next;
    }
    m_head = previus;
}


#endif