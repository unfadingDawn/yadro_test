#include <iostream>
#include <chrono>

#include "TypeSort.h"

int main (int argc, char* argv[]) {
    const auto delay = std::chrono::milliseconds(std::atoi(argv[1]));
    const int size_of_tape = std::atoi(argv[2]);
    std::string input_path;
    std::string output_path;
    std::cout << "Write name of input tape: ";
    std::cin >> input_path;
    std::cout << "Write name of output tape: ";
    std::cin >> output_path;
    auto input_type = Tape::IntTape(input_path, delay);
    auto output_type = Tape::IntTape(output_path, delay);
    auto sort = algo::TapeSort(input_type, output_type, size_of_tape);
    sort.sort(delay);
}
