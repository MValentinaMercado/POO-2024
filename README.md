# POO-2024

### [Ejercicio 01](https://github.com/MValentinaMercado/POO-2024/tree/main/Ejercicio-01) 

- Generar y mostrar números aleatorios en el intervalo [2, 20] utilizando QtCreator.

### [Ejercicio 03](https://github.com/MValentinaMercado/POO-2024/tree/main/Ejercicio-03)

- Elija un nombre para su propio espacio de nombres para todo lo que se haga en este asignatura
- Luego de elegido el nombre para su namespace, defina una función dentro de ese namespace para devolver el número de versión junto con la fecha de la última actualización de la biblioteca
```cpp
 QString getVersion();
```
### [Ejercicio 04](https://github.com/MValentinaMercado/POO-2024/tree/main/Ejercicio-04) 

- Crear un std::vector para contener int
- Cargar 30 valores pseudo aleatorios entre 1 y 15
- Publicar la moda

### [Ejercicio 05](https://github.com/MValentinaMercado/POO-2024/tree/main/Ejercicio-05)

- Crear un std::vector para contener objetos de la clase std::string
- Cargar 5 expresiones idiomáticas, como por ejemplo: pan comido
- Publicar por consola ordenado alfabéticamente

### [Ejercicio 06](https://github.com/MValentinaMercado/POO-2024/tree/main/Ejercicio-06)

- Crear una nueva clase (que no sea Persona, ni Cliente, ni Poste). Invente una clase.
- Agregar uno o más constructores, agregar sus métodos y sus atributos
- Crear algunos objetos de esta clase en la función main

### [Ejercicio 07](https://github.com/MValentinaMercado/POO-2024/tree/main/Ejercicio-07)

- Utilizar la clase creada en el ejercicio anterior para crear objetos y almacenarlos en un std::vector
- ¿Se pueden ordenar? Qué estrategia utilizaría para ordenarlos de menor a mayor


### [Ejercicio 08](https://github.com/MValentinaMercado/POO-2024/tree/main/Ejercicio-08)

- Crear una función genérica que imprima por consola una descripción de cualquier objeto.
- El mensaje puede ser algo así: "Persona con nombre Lucrecia", "Poste con altura de 8 metros y 15 cm de diámetro".
- Probar esta función en main utilizando dos objetos de la clase Persona y dos objetos de la clase Poste.
- Incluir todo el código fuente en el archivo main.cpp.

  
### [Ejercicio 09](https://github.com/MValentinaMercado/POO-2024/tree/main/Ejercicio-09)

- Crear una función genérica que imprima por consola sus valores ordenados
- Es decir, se le pasa un array con sus valores en cualquier orden, y la función genérica los imprime ordenados
- Que el prototipo sea: ``template < class T > void imprimir( T * v, int cantidad, bool mayor_a_menor );``
- Utilizar el método de ordenamiento por inserción
- Probar esta función en main utilizando dos arrays (int y float) y ordenar de mayor a menor y el otro al revés

### [Ejercicio 10](https://github.com/MValentinaMercado/POO-2024/tree/main/Ejercicio-10)

- Crear una clase Jugador con atributos ``int velocidad``, ``int fuerza`` y ``std::string nombre``
- Usar constructor inicializando de la manera recomendada la velocidad en 0, fuerza en 0 y nombre "sin nombre" 
- Crear los métodos setter y getter para setear y obtener los valores de los atributos
- Incluir el destructor
- En la función main crear un ``std::vector< Jugador >`` e insertar 10 jugadores distintos
- Por último, publicar los datos de cada uno de los jugadores con ``std::cout``

### [Ejercicio 11](https://github.com/MValentinaMercado/POO-2024/tree/main/Ejercicio-11)

- En la función main crear un objeto de la clase QLabel, uno de QWidget, uno de QPushButton y uno de QLineEdit
- Invocar al método show() de cada uno de estos 4 objetos
- Notar que cada objeto se muestra independiente
  
### [Ejercicio 12](https://github.com/MValentinaMercado/POO-2024/tree/main/Ejercicio-12)

- En la función main crear un objeto de la clase QLabel y pegarle en el mismo objeto QLabel una imagen de alta resolución.
- Que la imagen se obtenga desde un archivo JPG del disco duro
- Mostrar el QLabel de forma maximizada y que la imagen no se deforme.
- Al cabo de 3 segundos, el QLabel y la aplicación se deberá cerrar

  
