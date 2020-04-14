#include "LU_decom.h"

void LU_decom::LU(ifstream &inFile , ofstream &outFile){
	FLAG = false; //initialize FLAG
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

	LU_decomp();

	if(FLAG == false){ //no P_LU() was executed

		outFile << "True" << endl;

		outFile << row << " " << row << endl; //print L
		for(int i = 0 ; i < row ; i++){
			for(int j = 0 ; j < row ; j++){
				double roundoff = (round(L[i][j] * 100.0) / 100.0);
				outFile << left << setprecision(2) << setw(5) << fixed<< roundoff;
				if(j != (row - 1))
					outFile << " ";
			}
			outFile << endl;
		}

		outFile << row << " " << col << endl; //print U
		for(int i = 0 ; i < row ; i++){
			for(int j = 0 ; j < col ; j++){
				double roundoff = (round(U[i][j] * 100.0) / 100.0);
				outFile << setprecision(2) << setw(5) << roundoff;
				if(j != (col - 1))
					outFile << " ";
			}
			outFile << endl;
		}

	}

	else{ //P_LU() was executed at lease once

		outFile << "False" << endl;

		outFile << row << " " << row << endl; //print P
		for(int i = 0 ; i < row ; i++){
			for(int j = 0 ; j < row ; j++){
				outFile << setprecision(2) << fixed <<setw(5) << P[i][j];
				if(j != (row - 1))
					outFile << " ";
			}
			outFile << endl;
		}

		outFile << row << " " << row << endl; //print L
		for(int i = 0 ; i < row ; i++){
			for(int j = 0 ; j < row ; j++){
				double roundoff = (round(L[i][j] * 100.0) / 100.0);
				outFile << setprecision(2) << setw(5) << roundoff;
				if(j != (row - 1))
					outFile << " ";
			}
			outFile << endl;
		}

		outFile << row << " " << col << endl; //print U
		for(int i = 0 ; i < row ; i++){
			for(int j = 0 ; j < col ; j++){
				double roundoff = (round(U[i][j] * 100.0) / 100.0);
				outFile << setprecision(2) << setw(5) << roundoff;
				if(j != (col - 1))
					outFile << " ";
			}
			outFile << endl;
		}

	}
	return;
}

void LU_decom::LU_decomp(){
	if(FLAG == true){ //initialize L and U again , but with row exchange
		for(int i = 0 ; i < row ; i++){
			for(int j = 0 ; j < col ; j++){
				U[i][j] = static_cast<double>(mat[i][j]);
				L[i][j] = 0;
			}
		}
	
		for(int i = 0 ; i < row ; i++)
			L[i][i] = 1; //initialize L to indentity matrix
		bool flag[row][col] = {false};
		for(int i = 0 ; i < row ; i++){ //perform row exchange
			for(int j = 0 ; j < col ; j++){
				if(P[i][j] != 0 && i != j && flag[i][j] == false && flag[j][i] == false){ //if row exchange is necessary
					flag[i][j] = true;
					flag[j][i] = true;
					for(int k = 0 ; k < col ; k++)
						swap(U[j][k],U[i][k]);
				}
			}
		}
	}
	for(int i = 1 ; i < row ; i++){ //body of LU decomposition
		for(int j = 0 ; j < col ; j++){
			if(U[j][j] == 0){ //to prevent something divided by 0
				P_LU(i , j);
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
	return;
}

void LU_decom::P_LU(int row_i , int col_j){
	FLAG = true;
	for(int j = 0 ; j < col ; j++){
		bool flag = true; //check if the elements in a row is all 0
		if(U[row_i][j] != 0)
			flag = false;
		if(flag == true){
			for(int k = 0 ; k < col ; k++){ //exchange row
				swap(P[row-1][k] , P[row_i][k]);
				swap(U[row-1][k] , U[row_i][k]); //swap to last row
			}
			LU_decomp();
			return;
		}
	} 

	for(int i = 0 ; i < row && i > row_i ; i++){
		if(U[i][col_j] != 0){
			for(int j = 0 ; j < col ; j++){ //exchange row
				swap(P[i][j] , P[row_i][j]);
				swap(U[i][j] , U[row_i][j]);
			}
			LU_decomp();
			return;
		}
	}

	return;
}
