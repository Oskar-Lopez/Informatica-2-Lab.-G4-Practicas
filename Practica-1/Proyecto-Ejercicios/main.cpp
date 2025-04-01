#include <iostream>
#include <ctime>    // Proporciona funciones para trabajar con tiempo (como time() para obtener el tiempo actual)
#include <cstdlib>  // Contiene funciones generales como srand() para semillas aleatorias y rand() para generar números aleatorios
using namespace std;

int main() {
    // Variables principales del programa
    int opcion;                // Almacena la opción seleccionada del menú
    int numero, a, b;          // Variables para operaciones básicas
    int resultado;             // Almacena resultados de operaciones matemáticas
    int num, suma, contador;   // Variables específicas para el cálculo de promedio
    double promedio;           // Almacena el resultado del cálculo del promedio

    // Bucle principal que mantiene el programa en ejecución
    while(true) {
        // Mostrar menú de opciones al usuario
        cout << "\nMENU DE EJERCICIOS\n";
        cout << "1.  Determinar si un número es par o impar\n";
        cout << "2.  Encontrar el menor de dos números\n";
        cout << "3.  Calcular la potencia de un número\n";
        cout << "4.  Calcular el factorial de un número\n";
        cout << "5.  Mostrar múltiplos de un número hasta 100\n";
        cout << "6.  Mostrar potencias de un número desde n¹ hasta n⁵\n";
        cout << "7.  Mostrar columnas paralelas de números\n";
        cout << "8.  Calcular el promedio de números ingresados\n";
        cout << "9.  Determinar si es cuadrado perfecto\n";
        cout << "10. Verificación de números palindromos\n";
        cout << "11. Convertir segundos a horas:minutos:segundos\n";
        cout << "12. Dibujar un cuadrado con caracteres\n";
        cout << "13. Determinar tipo de triángulo\n";
        cout << "14. Calcular aproximación a Pi\n";
        cout << "15. Juego de adivinar el número\n";
        cout << "0.  Salir del programa\n";
        cout << "Elige una opción: ";
        cin >> opcion;

        // Validación de la entrada del usuario
        if(cin.fail()) {
            cin.clear();        // Limpia el estado de error del flujo de entrada
            while(cin.get() != '\n');  // Descarta la entrada incorrecta del buffer
            cout << "¡Debes ingresar un número válido!\n";
            continue;          // Vuelve al inicio del bucle
        }

        // Estructura de control para las diferentes opciones
        switch(opcion) {
        case 1: // Determinar si un número es par o impar
            cout << "Ingresa un número: ";
            cin >> numero;
            // Operador ternario que evalúa si el número es divisible entre 2
            cout << "El número es " << (numero % 2 == 0 ? "par" : "impar") << endl;
            break;

        case 2: // Encontrar el menor de dos números
            cout << "Ingresa dos números separados por espacio: ";
            cin >> a >> b;
            // Comparación directa entre los dos números
            cout << "El menor es: " << (a < b ? a : b) << endl;
            break;

        case 3: // Calcular la potencia de un número
            cout << "Ingresa la base y el exponente separados por espacio: ";
            cin >> a >> b;
            resultado = 1;  // Inicialización del resultado
            // Bucle que multiplica la base por sí misma 'exponente' veces
            for(int i = 0; i < b; i++) {
                resultado *= a;
            }
            cout << a << " elevado a la " << b << " = " << resultado << endl;
            break;

        case 4: // Calcular el factorial de un número
            cout << "Ingresa un número entero positivo: ";
            cin >> numero;
            resultado = 1;  // El factorial de 0 y 1 es 1
            // Bucle que multiplica todos los números desde 2 hasta el número ingresado
            for(int i = 2; i <= numero; i++) {
                resultado *= i;
            }
            cout << "El factorial de " << numero << " es: " << resultado << endl;
            break;

        case 5: // Mostrar múltiplos de un número hasta 100
            cout << "Ingresa un número para mostrar sus múltiplos: ";
            cin >> numero;
            cout << "Múltiplos de " << numero << " hasta 100: ";
            // Bucle que incrementa de 'numero' en 'numero' hasta llegar a 100
            for(int i = numero; i <= 100; i += numero) {
                cout << i << " ";
            }
            cout << endl;
            break;

        case 6: // Mostrar potencias de un número desde n¹ hasta n⁵
        {
            cout << "Ingresa un número para calcular sus potencias: ";
            cin >> numero;
            cout << "Potencias de " << numero << " desde 1 hasta 5:\n";
            int potencia = 1;  // Inicialización de la potencia
            // Bucle que calcula y muestra cada potencia
            for(int i = 1; i <= 5; i++) {
                potencia *= numero;  // Multiplicación acumulativa
                cout << numero << "^" << i << " = " << potencia << endl;
            }
            break;
        }

        case 7: // Mostrar columnas paralelas de números
        {
            cout << "Columnas paralelas de números (1-50 y 50-1):\n";
            // Bucle que muestra números ascendentes y descendentes en columnas
            for(int i = 1; i <= 50; i++) {
                cout << i << "\t" << 51 - i << endl;  // \t para alinear columnas
            }
            break;
        }

        case 8: // Calcular el promedio de números ingresados
        {
            suma = 0;       // Inicializa el acumulador de la suma
            contador = 0;   // Inicializa el contador de números ingresados
            cout << "Ingresa números para calcular el promedio (0 para terminar):\n";

            // Bucle que recibe números hasta que se ingrese 0
            do {
                cout << "Número: ";
                cin >> num;
                if(num != 0) {  // Solo suma si no es el 0 de terminación
                    suma += num;
                    contador++;
                }
            } while(num != 0);

            // Cálculo y muestra del promedio
            if(contador > 0) {
                promedio = (double)suma / contador;  // Conversión para división precisa
                cout << "El promedio de los " << contador << " números ingresados es: " << promedio << endl;
            } else {
                cout << "No se ingresaron números para calcular el promedio.\n";
            }
            break;
        }

        case 9: // Determinar si es cuadrado perfecto
        {
            // Solicitar al usuario que ingrese un número
            cout << "Ingrese un número: ";
            cin >> numero;

            // Variable booleana para almacenar el resultado de la verificación
            bool esPerfecto = false; // Inicialmente asumo que no es cuadrado perfecto

            // Bucle for para verificar todos los posibles enteros desde 0 hasta el número ingresado
            for(int i = 0; i <= numero; i++) {
                // Compruebo si el cuadrado del número actual (i) es igual al número ingresado
                if(i * i == numero) {
                    esPerfecto = true; // Si coincide, es cuadrado perfecto
                    break; // Salir del bucle ya que encontramos la respuesta
                }

                // Optimización: si el cuadrado supera al número, no tiene sentido seguir buscando
                if(i * i > numero) break; // Terminar el bucle anticipadamente
            }

            // Mostrar el resultado al usuario basado en la variable esPerfecto
            if(esPerfecto) {
                // Mensaje cuando es cuadrado perfecto
                cout << "El número " << numero << " es un cuadrado perfecto." << endl;
            } else {
                // Mensaje cuando no es cuadrado perfecto
                cout << "El número " << numero << " no es un cuadrado perfecto." << endl;
            }

            // Salir del switch-case
            break;
        }

        case 10: // Verificación de números palíndromos
        {
            // Solicitar al usuario que ingrese un número para verificar
            cout << "Ingrese un número: ";
            // Leer el número ingresado y almacenarlo en la variable 'numero'
            cin >> numero;

            // Inicializar variable para almacenar el número invertido
            int reverso = 0;
            // Guardar una copia del número original para comparación posterior
            int original = numero;

            // Bucle para invertir el número digitos
            while (numero != 0) {
                // Obtener el último dígito del número usando módulo 10
                int digito = numero % 10;
                // Construir el número invertido:
                // - Multiplicar el reverso actual por 10 para "mover" los dígitos
                // - Sumar el nuevo dígito obtenido
                reverso = reverso * 10 + digito;
                // Eliminar el último dígito del número original dividiendo entre 10
                numero /= 10;
            }

            // Comparar el número original con su versión invertida
            if (original == reverso) {
                // Si son iguales, es un palíndromo
                cout << "El número " << original << " es un palíndromo." << endl;
            } else {
                // Si son diferentes, no es un palíndromo
                cout << "El número " << original << " no es un palíndromo." << endl;
            }
            // Salir del switch-case para volver al menú principal
            break;
        }

        case 11: // Conversión de segundos a formato horas:minutos:segundos
        {
            int segundos;
            // Solicitar al usuario que ingrese una cantidad de segundos
            cout << "Ingrese una cantidad entera de segundos: ";
            cin >> segundos;

            // Calculo de las horas completas (1 hora = 3600 segundos)
            int horas = segundos / 3600;
            // Calculo de los minutos restantes después de extraer las horas
            int minutos = (segundos % 3600) / 60;
            // Calculo de los segundos restantes después de extraer horas y minutos
            int segundosRestantes = segundos % 60;

            // Mostrar el resultado formateado como HH:MM:SS
            cout << "El tiempo es: " << horas << ":" << minutos << ":" << segundosRestantes << endl;
            break;
        }

        case 12: // Dibujar un cuadrado con caracteres
        {
            // Declaración de variable para almacenar el tamaño del cuadrado
            int tamaño;

            // Solicito al usuario que ingrese el tamaño del cuadrado
            cout << "Ingrese el tamaño del cuadrado (mínimo 2): ";
            cin >> tamaño;  // Leer y almacenar el valor ingresado

            // Valido el tamaño mínimo requerido en la línea anterior
            if(tamaño < 2) {
                cout << "El tamaño debe ser al menos 2.\n";
                break;  // Salir del case si el tamaño es inválido
            }

            // --------------------------
            // Dibujo del borde superior
            // --------------------------
            // Bucle para imprimir una línea completa de caracteres '+'
            for(int i = 0; i < tamaño; i++) {
                cout << "+";  // Imprimir carácter de borde
            }
            cout << endl;  // Salto de línea al terminar el borde superior

            // --------------------------
            // Dibujo de las filas intermedias
            // --------------------------
            // Bucle para cada fila intermedia (total de filas - 2, no incluye bordes)
            for(int i = 0; i < tamaño - 2; i++) {
                cout << "+";  // Imprimir borde izquierdo

                // Bucle para los espacios internos del cuadrado
                for(int j = 0; j < tamaño - 2; j++) {
                    cout << " ";  // Espacio vacío en el interior
                }

                cout << "+" << endl;  // Imprimir borde derecho y saltar línea
            }

            // --------------------------
            // Dibujo del borde inferior
            // --------------------------
            // Verificación adicional para tamaños mayores a 1
            if(tamaño > 1) {
                // Bucle idéntico al borde superior
                for(int i = 0; i < tamaño; i++) {
                    cout << "+";  // Imprimir carácter de borde
                }
                cout << endl;  // Salto de línea final
            }

            break;
        }

        case 13: // Determinar tipo de triángulo
        {
            int lado1, lado2, lado3;  // Variables para almacenar los lados del triángulo

            // Solicito al usuario los tres lados del triángulo
            cout << "Ingrese el lado 1: ";
            cin >> lado1;
            cout << "Ingrese el lado 2: ";
            cin >> lado2;
            cout << "Ingrese el lado 3: ";
            cin >> lado3;

            // Primera validación: Desigualdad triangular (la suma de dos lados debe ser mayor que el tercero)
            if (lado1 + lado2 <= lado3 || lado1 + lado3 <= lado2 || lado2 + lado3 <= lado1) {
                cout << "No se puede formar un triángulo con estos lados." << endl;
                break;  // Salir del case si no cumple la condición básica de triángulo
            }

            // Determinar el tipo de triángulo según la igualdad de sus lados
            if (lado1 == lado2 && lado2 == lado3) {
                // Todos los lados iguales
                cout << "El triángulo es equilátero." << endl;
            }
            else if (lado1 == lado2 || lado2 == lado3 || lado1 == lado3) {
                // Dos lados iguales
                cout << "El triángulo es isósceles." << endl;
            }
            else {
                // Todos los lados diferentes
                cout << "El triángulo es escaleno." << endl;
            }
            break;
        }

        case 14: // Opción para calcular el valor de Pi
        {
            int n; // Aquí guardaremos cuántos números usaremos para el cálculo
            double pi = 0.0; // Empezamos con Pi en cero

            // Pedimos al usuario cuántos números quiere usar
            cout << "Ingrese número de elementos para aproximar Pi: ";
            cin >> n;

            // Reviso que el número sea positivo
            if(n <= 0) {
                cout << "Debe ingresar un número positivo.\n";
                break; // Si no es positivo, salimos
            }

            // Calculo Pi sumando y restando fracciones
            for(int i = 0; i < n; i++) {
                // Calculamos cada parte de la suma
                double termino = 1.0 / (2 * i + 1);

                // Alternamos entre sumar y restar
                if(i % 2 == 1) termino = -termino;

                // Vamos acumulando los valores
                pi += termino;
            }

            // Al final multiplico por 4 para obtener Pi
            pi *= 4;

            // Se muestra el resultado aproximado
            cout << "Pi ≈ " << pi << "\n";

            break;
        }

        case 15: // Juego de adivinar el número
        {
            // Esto hace que el número cambie cada vez que se ejecuta el programa
            srand(time(0)); // Se inicializa el generador de números aleatorios usando la hora actual
                            // como semilla para que sean diferentes en cada ejecución

            // Generamos un número secreto entre 0 y 100
            // rand() genera un número grande, y %101 lo convierte en 0-100
            int numeroSecreto = rand() % 101;

            // Variables para guardar el intento del usuario y contar sus intentos
            int intentoUsuario;
            int contadorIntentos = 0;

            // Muestro las instrucciones iniciales al jugador
            cout << "He pensado un número entre 0 y 100. ¡Adivínalo!\n";

            // Inicio el bucle principal del juego
            do {
                // Pido al usuario que ingrese un número
                cout << "Ingresa tu número: ";
                cin >> intentoUsuario;

                // Aumento el contador de intentos cada vez que prueba
                contadorIntentos++;

                // Comparo el número del usuario con el secreto
                if (intentoUsuario > numeroSecreto) {
                    // Si el número es mayor, damos una pista
                    cout << "El número es menor.\n";
                } else if (intentoUsuario < numeroSecreto) {
                    // Si el número es menor, damos una pista
                    cout << "El número es mayor.\n";
                } else {
                    // Si acierta, muestro mensaje de felicitación
                    cout << "¡Correcto! Adivinaste el número " << numeroSecreto
                         << " en " << contadorIntentos << " intentos.\n";
                }
            } while (intentoUsuario != numeroSecreto);  // Se repite hasta que acierte

            break;
        }

        case 0: // Salir del programa
            cout << "¡Gracias por usar el programa! Hasta pronto.\n";
            return 0;  // Termina la ejecución del programa

        default: // Opción no reconocida
            cout << "Opción no válida. Por favor ingresa un número del menú.\n";
        }
    }

    return 0;
}
