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

#### Bloque 5

1. LinkedStack usa un objeto SLList para almacenar los elementos de la pila. Las operaciones de pila como push, pop y top se implementan utilizando de SLList push, pop y peek.
2. LinkedQueue usa un objeto SLList para almacenar los elementos de la cola. Las operaciones de cola como add, remove y front se implementan utilizando de SLList add, remove y peek.
3. LinkedDeque se construye naturalmente sobre DLList porque una deque requiere operaciones eficientes en ambos extremos a la vez, y DLList permite insertar y eliminar elementos tanto al inicio como al final eficientemente, mientras que SLList solo permite operaciones eficientes en un extremo.
4. MinStack guarda el mínimo acumulado al hacer push en cada entrada para que al hacer pop, el mínimo se actualice automáticamente, lo que permite obtener el mínimo en O(1).
5. MinQueue mantiene dos pilas, una para el front y otra para el tail. Al agregar elementos, se insertan en tail y se eliminan por el front. Para mantener FIFO, cuando la pila de front está vacía, se transfieren todos los elementos de la pila de tail a la pila de front, invirtiendo el orden para eliminar el elemento más antiguo. Para mantener la consulta de mínimo, cada pila mantiene su propio mínimo acumulado, y el mínimo total se obtiene comparando los mínimos de las pilas.
6. MinDeque mantiene dos pilas, una para el front y otra para el back. El rebalanceo entre front_ y back_ se hace cuando una de las pilas se queda vacía. En ese caso, se transfieren elementos de la pila no vacía a la pila vacía para mantener la funcionalidad de deque, para que la inserción y eliminación sigan siendo eficientes. 
7. Implementar una estructura como MinDeque requiere diseñar una nueva estructura que almacene información adicional para mantener el mínimo, mientras que adaptar una estructura existente como LinkedStack implica reutilizar la lógica de SLList para implementar la funcionalidad de pila sin modificar la estructura base.
8. Las operaciones de push, pop, add, remove, front, back, removeFirst y removeLast pueden defenderse como O(1) para LinkedStack, LinkedQueue y LinkedDeque. En MinQueue y MinDeque, las operaciones de front, remove, back, removeFirst y removeLast el rebalanceo puede ser O(n) en el peor caso, pero es amortizado O(1) porque ocurre con poca frecuencia.

#### Bloque 6

1.
- size: Devuelve el número de elementos en la lista.
- empty: Verifica si la lista está vacía.
- clear: Elimina todos los elementos de la lista.
- push_front: Agrega un elemento al frente de la lista.
- push_back: Agrega un elemento al final de la lista.
- add: Agrega un elemento a la lista  en una posición específica.
- front: Devuelve el primer elemento de la lista.
- back: Devuelve el último elemento de la lista.
- get: Devuelve el elemento en una posición específica.
- set: Establece el valor de un elemento en una posición específica.
- remove: Elimina un elemento en una posición específica.
- contains: Verifica si un elemento está presente en la lista.
- find_index: Devuelve el índice de un elemento específico en la lista.
- sort: Ordena los elementos de la lista.
- dedup: Elimina elementos duplicados de la lista.
- uniquify: Elimina elementos duplicados consecutivos de la lista.
- reverse: Invierte el orden de los elementos en la lista.

2. Permite reutilizar la lógica de las estructuras de la semana 3 sin modificar su implementación, lo que facilita la integración en la resolución de problemas más complejos.
3.
- to_deng es una función que toma una lista de tipo DLList o SEList y crea un DengList mediante la asignación de elementos. 
- assign_from_deng es una función que toma un DengList y asigna sus elementos a una lista de tipo DLList o SEList, primero limpiando la lista de destino y luego agregando los elementos del DengList.
4. stable_sort_with_deng no obliga a reimplementar el ordenamiento dentro de DLList o SEList porque crea un objeto temporal DengList y lo ordena para luego convertir y retornar la respuesta al tipo original.
5. Similar a stable_sort_with_deng, dedup_with_deng crea un objeto temporal DengList para eliminar los elementos duplicados de la lista original, lo que permite reutilizar la lógica de eliminación de duplicados sin modificar la estructura base. La relación con deduplicate() o uniquify() es que dedup_with_deng implementa una funcionalidad similar a estas funciones, aunque uniquify solo elimina duplicados consecutivos, mientras dedup_with_deng elimina todos los duplicados similar a deduplicate.
6. Similar a stable_sort_with_deng y dedup_with_deng, reverse_with_deng crea un objeto temporal DengList para invertir el orden de los elementos de la lista original usando reverse de DengList, lo que permite reutilizar la lógica de inversión sin modificar la estructura base. 
7. El costo adicional de la conversión entre estructuras es O(n) debido a la necesidad de recorrer todos los elementos para convertirlos de un tipo a otro dos veces. En general no valdría la pena aceptarlo, pero si se tiene que hacer una nueva estructura más compleja podría considerarse aceptable el costo amortizado sobre el de implementación de lógica en la estructura original.

#### Bloque 7 

1. En ArrayDeque, la representación se basa en un arreglo circular, lo que permite un acceso rápido a los elementos pero pierde en costo inserción y eliminación. En cambio, LinkedDeque utiliza una lista doblemente enlazada, lo que permite una inserción y eliminación eficiente en ambos extremos sin necesidad de redimensionar, pero el acceso a elementos es más costoso. En uno el costo de acceso por índice es O(1) y en el otro es O(n), mientras que el costo de inserción y eliminación en ambos extremos es O(1) para LinkedDeque y O(n) para ArrayDeque.
2. La localidad de memoria se refiere a la cercanía en memoria de los datos entre sí. En una representación contigua, los elementos están almacenados uno al lado del otro en la memoria, lo que permite que el acceso a los datos sea más eficiente. 
3. Las operaciones que favorecen más a la representación enlazada son las inserciones y eliminaciones locales, porque solo se reconectan los punteros.
4. 
- La comparación entre radom_get_arraydeque y random_get_dllist sirve mejor para ver el acceso aleatorio. ArrayDeque tiene un costo de acceso por índice O(1) y DLLList tiene un costo de acceso por posición O(n).
- random_get_arraydeque           : 4516
- random_get_dllist               : 111877
- Para comparar extremos ver deque_contiguo_arraydeque y deque_enlazado_linkeddeque, aunque ambos tienen un costo O(1) para inserciones y eliminaciones en extremos, el contiguo tiene mejor rendimiento debido a la localidad de memoria.
- deque_contiguo_arraydeque       : 8140
- deque_enlazado_linkeddeque      : 4159

5. Porque el benchmark mide el rendimiento en casos específicos y puede no reflejar el rendimiento general en todos los escenarios posibles.
6. XorList demuestra como usando XOR puede reducir el espacio utilizado por los punteros al comprimir un puntero como referencia a sus punteros sucesor y anterior.
7. La desventaja práctica de XorList es que el acceso a los elementos se vuelve más complejo y costoso, ya que para acceder a un nodo específico se necesita descomprimir el puntero sucesor y anterior.

#### Bloque 8 

Cuando pasamos de un arreglo a una lista:
- La representación en memoria cambia de contigua a enlazada por punteros.
- Los arreglos son mejores en el acceso por rango comparados a las estructuras enlazadas.
- Las estructuras enlazadas son mejores en las inserciones y eliminaciones comparados a los arreglos.
- Mientras que SLList y DLList ofrecen inserciones y eliminaciones en O(1) en los extremos DLList implementa de forma natural un deque y SEList mejora la eficiencia espacial utilizando bloques de nodos y mantiene una complejidad amortizada de O(1), intenta mantener un equilibrio entre lista y arreglos.
- Con las estructuras base se implementan lógicas Stack, Queue, Deque al separar la interfaz.
- La representación contigua tiene costo de acceso por índice O(1) y la enlazada O(n), mientras que en inserciones es viceversa.

#### Autoevaluación breve

- Qué puedo defender con seguridad: Entiendo los casos de uso de una estructura enlazada vs memoria contigua y los beneficios o limitaciones.
- Qué todavía confundo: Sobre algunos costos y costo amortizado.
-. Qué evidencia usaría en una sustentación: Benchmark, casos borde, casos de pruebas.
