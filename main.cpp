//  Copyright 2025 Sowndaryan Jayaprakash, John Wesley Agojo
#include "EDistance.hpp"

int main(int argc, char*argv[]){
    sf::Clock clock;
    sf::Time time;

    std::string s1;
    std::string s2;

    if(argc > 2){
        s1 = argv[1];
        s2 = argv[2];
    } else {
        std::cin >> s1;
        std::cin >> s2;
    }
    EDistance dna(s1, s2);

    dna.optDistance();
    dna.alignment();

    time = clock.getElapsedTime();
    std::cout << "Total time: " << time.asSeconds() << " seconds \n";
    return 0;

}