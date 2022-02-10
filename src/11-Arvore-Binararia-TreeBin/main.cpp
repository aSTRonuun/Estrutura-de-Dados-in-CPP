#include <iostream>
#include <string>
#include "Tree.h"
using namespace std;

int main() {

	string line;
    getline(cin, line);
    Tree bt(line);
    int n;
    cin >> n;
    cout << bt.node_depth(n) << endl;
	return 0;
}