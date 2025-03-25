#include <iostream>
using namespace std;

int main() {
    int opcion, numero, a, b, resultado;

    while(true) {
        // Mostrar menú
        cout << "\nMENU DE EJERCICIOS\n";
        cout << "1. Par o impar\n";
        cout << "2. Número menor\n";
        cout << "3. Potencia\n";
        cout << "4. Factorial\n";
        cout << "5. Múltiplos\n";
        cout << "0. Salir\n";
        cout << "Elige una opción: ";
        cin >> opcion;

        // Si la entrada falla (cuando se ingresa texto)
        if(cin.fail()) {
            cin.clear(); // Limpiar el error
            while(cin.get() != '\n'); // Vaciar el buffer
            cout << "¡Debes ingresar un número!\n";
            continue;
        }

        switch(opcion) {
        case 1: // Par o impar
            cout << "Ingresa un número: ";
            cin >> numero;
            cout << "El número es " << (numero % 2 == 0 ? "par" : "impar") << endl;
            break;

        case 2: // Número menor
            cout << "Ingresa dos números (separados por espacio): ";
            cin >> a >> b;
            cout << "El menor es: " << (a < b ? a : b) << endl;
            break;

        case 3: // Potencia
            cout << "Ingresa base y exponente (separados por espacio): ";
            cin >> a >> b;
            resultado = 1;
            for(int i = 0; i < b; i++) resultado *= a;
            cout << a << "^" << b << " = " << resultado << endl;
            break;

        case 4: // Factorial
            cout << "Ingresa un número: ";
            cin >> numero;
            resultado = 1;
            for(int i = 2; i <= numero; i++) resultado *= i;
            cout << numero << "! = " << resultado << endl;
            break;

        case 5: // Múltiplos
            cout << "Ingresa un número: ";
            cin >> numero;
            cout << "Múltiplos: ";
            for(int i = numero; i <= 100; i += numero) cout << i << " ";
            cout << endl;
            break;

        case 0: // Salir
            cout << "¡Hasta luego!\n";
            return 0;

        default:
            cout << "Opción no válida\n";
        }
    }
}
