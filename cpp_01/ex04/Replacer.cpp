#include "Replacer.hpp"

Replacer::Replacer(std::string filename, std::string s1, std::string s2)
{
    this->filename = filename;
    this->s1 = s1;
    this->s2 = s2;
}

Replacer::~Replacer()
{}

std::string Replacer::readFileContent(int *error)
{
    std::ifstream inputFile(filename.c_str());
    if(!inputFile.is_open())
    {
        std::cerr << "file open Error" << std::endl;
        *error = 1;
        return "";
    }

    std::ostringstream fileContent;
    fileContent << inputFile.rdbuf();
    inputFile.close();

    return fileContent.str();
}

void    Replacer::writeOutfile(std::string content)
{
    filename = filename.append(".replace");
    std::ofstream outputFile(filename.c_str());
    if (!outputFile.is_open()){
        std::cerr << "Error\n";
        return ;
    }
    outputFile << content;
    outputFile.close();
}


void    Replacer::replaceInFile()
{
    int error = 0;
    std::string content = readFileContent(&error);

    if (error == 1)
        return ;
    size_t found = content.find(s1);
    //s1을 찾지 못하면 엄청나게 큰 수를 반환하는데, 아래 조건으로 검사하면 된다.
    while (found != std::string::npos)
    {
        content.erase(found, s1.length());
        content.insert(found, s2);
        found = content.find(s1, found + s2.length());
    }
    writeOutfile(content);
}
