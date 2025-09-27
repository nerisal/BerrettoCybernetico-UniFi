#include "headers.h"
#include "Library.h"
#include "Book.h"
#include "Dvd.h"

int main() {
    Book firstBook("First book", "Emma Author", "Emma actor", 100);
    Dvd firstDvd("First dvd", "Emma dvd", 50);

    Library* library = new Library();

    library->addToLibrary(&firstBook);
    library->addToLibrary(&firstDvd);

    library->printList();


    return 0;
}