#include <iostream>
#include "bigint.hpp"

int main() {
   std::string s(10000, '9'); // 10.000 tane 9
bigint big(s);
bigint one("1");
std::cout << (big + one); // 1 ve yanına 10.000 tane 0 basmalı
}
