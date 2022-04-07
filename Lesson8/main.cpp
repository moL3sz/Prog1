#include <iostream>
#include <algorithm>
#include <vector>
#include <array>
#include <map>

using namespace std;



template <typename K, typename V>
void print(map<K, V> m){
    for(pair<K, V> e : m){
        cout << e.first << ":" << e.second << " ";
    }
}
template <typename K, typename V>
void read_msi(map<K, V> &msi){
    string k;
    int v;
    cout << "\n(Key, value): ";
    cin >> k >> v;
    msi[k] = v;
}
int main(){

    //2
    try
    {
        map<string, int> msi;
        msi["a"] = 1;
        msi["b"] = 2;
        msi["c"] = 3;
        msi["d"] = 5;
        msi["e"] = 6;
        msi["f"] = 7;
        msi["g"] = 8;
        msi["i"] = 9;
        msi["j"] = 10;
        msi["k"] = 11;
        print<string, int> (msi);
        string eraseElement;
        cin >> eraseElement;

        msi.erase(eraseElement);

        print<string, int>(msi);
        for(short i = 0; i < 10; i++){
            read_msi<string, int>(msi);
        }
        print<string, int>(msi);
        int s = 0;
        for(pair<string, int> e : msi){
            s += e.second;
        }
        cout << "Sum of msi: " << s << endl;
        map<int, string> mis;

        for(pair<string, int> e : msi){
            mis[e.second] = e.first;
        }
        print<int, string>(mis);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    catch(...){
        std::cerr << "Rossz vagyol";
    }
    

    return 0;
}