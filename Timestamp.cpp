#include "Timestamp.h"


Timestamp::Timestamp() : timeseconds_(0){}

Timestamp::Timestamp(int64_t timeseconds) : timeseconds_(timeseconds){}

Timestamp Timestamp::now(){
    return Timestamp(time(nullptr));
}


std::string Timestamp::ToString() const{
    char buf[128] = {0};
     tm *tm_time = localtime(&timeseconds_);
    snprintf(buf, 128, "%4d/%02d/%02d %02d:%02d:%02d", 
        tm_time->tm_year + 1900,
        tm_time->tm_mon + 1,
        tm_time->tm_mday,
        tm_time->tm_hour,
        tm_time->tm_min,
        tm_time->tm_sec);
    return buf;
}

// #include <iostream>
// int main()
// {
//     std::cout << Timestamp::now().ToString() << std::endl; 
//     return 0;
// }