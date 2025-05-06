#pragma once

namespace Type{
    template <typename T>
    class IType{
        public:
            virtual void spinToRight() = 0;
            virtual void spinToLeft() = 0;
            virtual T read() = 0;
            virtual void write(T value) = 0;
        };
}
