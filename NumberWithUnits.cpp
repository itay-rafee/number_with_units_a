#include <iostream>
#include <fstream>
#include <map>
#include <array>
#include <sstream>
#include "NumberWithUnits.hpp"
#include <cstdio>

using namespace std;

// map<string,string> couples;
//map<string, map<string, float>> units_sign;
// map<string,string>::iterator it1;
const int zero = 0, one = 1, two = 2;

namespace ariel
{
    /* check if the unit fit */
    bool contain(const string& unit1, const string& unit2)
    {
        if (units_sign.find(unit1) != units_sign.end())
        {
            if (units_sign[unit1].find(unit2) != units_sign[unit1].end())
            {
                return true;
            }
        }
        return false;
    }

    array<string, two> split( string& s,  string& delimiter)
    {
        size_t pos=zero;
        string token;
        if ((pos = s.find(delimiter)) != string::npos)
        {
            token = s.substr(0, pos);
            s.erase(0, pos + delimiter.length());
            return {token, s};
        }
        return {"", ""};
    }

    void set_neighbors(string& s1, string& s2, float num)
    {
        map<string, float> m = units_sign[s2];
        for (auto & it : m)
        {
            units_sign[s1][it.first] = num * it.second;
        }
    }

    void set_unit(string str)
    {
        string delimiter_1 = " = ";
        string delimiter_2 = " ";
        float n1 =0;
        float n2=0;
        string token;
        string s1;
        string s2;
        array<string, two> sp = split(str, delimiter_1);
        array<string, two> sp2 = split(sp.at(zero), delimiter_2);
        stringstream geek(sp2.at(zero));
        geek >> n1;
        s1 = sp2.at(one);
        sp2 = split(sp.at(one), delimiter_2);
        geek >> n2;
        s2 = sp2.at(one);
        units_sign[s1][s2] = n1 / n2;
        units_sign[s2][s1] = n2 / n1;
        set_neighbors(s1, s2, n1 / n2);
        set_neighbors(s2, s1, n2 / n1);
    }

    void NumberWithUnits::read_units(ifstream &units_file)
    {
        string line;
        while (getline(units_file, line))
        {
            set_unit(line);
        }
        units_file.close();
    }

    ostream &operator<<(ostream &out, const NumberWithUnits &t)
    {
        return (out << t._num << "[" + t._unit + "]");
    }
    istream &operator>>(istream &input, NumberWithUnits &t)
    {
        char ch =0;
        return (input >> t._num >> ch >> t._unit >> ch);
    }
    NumberWithUnits operator+=(NumberWithUnits &num_1, const NumberWithUnits &num_2)
    {
        num_1 = num_1 + num_2;
        return num_1;
    }
    NumberWithUnits operator-=(NumberWithUnits &num_1, const NumberWithUnits &num_2)
    {
        num_1 = num_1 - num_2;
        return num_1;
    }
    NumberWithUnits operator*=(NumberWithUnits &num, float n)
    {
        num._num *= n;
        return num;
    }
    NumberWithUnits operator*=(float n, NumberWithUnits &num)
    {
        num._num *= n;
        return num;
    }
    NumberWithUnits operator++(NumberWithUnits &num)
    {
        num._num++;
        return num;
    }
    NumberWithUnits operator++(NumberWithUnits &num, int)
    {
        NumberWithUnits copy = num;
        num._num++;
        return copy;
    }
    NumberWithUnits operator--(NumberWithUnits &num)
    {
        num._num--;
        return num;
    }
    NumberWithUnits operator--(NumberWithUnits &num, int)
    {
        NumberWithUnits copy = num;
        num._num--;
        return copy;
    }

    NumberWithUnits operator*(NumberWithUnits &num, float n)
    {
        return NumberWithUnits{num._num * n, num._unit};
    }
    NumberWithUnits operator*(float n, NumberWithUnits &num)
    {
        return NumberWithUnits{num._num * n, num._unit};
    }
    NumberWithUnits operator-(const NumberWithUnits &num_1, const NumberWithUnits &num_2)
    {
        if (contain(num_1._unit, num_2._unit))
        {
            float newNum = num_1._num - units_sign[num_2._unit][num_1._unit] * num_2._num;
            return NumberWithUnits{newNum, num_1._unit};
        }
        throw exception();
    }
    NumberWithUnits operator-(const NumberWithUnits &num)
    {
        return NumberWithUnits{-num._num, num._unit};
    }
    NumberWithUnits operator+(const NumberWithUnits &num_1, const NumberWithUnits &num_2)
    {
        if (contain(num_1._unit, num_2._unit))
        {
            float newNum = num_1._num + units_sign[num_2._unit][num_1._unit] * num_2._num;
            return NumberWithUnits{newNum, num_1._unit};
        }
        throw exception();
    }
    NumberWithUnits operator+(const NumberWithUnits &num, float n)
    {
        return NumberWithUnits{num._num + n, num._unit};
    }
    bool operator>(const NumberWithUnits &num_1, const NumberWithUnits &num_2)
    {
        if (contain(num_1._unit, num_2._unit))
        {
            bool ans = false;
            float n_2 = units_sign[num_2._unit][num_1._unit] * num_2._num;
            if (num_1._num > n_2)
            {
                ans = true;
            }
            return ans;
        }
        throw exception();
    }
    bool operator>=(const NumberWithUnits &num_1, const NumberWithUnits &num_2)
    {
        if (contain(num_1._unit, num_2._unit))
        {
            bool ans = false;
            float n_2 = units_sign[num_2._unit][num_1._unit] * num_2._num;
            if (num_1._num >= n_2)
            {
                ans = true;
            }
            return ans;
        }
        throw exception();
    }
    bool operator<(const NumberWithUnits &num_1, const NumberWithUnits &num_2)
    {
        if (contain(num_1._unit, num_2._unit))
        {
            bool ans = false;
            float n_2 = units_sign[num_2._unit][num_1._unit] * num_2._num;
            if (num_1._num < n_2)
            {
                ans = true;
            }
            return ans;
        }
        throw exception();
    }
    bool operator<=(const NumberWithUnits &num_1, const NumberWithUnits &num_2)
    {
        if (contain(num_1._unit, num_2._unit))
        {
            bool ans = false;
            float n_2 = units_sign[num_2._unit][num_1._unit] * num_2._num;
            if (num_1._num <= n_2)
            {
                ans = true;
            }
            return ans;
        }
        throw exception();
    }
    bool operator==(const NumberWithUnits &num_1, const NumberWithUnits &num_2)
    {
        if (contain(num_1._unit, num_2._unit))
        {
            bool ans = false;
            float n_2 = units_sign[num_2._unit][num_1._unit] * num_2._num;
            if (num_1._num == n_2)
            {
                ans = true;
            }
            return ans;
        }
        throw exception();
    }
    bool operator!=(const NumberWithUnits &num_1, const NumberWithUnits &num_2)
    {
        if (contain(num_1._unit, num_2._unit))
        {
            bool ans = false;
            float n_2 = units_sign[num_2._unit][num_1._unit] * num_2._num;
            if (num_1._num != n_2)
            {
                ans = true;
            }
            return ans;
        }

        throw exception();
    }


}

// using namespace ariel;
// int main() {
//     char filename[] = "units.txt";
// //    ofstream units_f(filename);
// //    units_f << "1 km = 1000 m\n1 m = 100 cm\n1 kg = 1000 g\n1 ton = 1000 kg\n1 hour = 60 min\n1 min = 60 sec\n1 USD = 3.33 ILS";
// //    units_f.close();
//     ifstream units_file{filename};
//     NumberWithUnits::read_units(units_file);

//     NumberWithUnits a{2, "km"};   // 2 kilometers
//     cout << a << endl;           // Prints "2[km]".
//     cout << (-a) << endl;    // Prints "-2[km]"
//     cout << (3*a) << endl;    // Prints "6[km]"

//     NumberWithUnits b{300, "m"};  // 300 meters
//     cout << (a+b) << endl;   // Prints "2.3[km]". Note: units are determined by first number (a).
//     cout << (b-a) << endl;   // Prints "-1700[m]". Note: units are determined by first number (b).

//     cout << boolalpha; // print booleans as strings from now on:
//     cout << (a>b) << endl;  // Prints "true"
//     cout << (a<=b) << endl;  // Prints "false"
//     cout << (a==NumberWithUnits{2000, "m"}) << endl;  // Prints "true"

//     istringstream sample_input{"700 [ kg ]"};
//     sample_input >> a;
//     cout << a << endl;   // Prints "700[kg]"
//     cout << (a += NumberWithUnits{1, "ton"}) << endl;  // prints "1700[kg]"
//     cout << a << endl;   // Prints "1700[kg]". Note that a has changed.

//     try {
//         cout << (a+b) << endl;
//     } catch (const std::exception& ex) {
//         cout << ex.what() << endl; // Prints "Units do not match - [m] cannot be converted to [kg]"
//     }
//     cout << "End of demo!" << endl;
//     return 0;
// }