

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

    while (arreglo[hijo] < arreglo[(hijo - 1 )/2]){
        arreglo[hijo] = arreglo[(hijo - 1 )/2];
        arreglo[(hijo - 1 )/2] = valor;
        hijo = (hijo - 1 )/2;
    }

}

template <typename T>
void Heap<T>:: Imprimir(){
    for(int i = 0; i <= ultimo; ++i){
        std::cout << arreglo[i] << ", ";
    }

    std::cout << std::endl;
}
