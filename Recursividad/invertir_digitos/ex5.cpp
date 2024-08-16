#include <iostream>
using namespace std;

void inv_dig(int n){

    
    // Condición de parada
    if (n == 0){
        return;
    }

    // Invocación recursiva
    else {
        cout << resto;
        inv_dig(n);
    }

}

int main(){
    int digitos;

    cout << "Ingresa los dígitos que quieras invertir: " ;
    cin >> digitos;

    // cout << "Los dígitos invertidos son " << inv_dig(digitos) << endl;
    inv_dig(digitos);
    cout << endl;

    return 0;
};