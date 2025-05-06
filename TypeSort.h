#pragma once
#include "IntType.h"
#include <string>
#include <vector>
namespace algo{
    class TypeSort{
        private:
            Type::IntType input_type;
            Type::IntType output_type;
            int size_of_type;
            std::vector<std::string> paths_temp_types{};
        public:
            TypeSort(const Type::IntType &input_type, const Type::IntType &output_type, int size_of_type): input_type(input_type), output_type(output_type), size_of_type(size_of_type){};
            void sort(std::chrono::milliseconds delay);
            void insertNum(std::chrono::milliseconds delay);
      };
}