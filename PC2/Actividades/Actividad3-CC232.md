### Integrantes: 
- Victor Hugo Cadillo Gutierrez, 20255514D

### Bloque 1

1. En el almacenamiento contiguo la información se guarda en un espacio de memoria consecutivo, mientras en el dinámico los datos se acceden con punteros y las listas no necesariamente van a tener punteros con posiciones de memoria consecutiva.
2. El acceso por rango está asociado a memoria contigua en arrays, por lo que se puede pedir directamente el elemento i, mientras que el acceso por enlace está asociado a estructuras de listas enlazadas, por lo que para pedir un valor se tiene que recorrer cada nodo ya que no posee un índice.
3. Porque una lista enlazada conoce las posiciones exactas del elemento y los conecta con otros elementos mediante punteros y para modificar la información solo necesita reorganizar a quienes apuntan los punteros, mientras que por índice tiene que mover todos los datos siguientes del arreglo para agregar o remover un dato, pero pierde en acceso por índice porque debe recorrer los punteros en lugar de solo acceder al índice lógico del array.
4. Porque puede acceder directamente al primer o último elemento de la lista enlazada.
5. Porque SLList solo maneja una forma LIFO o FIFO y no puede manejar datos en ambos extremos a la vez, pero al elegir un extremo para ir al otro según el uso LIFO o FIFO, tiene que recorrer toda la lista para llegar al otro extremo, lo que hace que el costo de las operaciones de inserción o eliminación sea O(n) en lugar de O(1).
6. dummy sirve para manejar casos borde en el cual la lista está vacía y pueda realizar insertar o eliminar elementos sin complicar la implementación.
7. El los métodos get, set, add y remove usan getNodo que recorre la lista desde el inicio o el final dependiendo de si i es menor o mayor a n/2, por lo que el costo es O(1 + min(i, n-i)) porque se recorre como máximo la mitad de la lista.
8. La idea espacial central de SEList es que cada nodo de la lista enlazada contiene un bloque de elementos en un arreglo, lo que permite reducir el número de nodos y punteros necesarios para almacenar datos.
9. SEList usa un BDeque basado en ArrayDeque porque cada nodo de SEList contiene un bloque de elementos que se maneja como un deque, operaciones de inserción y eliminación dentro de cada bloque.
10. DengList es una estructura ADT de lista que ofrece operaciones adicionales como inserción y eliminación en cualquier posición no solo casos FIFO o LIFO, pero no reemplaza a las estructuras de Morin porque estas últimas son más simples y eficientes para casos específicos.

### Bloque 2

| Archivo | Salida u observable importante | Idea estructural | Argumento de costo, espacio o diseño |
| :--- | :---: | :---: | ---: |
| `demo_sllist.cpp` | size = 3, peek = 5, pop = 5, remove = 10 | SLList maneja tanto comportamiento tipo pila como tipo cola | El costo para insertar o eliminar en un extremo es O(1)|
| `demo_dllist.cpp` | 10 20 30 | | Lista doblemente enlazada | El costo para insertar o eliminar en cualquier posición conocida es O(1) |
| `demo_selist.cpp` | 0 10 20 30 40 50 60 70 80 90 | Maneja bloques de elementos en cada nodo | El costo para get es O(1 + min{i, n - i}/b)|
| `demo_deng_list.cpp` | size = 4, front = 5, back = 20, ordenada: 5 10 20 30 | Lista doblemente enlazada | El costo para insertar o eliminar en cualquier posición conocida es O(1) |
| `demo_morin_deng_bridge.cpp` | DLList reforzada con Deng: 1 2 3 4, Removido = 1 | Convierte un DLList a un DengList| Convierte un DLList a un tipo compatible con DengList con to_vector |
| `demo_capitulo3_panorama.cpp` | SLList size = 3, peek = 0, DLList: 10 20 30, SEList: 8 6 7, LinkedStack top = 200, LinkedQueue front = 11, LinkedDeque front/back = 5/9, ArrayDeque first/last = 4/6 | Recopilación de estructuras estudiadas| Permite comparar principalmente inserciones |
| `demo_min_structures.cpp` | MinStack min=3 top=7, MinQueue min=2 front=4, MinDeque min=1 front=3 back=1 | Estructuras que almacenan el mínimo | Permite obtener el mínimo en O(1) |
| `demo_xor_list.cpp` | XorList: 5 10 20, front=5 back=20 | Lista enlazada con operaciones XOR | Comprime el espacio de dos punteros a la mitad usando XOR entre el sucesor y anterior |
| `demo_linked_adapters.cpp` | LinkedStack: top() = 30, pop() = 30, top() = 20, size() = 2 | Adaptadores de estructuras enlazadas | Reutiliza una estructura base para crear una interfaz con operaciones más concretas|
| ^ | LinkedQueue: front() = 1, remove() = 1, front() = 2, size() = 2| ^ | ^ |
| ^ | LinkedDeque: front() = 10, back() = 40, removeFirst() = 10, removeLast() = 40, front() = 20, back() = 30, size() = 2| ^ | ^ |
| `demo_contiguous_vs_linked.cpp` | FIFO: front/remove:1/1, Deque: first/last: a/d, Acceso por indice: get(4) = 40 | Contraste entre estructuras contiguas y enlazadas | El acceso por índice es O(1) en contiguo y O(n) en enlazado, la inserción local es O(n) en contiguo y O(1) en enlazado |


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
