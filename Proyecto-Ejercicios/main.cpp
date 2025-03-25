#include <iostream>
using namespace std;

int main() {
    int opcion, numero, a, b, resultado; // Se declaran variables para menú y cálculos

    while(true) { // Bucle infinito hasta que se elija salir
        // Mostrar menú
        cout << "\nMENU DE EJERCICIOS\n";
        cout << "1. Par o impar\n";
        cout << "2. Número menor\n";
        cout << "3. Potencia\n";
        cout << "4. Factorial\n";
        cout << "5. Múltiplos\n";
        cout << "6. Potencias desde n¹ hasta n⁵\n";
        cout << "7. Columnas paralelas\n";
        cout << "0. Salir\n";
        cout << "Elige una opción: ";
        cin >> opcion;

        // Validación de entrada (si no es número)
        if(cin.fail()) {
            cin.clear(); // Restablece el estado de error de cin
            while(cin.get() != '\n'); // Limpia el buffer de entrada
            cout << "¡Debes ingresar un número!\n";
            continue; // Vuelve al inicio del bucle
        }

        switch(opcion) { // Ejecuta la opción seleccionada
        case 1: // Par o impar
            cout << "Ingresa un número: ";
            cin >> numero;
            // Operador ternario para determinar par/impar
            cout << "El número es " << (numero % 2 == 0 ? "par" : "impar") << endl;
            break;

        case 2: // Número menor
            cout << "Ingresa dos números (separados por espacio): ";
            cin >> a >> b;
            // Comparación directa con operador ternario
            cout << "El menor es: " << (a < b ? a : b) << endl;
            break;

        case 3: // Potencia
            cout << "Ingresa base y exponente (separados por espacio): ";
            cin >> a >> b;
            resultado = 1;  // Inicializa resultado
            // Bucle para multiplicar la base 'b' veces
            for(int i = 0; i < b; i++) resultado *= a;
            cout << a << "^" << b << " = " << resultado << endl;
            break;

        case 4: // Factorial
            cout << "Ingresa un número: ";
            cin >> numero;
            resultado = 1; // Inicializa factorial
            // Bucle para multiplicar números desde 2 hasta 'numero'
            for(int i = 2; i <= numero; i++) resultado *= i;
            cout << numero << "! = " << resultado << endl;
            break;

        case 5: // Múltiplos
            cout << "Ingresa un número: ";
            cin >> numero;
            cout << "Múltiplos: ";
            // Bucle para imprimir múltiplos hasta 100
            for(int i = numero; i <= 100; i += numero) cout << i << " ";
            cout << endl;
            break;

        case 6: // Potencias desde n¹ hasta n⁵
        {
            cout << "Ingrese un número N: ";
            cin >> numero;

            cout << "Las potencias de " << numero << " son:" << endl;

            // Calculo e impresión de las potencias
            int potencia = 1;
            for(int i = 1; i <= 5; i++) {
                potencia *= numero;  // Multiplicación acumulativa
                cout << numero << "^" << i << " = " << potencia << endl;
            }
            break;
        }

        case 7: // Columnas paralelas
        {
            cout << "Columnas paralelas (1-50 y 50-1):" << endl;
            // Se imprimen las dos columnas paralelas
            for(int i = 1; i <= 50; i++) {
                cout << i << "\t" << 51 - i << endl; // Se inserta tabulador para separar columnas
            }
            break;
        }

        case 0: // Salir
            cout << "¡Hasta luego!\n";
            return 0; // Termina el programa

        default: // Opción no valida
            cout << "Opción no válida\n";
        }
    }
}
