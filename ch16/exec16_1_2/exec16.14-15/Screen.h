#pragma once
 
#include <vector>
#include <string>
#include <iostream>

template <std::size_t H, std::size_t W> class Screen;
template <std::size_t H, std::size_t W> std::ostream& operator << (std::ostream& os, const Screen<H, W>& scn);

template <std::size_t H, std::size_t W>
class Screen {

    friend std::ostream& operator << <H, W> (std::ostream& os, const Screen<H, W>& scn);

    typedef std::size_t size_t;
    typedef std::string contentType;
    typedef contentType::value_type elemType;
public:
    Screen(elemType c) : height(H), width(W), contents(height * width, c) {}
    void set(size_t h, size_t w, elemType c) {
        check(h * width + w, "pos out of Screen, both h and w is begin from 0");
        contents[h * width + w] = c;
    }
private:
    void check(size_t pos, const std::string &msg) {
        if (pos >= contents.size())
        {
            throw std::out_of_range(msg);
        }
    }
    size_t height, width;
    contentType contents;
};

template <std::size_t H, std::size_t W>
std::ostream& operator << <H,W> (std::ostream& os, const Screen<H, W>& scn) {
    os << "============SCREEN OUT ("<< scn.width << "," << scn.height <<") ============\n";
    for (std::size_t i = 0; i < scn.height; ++i) {
        for (std::size_t j = 0; j < scn.width; ++j) {
            os << scn.contents[i * scn.width + j];
        }
        os << "\n";
    }
    os << "============SCREEN END============";
    return os;
}
