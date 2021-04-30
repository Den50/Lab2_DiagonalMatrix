#pragma once

#include "ArraySequence.h"
#include <iostream>


namespace MAIN {
	template<class T>
	class Matrix {
	private:
		ArraySequence<ArraySequence<T>> matrix;
		unsigned int size = 0;
	public:
		/// <summary>
		///		Constructors
		/// </summary>
		Matrix(); // Create empty matrix
		Matrix(T** elements, int count); // put matrix to this
		explicit Matrix(const ArraySequence<ArraySequence<T>>& _matrix); // copies all data to this

		// Destructor
		~Matrix(); // autodelete this matrix
		void DeleteMatrix();

		// Decompose
		T Get(int row, int col); // get T item of this matrix by row and col
		int GetLength(); // get length this matrix

		// Operations
		Matrix<T> Summ(Matrix<T>& _matrix); // summ two matrixes
		Matrix<T> Subs(Matrix<T>& _matrix); // substraction two matrixes
		Matrix<T> Multiply(Matrix<T>& _matrix); // multiply two matrixes
		Matrix<T> MultiplyOnAlpha(T alpha); // multiply matrix on alpha
		void ElemTransformOfCols(int col1, int col2, T alpha); // elementary col transformations
		void ElemTransformOfRows(int row1, int row2, T alpha); // elementary row transformations

		/*
		* Matrix norms are often used in determining the error of various numerical methods. 
		* In particular, in iterative methods for solving systems of linear algebraic equations, 
		* they are used to determine the error of the solution found at each iteration.
		* 
		* As a rule, three types of norms are used.
		*/
		T NormM(Matrix<T>& _matrix); // norm_M = max(Summ_j->[0, n](Abs(a_ij)))
		T NormL(Matrix<T>& _matrix); // norm_L = max(Summ_i->[0, n](Abs(a_ij)))
		T NormK(Matrix<T>& _matrix); // norm_K = sqrt(Summ_i->[0, n](Summ_j->[0, n](pow(a_ij, 2))))

		// Overloading operators
		Matrix<T>& operator=(Matrix<T> _matrix); // assigning a matrix to this

		//friend std::ostream& operator << (std::ostream& cout, Matrix<T>& n_matrix) {
		//	for (int j = 0; j < n_matrix.GetLength(); j++) { // по строкам
		//		for (int i = 0; i < n_matrix.GetLength(); i++) {
		//			cout << n_matrix.Get(j, i) << "   ";
		//		}
		//		cout << std::endl;
		//	}
		//	cout << std::endl;

		//	return cout;
		//}

		// print this matrix

	};
}
