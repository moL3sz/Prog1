// created by Molesz at 2022/04/07 11:12.
//
// DE-IK - 2022 - Prog1

#include <iostream>
#include <algorithm>
#include <fstream>
#include <numeric>

using namespace std;

template <typename C>
void print(const C &c, char sep = '\n')
{
    cout << "Container: " << endl;
    for (const auto d : c)
    {
        cout << d << sep;
    }
    cout << endl;
}

int main()
{

    try
    {
        const string iname{"input_floats.txt"};
        ifstream ifs{iname};
        if (!ifs)
        {
            throw runtime_error("Nincs ilyen file te idióta!");
        }
        vector<double> vd;
        for (double d; ifs >> d;)
        {
            vd.push_back(d);
        }

        vector<int> vi(vd.size());
        copy(vd.begin(), vd.end(), vi.begin());
        print(vd);
        print(vi);

        for (int i = 0; i < vi.size(); i++)
        {
            cout << vd[i] << "\t" << vi[i] << endl;
        }

        double vds = std::accumulate(vd.begin(), vd.end(), double(0));
        int vis = std::accumulate(vi.begin(), vi.end(), 0);

        cout << "Double sum: " << vds << endl;
        cout << "Integer sum: " << vis << endl;

        cout << "Difference: " << vds - vis << endl;

        cout << endl;

        reverse(vd.begin(), vd.end());

        print(vd);

        double mean = vds / vd.size();
        cout << "Mean value: " << mean << endl;

        vector<double> vd2(vd.size());
        auto it = copy_if(vd.begin(), vd.end(), vd2.begin(), [=](auto &e)
                { return e < mean; });
        vd2.resize(distance(vd2.begin(), it));
        print(vd2);
        sort(vd.begin(), vd.end());
        print(vd);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
    catch (...)
    {
        cerr << "Unexpected error :(" << endl;
    }

    return 0;
}