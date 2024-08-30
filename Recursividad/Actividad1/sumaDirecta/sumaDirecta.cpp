// Miranda Urban Solano A01752391
// 20 de agosto de 2024

// Calcular la sumatoria de 1 hasta n con un método matemático directo.


#include <iostream>
using namespace std;

int sumaDirecta(int n){

    return n * (n + 1) / 2;
    
}

/* OE           ||   P
    1 + 1 + 1   || 1(n) + 1(n) + 1(n) Operación para suma
    1           || 1(1) Return

    T(n) = 3n + 1
    
    Variables en la función para det. espacio en memoria
    1 ||

    S(n) =
*/

int main(){
    int num;
    
    do {
        cout << "Ingrese un numero positivo: " ;
        cin >> num;
    }
    while (num <= 0);

    int resultado = sumaDirecta(num);

    cout << "Este es el resultado de la suma: " << resultado << endl;

  return 0;
};