#ifndef TREE_H
#define TREE_H
#include <string>
#include <sstream>
#include <iostream>
#include <climits>

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
    Tree(std::string serial);
    void inorder();   // percurso em ordem simetrica
    void bshow();     // exibe a arvore de forma amigavel
    int size();
    int height();
    ~Tree();
    int sum_keys();
    int min_key();
    int total_internal_nodes();
    int um_filho();
private:
    Node *_root;
    Node *_clear(Node *root);
    void _inorder(Node *node);
    void _bshow(Node *node, std::string heranca);
    void _serializeTree(std::stringstream& ss, Node **node);
    int _size(Node *node);
    int _height(Node *node);
    int _sum_keys(Node *node);
    int _min_key(Node *node);
    int _total_internal_nodes(Node *node);
    int _um_filho(Node *node);
};

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
    std::cout << std::endl;
}

void Tree::_inorder(Node *node) {
    if(node != nullptr) { // Caso Geral
        _inorder(node->left);
        std::cout << node->key << " ";
        _inorder(node->right);  
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


#endif