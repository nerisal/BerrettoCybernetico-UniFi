

#ifndef ES5_ACCUMULATORMINMAX_ACCUMULATORMINMAX_H
#define ES5_ACCUMULATORMINMAX_ACCUMULATORMINMAX_H

#include <iostream>
#include <list>

template <typename T>
class AccumulatorMinMax {
public:
    AccumulatorMinMax() {};
    void addElement( T* el );

    T getMin();
    T getMax();

private:
    std::list< T* > elements;
};

template <typename T>
void AccumulatorMinMax<T>::addElement( T* el ){
    elements.push_back( el );
    std::cout << "Inserito : " << ( *el ) << std::endl;
}

template <typename T>
T AccumulatorMinMax<T>::getMin(){
    T* min = ( *elements.begin() ); //prende il primo elemento di elements
    for (auto itr = elements.begin(); itr != elements.end(); itr++ ){
        if (( *min ) > ( **itr ))
            min = ( *itr );
    }
    return ( *min );
}

template <typename T>
T AccumulatorMinMax<T>::getMax(){
    T* max = ( *elements.begin() );
    for (auto itr = elements.begin(); itr != elements.end(); itr++ ){
        if (( *max ) < ( **itr ))
            max = ( *itr );
    }
    return ( *max );
}

#endif //ES5_ACCUMULATORMINMAX_ACCUMULATORMINMAX_H
