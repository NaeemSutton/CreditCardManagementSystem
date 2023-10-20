#ifndef NEWCXXTEST_H
#define NEWCXXTEST_H

#include <cxxtest/TestSuite.h>
//Include your classes header file(s) below and uncomment.

#include "Binary_Search_Tree.h"
#include "Customer.h"
#include "Contact.h"
#include "Charge.h"
#include "Customers.h"



class newCxxTest : public CxxTest::TestSuite {
public:



    // Test case for the default constructor
    void testDefaultConstructor() {
        Charge charge;

        TS_ASSERT_EQUALS(charge.GetBusiness(), "");
        TS_ASSERT_EQUALS(charge.GetAmount(), 0.0);
    }

    // Test case for the parameterized constructor
    void testParameterizedConstructor() {
        Charge charge("Example Business", 50.0);

        TS_ASSERT_EQUALS(charge.GetBusiness(), "Example Business");
        TS_ASSERT_EQUALS(charge.GetAmount(), 50.0);
    }

    // Test case for the copy constructor
    void testCopyConstructor() {
        Charge original("Original Business", 75.0);
        Charge copy(original);

        TS_ASSERT_EQUALS(copy.GetBusiness(), original.GetBusiness());
        TS_ASSERT_EQUALS(copy.GetAmount(), original.GetAmount());
    }

    // Test case for the default constructor
    void testDefaultConstructor_UniqueName() {
        Contact contact;

        TS_ASSERT_EQUALS(contact.getName(), "");
        TS_ASSERT_EQUALS(contact.getAddress(), "");
        TS_ASSERT_EQUALS(contact.getEmail(), "");
    }

    // Test case for the parameterized constructor
    void testParameterizedConstructor_UniqueName() {
        Contact contact("Alice Adams", "123 Elm St", "alice@example.com");

        TS_ASSERT_EQUALS(contact.getName(), "Alice Adams");
        TS_ASSERT_EQUALS(contact.getAddress(), "123 Elm St");
        TS_ASSERT_EQUALS(contact.getEmail(), "alice@example.com");
    }

    // Test case for the setEmail and getEmail functions
    void testSetAndGetEmail_UniqueName() {
        Contact contact("Bob Brown", "456 Oak St", "bob@example.com");
        contact.setEmail("newemail@example.com");

        TS_ASSERT_EQUALS(contact.getEmail(), "newemail@example.com");
    }

    // Test case for the setAddress and getAddress functions
    void testSetAndGetAddress_UniqueName() {
        Contact contact("Carol Clark", "789 Pine St", "carol@example.com");
        contact.setAddress("new address");

        TS_ASSERT_EQUALS(contact.getAddress(), "new address");
    }

    // Test case for the setName and getName functions
    void testSetAndGetName_UniqueName() {
        Contact contact("David Davis", "321 Cedar St", "david@example.com");
        contact.setName("new name");

        TS_ASSERT_EQUALS(contact.getName(), "new name");
    }

    // Test case for the operator<< overload
    void testOutputOperator_UniqueName() {
        Contact contact("Eva Evans", "654 Maple St", "eva@example.com");

        std::ostringstream oss;
        oss << contact;

        TS_ASSERT_EQUALS(oss.str(), "Eva Evans 654 Maple St eva@example.com");
    }

    // Test case for the SetLimit and GetLimit functions
    void testSetAndGetLimit() {
        Customer customer;
        customer.SetLimit(1000.0);

        TS_ASSERT_EQUALS(customer.GetLimit(), 1000.0);
    }

    // Test case for the SetContact and GetContact functions
    void testSetAndGetContact() {
        Customer customer;
        Contact contact("Alice Johnson", "123 Elm St", "alice@example.com");
        customer.SetContact(contact);

        TS_ASSERT_EQUALS(customer.GetContact().getName(), "Alice Johnson");
        TS_ASSERT_EQUALS(customer.GetContact().getAddress(), "123 Elm St");
        TS_ASSERT_EQUALS(customer.GetContact().getEmail(), "alice@example.com");
    }


    void testDefaultConstructor3() {
        Customer customer;
        TS_ASSERT_EQUALS(customer.GetCard_number(), "");
        TS_ASSERT_EQUALS(customer.GetLimit(), 0.0);
        TS_ASSERT(customer.GetCharges().empty());
    }

    void testParameterizedConstructor3() {
        Contact contact("John Doe", "123 Main St", "john@example.com");
        std::list<Charge> charges;
        charges.push_back(Charge("Example Business", 50.0));
        Customer customer("12345", contact, 100.0, charges);

        TS_ASSERT_EQUALS(customer.GetCard_number(), "12345");
        TS_ASSERT_EQUALS(customer.GetLimit(), 100.0);
        TS_ASSERT_EQUALS(customer.GetCharges().size(), 1);
    }

    void testSetAndGetCharges() {
        Customer customer;
        std::list<Charge> charges;
        charges.push_back(Charge("Example Business", 50.0));
        customer.SetCharges(charges);

        TS_ASSERT_EQUALS(customer.GetCharges().size(), 1);
        TS_ASSERT_EQUALS(customer.GetCharges().front().GetAmount(), 50.0);
        TS_ASSERT_EQUALS(customer.GetCharges().front().GetBusiness(), "Example Business");
    }

    void testSetAndGetLimit2() {
        Customer customer;
        customer.SetLimit(200.0);
        TS_ASSERT_EQUALS(customer.GetLimit(), 200.0);
    }

    void testCountBigLimits() {

        Customers<Customer> customers;
        Contact contact1("John Doe", "123 Main St", "john@example.com");
        Contact contact2("Jane Smith", "456 Oak St", "jane@example.com");
        Contact contact3("Bob Johnson", "789 Elm St", "bob@example.com");

        Customer customer1("123", contact1, 200.0, {});
        Customer customer2("456", contact2, 300.0, {});
        Customer customer3("789", contact3, 100.0, {});

        customers.insert(customer1);
        customers.insert(customer2);
        customers.insert(customer3);

        TS_ASSERT_EQUALS(customers.count_big_limits(100.0), 2);

    }

    void testAnyOverLimit() {

            Customers<Customer> customers;
            Contact contact1("John Doe", "123 Main St", "main");
Contact contact2("Jane Smith", "456 Oak St", "oak");

Contact contact3("Bob Johnson", "789 Elm St", "elm");

Customer customer1("123", contact1, 200.0, { Charge("Example Business", 50.0)});

Customer customer2("456", contact2, 300.0, { Charge("Example Business", 500)});

Customer customer3("789", contact3, 100.0, { Charge("Example Business", 50.0)});

customers.insert(customer1);
customers.insert(customer2);
customers.insert(customer3);

TS_ASSERT_EQUALS(customers.any_over_limit(), true);

    }


    void testIncreaseLimit() {

                Customers<Customer> customers;
                Contact contact1("John Doe", "123 Main St", "main");
Contact contact2("Jane Smith", "456 Oak St", "oak");

Contact contact3("Bob Johnson", "789 Elm St", "elm");

Customer customer1("123", contact1, 200.0, { Charge("Example Business", 50.0)});

Customer customer2("456", contact2, 300.0, { Charge("Example Business", 500)});

Customer customer3("789", contact3, 100.0, { Charge("Example Business", 50.0)});

customers.insert(customer1);
customers.insert(customer2);
customers.insert(customer3);

customers.increase_limit("123", 100.0);

TS_ASSERT_EQUALS(customers.get_root().get_data().GetLimit(), 300.0);

    }


    void testCountBigLimits2() {

        Customers<Customer> customers;
        Contact contact1("John Doe", "123 Main St", "main");

        Contact contact2("Jane Smith", "456 Oak St", "oak");

        Contact contact3("Bob Johnson", "789 Elm St", "elm");

        Customer customer1("123", contact1, 200.0, {Charge("Example Business", 50.0)});

        Customer customer2("456", contact2, 300.0, {Charge("Example Business", 500)});

        Customer customer3("789", contact3, 100.0, {Charge("Example Business", 50.0)});

        customers.insert(customer1);

        customers.insert(customer2);

        customers.insert(customer3);

        TS_ASSERT_EQUALS(customers.count_big_limits(100.0), 2);



    }


    void testToString() {

            Customers<Customer> customers;
            Contact contact1("John Doe", "123 Main St", "main");

            Contact contact2("Jane Smith", "456 Oak St", "oak");

            Contact contact3("Bob Johnson", "789 Elm St", "elm");

            Customer customer1("123", contact1, 200.0, {Charge("Example Business", 50.0)});

            Customer customer2("456", contact2, 300.0, {Charge("Example Business", 500)});

            Customer customer3("789", contact3, 100.0, {Charge("Example Business", 50.0)});

            customers.insert(customer1);

            customers.insert(customer2);

            customers.insert(customer3);

            customers.to_string();

    }

    //void Customer::push_back(Charge c) {
    //122	0	    charges.push_back(c);
    //123	0	}
    //124

    void testChargePushback() {

            Customers<Customer> customers;
            Contact contact1("John Doe", "123 Main St", "main");

            Contact contact2("Jane Smith", "456 Oak St", "oak");

            Contact contact3("Bob Johnson", "789 Elm St", "elm");

            Customer customer1("123", contact1, 200.0, {Charge("Example Business", 50.0)});

            Customer customer2("456", contact2, 300.0, {Charge("Example Business", 500)});

            Customer customer3("789", contact3, 100.0, {Charge("Example Business", 50.0)});

            customers.insert(customer1);

            customers.insert(customer2);

            customers.insert(customer3);

            Charge charge("Example Business", 50.0);

            customer1.push_back(charge);

            TS_ASSERT_EQUALS(customer1.GetCharges().size(), 2);

    }

    void testDestructor() {
        Customers<Customer> customers;
        Contact contact1("John Doe", "123 Main St", "main");

        Contact contact2("Jane Smith", "456 Oak St", "oak");

        Contact contact3("Bob Johnson", "789 Elm St", "elm");

        Customer customer1("123", contact1, 200.0, {Charge("Example Business", 50.0)});

        Customer customer2("456", contact2, 300.0, {Charge("Example Business", 500)});

        Customer customer3("789", contact3, 100.0, {Charge("Example Business", 50.0)});

        customers.insert(customer1);

        customers.insert(customer2);

        customers.insert(customer3);

        customers.~Customers();


    }

    void testerase() {
        Binary_Search_Tree<int> bst; // Replace 'int' with your actual item type

        // Insert nodes into the tree
        bst.insert(5);
        bst.insert(3);
        bst.insert(7);
        bst.insert(2);
        bst.insert(4);
        bst.insert(6);
        bst.insert(8);

        // Verify the initial tree structure
        //       5
        //      / \
        //     3   7
        //    / \ / \
        //   2  4 6  8

        // Try erasing a non-existent node (should return false)
        TS_ASSERT(!bst.erase(1));

        // Erase a leaf node (e.g., 2)
        TS_ASSERT(bst.erase(2));
        // Verify the updated tree structure
        //       5
        //      / \
        //     3   7
        //      \ / \
        //       4 6  8

        // Erase a node with one child (e.g., 7)
        TS_ASSERT(bst.erase(7));
        // Verify the updated tree structure
        //       5
        //      / \
        //     3   8
        //      \ /
        //       4 6

        // Erase a node with two children (e.g., 3)
        TS_ASSERT(bst.erase(3));
        // Verify the updated tree structure
        //       5
        //        \
        //         8
        //        /
        //       4
        //        \
        //         6
    }




};
#endif /* NEWCXXTEST_H */
