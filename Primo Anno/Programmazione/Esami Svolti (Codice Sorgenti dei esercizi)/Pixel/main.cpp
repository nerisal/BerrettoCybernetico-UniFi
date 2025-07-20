#include <iostream>
template<typename T>
class Pixel{
    T R;
    T G;
    T B;

public:
    Pixel(T R=0, T  G=0, T B = 0) : R(R), G(G), B(B) {}
    T get_R(){
        return R;}
    T get_G(){
        return G;
    }
    T  get_B(){
        return B;
    }
    void print_info(){
        std::cout<<"R: "<<R<<std::endl;
        std::cout<<"G: "<<G<<std::endl;
        std::cout<<"B: "<<B<<std::endl;
    }

};
template <typename T>
class Image{
public:
    Image(int w, int h) : width(h), altezza(w) {
        pix= new Pixel<T>[width*altezza];
    }
    void set_pixel(int x, int y,Pixel<T> *pi){
        if(x<0||y<0||x>altezza||y>width){
            throw std::out_of_range("OUT_OF_RANGE");
        }

        if(pi->get_B()<0||pi->get_G()<0||pi->get_R()<0){
            throw std::invalid_argument("INVALID_ARGUMENT");
        }
        pix[x*width+y]=*pi;
        std::cout<<std::endl<<"...added successfully"<<std::endl;
    }

    virtual ~Image() { delete pix;

    }

    Pixel<T> get_pixel(int x,int y){
        std::cout<<"Coordinates: "<<x<<" "<<y<<std::endl;
        pix[x*width+y].print_info();
        return  pix[x*width+y];

    }

    Image(const Image& img){
        copy(img);
    }

    void copy(const Image& img){

        altezza=img.altezza;
        width=img.width;
         pix =new Pixel<T>[width*altezza];
        if(img.pix!=nullptr){
            for(width*altezza!=)
            Pixel<T>* pix
                pix=new Pixel<T>(*img.pix);

        }
        else
            pix= nullptr;

    }

    Image operator=(const Image& img){
        if(this != &img) {
            if(pix!=nullptr){
                delete pix;
            }
            altezza=img.altezza;
            width=img.width;
            if(img.pix!= nullptr){
                pix= new Pixel<T>(*img.pix);
            }
            else pix=nullptr;
        }
        return *this;
    }



private:
    int altezza;
    int width;
    Pixel<T>* pix;
};

int main() {
    Pixel<int> pi_2(2,3,3);
    Pixel<int> pi(-1,2,-3);
    Pixel<int> pi_3(2,2,2);
    Image<int> I(10,10);
    try{
    I.set_pixel(1,1,&pi_2);
    I.get_pixel(1,1);
    I.set_pixel(1,2,&pi);
    I.set_pixel(-1,2,&pi_3);

    }

    catch (std::out_of_range &e) {
        std::cerr<<"OUT_OF RANGE";
    }
    catch (std::invalid_argument& c ){
        std::cerr<<"INVALID ARGUMENT";
    }



}