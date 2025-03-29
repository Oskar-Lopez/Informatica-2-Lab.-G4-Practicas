#include <iostream>
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

        case 0: // Salir del programa
            cout << "¡Gracias por usar el programa! Hasta pronto.\n";
            return 0;  // Termina la ejecución del programa

        default: // Opción no reconocida
            cout << "Opción no válida. Por favor ingresa un número del menú.\n";
        }
    }

    return 0;
}
