//Copyright [2023]

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   Customers.h
 * Author: hloi
 *
 * Created on November 24, 2018, 9:05 PM
 */



#ifndef CUSTOMERS_H
#define CUSTOMERS_H
#include "Binary_Search_Tree.h"
#include "Customer.h"
#include <iostream>

using std::cout;
using std::endl;

template<typename Item_Type>
class Customers : public Binary_Search_Tree<Item_Type> {
public:

    Customers() : Binary_Search_Tree<Item_Type>() {
    }
    Customers(const Customers& orig) {}
    virtual ~Customers() {}
    // count-big-limits: BST Number -> Natural
    // consumes a binary search tree and a credit limit amount, produces the number of customers
    // who have a credit limit higher than the given amount
    int count_big_limits(double limit);

    int count_big_limits(double limit) const;


    bool any_over_limit();

    //implement the to_string method
    string to_string() const;

    // increase-limit: BST Natural Number -> BST
    // consumes a BST, a credit card number, and an amount of money. Function finds that
    // card number in the BST and changes that customer's credit limit, adding the amount of money
    // given to the limit. Function returns BST identical except for limit change
    Item_Type* increase_limit(string card_number, double limit_add);

    const Item_Type* find(const string& target) const;

private:
    // count-big-limits: BST Number -> Natural
    // consumes a binary search tree and a credit limit amount, produces the number of customers
    // who have a credit limit higher than the given amount
    int count_big_limits(const Binary_Tree<Item_Type>& the_tree, double limit);
    // check-limit: Number Number -> Natural
    // takes in a customer's credit limit and a given credit limit, returns 1 if the customers's
    // credit limit is higher than the given limit, 0 otherwise.
    int check_limit(Customer data, double limit);

    // any-over-limit?: BST -> Boolean
    // consumes a binary search tree and produces true if any customer in that tree has exceeded
    // their credit limit with their total purchases (charges)
    bool any_over_limit(const Binary_Tree<Item_Type>& the_tree);
    // sum-charges: ListOfCharge -> Number
    // consumes a ListOfCharge, produces the sum cost of those charges as a Number
    double sum_charges(list<Charge>::iterator begin,
            list<Charge>::iterator end);



};


template<typename Item_Type>
int Customers<Item_Type>::count_big_limits(double limit) {
    return count_big_limits(this->get_root(), limit);
}

template<typename Item_Type>
int Customers<Item_Type>::count_big_limits(const Binary_Tree<Item_Type>& the_tree, double limit) {
    if (the_tree.is_null()) {
        return 0;
    } else {
        int count = 0;
        if (check_limit(the_tree.get_data(), limit) == 1) {
            count++;
        }
        count += count_big_limits(the_tree.get_left_subtree(), limit);
        count += count_big_limits(the_tree.get_right_subtree(), limit);
        return count;
    }
}

template<typename Item_Type>
int Customers<Item_Type>::check_limit(Customer data, double limit) {
    if (data.GetLimit() > limit) {
        return 1;
    } else {
        return 0;
    }
}


template<typename Item_Type>
bool Customers<Item_Type>::any_over_limit() {
   //BTNode<Item_Type>* get_root() const {
    //        return root;
    //    }

    return any_over_limit(this->get_root());
}



template<typename Item_Type>
bool Customers<Item_Type>::any_over_limit(const Binary_Tree<Item_Type> &the_tree) {
    if (the_tree.is_null()) {
        return false;
    }

    Customer yummy = the_tree.get_data();
    double limit = yummy.GetLimit();
    double totalCost = sum_charges(yummy.GetChargesBegin(), yummy.GetChargesEnd());

    if (totalCost > limit) {
        return true;
    } else {
        return any_over_limit(the_tree.get_left_subtree()) || any_over_limit(the_tree.get_right_subtree());
    }

}


template<typename Item_Type>
double Customers<Item_Type>::sum_charges(list<Charge>::iterator begin,
                                         list<Charge>::iterator end) {
    if (begin == end) {
        return 0; // Return 0 if the list is empty
    } else {
        auto next = begin;
        ++next;
        double totalCost = begin->GetAmount() + sum_charges(next, end);
        return totalCost;
    }
}

template<typename Item_Type>
Item_Type* Customers<Item_Type>::increase_limit(string card_number, double limit_add) {

    Item_Type* customer = const_cast<Item_Type*> (find(card_number));


    if (customer == NULL) {
        return NULL;
    } else {
        customer->SetLimit(customer->GetLimit() + limit_add);
        return customer;
    }


}

template<typename Item_Type>
const Item_Type* Customers<Item_Type>::find(const string& target) const {
    Customer one;
    one.SetCard_number(target);

    return Binary_Search_Tree<Item_Type>::find(one);
}

template<typename Item_Type>
string Customers<Item_Type>::to_string() const {
    std::ostringstream os;
    os << "Customers: " << endl;
    os << Binary_Search_Tree<Item_Type>::to_string();
    return os.str();
}

template<typename Item_Type>
int Customers<Item_Type>::count_big_limits(double limit) const {
    return count_big_limits(this->root, limit);
}








#endif /* CUSTOMERS_H */

