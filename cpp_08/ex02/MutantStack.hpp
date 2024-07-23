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
        const_iterator cbegin(){
            return this->c.cbegin();
        }
        const_iterator cend(){
            return this->c.cend();
        }
        reverse_iterator rbegin(){
            return this->c.rbegin()
        }
        reverse_iterator cend(){
            return this->c.end();
        }
        const_reverse_iterator crbegin(){
            return this->c.crbegin;
        }
};

#endif
