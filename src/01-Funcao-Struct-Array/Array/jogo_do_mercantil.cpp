#include <iostream>

using namespace std;

string disputa(int size, float productos[], float first_answers[], char second_answers[]){
    
    int f_points = 0, s_points = 0;

    for(int i=0; i<size; i++){
        if(productos[i] == first_answers[i]){
            f_points++;
        }else if(first_answers[i] > productos[i] && second_answers[i] == 'M'){
            f_points++;
        }else if(first_answers[i] < productos[i] && second_answers[i] == 'm'){
            f_points++;
        }else{
            s_points++;
        }
    }

    if(f_points > s_points) return "primeiro";
    else if(f_points < s_points) return "segundo";
    else return "empate";
}

int main() {

    int size;
    cin >> size;

    float productors[size];
    float first_answers[size];
    char second_answers[size];

    for(int i=0; i<size; i++) {
        cin >> productors[i];
    }

    for(int i=0; i<size; i++) {
        cin >> first_answers[i];
    }

    for(int i=0; i<size; i++) {
        cin >> second_answers[i];
    }

    cout << disputa(size, productors, first_answers, second_answers);

    return 0;
}