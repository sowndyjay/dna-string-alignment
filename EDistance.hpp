//  Copyright 2025 Sowndaryan J, John Wesley 
#ifndef EDISTANCE_HPP
#define EDISTANCE_HPP
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

class EDistance {
 public:
    EDistance(const std::string& s1, const std::string& s2);

    static int penalty(char a, char b);
    static int min3(int a, int b, int c);

    int optDistance();
    std::string alignment();
 private:
   std::vector<std::vector<int>> ED;
   std::string gene[2];
   int size[2];

};

#endif
