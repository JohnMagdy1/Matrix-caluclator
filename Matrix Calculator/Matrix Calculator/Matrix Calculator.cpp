#include <iostream>
#include <math.h>
#include <cstdlib>
#include <stdio.h>
using namespace std;

// function to Output the matrix in a proper form
void Prt_mtr(float MatrixName[10][10], int MatRows, int MatCols) {
	for (int i = 0; i < MatRows; i++) {
		for (int j = 0; j < MatCols; j++) { /*cout << "\t" << MatrixName[i][j];*/printf("\t %.2f", MatrixName[i][j]); }
		cout << endl;
	}
}

// function to generate the matrix inverse
void Inv_Matrix(float MatrixName[10][10], int MatRows, float MatrixInverse_Output[10][10]) {
	float MatrixInverse[10][10] = {};
	for (int i = 0; i < MatRows; i++) {
		for (int j = 0; j < MatRows; j++) { MatrixInverse[i][j] = MatrixName[i][j]; }
	}
	int i, j, k;
	float t;
	for (i = 0; i < MatRows; i++)
	{
		for (j = MatRows; j < 2 * MatRows; j++)
		{
			if (i == j - MatRows)
				MatrixInverse[i][j] = 1;
			else
				MatrixInverse[i][j] = 0;
		}
	}
	for (i = 0; i < MatRows; i++)
	{
		t = MatrixInverse[i][i];
		for (j = i; j < 2 * MatRows; j++)
			MatrixInverse[i][j] = MatrixInverse[i][j] / t;
		for (j = 0; j < MatRows; j++)
		{
			if (i != j)
			{
				t = MatrixInverse[j][i];
				for (k = 0; k < 2 * MatRows; k++)
					MatrixInverse[j][k] = MatrixInverse[j][k] - t * MatrixInverse[i][k];
			}
		}
	}
	for (int i = 0; i < MatRows; i++) {
		for (int j = MatRows; j < 2 * MatRows; j++) { MatrixInverse_Output[i][j - MatRows] = MatrixInverse[i][j]; }
		cout << endl;
	}
}

// function to create a new matrix
void Gen_Mtx(float MatrixName[10][10], string MatLabel, char MatChar, int MatRows, int MatCols) {

	cout << endl << "Please enter the Elements of matrix " << MatLabel << endl;
	for (int i = 0; i < MatRows; ++i)
		for (int j = 0; j < MatCols; ++j)
		{
			cout << "Enter element " << MatChar << i + 1 << j + 1 << " : ";
			cin >> MatrixName[i][j];
		}
	cout << MatLabel << " is saved successfully\n" << endl;

}

// function to calculate the determinant of any square matrix
float determinant(float matrix[10][10], float Order) {
	float det = {};
	float submatrix[10][10];
	if (Order == 2)
		return ((matrix[0][0] * matrix[1][1]) - (matrix[1][0] * matrix[0][1]));
	else {
		for (int x = 0; x < Order; x++) {
			int subi = 0;
			for (int i = 1; i < Order; i++) {
				int subj = 0;
				for (int j = 0; j < Order; j++) {
					if (j == x)
						continue;
					submatrix[subi][subj] = matrix[i][j];
					subj++;
				}
				subi++;
			}
			det = det + (pow(-1, x) * matrix[0][x] * determinant(submatrix, Order - 1));
		}
	}

	return det;
}

// functions to Output certain lines to the user
void Main_Operations_List() {
	cout << "\nPlease choose one of the following operations" << endl;
	cout << "---------------------------------------------\n" << endl;
	cout << "1- Add/Edit Matrix" << endl;
	cout << "2- View Matrix" << endl;
	cout << "3- Matrix Determinant" << endl;
	cout << "4- Matrix Addition" << endl;
	cout << "5- Matrix Subtraction" << endl;
	cout << "6- Matrix Multiplication" << endl;
	cout << "7- Matrix Transpose" << endl;
	cout << "8- Matrix Inverse" << endl;
	cout << "9- Matrix Division" << endl;
	cout << "10- Quit the program \n" << endl;
	cout << "You Entered --> ";
}
void Scd_Swtich(string String) {
	cout << "Please choose one of the following operations" << endl;
	cout << "---------------------------------------------" << endl;
	cout << "1- " << String << " A" << endl;
	cout << "2- " << String << " B\n" << endl;
	cout << "Your choice --> ";
}
void End_Switch() {
	system("pause");
	system("CLS");
}


int main() {

	//Initializing the Matrices
	float MatrixA[10][10] = {}, MatrixB[10][10] = {}, AdditonMat[10][10] = {}, SubstractionMat[10][10] = {}, MultiplicationMat[10][10] = {};
	float InverseA[10][10] = {}, InverseB[10][10] = {}, TranA[10][10] = {}, TranB[10][10] = {};
	char Quit_char = {}, Quit_check = {};
	int r1 = {}, c1 = {}, r2 = {}, c2 = {};

	while (Quit_char != 'q') {

		cout << "                                        Welcome to the Matrix Calculator\n" << endl;
		Main_Operations_List();

		int Main_Choice, Add_Matrix_Choice, View_Matrix_Choice, View_Determinant_Choice, Transpose_Matrix_Choice, Inverse_Matrix_Choice;
		cin >> Main_Choice;

		switch (Main_Choice) {

		case 1:
			Scd_Swtich("Edit Matrix");
			cin >> Add_Matrix_Choice;
			switch (Add_Matrix_Choice) {
			case 1:
				cout << "Please enter Number of rows and columns for MatA: " << endl;
				cout << "Number of rows =>> ";
				cin >> r1;
				cout << "Number of Columns =>> ";
				cin >> c1;
				Gen_Mtx(MatrixA, "MatA", 'A', r1, c1);
				break;

			case 2:
				cout << "Please enter Number of rows and columns for MatB: " << endl;
				cout << "Number of rows =>> ";
				cin >> r2;
				cout << "Number of Columns =>> ";
				cin >> c2;
				Gen_Mtx(MatrixB, "MatB", 'B', r2, c2);
				break;

			default:
				cout << "\nInvalid answer! \n" << endl;
			}

			/* Calculating The Mathematical Expressions on the Matrix */

			for (int i = 0; i < r2; i++) { for (int j = 0; j < c2; j++) { TranB[j][i] = MatrixB[i][j]; } }
			for (int i = 0; i < r1; i++) {
				for (int j = 0; j < c1; j++) {
					AdditonMat[i][j] = MatrixA[i][j] + MatrixB[i][j];
					SubstractionMat[i][j] = MatrixA[i][j] - MatrixB[i][j];
					TranA[j][i] = MatrixA[i][j];
				}
			}
			for (int i = 0; i < r1; i++) {
				for (int j = 0; j < c2; j++) {
					for (int k = 0; k < 10; k++) { MultiplicationMat[i][j] += MatrixA[i][k] * MatrixB[k][j]; }
				}
			}

			/* Calculating The Mathematical Expressions on the Matrix */

			End_Switch();
			break;

		case 2:
			Scd_Swtich("View Matrix");
			cin >> View_Matrix_Choice;
			switch (View_Matrix_Choice) {

			case 1:
				cout << "\nViewing Matrix A..." << endl;
				Prt_mtr(MatrixA, r1, c1);
				break;

			case 2:
				cout << "\nViewing Matrix B..." << endl;
				Prt_mtr(MatrixB, r2, c2);
				break;

			default:
				cout << "\nInvalid answer! \n" << endl;
			}
			End_Switch();
			break;

		case 3:
			Scd_Swtich("Calculate Determinant");
			cin >> View_Determinant_Choice;
			switch (View_Determinant_Choice) {

			case 1:
				if (r1 == c1) { cout << "\nDeterminant of Matrix A = " << determinant(MatrixA, r1) << endl; }
				else { cout << "Error : Matrix A isn't a Square Matrix\n" << endl; }
				break;

			case 2:
				if (r2 == c2) { cout << "\nDeterminant of Matrix B = " << determinant(MatrixB, r2) << endl; }
				else { cout << "Error : Matrix B isn't a Square Matrix\n" << endl; }
				break;

			default:
				cout << "\nInvalid answer! \n" << endl;
			}
			End_Switch();
			break;

		case 4:
			if (r1 != r2 || c1 != c2) { cout << "Error : The Matrices aren't of the same size\n" << endl; }
			else { cout << "\nViewing the addition matrix (MatA + MatB)... " << endl; Prt_mtr(AdditonMat, r1, c1); }
			End_Switch();
			break;

		case 5:
			if (r1 != r2 || c1 != c2) { cout << "Error : The Matrices aren't of the same size\n" << endl; }
			else { cout << "\nViewing the Subtraction matrix (MatA - MatB)... " << endl; Prt_mtr(SubstractionMat, r1, c1); }
			End_Switch();
			break;

		case 6:
			if (c1 != r2) { cout << "Error : c1 isn't equal to r2\n" << endl; }
			else { cout << "\nViewing the multiplication matrix (MatA * MatB)... " << endl; Prt_mtr(MultiplicationMat, r1, c2); }
			End_Switch();
			break;

		case 7:
			Scd_Swtich("View Transpose Matrix");
			cin >> Transpose_Matrix_Choice;
			switch (Transpose_Matrix_Choice) {

			case 1:
				cout << "\nViewing the Transpose of matrix Tran(MatA)... " << endl;
				Prt_mtr(TranA, c1, r1);
				break;

			case 2:
				cout << "\nViewing the Transpose of matrix Tran(MatB)...  " << endl;
				Prt_mtr(TranB, c2, r2);
				break;

			default:
				cout << "\nInvalid answer!\n" << endl;

			}
			End_Switch();
			break;

		case 8:
			Scd_Swtich("View Inverse Matrix");
			cin >> Inverse_Matrix_Choice;
			switch (Inverse_Matrix_Choice) {

			case 1:
				if (r1 != c1) { cout << "\nMatrix A isn't a square Matrix" << endl; }
				else if (determinant(MatrixA, r1) == 0) { cout << "\nMatrix A is a singular Matrix" << endl; }
				else {
					cout << "\nViewing the Inverse of matrix Inv(MatA)... " << endl;
					Inv_Matrix(MatrixA, r1, InverseA);
					Prt_mtr(InverseA, r1, c1);
				}
				break;

			case 2:
				if (r2 != c2) { cout << "\nMatrix B isn't a square Matrix" << endl; }
				else if (determinant(MatrixB, r2) == 0) { cout << "\nMatrix B is a singular Matrix" << endl; }
				else {
					cout << "\nViewing the Inverse of matrix Inv(MatB)... " << endl;
					Inv_Matrix(MatrixB, r2, InverseB);
					Prt_mtr(InverseB, r2, c2);
				}
				break;

			default:
				cout << "\nInvalid answer!\n" << endl;
			}
			End_Switch();
			break;

		case 9:
			if (r2 != c2) { cout << "\nMatrix B isn't a square Matrix" << endl; }
			else if (determinant(MatrixB, r2) == 0) { cout << "\nMatrix B is a singular Matrix" << endl; }
			else if (c1 != r2) { cout << "Error : The Matrices aren't of the same size\n" << endl; }
			else {
				float Division[10][10] = {};
				Inv_Matrix(MatrixB, r2, InverseB);
				for (int i = 0; i < r1; i++) {
					for (int j = 0; j < c2; j++) {
						for (int k = 0; k < 10; k++) { Division[i][j] += MatrixA[i][k] * InverseB[k][j]; }
					}
				}
				cout << "Matrix A divided by Matrix B (MatA * Inv(MatB))" << endl;
				Prt_mtr(Division, r1, c2);
			}
			End_Switch();
			break;

		case 10:
			cout << "Are you sure you want to exit ? y/n \n";
			cout << "You Entered --> ";
			cin >> Quit_check;
			if (Quit_check == 'y') { Quit_char = 'q'; }
			else { End_Switch(); }
			break;

		default:
			cout << "\nInvalid answer! \n" << endl;

		}
	}
	cout << "\nQuitting the program..." << endl;
}
