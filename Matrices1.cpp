#include "Matrices.h"
#include <iostream>
namespace Matrices
{
	Matrix::Matrix(int _rows, int _cols)
	{
		rows = _rows;
		cols = _cols;
		a.resize(rows);
	
		for (int i = 0; i < rows; i++)
		{
			a[i].resize(cols);

		}

		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				a[i][j] = 0;
			}

		}
	}


	 Matrix operator+(const Matrix& a, const Matrix& b)
	{

		
		if (a.getRows() == b.getRows() && a.getCols() == b.getCols())
		{
			Matrix c(a.getRows(), b.getCols());
			
			for (int i = 0; i < a.getRows(); i++)
			{
					for (int j = 0; j < a.getCols(); j++)
					{
						
						c(i,j) = a(i, j) + b(i, j);
						
					}
			}
			return c;
		}
		else
		{
			throw runtime_error("Error: dimensions must agree");
		}
		
		
	}

	Matrix operator*(const Matrix& a, const Matrix& b)
	{
		double total = 0;
		if (a.getCols() == b.getRows())
		{
			Matrix c(a.getRows(), b.getCols());
			
			for (int k = 0; k < b.getCols(); k++)
			{
				for (int i = 0; i < a.getRows(); i++)
				{
					for (int j = 0;j < b.getRows();j++)
					{
						total += a(i, j) * b(j, k);
					}
					c(i, k) = total;
					total = 0;
				}
			}

				
		
			return c;
		}
		else
		{
			throw runtime_error("Error: dimensions must agree");
		}
	}

	bool operator==(const Matrix& a, const Matrix& b)
	{
		bool flag = true;
		if (a.getRows() != b.getRows() && a.getCols() != b.getCols())
		{
			return false;
		}
		else
		{
			for (int i = 0; i < a.getRows(); i++)
			{
				for (int j = 0; j < b.getCols(); j++)
				{
					if (abs(a(i, j) - b(i, j)) < 0.001 && flag == true)
					{
						return true;
					}
					else
					{
						flag = false;
						return false;
					}
				}
			}
		}
	}

	bool operator!=(const Matrix& a, const Matrix& b)
	{
		bool flag = false;
		if (a.getRows() != b.getRows() || a.getCols() != b.getCols())
		{
			return true;
		}
		else
		{
			for (int i = 0; i < a.getRows(); i++)
			{
				for (int j = 0; j < b.getCols(); j++)
				{
					if (abs(a(i, j) - b(i, j)) < 0.001 && flag == false)
					{
						return false;
					}
					else
					{
						flag = true;
						return flag;
					}
				}
			}
		}
	}

	ostream& operator<<(ostream& os, const Matrix& a)
	{
		
		for (int i = 0; i < a.getRows(); i++)
		{
			for (int j = 0; j < a.getCols(); j++)
			{
				os << a(i,j) << setw(10);
			}
			os << setw(10) << '\n' << '\n';
		}
		return os;
	}
	
}