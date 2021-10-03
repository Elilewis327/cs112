/* Matrix.cpp defines Matrix class methods.
 * Student Names: Eli Lewis, Jay Carlson
 * Date: 09/28/21
 * Begun by: Joel Adams, for CS 112 at Calvin University.
 */

#include "Matrix.h"

Matrix::Matrix(){
	myRows = myColumns = 0;
}

Matrix::Matrix(unsigned rows, unsigned columns){
	myRows = rows;
	myColumns = columns;
	myVec.setSize(rows);
	for (unsigned i = 0; i < rows; i++) {
		myVec[i].setSize(columns);
	}
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




