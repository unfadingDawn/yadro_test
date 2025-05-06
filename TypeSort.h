#pragma once
#include "IntType.h"
#include <string>
#include <vector>
namespace algo{
    class TapeSort{
        private:
            Tape::IntTape input_type;
            Tape::IntTape output_type;
            int size_of_type;
            std::vector<std::string> paths_temp_types{};
        public:
            TapeSort(const Tape::IntTape &input_type, const Tape::IntTape &output_type, int size_of_type): input_type(input_type), output_type(output_type), size_of_type(size_of_type){};
            void sort(std::chrono::milliseconds delay);
            void insertNum(std::chrono::milliseconds delay);
      };
}