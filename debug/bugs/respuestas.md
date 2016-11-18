1) Los codigos que presentan bugs son: add_array_segfault y add_array_static. Con el debugger el primero indica que tengo un segmentation fault en el main, el segundo me da un resultado erroneo pero la ejecución se realiza correctamente por lo que no me da ninguna pista del posible bug.

corriendo con gdb el archivo add_array_segfault:

celeste@chicaLunar:~/Escritorio/Tecnicas de Programación Cientifica/Cla
se4/HOdebug-profile/debug/bugs$ gdb add_array_segfault.e
GNU gdb (Ubuntu 7.10-1ubuntu2) 7.10
Copyright (C) 2015 Free Software Foundation, Inc.
License GPLv3+: GNU GPL version 3 or later <http://gnu.org/licenses/gpl.html>
This is free software: you are free to change and redistribute it.
There is NO WARRANTY, to the extent permitted by law.  Type "show copying"
and "show warranty" for details.
This GDB was configured as "x86_64-linux-gnu".
Type "show configuration" for configuration details.
Para las instrucciones de informe de errores, vea:
<http://www.gnu.org/software/gdb/bugs/>.
Find the GDB manual and other documentation resources online at:
<http://www.gnu.org/software/gdb/documentation/>.
For help, type "help".
Type "apropos word" to search for commands related to "word"...
Leyendo símbolos desde add_array_segfault.e...(no se encontraron símbolos de depuración)hecho.
(gdb) run
Starting program: /home/celeste/Escritorio/Tecnicas de Programación Cientifica/Clase4/HOdebug-profile/debug/bugs/add_array_segfault.e 

Program received signal SIGSEGV, Segmentation fault.
0x00000000004005fb in main ()
(gdb) 

Me dice que tengo un segmentation fault en el main


Modifico los flags para compilar con -g -Wall, el debugger con gdb obtengo lo siguiente:

celeste@chicaLunar:~/Escritorio/Tecnicas de Programación Cientifica/Clase4/HOdebug-
profile/debug/bugs$ gdb ./add_array_segfault.e 
GNU gdb (Ubuntu 7.10-1ubuntu2) 7.10
Copyright (C) 2015 Free Software Foundation, Inc.
License GPLv3+: GNU GPL version 3 or later <http://gnu.org/licenses/gpl.html>
This is free software: you are free to change and redistribute it.
There is NO WARRANTY, to the extent permitted by law.  Type "show copying"
and "show warranty" for details.
This GDB was configured as "x86_64-linux-gnu".
Type "show configuration" for configuration details.
Para las instrucciones de informe de errores, vea:
<http://www.gnu.org/software/gdb/bugs/>.
Find the GDB manual and other documentation resources online at:
<http://www.gnu.org/software/gdb/documentation/>.
For help, type "help".
Type "apropos word" to search for commands related to "word"...
Leyendo símbolos desde ./add_array_segfault.e...hecho.
(gdb) run
Starting program: /home/celeste/Escritorio/Tecnicas de Programación Cientifica/Clase4/HOdebug-profile/debug/bugs/add_array_segfault.e 

Program received signal SIGSEGV, Segmentation fault.
0x00000000004005fb in main (argc=1, argv=0x7fffffffdf38)
    at add_array_segfault.c:19
19	    b[i] = i;
(gdb) 

Me indica la linea en donde tengo el inconveniente del segmentation fault. Puedo ver que el problema esta con la asginación al vector b... al revisar encuentro que estoy declarando b como un puntero, pero no lo apunto a ningun vector ni le asigno memoria dinamica...
