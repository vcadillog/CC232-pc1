## Solucionario Examen Parcial - CC232
## Versión A

### Estudiante
- Nombre: Victor Hugo Cadillo Gutierrez
- Código: 20255514D

### Pregunta 1

#### a)

La parte que pertenece al ADT es aquella que define que hace la estructura:
Ejemplo:
```cpp
public:
    int size() const;
    T get(int i) const;
```
La parte que pertenece a la implementación no está definida, pero menciona que hay dos tipos de implementación, una por arreglo dinámico y otro con lista doblemente enlazada.
Ejemplo para lista doblemente enlazada:
```cpp
    int size(){
        return n; //n es el tamaño de la lista enlazada
        }
```
Ejemplo para arreglo dinámico:
```cpp
    T get(int i){
        return a[i]; //a es el arreglo de la estructura
        }
```

#### b)
 
Costos en el peor caso
| Implementación | get | set | add | remove |
| :--- | :---: | :---: | :---: | ---: |
| I | O(1) | O(1) | O(n) | O(n) |
| II | O(n) | O(n) | O(1) | O(1) |

No hay costos amortizados para estructuras de listas doblemente enlazadas (implementación II), solo para arreglos (Implementación I).
El costo amortizado del redimensionamiento es:
| add | remove |
| :--- | ---: |
| O(1) | O(1) |

#### c)

Implementación I: Un invariante es que el tamaño del arreglo nunca supera a la cadacidad.
Implementación II: El nodo centinela dummy siempre está conectado al inicio y al final de la lista doblemente enlazada.

Una mala implementación podría romper la invariante, para:
Implementación I: Si no se detecta que size es igual capacity y no se hace redimensionamiento, entonces se puede romper la invariante. 
Implementación II: Si se elimina un nodo y deja una lista vacía y luego no se reconecta correctamente los punteros de dummy a sí mismo como inicio y final de la lista.

#### d)

Una lista enlazada no garantiza que add(i,x) sea O(1) porque esta solo conoce la posición inicial y final, pero no conoce la posición i y tiene que buscarla, lo que cuesta O(n) en el peor caso, pero la acción de insertar cuesta O(1).

### Pregunta 2
### Pregunta 3
### Pregunta 4
### Pregunta 5
### Pregunta 6
### Pregunta 7


