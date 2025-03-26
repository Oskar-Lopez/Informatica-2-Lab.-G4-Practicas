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
        cout << "1. Determinar si un número es par o impar\n";
        cout << "2. Encontrar el menor de dos números\n";
        cout << "3. Calcular la potencia de un número\n";
        cout << "4. Calcular el factorial de un número\n";
        cout << "5. Mostrar múltiplos de un número hasta 100\n";
        cout << "6. Mostrar potencias de un número desde n¹ hasta n⁵\n";
        cout << "7. Mostrar columnas paralelas de números\n";
        cout << "8. Calcular el promedio de números ingresados\n";
        cout << "9. Determinar si es cuadrado perfecto\n";
        cout << "0. Salir del programa\n";
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

        case 0: // Salir del programa
            cout << "¡Gracias por usar el programa! Hasta pronto.\n";
            return 0;  // Termina la ejecución del programa

        default: // Opción no reconocida
            cout << "Opción no válida. Por favor ingresa un número del menú.\n";
        }
    }

    return 0;
}
