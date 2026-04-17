#### Ejercicio 4. `shrink()` y reducción amortizada

La reducción de capacidad también forma parte del diseño de un arreglo dinámico eficiente.

##### Se pide

1. Revisar cómo se reduce capacidad en `DengVector` y cómo se redimensiona el arreglo en `ArrayStack`.

###### DengVector
ArrayStack
```
    void shrink() {
        if (_capacity <= DEFAULT_CAPACITY * 2) return;
        if (_size * 4 > _capacity) return;
        T* oldElem = _elem;
        _capacity >>= 1;
        if (_capacity < DEFAULT_CAPACITY) _capacity = DEFAULT_CAPACITY;
        _elem = new T[_capacity];
        for (int i = 0; i < _size; ++i) {
            _elem[i] = oldElem[i];
        }
        delete[] oldElem;
    }
```
Si la capacidad es menor a DEFAULT_CAPACITY (para el caso es 3) entonces se reduce el array.

###### ArrayStack
```
template<class T>
void ArrayStack<T>::resize() {
	array<T> b(max(2 * n, 1));
	for (int i = 0; i < n; i++)
		b[i] = a[i];
	a = b;
}
```

El arreglo se redimensiona al doble de la capacidad actual en ArrayStack.

2. Explicar qué condición debe cumplirse para que una reducción de capacidad sea razonable.

La condición que debe cumplirse en DengVector es si la capacidad es menor a DEFAULT_CAPACITY se redimensiona.

3. Justificar por qué no conviene reducir el arreglo después de cada eliminación.

shrink() es llamado después de cada remove() al final.
Si el arreglo se reduciera para cada iteración introduciría un costo de O(n) para cada eliminiación, lo que sería bastante costoso.

4. Argumentar informalmente por qué el costo amortizado de las reducciones puede mantenerse en `O(1)` por operación.

Porque al hacerse solo en pocas iteraciones del total el impacto no es tan grande

5. Comparar el papel de `expand()` y `shrink()` dentro del equilibrio entre tiempo y espacio.

