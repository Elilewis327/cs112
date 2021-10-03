/* Matrix.h provides a class for manipulating 2-dimensional vectors.
 * Student Name: Eli Lewis, and Jay Carlson
 * Date: 09/28/21
 * Begun by: Joel Adams, for CS 112 at Calvin University.
 */

#ifndef MATRIX
#define MATRIX

#include "Vec.h"

typedef double Item;

class Matrix {
	public:
		Matrix();
		Matrix(unsigned rows, unsigned columns);
		unsigned getColumns() const {return myColumns;}
		unsigned getRows() const {return myRows;}
		bool operator==(const Matrix& m2) const;
		Vec<Item>& operator[](unsigned index);
		const Vec<Item>& operator[](unsigned index) const;

	private:
		Vec< Vec<Item> > myVec;
		unsigned myRows;
		unsigned myColumns;

		friend class MatrixTester;
};

#endif