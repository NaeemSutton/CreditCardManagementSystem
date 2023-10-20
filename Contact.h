#ifndef CONTACT_H
#define CONTACT_H

#include <string>
#include <list>
#include "Charge.h"
#include <sstream>
#include <iostream>

//Copyright [2023]

using std::list;
using std::string;

class Contact {
public:
    // default constructor
    Contact();
    // non default constructor
    Contact(string name, string address, string email);
    // copy constructor
    Contact(const Contact& orig);
    virtual ~Contact();        
    void setEmail(string email);
    string getEmail() const;
    void setAddress(string address);
    string getAddress() const;
    void setName(string name);
    string getName() const;
    friend std::ostream& operator<<(std::ostream& out, 
                           const Contact& contact);
private:    
    string name;
    string address;
    string email;    
};

Contact::Contact() {
    name = "";
    address = "";
    email = "";
}

Contact::Contact(string name, string address, string email) {
    this->name = name;
    this->address = address;
    this->email = email;
}

Contact::Contact(const Contact& orig) {
    this->name = orig.name;
    this->address = orig.address;
    this->email = orig.email;
}

Contact::~Contact() {
}

void Contact::setEmail(string email) {
    this->email = email;
}

string Contact::getEmail() const {
    return email;
}

void Contact::setAddress(string address) {
    this->address = address;
}

string Contact::getAddress() const {
    return address;
}

void Contact::setName(string name) {
    this->name = name;
}

string Contact::getName() const {
    return name;
}

std::ostream& operator<<(std::ostream& out,
                           const Contact& contact) {
    out << contact.name << " " << contact.address << " " << contact.email;
    return out;
}





#endif /* CONTACT_H */

