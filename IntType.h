#include "IType.h"
#include <string>
namespace Type{
    class IntType : public IType<int>{
        private:
            void spinToRight() override;
            void spinToLeft() override;
            int read() override;
            void write(int value) override;
        public:
            int pos;
            std::string path;
            IntType(const std::string& path): path(path), pos(0){};
    };
}
