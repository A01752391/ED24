#include <iostream>
#include <vector>
using namespace std;

int suma_vector(vector<int> v, int pos, int n){

  if (pos == n) {
    return v[pos];
  }
  // Paso recursivo
  else {
    return v[pos] + suma_vector(v, pos+1, n);
  }

}

int suma_inversa(vector<int> v, int pos, int n){
if (pos == 0) {
    return v[pos];
  }
  // Paso recursivo
  else {
    return v[pos] + suma_inversa(v, pos-1, n);
  }
}

int main(){
  int n = 0;

  cout << "Entre el número de elementos: ";
  cin >> n;

  while (n < 1); // Verificar que n sea mayor o igual a 1

  vector<int> v(n,1);

  for (int i : v) {
      cout << i << " ";
  }
  cout << endl;

  int resultado = suma_vector (v,0,n-1);
  cout << "La suma de " << n << " elementos = " << resultado << endl;

  int resultado_inv = suma_inversa (v,n-1,n-1);
  cout << "La suma inversa de " << n << " elementos = " << resultado_inv << endl;

  return 0;
};