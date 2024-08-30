// Miranda Urban Solano A01752391
// 20 de agosto de 2024

// Calcular la sumatoria de 1 hasta n con un método matemático directo.


#include <iostream>
using namespace std;

int sumaDirecta(int n){

    return n * (n + 1) / 2;
    
}

/* OE               ||   P
    1 + 1 + 1 + 1   || 1(1) + 1(1) + 1(1)+ 1(1) Operación para suma

    T(n) = 4
         = O(1)
    
    Variables en la función para det. espacio en memoria
    1 || Var. n

    S(n) = 1
         = O(1)
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