#ifndef TREE_H
#define TREE_H
#include <string>
#include <sstream>
#include <iostream>
#include <climits>
#include <stack>

// Definicao do struct Node
// Em C++ os structs podem ter funcoes-membro, como 
// construtores, destrutores, etc.
struct Node {
    int key;
    Node *left;
    Node *right;

    Node(int k, Node *l = nullptr, Node *r = nullptr) {
        this->key = k;
        this->left = l;
        this->right = r;
    }
};

class Tree {
public:
    Tree();
    Tree(std::string serial);
    void inorder();   // percurso em ordem simetrica
    void preorder();  // percurso em pre-ordem
    void bshow();     // exibe a arvore de forma amigavel
    int size();
    int height();
    ~Tree();
    int sum_keys();
    int min_key();
    int total_internal_nodes();
    int um_filho();
    void delete_leaves();
    int count_leaves();
    void delete_leaves_with_value(int key);
    bool identical(Tree *t);
    Tree *clone();
    int size_iterative();
    std::string find_path(int value);
    int node_depth(int value);
private:
    Node *_root;
    Node *_clear(Node *root);
    void _inorder(Node *node);
    void _preorder(Node *node);
    void _bshow(Node *node, std::string heranca);
    void _serializeTree(std::stringstream& ss, Node **node);
    int _size(Node *node);
    int _height(Node *node);
    int _sum_keys(Node *node);
    int _min_key(Node *node);
    int _total_internal_nodes(Node *node);
    int _um_filho(Node *node);
    Node* _delete_leaves(Node *node);
    int _count_leaves(Node *node);
    Node* _delete_leaves_with_value(Node *node, int key);
    bool _identical(Node *node1, Node *node2);
    Node* _clone(Node *node);
    int _size_iterative(Node *node);
    std::string _find_path(Node *node, int value);
    int _node_depth(Node *node, int value);
};

Tree::Tree() {
    _root = nullptr;
}

// Construtor
Tree::Tree(std::string serial) {
    _root = nullptr;
    std::stringstream ss(serial);
    _serializeTree(ss, &_root);
}

// Essa funcao recursiva recebe como entrada uma string contendo 
// uma versao serializada da arvore e recebe um ponteiro para ponteiro para o no raiz.
// A funcao ler os dados e constroi a arvore seguindo um percurso em pre-ordem.
void Tree::_serializeTree(std::stringstream& ss, Node **node) {
    std::string value;
    ss >> value;
    if(value == "#") // filho == nullptr
        return;
    int key = std::stoi(value);
    *node = new Node(key);
    _serializeTree(ss, &((*node)->left));
    _serializeTree(ss, &((*node)->right));
}


// Destrutor
Tree::~Tree() {
    _root = _clear(_root);
}

// Essa funcao recebe uma raiz chamada node e
// ela libera todos os nos decendentes de node e o proprio node.
Node *Tree::_clear(Node *node) {
    if(node != nullptr) { // caso geral: vamos liberar essa arvore
        node->left = _clear(node->left);
        node->right = _clear(node->right);
        delete node;
    }
    return nullptr;
}

void Tree::inorder() {
    _inorder(_root);
}

void Tree::_inorder(Node *node) {
    if(node != nullptr) { // Caso Geral
        _inorder(node->left);
        std::cout << node->key << " ";
        _inorder(node->right);  
    }
}

void Tree::preorder() {
    _preorder(_root);
}

void Tree::_preorder(Node *node) {
    if(node != nullptr) {
        std::cout << node->key << " ";
        _preorder(node->left);
        _preorder(node->right);
    }
}

void Tree::bshow(){
    _bshow(_root, "");
}

void Tree::_bshow(Node *node, std::string heranca) {
    if(node != nullptr && (node->left != nullptr || node->right != nullptr))
        _bshow(node->right , heranca + "r");
    for(int i = 0; i < (int) heranca.size() - 1; i++)
        std::cout << (heranca[i] != heranca[i + 1] ? "│   " : "    ");
    if(heranca != "")
        std::cout << (heranca.back() == 'r' ? "┌───" : "└───");
    if(node == nullptr){
        std::cout << "#" << std::endl;
        return;
    }
    std::cout << node->key << std::endl;
    if(node != nullptr && (node->left != nullptr || node->right != nullptr))
        _bshow(node->left, heranca + "l");
}

int Tree::size() { //TODO
    return _size(_root);
}

int Tree::_size(Node *node) { // TODO
    //Se o node for diferente de vazio inicia contador com 0
    //Incrementa o contador chamando a funcao recursivamente
    if(node != nullptr){
        int count = 1;
        count += _size(node->left);
        count += _size(node->right);
        return count;
    }
    return 0;
}

int Tree::height() { // TODO
    return _height(_root);
}

int Tree::_height(Node *node) { // TODO
    if(node != nullptr){
        int h_left = 0, h_right = 0;

        h_left = _height(node->left);
        h_right = _height(node->right);

        if(h_left > h_right){
            return h_left + 1;
        }else {
            return h_right + 1;
        }
    }
    return 0;
}

int Tree::sum_keys() { //TODO
    return _sum_keys(_root);
}

int Tree::_sum_keys(Node *node) {
    if(node != nullptr){
        int sum = 0;
        sum += _sum_keys(node->left);
        sum += _sum_keys(node->right);
        sum += node->key;

        return sum;
    }
    return 0;
}

// Para fazer essa funcao, suponha que as arvores dos testes nunca serao vazias,
// assim, sempre havera um menor valor de chave a ser retornado
int Tree::min_key() { //TODO
    return _min_key(_root);
}

// Supoe que o ponteiro recebido sempre eh diferente de nullptr
int Tree::_min_key(Node *node) {
    if(node != nullptr) {
        int left = _min_key(node->left);
        int right = _min_key(node->right);
        if(left < right && left < node->key)
            return left;
        else if(right < left && right < node->key)
            return right;
        else if(node->key < left && node->key < right)
            return node->key;
        else
            return node->key;

    }
    return INT_MAX;
}

int Tree::total_internal_nodes() {
    return _total_internal_nodes(_root);
}

int Tree::_total_internal_nodes(Node *node) {
    if(node != nullptr){
        int count = 0;
        count += _total_internal_nodes(node->left);
        count += _total_internal_nodes(node->right);
        if(node->left != nullptr || node->right != nullptr){
            count++;
            return count;
        }
        return count;
    }
    return 0;
}

int Tree::um_filho() {
    return _um_filho(_root);
}

int Tree::_um_filho(Node *node){
    if(node != nullptr){
        int count = 0;
        count += _um_filho(node->left);
        count += _um_filho(node->right);
        if((node->left != nullptr && node->right == nullptr) || (node->left == nullptr && node->right != nullptr)) {
            count++;
            return count;
        }
        return count;
    }
    return 0;
}

void Tree::delete_leaves() {
    _delete_leaves(_root);
}

Node* Tree::_delete_leaves(Node *node) {
    if(node != nullptr){
        if(node->left == nullptr && node->right == nullptr) {
            delete node;
            node = nullptr;
            return node;
        }else{
            node->left = _delete_leaves(node->left);
            node->right = _delete_leaves(node->right);
        }
        return node;
    }
    return node;
}

int Tree::count_leaves() {
    return _count_leaves(_root);
}

int Tree::_count_leaves(Node *node) {
    if(node != nullptr){
        int count = 0;
        count += _count_leaves(node->left);
        count += _count_leaves(node->right);
        if(node->left == nullptr && node->right == nullptr){
            count++;
        }
        return count;
    }
    return 0;
}

void Tree::delete_leaves_with_value(int key) {
    _delete_leaves_with_value(_root, key);
}

Node* Tree::_delete_leaves_with_value(Node *node, int key) {
   if(node != nullptr){
       if(node->right == nullptr && node->left == nullptr) {
            if(node->key == key) {
                delete node;
                node = nullptr;
                return node;
            }
            return node;
        }
        node->left = _delete_leaves_with_value(node->left, key);
        node->right = _delete_leaves_with_value(node->right, key);
        return node;
   }
   return node;
}

bool Tree::identical(Tree *t) {
    return _identical(_root, t->_root);
}

bool Tree::_identical(Node *node1, Node *node2) {
    if(node1 != nullptr && node2 != nullptr){
        if(node1->key == node2->key){
            return _identical(node1->left, node2->left) && _identical(node1->right, node2->right);
        }
        return false;
    }
    return true;
}

Tree* Tree::clone() {
    Tree *t = new Tree();
    t->_root = _clone(_root);

    return t;
}

Node* Tree::_clone(Node *node) {
    if(node != nullptr) {
        Node *new_node = new Node(node->key);
        new_node->left = _clone(node->left);
        new_node->right = _clone(node->right);
        return new_node;
    }
    return node;

}

int Tree::size_iterative() {
    return _size_iterative(_root);
}

int Tree::_size_iterative(Node *node) {
    if(node != nullptr) {
        std::stack<Node*> pilha;
        pilha.push(node);
        int count = 0;

        while(!pilha.empty()){
            Node *aux = pilha.top();
            pilha.pop();
            if(aux != nullptr) {
                count++;
                pilha.push(aux->right);
                pilha.push(aux->left);
            }
        }
        return count;
    }
    return 0;
}

std::string Tree::find_path(int value) {
    return _find_path(_root, value);
}

/**
 * Saida:
 *  - se o valor existir
 *   - mostre o caminho da raiz até o no
 *   - indicando "l" ou "r" se o caminho é pelo filho esquerdo ou direito, respectivamente
 *   - ponha um "x" para quando achar o no
 * - se o valor nao existir
 *  - mostre "!"
 * 
 */
std::string Tree::_find_path(Node *node, int value) {
    if(node != nullptr) {
        if(node->key == value) {
            return "x";                               
        }
        std::string left_path = _find_path(node->left, value);                               
        if(left_path.back() == 'x') {
            return "l" + left_path;
        }                
        std::string right_path = _find_path(node->right, value);
        if(right_path.back() == 'x') {
            return "r" + right_path;
        }
    }                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          
    return "!";
}
                                    
int Tree::node_depth(int value) {
    return _node_depth(_root, value);
}

int Tree::_node_depth(Node *node, int value) {
    // Se o valor nao existis, retorna -1
    if(node != nullptr) {
        // Se o valor existir, retorna a profundidade do no
        if(node->key == value) {
            return 0;
        }
        // Se o valor nao existir, retorna a profundidade do no mais a profundidade do filho mais profundo
        int left_depth = _node_depth(node->left, value);
        if(left_depth != -1) {
            return left_depth + 1;
        }
        // 
        int right_depth = _node_depth(node->right, value);
        if(right_depth != -1) {
            return right_depth + 1;
        }
    }
    return -1;

}

// Verifica se o node é diferente de nulo
// Se o node for diferente de nulo
//     Verifica se o node é igual ao valor
//         Se for igual, retorna a profundidade do node
    
//     Cria um contador para receber a funcao recursivamente para calcular a profundidade do filho esquerdo
//     Verifica se o contato é diferente de -1
//         Se for diferente de -1, retorna a profundidade do node mais a profundidade do filho mais profundo esquerdo
    
//     Faz a mesma coisa para o filho direito
    
// Se o node for igual a nulo
//     retorna -1


#endif