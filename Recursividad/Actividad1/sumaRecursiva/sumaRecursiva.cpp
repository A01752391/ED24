// Miranda Urban Solano A01752391
// 20 de agosto de 2024

// Calcular la sumatoria de 1 hasta n con un método recursivo.


#include <iostream>
using namespace std;

int sumaRecursiva(int n){

    // Condición de parada
    if (n == 0){
        return 0;
    }

    // Invocación recursiva
    else{
        return n + sumaRecursiva(n-1); // El número actual más la suma del resto
    }
}

/* OE           ||  P
    1           ||  1(n) Comparación del IF
    1           ||  1(1) Return
    1 + 1       ||  3(n-1) Return y suma 

    T(n) = n + 1 + 3n - 3
         = 4n - 2
         = O(n)

    Variables en la función para det. espacio en memoria
    1 || Var. n || n

    S(n) = 1 * n
         = O(n)
*/

int main(){
    int num;
    
    do {
        cout << "Ingrese un numero positivo: " ;
        cin >> num;
    }
    while (num <= 0);

    int resultado = sumaRecursiva(num);

    cout << "Este es el resultado de la suma: " << resultado << endl;

  return 0;
};