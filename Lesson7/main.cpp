// created by Molesz at 2022/03/24 10:14.
//
// DE-IK - 2022 - Prog1

#include <iostream>
#include <list>
#include <vector>
#include <array>
#include <algorithm>

using namespace std;

namespace cc
{
    template <typename Iter1, typename Iter2>

    Iter2 copy(Iter1 f1, Iter1 e1, Iter2 f2)
    {
        for (Iter1 p = f1; p != e1; ++p)
        {
            *f2++ = *p;
        }
        return f2;
    }
};

void print_element(int e)
{
    cout << e << " ";
}
template <typename T>
void print(const T &a)
{

    for_each(a.begin(), a.end(), [](auto e)
             { cout << e << " "; });
    cout << endl;
}
/*
template <typename T>
void transform (vector<int> a, int f){
    for(int i = 0; i < a.size(); i++){
        a[i] = f(a[i]);
    }
}*/
int main()
{

    constexpr int N = 10;
    int a[N];
    for (int i = 0; i < N; i++)
        a[i] = i;

    array<int, N> ai;
    copy(a, a + N, ai.begin());

    vector<int> vi(N);
    copy(a, a + N, vi.begin());

    list<int> li(N);
    copy(a, a + N, li.begin());

    // 4

    array<int, N> ai1;
    copy(ai.begin(), ai.end(), ai1.begin());

    vector<int> vi1(N);
    copy(vi.begin(), vi.end(), vi1.begin());

    list<int> li1(N);
    copy(li.begin(), li.end(), li1.begin());

    for_each(ai1.begin(), ai1.end(), [](int &e)
             { e += 2; });
    for_each(vi1.begin(), vi1.end(), [](int &e)
             { e += 3; });

    for_each(li1.begin(), li1.end(), [](int &e)
             { e += 5; });

    vector<int> v2(N);

    cc::copy(vi.begin(), vi.end(), vi1.end());
    print(vi1);

    return 0;
}