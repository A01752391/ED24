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