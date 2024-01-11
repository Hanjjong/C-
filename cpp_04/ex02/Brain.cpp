#include "Brain.hpp"

Brain::Brain()
{
    std::cout << "Brain이 생성되었습니다." << std::endl;
    for (int i = 0; i < 100; i++)
		this->ideas[i] = "i'm brain...";
}

Brain::~Brain()
{
    std::cout << "Brain이 소멸되었습니다." << std::endl;
}

Brain::Brain(const Brain &origin)
{
    (*this) = origin;
    std::cout << "Brain이 생성되었습니다." << std::endl;
}

Brain &Brain::operator=(const Brain &obj)
{
    if(this != &obj)
    {
        for (int i = 0; i < 100; i++){
            this->ideas[i] = obj.ideas[i];
        }
    }
    return (*this);
}

const std::string &Brain::getIdea(int n) const
{
    return this->ideas[n];
}

void Brain::setIdeas(std::string idea, int n)
{
    this->ideas[n] = idea;
}
