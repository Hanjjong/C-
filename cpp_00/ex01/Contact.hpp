#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <cctype>

class Contact
{
private:
  std::string firstname;
  std::string lastname;
  std::string nickname;
  std::string p_number;
  std::string secret;
  std::string onlytenlength(std::string str);
  void  setContact(std::string firstname, std::string lastname, std::string nickname, std::string p_number, std::string secret);
public:
    Contact();
    ~Contact();
    void  print_contact();
    void  show_contact();
    void  addcontact();
};

int is_space(const char *str);

#endif