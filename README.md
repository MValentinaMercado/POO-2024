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
- 
### [Ejercicio 13](https://github.com/MValentinaMercado/POO-2024/tree/main/Ejercicio-13)

- Punto de partida: Usar el código del ejemplo del control de volumen
- Cuando el valor del QSlider se modifique, colocar como título de la ventana el mismo valor que tiene el QSlider.
  
```cpp
#include <QApplication>
#include <QWidget>
#include <QHBoxLayout>
#include <QSlider>
#include <QSpinBox>

int main( int argc, char** argv )  {
    QApplication a( argc, argv );

    QWidget * ventana = new QWidget;  // Es la ventana padre (principal)
    ventana->setWindowTitle( "Volumen" ); 
    ventana->resize( 300, 50 );

    QSpinBox * spinBox = new QSpinBox;
    QSlider * slider = new QSlider( Qt::Horizontal );
    spinBox->setRange( 0, 100 );
    slider->setRange( 0, 100 );

    QObject::connect( spinBox, SIGNAL( valueChanged( int ) ), slider, SLOT( setValue( int ) ) );
    QObject::connect( slider, SIGNAL( valueChanged( int ) ),  spinBox, SLOT( setValue( int ) ) );

    spinBox->setValue( 15 );

    QHBoxLayout * layout = new QHBoxLayout;
    layout->addWidget( spinBox );
    layout->addWidget( slider );
    ventana->setLayout( layout );
    ventana->setVisible( true ); 

    return a.exec();
}

```

### [Ejercicio 14](https://github.com/MValentinaMercado/POO-2024/tree/main/Ejercicio-14)

- Diseñar un login con QGridLayout.
- Usar asteriscos para la clave.
- Detectar enter para simular la pulsación del botón.
- Definir la clase Formulario que será un QWidget
- Formulario tendrá QLabels y QLineEdits para Legajo, Nombre y Apellido, y un QPushButton
- Si la clave ingresada es admin:1111, se cierra Login y se muestra Formulario
- Si se ingresa otra clave se borrará el texto del QLineEdit de la clave.

### [Ejercicio 15](https://github.com/MValentinaMercado/POO-2024/tree/main/Ejercicio-15)
#### [Enunciado](https://github.com/MValentinaMercado/POO-2024/blob/main/imagenes/ejercicio_captcha.jpg)

### [Ejercicio 16](https://github.com/MValentinaMercado/POO-2024/tree/main/Ejercicio-16)

- Registrar en MongoDB algunos usuarios (nombre, apellido, usuario, clave)
- Tener disponible un endpoint con FastAPI para validar usuarios.

### [Ejercicio 14 Continuacion](https://github.com/MValentinaMercado/POO-2024/tree/main/Ejercicio-14%20-%20continuacion)

- Publicar en la ventana de Login, la temperatura actual en la Ciudad de Córdoba. Usar alguna API disponible.
- Agregar un método en Login que permita mostrar u ocultar la información de la temperatura.
- Además que la ventana de Login tenga como background una imagen descargada de interner, centrada y adaptada en tamaño, sin deformar su aspecto y que permita al usuario que modifique el tamaño del Login y que se siga viendo correctamente la imagen.
- Agregar un método en Login que permita indicar la URL de la imagen que se mostrará en el background. En caso que nunca se invoque a este método, ninguna imagen se mostrará.
- Agregar la siguiente característica a Login: Si el usuario falla 3 veces la clave, bloquear por 5 minutos a ese usuario.

### [Ejercicio 16 Continuacion](https://github.com/MValentinaMercado/POO-2024/tree/main/Ejercicio-16%20-%20continuacion)

- Que el endpoint para validar a los usuarios sea con un POST y que devuelva "denegado" o que devuelva el nombre y el apellido del usuario en el siguiente formato: "Juan Carlos::Ponce"
- Probar el funcionamiento de este endpoint mediante la web de prueba de FastAPI.

### [Ejercicio 17](https://github.com/MValentinaMercado/POO-2024/tree/main/Ejercicio-17)

- Diseñar un login que cargue como fondo, una imagen descargada de internet
- Cuando un usuario sea válido, que se abra en full screen otra ventana (definida en la clase Ventana) y que tenga otra imagen descargada de internet en su interior, abarcando toda la ventana.
- Esta ventana no deberá abrirse hasta tanto se haya descargado la imagen.
- La imagen no se debe deformar al visualizarse.

### [Ejercicio 18](https://github.com/MValentinaMercado/POO-2024/tree/main/Ejercicio-18)

- Utilizar un proyecto con un login cualquiera que valide admin:1234
- Cuando el usuario es válido, abrir una nueva ventana que tenga un QTextEdit que permita mostrar código HTML.
- Esta ventana deberá tener un QLineEdit que permita ingresar una URL
- Cuando se pulse Enter, se deberá buscar el html de la URL escrita y se deberá publicar en el QTextEdit.

**Otros Ejercicios**

### [Login-Mapa](https://github.com/MValentinaMercado/POO-2024/tree/main/Login-mapa)
  
### [Ejercicio A](https://github.com/MValentinaMercado/POO-2024/tree/main/Ejercicio-A)
- Comenzar un proyecto vacío con QtCreator y diseñar un login de usuarios como el siguiente:
- Tendrá un tamaño de 250x120 píxeles y llevará por título "Login".
- Para el layout utilizar QGridLayout.
- El único usuario válido es el DNI de estudiante y como clave sus últimos 3 números del DNI.
- Ocultar con asteriscos la clave y detectar el Enter para validar al usuario.
- Si el usuario y clave no es válido, sólo el campo de la clave se deberá limpiar.
- Al fallar la clave 3 veces, la aplicación se cierra.
- Si el usuario es válido, entonces se oculta el login y se visualiza un nuevo QWidget como el que sigue:
- Utilizar una imagen del disco aproximadamente de 100x100 píxeles.
- Esta imagen se mostrará en el QWidget exactamente centrada.
- Dibujar además un cuadrado que envuelva la imagen (como muestra el ejemplo).

### [Ejercicio B](https://github.com/MValentinaMercado/POO-2024/tree/main/Ejercicio-B)
- Crear una aplicación que inicie con un login validando el usuario admin:123
- Luego de ingresar el usuario válido, mostrar un nuevo QWidget con las siguientes características:
- Definida en la clase Editor
- Contendrá un QTextEdit vacío, un QLineEdit, un QPushButton "Buscar" y un QLabel
- El usuario podrá escribir cualquier texto en el QTextEdit.
- EL usuario podrá escribir también en el QLineEdit un caracter, una cadena o una frase.
- Al presionar "Buscar" se detectará automáticamente la cantidad de ocurrencias encontradas de los que se escribió en el QLineEdit.
- El resultado de colocará en el QLabel, indicando, por ejemplo, "14 ocurrencias."
- Luego de dejar funcionando lo anterior, agregar lo siguiente:
- Un QLineEdit y un QPushButton "Guardar"
- En este QLineEdit el usuario puede colocar el nombre de un archivo .txt
- Al presionar Guardar se almacenará todo el texto del QTextEdit en este archivo .txt

### [Ejercicio C](https://github.com/MValentinaMercado/POO-2024/tree/main/Ejercicio-C)

- Crear una clase Barra para dar funcionalidad a una barra de progreso
- Debe tener métodos para setear su valor en porcentaje
- Usar la señal de downloadProgress de QNetworkReply para controlar el porcentaje de descarga
- Crear una interfaz que tenga un QLineEdit para una URL y un objeto Barra.
- Probarlo con alguna URL que pertenezca a un archivo de tamaño superior a 50MB para que se note la demora en la descarga.

### [Ejercicio D](https://github.com/MValentinaMercado/POO-2024/tree/main/Ejercicio-D)

- Diseñar una aplicación para una galería de fotos
- En un archivo .txt almacenar en cada línea, una URL a una imagen
- Un botón >> y otro botón << para avanzar o retroceder en la galería de fotos

### [Ejercicio E](https://github.com/MValentinaMercado/POO-2024/tree/main/Ejercicio-E)

- Definir la clase Ventana que herede de QWidget
- Usar desde el disco una imagen de una bola 8 con formato PNG (para usar transparencias).
- Ventana tendrá un QGroupBox con los siguientes parámetros:
- Diámetro de la bola (en píxeles)
- Velocidad (segundos para ir de lado a lado)
- QPushButton para actualizar estos parámetros en la bola
- La bola irá golpeando de izquierda a derecha en la Ventana.
