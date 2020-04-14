#include <cstdio>
#include <cmath>
#include <iomanip>
#include <fstream>
using namespace std;
class LU_decom{
	public:
		void LU(ifstream &inFile , ofstream &outFile);
		
	private:
		void P_LU(ofstream &outFile , int mode , int pos);
		int row;
		int col;
		int mat[10][10]; //row col
		double L[10][10]; //row row
		double U[10][10]; //row col
		int P[10][10]; // row col
};

