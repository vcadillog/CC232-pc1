### Integrantes: 
- Victor Hugo Cadillo Gutierrez, 20255514D

### Bloque 1

1. En el almacenamiento contiguo la información se guarda en un espacio de memoria consecutivo, mientras en el dinámico los datos se acceden con punteros y las listas no necesariamente van a tener punteros con posiciones de memoria consecutiva.

2. El acceso por rango está asociado a memoria contigua en arrays, por lo que se puede pedir directamente el elemento i, mientras que el acceso por enlace está asociado a estructuras de listas enlazadas, por lo que para pedir un valor se tiene que recorrer cada nodo ya que no posee un índice.

3. Porque una lista enlazada conoce las posiciones exactas del elemento y los conecta con otros elementos mediante punteros y para modificar la información solo necesita reorganizar a quienes apuntan los punteros, mientras que por índice tiene que mover todos los datos siguientes del arreglo para agregar o remover un dato, pero pierde en acceso por índice porque debe recorrer los punteros en lugar de solo acceder al índice lógico del array.

4. Porque puede acceder directamente al primer o último elemento de la lista enlazada.

5. Porque SLList solo maneja una forma LIFO o FIFO y no puede manejar datos en ambos extremos a la vez.

6. dummy sirve para manejar casos borde en el cual la lista está vacía y pueda realizar insertar o eliminar elementos sin complicar la implementación.

7. Expliquen por qué `DLList` permite justificar `get(i)`, `set(i,x)`, `add(i,x)` y `remove(i)` con costo `O(1 + min(i, n-i))`.

8. Expliquen cuál es la idea espacial central de `SEList`.

9. Expliquen por qué `SEList` reutiliza una `BDeque` basada en `ArrayDeque`.

10. Expliquen qué papel cumple `DengList` dentro de esta semana y por qué no reemplaza a las estructuras de Morin.

### Bloque 2

Construyan una tabla con cuatro columnas:

- Archivo
- Salida u observable importante
- Idea estructural
- Argumento de costo, espacio o diseño

- `Semana3/demos/demo_sllist.cpp`
- `Semana3/demos/demo_dllist.cpp`
- `Semana3/demos/demo_selist.cpp`
- `Semana3/demos/demo_deng_list.cpp`
- `Semana3/demos/demo_morin_deng_bridge.cpp`
- `Semana3/demos/demo_capitulo3_panorama.cpp`
- `Semana3/demos/demo_min_structures.cpp`
- `Semana3/demos/demo_xor_list.cpp`
- `Semana3/demos/demo_linked_adapters.cpp`
- `Semana3/demos/demo_contiguous_vs_linked.cpp`

SLList size = 3, peek = 0, DLList: 10 20 30 , SEList: 8 6 7 , LinkedStack top = 200, LinkedQueue front = 11, LinkedDeque front/back = 5/9, ArrayDeque first/last = 4/6
| Archivo | Salida | Idea estructural | Argumento de costo|
| :--- | :---: | :---: | ---: |
| demo_sllist | size = 3 , peek = 5, pop = 5, remove = 10 | SLList | |
| demo_dllist | 10 20 30 |DLList | |
| demo_selist | 0 10 20 30 40 50 60 70 80 90 | | |
| demo_deng_list | | | |
| demo_morin_deng_bridge | | | |
| demo_capitulo3_panorama | SLList size = 3, peek = 0, DLList: 10 20 30 , SEList: 8 6 7 , LinkedStack top = 200, LinkedQueue front = 11, LinkedDeque front/back = 5/9, ArrayDeque first/last = 4/6 | | |
| demo_min_structures | MinStack min=3 top=7, MinQueue min=2 front=4, MinDeque min=1 front=3 back=1 | | |
| demo_xor_list| XorList: 5 10 20 , front=5 back=20 | | |
| demo_linked_adapters| | | |
| demo_contiguous_vs_linked| | | |


Luego respondan:

1. En `demo_sllist.cpp`, ¿qué secuencia deja más clara la coexistencia de comportamiento tipo pila y tipo cola dentro de `SLList`?
2. En `demo_dllist.cpp`, ¿qué operación muestra mejor la inserción en una posición intermedia?
3. En `demo_selist.cpp`, ¿qué observable permite defender que la lista mantiene orden lógico aunque internamente trabaje por bloques?
4. En `demo_deng_list.cpp`, ¿qué evidencia muestra que la lista reforzada por Deng ofrece operaciones más cercanas a un ADT de lista completo?
5. En `demo_morin_deng_bridge.cpp`, ¿qué parte de la salida permite justificar que se reutilizan algoritmos sin reescribir la estructura base?
6. En `demo_min_structures.cpp`, ¿qué diferencia conceptual observan entre almacenar valores y almacenar información adicional para responder `min()`?
7. En `demo_linked_adapters.cpp`, ¿qué adaptador representa mejor la idea de reutilizar una estructura existente para ofrecer una interfaz nueva?
8. En `demo_contiguous_vs_linked.cpp`, ¿qué contraste se observa entre acceso por índice, inserción local y localidad de memoria?

### Bloque 3

1. Valida size, peek, pop y remove.

2. Valida size, get y remove.

3. Valida size, get y remove.

4. 
 -Para SLList  valida to_vector, secondLast, checkSize. 
 -Para DLList  valida to_vector, isPalindrome, checkSize.
 -Para MinStack min y pop.
 -Para MinQueue min, remove y front.
 -Para MinDeque min, back, removeLast y front.
 -Para XorList to_vector.

5. ¿Qué valida específicamente `test_public_linked_adapters.cpp` sobre `LinkedStack`, `LinkedQueue` y `LinkedDeque`?
6. ¿Qué demuestra `test_public_deng_bridge.cpp` sobre integración y reutilización?
7. En `stress_selist_week3.cpp`, ¿qué comportamiento intenta estresar sobre crecimiento, borrado y mantenimiento del tamaño lógico?
8. ¿Qué sí demuestra una prueba pública sobre una estructura enlazada?
9. ¿Qué no demuestra una prueba pública por sí sola?
10. ¿Por qué pasar pruebas no reemplaza una explicación de invariantes, punteros y complejidad?
