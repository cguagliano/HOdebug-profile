La aplicacion small.e corre sin errores aparentes
La aplicación big.e corre y genera un segmentation fault

Al ejecutar la sentencia ulimit -s unlimited ya no tengo errores en tiempo de ejecución ni en small ni en big

Esta solución no es una forma de debug, una solución real sería asignar en forma dinámica la memoria para los elementos de la matriz.
