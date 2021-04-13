#include "doctest.h"
#include "NumberWithUnits.hpp"
using namespace ariel;
#include <iostream>
#include <cstdio>
#include <string>
#include <unistd.h>
#include <fstream>
#include <sstream>
using namespace std;

const float zero = 0, one = 1, two = 2, ten = 10, hundred = 100, thousand = 1000;

TEST_CASE("Operators")
{
    char filename[] = "unit.txt";
    ofstream units_f(filename);
    units_f << "1 km = 1000 m\n1 m = 100 cm\n1 kg = 1000 g\n1 ton = 1000 kg\n1 hour = 60 min\n1 min = 60 sec\n1 USD = 3.33 ILS";
    units_f.close();
    ifstream units_file{"unit.txt"};
    NumberWithUnits::read_units(units_file);
    NumberWithUnits a{ten, "kg"};
    NumberWithUnits b{ten, "m"};
    NumberWithUnits c{ten, "min"};

    /* Operators: ==, !=, >=, <=, <, > */
    CHECK(a == NumberWithUnits{ten, "kg"});
    CHECK(a == NumberWithUnits{ten * thousand, "g"});
    CHECK(a == NumberWithUnits{one / hundred, "ton"});
    CHECK(a <= NumberWithUnits{ten, "kg"} + one);
    CHECK(a < NumberWithUnits{ten, "kg"} + one);
    CHECK(a >= NumberWithUnits{thousand, "g"});
    CHECK(a > NumberWithUnits{one / thousand, "ton"});
    CHECK(b == NumberWithUnits{ten, "m"});
    CHECK(b == NumberWithUnits{thousand, "cm"});
    CHECK(b == NumberWithUnits{one / hundred, "km"});
    CHECK(c <= NumberWithUnits{ten, "min"} + one);
    CHECK(c < NumberWithUnits{ten, "min"} + one);
    CHECK(b < (b + NumberWithUnits{one, "cm"}));
    CHECK(b < NumberWithUnits{one / ten, "km"});

    /* Operators: +=, -=, *=, ++, --, *, -, +  */
    a += a;
    b += b;
    c += c;
    CHECK(a == NumberWithUnits{ten + ten, "kg"});
    CHECK(b == NumberWithUnits{ten + ten, "m"});
    CHECK(c == NumberWithUnits{ten + ten, "min"});

    a -= NumberWithUnits{ten, "kg"};
    b -= NumberWithUnits{ten, "m"};
    c -= NumberWithUnits{ten, "min"};
    CHECK(a == NumberWithUnits{ten, "kg"});
    CHECK(b == NumberWithUnits{ten, "m"});
    CHECK(c == NumberWithUnits{ten, "min"});

    a *= two;
    b *= two;
    c *= two;
    CHECK(a == NumberWithUnits{ten + ten, "kg"});
    CHECK(b == NumberWithUnits{ten + ten, "m"});
    CHECK(c == NumberWithUnits{ten + ten, "min"});

    a = a - NumberWithUnits{ten, "kg"};
    b = b - NumberWithUnits{ten, "m"};
    c = c - NumberWithUnits{ten, "min"};
    CHECK(a == NumberWithUnits{ten, "kg"});
    CHECK(b == NumberWithUnits{ten, "m"});
    CHECK(c == NumberWithUnits{ten, "min"});

    a = a + a;
    b = b + b;
    c = c + c;
    CHECK(a == NumberWithUnits{ten + ten, "kg"});
    CHECK(b == NumberWithUnits{ten + ten, "m"});
    CHECK(c == NumberWithUnits{ten + ten, "min"});

    a++;
    b++;
    c++;
    CHECK(a == NumberWithUnits{ten + ten + one, "kg"});
    CHECK(b == NumberWithUnits{ten + ten + one, "m"});
    CHECK(c == NumberWithUnits{ten + ten + one, "min"});

    a--;
    b--;
    c--;
    CHECK(a == NumberWithUnits{ten + ten, "kg"});
    CHECK(b == NumberWithUnits{ten + ten, "m"});
    CHECK(c == NumberWithUnits{ten + ten, "min"});

    a = a * two;
    b = two * b;
    c = c * two;
    CHECK(a == NumberWithUnits{two * (ten + ten), "kg"});
    CHECK(b == NumberWithUnits{two * (ten + ten), "m"});
    CHECK(c == NumberWithUnits{two * (ten + ten), "min"});

    /* delete the file */
    if (remove(filename) != zero)
    {
        perror("File deletion failed");
    }
    else
    {
        cout << "File deleted successfully";
    }
}