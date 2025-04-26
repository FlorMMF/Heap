
#include <cmath>
#include <math.h>
template <typename T>
Heap<T>::Heap(bool (*comparador)(const T &, const T &)) : ultimo(-1), cap(31), comp(comparador){
    arreglo = new T[cap];
}

template <typename T>
Heap<T>::Heap(const Heap<T> & h){
    *this = h;
}

template <typename T>
Heap<T> & Heap<T>::operator= (const Heap<T> & h){
    T *aux = arreglo;
    arreglo = new T[h.cap];
    for(int i = 0; i <= h.ultimo; ++i){
        arreglo[i] = h[i];
    }
    delete aux;
}

template <typename T>
Heap<T>::~Heap(){
    delete arreglo;
}

template <typename T>
void Heap<T>::Agregar(T valor){
    if ((ultimo + 1) == cap){
        redimensionar();
    }
    ++ultimo;
    arreglo[ultimo] = valor;
    int hijo = ultimo;

    while (hijo > 0 && comp(arreglo[hijo], arreglo[(hijo - 1) / 2])){
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
int Heap<T>:: EmpujarAbajo(int i, bool hijo){
    if (hijo == IZQ && (2 * i + 1) <= ultimo){
        int valor = arreglo[i];
        arreglo[i] = arreglo[2 * i + 1];
        arreglo[2 * i + 1] = valor;
        i = 2 * i + 1;
    } else if (hijo == DER && (2 * i + 2) <= ultimo){
        int valor = arreglo[i];
        arreglo[i] = arreglo[2 * i + 2];
        arreglo[2 * i + 2] = valor;
        i = 2 * i + 2;
    }
    return i;
}

template <typename T>
void Heap<T>:: redimensionar(){
    cap = cap*2;
    T *aux = arreglo;
    arreglo = new T[cap];
    for(int i = 0; i <= ultimo; ++i){
        arreglo[i] = aux[i];
    }
    delete aux;

}

template <typename T>
T Heap<T>::EliminarRaiz() {
    if (ultimo == -1) {
        throw std::out_of_range("El heap está vacío");
    }

    T raiz = arreglo[0]; 
    arreglo[0] = arreglo[ultimo];
    --ultimo;


    int padre = 0;
    while (true) {
        int hijoIzq = 2 * padre + 1;
        int hijoDer = 2 * padre + 2;
        int menorHijo = padre;

        if (hijoIzq <= ultimo && arreglo[hijoIzq] < arreglo[menorHijo]) {
            menorHijo = hijoIzq;
        }
        if (hijoDer <= ultimo && arreglo[hijoDer] < arreglo[menorHijo]) {
            menorHijo = hijoDer;
        }
        if (menorHijo == padre) {
            break;
        }
        EmpujarAbajo(padre, menorHijo == hijoIzq ? IZQ : DER);
        padre = menorHijo;
    }

    return raiz;
}

template <typename T>
T Heap<T>::ObtFrente() const {
    if (ultimo == -1) {
        throw std::out_of_range("El heap está vacío");
    }
    return arreglo[0];
}

template <typename T>
bool Heap<T>::EstaVacio() const {
    return ultimo == -1;
}

template <typename T>
void Heap<T>::Vaciar() {
    delete arreglo;
    cap = 31;
    arreglo = new T[cap];
    ultimo = -1;
}

template <typename T>
int Heap<T>::NumElementos() const {
    return ultimo + 1;
}

template <typename T>
int Heap<T>::Capacidad() const {
    return cap;
}
