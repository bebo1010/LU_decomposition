#include "LU_decom.h"

void LU_decom::LU_decom(ifstream &inFile , ofstream &outFile){
	inFile >> row >> col;
	for(int i = 0 ; i < row , i++){
		for(int j = 0 ; j < col ; j++){
			inFile >> mat[i][j]; //input the matrix data
			U[i][j] = static_cast<double>(mat[i][j]);
		}
	}
	
	for(int i = 0 ; i < row ; i++)
		L[i][i] = 1; //initialize L to indentity matrix 

	for(int i = 1 ; i < row ; i++){
		for(int j = 0 ; j < col ; j++){
			if(L[i][j] != 0)
				continue;
			double temp = (mat[i][j] / mat[i-1][j]);
			L[i][j] = temp;
			for(int k = 0 ; k < col ; k++)
				U[i][k] = (U[j][k] + (U[j][k] * temp) );
		}
	}
	outFile << row << ' ' << row << '\n'; //print L
	for(int i = 0 ; i < row ; i++){
		for(int j = 0 ; j < row ; j++){
			outFile << L[i][j];
			if(j != (row - 1))
				outFile << ' ';
		}
		outFile << '\n';
	}
	outFile << row << ' ' << col << '\n'; //print U
	for(int i = 0 ; i < row ; i++){
		for(int j = 0 ; j < col ; j++){
			outFile << U[i][j];
			if(j != (col - 1))
				outFile << ' ';
		}
		outFile << '\n';
	}
	return 0;
}

void LU_decom::P_LU(ofstream &outFile){
	return 0;
}
