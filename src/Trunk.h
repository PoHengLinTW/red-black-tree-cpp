#ifndef TRUNK__H
#define TRUNK__H
#include <string>
#include <memory>
#include <iostream>

struct Trunk {
    std::shared_ptr<Trunk> prev;
    std::string str;
 
    Trunk(std::shared_ptr<Trunk> prev, std::string str) {
        this->prev = prev;
        this->str = str;
    }

    static void showTrunk(std::shared_ptr<Trunk> trunk) {
        if (trunk == nullptr)
            return ;
        showTrunk(trunk->prev);
        std::cout << trunk->str;
    }
};
 

#endif