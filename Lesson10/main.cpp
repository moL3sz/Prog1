#include <iostream>
#include <iomanip>
#include <cmath>
#include <complex>
#include <cerrno>
#include "../Matrix.h"  
#include "../MatrixIO.h"

#include <algorithm>
using namespace std;
using namespace Numeric_lib;

void read_sqrt()
{
    int t;
    cin >> t;

    if (t >= 0)
    {
        cout << "Sqrt(" << t << "): " << sqrt(t) << endl;
    }
    else
    {
        cout << "No sqrt of " << t << endl;
    }
}

int main()
{
    try
    {

        cout << "sizeof:\n";
        cout << "char:\t" << sizeof(char) << endl;
        cout << "short:\t" << sizeof(short) << endl;
        cout << "int:\t" << sizeof(int) << endl;
        cout << "long:\t" << sizeof(long) << endl;
        cout << "float:\t" << sizeof(float) << endl;
        cout << "double:\t" << sizeof(double) << endl;
        cout << "int*:\t" << sizeof(int *) << endl;
        cout << "double*:\t" << sizeof(double *) << endl
             << endl;

        cout << "Matrix sizes" << endl;
        Matrix<int> a(10);
        Matrix<int> b(100);
        Matrix<double> c(10);

        Matrix<int, 2> d(10, 10);
        Matrix<int, 3> e(10, 10, 10);

        cout << "1D int, 10 elem: " << sizeof(a) << endl;
        cout << "1D int, 100 elem: " << sizeof(b) << endl;
        cout << "1D double, 10 elem: " << sizeof(c) << endl;
        cout << "2D int, 10*10 elem: " << sizeof(d) << endl;
        cout << "3D int, 10*10*10 elem: " << sizeof(e) << endl;

        cout << "\nNumber of elements" << endl;
        cout << "a:\t" << a.size() << endl;
        cout << "b:\t" << b.size() << endl;
        cout << "c:\t" << c.size() << endl;
        cout << "d:\t" << d.size() << endl;
        cout << "e:\t" << e.size() << endl;
        read_sqrt();

        /*
        Matrix<double> m2(10);
        for (int i = 0; i < m2.size(); i++)
        {
            double t;
            cin >> t;
            if (!cin)
                throw runtime_error("bena vagyol!");
            m2[i] = t;
        }
        cout << m2;*/

        cin.clear();
        cin.ignore();
        int n, m;
        cout << "Enter (n,m): ";
        cin >> n >> m;
        Matrix<double, 2> szorzo(n, m);
        for (int i = 1; i < n + 1; i++)
        {
            for (int j = 1; j < m + 1; j++)
            {
                szorzo(i - 1, j - 1) = i * j;
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cout << setw(4) <<szorzo(i,j);
            }
            cout << endl;
        }

        Matrix<complex<double>> mcomp(10);
        cout << "\nEnter 10 complex numbers (Re,Im):";
        complex<double> comp;
        for (int i = 0; i < 10; i++)
        {
            cin >> comp;
            if(!cin) throw runtime_error("bena vgay!");
            mcomp[i] = comp;
        }
        complex<double> s;
        for(int i = 0; i < mcomp.size(); i++){
            s+=mcomp[i];
        }
        cout << "Sum of mcomp: " << s << endl;
        

        cout << "\nEnter 6 ints: ";
        Matrix<int,2> M(2,3);
        for(int i = 0; i < 6; i++){
            int r  = i / 3;
            int c = i % 3;
            cin >> M(r,c);
        }
        for(int i = 0; i < 2; i++){
            for(int j = 0; j < 3; j++){
                cout << setw(4) << M(i,j);
            }
            cout << endl;
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
}