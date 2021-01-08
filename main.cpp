#include <iostream>
#include<vector>
#include<memory>
#include"Design_Pattern.h"
#include "matrix.h"
#include <iostream>

using namespace std;

int main()
{
    QSMatrix<int> mat1(10, 10, 1);
    QSMatrix<int> mat2(10, 10, 2);
    QSMatrix<int> mat3 = mat1 + mat2;
    for (int i=0; i<mat3.get_rows(); i++)
    {
        for (int j=0; j<mat3.get_cols(); j++)
        {
            cout << mat3[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
