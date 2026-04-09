## INSTRUCCIONES PARA COMPILAR

Debido a los requerimientos de la práctica se realiza la compilación de dos formas.
1. Se compila con el cmake cuando se trabaja sobre el código por la facilidad que otorga el cmake y también para evaluar los sanitizers.
2. Se compila con un archivo bash para obtener los ejecutables con determinadas banderas.

Para compilar con el cmake se realiza lo siguiente:
1. Moverse a la carpeta build:
```bash
cd build
```
2. En la carpeta build ejecutar el cmake

```bash
cmake ..
cmake --build .
```

Para compilar con las banderas como la de depuración, etc, hacer en la carpeta principal del proyecto.
```bash
./compilacion.sh
```
### Si presenta errores de falta de permiso, primero tendrá que ejecutar, el siguiente comando para darle el permiso de ejecutable:
```bash
chmod +x compilacion.sh
```

## INSTRUCCIONES PARA COMPILAR

Los archivos obtenidos por el cmake se pueden ejecutar en la carpeta build de la siguiente manera:

```bash
./demo_countones
./benchmark
```

Los archivos obtenidos por el bash se pueden ejecutar en la carpeta build_with_flags de la siguiente manera:
```bash
./coverage
./profiling
./test_compacto
./test_depuracion
./test_optimizacion
./test_release
./test_O1
./test_O3
```

## INSTRUCCIONES PARA EJECUTAR PRUEBAS

En la carpeta build ejecutar:

```bash
ctest
```

O también puede ejecutar las pruebas de forma individual usando el ejecutable:
```bash
./test_internal
./test_extra
./edge_cases
```

## TABLA RESUMIDA DE BUILDS Y RESULTADOS

Tabla con resultados obtenidos de ejecutar el comando time en bash y du.

| Build                        | Tiempo de ejecución (s) | Tamaño ejecutable (KB) | Ruta del ejecutable                          |
|------------------------------|-------------------------|------------------------|----------------------------------------------|
| Depuración                   | 1.540                   | 128K                   | ./build_with_flags/test_depuracion           |
| Depuración optimizado        | 0.503                   | 124K                   | ./build_with_flags/test_optimizado           |
| Release                      | 0.401                   | 128K                   | ./build_with_flags/test_release              |
| Compacto                     | 0.454                   | 120K                   | ./build_with_flags/test_compacto             |
| -O1                          | 0.488                   | 128K                   | ./build_with_flags/test_O1                   |
| -O3 compacto                 | 0.498                   | 136K                   | ./build_with_flags/test_O3                   |

Al ser ejecutables de test y al no activar los asserts, las pruebas se ejecutaron correctamente, siguiendo los comportamientos esperables.

## OBSERVACION DE LOS SANITIZERS

Hubo una advertencia sobre tipos incompatibles entre int y static, que se corrigió y
no debería haber otro problema ya que no se usan punteros de forma directa en el código, 
solo en las librerías internas de c++.

## DESCRIPCION DEL BENCHMARK

Se realizo un benchmark para comparar el STL, la versión ingenua y la optimizada.
La version STL usa instrucciones de CPU por lo que es más rápido aunque realice más bucles que
la versión optimizada, la versión ingenua recorre uno por uno las opciones hasta hacer todos los bits cero y
la versión optimizada usa calculos anteriormente obtenidos.

Resultados del benchmark

=== Benchmark (n = 10000000) ===

Metodo              Tiempo (ms)    Operaciones         
-------------------------------------------------------
STL                 129            124434633           
countOnes1          817            124434633           
Optimizado          299            10000000            

## DISCUSIÓN SOBRE MICROOPTIMIZACIÓN VS ALGORITMO

Como se puede observar en el reporte sobre los ejecutables, no hay mejoras considerables usando las 
flags -O1 u -O3, sin embargo la elección de un algoritmo diferente, que reutiliza los cálculos anteriores
si muestra una mejora considerable, del 250%.

## QUÉ SE USO DE COPILOT Y CÓMO SE VALIDÓ

El asistente IA se utilizó principalmente para obtener un boilerplate de códigos, así como para hacer 
debugging de algunos errores, se validó mediante la lectura del código y la ejecución de las pruebas.
