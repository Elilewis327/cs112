/* Matrix.cpp defines Matrix class methods.
 * Student Names: Eli Lewis, Jay Carlson
 * Date: 09/28/21
 * Begun by: Joel Adams, for CS 112 at Calvin University.
 */

#include "Matrix.h"

Matrix::Matrix(){
	myRows = myColumns = 0;
}

void Matrix::reSize(unsigned rows, unsigned columns) {
	myRows = rows;
	myColumns = columns;
	myVec.setSize(rows);
	for (unsigned i = 0; i < rows; i++) {
		myVec[i].setSize(columns);
	}
}

Matrix::Matrix(unsigned rows, unsigned columns){
	reSize(rows, columns);
}

bool Matrix::operator==(const Matrix& m2) const {
	if ( myRows != m2.getRows() || myColumns != m2.getColumns() ) {
		return false;
	} else {
		return myVec == m2.myVec;
	}
}

Vec<Item>& Matrix::operator[](unsigned index) {
	if (index >= myRows) throw range_error("Subscript: Index out of range");
	return myVec[index];
}

const Vec<Item>& Matrix::operator[](unsigned index) const{
	if (index >= myRows) throw range_error("Subscript: Index out of range");
	return myVec[index];
}

void Matrix::readFrom(istream &in){
	for(unsigned i = 0; i < myRows; ++i){
		for (unsigned j = 0; j < myColumns; ++j){
			in >> myVec[i][j];
		}
	}
}

void Matrix::readFrom(string in){
	ifstream fin(in.c_str());
	assert( fin.is_open() );
	unsigned rows, columns;
	fin >> rows >> columns;
	this->reSize(rows, columns); //i love me some arrows
	this->readFrom(fin);
	fin.close();
}

// makes all the columns rows and the rows columns
Matrix& Matrix::getTranspose(){
	Matrix* tmp = new Matrix(myColumns, myRows); //have to use new otherwise hanging pointer

	cout << endl;

	for (unsigned i = 0; i < myRows; ++i){
		cout << endl;
		for(unsigned j = 0; j < myColumns; ++j){
			cout << myVec[i][j] << ' ' << flush;
		}
	}

	cout << endl;

	cout << tmp->myColumns << ' ' << tmp->myRows << ' ' << myColumns << ' ' << myRows << endl;

	cout << endl;

	for (unsigned i = 0; i < myColumns; ++i){
			cout << endl;
			for(unsigned j = 0; j < myRows; ++j){
				cout << myVec[j][i] << ' ' << flush;
				tmp[i][j] = myVec[j][i];

			}
		}

	cout << endl;


	return *tmp;

}



