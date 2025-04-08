/**
 * @file     Problemas-2.cpp
 * @brief    Programa con múltiples funcionalidades: conversor monetario, generador de letras,
 *           comparador de cadenas y conversor de cadena a entero.
 * @author   [Oscar Lopez Peñata]
 * @date     [Abril de 2025]
 * @version  1.0
 */

#include <iostream>

/**
 * @brief Función principal que muestra un menú interactivo con diversas opciones.
 *
 * El programa ofrece 4 funcionalidades principales:
 * 1. Conversor de denominaciones monetarias
 * 2. Generador y contador de letras aleatorias
 * 3. Comparador de cadenas de caracteres
 * 4. Convertir cadena numérica a entero
 *
 * @return 0 si el programa termina correctamente
 */
int main() {
    int opcion;

    // Mostrar menú principal
    std::cout << "=== SELECCION DE PROGRAMAS ===" << std::endl;
    std::cout << "1. Conversor de denominaciones monetarias" << std::endl;
    std::cout << "2. Generador y contador de letras aleatorias" << std::endl;
    std::cout << "3. Comparador de cadenas de caracteres" << std::endl;
    std::cout << "4. Convertir cadena numérica a entero" << std::endl;
    std::cout << "Ingrese su opcion (1-4): ";
    std::cin >> opcion;

    switch(opcion) {
    case 1: {
        /*****************************************************
         * PROGRAMA 1: CONVERSOR DE DENOMINACIONES MONETARIAS *
         *****************************************************/
        /**
         * @brief Desglosa una cantidad monetaria en billetes y monedas disponibles.
         *
         * - Usa denominaciones predefinidas de mayor a menor valor
         * - Calcula la cantidad de cada denominación necesaria
         * - Muestra el resultado del desglose
         * - Maneja cantidades residuales que no pueden ser cubiertas
         */

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
                contador[i] = cantidad / billetesMonedas[i]; // Calcula unidades necesarias
                cantidad %= billetesMonedas[i]; // Actualiza cantidad restante
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
        /**
         * @brief Genera letras aleatorias y cuenta su frecuencia.
         *
         * - Crea un arreglo de 200 letras mayúsculas aleatorias (A-Z)
         * - Muestra una muestra de 50 caracteres
         * - Cuenta la frecuencia de cada letra en el arreglo
         * - Muestra el recuento de letras que aparecen al menos una vez
         */

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
        /**
         * @brief Compara dos cadenas de caracteres ingresadas por el usuario.
         *
         * - Lee dos cadenas de hasta 100 caracteres
         * - Compara longitud y contenido carácter por carácter
         * - Muestra si son iguales o diferentes
         */

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

    case 4: {
        /*****************************************************
         * PROGRAMA 4: CONVERTIR CADENA NUMÉRICA A ENTERO *
         *****************************************************/
        /**
         * @brief Convierte una cadena de caracteres numéricos a un valor entero.
         *
         * - Maneja números positivos y negativos
         * - Ignora caracteres no numéricos después del número
         * - Muestra el resultado de la conversión
         */

        const int tamaño = 100;
        char cadenaNum[tamaño];

        std::cin.ignore(); // Limpiar el buffer del teclado

        // Función local para convertir cadena a entero
        auto cadenaAEntero = [](const char* cadena) -> int {
            int resultado = 0;
            int signo = 1;
            int i = 0;

            // Manejar signo negativo
            if (cadena[0] == '-') {
                signo = -1;
                i = 1;
            }

            // Convertir cada carácter a dígito y construir el número
            while (cadena[i] != '\0') {
                if (cadena[i] >= '0' && cadena[i] <= '9') {
                    resultado = resultado * 10 + (cadena[i] - '0');
                    i++;
                } else {
                    // Si encuentra un carácter no numérico, salir del bucle
                    break;
                }
            }

            return resultado * signo;
        };

        std::cout << "\n[CONVERSOR DE CADENA A ENTERO]" << std::endl;
        std::cout << "Ingrese una cadena numerica: ";
        std::cin.getline(cadenaNum, tamaño);

        int numero = cadenaAEntero(cadenaNum);
        std::cout << "El numero convertido es: " << numero << std::endl;
        break;
    }

    default:
        std::cout << "\n[!] Opcion no valida. Por favor seleccione 1-4." << std::endl;
        break;
    }

    return 0;
}
