#include "date.hpp"


void Date::init(int dd, int mm, int yy)
{ d = dd; m = mm; y = yy; }

void Date::add_year(int n){
    y = y + n;
}

void Date::add_month(int n){
    int months_left = 12 - m;
    if( n > months_left ){
        Date::add_year( n / 12 );
        Date::add_month( n % 12 );
    } else {
        m = m + n;
    }
}

void Date::add_day(int n){
    int days_left = 30 - d;
    if( n > days_left ){
        Date::add_month( n / 30 );
        Date::add_day( n % 30 );
    } else {
        d = d + n;
    }
}
void Date::to_str(){
    std::stringstream ss;
    ss << m << "-" << d << "-" << y;
    std::cout << ss.str() << std::endl;
}