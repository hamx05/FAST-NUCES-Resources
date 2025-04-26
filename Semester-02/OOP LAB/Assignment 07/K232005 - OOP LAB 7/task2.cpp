#include <iostream>
#include <vector>
using namespace std;

class Product { // Base class
    protected:
        int productID;
        string productName;
        int price;
        int quanity;
        string category;
        string supplier;
        string* stock;
        int numStock;

    public:
        Product () {
            productID = 0;
            productName = "Default product name";
            price = 0;
            quanity = 0;
            category = "Default category";
            supplier = "Default supplier";
        }

        Product (int productID, string productName, float price, int quanity, string category, string supplier) {
            this->productID = productID;
            this->productName = productName;
            this->quanity = quanity;
            this->category = category;
            this->supplier = supplier;
        }

        void addStock (int q) {
            quanity += q;
        }

        friend ostream& operator<<(ostream& os, const Product& product);
};

// error solved by gpt
ostream& operator<<(ostream& os, const Product& product) {
    os << "Product ID: " << product.productID << ", Name: " << product.productName << ", Price: Rs " << product.price << ", Quantity: " << product.quanity << ", Category: " << product.category << ", Supplier: " << product.supplier;
    return os;
}

class Category : public Product {
    private:
        int categoryID;
        string categoryName;
    public:
        vector <Product> products;

        Category () {
            categoryID = 0;
            categoryName = "Default category name";
        }

        Category (int categoryID, string categoryName) {
            this->categoryID = categoryID;
            this->categoryName = categoryName;
        }

        void addProducts (Product newProd) { // adds a product to the category
            products.push_back(newProd);
        }

        void getProducts () { // returns a list of products in the category
            for (int i=0; i<products.size(); i++) {
                cout<< products.at(i) << endl;
            }
        }

};

class Supplier : public Category {
    private:
        int supplierID;
        string supplierName;
        vector <Product> productList;
    
    public:
        Supplier () {
            supplierID = 0;
            supplierName = "Default supplier name";
        }

        Supplier (int supplierID, string supplierName) {
            this->supplierID = supplierID;
            this->supplierName = supplierName;
        }

        void addProducts (Product newProd) { // adds a product to the category
            productList.push_back(newProd);
        }

        void getProducts () { // returns a list of products in the category
            for (int i=0; i<productList.size(); i++) {
                cout<< productList.at(i) << endl;
            }
        }
};

int main () {

    Product prod1(3, "Soap", 350, 10, "Sanitary", "Dove");
    Product prod2(4, "Pre cooked pizza", 1000, 15, "Food", "Hilal");
    Category cat1(5, "Sanitary");
    Category cat2(6, "Food");
    Supplier supp1(35, "John");
    Supplier supp2(36, "Eliot");

    // For 1st product:
    cat1.addProducts(prod1);
    supp1.addProducts(prod1);

    cout<<"--------------------------------------" << endl;
    cout<<"\tProducts added in 1st Category Class" << endl;
    cat1.getProducts();

    cout<<"--------------------------------------" << endl;
    cout<<"\tProducts added in 1st Supplier Class" << endl;
    supp1.getProducts();

    // For 2nd product:
    cout << endl;
    cat2.addProducts(prod2);
    supp2.addProducts(prod2);

    cout<<"--------------------------------------" << endl;
    cout<<"\tProducts added in 2nd Category Class" << endl;
    cat2.getProducts();

    cout<<"--------------------------------------" << endl;
    cout<<"\tProducts added in 2nd Supplier Class" << endl;
    supp2.getProducts();

    return 0;
}