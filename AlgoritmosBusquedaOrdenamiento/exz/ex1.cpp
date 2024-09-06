#include <iostream>
#include <cstdlib>
#include <vector>
#include <cctype>   
#include <algorithm>
using namespace std;

template <typename T>
int busquedaSecuencial(T arr[], int N, T objetivo) {
    int i = 0;
    int encontrado = -1;

    while (encontrado == -1 && i < N) {
        if (objetivo == arr[i] ) {
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

int genera(int) {
    return rand() % 100;
}

float genera(float) {
    return (rand() % 100) * 0.5;
}

template <typename T>
vector<T> crearArray(int n) {
    vector<T> arr(n);

    for (int i = 0; i < n; ++i) {
        arr[i] = genera(static_cast<T>(0)); // Se asigna un valor de tipo T a la función genera [1]
    }
    return arr;
}

int main(int argc, char *argv[]) {
    // Ayudar al usuario a usar los parámetros correctos
    if (argc < 3) {
        cout << "Use: programa numero algoritmo" << endl;
        exit(0);
    }

    // Establecer el orden de los parámetros y variables
    int numero = atoi(argv[1]); // Convertir a integer
    char algoritmo = *(argv[2]);
    int encontrado = 0; // Salir del programa cuando se encuentre
    
    char tam;
    int N; // Variable para arreglo

    cout << endl;
    cout << "Elige el arreglo en donde se buscará: " << endl;
    cout << "A: 10, B: 100, C: 1000, D: 10000, E: 100000, F: 1000000" << endl;
    cin >> tam;
    tam = toupper(tam);
    cout << endl;

    // Determinar el valor de N de acuerdo a la elección del usuario
    switch (tam) {
        case 'A': N = 10; break;
        case 'B': N = 100; break;
        case 'C': N = 1000; break;
        case 'D': N = 10000; break;
        case 'E': N = 100000; break;
        case 'F': N = 1000000; break;
        default: cout << "Elige uno de los casos dados" << endl; return 1;
    }

    char datos;
    cout << "Elige el tipo de datos: I para int o F para float" << endl;
    cin >> datos;

    vector<int> arrInt;
    vector<float> arrFlo;

    switch (datos) {
        case 'I':
            arrInt = crearArray<int>(N);
            sort(arrInt.begin(), arrInt.end()); 
            break;
        case 'F':
            arrFlo = crearArray<float>(N);
            sort(arrFlo.begin(), arrFlo.end()); 
            break;
        default: cout << "Elige uno de los tipos de datos." << endl; return 1;
    }

    // Elegir el algoritmo de búsqueda con base en la elección del usuario
    switch (algoritmo){
        case 'S':
            encontrado = busquedaSecuencial(arrInt.data(), N, numero); break;
        case 'B':
            encontrado = busquedaBinaria(arrFlo.data(), N, numero); break;
        default:
            cout << "Recuerde seleccionar 'S' o 'B' para la busqueda" << endl; return -1;

    }
    cout << "Elegiste buscar el número " << numero << " en un arreglo de " << N << " números con un algoritmo " << algoritmo << endl;
    
    // Resultado obtenido de la búsqueda
    if (encontrado >= 0)
    {
        cout << "El número " << numero << " se  encuentra en la posición " << encontrado << endl;
    }
    else {
        cout << "El número " << numero << " no forma parte del arreglo" << endl;
    }

    return 0;
}
