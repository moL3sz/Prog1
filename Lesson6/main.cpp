// created by Molesz at 2022/03/17 10:17.
//
// DE-IK - 2022 - Prog1

#include <iostream>
#include <vector>
#include <string>
using namespace std;

template <typename T>
struct S
{
private:
    T val;

public:
    S(T vv = 0)
    {
        val = vv;
    }
    T &get();
    const T &get() const;

    void set(T);
    void operator=(const T &);
};
template <typename T>
T &S<T>::get()
{
    return val;
}
template <typename T>
const T &S<T>::get() const
{
    return val;
}
template <typename T>
void S<T>::set(T vv)
{
    val = vv;
}
template <typename T>
void S<T>::operator=(const T &vv)
{
    val = vv;
}

template <typename T>
void read_val(T &v)
{
    cin >> v;
}

template <typename T>
ostream &operator<<(ostream &os, vector<T> &vv)
{
    os << "{";
    for (int i = 0; i < vv.size(); i++)
    {
        os << vv[i];
        if (i < vv.size() - 1)
        {
            os << ", ";
        }
    }
    os << "}" << endl;
    return os;
}
template <typename T>
istream &operator>>(istream &is, vector<T> &vv)
{
    char ch = 0;
    is >> ch;
    if (ch != '{')
    {
        is.unget();
        return is;
    }
    T tmp;
    while (is >> tmp)
    {
        is >> ch;
        if (ch != ',')
        {
            break;
        }
    }
    return is;
}
int main()
{
    S<int> s;
    S<int> si{37};
    S<char> sc;
    S<double> sd{3.2};
    S<string> ss{"Hello"};
    S<vector<int>> sv{vector<int>{1, 2, 3, 5, 6, 7, 8, 9}};
    ss = "ASDasdÉLAJDKASJKLDJkalsDJ";
    cout << ss.get() << endl;
    ;
    for (auto &e : sv.get())
    {
        cout << e << " ";
    }
    cout << endl;
    vector<int> asd;
    read_val(asd);
    cout<< asd;

    return 0;
}