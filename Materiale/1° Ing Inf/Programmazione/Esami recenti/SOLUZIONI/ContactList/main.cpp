#include "header.h"
#include "Person.h"
#include "Email.h"
#include "Contact.h"


void fieldContact(list<Person*>& contacts);
void printContacts(list<Person*>& contacts){

}
void mainMenu();

int main() {
    /*
    list<Person*> people;
    string name, surname, etype, ename,atype,aname, ntype,nvalue;
    int id,num;
    //mainMenu();
    cout << "How many contacts do you want to insert: "; cin >> num;
    for(int i = 1; i<=num; i++){
        //cout << "Insert id: "; cin >> id;
        cout << "Insert name: "; cin >> name;
        cout << "Insert surname: "; cin >> surname;
        Person* newPerson = new Person(i,name, surname);
        people.push_back(newPerson);
    }
    cout << endl;
    for(auto itr : people)
        itr->print();

    int count = 1;

    for(auto i : people){
        cout << "\nInsert information for contact ID[" << count << "]" << endl;
        cout << "Insert email type: "; cin >> etype;
        cout << "Insert email: "; cin >> ename;
        i->insertEmail(etype, ename);
        cout << "Insert address type: "; cin >> atype;
        cout << "Insert address: "; cin >> aname;
        i->insertAddress(atype, aname);
        cout << "Insert number type: "; cin >> ntype;
        cout << "Insert number: "; cin >> nvalue;
        i->insertNumber(ntype, nvalue);
        count ++ ;

    }
    cout << endl;
    Contact* contact = new Contact(people);
    contact->printContacts();
    int idn;
    cout << "Enter id contact to remove: "; cin >> idn;

    //std::list<int>::iterator findIter = std::find(ilist.begin(), ilist.end(), 1);



    */
    Contact* contact = new Contact;
    Person* p1 = new Person(1,"Daniel", "Cullhaj");
    Person* p2 = new Person(2, "Dorek", "Cgeorge");
    Person* p3 = new Person(3, "Manch", "Carrera");

    contact->addPerson(p1);
    contact->addPerson(p2);
    contact->addPerson(p3);
    contact->printContacts();
    cout << endl;

    cout << "Adding some information for contact ID [1]: " << endl;
    p1->insertEmail("Personal", "emai@email.com");
    p1->insertAddress("Permanent", "Italy");
    p1->insertNumber("Personal","3876251746");

    cout << "Adding some information for contact ID [2]: " << endl;
    p2->insertEmail("Personal", "keko@gmail.com");
    p2->insertAddress("Permanent", "Greece");
    p2->insertNumber("Personal","3843601278");

    cout << "Adding some information for contact ID [3]: " << endl;
    p3->insertEmail("Business", "manch@manch.com");
    p3->insertAddress("Residence", "USA");
    p3->insertNumber("Job","3803664594");
    cout << endl;
    contact->printContacts();

    cout << "Removing Contacts" << endl;
    contact->removePerson(p2);
    contact->printContacts();
    cout << endl;

    cout << "Modifying some fields" << endl;
    p1->setPName("Newname"); p1->setPSurname("Newsurname");
    contact->printContacts();

    cout << "Removing Contacts" << endl;
    contact->removePerson(p3);
    contact->removePerson(p1);
    contact->printContacts();

    cout << endl;

    return 0;
}

void mainMenu(){
    cout << "###########################" << endl;
    cout << "#       1)Add contact     #" << endl;
    cout << "#       2)Remove contact  #" << endl;
    cout << "#       3)Edit contact    #" << endl;
    cout << "#       4)Show contacts   #" << endl;
    cout << "#       0)Exit            #" << endl;
    cout << "###########################" << endl;
}