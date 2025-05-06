#include "TypeSort.h"
#include <iostream>
namespace algo{
    void TypeSort::insertNum(std::chrono::milliseconds delay){
        Type::IntType curr_num("tmp/curr_num.txt", delay);
        Type::IntType curr_pos_on_input = Type::IntType("tmp/curr_pos_on_input.txt", delay);
        Type::IntType curr_pos_on_output = Type::IntType("tmp/curr_pos_on_output.txt", delay);
        Type::IntType next_buffer = Type::IntType("tmp/next_num_buffer.txt", delay);
        if(curr_num.read() > output_type.read()){
            output_type.spinToRight();
            curr_pos_on_output.write(curr_pos_on_output.read() + 1);
            output_type.write(curr_num.read());
        }
        else{
            while(curr_pos_on_output.read() != 0){
                output_type.spinToLeft();
                curr_pos_on_output.write(curr_pos_on_output.read() - 1);
                if(curr_num.read() > output_type.read()){
                    output_type.spinToRight();
                    curr_pos_on_output.write(curr_pos_on_output.read() + 1);
                    break;
                }
            }
            while(curr_pos_on_output.read() < curr_pos_on_input.read()){
                next_buffer.write(output_type.read());
                output_type.write(curr_num.read());
                curr_num.write(next_buffer.read());
                output_type.spinToRight();
                curr_pos_on_output.write(curr_pos_on_output.read() + 1);
            }
            output_type.write(curr_num.read());
        }
    }
    void TypeSort::sort(std::chrono::milliseconds delay){
        Type::IntType curr_pos_on_input = Type::IntType("tmp/curr_pos_on_input.txt", delay);
        Type::IntType curr_pos_on_output = Type::IntType("tmp/curr_pos_on_output.txt", delay);
        curr_pos_on_input.write(0);
        curr_pos_on_output.write(0);
        output_type.write(input_type.read());
        input_type.spinToRight();
        curr_pos_on_input.write(curr_pos_on_input.read() + 1);
        while(curr_pos_on_input.read() < size_of_type - 1){
            Type::IntType curr_num("tmp/curr_num.txt", delay);
            curr_num.write(input_type.read());
            insertNum(delay);
            input_type.spinToRight();
            curr_pos_on_input.write(curr_pos_on_input.read() + 1);
        }
        Type::IntType curr_num("tmp/curr_num.txt", delay);
        curr_num.write(input_type.read());
        insertNum(delay);
    }
}