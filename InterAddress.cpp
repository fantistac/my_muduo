#include "InterAddress.h"

InterAddress::InterAddress (uint16_t port, std::string ip ){
    memset(&addr_, '\0', sizeof(addr_));
    addr_.sin_family = AF_INET;
    addr_.sin_port = htons(port);
    addr_.sin_addr.s_addr = inet_addr(ip.c_str());
}


std::string InterAddress::toIp() const{
    char buf[64];
    memset(buf, '\0', sizeof(buf));
    inet_ntop(AF_INET, &addr_.sin_addr.s_addr, buf, sizeof(buf));
    return buf;
}


std::string InterAddress::toIpPort() const {
    char buf[64];
    memset(buf, '\0', sizeof(buf));
    inet_ntop(AF_INET, &addr_.sin_addr.s_addr, buf, sizeof(buf));
    size_t end = strlen(buf);
    uint16_t port = ntohs(addr_.sin_port);
    sprintf(buf + end, " : %u", port);
    return buf;
}


uint16_t InterAddress::toPort() const{
    return ntohs(addr_.sin_port);
}

// #include <iostream>

// int main(){
//     InterAddress addr(8080);
//     std::cout << addr.toPort() << std::endl;

//     return 0;
// }