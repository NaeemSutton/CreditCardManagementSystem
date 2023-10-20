#include <iostream>
#include "Customers.h"
#include "Customer.h"
#include "Charge.h"
#include "Contact.h"

int main() {
    Customers<Customer> customers;

    while (true) {
        std::cout << "==================== Customer Management System ====================" << std::endl;
        std::cout << "1. Add Customer" << std::endl;
        std::cout << "2. Check for Customers Exceeding Credit Limit" << std::endl;
        std::cout << "3. Count Customers with Credit Limits Above a Value" << std::endl;
        std::cout << "4. Exit" << std::endl;

        int choice;
        std::cout << "Enter your choice:" << endl;
        std::cin >> choice;

        switch (choice) {
            case 1: {
                // Add a new customer
                std::string cardNumber, name, address, email;
                double limit;
                std::list<Charge> charges;

                std::cout << "Enter customer card number:";
                std::cin >> cardNumber;
                std::cin.ignore();

                std::cout << "Enter customer name:";
                std::getline(std::cin, name);

                std::cout << "Enter customer address:";
                std::getline(std::cin, address);

                std::cout << "Enter customer email:";
                std::cin >> email;

                std::cout << "Enter credit limit:";
                std::cin >> limit;

                int numCharges;
                std::cout << "Enter the number of charges:";
                std::cin >> numCharges;

                for (int i = 0; i < numCharges; ++i) {
                    std::string business;
                    double amount;
                    std::cout << "Enter charge #" << i + 1 << " business:";
                    std::cin >> business;
                    std::cout << "Enter charge #" << i + 1 << " amount:";
                    std::cin >> amount;
                    charges.push_back(Charge(business, amount));
                }

                Contact contact(name, address, email);
                Customer customer(cardNumber, contact, limit, charges);
                customers.insert(customer);
                std::cout << "Customer added successfully." << std::endl;
                break;
            }

            case 2: {
                // Check if any customers have exceeded their credit limit
                bool anyOverLimit = customers.any_over_limit();
                if (anyOverLimit) {
                    std::cout << "Some customers have exceeded their credit limit." << std::endl;
                } else {
                    std::cout << "No customers have exceeded their credit limit." << std::endl;
                }
                break;
            }

            case 3: {
                // Count the number of customers with credit limits above a certain value
                double limitToCheck;
                std::cout << "Enter the credit limit to check: ";
                std::cin >> limitToCheck;
                int count = customers.count_big_limits(limitToCheck);
                std::cout << "Number of customers with credit limits above " << limitToCheck << ": " << count << std::endl;
                break;
            }

            case 4:
                std::cout << "Exiting the program. Goodbye!" << std::endl;
                return 0;

            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
        }
    }
}



