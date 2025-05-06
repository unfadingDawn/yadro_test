#include "TypeSort.h"

int main () {
    const Type::IntType input_type = Type::IntType("input_type.txt");
    Type::IntType output_type = Type::IntType("output_type.txt");
    algo::TypeSort sort = algo::TypeSort(input_type, output_type, 10);
    sort.sort();
}