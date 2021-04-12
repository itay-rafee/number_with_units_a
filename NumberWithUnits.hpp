#include <iostream>

using namespace std;

namespace ariel
{
    class NumberWithUnits
    {
    private:
        float _num;
        string _unit;

    public:
        NumberWithUnits(float n, string s): _num(n),_unit(s){}
        static void read_units(ifstream &units_file);
        friend ostream &operator<<(ostream &out, const NumberWithUnits &t);
        friend istream &operator>>(istream &in, NumberWithUnits &t);
        friend NumberWithUnits operator+=(NumberWithUnits &num_1, const NumberWithUnits &num_2);
        friend NumberWithUnits operator-=(NumberWithUnits &num_1, const NumberWithUnits &num_2);
        friend NumberWithUnits operator++(NumberWithUnits &num);
        friend NumberWithUnits operator++(NumberWithUnits &num, int);
        friend NumberWithUnits operator--(NumberWithUnits &num);
        friend NumberWithUnits operator--(NumberWithUnits &num, int);
        friend NumberWithUnits operator*=(NumberWithUnits &num, float n);
        friend NumberWithUnits operator*=(float n, NumberWithUnits &num);
        friend const NumberWithUnits operator*(NumberWithUnits &num, float n);
        friend const NumberWithUnits operator*(float n, NumberWithUnits &num);
        friend const NumberWithUnits operator-(const NumberWithUnits &num_1, const NumberWithUnits &num_2);
        friend const NumberWithUnits operator-(const NumberWithUnits &num);
        friend const NumberWithUnits operator+(const NumberWithUnits &num_1, const NumberWithUnits &num_2);
        friend const NumberWithUnits operator+(const NumberWithUnits &num, float n);
        friend bool operator>(const NumberWithUnits &num_1, const NumberWithUnits &num_2);
        friend bool operator>=(const NumberWithUnits &num_1, const NumberWithUnits &num_2);
        friend bool operator<(const NumberWithUnits &num_1, const NumberWithUnits &num_2);
        friend bool operator<=(const NumberWithUnits &num_1, const NumberWithUnits &num_2);
        friend bool operator==(const NumberWithUnits &num_1, const NumberWithUnits &num_2);
        friend bool operator!=(const NumberWithUnits &num_1, const NumberWithUnits &num_2);
    };
}