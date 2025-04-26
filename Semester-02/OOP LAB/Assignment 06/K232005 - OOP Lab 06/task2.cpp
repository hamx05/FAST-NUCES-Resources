#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class Image {
private:
    int width;
    int height;
    int* data;
public:
    // Constructor
    Image(int newWidth, int newHeight, int* imgData) : width(newWidth), height(newHeight) {
        data = new int[width * height];
        for (int i=0; i<width*height; i++) {
            data[i] = imgData[i];
        }
    }

    // Copy Constructor
    Image(const Image& obj) : width(obj.width), height(obj.height) {
        data = new int[width * height];

        for (int i=0; i<width*height; i++) {
            data[i] = obj.data[i];
        }
    }

    // Destructor
    ~Image() {
        delete[] data;
    }

   // Methods
    void display() const {
        for (int i = 0; i < height; ++i) {
            for (int j = 0; j < width; ++j) {
                cout << data[i * width + j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    void updateData() {
        srand(time(NULL));
        for (int i = 0; i < width * height; ++i) {
            if (data[i] <= 0) {
                data[i] = rand() % 255 + 1;
            }
        }
    }
};

int main() {
   
    int ogData[] = {0, 0, 0, 200, 100, 0};
   
    Image ogImage(2, 3, ogData);
    Image cpImage = ogImage;

    cout << "Original Image:" << endl;
    ogImage.display();

    cout << "Copied Image:" << endl;    
    cpImage.display();

    ogImage.updateData();
    cout << "Updated Original Image Data:" << endl;
    ogImage.display();

    cout << "Copied Image:" << endl; // not copying the image data from new data because question me mentioned nahi tha
    cpImage.display();

    return 0;
}


