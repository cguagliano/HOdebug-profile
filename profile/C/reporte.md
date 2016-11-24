Primero se compilo el programa profile_me_1.c con

gcc -pg -o0 profile_me_1.c -o test_profile

./test_profile

Esto me generaba una violacion de segmento y no me producia el archivo gmon.out
Tuve que modificar la cantidad de elementos de la matriz
En un primer momento cambie el SIZE a 50 pero en el reporte me producia todos los datos en 0
Luego lo cambie a 500 y obtuve los siguientes datos:

Each sample counts as 0.01 seconds.
  %   cumulative   self              self     total           
 time   seconds   seconds    calls  ns/call  ns/call  name    
 50.29      0.01     0.01   250000    40.23    40.23  first_assign
 50.29      0.02     0.01   250000    40.23    40.23  second_assign


Al compilar con -o1 obtuve los siguientes datos:

Each sample counts as 0.01 seconds.
  %   cumulative   self              self     total           
 time   seconds   seconds    calls  ns/call  ns/call  name    
100.58      0.01     0.01   250000    40.23    40.23  first_assign
  0.00      0.01     0.00   250000     0.00     0.00  second_assign
