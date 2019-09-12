#define SIZE 10
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <chrono>
#include <thread>
using namespace std;
typedef int Matrix[SIZE][SIZE];

void header();
void populateMatrix(Matrix matrix);
void extractColumn(const Matrix matrix, int column[], int column_number);
void showMeTheMatrix(const Matrix matrix);
void printCol(const int column[]);
void printCol(const Matrix matrix, int column_number);
void computeStats(const int column[], double & mean, double & variance, double & stDev);
double myMeanFx(const int column[]);
double myVarFx(const int column[]);
double myStDevFx(const int column[]);

int main(){
	Matrix myMatrix;
	int extract[SIZE];
	double myMean, myVariance, myStDev;
	
	header();
	populateMatrix(myMatrix);
	showMeTheMatrix(myMatrix);
	extractColumn(myMatrix, extract, 1);
	printCol(myMatrix, 1);
	computeStats(extract, myMean, myVariance, myStDev);
	cout << "Mean: " << myMean << '\n';
	cout << "Variance: " << myVariance << '\n';
	cout << "Standard Deviation: " << myStDev << '\n';
	
	return 0;
}

/* header
 * Desc: Prints a header for the program
 */
 void header(){
	cout << "\033[36;1m"
        << "╔══════════════════════════════════════╗\n"
        << "║        Matrix Display System         ║\n"
        << "╚══════════════════════════════════════╝\n\033[0m";
	return;
 }
/* populateMatrix
 * Desc: Generates random values in a matrix
 */
void populateMatrix(Matrix matrix){
	srand(time(NULL));
	for(int r = 0; r < SIZE; r++){
		for(int c = 0; c < SIZE; c++){
			matrix[r][c] = rand() % 10;
		}
	}
	return;
}
/* extractColumn
 * Desc: Takes a column from a matrix and stores it in an array
 */
void extractColumn(const Matrix matrix, int column[], int column_number){
	for(int r = 0; r < SIZE; r++){
		column[r] = matrix[r][column_number];
	}
	return;
}
/* showMeTheMatrix
 * Desc: Prints a matrix to the console
 */
void showMeTheMatrix(const Matrix matrix){
	cout << "\033[36;1mgenerating matrix...\n\033[0m";
	for(int r = 0; r < SIZE; r++){
		for(int c = 0; c < SIZE; c++){
			if(c % 2)
				cout << "\033[32m";
			else
				cout << "\033[36m";
			this_thread::sleep_for(chrono::milliseconds(10));
			cout << matrix[r][c] << ' ' << flush;
		}
		cout << endl;
	}
	cout << "\033[36;1mdone!\n\033[0m";
	return;
}
/* printCol
 * Desc: Prints a column to the console
 */
void printCol(const int column[]){
	for(int r = 0; r < SIZE; r++){
		cout << column[r] << '\n';
	}
	return;
}
void printCol(const Matrix matrix, int column_number){
	int column[SIZE];
	cout << "\033[36;1mextracting column (id:" << column_number << ")...\n\033[0m";
	extractColumn(matrix, column, column_number);
	if(column_number % 2)
		cout << "\033[32m";
	else
		cout << "\033[36m";
	for(int r = 0; r < SIZE; r++){
		this_thread::sleep_for(chrono::milliseconds(200));
		cout << column[r] << endl;
	}
	cout << "\033[36;1mdone!\033[0m" << endl;
	return;
}
/* computeStats
 * Desc: Computes and prints all the statistics associated with a column
 */
void computeStats(const int column[], double & mean, double & variance, double & stDev){
	cout << "\033[36;1mcomputing[         ]\r";
	string comp = "[         ]";
	for(int i = 1; i < comp.length() - 1; i += 3){
		comp.replace(i, 1, "▉");
		this_thread::sleep_for(chrono::milliseconds(200));
		cout << "\033[36;1mcomputing" << comp << "\033[0m";
		if(comp.length() == 17){
			mean = myMeanFx(column);
		}else if(comp.length() == 23){
			variance = myVarFx(column);
		}else if(comp.length() == 29){
			stDev = myStDevFx(column);
		}
		if(comp.length() >= 29){
			cout << " mean \033[32m☑\033[0m variance \033[32m☑\033[0m standard deviation \033[32m☑\033[0m";
			cout  << '\r' << flush;
		}else if(comp.length() >= 23){
			cout << " mean \033[32m☑\033[0m variance \033[32m☑\033[0m standard deviation \033[31m☐\033[0m";
			cout  << '\r' << flush;
		}else if(comp.length() >= 17){
			cout << " mean \033[32m☑\033[0m variance \033[31m☐\033[0m standard deviation \033[31m☐\033[0m";
			cout  << '\r' << flush;
		}else{
			cout << " mean \033[31m☐\033[0m variance \033[31m☐\033[0m standard deviation \033[31m☐\033[0m";
			cout  << '\r' << flush;
		}
	}
	cout << endl << "\033[36;1mdone!\033[0m" << endl;
	return;
}
/* myMeanFx
 * Desc: Computes and returns mean of values in a column
 */
double myMeanFx(const int column[]){
	double mean = 0;
	for(int i = 0; i < SIZE; i++){
		mean += column[i];
	}
	mean /= SIZE;
	return mean;
}
/* myVarFx
 * Desc: Computes and returns variance of values in a column
 */
double myVarFx(const int column[]){
	double variance = 0;
	double mean = myMeanFx(column);
	for(int i = 0; i < SIZE; i++){
		double term = column[i] - mean;
		term *= term;
		variance += term;
	}
	variance /= SIZE - 1;
	return variance;
}
/* myStDevFx
 * Desc: Computes and returns standard deviation of values in a column
 */
double myStDevFx(const int column[]){
	return sqrt(myVarFx(column));
}
