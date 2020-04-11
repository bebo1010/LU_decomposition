#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

#include "LU_decom.h"
int main(){
	ifstream inFile("input.txt",ios::in);
	if(!inFile){
		cout << "Failed opening input.txt" << endl;
		exit(1);
	}
	ofstream outFile("output.txt",ios::out);
	if(!outFile){
		cout << "Failed opening output.txt" << endl;
		exit(1);
	}

	short int loops = 0;
	inFile >> loops;
	while(loops >= 0){
		LU_decom(inFile , outFile);
		loops--;
	}
	return 0;
}
