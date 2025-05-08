//  Copyright 2025 Sowndaryan J, John Wesley Agojo
#include <iostream>
#include <stdexcept>
#include <algorithm>
#include "EDistance.hpp"

EDistance::EDistance(const std::string& s1, const std::string& s2) {
    auto is_valid_gene = [](char c) { return c == 'A' || c == 'T' || c == 'G' || c == 'C'; };
    if (!std::all_of(s1.begin(), s1.end(), is_valid_gene) ||
        !std::all_of(s2.begin(), s2.end(), is_valid_gene)) {
        std::cout << "Invalid gene sequence\n";
        exit(1);
    }
    
    gene[0] = s1 + "-";
    gene[1] = s2 + "-";
    
    size[0] = gene[0].size();
    size[1] = gene[1].size();
    
    ED.resize(size[0], std::vector<int>(size[1], 0));
}

int EDistance::min3(int a, int b, int c){
    int min = a;
    if(b <= min){
        min = b;
    }
    if(c <= min){
        min = c;
    }
    return min;
}

int EDistance::optDistance(){
    for(int i = size[0] - 1; i >= 0; i--){
        for(int j = size[1] - 1; j>= 0; j--){
            if((i == size[0] -1) && (j == size[1] - 1)){
                ED[i][j] = 0;
            } else if (i == size[0] - 1){
                ED[i][j] = ED[i][j+1] + 2;
            } else if (j == size[1] - 1){
                ED[i][j] = ED[i+1][j] + 2;
            } else {
                ED[i][j] = min3((ED[i+1][j+1] + penalty(gene[0][i], gene[1][j])), ED[i+1][j] + 2, ED[i][j+1] + 2);
            }
        }
    }
    
    return ED[0][0];
}

int EDistance::penalty(char a, char b){
    auto p = [](char c, char d){
        return (c == d) ? 0 : 1;
    };
    return p(a,b);
}

std::string EDistance::alignment() {
    std::string opt;
    int i = 0, j = 0;
    while (i < size[0] - 1 || j < size[1] - 1) {
        if (i < size[0] - 1 && j < size[1] - 1 && gene[0][i] == gene[1][j]) {
            opt += std::string(1, gene[0][i]) + " " + gene[1][j] + " 0\n";
            i++; j++;
        } else if (j < size[1] - 1 && (i == size[0] - 1 || ED[i][j] == ED[i][j+1] + 2)) {
            opt += "- " + std::string(1, gene[1][j]) + " 2\n";
            j++;
        } else if (i < size[0] - 1 && (j == size[1] - 1 || ED[i][j] == ED[i+1][j] + 2)) {
            opt += std::string(1, gene[0][i]) + " - 2\n";
            i++;
        } else {
            opt += std::string(1, gene[0][i]) + " " + gene[1][j] + " 1\n";
            i++; j++;
        }
    }
    std::cout<< opt;
    std::cout << "Edit distance is: " << ED[0][0] << std::endl;
    return opt;
}
