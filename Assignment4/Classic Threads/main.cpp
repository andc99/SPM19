// @Authors Alessi Carlo, Corbucci Luca

#include <unistd.h>
#include <iostream>
#include <type_traits>
#include <typeinfo>
#include <utility>
#include <vector>
#include "./MapReduce.h"

template <typename T>
std::pair<T, int> count_numbers_map(T item) {
    return std::make_pair(item, 1);
}

int main(int argc, char* argv[]) {
    int nw_mapper = atoi(argv[1]);
    int nw_reducer = atoi(argv[2]);

    std::vector<std::string> data = {"ciao", "mondo", "roma", "lazio", "italia", "lex", "ciao", "italia", "roma"};
    //std::vector<double> data = {4.0, 5.1, 6.0, 2, 0, 5.1, 4.0};

    for (auto i : data)
        std::cout << i << " ";
    std::cout << std::endl;

    MapReduce<std::string> mr(nw_mapper, nw_reducer);
    mr.map_and_reduce(data, count_numbers_map<std::string>);
    mr.print_results();

    return 0;
}