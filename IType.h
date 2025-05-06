#pragma once

namespace TapeInterface{
    class ITape{
        public:
        virtual ~ITape() = default;

        virtual void spinToRight() = 0;
        virtual void spinToLeft() = 0;
        virtual int read() = 0;
        virtual void write(int value) = 0;
    };
}
