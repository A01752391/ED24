#include <iostream>
using namespace std;

int mcd (int m, int n){

    int r = m % n; // Regresa el residuo de una división
  
    if (r == 0)
    {
        // Condición de parada
        return n;
    }

    else
    {
        // Paso recursivo
        return mcd(n,r);
    }
}

int main(){
    int m, n;
    cout << "Ingresa un número positivo: " ;
    cin >> m;

  while (m <= 0);

  do{
    cout << "Ingresa otro número positivo: " ;
    cin >> n;
  }

    while (n < 0);

    int resultado = mcd(m, n);
    cout << "mcd(" << m << "," << n << ") = " << resultado << endl;

  return 0;
}