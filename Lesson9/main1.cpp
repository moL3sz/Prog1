#include <iostream>
#include <set>
#include <stdexcept>
#include <string>
#include <vector>

using namespace std;

struct Fruit
{
    string name;
    int quantity;
    double unit_price;

    Fruit(const string &n, int q = 0, int u = 0)
    {
        name = n;
        quantity = q;
        unit_price = u;
    };
};

struct Fruit_cmp_ptr
{
    bool operator() (const Fruit *f1, const Fruit *f2) const
    {
        return f1->name < f2->name;
        //return f1->quantity < f2->quantity;
    }
};
 int main()
{

    try
    {
        vector<Fruit> vf{
            Fruit("Plum", 3),
            Fruit("Grape", 32),
            Fruit("Banana", 11),
            Fruit("Apple", 98),
            Fruit("Orange", 75),
            Fruit("Cherry", 47),
            Fruit("Plum", 33),
            Fruit("Kiwi", 29)};

        cout << "Vector values: " << endl;
        for (Fruit &f : vf)
        {
            cout << f.name << endl;
        }
        set<Fruit*,Fruit_cmp_ptr> sf;
        for (auto &f : vf)
        {
            sf.insert(&f);
        }

        cout << endl;
        cout << "Set values: " << endl;
        for (const Fruit *f : sf)
        {
            cout << f->name << endl;
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
        return 1;
    }
    catch (...)
    {
        std::cerr << "Unexpected error :(" << endl;
        return 2;
    }

    return 0;
}