#include <iostream>
#include <vector>

using namespace std;

void right_rotation(vector<int> &array, int nrotations) {
    for(int i=0; i<nrotations; i++) {
        int aux = array[array.size()-1];
        for(int i=array.size()-1; i>0; i--) {
            array[i] = array[i-1];
        }
        array[0] = aux;
    }
}

void show(vector<int> &v) {
    cout << "[ ";
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << "]" << endl;
}

int main() {

    int size, nrotation;

    cin >> size >> nrotation;

    vector<int> array(size);

    for(int i=0; i<size; i++) {
        cin >> array[i];
    }

    right_rotation(array, nrotation);

    show(array);
}