#pragma once
#ifndef MATRIX_H
#define MARTIX_H

#include <fstream>
#include <iostream>
using namespace std;
class Matrix
{
public:
    Matrix(int, int);
    Matrix();
    Matrix(const Matrix &);
    ~Matrix();
    Matrix operator+(Matrix &);
    Matrix & operator=(const  Matrix &);
    Matrix operator*(Matrix &);
    Matrix setTransMatrix();
    void Stobu(int,int);
    Matrix operator-(Matrix &);
    Matrix MullMatrix(Matrix & );
    Matrix NumberAddMatrix(int);
    void SetData(int,int, float**);
    void ShowFile();
    void Show();
    void GenericMatrixC(int);
    Matrix ADDNumberMatrix(Matrix &);
    int ShowCollum();
    int ShowRow();
    float** ShowMatrix();






private:
    float **mass_matrix;
    int size_matrix_collum;
    int size_matrix_row;

};


#endif // !MATRIX_H

