#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>

template <typename T>
class MutantStack : public std::stack<T> {
    // private:
    //     typedef typename MutantStack<T>::container_type type;
    public : 
        MutantStack(){}
        ~MutantStack(){}
        MutantStack(const MutantStack& origin) : std::stack<T>(origin) {}
        MutantStack& operator=(const MutantStack& obj){
            if (this != &obj) {
                std::stack<T>::operator=(obj);
            }
            return *this;
        }
        typedef typename MutantStack<T>::container_type::iterator               iterator;
        typedef typename MutantStack<T>::container_type::const_iterator         const_iterator;
        typedef typename MutantStack<T>::container_type::reverse_iterator       reverse_iterator;
        typedef typename MutantStack<T>::container_type::const_reverse_iterator const_reverse_iterator;
        iterator begin(){
            return this->c.begin();
        };
        iterator end(){
            return this->c.end();
        };
        const_iterator cbegin() const {
            return this->c.begin();
        };
        const_iterator cend() const{
            return this->c.end();
        };
        reverse_iterator rbegin(){
            return this->c.rbegin();
        };
        reverse_iterator rend(){
            return this->c.rend();
        };
        const_reverse_iterator crbegin() const {
            return this->c.rbegin();
        };
        const_reverse_iterator crend() const {
            return this->c.rend();
        };
};

#endif
