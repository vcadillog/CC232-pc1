## PC2 - CC232

### Estudiante
- Nombre: Victor Hugo Cadillo Gutierrez
- Código: 20255514D
- Problema asignado: Flatten a Multilevel Doubly Linked List
- Enlace: https://leetcode.com/problems/flatten-a-multilevel-doubly-linked-list/description/

### Referencia oficial
- Archivo de asignación:
  https://github.com/kapumota/CC-232/blob/main/Practicas/Practica2_CC232/Problemas-Evaluacion2.csv

### Tema principal
- Semana: 4
- Estructura o técnica principal: Listas doblemente enlazada

### Resumen de la solución
El problema nos da una lista doblemente enlazada con múltiples niveles y nos pide que lo aplanemos, es decir pasarlo a una lista doblemente enlazada (sin niveles) y el orden que debe seguir al ser aplanada es que a un nodo padre le siga su nodo hijo y los asociados a su nodo hijo, hasta que encuentre otro nodo hijo y así recursivamente, cuando ya no encuentre más hijos retornar al nivel anterior y colocar los nodos posteriores al salto de nivel.

Entrada del problema:
![alt text](https://assets.leetcode.com/uploads/2021/11/09/flatten11.jpg)
Salida:
![alt text](https://assets.leetcode.com/uploads/2021/11/09/flatten12.jpg)


Para eso reutilizamos el ADT de DLList e implementamos el multinivel siguiendo los siguientes criterios:
- Creamos una función que nos ayude a identificar si el nodo es hijo, esto nos permite hacer otras operaciones como eliminación o evitar que se agreguen más de un hijo en un mismo nivel.
- Agregamos una variable a la estructura que cuenta cuántos nodos en total hay, esto nos permite amortizar el costo de tener que contar todos nodos y se actualiza cada vez que se agrega o eliminan nodos simples o con hijos. 
- La solución ya cuenta con centinela heredado de la clase DLList, que nos permite el trabajo con casos borde, en el que no hay nodos.
- La función de aplanamiento (flatten) devuelve un tipo DLList, lo que asegura que el resultado sea una lista doblemente enlazada, recorre todos los elementos hasta el nodo centinela y va añadiendo los nodos, hasta encontrar un nodo con hijo, entonces llama recursivamente a flatten y contínua al nodo siguiente, así hasta llegar al sentinela y entonces retorna lo que se almaceno en la pila de ejecución hasta regresar al primer nivel.
- Se implementó un intérprete de string que funciona como constructor de la lista multinivel como forma alternativa a la forma tradicional de agregar nodos individualmente, esto según el problema de Leetcode.

### Complejidad
Para la función principal flatten:
- Tiempo: O(n), cada add tiene costo O(1).
- Espacio: O(n+h), h es la pila de la recursión.

### Invariante o idea clave
El invariante de flatten es que el número total de nodos de la estructura multinivel es igual al número de nodos de la estructura aplanada.

### Archivos relevantes
- include/
  - MultiLevelDLList.h
  - DLList.h
- src/
  - MultiLevelDLList.cpp
  - DLList.cpp
- tests/
  - edge_cases.cpp
  - test_internal.cpp
- demos/
  - demo_multileveldllist.cpp

### Compilación
```bash
cmake -S . -B build
cmake --build build
```

### Ejecución
```bash
./build/pc2_demo_create_adt
./bulid/benchmark
./bulid/test_internal
./bulid/edge_cases
```
Para las pruebas:

```bash
ctest --test-dir build
```

### Casos de prueba
test_internal tiene pruebas que:
1. Para casos de prueba verifica que el flatten coincida con un DLList.
2. Prueba que para eliminar un nodo padre el flatten no muestra el padre, el hijo asociado y que su tamaño coincide con el equivalente DLList.
3. Prueba que cuando se ingresa la información de la lista multinivel mediante la forma manual con add coincide con su representación en string.

### Declaración de autoría
Declaro que entiendo el código entregado, que puedo explicarlo, compilarlo, ejecutarlo y modificarlo sin ayuda externa durante la grabación.
