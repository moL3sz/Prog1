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
template <typename C>
void inc(C &c, int n)
{
    for (auto &i : c)
    {
        i += n;
    }
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
    print(ai);
    print(vi);
    print(li);

    inc(ai, 2);
    inc(vi, 3);
    inc(li, 5);

    print(ai);
    print(vi);
    print(li);

    array<int, N> ai1;
    cc::copy(ai.begin(), ai.end(), ai1.begin());

    vector<int> vi1(N);
    cc::copy(vi.begin(), vi.end(), vi1.begin());

    list<int> li1(N);
    cc::copy(li.begin(), li.end(), li1.begin());

    print(ai1);
    print(vi1);
    print(li1);

    vector<int>::iterator vit;
    vit = find(vi1.begin(), vi1.end(), 3);

    if (vit != vi1.end())
    {
        cout << "[+] Found at " << distance(vi1.begin(), vit) << endl;
    }
    else{
        cout << "[-] Not found :(" << endl;
    }

    //wants to find no 27.
    vector<int>::iterator vit2;
	vit2 = std::find(vi1.begin(), vi1.end(), 27);
	
    if( vit2 != vi1.end()){
		cout << "[+] Found at " << distance(vi1.begin(), vit2) << endl;
	}
	else {
		cout << "[-] Not found :(" << endl;
	}

    return 0;
}