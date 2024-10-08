// Miranda Urban Solano A01752391
// 20 de agosto de 2024

// Calcular la sumatoria de 1 hasta n con un método iterativo.


#include <iostream>
using namespace std;

int sumaIterativa(int n){
    int suma = 0; 
    
    for (int i = 1; i <= n; ++i) { 
        suma += i;  // Suma cada número desde 1 hasta n
    }
    
    return suma; 
}

/* OE           ||  P
    1           ||  1(1) Inicialización de la suma
    1 + 1 + 1   ||  1(1) + 1(n+1) + 1(n) Bucle FOR
    1 + 1       ||  1(n) + 1(n) Suma de cada número
    1           ||  1(1) Return

    T(n) = 1 + 1 + n + 1 + n + 2n + 1 
         = 4n + 4
         = O(n)

    Variables en la función para det. espacio en memoria
    1 || Var. ini. suma
    1 || Var i del ciclo for
    1 || Var n del ciclo for

    S(n) = 1 + 1 + 1
         = 3
         = O(1)
*/

int main(){
    int num;
    
    do {
        cout << "Ingrese un numero positivo: " ;
        cin >> num;
    }
    while (num <= 0);

    int resultado = sumaIterativa(num);

    cout << "Este es el resultado de la suma iterativa: " << resultado << endl;

  return 0;
};