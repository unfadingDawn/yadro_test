#pragma once
#include <chrono>

#include "IType.h"
#include <string>
namespace Type{
    class IntType final : public TypeInterface::IType{
        private:
            std::chrono::milliseconds delay;
            int pos;
            std::string path;
        public:
            void spinToRight() override;
            void spinToLeft() override;
            int read() override;
            void write(int value) override;
            [[nodiscard]] int getPos() const {return pos;}
            explicit IntType(const std::string& path, const std::chrono::milliseconds delay) : delay(delay), pos(0), path(path){}
            ~IntType() override = default;
    };
}
