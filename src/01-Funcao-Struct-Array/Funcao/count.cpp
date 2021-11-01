#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int main() {
    
    vector<int> numbers;

    numbers.push_back(1);
    numbers.push_back(2);
    numbers.push_back(3);
    numbers.push_back(3);
    numbers.push_back(5);

    for(auto i =0; i<numbers.size(); i++){

        // cout << numbers[i];

        int counnt = count(numbers.begin(), numbers.end(), numbers[i]);

        if(counnt > 1)
            cout << numbers[i] << " ";
    }
}