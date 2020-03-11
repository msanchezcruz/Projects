#include <iostream>

using namespace std;

struct Location{


     //public:
        double longitude;
        double latitude;
        string name;
        string address;
        string city;
        long int postalCode;
        string province;
        int priceRangeMin;
        int priceRangeMax;


    Location();
    ~Location();

};
Location::Location()
{

}
Location::~Location()
{

}