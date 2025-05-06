#include "IType.h"
#include <string>
namespace Type{
    class IntType : public IType<int>{
        private:
            int pos;
            std::string path;
        public:
            void spinToRight() override;
            void spinToLeft() override;
            int read() override;
            void write(int value) override;
            IntType(const std::string& path): path(path), pos(0){};
    };
}
