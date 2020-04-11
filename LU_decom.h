#include <fstream>
class LU_decom{
	public:
		void LU_decom(ifstream &inFile , ofstream &outFile);
		
	private:
		void P_LU(ofstream &outFile);
		short int row;
		short int col;
		int mat[row][col];
		double L[row][row];
		double U[row][col];
		int P[row][col];
};

