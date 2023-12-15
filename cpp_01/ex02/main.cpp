#include <iostream>

int main()
{
    std::string str = "HI THIS IS BRAIN";
    std::string *stringPTR = &str;
    //stringPTR의 값에 str의 주소
    //포인터는 다른 포인터 변수를 참조할수 있다.
    //메모리 주소를 참조하고 있으므로 역참조가 가능하고, 포인터의 산술이 가능하다.
    //null이 가능

    std::string &stringREF = str;
    //stringREF의 주소에 str의 값
    //레퍼런스는 str변수에 대한 별칭이라고 할수 있다. 
    //레퍼런스 변수의 초기화는 선언과 동시에 이루어져야하며, 한번 초기화된 레퍼런스는 다른 변수를 참조할 수 없다.
    //또한 레퍼런스는 null 값을 가질수 없다.
    //레퍼런스가 변경되면 원래의 변수의 값도 변경된다.
    //레퍼런스가 함수의 매개변수로 전달되면, 값이 복사되지 않고 원래의 변수를 참조된다.

    std::cout << "stringPTR address : " <<  stringPTR <<std::endl;
    std::cout << "stringREF address : " << &stringREF <<std::endl;

    std::cout << "stringPTR value : " <<  *stringPTR <<std::endl;
    std::cout << "stringREF value : " << stringREF <<std::endl;

    return (0);
}