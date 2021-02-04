#ifndef CONTACTLISTPROVIDER_H
#define CONTACTLISTPROVIDER_H

#include <iostream>
#include <vector>

//! Class that provides contact info

// Person struct with personal data attributes
struct Person {
    std::string name;
    std::string surname;
    std::string phone;
    bool is_fav;
    int id;
};

// ContactListProvider class that gets
// actual contact list from device.
// contactVector - vector that stores contacts in Person's
class ContactListProvider
{
private:
    std::vector<Person> contactVector;
public:
    ContactListProvider();
    void fillContact();
    std::vector<Person> getContact();
};

#endif // CONTACTLISTPROVIDER_H
