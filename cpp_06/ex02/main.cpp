#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base *generate(void)
{ 
    srand(static_cast<unsigned int>(time(nullptr)));
    int random = rand() % 3;
    switch (random)
    {
        case 0:
            return new A();
        case 1:
            return new B();
        case 2:
            return new C();
        default:
            return nullptr;;
    }
    
}

void identify(Base *p)
{
    if (dynamic_cast<A*>(p)){
        std::cout << "A" << std::endl;
    }
    else if (dynamic_cast<B*>(p)){
        std::cout << "B" << std::endl;
    }
    else if (dynamic_cast<C*>(p)){
        std::cout << "C" << std::endl;
    }
}

void identify(Base &p)
{
    try{
        (void)dynamic_cast<A&>(p);
        std::cout << "A" << std::endl;
    }
    catch(std::bad_cast&) {
        std::cout << "A 아니에요~" << std::endl;
    }
    try{
        (void)dynamic_cast<B&>(p);
        std::cout << "B" << std::endl;
    }
    catch(std::bad_cast&) {
                std::cout << "B 아니에요~" << std::endl;

    }
    try{
        (void)dynamic_cast<C&>(p);
        std::cout << "C" << std::endl;
    }
    catch(std::bad_cast&) {
                std::cout << "C 아니에요~" << std::endl;

    }
}
int main(){
    Base* randomBase = generate();
    identify(randomBase);
    identify(*randomBase);
}