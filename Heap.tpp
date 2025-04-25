
#include <cmath>
#include <math.h>
template <typename T>
Heap<T>::Heap():ultimo(-1), cap(31){
    arreglo = new T[cap];

}

template <typename T>
Heap<T>::~Heap(){
    delete arreglo;
}

template <typename T>
void Heap<T>::Agregar(T valor){
    if( (ultimo +1) == cap){
        cap = cap*2;
    }
    ++ultimo;
    arreglo[ultimo] = valor;
    int hijo = ultimo;

    while (arreglo[hijo] < floor(arreglo[(hijo - 1 )/2]) ){

        hijo = EmpujarArriba(hijo);
    }

}

template <typename T>
void Heap<T>:: Imprimir(){
    int aux = 0;
    for(int i = 0; i <= ultimo; ++i){
         if(pow(2,aux) == i+1){
            ++aux;

            std::cout << std::endl;
        }
        std::cout << arreglo[i] << ", ";

    }

    std::cout << std::endl;
}

template <typename T>
int Heap<T>::EmpujarArriba(int i){
    int valor = arreglo[i];
    arreglo[i] = arreglo[(i - 1 )/2];
    arreglo[(i - 1 )/2] = valor;
    i = (i - 1 )/2;
    return i;
}

template <typename T>
int Heap<T>:: EmpujarAbajo(int i){
    if(/*es hijo izquierdo*/){
        int valor = arreglo[i];
        arreglo[i] = arreglo[2*i + 1];
        arreglo[2*i + 1] = valor;
        i = 2*i + 1;

    }else{
        int valor = arreglo[i];
        arreglo[i] = arreglo[2*i + 2];
        arreglo[2*i + 2] = valor;
        i = 2*i + 2;
    }

    return i;
}

template <typename T>
void Heap<T>:: redimensionar(){
    cap = cap*2;
    T aux[] = arreglo;
    arreglo = new T[cap];
    arreglo = aux;

}

