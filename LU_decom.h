#include <fstream>
class LU_decom(){
	public:
		LU_decom(ifstream &inFile);

	private:
		int row;
		int col;
		int mat[][];
		int L[][];
		int U[][];
		int P[][];
}

