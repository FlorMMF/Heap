#include <iostream>
#include "Heap.hpp"
using namespace std;

int main()
{
    Heap<int> heap;
    heap.Agregar(15);
    heap.Agregar(0);
    heap.Agregar(2);
    heap.Agregar(1);
    heap.Agregar(-1);
    heap.Agregar(22);
    heap.Agregar(222);
    heap.Agregar(-5);
    heap.Agregar(2);
    heap.Agregar(-22);
    heap.Agregar(-2);

    heap.Imprimir();


    return 0;
}
