#include "LU_decom.h"

void LU_decom::LU(ifstream &inFile , ofstream &outFile){
	for(int i = 0 ; i < 10 ; i++){ //initialize all elements in matrices to 0
		for(int j = 0 ; j < 10 ; j++){
			mat[i][j] = 0;
			L[i][j] = 0;
			U[i][j] = 0;
			P[i][j] = 0;
		}
	}

	inFile >> row >> col;
	for(int i = 0 ; i < row ; i++){
		for(int j = 0 ; j < col ; j++){
			inFile >> mat[i][j]; //input the matrix data
			U[i][j] = static_cast<double>(mat[i][j]);
		}
	}
	
	for(int i = 0 ; i < row ; i++)
		L[i][i] = 1; //initialize L to indentity matrix 
	for(int i = 0 ; i < row && i < col ; i++)
		P[i][i] = 1; //initialize P to indentity matrix

	for(int i = 1 ; i < row ; i++){ //body of LU decomposition
		for(int j = 0 ; j < col ; j++){
			if(mat[i-1][j] == 0){
				outFile << "False" << endl;
				P_LU(outFile , 0); //not possible to do A=LU
				return;
			}
			if(L[i][j] != 0)
				continue;
			double temp = (mat[i][j] / mat[i-1][j]);
			L[i][j] = temp;
			for(int k = 0 ; k < col ; k++)
				U[i][k] = (U[j][k] + (U[j][k] * temp) );
		}
	}

	short int pivot_count = 0;
	for(int i = 0 ; i < row  && i < col ; i++){ //check pivots
			if(U[i][i] != 0)
				pivot_count++;
	}
	bool compare;
	if(row < col)
		compare = 0;
	else
		compare = 1;
	if(compare == 0 && pivot_count < row){
		outFile << "False" << endl;
		P_LU(outFile , 1); //not enough pivots
		return;
	}
	else if(compare == 1 && pivot_count < col){
		outFile << "False" << endl;
		P_LU(outFile , 2);
		return;
	}
	
	outFile << "True" << endl;
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
	return;
}

void LU_decom::P_LU(ofstream &outFile , int mode){
	return;
}
