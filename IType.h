#pragma once

namespace TypeInterface{
    class IType{
        public:
        virtual ~IType() = default;

        virtual void spinToRight() = 0;
        virtual void spinToLeft() = 0;
        virtual int read() = 0;
        virtual void write(int value) = 0;
    };
}
