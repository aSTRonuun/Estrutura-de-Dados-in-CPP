#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Funcao para receber as strings
void recive_input(vector<string> &vector, int n) {
    string input;
    for (int i = 0; i < n; i++) {
        cin >> input;
        vector.push_back(input);
    }
}

void print_vector(vector<int> vector) {
    for (int i = 0; i < vector.size(); i++) {
        cout << vector[i] <<  " ";
    }
}

vector<int> matching_strings(vector<string> &pesquise, vector<string> &consult) {
    vector<int> result;
    for( int i=0; i<consult.size(); i++) {
        int count = 0;
        for( int j=0; j<pesquise.size(); j++) {
            if(pesquise[j] == consult[i]) {
                count++;
            }
        }
        result.push_back(count);
    }
    return result;
}

int main() {
    
    vector<string> strings;
    vector<string> strings_consult;
    vector<int> result;

    int qtd_strings, qtd_strings_consult;
    cin >> qtd_strings;

    recive_input(strings, qtd_strings);

    cin >> qtd_strings_consult;

    recive_input(strings_consult, qtd_strings_consult);

    result = matching_strings(strings, strings_consult);

    print_vector(result);
}