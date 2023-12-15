#include <iostream>

int main(int argc, char *argv[])
{
    if (argc == 1)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
    }
    for (int i = 1; i < argc; i++)
    {
        std::string str = argv[i];
        for (int j = 0; j < str.length(); j++)
        {
            char ch = std::toupper(argv[i][j]);
            std::cout << ch;
        }
        std::cout << " ";
    }
    std::cout << std::endl;
}