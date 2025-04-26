#include <iostream>

// Interface
class Printable {
public:
    virtual void print() const = 0;
};

// Class implementing the interface
class Document : public Printable {
public:
    void print() const override {
        std::cout << "Printing document..." << std::endl;
    }
};

// Another class implementing the interface
class Image : public Printable {
public:
    void print() const override {
        std::cout << "Printing image..." << std::endl;
    }
};

int main() {
    Document doc;
    Image img;
    
    // Polymorphic behavior using interface
    Printable* printable1 = &doc;
    Printable* printable2 = &img;
    
    printable1->print(); // Prints "Printing document..."
    printable2->print(); // Prints "Printing image..."

    // OR
    doc.print();
    img.print();
        
    return 0;
}
