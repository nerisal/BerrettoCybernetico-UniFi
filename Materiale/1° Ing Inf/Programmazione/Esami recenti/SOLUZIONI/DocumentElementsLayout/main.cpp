#include "header.h"
#include "DocumentElement.h"
#include "LayoutElement.h"
#include "ImageElement.h"
#include "TextElement.h"

int main() {
    LayoutElement* firstLayoutElement = new LayoutElement;
    LayoutElement* secondLayoutElement = new LayoutElement;

    ImageElement* imageElement = new ImageElement("Image element");
    TextElement* textEl = new TextElement("TextElement");

    firstLayoutElement->addElement(imageElement);
    firstLayoutElement->addElement(textEl);
    firstLayoutElement->draw();


    cout << "\nLayout element inside another layout element." << endl;
    cout << "---------------------------------------------" << endl;
    secondLayoutElement->addElement(firstLayoutElement);
    secondLayoutElement->draw();

}