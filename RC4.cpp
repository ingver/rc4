#include "RC4.h"

RC4::RC4(const std::string& k)
    : block_size(256),
      s(std::string("", block_size)),
      key(k),
      idx_i(0), idx_j(0)
{
    init_s();
}

void RC4::init_s()
{
    // initialize s-block
    for (size_t i = 0; i < block_size; ++i) {
        s[i] = char(i);
    }

    size_t j = 0;
    for (size_t i = 0; i < block_size; ++i) {
        j = (j + s[i] + key[i % key.length()]) % block_size;
        std::swap(s[i], s[j]);
    }

    idx_i = idx_j = 0;
}

char RC4::prnd()
{
    idx_i = (idx_i + 1) % block_size;
    idx_j = (idx_j + s[idx_i]) % block_size;

    std::swap(s[idx_i], s[idx_j]);

    return (s[idx_i] + s[idx_j]) % block_size;
}

std::string RC4::proc(const std::string& text)
{
    std::string ciphered;

    for(size_t i = 0; i < text.length(); ++i) {
        ciphered += text[i] ^ prnd();
    }

    init_s();

    return ciphered;
}

void RC4::proc(std::istream& in, std::ostream& out)
{
    int c = 0;

    while(!in.eof()) {
        c = in.get();
        out << (char)(c ^ prnd());
    }

    init_s();
}
