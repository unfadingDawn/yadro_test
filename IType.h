#pragma once

namespace Type{
    template <typename T>
    class IType{
        private:
            virtual void spinToRight() = 0;
            virtual void spinToLeft() = 0;
            virtual T read() = 0;
            virtual void write(T value) = 0;
        };
}
