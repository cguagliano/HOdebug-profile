#include <stdio.h>

int add_array(int *a, int *b, int n){
  int sum = 0;
  int i = 0;
  for (i = 0; i <= n+1 ; i++) { //n fuera de rango, debería ser desde 0 hasta n-1
    sum += abs(a[i]);
    sum += abs(b[i]);
  };
  return sum;
}

int main(int argc, char **argv) {
  int *a, *b;     //los punteros se definen pero no hago reserva de memoria dinamica ni defino los vectores a los cuales apuntaran. 
  int n = 3;
  int i, sum;
  for (i = 0; i < n; i++) { //aca se produce el segmentation fault, intento cargarle datos a los vectores a y b pero nunca reserve espacio ni le dije el tamaño ya que solo definí los punteros y no los vectores ni estatica ni dinamicamente
    a[i] = i;
    b[i] = i;
  }
  sum = add_array(a, b, 3);
  printf("The addition is %d\n", sum);
  return 0;
}
