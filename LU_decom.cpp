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
			if(U[j][j] == 0){ //to prevent something divided by 0
				P_LU(outFile , 0 , j);
				return;
			}
			if(L[i][j] != 0)
				goto LOOP_END;
			double temp = U[i][j] / U[j][j]; 
			L[i][j] = temp;
			for(int k = 0 ; k < col ; k++) //do row calculation
				U[i][k] = U[i][k] - temp * U[j][k];
		}
		LOOP_END:;
	}

	outFile << "True\n";
	outFile << row << " " << row << endl; //print L
	for(int i = 0 ; i < row ; i++){
		for(int j = 0 ; j < row ; j++){
			double roundoff = (round(L[i][j] * 100.0) / 100.0);
			outFile << setprecision(2) << roundoff;
			if(j != (row - 1))
				outFile << " ";
		}
		outFile << "\n";
	}
	outFile << row << " " << col << endl; //print U
	for(int i = 0 ; i < row ; i++){
		for(int j = 0 ; j < col ; j++){
			double roundoff = (round(U[i][j] * 100.0) / 100.0);
			outFile << setprecision(2) << roundoff;
			if(j != (col - 1))
				outFile << " ";
		}
		outFile << "\n";
	}
	return;
}

void LU_decom::P_LU(ofstream &outFile , int mode , int pos){
	outFile << "False\n";
	return;
}
