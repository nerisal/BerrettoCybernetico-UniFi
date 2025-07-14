

#include <iostream>

using namespace std;

class Pixel{
public:
    Pixel(int g=0, int r=0, int b=0):G(g),R(r),B(b){
        pixel=new int;
    };

    ~Pixel(){
        delete pixel;
    }

private:
    int G, R, B;
    int* pixel;

};

class Image{
public:
    Image( int h, int w, bool s=false):saved(s),height(h), width(w){
        buffer=new Pixel;
    };

    ~Image(){
        delete buffer;
    }

    void load(std::string name){
//        buffer=decompressImage(name);
        cout<<"Decompressing image....."<<endl;
    }

    void save(std::string name){
//        Pixel*compressedBuffer=compressedBuffer(buffer);
//        saveCompressedBuffer(name,compressedBuffer);
//        freeBuffer(compressedBuffer);
        cout<<"Saving image with name: "<<name<<endl;
    }

    void setPixel(int x, int y, const Pixel& pix){
        buffer[x*width+y]=pix;
    }

    Pixel getPixel(int x, int y)const {
        return buffer[x*width+y];
    }

    void setSaved(){
        saved=true;
    }

    bool getSaved()const{
        return saved;
    }


    bool IfNotSaved(string name){
        if(!saved){
            save(name);
            setSaved();
        }
        return saved;
    }

     bool operator==(const Image& right){
        if(height==right.height)
            if(width==right.width)
                if(computeHash()==right.computeHash())
                    return true;
        return false;
    }

     bool operator!=(const Image& right){
        if(operator==(right))
            return false;
        return true;
    }

protected:
     std::string computeHash()const{
        std::string result="HashValue";
        return result;
    }

private:
    Pixel* buffer;
    bool saved;
    int height, width;
};

int main(){
    auto img=new Image(20,30);

    auto img2=new Image(30,40, true);

    cout<<"\nIs it saved?"<<img->getSaved()<<endl;
    cout<<"Is it saved?"<<img2->getSaved()<<endl;

    cout<<"\n1=true(yes) \n0=false(no)"<<endl;

    cout<<"\n"<<endl;
    img->load("img.jpg");
    img2->IfNotSaved("img2.jpg");
    img->operator==(*img2);

    Pixel pic(2,3,5);
    img2->setPixel(2,2,pic);

    img->IfNotSaved("img.jpeg");
    cout<<"\n"<<endl;

    cout<<"Is img saved?"<<img->getSaved()<<endl;

    cout<<"\nIs img2 saved?"<<img2->getSaved()<<endl;
}