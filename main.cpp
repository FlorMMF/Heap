#include <iostream>
#include "Heap.hpp"
using namespace std;

int main(){
    //Monticulo mínimo
    cout << "Mont\241culo m\241nimo:";
    Heap<int> heapMin;
    heapMin.Agregar(15);
    heapMin.Agregar(0);
    heapMin.Agregar(22);
    heapMin.Agregar(-5);
    heapMin.Imprimir();
    cout << "ObtFrente: " << heapMin.ObtFrente() << endl;
    cout << "Eliminar: " << heapMin.EliminarRaiz() << endl;
    heapMin.Imprimir();

    // Montículo máximo
    cout << "\nPrueba con mont\241culo m\240ximo:";
    Heap<int> heapMax(maximo<int>);
    heapMax.Agregar(15);
    heapMax.Agregar(0);
    heapMax.Agregar(22);
    heapMax.Agregar(-5);
    heapMax.Imprimir();
    cout << "ObtObtFrente: " << heapMax.ObtFrente() << endl;
    cout << "Eliminar: " << heapMax.EliminarRaiz() << endl;
    heapMax.Imprimir();

    // Lo demás
    cout << "\nVacio de mont\241culo: (juro que se acabo de vaciar)" << endl;
    heapMin.Vaciar();
    cout << "\n¿Est\240 vac\241o? " << (heapMin.EstaVacio() ? "S\241" : "No") << endl;
    cout << "N\243mero de elementos: " << heapMin.NumElementos() << endl;
    cout << "Capacidad del mont\241culo: " << heapMin.Capacidad() << endl;

    return 0;
}
