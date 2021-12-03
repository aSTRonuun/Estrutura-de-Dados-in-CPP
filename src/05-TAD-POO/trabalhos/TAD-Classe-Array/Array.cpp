#include <iostream>
#include <sstream>
using namespace std;

struct Vector {
    int capacity;
    int size;
    int * data;
};

Vector * vector_create(int capacity) {
    //crie o struct vector dinâmicamente
    Vector * vector =  new (nothrow) Vector;
    if(vector == nullptr) {
        return nullptr;
    }
    //crie o vetor data
    vector->data = new ((nothrow)) int[capacity];
    if(vector->data == nullptr) {
        return nullptr;
    }
    //inicialize size e capacity
    vector->size = 0;
    vector->capacity = capacity;
    return vector;
}

void vector_destroy(Vector * vector) {
    //destrua data
    delete vector->data;
    //destrua a struct
    delete vector;
}

void vector_add(Vector * vector, int value) {
    //utilize capacity e size para verificar se ainda existe espaço
    if(vector->size == vector->capacity) {
        cout << "Nao eh possivel inserir mais elementos" << endl;
    }else {
        vector->data[vector->size] = value;
        vector->size++;
    }
}

//retorne a string no formato 
// [ a b c ]
string vector_show(Vector * vector) {
    //retorne uma string com os dados do vetor
    //você pode usar uma stringstream como buffer
    //stringstream ss;
    //ss << 5 << " eh inteiro";
    //ss.str() será "5 eh inteiro"
    stringstream ss;
    ss << "[ ";
    if(vector->size > 0) {
        for(int i=0; i<vector->size; i++) {
            ss << vector->data[i] << " ";
        }
    }
    ss << "]";
    return ss.str();
}


/* NAO MEXA DAQUI PRA BAIXO */
int main() {
    string line, cmd;
    int value;
    Vector * v = vector_create(0);
    while(true) {
        getline(cin, line);
        cout << "$" << line << endl;
        stringstream ss(line);
        ss >> cmd;
        if(cmd == "end"){
            break;
        } else if(cmd == "init") {
            ss >> value;
            if(v != nullptr)
                vector_destroy(v);
            v = vector_create(value);
        } else if(cmd == "status") {
            cout << "size:" << v->size << " capacity:" << v->capacity << "\n";
        } else if(cmd == "add") {
            while(ss >> value)
                vector_add(v, value);
        } else if(cmd == "show") {
            cout << vector_show(v) << endl;
        } else {
            cout << "fail: comando invalido\n";
        }
    }
    vector_destroy(v);
}