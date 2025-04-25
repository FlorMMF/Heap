#ifndef HEAP_HPP_INCLUDED
#define HEAP_HPP_INCLUDED

template <typename T>
class Heap{
public:
    Heap();
    ~Heap();
    Heap(const Heap<T> & h);
    Heap & operator= (const Heap<T> & h);
    void Agregar(T valor);
    void Eliminar();
    void Imprimir();
private:
    T *arreglo;
    int ultimo,cap;

    int EmpujarArriba(int i);
    int EmpujarAbajo(int i);
    void redimensionar();
};

#include "Heap.tpp"

#endif // HEAP_HPP_INCLUDED
