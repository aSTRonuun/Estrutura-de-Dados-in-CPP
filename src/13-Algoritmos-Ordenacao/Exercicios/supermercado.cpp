#include <iostream>
#include <vector>
using namespace std;

class Product {
    public:
        string name;
        int price;

    public:
    Product(string n, int p) {
        name = n;
        price = p;
    }

    bool operator<(const Product & a){
        if( price != a.price){
            return price < a.price;
        }else{
            return name < a.name;
        }
    }
    friend ostream& operator<<(ostream& os, const Product& p);
};

ostream& operator<<(ostream& os, const Product& p){
    os << "(" << p.name << "," << p.price << ")";
    return os;
}

void selectionSort(Product A[], int n) {
    int trocas = 0;
    for(int i=0; i<n-1; i++) {
        int min = i;
        for(int j=i+1; j<n; j++) {
            if(A[j] < A[min]){
                min = j;
            }
        }
        Product aux = A[i];
        A[i] = A[min];
        A[min] = aux;
    }
}

int main() {

    int qtd_pratileira1, qtd_pratileira2, qtd_prod1, qtd_prod2;

    cin >> qtd_pratileira1 >> qtd_pratileira2 >> qtd_prod1 >> qtd_prod2;
    int produtos_total = qtd_prod1 + qtd_prod2;

    vector<Product> produtos_pratileira1;
    vector<Product> produtos_pratileira2;
    vector<Product> produtos_pegos;

    for(int i=0; i<qtd_pratileira1; i++) {
        string name;
        int price;
        cin >> name >> price;
        produtos_pratileira1.push_back(Product(name, price));
    }

    for(int i=0; i<qtd_pratileira2; i++) {
        string name;
        int price;
        cin >> name >> price;
        produtos_pratileira2.push_back(Product(name, price));
    }

    selectionSort(produtos_pratileira1.data(), qtd_pratileira1);
    selectionSort(produtos_pratileira2.data(), qtd_pratileira2);

    for(int i=0; i<qtd_prod1; i++) {
        produtos_pegos.push_back(produtos_pratileira1[i]);
    }

    for(int i=0; i<qtd_prod2; i++) {
        produtos_pegos.push_back(produtos_pratileira2[i]);
    }

    selectionSort(produtos_pegos.data(), produtos_pegos.size());

    for(int i=0; i<produtos_total; i++) {
        cout << produtos_pegos[i].name <<  " ";
    }
    

    return 0;
}



