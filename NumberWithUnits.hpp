#include <iostream>
#include <utility>
#include <map>

using namespace std;

namespace ariel
{
    static map<string, map<string, float>> units_sign;

    class NumberWithUnits
    {
    private:
//        float _n;
//        string _s;

    public:
        float _num;
        string _unit;
        NumberWithUnits(float n, string s): _num(n),_unit(std::move(s)){}
        // NumberWithUnits(NumberWithUnits &n):_num(n._num), _unit(std::move(n._unit)){}
        static void read_units(ifstream &units_file);
        friend ostream &operator<<(ostream &out, const NumberWithUnits &t);
        friend istream &operator>>(istream &in, NumberWithUnits &t);
        friend  NumberWithUnits operator+=(NumberWithUnits &num_1, const NumberWithUnits &num_2);
        friend  NumberWithUnits operator-=(NumberWithUnits &num_1, const NumberWithUnits &num_2);
        friend  NumberWithUnits operator++(NumberWithUnits &num);
        friend  NumberWithUnits operator++(NumberWithUnits &num, int);
        friend NumberWithUnits operator--(NumberWithUnits &num);
        friend  NumberWithUnits operator--(NumberWithUnits &num, int);
        friend  NumberWithUnits operator*=(NumberWithUnits &num, float n);
        friend  NumberWithUnits operator*=(float n, NumberWithUnits &num);
        friend NumberWithUnits operator*(NumberWithUnits &num, float n);
        friend NumberWithUnits operator*(float n, NumberWithUnits &num);
        friend NumberWithUnits operator-(const NumberWithUnits &num_1, const NumberWithUnits &num_2);
        friend NumberWithUnits operator-(const NumberWithUnits &num);
        friend NumberWithUnits operator+(const NumberWithUnits &num_1, const NumberWithUnits &num_2);
        friend NumberWithUnits operator+(const NumberWithUnits &num, float n);
        friend bool operator>(const NumberWithUnits &num_1, const NumberWithUnits &num_2);
        friend bool operator>=(const NumberWithUnits &num_1, const NumberWithUnits &num_2);
        friend bool operator<(const NumberWithUnits &num_1, const NumberWithUnits &num_2);
        friend bool operator<=(const NumberWithUnits &num_1, const NumberWithUnits &num_2);
        friend bool operator==(const NumberWithUnits &num_1, const NumberWithUnits &num_2);
        friend bool operator!=(const NumberWithUnits &num_1, const NumberWithUnits &num_2);
    };
}