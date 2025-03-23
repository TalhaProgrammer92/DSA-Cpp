#include <iostream>
#include <vector>

using namespace std;

//? Dictionary class
template <typename Key, typename Value>
class Dict
{
public:
    //? Key and Value vectors
    vector<Key> key;
    vector<Value> value;

    //* Insert function
    void insert(Key k, Value v)
    {
        key.push_back(k);
        value.push_back(v);
    }

    //* Remove function
    void remove(Key k)
    {
        for (int i = 0; i < key.size(); i++)
        {
            if (key[i] == k)
            {
                key.erase(key.begin() + i);
                value.erase(value.begin() + i);
                break;
            }
        }
    }

    //* Get function
    Value get(Key k)
    {
        Value v;
        for (int i = 0; i < key.size(); i++)
        {
            if (key[i] == k)
            {
                v = value[i];
                break;
            }
        }
        return v;
    }
};

int main()
{
    //? Testing
    Dict<string, int> d;
    d.insert("a", 1);
    d.insert("b", 2);
    d.insert("c", 3);

    //* Accessing the values by keys
    for (int i = 0; i < d.key.size(); i++)
    {
        cout << d.get(d.key[i]) << endl;
    }

    return 0;
}
