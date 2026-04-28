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
| `demo_linked_adapters.cpp`| LinkedStack: top() = 30, pop() = 30, top() = 20, size() = 2<br>LinkedQueue: front() = 1, remove() = 1, front() = 2, size() = 2<br>LinkedDeque: front() = 10, back() = 40, removeFirst() = 10, removeLast() = 40, front() = 20, back() = 30, size() = 2| Adaptadores de estructuras enlazadas | Reutiliza una estructura de lista enlazada para implementar lógicas de pila, cola y deque|
| `demo_contiguous_vs_linked.cpp` | FIFO: front/remove:1/1, Deque: first/last: a/d, Acceso por indice: get(4) = 40 | Contraste entre estructuras contiguas y enlazadas | El acceso por índice es O(1) en contiguo y O(n) en enlazado, la inserción local es O(n) en contiguo y O(1) en enlazado |

1. En demo_sllist se muestra la secuencia de inserciones 10, 20, 5 y luego se muestra el resultado de peek y pop que devuelve 5, lo que muestra el comportamiento tipo pila, pero luego se muestra el resultado de remove que devuelve 10, propio de un comportamiento tipo cola.
2. En demo_dllist se muestra add(1,20) la operación de inserción en la posición 1 con el valor 20, lo que demuestra la capacidad de la lista doblemente enlazada para insertar en cualquier posición conocida con un costo O(1).
3. En demo_selist, el observable get(i) muestra la salida de los elementos en orden lógico (0, 10, 20, 30, 40, 50, 60, 70, 80, 90) a pesar de que internamente se maneja por bloques.
4. En demo_deng_list se muestra la secuencia de inserciones que da el resultado: 5,30,10,20 y luego se muestra la salida de front, back y to_vector que devuelve 5, 20 y 5 10 20 30 para sort. 
5. En demo_morin_deng_bridge se muestra la salida de to_vector que devuelve 1 2 3 4, lo que demuestra que se ha convertido un DLList a un tipo compatible con DengList sin modificar la estructura base, sino usando una función puente.
6. En demo_min_structures se muestra que cada estructura almacena información adicional para responder min() en O(1), MinStack guarda en la estructura el mínimo para cada push, no se cambia la idea estructural de pila o cola, pero se optimiza la busqueda de elementos mínimos.
7. En demo_linked_adapters, LinkedDeque tiene una implementación que abstrae mejor las operaciones de deque, mientras que en LinkedStack y LinkedQueue al utilizar SLList las operaciones de pila o cola ya eran naturales por lo que la implementación es mínima.
8. En demo_contiguous_vs_linked, se observa el contraste. El acceso por índice es O(1) en estructuras contiguas, mientras que es O(n) en estructuras de listas enlazadas. La inserción local es O(n), mientras que es O(1) en estructuras de listas enlazadas y la localidad de memoria es mejor en estructuras contiguas porque los datos almacenadas una al lado del otro y en las listas enlazadas la localidad se dispersa ya que los punteros no se almacenan necesariamente en posiciones de memoria consecutivas.

### Bloque 3

1. Valida size, peek, pop y remove.
2. Valida size, get y remove.
3. Valida size, get y remove.
4. 
 - Para SLList  valida to_vector, secondLast, checkSize. 
 - Para DLList  valida to_vector, isPalindrome, checkSize.
 - Para MinStack min y pop.
 - Para MinQueue min, remove y front.
 - Para MinDeque min, back, removeLast y front.
 - Para XorList to_vector.
5. 
 - Para LinkedStack valida empty, size, top y pop.
 - Para LinkedQueue valida empty, size, front y remove.
 - Para LinkedDeque valida empty, size, front, back, removeFirst y removeLast.
6. Valida que se puede convertir un DLList a un equivalente en DengList sin modificar las estructuras base.  
7. En stress_selist_week3 se intenta estresar el comportamiento de crecimiento al insertar elementos hasta llenar un bloque y forzar la creación de un nuevo nodo, el comportamiento de borrado al eliminar elementos para vaciar bloques y nodos, y el mantenimiento del tamaño lógico al verificar que el tamaño final coincida con el número de elementos insertados y eliminados.
8. Las pruebas públicas demuestran que las implemenentaciones de las estructuras enlazadas tienen el resultado esperado.
9. Las pruebas públicas no pueden demostrar que todas las entradas den una salida correcta, pueden existir casos borde que no cumplan con lo esperado.
10. Porque pasar pruebas solo demuestra que la implementación funciona para los casos de prueba específicos e invariantes y complejida siguen ideas de diseño teóricas.

### Bloque 4

1. En SLList, head representa un puntero al primer nodo de la lista enlazada, tail representa un puntero al último nodo y n representa el número de elementos en la lista. 
2.
 - Con push, se crea un nuevo nodo u con el valor ingresado y reconecta su next con el head y si la lista estaba vacía conecta el tail a u. 
 - Con pop se llama a remove, se guarda el puntero del head, se reconecta el head al siguiente nodo y si la lista queda vacía se reconecta el tail a nullptr.
 - Con add se crea un nuevo nodo u con el valor ingresado, si está vacio reconecta el head y tail a u, si no reconecta tail y el siguiente del tail a u.
 - Con remove, se guarda el puntero del head, se reconecta el head al siguiente nodo y si la lista queda vacía se reconecta el tail a nullptr.
3. secondLast() verifica que tenga al menos dos elementos y recorre la lista desde el head hasta llegar al nodo que apunta al tail. No se puede resolver directamente con tail porque solo tiene información del último nodo y no tiene un puntero hacia el nodo anterior.
4. reverse() recorre la lista desde el head, intercambia su next con el nodo anterior prev. Al finalizar el bucle, intercambia head y tail. No necesita estructura auxiliar porque solo se reconectan los punteros.
5. checkSize() recorre la lista desde el head contando el número de nodos y lo compara con n. Y ayuda a defender la correctitud porque verifica que la cantidad de nodos coincida con lo contado y además head y tail tenga punteros esperados.
6. Porque DLList implementa una lista doblemente enlazada, que tiene punteros en ambas direcciones para cada nodo, lo que permite recorrer la lista desde el inicio o desde el final.
7. addBefore actualiza los enlaces del nodo nuevo u, el nodo siguiente next y el nodo anterior prev. El nodo centinela elimina casos borde porque siempre existe un nodo antes y después del nodo nuevo.
8. rotate(r) cambia el primer nodo (dummy/sentinela) por el nodo en la posición r, esto mediante reconección de los punteros del nodo en posición r como primer nodo, esto hace que las posiciones lógicas se vean respecto al nodo en posición r.
9. isPalindrome() verifica que los elementos extremos de la lista sean iguales y luego actualiza los punteros en ambos extremos hasta llegar al centro si los elementos son iguales o se detiene cuando alguno no coincide.
10. Location es una estructura que representa la ubicación de un nodo dentro de SEList, con un puntero al nodo que contiene el bloque y un índice de la posición del bloque que contiene el índice lógico i. Con esto se accede a los elementos del bloque de manera eficiente.
11. spread reparte los elementos de un bloque lleno a un bloque vecino. gather junta los elementos de un bloque con un bloque vecino. spread se usa cuando se quiere insertar elementos en un bloque en el futuro de forma eficiente y gather para reducir el espacio utilizado por la estructura de datos.
12. Un bloque más grande reduce el número de nodos y punteros necesarios, lo que mejora la eficiencia espacial, pero aumenta el costo de acceso a elementos individuales dentro del bloque, ya que se necesita recorrer el bloque para encontrar el elemento deseado. Por otro lado, un bloque más pequeño aumenta el número de nodos y punteros, lo que aumenta el costo espacial, pero reduce el costo de acceso a elementos individuales dentro del bloque.

#### Bloque 5 - Adaptadores y estructuras derivadas

Revisen:

- `Semana3/include/LinkedStack.h`
- `Semana3/include/LinkedQueue.h`
- `Semana3/include/LinkedDeque.h`
- `Semana3/include/MinStack.h`
- `Semana3/include/MinQueue.h`
- `Semana3/include/MinDeque.h`
- `Semana3/demos/demo_linked_adapters.cpp`
- `Semana3/demos/demo_min_structures.cpp`

Respondan:

1. ¿Cómo reutiliza `LinkedStack` a `SLList`?
2. ¿Cómo reutiliza `LinkedQueue` a `SLList`?
3. ¿Por qué `LinkedDeque` se construye naturalmente sobre `DLList` y no sobre `SLList`?
4. En `MinStack`, ¿por qué cada entrada guarda el valor y el mínimo acumulado?
5. En `MinQueue`, ¿por qué usar dos pilas permite mantener semántica FIFO y consulta de mínimo?
6. En `MinDeque`, ¿qué problema resuelve el rebalanceo entre `front_` y `back_`?
7. Comparen "implementar una estructura" y "adaptar una estructura existente" usando ejemplos de este bloque.
8. ¿Qué operaciones pueden defender como constantes y cuáles deben defender como amortizadas?

#### Bloque 6 - Deng como refuerzo algorítmico y puente de integración

Revisen:

- `Semana3/include/CleanList.h`
- `Semana3/include/DengList.h`
- `Semana3/include/MorinDengBridge.h`
- `Semana3/demos/demo_deng_list.cpp`
- `Semana3/demos/demo_morin_deng_bridge.cpp`
- `Semana3/pruebas_publicas/test_public_deng_bridge.cpp`
- `Semana3/pruebas_internas/test_internal_deng_algorithms.cpp`
- `Parte3-Deng.pdf`

Respondan:

1. ¿Qué operaciones del ADT de lista aparecen reforzadas en `DengList`?
2. ¿Qué ventaja tiene encapsular una lista más rica sin cambiar el resto de estructuras de Semana 3?
3. Expliquen qué hacen `to_deng` y `assign_from_deng`.
4. Expliquen por qué `stable_sort_with_deng` no obliga a reimplementar ordenamiento dentro de `DLList` o `SEList`.
5. Expliquen qué hace `dedup_with_deng` y qué relación guarda con `deduplicate()` o `uniquify()` de la teoría.
6. Expliquen por qué `reverse_with_deng` es un ejemplo de reutilización de algoritmos sobre una interfaz común.
7. ¿Qué costo adicional introduce la conversión entre estructuras y cuándo vale la pena aceptarlo?

#### Bloque 7 - Comparación enlazado vs contiguo, variantes y evidencia experimental

Revisen:

- `Semana3/include/ArrayDeque.h`
- `Semana3/include/XorList.h`
- `Semana3/demos/demo_contiguous_vs_linked.cpp`
- `Semana3/demos/demo_xor_list.cpp`
- `Semana3/benchmarks/benchmark_semana3.cpp`
- `Parte3-Morin.pdf`

Respondan:

1. Comparen `ArrayDeque` y `LinkedDeque`: ¿qué cambia en representación y qué cambia en costo observable?
2. ¿Qué significa que una representación contigua tenga mejor localidad de memoria?
3. ¿Qué tipo de operaciones favorecen más a la representación enlazada?
4. En el benchmark, ¿qué comparación sirve mejor para discutir acceso aleatorio y cuál sirve mejor para discutir operaciones en extremos?
5. ¿Por qué el benchmark no debe leerse como prueba absoluta de superioridad de una estructura sobre otra?
6. ¿Qué idea intenta mostrar `XorList` respecto al ahorro de punteros?
7. ¿Qué desventaja práctica introduce una estructura como `XorList` aunque sea interesante desde el punto de vista del espacio?.

#### Bloque 8 - Cierre comparativo y preparación de sustentación

Respondan esta pregunta final:

¿Qué cambia cuando pasamos de "usar arreglos dinámicos" a "diseñar estructuras enlazadas y adaptadores sobre nodos"?

La respuesta debe incluir obligatoriamente:

- Una afirmación sobre representación
- Una afirmación sobre acceso por rango frente a acceso por posición
- Una afirmación sobre inserciones y eliminaciones locales
- Una afirmación sobre complejidad de `SLList`, `DLList` y `SEList`
- Una afirmación sobre reutilización mediante adaptadores o puentes
- Una comparación entre representación contigua y enlazada.
