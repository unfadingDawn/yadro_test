#include <iostream>

#include "TypeSort.h"

int main (int argc, char* argv[]) {
    const int delay = std::atoi(argv[1]);
    const int size_of_tape = std::atoi(argv[2]);
    auto input_type = Type::IntType("input_type.txt", delay);
    auto output_type = Type::IntType("output_type.txt", delay);
    auto sort = algo::TypeSort(input_type, output_type, size_of_tape);
    sort.sort();
}
