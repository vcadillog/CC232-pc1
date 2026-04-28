## Actividad 4-CC232

### Estudiante
- Cadillo Gutierrez, Victor Hugo 20255514D

#### Bloque 1 
1. El acceso LIFO se refiere a una estructura de datos donde el último elemento agregado es el primero en ser removido. Mientras que el acceso FIFO se refiere a una estructura de datos donde el primer elemento agregado es el primero en ser removido. LIFO se basa en el orden inverso de llegada, mientras que FIFO se basa en el orden de llegada.
2. El Stack es una estructura de datos que sigue el principio LIFO, lo que significa que el último elemento agregado es el primero en ser removido. Esto lo hace ideal para resolver problemas donde importa lo último pendiente porque permite acceder rápidamente al último elemento agregado sin tener que recorrer toda la estructura. 
3. Queue es una estructura de datos que sigue el principio FIFO, lo que significa que el primer elemento agregado es el primero en ser removido. Esto la hace ideal para modelar procesos de espera y atención porque permite atender a los elementos en el orden en que llegaron. Como manejar las personas en una fila de espera.
4. Reemplazar recursión implícita por una estructura explícita significa que en lugar de confiar en la pila de llamadas del sistema para manejar el estado de las funciones recursivas, se utiliza una estructura de datos explícita, como una pila o una cola, para almacenar y gestionar el estado de las operaciones. Esto permite abstraer el ADT y reutilizar la lógica de pila o cola.
5. La información mínima que debe guardarse en una pila para permitir reconstruir una solución parcial es el estado actual del problema que se está resolviendo. Esto puede incluir variables relevantes, decisiones tomadas, y cualquier información necesaria para continuar el proceso desde ese punto específico. Esta información permite que al desapilar, se pueda volver a ese estado y continuar la resolución del problema sin perder el contexto.


#### Bloque 2 - Demostración y trazado guiado


| Archivo                          | Salida u observable importante                                                                 | Estructura o técnica central      | Qué concepto permite defender                                                                 |
|----------------------------------|------------------------------------------------------------------------------------------------|-----------------------------------|----------------------------------------------------------------------------------------------|
| demo_stack_queue.cpp             | Tope de la pila = 9, Frente de la cola = 10, Elemento desapilado = 9, Elemento desencolado = 10 | Stack y Queue                     | Diferencia entre LIFO (pila) y FIFO (cola)                                                 |
| demo_base_conversion.cpp         | 12345 en base 8 (recursivo) = 30071, 12345 en base 8 (iterativo) = 30071                      | Recursión e Iteración             | Diferentes implementaciones producen la misma respuesta|
| demo_paren_rpn.cpp               | Paréntesis balanceados = true, RPN = 0 ! 1 + 2 3 ! 4 + ^ * 5 ! 67 - 8 9 + - -, Valor = 2012   | Paréntesis, RPN, evaluación       | Uso de pilas para precedencia |
| demo_nqueens.cpp                 | N = 4, soluciones = 2, verificaciones = 84                                                     | Backtracking                      | Explora combinaciones usando pila                                           |
| demo_maze.cpp                    | Medida del camino = 5, (1,1) (1,2) (1,3) (2,3) (3,3)                                          | Backtracking                      | Explora rutas usando pila |
| demo_bank.cpp                    | Llegadas = 7, atendidos = 0, estados para t                                                     | Simulación de colas               | Evolución del sistema usando FIFO                                                            |
| demo_capitulo4_panorama.cpp      | Recopilacion semana 4, pila=2, cola=10, base8=30071, balanceo=true, RPN, valor=2012, N=2, camino=5, banco=5/0 | Integración de técnicas           | Recopila y unifica estructuras, algoritmos en distintos problemas                                      |

Luego responde:

1. En demo_stack_queue, la parte de la salida que deja más clara la diferencia entre tope y frente es cuando se muestra el "Tope de la pila = 9" y el "Frente de la cola = 10". Esto resalta que el tope de la pila representa el último elemento agregado (LIFO), mientras que el frente de la cola representa el primer elemento agregado (FIFO). Además, al mostrar el "Elemento desapilado = 9" y el "Elemento desencolado = 10", lo resalta, ya que el elemento desapilado es el último en entrar a la pila, mientras que el elemento desencolado es el primero en entrar a la cola.
2. En demo_base_conversion, el observable que permite afirmar que las versiones recursiva e iterativa producen la misma representación es el resultado final de la conversión de 12345 en base 8, que es "30071". 
3. En demo_paren_rpn, la relación entre paréntesis balanceados, RPN y el valor final es que el balanceo de paréntesis es que la expresión tenga una apertura de paréntesis ( asociado a un cierre ) en la jerarquía correcta y los elimina, y pueda ser convertida a notación RPN. Y con la notación RPN, se puede obtener el valor final.

4. En `demo_nqueens.cpp`, ¿qué significan `solutions` y `checks`, y por qué no miden lo mismo?
4. En demo_nqueens solutions se refiere al número de configuraciones válidas de reinas en el tablero que cumplen con las reglas del juego (es decir, ninguna reina ataca a otra). checks se refiere al número de veces que el algoritmo verifica si una posición es válida para colocar una reina. No miden lo mismo porque `solutions` cuenta solo las configuraciones finales que son correctas, mientras que `checks` cuenta todas las verificaciones realizadas durante el proceso de búsqueda, incluyendo aquellas que resultan en configuraciones inválidas.
5. En `demo_maze.cpp`, ¿qué muestra la secuencia de coordenadas sobre el camino encontrado?
6. En `demo_bank.cpp`, ¿qué representa cada lista impresa en cada instante `t`?
7. En `demo_capitulo4_panorama.cpp`, ¿qué salida resume mejor la idea de que una misma semana reúne estructuras y aplicaciones?

#### Bloque 3 
#### Bloque 4 
#### Bloque 5 
#### Bloque 6 
#### Bloque 7 
#### Bloque 8 
