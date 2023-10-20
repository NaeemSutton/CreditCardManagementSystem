//Copyright [2023]

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Customer.h
 * Author: hloi
 *
 * Created on November 24, 2018, 2:13 PM
 */




#ifndef CUSTOMER_H
#define CUSTOMER_H
#include "Charge.h"
#include "Contact.h"

class Customer {
public:
    Customer();
    // non-default constructor
    Customer(string ccn, Contact& contact, double limit, list<Charge> charges);
    //copy constructor
    Customer(const Customer& orig);
    virtual ~Customer();
    void SetCharges(list<Charge> charges);
    list<Charge> GetCharges() const;
    void SetLimit(double limit);
    double GetLimit() const;
    void SetContact(Contact& contact);
    Contact GetContact() const;
    void SetCard_number(string card_number);
    string GetCard_number() const;

    list<Charge> GetCharges() {
        return charges;
    }

    list<Charge>::iterator GetChargesBegin() {
        return charges.begin();
    }

    list<Charge>::iterator GetChargesEnd() {
        return charges.end();
    }

    //implement the to_string method
    string to_string() const;

    
    bool operator<(const Customer& other) const;
    
    void push_back(Charge c);
    
    friend std::ostream& operator<<(std::ostream& out, 
                           const Customer& customer);
    
private:
    string card_number;
    Contact contact;
    double limit;
    list<Charge> charges;
};


Customer::Customer()
        : card_number(""), contact(), limit(0.0), charges() {}

Customer::Customer(std::string ccn, Contact &contact, double limit, std::list<Charge> charges)
        : card_number(ccn), contact(contact), limit(limit), charges(charges) {}

Customer::Customer(const Customer &orig)
        : card_number(orig.card_number), contact(orig.contact), limit(orig.limit), charges(orig.charges) {}


Customer::~Customer() {
}

void Customer::SetCharges(list<Charge> charges) {
    this->charges = charges;
}

list<Charge> Customer::GetCharges() const {
    return charges;
}

void Customer::SetLimit(double limit) {
    this->limit = limit;
}

double Customer::GetLimit() const {
    return limit;
}

void Customer::SetContact(Contact& contact) {
    this->contact = contact;
}

Contact Customer::GetContact() const {
    return contact;
}

void Customer::SetCard_number(string card_number) {
    this->card_number = card_number;
}

string Customer::GetCard_number() const {
    return card_number;
}

bool Customer::operator<(const Customer& other) const {
    return this->card_number < other.card_number;
}

void Customer::push_back(Charge c) {
    charges.push_back(c);
}

std::ostream& operator<<(std::ostream& out,
                           const Customer& customer) {
    out << customer.card_number << " " << customer.contact << " " << customer.limit;
    return out;
}

#endif /* CUSTOMER_H */
