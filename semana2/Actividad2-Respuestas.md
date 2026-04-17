### Integrantes: 
- Victor Hugo Cadillo Gutierrez, 20255514D

## Bloque 0

### Demo:
```
victor@victor-desktop:~/clases/algoritmos/CC232-pc/semana2$ ./build/sem2_demo_array_basico
array.length = 5
contenido: 10 20 30 40 50
antes de la asignacion, b[0] = -1
despues de b = a, b.length = 5
b: 10 20 30 40 50
nota: esta version de array usa una asignacion por transferencia de ownership.
```
### Prueba pública:
```
victor@victor-desktop:~/clases/algoritmos/CC232-pc/semana2$ ./build/sem2_test_public_cap2
```

## Bloque 1

1. Memoria contigua es cuando el uso de la memoria se hace de forma consecutiva
2. Acceder a A[i] es de costo O(1) porque es una estructra indexada.
3. La diferencia entre size y capacity, size toma el espacio usado y capacity es la memoria física reservada.
4. Porque trabaja con arrays y los arrays tiene un espacio de memoria reservada fijo, entonces no se puede modificar directamente, para redimensionar se tiene que crear un nuevo array y copiar los contenidos del array original.
5. Porque para agregar un elemento al final solo necesitaría buscar el último elemento con el size y luego insertar el nuevo elemento con size+1.
6. Hacen cosas similares, pero tienen una interfaz diferente, ambos agregan elementos, los buscan, redimensionan y limpian, pero DengVector implementa funciones más específicas como reducir o aumentar el tamaño o aplicar una función a todos los elementos del arreglo.
7. FastArrayStack implementa una lógica para agregar o quitar elmentos mediante una copia directa de una porción usando funciones de una librería STL optimizada, copy y copy_backward.
8. La idea espacial es agregar bloques al final cada vez de el tamaño del bloque final más uno, esto para reducir el uso de memoria con respecto a implementaciones más simples como ArrayStack o FastArrayStack.
9. El diseño de RootishArrayStack hace que aumenten en 1 cada bloque, para que necesite cada vez menos inserciones de bloques a medida que el arreglo crezca.
10. Las tres implementaciones tienen el mismo costo temporal, costo amortizado, sin embargo en el caso de ArrayStack y FastArrayStack la implementación usando librerías optimizadas hace que la implementación sea mejor, tienen el mismo costo espacial y el caso de RootishArrayStack tiene un costo espacial menor, porque a diferencia de los otros que duplican el espacio físico rootisharraystack lo hace de manera adaptativa según el tamaño actual del arreglo pero a costo de una mayor complejidad en la implementación.

### Bloque 2


