# Ejercicios de POO-2024

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

## [Parte 2](https://github.com/MValentinaMercado/POO-2024/tree/main/Ejercicio-14-Parte-2)

- Publicar en la ventana de Login, la temperatura actual en la Ciudad de Córdoba. Usar alguna API disponible.
- Agregar un método en Login que permita mostrar u ocultar la información de la temperatura.
- Además que la ventana de Login tenga como background una imagen descargada de interner, centrada y adaptada en tamaño, sin deformar su aspecto y que permita al usuario que modifique el tamaño del Login y que se siga viendo correctamente la imagen.
- Agregar un método en Login que permita indicar la URL de la imagen que se mostrará en el background. En caso que nunca se invoque a este método, ninguna imagen se mostrará.

## [Parte 3](https://github.com/MValentinaMercado/POO-2024/tree/main/Ejercicio-14-Parte-3)

- Agregar la siguiente característica a Login: Si el usuario falla 3 veces la clave, bloquear por 5 minutos a ese usuario.
  
## [Parte 4](https://github.com/MValentinaMercado/POO-2024/tree/main/Ejercicio-14-Parte-4)

- Incorporar la validación de usuarios con QSLite.
- Todo lo que se haga con la base de datos, que se encuentre en la clase AdminDB

## [Parte 5](https://github.com/MValentinaMercado/POO-2024/tree/main/Ejercicio-14-Parte-5)

- Implementar en AdminDB el uso de MD5 para las claves de los usuarios.
- Acondicionar para que el método utilizado sea el siguiente:
```cpp
 /**
 * Si el usuario y clave son crrectas, este metodo devuelve el nombre y 
 * apellido en un QStringList.             
 */
QStringList AdminDB::validarUsuario( QString tabla, QString usuario, QString clave )  {

    QStringList datosPersonales;

    if ( ! db.isOpen() ) 
        return datosPersonales;

    QSqlQuery * query = new QSqlQuery( db );
    QString claveMd5 = QCryptographicHash::hash( clave.toUtf8(), 
                                                 QCryptographicHash::Md5 ).toHex();

    query->exec( "SELECT nombre, apellido FROM " +
                 tabla + " WHERE usuario = '" + usuario +
                 "' AND clave = '" + claveMd5 + "'" );

    while( query->next() )  {
        QSqlRecord registro = query->record();

        datosPersonales << query->value( registro.indexOf( "nombre" ) ).toString();
        datosPersonales << query->value( registro.indexOf( "apellido" ) ).toString();
    }

    return datosPersonales;
} 
```
- Además, definir un método en AdminDB para ejecutar un select a la base. El prototipo es el siguiente:
```cpp
/**
 * @brief Método que ejecuta una consulta SQL a la base de datos que ya se encuentra conectado. 
          Utiliza QSqlQuery para ejecutar la consulta, con el método next() se van extrayendo 
          los registros que pueden ser analizados con QSqlRecord para conocer la cantidad de 
          campos por registro.
 * @param comando es una consulta como la siguiente: SELECT nombre, apellido, id FROM usuarios
 * @return Devuelve un QVector donde cada elemento es un registro, donde cada uno de estos registros 
           están almacenados en un QStringList que contiene cada campo de cada registro.               
 */
QVector< QStringList > select( QString comando ); 
```
- Definir en Login una signal que se emita cada vez que un usuario se loguee exitosamente. La signal debe emitir el nombre de usuario.
```cpp
void signal_usuarioValidado( QString usuario ); 
```

### [Ejercicio 15](https://github.com/MValentinaMercado/POO-2024/tree/main/Ejercicio-15)
#### [Enunciado](https://github.com/MValentinaMercado/POO-2024/blob/main/imagenes/ejercicio_captcha.jpg)

### [Ejercicio 16](https://github.com/MValentinaMercado/POO-2024/tree/main/Ejercicio-16)

- Registrar en MongoDB algunos usuarios (nombre, apellido, usuario, clave)
- Tener disponible un endpoint con FastAPI para validar usuarios.

## [Parte 2](https://github.com/MValentinaMercado/POO-2024/tree/main/Ejercicio-16%20-%20continuacion)

- Que el endpoint para validar a los usuarios sea con un POST y que devuelva "denegado" o que devuelva el nombre y el apellido del usuario en el siguiente formato: "Juan Carlos::Ponce"
- Probar el funcionamiento de este endpoint mediante la web de prueba de FastAPI.

## [Parte 3](https://github.com/MValentinaMercado/POO-2024/tree/main/Ejercicio-16-continuacion-parte3)

- Luego de tener registrados los usuarios en MongoDB y funcionando el endpoint.
- Acondicionar la clase Login para validar los usuarios contra el endpoint de FastAPI.

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

### [Ejercicio 19](https://github.com/MValentinaMercado/POO-2024/tree/main/Ejercicio-19)

- Crear una clase Pintura que herede de QWidget y que permita dibujar a mano alzada con el mouse.
- Con el scroll permitirá ampliar y disminuir el tamaño del trazo del pincel.
- Con las teclas R, G y B se cambia el color del pincel.
- Con Escape se borra todo lo que esté dibujado.

### [Ejercicio 20](https://github.com/MValentinaMercado/POO-2024/tree/main/Ejercicio-20)

- Crear un proyecto Qt Widget Application con un QWidget que sea la clase Ventana
- Crear una clase Boton que hereda de QWidget
- Redefinir paintEvent en Boton y usar fillRect para dibujarlo de algún color
- Definir el siguiente método en Boton:
 ```cpp
 Boton * boton = new Boton;
boton->colorear( Boton::Azul );

// Este método recibe como parámetro una enumeración que puede ser:
// Boton::Azul  Boton::Verde  Boton::Magenta
```
- Usar QtDesigner para Ventana y Boton. Es decir, Designer Form Class
- Definir la enumeración en Boton
- Abrir el designer de Ventana y agregar 5 botones (objetos de la clase Boton). Promocionarlos
- Que esta Ventana con botones quede lo más parecido a la siguiente imagen:
  [Imagen](https://github.com/MValentinaMercado/POO-2024/blob/main/imagenes/botones.png)
- Usar para Ventana grid layout, usar espaciadores y usar todos los recursos posibles del QtDesigner
- Dibujar un fondo agradable con paintEvent y drawImage
- Que Boton tenga la señal signal_clic()

### [Ejercicio 21](https://github.com/MValentinaMercado/POO-2024/tree/main/Ejercicio-21)

- Definir dos QWidgets (una clase Login y una clase Ventana).
- El Login validará al usuario contra una base SQLite.
- La Ventana sólo mostrará un QPushButton para "Volver" al login.
- Crear solamente un objeto de Ventana y uno solo de Login.
- Si sucede un problema en la compilación, analizar los motivos (respetar el enunciado).
- Solucionar ese problema y ver la alternativa de hacerlo con Manager.

### [Ejercicio 22](https://github.com/MValentinaMercado/POO-2024/tree/main/Ejercicio-22)

- Crear una clase base llamada Instrumento y las clases derivadas Guitarra, Bateria y Teclado.
- La clase base tiene una función virtual pura llamada sonar().
- Defina una función virtual verlo() que publique la marca del instrumento. Por defecto todos los instrumentos son de la marca Yamaha.
- Utilice en la función main() un std::vector para almacenar punteros a objetos del tipo Instrumento. Instancie 5 objetos y agréguelos al std::vector.
- Publique la marca de cada instrumento recorriendo el vector.
- En las clases derivadas agregue los datos miembro "int cuerdas", "int teclas" e "int tambores" según corresponda. Por defecto, guitarra con 6 cuerdas, teclado con 61 teclas y batería con 5 tambores.
- Haga que la clase Teclado tenga herencia múltiple, heredando además de una nueva clase Electrico. Todos los equipos del tipo "Electrico" tienen por defecto un voltaje de 220 volts. Esta clase deberá tener un destructor que al destruirse publique la leyenda "Desenchufado".
- Al llamar a la función sonar(), se deberá publicar "Guitarra suena...", "Teclado suena..." o "Batería suena..." según corresponda.
- Incluya los métodos get y set que crea convenientes.

### [Ejercicio 23](https://github.com/MValentinaMercado/POO-2024/tree/main/Ejercicio-23)

- Reutilizar el código fuente de cualquier otro ejericio y utilizar herencia múltiple, inline y friend.
- Implementar herencia múltiple, inline y friend cuando sea beneficioso hacerlo.

### [Ejercicio 24](https://github.com/MValentinaMercado/POO-2024/tree/main/Ejercicio-24)

- Crear un parser que pueda analizar cualquier html en busca de todas las URLs que encuentre
- Crear una GUI que permita al usuario ingresar un sitio web en un QLineEdit
- Que descargue en archivos todos los recursos de dicho sitio web
- Es decir, que busque en el html las imágenes, los css, los javascript y los descargue en archivos
- Que le permita al usuario indicar en qué directorio descargar los archivos
- También agregar un botón que upermita elegir un archivo de imagen del disco con QFileDialog y que la dibuje en pantalla con paintEvent.

### [Ejercicio 25](https://github.com/MValentinaMercado/POO-2024/tree/main/Ejercicio-25)

- Construir un nuevo proyecto que tenga un Login independiente, es decir, que no dependa de otra clase GUI.
- El Login tenga un QLabel que funciona como botón que sea para registrar un nuevo usuario.
- Cuando se presiona el QLabel que funciona como botón, se abrirá una ventana para dar de alta un usuario.
- Usar SQLite con AdminDB como singleton.
- Cuando un usuario válido ingresa correctamente se mostrará otra ventana que visualizará todos los usuarios cargados en la base.
- Para la visualización de los usuarios se puede usar QTreeWidget. Agregar la funcionalidad para que en esta misma ventana se puedan editar los campos como si 
  fuera una planilla tipo excel.
- Seguir las recomendaciones que se comentaron durante el dictado de clases para construir las clases.

# Ejercicios Extra

### [Login-Mapa](https://github.com/MValentinaMercado/POO-2024/tree/main/Login-mapa)

# Modelo de Parcial 1
  
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

# Modelo de Pacial 2

### [Ejercicio A](https://github.com/MValentinaMercado/POO-2024/tree/main/Ejercicio-A-Parcial-2)

- Definir una ventana vacía en la clase Principal, que herede de QWidget y diseñado con QtDesigner.
- Agregar a este proyecto la clase AdminDB para permitir el uso de una base de datos.
- Instanciar un único objeto de AdminDB en la aplicación.
  - **Definir una clase Linea con las siguientes características:**
     - En los archivos fuente linea.h y linea.cpp
     - Atributos privados: int x_inicial, y_inicial, x_final, y_final
     - Con sus getters y setters.
     - Utilizar en esta clase todos los const que son recomendables
- Definir una tabla "lineas" en la base de datos con los siguientes campos: id, x_inicial, y_inicial, x_final, y_final
- Cargar en la base de datos un único registro, es decir, los datos de una única línea.
- Desde la clase Principal se podrá leer este único registro y crear un objeto Linea con esos datos.
- Dibujar con paintEvent esta línea dentro de la ventana con las coordenadas leídas de la base.

### [Ejercicio B](https://github.com/MValentinaMercado/POO-2024/tree/main/Ejercicio-B-Parcial-2)

- Definir un formulario en la clase Formulario usando QtDesigner.
- En Formulario se darán de alta instrumentos en un negocio de instrumentos musicales.
- Los instrumentos que se pueden cargar serán: guitarras, vientos y teclados.
- Definir las clases Instrumento, Guitarra, Viento y Teclado.
- Cada clase en sus correspondientes archivos .h y .cpp
- Instrumento será una clase abstracta con la función virtual pura void afinar()
- Que esa función virtual pura simplemente publique un texto por consola, por ejemplo "Afinando guitarra".
- El formulario tendrá un botón que agregará un instrumento nuevo a un QVector< Instrumento * >
- El formulario tendrá un QComboBox en el cual tendrá el siguiente listado: Guitarra, Viento y Teclado.
- El formulario también tendrá un botón "Ver stock" que publicará por consola todos los instrumentos cargados.
- Los Instrumentos tendrán los siguientes atributos: marca, precio, cantidad_de_cuerdas, cantidad_de_teclas, metal_usado.
- Cuando en el QComboBox se seleccione Guitarra, se deberá permitir ingresar sólo la marca, el precio y la cantidad de cuerdas.

### [Ejercicio C](https://github.com/MValentinaMercado/POO-2024/tree/main/Ejercicio-C-Parcial-2)

- Usar la clase Manager para gestionar todas las ventanas de una nueva aplicación.
- Usar un login (clase Login) que valide usuarios contra la tabla usuarios usando AdminDB.
- Para el campo clave usar MD5.
- La base de datos debe estar en el archivo base.sqlite
- Login y AdminDB que sean singleton.
- Cada clase en sus correspondientes archivos .h y .cpp
- Cuando un usuario ingrese correctamente, mostrar una ventana vacía.

### [Ejercicio D](https://github.com/MValentinaMercado/POO-2024/tree/main/Ejercicio-D-Parcial-2)

- Crear una clase Lienzo que herede de QWidget, creado con QtDesigner y que permita dibujar con paintEvent.
- Cuando se presiona la tecla A (Activar) se comenzará a dibujar cada posición en donde se encuentra el mouse. No depende de que se presione algún bóton del mouse para comenzar a dibujar.
- Cuando se presiona la tecla D (Desactivar) se dejará de dibujar.
- La clase Lienzo recibe una enumeración que puede ser: TrazoFino, TrazoMediano, TrazoGrueso que determinará el grosor de lo que se dibuja.
- Dentro de Lienzo y ubicado abajo a la derecha, se ubicará un objeto de MiLabel, que hereda de QLabel, con una señal propia para detectar el click del mouse.
- Cuando se presione este MiLabel, se borrará todo lo dibujado.
