/*Overload operator two multiply two matrices.
Matrix class has three member variable int rows, int cols, int ** Mat and required member functions to perform matrix multiplication.*/

#include <iostream>
using namespace std;

class Matrix {
private:
    int row;
    int col;
    int **mat;

public:
    // Constructor
    Matrix(int r, int c) : row(r), col(c) {
        mat = new int*[row];
        for(int i = 0; i < row; i++) {
            mat[i] = new int[col];
            for(int j = 0; j < col; j++) {
                mat[i][j] = 0;
            }
        }
    }

    // Copy constructor
    Matrix(const Matrix& other) : row(other.row), col(other.col) {
        mat = new int*[row];
        for(int i = 0; i < row; i++) {
            mat[i] = new int[col];
            for(int j = 0; j < col; j++) {
                mat[i][j] = other.mat[i][j];
            }
        }
    }

    // Destructor
    ~Matrix() {
        for(int i = 0; i < row; i++) {
            delete[] mat[i];
        }
        delete[] mat;
    }

    // Overloaded * operator for matrix multiplication
    Matrix operator*(const Matrix &other) {
        if(col != other.row) {
            cout << "Invalid dimensions for multiplication!" << endl;
            return Matrix(0, 0);  // Return empty matrix
        }

        Matrix result(row, other.col);
        for(int i = 0; i < row; i++) {
            for(int j = 0; j < other.col; j++) {
                for(int k = 0; k < col; k++) {
                    result.mat[i][j] += mat[i][k] * other.mat[k][j];
                }
            }
        }
        return result;
    }

    // Friend function for output
    friend ostream& operator<<(ostream& out, const Matrix &m) {
        for(int i = 0; i < m.row; i++) {
            for(int j = 0; j < m.col; j++) {
                out << m.mat[i][j] << " ";
            }
            out << endl;
        }
        return out;
    }

    // Friend function for input
    friend istream& operator>>(istream& in, Matrix &m) {
        for(int i = 0; i < m.row; i++) {
            for(int j = 0; j < m.col; j++) {
                in >> m.mat[i][j];
            }
        }
        return in;
    }
};

int main() {
    int r1, c1, r2, c2;
    
    cout << "Matrix 1" << endl << "Rows and Columns: ";
    cin >> r1 >> c1;
    
    cout << "Matrix 2" << endl << "Rows and Columns: ";
    cin >> r2 >> c2;
    
    if(c1 != r2) {
        cout << "Invalid dimensions for matrix multiplication!" << endl;
        return 0;
    }
    
    Matrix m1(r1, c1), m2(r2, c2);
    
    cout << "Enter elements for Matrix 1:" << endl;
    cin >> m1;
    
    cout << "Enter elements for Matrix 2:" << endl;
    cin >> m2;
    
    Matrix result = m1 * m2;
    
    cout << "Result of multiplication:" << endl;
    cout << result;
    
    return 0;
}


/* OUTPUT
Matrix 1
Rows and Columns: 2 3
Matrix 2
Rows and Columns: 3 3 
Enter elements for Matrix 1:
1 2 3 4 5 6
Enter elements for Matrix 2:
1 2 3 4 5 6 7 8 9
Result of multiplication:
30 36 42
66 81 96
*/
