#include "image.h"
#include "deque.hpp"
#include "coordinate.yiq25"
#include "problem.yiq25"
#include <iostream>

/*
 * https://www.youtube.com/watch?v=ZuHW4fS60pc&ab_channel=DavisMT
 */



int main(int argc, char *argv[]) {

    if (argc != 3) {
        throw std::logic_error("main(): Too many/few arguments");
    }
    Problem maze(argv[1],argv[2]);
    maze.go();
}
