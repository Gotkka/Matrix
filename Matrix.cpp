#include <iostream>
#include<string>
using namespace std;

template <class T>
class Matrix
{
    private:
        int rows, cols;
        T *data;

    public:
        Matrix() : rows(0), cols(0), data(nullptr) {}; // Khoi tao ham khong doi
        Matrix(int rows, int cols) : rows(rows), cols(cols), data(new T[rows * cols]) {}; // Khoi tao ham co doi 

        ~Matrix()  // Ham huy 
        {
            delete[] data;
        }

        T getValueRowAndCol(int row, int col) const;  // Lay gia tri o vi tri bat ki
        void setValueRowAndCol(int row, int col, T value); // Thay gia tri o vi tri bat ki thanh
        T *getRow(int row); // Lay hang bat ki
        T *getColumn(int col); // Lay cot bat ki

        void print() const; // Ham in ma tran
        void input();   // Ham nhap ma tran

        bool isZeroMatrix(); // Kiem tra ma tran khong 
        bool isSquareMatrix(); // Kiem tra ma tran vuong
        bool isCrossMatrix(); // Kiem tra ma tran cheo
        bool isUnitMatrix(); // Kiem tra ma tran don vi 
        bool isRowMatrix(); // Kiem tra ma trang hang
        bool isColumnMatrix(); // Kiem tra ma tran cot

        Matrix displacementMatrix(); // Ma tran chuyen vi

        bool isEqual(Matrix matrix); // Kiem tra 2 ma tran bang nhau

        Matrix plusTwoMatrixs(Matrix matrix);  // Cong 2 ma tran
        Matrix minusTwoMatrixs(Matrix matrix); // Tru 2 ma tran
        Matrix scalarMultipliteMatrix(int k); // Nhan vo huong ma tran voi k 
        Matrix MultipliteTwoMatrixs(Matrix matrix); // Nhan 2 ma tran
};

template <class T> 
T Matrix <T> :: getValueRowAndCol(int row, int col) const 
{
    return data[row * cols + col];   
}

template <class T>
void Matrix <T> :: setValueRowAndCol(int row, int col, T value)
{
    data[row * cols + col] = value;
}

template <class T> 
void Matrix <T> :: print() const
{
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            cout << getValueRowAndCol(i, j) << ' ';
        }
        cout << '\n';
    }
}

template <class T> 
void Matrix <T> :: input()
{
    T value;
    cout << "Nhap so hang: ";
    cin >> rows;
    cout << "Nhap so cot:";
    cin >> cols;
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            cin >> value;
            setValueRowAndCol(i,j,value);
        }
    }
}

template <class T>
bool Matrix <T> :: isZeroMatrix()
{
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            if(getValueRowAndCol(i,j) != 0)
                return false;
        }
    }
    return true;
}

template <class T>
bool Matrix <T> :: isSquareMatrix()
{
    if(rows == cols)
        return true;
    return false;
}

template <class T>
bool Matrix <T> :: isCrossMatrix()
{
    if(!isSquareMatrix())
        return false;
    else 
    {
        for(int i = 0; i < rows; i++)
        {
            for(int j = 0; j < cols; j++)
            {
                if(!isZeroMatrix())
                {
                    if(i == j) 
                    {
                        if(getValueRowAndCol(i,j) == 0)
                            return false;
                    }
                    else 
                    {
                        if(getValueRowAndCol(i,j) != 0)
                            return false;
                    }
                }
            }
        }
        return true;
    }
}

template <class T>
bool Matrix <T> :: isUnitMatrix()
{
    if(!isCrossMatrix())
        return false;
    else 
    {
        for(int i = 0; i < rows; i++)
        {
            for(int j = 0; j < cols; j++)
            {
                if(i == j)
                {
                    if(getValueRowAndCol(i,j) != 1)
                        return false;
                }
                else 
                {
                    if(getValueRowAndCol(i,j) != 0)
                        return false;
                }
            }
        }
        return true;
    }
}

template <class T>
bool Matrix <T> :: isRowMatrix()
{
    if(rows == 1)
        return true;
    return false;
}

template <class T>
bool Matrix <T> :: isColumnMatrix()
{
    if(cols == 1)
        return true;
    return false;
}

template <class T>
T * Matrix <T> :: getRow(int row)
{
    T *temp = new T[cols];
    if(row < -1 || row > rows - 1)
        return nullptr;
    else 
    {
        for(int i = 0; i < cols; i++)
            temp[i] = getValueRowAndCol(row, i);
    }
    return temp;
}

template <class T>
T * Matrix <T> :: getColumn(int col)
{
    T *temp = new T[rows];
    if(col < -1 || col > cols - 1)
        return nullptr;
    else 
    {
        for(int i = 0; i < rows; i++)
            temp[i] = getValueRowAndCol(i, col);
    }
    return temp;
}

template <class T>
Matrix <T> Matrix <T> :: displacementMatrix()
{
    int newRows = cols;
    int newCols = rows;
    Matrix matrix(newRows, newCols);

    for(int i = 0; i < matrix.rows; i++ )
    {
        for(int j = 0 ; j < matrix.cols; j++)
        {
            matrix.setValueRowAndCol(i,j,getValueRowAndCol(j,i));
        }
    }
    return matrix;
}

template <class T>
bool Matrix <T> ::isEqual(Matrix <T> matrix)
{
    if(rows != matrix.rows)
        return false;
    if(cols != matrix.cols)
        return false;
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            if(getValueRowAndCol(i,j) != matrix.getValueRowAndCol(i,j))
                return false;
        }
    }
    return true;
}

template <class T>
Matrix <T> Matrix <T> :: plusTwoMatrixs(Matrix <T> matrix)
{
    if(rows != matrix.rows) 
        return Matrix();
    if(cols != matrix.cols)
        return Matrix();
    Matrix <T> result(rows,cols);
    for(int i = 0; i < result.rows; i++)
    {
        for(int j = 0; j < result.cols; j++)
            result.setValueRowAndCol(i,j,getValueRowAndCol(i,j) + matrix.getValueRowAndCol(i,j));
    }
    return result;
}

template <class T>
Matrix <T> Matrix <T> :: minusTwoMatrixs(Matrix <T> matrix)
{
    if(rows != matrix.rows) 
        return Matrix();
    if(cols != matrix.cols)
        return Matrix();
    Matrix <T> result(rows,cols);
    for(int i = 0; i < result.rows; i++)
    {
        for(int j = 0; j < result.cols; j++)
            result.setValueRowAndCol(i,j,getValueRowAndCol(i,j) - matrix.getValueRowAndCol(i,j));
    }
    return result;
}

template <class T>
Matrix <T> Matrix <T> :: scalarMultipliteMatrix(int k)
{
    Matrix <T> result(rows,cols);
    for(int i = 0; i < result.rows; i++)
    {
        for(int j = 0; j < result.cols; j++)
            result.setValueRowAndCol(i,j,getValueRowAndCol(i,j) * k);
    }
    return result;
}

template <class T>
Matrix <T> Matrix <T> :: MultipliteTwoMatrixs(Matrix <T> matrix)
{
    if(cols != matrix.rows)
        return Matrix();
    else 
    {
        Matrix <T> result(rows,matrix.cols);
        for(int i = 0; i < result.rows; i++)
        {
            for(int j = 0; j < result.cols; j++)
            {
                T sum = 0;
                for(int k = 0; k < cols; k++)
                    sum = sum + getValueRowAndCol(i,k) * matrix.getValueRowAndCol(k,j);
                result.setValueRowAndCol(i,j,sum);
            }
        }
        return result;
    }
}

int main()
{
    Matrix <int> matrix1(3,3);
    matrix1.input();
    Matrix <int> matrix2(3,3);
    matrix2.input();
    matrix1.MultipliteTwoMatrixs(matrix2).print();
}