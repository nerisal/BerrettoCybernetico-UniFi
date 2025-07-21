#include <exception>
#include <string>


struct Pixel{
    int R;
    int G;
    int B;
};

class Image {
private:
    int width;
    int height;
    bool modified;

    Pixel* buffer;
public:
    // Passo il buffer nel costruttore perché potrebbe essere passato ad esempio dalla fotocamera
    Image(int w, int h): buffer(new Pixel[w * h]), width(w), height(h) {}

    Image(const Image& original) {
        width = original.width;
        height = original.height;

        buffer = new Pixel[original.width * original.height];
        for(int i = 0; i < height * width; i++)
            buffer[i] = original.buffer[i];
    }

    ~Image() {
        delete[] buffer;
    }

    Image& operator=(const Image& right) {
        if (this == &right) return *this;

        width = right.width;
        height = right.height;
        
        if(buffer != nullptr) {
          delete[] buffer;
        }
        buffer = new Pixel[right.width * right.height];
        
        for(int i = 0; i < width * height; i++)
            buffer[i] = right.buffer[i];

        return *Image;
    }

    void load(std::string name) {
        buffer = decompressImage(name);
        modified = false;
    }

    void save(std::string name) {
        if(modified){


            Pixel* compressBuffer = compressBuffer(buffer);
            saveCompressedBuffer(name, compressedBuffer);
            freeBuffer(compressedBuffer);
        }
        modified = false;
    }

    void setPixel(int x, int y, const Pixel& pix);
    Pixel getPixel(int x, int y);
};

void Image::setPixel(int x, int y, const Pixel& pix) {
    if(x > width || y > height) {
        throw std::out_of_bound("The coordinated are grater than Image size");
    }

    buffer[y * width + x] = pix;

    modified = true;
}

Pixel Image::getPixel(int x, int y) {
    if(x > width || y > height) {
        throw std::out_of_bound("The coordinated are grater than Image size");
    }

    return buffer[y * width + x];
}

// La classe gestisce delle risorse. Dunque ha necessità della deep copy
