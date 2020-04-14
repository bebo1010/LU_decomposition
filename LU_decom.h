#include <cstdio>
#include <cmath>
#include <iomanip>
#include <fstream>
#include <algorithm>
using namespace std;
class LU_decom{
	public:
		void LU(ifstream &inFile , ofstream &outFile);
		
	private:
		void P_LU(ifstream &inFile , ofstream &outFile , int row_i , int col_j);
		int row;
		int col;
		int mat[10][10]; //row col
		double L[10][10]; //row row
		double U[10][10]; //row col
		int P[10][10]; // row row
		bool FLAG; //check if P_LU has been executed
};

