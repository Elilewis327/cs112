//============================================================================
// Name        : findDot.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
using namespace std;

int findDot(const vector<char> &charvec) const{
	unsigned i = 0;
	while (charvec[i] != ‘.’){
	if (charvec.size() < i){return -1;}
	i++;
	}
return i;
}


int main() {
	vector<char> charvec(10);
	charvec[0] = 'a';
	charvec[1] = 's';
	charvec[2] = 'f';
	charvec[3] = '.';
	cout << findDot(charvec);
	return 0;
}
