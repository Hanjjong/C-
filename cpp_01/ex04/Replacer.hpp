#ifndef REPLACER_HPP
# define REPLACER_HPP

#include <iostream>
#include <fstream>
#include <sstream>

class Replacer{
    private :
        std::string filename;
        std::string s1;
        std::string s2;
        std::string readFileContent();
        void    writeOutfile(std::string content);
        

    public :
        Replacer(std::string filename, std::string s1, std::string s2);
        ~Replacer();
        void    replaceInFile();

};

#endif