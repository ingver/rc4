#ifndef RC4_H
#define RC4_H

#include <algorithm>
#include <iostream>
#include <string>

class RC4 {

private:
    const size_t block_size;

    std::string s;
    std::string key;

    size_t idx_i, idx_j; // indeces


    char prnd();
    void init_s();

public:
    RC4(const std::string& k);

    std::string proc(const std::string& text);
    void proc(std::istream& in, std::ostream& out);
};

#endif
