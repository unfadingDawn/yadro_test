#pragma once
#include <chrono>

#include "IType.h"
#include <string>
namespace Tape{
    class IntTape final : public TapeInterface::ITape{
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
            explicit IntTape(const std::string& path, const std::chrono::milliseconds delay) : delay(delay), pos(0), path(path){}
            ~IntTape() override = default;
    };
}
