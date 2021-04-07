#include <iostream>
#include "NumberWithUnits.hpp"

using namespace std;

namespace ariel
{

        // static void read_units(ifstream &units_file);
        ostream &operator<<(ostream &out, const NumberWithUnits &t){
            out << t._n << "["+t._s+"]";
            return out;
        }
        // istream &operator>>(istream &in, NumberWithUnits &t){
        //     in >> t;
        //     return in;
        // }
        NumberWithUnits operator+=(NumberWithUnits &num_1, const NumberWithUnits &num_2){
            num_1 = num_1 + num_2;
            return num_1;
        }
        NumberWithUnits operator-=(NumberWithUnits &num_1, const NumberWithUnits &num_2){
                        num_1 = num_1 - num_2;
            return num_1;
        }
        // friend NumberWithUnits operator++(NumberWithUnits &num);
        // friend NumberWithUnits operator++(NumberWithUnits &num, int);
        // friend NumberWithUnits operator--(NumberWithUnits &num);
        // friend NumberWithUnits operator--(NumberWithUnits &num, int);
        // friend NumberWithUnits operator*=(NumberWithUnits &num, float n);
        // friend NumberWithUnits operator*=(float n, NumberWithUnits &num);
        // friend const NumberWithUnits operator*(NumberWithUnits &num, float n);
        // friend const NumberWithUnits operator*(float n, NumberWithUnits &num);
        // friend const NumberWithUnits operator-(const NumberWithUnits &num_1, const NumberWithUnits &num_2);
        // friend const NumberWithUnits operator-(const NumberWithUnits &num);
        // friend const NumberWithUnits operator+(const NumberWithUnits &nun_1, const NumberWithUnits &num_2);
        // friend const NumberWithUnits operator+(const NumberWithUnits &num, float n);
        // friend bool operator>(const NumberWithUnits &num_1, const NumberWithUnits &num_2);
        // friend bool operator>=(const NumberWithUnits &num_1, const NumberWithUnits &num_2);
        // friend bool operator<(const NumberWithUnits &num_1, const NumberWithUnits &num_2);
        // friend bool operator<=(const NumberWithUnits &num_1, const NumberWithUnits &num_2);
        // friend bool operator==(const NumberWithUnits &num_1, const NumberWithUnits &num_2);
        // friend bool operator!=(const NumberWithUnits &num_1, const NumberWithUnits &num_2);

}