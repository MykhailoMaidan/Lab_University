# include "matrix.h"
Matrix::Matrix()
{
    size_matrix_collum = 0;
    size_matrix_row = 0;
}

Matrix::Matrix(int size_row, int size_collum)
{
    size_matrix_collum = size_collum;
    size_matrix_row = size_row;
    mass_matrix = new float*[size_matrix_row];
    for (int i = 0; i < size_matrix_row; i++)
    {
        mass_matrix[i] = new float[size_matrix_collum];
    }
    for (int i = 0; i < size_matrix_row; i++)
    {
        for (int j = 0; j < size_matrix_collum; j++)
        {

            mass_matrix[i][j] = 0;
        }
    }

}
void Matrix::SetData(int size_matrixrow, int size_matrixcollum, float** mass )
{

    size_matrix_row = size_matrixrow;
    size_matrix_collum = size_matrixcollum;
    mass_matrix = new float*[size_matrix_row];
    for (int i = 0; i < size_matrix_row; i++)
    {
        mass_matrix[i] = new float [size_matrix_collum] ;
    }
    for (int i = 0; i < size_matrix_row; i++)
    {
        for (int j = 0; j < size_matrix_collum; j++)
        {

            mass_matrix[i][j] = mass[i][j];
        }
    }

}
Matrix::~Matrix()
{
        for (int i = 0; i < size_matrix_row; i++)
            delete[] mass_matrix[i];

}
Matrix::Matrix(const Matrix &copy_constr)
{
    size_matrix_row = copy_constr.size_matrix_row;
    size_matrix_collum = copy_constr.size_matrix_collum;
    mass_matrix = new float*[size_matrix_row];
    for (int i = 0; i < size_matrix_row; i++)
    {
        mass_matrix[i] = new float[size_matrix_collum];
    }
    for (int i = 0; i < size_matrix_row; i++)
    {
        for (int j = 0; j < size_matrix_collum; j++)
        {
            mass_matrix[i][j] = copy_constr.mass_matrix[i][j];
        }
    }
}
Matrix Matrix::operator+(Matrix & obj)
{
    Matrix res_obj(obj.size_matrix_row, obj.size_matrix_collum);
    for (int i = 0; i < obj.size_matrix_row; i++)
    {
        for (int j = 0; j < obj.size_matrix_collum; j++)
        {
            res_obj.mass_matrix[i][j] = mass_matrix[i][j] +obj.mass_matrix[i][j];
        }
    }
    return res_obj;
}
void Matrix::Show()
{
    for (int i = 0; i < this->size_matrix_row ; i++)
    {
        for (int j = 0; j < this->size_matrix_collum; j++)
        {

            cout << this->mass_matrix[i][j] << " ";

        }
        cout << endl;
    }
}
Matrix Matrix::operator*(Matrix & obj_matrix)
{
    Matrix res(size_matrix_row, obj_matrix.size_matrix_collum);
    for (int i = 0; i < size_matrix_row; i++)
    {
        for (int j = 0; j < obj_matrix.size_matrix_collum; j++)
          {

            for (int k = 0; k < size_matrix_collum; k++)
            {

                res.mass_matrix[i][j] = float(res.mass_matrix[i][j] + float(mass_matrix[i][k] * obj_matrix.mass_matrix[k][j]));
            }
        }
    }
    return res;
}
Matrix Matrix::setTransMatrix()
{
    Matrix res(size_matrix_collum, size_matrix_row);
    for (int i = 0; i < size_matrix_collum; i++)
    {
        for (int j = 0; j < size_matrix_row; j++)
        {
            res.mass_matrix[i][j] = mass_matrix[j][i];
        }
    }


    return res;
}
Matrix Matrix::operator-(Matrix &obj_sub)
{
    Matrix res(size_matrix_row, size_matrix_collum);
    for (int i = 0; i < size_matrix_row; i++)
    {
        for (int j = 0; j < size_matrix_collum; j++)
        {
            res.mass_matrix[i][j] = mass_matrix[i][j] - obj_sub.mass_matrix[i][j];
        }
    }
    return res;
}
void Matrix::ShowFile()
{
    ofstream file("D:\\weewr.txt",ios_base::app);
    for(int i = 0; i < size_matrix_row; i++)
    {
        for(int j = 0; j <size_matrix_collum; j++)
        {
            file << mass_matrix[i][j] << " ";
        }
        file << endl;
    }
    file << "************" << endl;
    file.close();

}
void Matrix::Stobu(int n, int x)
{
size_matrix_row = n;
size_matrix_collum = x;
    mass_matrix = new float*[n];
    for (int i = 0; i < n; i++)
    {
        mass_matrix[i] = new float[0];
    }
    int i = 1;
        for(int j = 0; j < n ; j++)
        {
            if( i%2 == 0)
            {

                mass_matrix[j][0] = (float(i*i)/float(12));
                i++;
            }
            else
            {

                mass_matrix[j][0] = float(12)/float(i*i*i);
                i++;
            }
        }

}
Matrix Matrix::MullMatrix(Matrix &obj)
{
    Matrix res(size_matrix_row,obj.size_matrix_collum);
    for(int i = 0; i <size_matrix_row; i++)
    {
        for(int j = 0; j <obj.size_matrix_collum; j++)
        {
            res.mass_matrix[i][j] = mass_matrix[i][1] * obj.mass_matrix[i][j];
        }
    }
    return res;
}
Matrix Matrix::NumberAddMatrix(int n)
{
    Matrix res(size_matrix_row,size_matrix_collum);
    for(int i = 0; i <size_matrix_row; i++)
    {
        for(int j = 0; j <size_matrix_collum; j++)
        {
            res.mass_matrix[i][j] =  n * mass_matrix[i][j];
        }
    }
    return res;
}
void Matrix::GenericMatrixC(int n )
{
    size_matrix_row = n;
    size_matrix_collum = n;
    mass_matrix = new float*[n];
    for (int i = 0; i < n; i++)
    {
        mass_matrix[i] = new float[n];
    }

    int k = 1;
    int x = 1;
    for(int i = 0; i < size_matrix_row; i++)
    {
        for(int j = 0; j < size_matrix_collum; j++)
        {
            mass_matrix[i][j] = float(1 / float(4*k+x*x));
            x++;
        }
        k++;
    }


}
Matrix & Matrix::operator=(const Matrix & obj)
{
    size_matrix_row = obj.size_matrix_row;
    size_matrix_collum = obj.size_matrix_collum;
    mass_matrix = new float*[size_matrix_row];
    for (int i = 0; i < size_matrix_row; i++)
    {
        mass_matrix[i] = new float[size_matrix_collum];
    }
    for (int i = 0; i < size_matrix_row; i++)
    {
        for (int j = 0; j < size_matrix_collum; j++)
        {
            mass_matrix[i][j] = obj.mass_matrix[i][j];
        }
    }
    return *this;
}
Matrix Matrix::ADDNumberMatrix(Matrix & obj)
{
    Matrix res(obj.size_matrix_row, obj.size_matrix_collum);
    for(int i = 0; i < obj.size_matrix_row; i++)
    {
        for (int j = 0; j < obj.size_matrix_collum; j++)
        {
            res.mass_matrix[i][j] = mass_matrix[0][0] + obj.mass_matrix[i][j];
        }
    }
    return res;
}

 int Matrix::ShowCollum()
 {
     return size_matrix_collum;
 }
 int Matrix::ShowRow()
 {
     return size_matrix_row;
 }
 float** Matrix::ShowMatrix()
 {
     return mass_matrix;
 }
