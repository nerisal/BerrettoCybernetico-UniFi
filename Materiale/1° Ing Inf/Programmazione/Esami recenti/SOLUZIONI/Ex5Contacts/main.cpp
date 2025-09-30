#include <iostream>
#include "Person.h"
#include "Contacts.h"

int main() {

    Contacts *rubrica = new Contacts(5);

    Person *p1 = new Person("Monica", "Eron");
    Person *p2 = new Person("Mario", "Rossi");
    Person *p3 = new Person("Paolo", "Biondi");
    Person *p4 = new Person("Daniele", "Ferri");
    Person *p5 = new Person("Marta", "Chicchi");
    Person *p6 = new Person("Anna", "Bini");

    p1->addEmail("Personal", "monica@gmail.com");
    p1->addEmail("Personal", "monika.e@hotmail.it");
    p1->addAddress("Home", "Via della Chiesa 64");
    p1->addEmail("Business", "monica@tiscali.it");
    p1->addTelephone("Personal", "3400599012");

    p2->addEmail("Business","mario@libero.it");
    p2->addTelephone("Home","055-214937");
    p2->addTelephone("Home","055-6280914");
    p2->addAddress("Domicile","Viale Spartaco Lavagnini 23");

    p3->addTelephone("Personal", "3406015490");
    p3->addAddress("Home", "Via Doni 13");
    p3->addAddress("Domicile", "Via Pratesi 45");
    p3->addEmail("Personal","paolo.biondi@email.com");

    p4->addTelephone("Business","055-2467890");

    p5->addEmail("Business", "marta@mail.it");
    p5->addEmail("Business", "marta@tiscali.it");
    p5->addTelephone("Business", "055-1234555");

    p6->addAddress("Home","Via Romana 115");
    p6->addAddress("Domicile","Piazza Goldoni 16");
    p6->addAddress("Domicile","Via Senese 110");
    p6->addTelephone("Personal","3201848733");

    rubrica->addPerson(p1);
    rubrica->addPerson(p2);
    rubrica->addPerson(p3);
    rubrica->addPerson(p4);
    rubrica->addPerson(p5);
    rubrica->addPerson(p6);

    rubrica->printAllContacts();

    rubrica->removePerson(p2);
    rubrica->removePerson(p1);

    rubrica->printAllContacts();

    rubrica->addPerson(p6);
    rubrica->addPerson(p2);

    rubrica->removePerson(p5);

    rubrica->printAllContacts();
}