#pragma once
#include<iostream>
using namespace std;

template<class T>
class Matrix
{
	int row, col;
	T** arr=nullptr;
public:
	
	Matrix() :Matrix(1, 1) {};  
	Matrix(int row, int col);
	Matrix(const Matrix& obj);
	~Matrix();

	friend ostream& operator<<<T>(ostream& out, const Matrix<T>& t);
	void print();
	void setRandom(int min = 0, int max = 9);
	T* operator[](int ind);
	void addRow();
	void transponation();
	Matrix<T> operator+(Matrix b);
	Matrix<T> operator*(T b);

};

//(a[r]).[c] = *(*(a+r)+c)

template<class T>
Matrix<T>::Matrix(int r, int c) :row(r), col(c)
{
	if (row < 1 or col < 1)
	{
		cout << "error" << endl;
	}
	else
	{
		arr = new T * [row];
		for (size_t i = 0; i < row; i++)
		{
			arr[i] = new T[col]{ 0 };
		}
	}
}

template<class T>
inline Matrix<T>::Matrix(const Matrix& obj)
{
	
	this->row = obj.row;
	this->col = obj.col;
	this->arr = new T * [obj.row];
	for (size_t i = 0; i < row; i++)
	{
		this->arr[i] = new T[obj.col];
	}

	for (size_t i = 0; i < obj.row; i++)
	{
		for (size_t j = 0; j < obj.col; j++)
		{
			this->arr[i][j] = obj.arr[i][j];
		}
	}

}

template<class T>
Matrix<T>::~Matrix()
{
	for (size_t i = 0; i < row; i++)
	{
		delete[]arr[i];
	}
	delete[] arr;
}

template<class T>
inline void Matrix<T>::print()
{
	for (size_t i = 0; i < row; i++)
	{
		for (size_t j = 0; j < col; j++)
		{
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

template<class T>
inline void Matrix<T>::setRandom(int min, int max)
{
	for (size_t i = 0; i < row; i++)
	{
		for (size_t j = 0; j < col; j++)
		{
			arr[i][j] = rand() % (max - min + 1) + min;
		}
	}
}

template<class T>
inline T* Matrix<T>::operator[](int ind)
{
	return arr[ind];
}

template<class T>
inline void Matrix<T>::addRow()
{
	T** new_arr = new T * [row + 1];
	for (size_t i = 0; i < row; i++)
	{
		new_arr[i] = arr[i];
	}
	new_arr[row] = new T[col]{ 0 };
	delete[]arr;
	arr = new_arr;
	row++;
}

template<class T>
inline void Matrix<T>::transponation()
{
	swap(col, row);
	T** new_arr=new T*[row];
	for (size_t i = 0; i < row; i++)
	{
		new_arr[i] = new T[col];
	}

	for (size_t i = 0; i < row; i++)
	{
		for (size_t j = 0; j < col; j++)
		{
			new_arr[i][j] = arr[j][i];
		}
	}
	delete[] arr;
	arr = new_arr;

}

template<class T>
inline Matrix<T> Matrix<T>::operator*(T b)
{
	this->row = this->row * b;
	this->col = this->col * b;
	delete[] this->arr;
	this->arr = new T * [this->row];
	for (size_t i = 0; i < this->row; i++)
	{
		arr[i] = new T[this->col];
	}
	return *this;
}


template<class T >
inline Matrix<T> Matrix<T>::operator+(Matrix<T> b)
{
	
	Matrix c;
	
	c.row = this->row + b.row;
	c.col = this->col + b.col;
	c.arr= new T * [c.row];
	for (size_t i = 0; i < c.row; i++)
	{
		c.arr[i] = new T[c.col];
	}
	return c;
	
}

template<class T>
ostream& operator<<(ostream& out, const Matrix<T>& t)
{
	for (size_t i = 0; i < t.row; i++)
	{
		for (size_t j = 0; j < t.col; j++)
		{
			out << t.arr[i][j] << " ";
		}
		out << endl;
	}
	return out;
}