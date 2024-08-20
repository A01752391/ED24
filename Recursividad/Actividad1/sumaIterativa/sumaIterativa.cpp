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