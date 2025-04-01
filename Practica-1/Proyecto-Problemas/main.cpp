#include <iostream>

// Prototipos de funciones
/**
 * @brief Limpia el buffer de entrada para evitar problemas con lecturas posteriores
 */
void limpiarBuffer();

/**
 * @brief Lee y valida un número entero ingresado por el usuario
 * @param mensaje Mensaje a mostrar para solicitar la entrada
 * @return El número entero válido ingresado por el usuario
 */
int leerEntero(const char* mensaje);

/**
 * @brief Calcula la sumatoria de múltiplos de dos números menores que un tercero
 * @details Pide al usuario tres valores (a, b, c) y suma todos los múltiplos de a
 *          y b que sean menores que c (sin duplicar múltiplos comunes)
 */
void calcularSumatoriaMultiplos();

/**
 * @brief Realiza el desglose de una cantidad de dinero en billetes y monedas
 * @details Muestra cómo se puede representar una cantidad usando billetes
 *          de $50,000 a $1,000 y monedas de $500 a $50
 */
void desgloseMonedas();

/**
 * @brief Suma dos tiempos expresados en formato HHMM
 * @details Realiza la suma considerando las reglas de tiempo (60 minutos = 1 hora)
 *          y muestra el resultado en formato HHMM
 */
void sumarTiempos();

/**
 * @brief Aproxima el valor de la constante matemática e mediante series
 * @details Calcula e ≈ 1 + 1/1! + 1/2! + ... + 1/n! donde n es especificado por el usuario
 */
void aproximarConstanteE();

/**
 * @brief Encuentra el n-ésimo número primo
 * @details Calcula y muestra el número primo que se encuentra en la posición n
 *          de la secuencia de números primos
 */
void encontrarEnesimoPrimo();

/**
 * @brief Encuentra el mayor factor primo de un número
 * @details Descompone un número en sus factores primos y devuelve el mayor de ellos
 */
void encontrarMaxFactorPrimo();

/**
 * @brief Determina si un número es palíndromo
 * @param numero Número a evaluar
 * @return true si el número es palíndromo (se lee igual al derecho y al revés),
 *         false en caso contrario
 */
bool esPalindromo(int numero);

/**
 * @brief Encuentra el mayor palíndromo producto de dos números en un rango dado
 * @details Busca el mayor número palíndromo que puede obtenerse como producto de
 *          dos números de 3 dígitos dentro del rango especificado
 */
void encontrarPalindromoMultiplicacion();

/**
 * @brief Genera la serie de Collatz para una semilla dada
 * @param semilla Número inicial para la serie
 * @param imprimirSerie Si es true, muestra la serie completa en la salida
 * @return La longitud de la serie generada (número de términos)
 */
int collatzSerie(int semilla, bool imprimirSerie = false);

/**
 * @brief Encuentra la serie de Collatz más larga para semillas menores a un valor k
 * @details Evalúa todas las series para semillas desde 1 hasta k-1 y muestra
 *          información sobre la serie más larga encontrada
 */
void encontrarSerieCollatzMasLarga();

/**
 * @brief Muestra y gestiona el menú principal del programa
 * @details Presenta las opciones disponibles y redirige a la función correspondiente
 *          según la selección del usuario, en un ciclo hasta que se elija salir
 */
void mostrarMenuPrincipal();

/**
 * @brief Limpia el buffer de entrada
 */
void limpiarBuffer() {
    std::cin.clear();
    while (std::cin.get() != '\n');
}

/**
 * @brief Lee y valida un número entero
 */
int leerEntero(const char* mensaje) {
    int valor;
    while (true) {
        std::cout << mensaje;
        if (std::cin >> valor) {
            limpiarBuffer();
            return valor;
        }
        std::cout << "Error: Entrada inválida. ";
        limpiarBuffer();
    }
}

/**
 * @brief Determina si un número es primo
 */
bool esPrimo(int numero) {
    if (numero <= 1) return false;
    for (int i = 2; i * i <= numero; i++) {
        if (numero % i == 0) return false;
    }
    return true;
}

/**
 * @brief Encuentra el máximo factor primo de un número
 */
int maxFactorPrimo(int numero) {
    int factorMaximo = 1;

    // Eliminar todos los factores pares
    while (numero % 2 == 0) {
        factorMaximo = 2;
        numero /= 2;
    }

    // Buscar factores impares
    for (int i = 3; i * i <= numero; i += 2) {
        while (numero % i == 0) {
            factorMaximo = i;
            numero /= i;
        }
    }

    // Si queda un número primo mayor que 2
    if (numero > 2) {
        factorMaximo = numero;
    }

    return factorMaximo;
}

/**
 * @brief Verifica si un número es palíndromo (sin usar strings)
 */
bool esPalindromo(int numero) {
    if (numero < 0) return false;

    int original = numero;
    long reverso = 0;  // Usamos long para prevenir overflow

    while (numero > 0) {
        reverso = reverso * 10 + (numero % 10);
        numero /= 10;
    }

    return original == reverso;
}

/**
 * @brief Calcula la serie de Collatz para una semilla dada
 */
int collatzSerie(int semilla, bool imprimirSerie) {
    int longitud = 1;

    if (imprimirSerie) {
        std::cout << semilla << " ";
    }

    while (semilla != 1) {
        if (semilla % 2 == 0) {
            semilla /= 2;
        } else {
            semilla = 3 * semilla + 1;
        }

        longitud++;

        if (imprimirSerie) {
            std::cout << semilla << " ";
        }
    }

    if (imprimirSerie) {
        std::cout << "\n";
    }

    return longitud;
}

/**
 * @brief Calcula sumatoria de múltiplos de a y b menores que c
 */
void calcularSumatoriaMultiplos() {
    std::cout << "\n=== SUMATORIA DE MÚLTIPLOS ===\n";

    int a = leerEntero("Ingrese el valor de a: ");
    int b = leerEntero("Ingrese el valor de b: ");
    int c = leerEntero("Ingrese el valor de c: ");

    int sumatoria = 0;
    std::cout << "Sumatoria: ";

    // Sumar múltiplos de a menores que c
    for (int i = a; i < c; i += a) {
        sumatoria += i;
        std::cout << i << " + ";
    }

    // Sumar múltiplos de b menores que c (que no sean múltiplos de a)
    for (int i = b; i < c; i += b) {
        if (i % a != 0) {
            sumatoria += i;
            std::cout << i << " + ";
        }
    }

    std::cout << "\b\b= " << sumatoria << "\n";
}

/**
 * @brief Desglosa una cantidad en billetes y monedas
 */
void desgloseMonedas() {
    const int billetes[] = {50000, 20000, 10000, 5000, 2000, 1000};
    const int monedas[] = {500, 200, 100, 50};
    int cantidadBilletes[6] = {0};
    int cantidadMonedas[4] = {0};

    std::cout << "\n=== DESGLOSE DE DINERO ===\n";
    int cantidad = leerEntero("Ingrese la cantidad: ");
    int resto = cantidad;

    // Calcular billetes
    for (int i = 0; i < 6; i++) {
        cantidadBilletes[i] = resto / billetes[i];
        resto %= billetes[i];
    }

    // Calcular monedas
    for (int i = 0; i < 4; i++) {
        cantidadMonedas[i] = resto / monedas[i];
        resto %= monedas[i];
    }

    // Mostrar resultados
    std::cout << "\nDesglose:\n";
    for (int i = 0; i < 6; i++) {
        if (cantidadBilletes[i] > 0) {
            std::cout << "Billetes de $" << billetes[i] << ": " << cantidadBilletes[i] << "\n";
        }
    }
    for (int i = 0; i < 4; i++) {
        if (cantidadMonedas[i] > 0) {
            std::cout << "Monedas de $" << monedas[i] << ": " << cantidadMonedas[i] << "\n";
        }
    }
    if (resto > 0) {
        std::cout << "Restante: $" << resto << "\n";
    }
}

/**
 * @brief Suma dos tiempos en formato HHMM
 */
void sumarTiempos() {
    std::cout << "\n=== SUMA DE TIEMPOS ===\n";

    int hora, duracion;

    // Validar hora inicial
    do {
        hora = leerEntero("Ingrese hora inicial (HHMM): ");
        if (hora < 0 || hora % 100 >= 60 || hora / 100 >= 24) {
            std::cout << "Formato inválido. Use HHMM (00-23 horas, 00-59 minutos)\n";
        }
    } while (hora < 0 || hora % 100 >= 60 || hora / 100 >= 24);

    // Validar duración
    do {
        duracion = leerEntero("Ingrese duración (HHMM): ");
        if (duracion < 0 || duracion % 100 >= 60 || duracion / 100 >= 24) {
            std::cout << "Formato inválido. Use HHMM (00-23 horas, 00-59 minutos)\n";
        }
    } while (duracion < 0 || duracion % 100 >= 60 || duracion / 100 >= 24);

    // Calcular suma
    int minutos = (hora % 100) + (duracion % 100);
    int horas = (hora / 100) + (duracion / 100) + (minutos / 60);
    minutos %= 60;
    horas %= 24;

    // Mostrar resultado
    std::cout << "Hora resultante: ";
    if (horas < 10) std::cout << "0";
    std::cout << horas;
    if (minutos < 10) std::cout << "0";
    std::cout << minutos << "\n";
}

/**
 * @brief Aproxima la constante e usando serie infinita sin bibliotecas externas
 * @details Calcula e ≈ 1/0! + 1/1! + 1/2! + ... + 1/n!
 * Formato de salida: "e es aproximadamente: x.x"
 */
void aproximarConstanteE() {
    std::cout << "\n=== APROXIMACIÓN DE EULER ===\n";
    int terminos = leerEntero("Ingrese número de términos: ");

    double e = 1.0;  // Primer término (1/0!)
    double factorial = 1.0;

    // Calcular la serie
    for (int i = 1; i <= terminos; i++) {
        factorial *= i;          // Calcula i!
        e += 1.0 / factorial;   // Suma el término actual
    }

    // Mostrar resultado con 1 decimal sin usar <iomanip>
    std::cout << "e es aproximadamente: ";

    // Formateo manual para 1 decimal
    int parte_entera = static_cast<int>(e);
    int decimal = static_cast<int>((e - parte_entera) * 10 + 0.5); // Redondeo

    std::cout << parte_entera << "." << decimal << "\n";
}

/**
 * @brief Encuentra el n-ésimo número primo
 */
void encontrarEnesimoPrimo() {
    std::cout << "\n=== ENÉSIMO NÚMERO PRIMO ===\n";
    int n = leerEntero("Ingrese un número n: ");

    if (n < 1) {
        std::cout << "El número debe ser mayor o igual a 1\n";
        return;
    }

    int contador = 0;
    int numero = 2;

    while (contador < n) {
        if (esPrimo(numero)) {
            contador++;
            if (contador == n) break;
        }
        numero++;
    }

    std::cout << "El enésimo número primo es: " << numero << "\n";
}

/**
 * @brief Encuentra el máximo factor primo de un número
 */
void encontrarMaxFactorPrimo() {
    std::cout << "\n=== MÁXIMO FACTOR PRIMO ===\n";
    int numero = leerEntero("Ingrese un número: ");

    if (numero < 2) {
        std::cout << "El número debe ser mayor o igual a 2\n";
        return;
    }

    int factor = maxFactorPrimo(numero);
    std::cout << "El máximo factor primo de " << numero << " es: " << factor << "\n";
}

/**
 * @brief Encuentra el mayor palíndromo producto de dos números en un rango
 */
void encontrarPalindromoMultiplicacion() {
    std::cout << "\n=== PALÍNDROMO MÁXIMO DE MULTIPLICACIÓN ===\n";
    int inicio = leerEntero("Ingrese el número inicial (mínimo 100): ");
    int fin = leerEntero("Ingrese el número final (máximo 999): ");

    if (inicio < 100 || fin > 999 || inicio > fin) {
        std::cout << "Rango inválido. Debe ser entre 100 y 999, con inicio <= fin\n";
        return;
    }

    int maxPalindromo = 0;
    int num1 = 0, num2 = 0;

    for (int i = fin; i >= inicio; i--) {
        for (int j = i; j >= inicio; j--) {
            int producto = i * j;
            if (producto > maxPalindromo && esPalindromo(producto)) {
                maxPalindromo = producto;
                num1 = i;
                num2 = j;
            }
        }
    }

    if (maxPalindromo > 0) {
        std::cout << "El mayor palíndromo es: " << maxPalindromo << "\n";
        std::cout << "Producto de: " << num1 << " × " << num2 << "\n";
    } else {
        std::cout << "No se encontraron palíndromos en el rango especificado\n";
    }
}

/**
 * @brief Encuentra la serie de Collatz más larga para semillas menores a k
 */
void encontrarSerieCollatzMasLarga() {
    std::cout << "\n=== SERIE DE COLLATZ MÁS LARGA ===\n";
    int k = leerEntero("Ingrese un número k: ");

    if (k < 2) {
        std::cout << "El número debe ser mayor o igual a 2\n";
        return;
    }

    int semillaMax = 1;
    int maxLongitud = 1;

    for (int i = 2; i < k; i++) {
        int longitud = collatzSerie(i, false);
        if (longitud > maxLongitud) {
            maxLongitud = longitud;
            semillaMax = i;
        }
    }

    std::cout << "La serie más larga es con la semilla: " << semillaMax << "\n";
    std::cout << "Longitud: " << maxLongitud << " términos\n";
    std::cout << "Serie: ";
    collatzSerie(semillaMax, true);
}

/**
 * @brief Muestra el menú principal
 */
void mostrarMenuPrincipal() {
    int opcion;
    do {
        std::cout << "\n=== MENÚ PRINCIPAL ===\n"
                  << "1. Desglose de dinero\n"
                  << "2. Suma de tiempos\n"
                  << "3. Aproximación de Euler\n"
                  << "4. Sumatoria de múltiplos\n"
                  << "5. Encontrar n-ésimo primo\n"
                  << "6. Encontrar máximo factor primo\n"
                  << "7. Encontrar palíndromo máximo\n"
                  << "8. Encontrar serie Collatz más larga\n"
                  << "9. Salir\n"
                  << "Seleccione opción (1-9): ";

        opcion = leerEntero("");

        switch (opcion) {
        case 1: desgloseMonedas(); break;
        case 2: sumarTiempos(); break;
        case 3: aproximarConstanteE(); break;
        case 4: calcularSumatoriaMultiplos(); break;
        case 5: encontrarEnesimoPrimo(); break;
        case 6: encontrarMaxFactorPrimo(); break;
        case 7: encontrarPalindromoMultiplicacion(); break;
        case 8: encontrarSerieCollatzMasLarga(); break;
        case 9: std::cout << "Saliendo del programa...\n"; break;
        default: std::cout << "Opción inválida. Intente nuevamente.\n";
        }
    } while (opcion != 9);
}

/**
 * Función principal
 */
int main() {
    std::cout << "========================================\n"
              << "PROYECTO PROBLEMAS LAB. 2 PRÁCTICA 1\n"
              << "========================================\n";

    mostrarMenuPrincipal();
    return 0;
}
