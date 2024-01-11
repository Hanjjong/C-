#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>

class Brain{
    private :
        std::string ideas[100];
    public :
        Brain();
        ~Brain();
        Brain(const Brain& origin);
        Brain& operator=(const Brain& obj);
        const std::string& getIdea(int n) const;
        void setIdeas(std::string idea, int n);

};


#endif