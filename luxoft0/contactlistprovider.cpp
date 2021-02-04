#include "contactlistprovider.h"
#include <QMessageBox>

// When class is init, contactVector is filled
ContactListProvider::ContactListProvider()
{
    this->fillContact();
}

// filling contact vector by sample data
void ContactListProvider::fillContact(){
    for (auto i = 0; i < 10; ++i){
        Person tempPerson = Person();
        tempPerson.name = "Linus";
        tempPerson.surname = "Torvalds";
        tempPerson.phone = "+3801234567890";
        tempPerson.is_fav = false;
        tempPerson.id = i;
        this->contactVector.push_back(tempPerson);
    }
}

// returns contat vector
std::vector<Person> ContactListProvider::getContact(){
    return this->contactVector;
}
