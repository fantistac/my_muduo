#pragma once
#include <iostream>
#include <time.h>


class Timestamp{
public:
    Timestamp();
    explicit Timestamp(int64_t);
    static Timestamp now();
    std::string ToString() const;

private:
    int64_t timeseconds_;
};