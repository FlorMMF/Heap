#ifndef HEAP_HPP_INCLUDED
#define HEAP_HPP_INCLUDED

#define IZQ true
#define DER false
template <typename T>
class Heap{
public:
    /** \brief Constructor de la clase
     *
     *
     */
    Heap();
    /** \brief Destructor de la clase
     *
     *
     */
    ~Heap();
    /** \brief Constructor de copias de la clase
     *
     * \param h const Heap<T>&
     *
     */
    Heap(const Heap<T> & h);
    /** \brief Operador igual, copia un heap en el objeto de la clase
     *
     * \param const Heap<T> & h
     * \return Heap, devuelve el heap copiado
     *
     */
    Heap & operator= (const Heap<T> & h);
    /** \brief M&eacute;todo para agregar un valor al &aacute;rbol, lo agrega al final y lo sube a su posici&oacute;n de menor a mayor o viceversa
     *
     * \param valor T, el valor a agregar
     * \return void
     *
     */
    void Agregar(T valor);
    /** \brief Imprime un &aacute;rbol tipo Heap por niveles
     *
     * \return void
     *
     */
    void Imprimir();
private:
    T *arreglo;
    int ultimo,cap;

    /** \brief M&eacute;todo para intercambiar dos valores en el &aacute;rbol,
                intercambia un hijo con su padre
     *
     * \param i int, la posici&oacute;n de el valor que queremos subir
     * \return int,devuelve la posici&oacute;n de donde ahora esta ubicado el valor
     *
     */
    int EmpujarArriba(int i);
    /** \brief M&eacute;todo para intercambiar dios valores en el &aacute;rbol,
                intercambia un valor con uno de sus dos hijos
     *
     * \param i int, la posici&oacute;n del valor que queremos intercambiar
     * \param hijo bool, selecci&oacute;n si es el hijo izquierdo o derecho el que se quiere intercambiar
     * \return int, devuelve la posici&oacute;n de donde ahora esta ubicado el valor
     *
     */
    int EmpujarAbajo(int i, bool hijo);
    /** \brief M&eacute;todo para aumentar la capacidad del arreglo
     *
     * \return void
     *
     */
    void redimensionar();
};

#include "Heap.tpp"

#endif // HEAP_HPP_INCLUDED
