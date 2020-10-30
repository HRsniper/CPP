#include <iostream>

namespace Npc1
{
    int num{50};

    class A
    {
    public:
        void imp()
        {
            std::cout << "ClassA de Npc1 \n";
        }
        
    };
} // namespace Npc1

namespace Npc2
{
    int num{40};

    class A
    {
    public:
        void imp()
        {
            std::cout << "ClassA de Npc2 \n";
        }

} // namespace Npc2


int main(int argc, char const *argv[])
{
    std::cout << "hello word" << std::endl;//esplicitando uso do std da iostream em vez de usar using namespace std; , metodo acomseplhado

    std::cout << Npc1::num << std::endl;//50

    std::cout << Npc2::num << std::endl;//40

    Npc1::A class1a;//classe A de Npc1
    Npc2::A class2a;//classe A de Npc2

    class1a.imp();
    class2a.imp();

    return 0;
}
