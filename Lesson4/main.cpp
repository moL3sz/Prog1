#include <iostream>
#include <vector>

using namespace std;

string invalid = "\";:'[]*&^%$#@!-";
struct Person
{
private:
    string name;
    int age;

public:
    Person() {}
    Person(string n, int a)
    {
        if (a < 0 || a > 150)
        {
            throw runtime_error("Bad age!");
        }

        // check name
        for (char c : invalid)
        {
            for (char c1 : n)
            {
                if (c == c1)
                {
                    throw runtime_error("Bad name");
                }
            }
        }
        name = n;
        age = a;
    }
    string name_() const { return name; };
    int age_() const { return age; };
};
ostream &operator<<(ostream &os, Person &p)
{
    os << "Name: " << p.name_() << "\tAge: " << p.age_() << endl;
    return os;
}
istream &operator>>(istream &is, Person &p)
{
    try
    {
        string n;
        int a;
        is >> n >> a;
        p = Person(n,a);
        return is;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
}

int main()
{
    vector<Person> persons;
    Person p;
    while(cin >> p){
        persons.push_back(p);
    }
    for(Person p_ : persons){
        cout << p_;
    }
    return 0;
}