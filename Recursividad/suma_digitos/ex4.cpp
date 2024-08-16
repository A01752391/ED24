#include <iostream>
using namespace std;

int suma_dig(int n){

    int resto = n % 10;
    n = n / 10;
    
    // Condición de parada
    if (n == 0){
        return resto;
    }

    // Invocación recursiva
    else{
        return resto + suma_dig(n);
    }

}

int main(){
    int digitos;

    cout << "Ingresa los dígitos que quieras sumar: " ;
    cin >> digitos;

    cout << "La suma de los digitos es " << suma_dig(digitos) << endl;

    return 0;
};