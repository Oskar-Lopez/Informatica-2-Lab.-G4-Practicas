#include <iostream>
#include <string>

using namespace std;

// Prototipos de funciones
void limpiarBuffer();
int leerEntero(const string& mensaje);
void calcularSumatoriaMultiplos();
void desgloseMonedas();
void sumarTiempos();
void aproximarConstanteE();
void mostrarMenuPrincipal();

/**
 * @brief Limpia el buffer de entrada
 */
void limpiarBuffer() {
    cin.clear();
    cin.ignore(1000, '\n');
}

/**
 * @brief Lee y valida un número entero
 */
int leerEntero(const string& mensaje) {
    int valor;
    while (true) {
        cout << mensaje;
        if (cin >> valor) {
            limpiarBuffer();
            return valor;
        }
        cout << "Error: Entrada inválida. ";
        limpiarBuffer();
    }
}

/**
 * @brief Calcula sumatoria de múltiplos de a y b menores que c
 */
void calcularSumatoriaMultiplos() {
    cout << "\n=== SUMATORIA DE MÚLTIPLOS ===" << endl;

    int a = leerEntero("Ingrese el valor de a: ");
    int b = leerEntero("Ingrese el valor de b: ");
    int c = leerEntero("Ingrese el valor de c: ");

    int sumatoria = 0;
    int multiploA = a;
    int multiploB = b;
    string salida = "";

    // Sumar múltiplos de a menores que c
    while (multiploA < c) {
        if (!salida.empty()) {
            salida += " + ";
        }
        salida += to_string(multiploA);
        sumatoria += multiploA;
        multiploA += a;
    }

    // Sumar múltiplos de b menores que c (que no sean múltiplos de a)
    while (multiploB < c) {
        if (multiploB % a != 0) {
            if (!salida.empty()) {
                salida += " + ";
            }
            salida += to_string(multiploB);
            sumatoria += multiploB;
        }
        multiploB += b;
    }

    cout << salida << " = " << sumatoria << endl;
}

/**
 * @brief Desglosa una cantidad en billetes y monedas
 */
void desgloseMonedas() {
    const int denominacionesBilletes[] = {50000, 20000, 10000, 5000, 2000, 1000};
    const int denominacionesMonedas[] = {500, 200, 100, 50};
    int cantidadBilletes[6] = {0};
    int cantidadMonedas[4] = {0};

    cout << "\n=== DESGLOSE DE DINERO ===" << endl;
    int cantidad = leerEntero("Ingrese la cantidad: ");
    int resto = cantidad;

    for (int i = 0; i < 6; i++) {
        cantidadBilletes[i] = resto / denominacionesBilletes[i];
        resto %= denominacionesBilletes[i];
    }

    for (int i = 0; i < 4; i++) {
        cantidadMonedas[i] = resto / denominacionesMonedas[i];
        resto %= denominacionesMonedas[i];
    }

    cout << "\nResultado:\n";
    for (int i = 0; i < 6; i++) {
        if (cantidadBilletes[i] > 0) {
            cout << "Billetes de $" << denominacionesBilletes[i] << ": " << cantidadBilletes[i] << endl;
        }
    }
    for (int i = 0; i < 4; i++) {
        if (cantidadMonedas[i] > 0) {
            cout << "Monedas de $" << denominacionesMonedas[i] << ": " << cantidadMonedas[i] << endl;
        }
    }

    if (resto > 0) {
        cout << "Restante: $" << resto << endl;
    }
}

/**
 * @brief Suma dos tiempos en formato HHMM
 */
void sumarTiempos() {
    cout << "\n=== SUMA DE TIEMPOS ===" << endl;
    int hora, duracion;

    do {
        hora = leerEntero("Ingrese hora inicial (HHMM): ");
        if (hora < 0 || hora % 100 >= 60 || hora / 100 >= 24) {
            cout << "Formato inválido. Use HHMM (00-23 horas, 00-59 minutos)\n";
        }
    } while (hora < 0 || hora % 100 >= 60 || hora / 100 >= 24);

    do {
        duracion = leerEntero("Ingrese duración (HHMM): ");
        if (duracion < 0 || duracion % 100 >= 60 || duracion / 100 >= 24) {
            cout << "Formato inválido. Use HHMM (00-23 horas, 00-59 minutos)\n";
        }
    } while (duracion < 0 || duracion % 100 >= 60 || duracion / 100 >= 24);

    int totalMinutos = (hora % 100) + (duracion % 100);
    int totalHoras = (hora / 100) + (duracion / 100) + (totalMinutos / 60);
    totalMinutos %= 60;
    totalHoras %= 24;

    cout << "\nHora resultante: "
         << (totalHoras < 10 ? "0" : "") << totalHoras
         << (totalMinutos < 10 ? "0" : "") << totalMinutos << endl;
}

/**
 * @brief Aproxima la constante e usando serie infinita
 */
void aproximarConstanteE() {
    cout << "\n=== APROXIMACIÓN DE EULER ===" << endl;
    int terminos = leerEntero("Ingrese número de términos: ");

    double e = 0.0;
    long double factorial = 1.0;

    for (int i = 0; i < terminos; ++i) {
        if (i > 0) {
            factorial *= i;
        }
        e += 1.0 / factorial;
    }

    cout.precision(10);
    cout << fixed << "e ≈ " << e << endl;
}

/**
 * @brief Muestra el menú principal
 */
void mostrarMenuPrincipal() {
    int opcion;
    do {
        cout << "\n=== MENÚ PRINCIPAL ==="
             << "\n1. Desglose de dinero"
             << "\n2. Suma de tiempos"
             << "\n3. Aproximación de euler"
             << "\n4. Sumatoria de múltiplos"
             << "\n5. Salir"
             << "\nSeleccione opción (1-5): ";

        while (!(cin >> opcion) || opcion < 1 || opcion > 5) {
            cout << "Opción inválida. Ingrese 1-5: ";
            limpiarBuffer();
        }
        limpiarBuffer();

        switch (opcion) {
        case 1: desgloseMonedas(); break;
        case 2: sumarTiempos(); break;
        case 3: aproximarConstanteE(); break;
        case 4: calcularSumatoriaMultiplos(); break;
        case 5: cout << "Saliendo del programa...\n"; break;
        }

    } while (opcion != 5);
}

/**
 * Función principal que inicia el sistema
 */
int main() {
    cout << "========================================";
    cout << "\nPROYECTO PROBLEMAS LAB. 2 PRÁCTICA 1";
    cout << "\n========================================";

    mostrarMenuPrincipal();

    return 0;
}
