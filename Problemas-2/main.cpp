#include <iostream>

int main() {
    int opcion;

    std::cout << "=== SELECCION DE PROGRAMAS ===" << std::endl;
    std::cout << "1. Conversor de denominaciones monetarias" << std::endl;
    std::cout << "2. Generador y contador de letras aleatorias" << std::endl;
    std::cout << "3. Comparador de cadenas de caracteres" << std::endl;
    std::cout << "Ingrese su opcion (1-3): ";
    std::cin >> opcion;

    switch(opcion) {
    case 1: {
        /*****************************************************
             * PROGRAMA 1: CONVERSOR DE DENOMINACIONES MONETARIAS *
             *****************************************************/

        // Denominaciones disponibles (de mayor a menor)
        const int billetesMonedas[] = {50000, 20000, 10000, 5000, 2000, 1000, 500, 200, 100, 50};
        const int numDenominaciones = sizeof(billetesMonedas) / sizeof(billetesMonedas[0]);
        int cantidad;
        int contador[numDenominaciones] = {0}; // Inicializa todos los contadores a 0

        // Entrada de datos
        std::cout << "\n[CONVERSOR MONETARIO]" << std::endl;
        std::cout << "Ingrese la cantidad a desglosar: $";
        std::cin >> cantidad;

        // Guardamos el valor original para mostrar al final
        int cantidadOriginal = cantidad;

        // Proceso de desglose
        for (int i = 0; i < numDenominaciones; i++) {
            if (cantidad >= billetesMonedas[i]) {
                // Calcula cuántas unidades de esta denominación se necesitan
                contador[i] = cantidad / billetesMonedas[i];
                // Actualiza la cantidad restante
                cantidad %= billetesMonedas[i];
            }
        }

        // Mostrar resultados
        std::cout << "\nDesglose para $" << cantidadOriginal << ":" << std::endl;
        bool sePuedeLograr = false;

        for (int i = 0; i < numDenominaciones; i++) {
            if (contador[i] > 0) {
                std::cout << "- $" << billetesMonedas[i] << ": " << contador[i] << std::endl;
                sePuedeLograr = true;
            }
        }

        // Manejo de residuo
        if (cantidad > 0) {
            std::cout << "\n[!] No hay denominaciones para cubrir: $" << cantidad << std::endl;
        } else if (!sePuedeLograr && cantidadOriginal > 0) {
            std::cout << "\n[!] No hay denominaciones disponibles para esta cantidad." << std::endl;
        }
        break;
    }

    case 2: {
        /*****************************************************
             * PROGRAMA 2: GENERADOR Y CONTADOR DE LETRAS ALEATORIAS *
             *****************************************************/

        // Configuración inicial
        const int tamaño = 200;
        char letras[tamaño];
        int contador[26] = {0}; // Contador para cada letra (A-Z)

        // Función local para generar números pseudoaleatorios
        auto numeroAleatorio = [](int limite) {
            static int semilla = 1;
            semilla = (semilla + 1) % 100; // Actualiza la semilla
            return semilla % limite; // Retorna valor dentro del límite
        };

        std::cout << "\n[GENERADOR DE LETRAS]" << std::endl;

        // Generación de letras aleatorias
        for (int i = 0; i < tamaño; i++) {
            letras[i] = 'A' + numeroAleatorio(26); // Genera letra entre A-Z
        }

        // Mostrar muestra del arreglo (solo las primeras 50 letras)
        std::cout << "Muestra del arreglo (50 primeros caracteres): ";
        for (int i = 0; i < 50 && i < tamaño; i++) {
            std::cout << letras[i];
        }
        std::cout << "..." << std::endl;

        // Conteo de frecuencia de cada letra
        for (int i = 0; i < tamaño; i++) {
            contador[letras[i] - 'A']++; // Incrementa el contador correspondiente
        }

        // Mostrar resultados del conteo
        std::cout << "\nFrecuencia de letras:" << std::endl;
        for (int i = 0; i < 26; i++) {
            if (contador[i] > 0) {
                std::cout << "- " << static_cast<char>('A' + i)
                << ": " << contador[i] << " veces" << std::endl;
            }
        }
        break;
    }

    case 3: {
        /*****************************************************
             * PROGRAMA 3: COMPARADOR DE CADENAS DE CARACTERES *
             *****************************************************/
        const int tamaño = 100;
        char cadena1[tamaño], cadena2[tamaño];

        std::cin.ignore(); // Limpiar el buffer del teclado

        // Función local para comparar cadenas
        auto compararCadenas = [](const char* cad1, const char* cad2) -> bool {
            // Primero comparamos longitudes
            int i = 0;
            while (cad1[i] != '\0' && cad2[i] != '\0') i++;

            // Si alguno tiene diferente longitud
            if (cad1[i] != cad2[i]) return false;

            // Comparación carácter por carácter
            for (i = 0; cad1[i] != '\0'; i++) {
                if (cad1[i] != cad2[i]) return false;
            }

            return true;
        };

        std::cout << "\n[COMPARADOR DE CADENAS]" << std::endl;

        // Captura de cadenas
        std::cout << "Ingrese la primera cadena: ";
        std::cin.getline(cadena1, tamaño);

        std::cout << "Ingrese la segunda cadena: ";
        std::cin.getline(cadena2, tamaño);

        // Comparación y resultado
        bool sonIguales = compararCadenas(cadena1, cadena2);
        std::cout << "\nResultado de comparacion: "
                  << (sonIguales ? "TRUE (son iguales)" : "FALSE (son diferentes)")
                  << std::endl;
        break;
    }

    default:
        std::cout << "\n[!] Opcion no valida. Por favor seleccione 1-3." << std::endl;
        break;
    }

    return 0;
}
