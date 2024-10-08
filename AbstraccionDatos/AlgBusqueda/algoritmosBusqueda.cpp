#include <iostream>
#include <cstdlib>
#include <random>
using namespace std;

template<typename T>
void generar_array(T* array, int size) {
    for (int i = 0; i < size; ++i) {
        array[i] = i * rand() % 100;
    }

    for (int i = 0; i < size; i++){
    for (int j = size-1; j > i; j--){
        if (array[j-1] > array[j]) {
            swap(array[j - 1], array[j]);
        }
    }
    }
}

template <class T>
int busquedaSecuencial(T arr[], int N, T objetivo) {
    int i = 0;
    int encontrado = -1;

    while (encontrado == -1 && i < N) {
        if (objetivo == arr[i]) {
            encontrado = i;
        }
        i++;
    }
    return encontrado;
}

template <typename T>
int busquedaBinaria(T arr[], int N, T objetivo) {
    if (N == 0) { 
        return 0; 
    }
    
    int mitad, inf = 0, sup = N - 1; // Determinar valores para la búsqueda
    
    // Búsqueda en la mitad izquierda o derecha del vector
    do {
        mitad = (inf + sup) / 2;
        if (objetivo > arr[mitad]) {
            inf = mitad + 1;
        }
        else {
            sup = mitad - 1;
        }
        }

    while (arr[mitad] != objetivo && inf <= sup);
    
    if (arr[mitad] == objetivo) { 
        return mitad; 
    }
    else { 
        return -1;
        }
}

int main(int argc, char *argv[]) {
    // Ayudar al usuario a usar los parámetros correctos
    if (argc < 4) {
        cout << "Use: programa numero algoritmo elementos" << endl;
        exit(0);
    }

    // Establecer el orden de los parámetros y variables
    int numero = atof(argv[1]); // Convertir a integer
    char algoritmo = *(argv[2]);
    int elementos = atoi(argv[3]);
    int encontrado; // Salir del programa cuando se encuentre

    /* srand((unsigned int) time(NULL)); 
    Genera una semilla diferente para el rand, por eso no se uso.
    Se esperaba tener un arreglo "random" idéntico para las comparaciones*/

    int* array = new int[elementos];
    generar_array(array, elementos);

    switch (algoritmo){
        case 'S':
            encontrado = busquedaSecuencial(array, elementos, numero); break;
        case 'B':
            encontrado = busquedaBinaria(array, elementos, numero); break;
        default:
            cout << "Utliza 'S' para búsqueda secuencial o 'B' para búsqueda binaria." << endl;
            return 1;
    }

    if (encontrado > 0) {
        cout << "El número " << numero << " está en la posición " << encontrado << endl;
    }
    else {
        cout << "El número " << numero << " no se encuentra" << endl;
    }

    return 0;
};