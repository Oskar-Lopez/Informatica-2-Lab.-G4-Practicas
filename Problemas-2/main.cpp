#include <iostream>

// Declaraciones de funciones (prototipos)
int numeroAleatorio(int limite);
bool compararCadenas(const char* cad1, const char* cad2);
int cadenaAEntero(const char* cadena);
void convertirEnteroACadena(int numero, char* cadena);
void convertirMinusculasAMayusculas(char* cadena);
void eliminarRepetidos(char* cadena);
void separarNumerosTexto(const char* entrada, char* salidaTexto, char* salidaNumeros);
int sumarGrupos(const char* cadena, int n, char* desglose);
int valorRomano(char c);
void mostrarSalaCine(const char sala[][20], int filas, int asientosPorFila);
bool salaCineLlena(const char sala[][20], int filas, int asientosPorFila);
void reservarAsientoCine(char sala[][20], char fila, int asiento);
void cancelarReservaCine(char sala[][20], char fila, int asiento);
bool esCuadradoMagico(const int matriz[][10], int n);
bool esEstrella(const int matriz[][8], int i, int j);
int contarEstrellas(const int matriz[][8], int filas, int columnas);
void imprimirMatriz(int matriz[5][5]);
void rotar90(int original[5][5], int rotada[5][5]);
void rotar180(int original[5][5], int rotada[5][5]);
void rotar270(int original[5][5], int rotada[5][5]);

int main() {
    int opcion;

    std::cout << "=== SELECCION DE PROGRAMAS ===" << std::endl;
    std::cout << "1. Conversor de denominaciones monetarias" << std::endl;
    std::cout << "2. Generador y contador de letras aleatorias" << std::endl;
    std::cout << "3. Comparador de cadenas de caracteres" << std::endl;
    std::cout << "4. Convertir cadena numérica a entero" << std::endl;
    std::cout << "5. Convertir entero a cadena numérica" << std::endl;
    std::cout << "6. Convertir minúsculas a mayúsculas" << std::endl;
    std::cout << "7. Eliminar caracteres repetidos" << std::endl;
    std::cout << "8. Separar números de texto" << std::endl;
    std::cout << "9. Sumar grupos de n cifras" << std::endl;
    std::cout << "10. Convertir romano a arábigo" << std::endl;
    std::cout << "11. Sistema de reservas de cine" << std::endl;
    std::cout << "12. Verificador de cuadrado mágico" << std::endl;
    std::cout << "13. Detector de estrellas en galaxia" << std::endl;
    std::cout << "14. Rotación de matriz 5x5" << std::endl;
    std::cout << "0. Salir" << std::endl;
    std::cout << "Ingrese su opción (0-14): ";
    std::cin >> opcion;

    switch(opcion) {
    case 1: {
        /*****************************************************
         * PROGRAMA 1: CONVERSOR DE DENOMINACIONES MONETARIAS *
         *****************************************************/
        const int billetesMonedas[] = {50000, 20000, 10000, 5000, 2000, 1000, 500, 200, 100, 50};
        const int numDenominaciones = sizeof(billetesMonedas) / sizeof(billetesMonedas[0]);
        int cantidad;
        int contador[numDenominaciones] = {0};

        std::cout << "\n[CONVERSOR MONETARIO]" << std::endl;
        std::cout << "Ingrese la cantidad a desglosar: $";
        std::cin >> cantidad;

        int cantidadOriginal = cantidad;

        for (int i = 0; i < numDenominaciones; i++) {
            if (cantidad >= billetesMonedas[i]) {
                contador[i] = cantidad / billetesMonedas[i];
                cantidad %= billetesMonedas[i];
            }
        }

        std::cout << "\nDesglose para $" << cantidadOriginal << ":" << std::endl;
        bool sePuedeLograr = false;

        for (int i = 0; i < numDenominaciones; i++) {
            if (contador[i] > 0) {
                std::cout << "- $" << billetesMonedas[i] << ": " << contador[i] << std::endl;
                sePuedeLograr = true;
            }
        }

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
        const int tamaño = 200;
        char letras[tamaño];
        int contador[26] = {0};

        std::cout << "\n[GENERADOR DE LETRAS]" << std::endl;

        for (int i = 0; i < tamaño; i++) {
            letras[i] = 'A' + numeroAleatorio(26);
        }

        std::cout << "Muestra del arreglo (50 primeros caracteres): ";
        for (int i = 0; i < 50 && i < tamaño; i++) {
            std::cout << letras[i];
        }
        std::cout << "..." << std::endl;

        for (int i = 0; i < tamaño; i++) {
            contador[letras[i] - 'A']++;
        }

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

        std::cin.ignore();

        std::cout << "\n[COMPARADOR DE CADENAS]" << std::endl;
        std::cout << "Ingrese la primera cadena: ";
        std::cin.getline(cadena1, tamaño);
        std::cout << "Ingrese la segunda cadena: ";
        std::cin.getline(cadena2, tamaño);

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
        const int MAX_LONGITUD = 100;
        char cadenaNum[MAX_LONGITUD];

        std::cin.ignore();

        std::cout << "\n[CONVERSOR DE CADENA A ENTERO]" << std::endl;
        std::cout << "Ingrese una cadena numerica: ";
        std::cin.getline(cadenaNum, MAX_LONGITUD);

        int numeroConvertido = cadenaAEntero(cadenaNum);
        std::cout << "El numero convertido es: " << numeroConvertido << std::endl;
        break;
    }

    case 5: {
        /*****************************************************
         * PROGRAMA 5: CONVERTIR ENTERO A CADENA NUMÉRICA *
         *****************************************************/
        const int MAX_LONGITUD = 20;
        char cadenaResultado[MAX_LONGITUD];

        std::cout << "\n[CONVERSOR DE ENTERO A CADENA]" << std::endl;
        int numero;
        std::cout << "Ingrese un numero entero: ";
        std::cin >> numero;

        convertirEnteroACadena(numero, cadenaResultado);
        std::cout << "El numero como cadena es: \"" << cadenaResultado << "\"" << std::endl;
        break;
    }

    case 6: {
        /*****************************************************
         * PROGRAMA 6: CONVERTIR MINÚSCULAS A MAYÚSCULAS *
         *****************************************************/
        const int MAX_LONGITUD = 100;
        char cadena[MAX_LONGITUD];

        std::cin.ignore();

        std::cout << "\n[CONVERSOR DE MINÚSCULAS A MAYÚSCULAS]" << std::endl;
        std::cout << "Ingrese una cadena de caracteres: ";
        std::cin.getline(cadena, MAX_LONGITUD);

        convertirMinusculasAMayusculas(cadena);
        std::cout << "Cadena convertida a mayúsculas: " << cadena << std::endl;
        break;
    }

    case 7: {
        /*****************************************************
         * PROGRAMA 7: ELIMINAR CARACTERES REPETIDOS         *
         *****************************************************/
        const int MAX_LONGITUD = 100;
        char cadena[MAX_LONGITUD];

        std::cin.ignore();

        std::cout << "\n[ELIMINADOR DE CARACTERES REPETIDOS]" << std::endl;
        std::cout << "Ingrese una cadena: ";
        std::cin.getline(cadena, MAX_LONGITUD);

        eliminarRepetidos(cadena);
        std::cout << "Cadena sin repetidos: " << cadena << std::endl;
        break;
    }

    case 8: {
        /*****************************************************
         * PROGRAMA 8: SEPARAR NÚMEROS DE TEXTO              *
         *****************************************************/
        const int MAX_LONGITUD = 100;
        char cadena[MAX_LONGITUD];
        char texto[MAX_LONGITUD];
        char numeros[MAX_LONGITUD];

        std::cin.ignore();

        std::cout << "\n[SEPARADOR DE NÚMEROS Y TEXTO]" << std::endl;
        std::cout << "Ingrese una cadena: ";
        std::cin.getline(cadena, MAX_LONGITUD);

        separarNumerosTexto(cadena, texto, numeros);
        std::cout << "Original: " << cadena << std::endl;
        std::cout << "Texto: " << texto << ". Números: " << numeros << std::endl;
        break;
    }

    case 9: {
        /*****************************************************
         * PROGRAMA 9: SUMAR GRUPOS DE N CIFRAS              *
         *****************************************************/
        const int MAX_LONGITUD = 100;
        const int MAX_DESGLOSE = 200;
        char cadena[MAX_LONGITUD];
        char desglose[MAX_DESGLOSE] = {0};
        int n;

        std::cin.ignore();

        std::cout << "\n[SUMAR GRUPOS DE N CIFRAS]" << std::endl;
        std::cout << "Ingrese el valor de n: ";
        std::cin >> n;
        std::cin.ignore();

        std::cout << "Ingrese cadena numérica: ";
        std::cin.getline(cadena, MAX_LONGITUD);

        int resultado = sumarGrupos(cadena, n, desglose);
        std::cout << "Original: " << cadena << "." << std::endl;
        std::cout << "Suma: " << desglose << "=" << resultado << "." << std::endl;
        break;
    }

    case 10: {
        /*****************************************************
         * PROGRAMA 10: CONVERSOR ROMANO A ARÁBIGO           *
         *****************************************************/
        const int MAX_ROMANO = 100;
        char romano[MAX_ROMANO];

        std::cin.ignore();

        std::cout << "\n[CONVERSOR ROMANO A ARÁBIGO]" << std::endl;
        std::cout << "Ingrese número romano: ";
        std::cin.getline(romano, MAX_ROMANO);

        // Procesamiento directo
        int total = 0;
        for(int i = 0; romano[i] != '\0'; i++) {
            int actual = valorRomano(romano[i]);
            int siguiente = valorRomano(romano[i+1]);

            if (actual >= siguiente) {
                total += actual;
            } else {
                total -= actual;
            }
        }

        std::cout << "El número ingresado fue: " << romano << std::endl;
        std::cout << "Que corresponde a: " << total << std::endl;
        break;
    }

    case 11: {
        /*****************************************************
         * PROGRAMA 11: SISTEMA DE RESERVAS DE CINE          *
         *****************************************************/
        const int FILAS_CINE = 15;
        const int ASIENTOS_POR_FILA = 20;
        char salaCine[FILAS_CINE][ASIENTOS_POR_FILA];
        char opcionCine;
        char fila;
        int asiento;

        // Inicializar todos los asientos como disponibles
        for (int i = 0; i < FILAS_CINE; i++) {
            for (int j = 0; j < ASIENTOS_POR_FILA; j++) {
                salaCine[i][j] = '-';
            }
        }

        do {
            std::cout << "\n--- Gestion de Reservas de Cine ---\n";
            mostrarSalaCine(salaCine, FILAS_CINE, ASIENTOS_POR_FILA);

            if (salaCineLlena(salaCine, FILAS_CINE, ASIENTOS_POR_FILA)) {
                std::cout << "La sala esta completamente llena.\n";
                break;
            }

            std::cout << "Seleccione una opcion:\n";
            std::cout << "1. Reservar asiento\n";
            std::cout << "2. Cancelar reserva\n";
            std::cout << "3. Salir\n";
            std::cin >> opcionCine;

            switch (opcionCine) {
            case '1': {
                // Validar fila
                do {
                    std::cout << "Ingrese la fila (A-O): ";
                    std::cin >> fila;
                    if (fila >= 'a' && fila <= 'o') {
                        fila = fila - 'a' + 'A'; // Convertir a mayúscula
                    }
                } while (fila < 'A' || fila > 'O');

                // Validar asiento
                do {
                    std::cout << "Ingrese el numero del asiento (1-20): ";
                    std::cin >> asiento;
                } while (asiento < 1 || asiento > 20);

                reservarAsientoCine(salaCine, fila, asiento);
                break;
            }
            case '2': {
                // Validar fila
                do {
                    std::cout << "Ingrese la fila (A-O): ";
                    std::cin >> fila;
                    if (fila >= 'a' && fila <= 'o') {
                        fila = fila - 'a' + 'A'; // Convertir a mayúscula
                    }
                } while (fila < 'A' || fila > 'O');

                // Validar asiento
                do {
                    std::cout << "Ingrese el numero del asiento (1-20): ";
                    std::cin >> asiento;
                } while (asiento < 1 || asiento > 20);

                cancelarReservaCine(salaCine, fila, asiento);
                break;
            }
            case '3':
                std::cout << "Saliendo del sistema de reservas...\n";
                break;
            default:
                std::cout << "Opcion invalida.\n";
                break;
            }
        } while (opcionCine != '3');
        break;
    }

    case 12: {
        /*****************************************************
             * PROGRAMA 12: VERIFICADOR DE CUADRADO MÁGICO  *
        *****************************************************/
        const int MAX_DIM = 10;
        int matriz[MAX_DIM][MAX_DIM];
        int n;

        std::cout << "\n[VERIFICADOR DE CUADRADO MAGICO]" << std::endl;

        // Solicitar dimensión con validación
        do {
            std::cout << "Ingrese la dimension de la matriz cuadrada (2-" << MAX_DIM << "): ";
            std::cin >> n;
        } while (n < 2 || n > MAX_DIM);

        // Ingresar elementos
        std::cout << "Ingrese los elementos de la matriz:" << std::endl;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                std::cout << "Elemento [" << i+1 << "][" << j+1 << "]: ";
                std::cin >> matriz[i][j];
            }
        }

        // Mostrar matriz
        std::cout << "\nMatriz ingresada:" << std::endl;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                std::cout << matriz[i][j] << "\t";
            }
            std::cout << std::endl;
        }

        // Verificar y mostrar resultado
        if (esCuadradoMagico(matriz, n)) {
            std::cout << "\nLa matriz SI es un cuadrado magico." << std::endl;
        } else {
            std::cout << "\nLa matriz NO es un cuadrado magico." << std::endl;
        }
        break;
    }

    case 13: {
        /*****************************************************
            * PROGRAMA 13: DETECTOR DE ESTRELLAS EN GALAXIA *
        *****************************************************/
        const int filas = 6;
        const int columnas = 8;
        int matriz[filas][columnas] = {
            {0, 3, 4, 0, 0, 0, 6, 8},
            {5, 13, 6, 0, 0, 0, 2, 3},
            {2, 6, 2, 7, 3, 0, 10, 0},
            {0, 0, 4, 15, 4, 1, 6, 0},
            {0, 0, 7, 12, 6, 9, 10, 4},
            {5, 0, 6, 10, 6, 4, 8, 0}
        };

        std::cout << "\n[DETECTOR DE ESTRELLAS EN GALAXIA NGC 1300]" << std::endl;

        // Mostrar la matriz de la galaxia
        std::cout << "\nMatriz de luminosidad:" << std::endl;
        for (int i = 0; i < filas; ++i) {
            for (int j = 0; j < columnas; ++j) {
                std::cout << matriz[i][j] << "\t";
            }
            std::cout << std::endl;
        }

        // Contar estrellas
        int totalEstrellas = contarEstrellas(matriz, filas, columnas);

        std::cout << "\nNumero de estrellas detectadas: " << totalEstrellas << std::endl;
        std::cout << "(Ignorando bordes de la imagen)" << std::endl;
        break;
    }

    case 14: {
        // Declaramos la matriz 5x5 y la llenamos con los números del 1 al 25
        int matriz[5][5] = {
            { 1,  2,  3,  4,  5},
            { 6,  7,  8,  9, 10},
            {11, 12, 13, 14, 15},
            {16, 17, 18, 19, 20},
            {21, 22, 23, 24, 25}
        };

        // Matrices para almacenar las rotaciones
        int rotada90[5][5], rotada180[5][5], rotada270[5][5];

        // Imprimir la matriz original
        std::cout << "\nMatriz original:" << std::endl;
        imprimirMatriz(matriz);

        // Rotar la matriz 90 grados
        rotar90(matriz, rotada90);
        std::cout << "Matriz rotada 90 grados:" << std::endl;
        imprimirMatriz(rotada90);

        // Rotar la matriz 180 grados
        rotar180(matriz, rotada180);
        std::cout << "Matriz rotada 180 grados:" << std::endl;
        imprimirMatriz(rotada180);

        // Rotar la matriz 270 grados
        rotar270(matriz, rotada270);
        std::cout << "Matriz rotada 270 grados:" << std::endl;
        imprimirMatriz(rotada270);
        break;
    }

    case 0: {
        std::cout << "Saliendo del programa..." << std::endl;
        break;
    }
        default: {
            std::cout << "Opción no válida" << std::endl;
        }
    }

    return 0;
}

// Implementaciones de funciones

// Case 2: Generador y contador de letras aleatorias
int numeroAleatorio(int limite) {
    static int semilla = 1;
    semilla = (semilla + 1) % 100;
    return semilla % limite;
}

// Case 3: Comparador de cadenas de caracteres
bool compararCadenas(const char* cad1, const char* cad2) {
    int i = 0;
    while (cad1[i] != '\0' && cad2[i] != '\0') i++;

    if (cad1[i] != cad2[i]) return false;

    for (i = 0; cad1[i] != '\0'; i++) {
        if (cad1[i] != cad2[i]) return false;
    }

    return true;
}

// Case 4: Convertir cadena numérica a entero
int cadenaAEntero(const char* cadena) {
    int resultado = 0;
    int signo = 1;
    int i = 0;

    if (cadena[0] == '-') {
        signo = -1;
        i = 1;
    }

    while (cadena[i] != '\0') {
        if (cadena[i] >= '0' && cadena[i] <= '9') {
            resultado = resultado * 10 + (cadena[i] - '0');
            i++;
        } else {
            break;
        }
    }

    return resultado * signo;
}

// Case 5: Convertir entero a cadena numérica
void convertirEnteroACadena(int numero, char* cadena) {
    int i = 0;
    bool esNegativo = false;

    if (numero < 0) {
        esNegativo = true;
        numero = -numero;
    }

    do {
        cadena[i++] = (numero % 10) + '0';
        numero /= 10;
    } while (numero > 0);

    if (esNegativo) {
        cadena[i++] = '-';
    }

    cadena[i] = '\0';

    for (int j = 0, k = i - 1; j < k; j++, k--) {
        char temp = cadena[j];
        cadena[j] = cadena[k];
        cadena[k] = temp;
    }
}

// Case 6: Convertir minúsculas a mayúsculas
void convertirMinusculasAMayusculas(char* cadena) {
    int i = 0;

    while (cadena[i] != '\0') {
        if (cadena[i] >= 'a' && cadena[i] <= 'z') {
            cadena[i] = cadena[i] - ('a' - 'A');
        }
        i++;
    }
}

// Case 7: Eliminar caracteres repetidos
void eliminarRepetidos(char* cadena) {
    int i = 0, j, k;

    while (cadena[i] != '\0') {
        j = i + 1;

        while (cadena[j] != '\0') {
            if (cadena[i] == cadena[j]) {
                k = j;
                while (cadena[k] != '\0') {
                    cadena[k] = cadena[k + 1];
                    k++;
                }
            } else {
                j++;
            }
        }
        i++;
    }
}

// Case 8: Separar números de texto
void separarNumerosTexto(const char* entrada, char* salidaTexto, char* salidaNumeros) {
    int idxTexto = 0;
    int idxNumeros = 0;

    for (int i = 0; entrada[i] != '\0'; i++) {
        if (entrada[i] >= '0' && entrada[i] <= '9') {
            salidaNumeros[idxNumeros++] = entrada[i];
        } else {
            salidaTexto[idxTexto++] = entrada[i];
        }
    }

    salidaTexto[idxTexto] = '\0';
    salidaNumeros[idxNumeros] = '\0';
}

// Case 9: Sumar grupos de n cifras
int sumarGrupos(const char* cadena, int n, char* desglose) {
    int suma_total = 0;
    int longitud = 0;
    int digitos = 0;

    while (cadena[longitud] != '\0') longitud++;

    int ceros = (n - (longitud % n)) % n;
    char* d = desglose;
    for (int i = 0; i < ceros; i++) {
        *d++ = '0';
        digitos++;
    }

    int num_actual = 0;
    for (int i = 0; cadena[i] != '\0'; i++) {
        num_actual = num_actual * 10 + (cadena[i] - '0');
        *d++ = cadena[i];
        digitos++;

        if (digitos % n == 0) {
            suma_total += num_actual;
            num_actual = 0;
            if (cadena[i+1] != '\0') *d++ = '+';
        }
    }
    *d = '\0';
    return suma_total;
}

// Case 10: Convertir romano a arábigo
int valorRomano(char c) {
    switch(c) {
    case 'M': return 1000;
    case 'D': return 500;
    case 'C': return 100;
    case 'L': return 50;
    case 'X': return 10;
    case 'V': return 5;
    case 'I': return 1;
    default: return 0;
    }
}

// Case 11: Sistema de reservas de cine
void mostrarSalaCine(const char sala[][20], int filas, int asientosPorFila) {
    std::cout << "  ";
    for (int i = 1; i <= asientosPorFila; ++i) {
        if (i < 10) std::cout << " ";
        std::cout << i << " ";
    }
    std::cout << std::endl;

    for (int i = 0; i < filas; ++i) {
        std::cout << char('A' + i) << " ";
        for (int j = 0; j < asientosPorFila; ++j) {
            std::cout << sala[i][j] << "  ";
        }
        std::cout << std::endl;
    }
}

bool salaCineLlena(const char sala[][20], int filas, int asientosPorFila) {
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < asientosPorFila; j++) {
            if (sala[i][j] == '-') {
                return false;
            }
        }
    }
    return true;
}

void reservarAsientoCine(char sala[][20], char fila, int asiento) {
    int filaIndex = fila - 'A';
    if (sala[filaIndex][asiento - 1] == '-') {
        sala[filaIndex][asiento - 1] = '+';
        std::cout << "Asiento reservado exitosamente.\n";
    } else {
        std::cout << "El asiento ya esta reservado.\n";
    }
}

void cancelarReservaCine(char sala[][20], char fila, int asiento) {
    int filaIndex = fila - 'A';
    if (sala[filaIndex][asiento - 1] == '+') {
        sala[filaIndex][asiento - 1] = '-';
        std::cout << "Reserva cancelada exitosamente.\n";
    } else {
        std::cout << "El asiento ya esta disponible.\n";
    }
}

// Case 12: Verificador de cuadrado mágico
bool esCuadradoMagico(const int matriz[][10], int n) {
    int suma_base = 0;
    int suma_diag1 = 0, suma_diag2 = 0;

    for (int j = 0; j < n; j++) {
        suma_base += matriz[0][j];
    }

    for (int i = 0; i < n; i++) {
        suma_diag1 += matriz[i][i];
        suma_diag2 += matriz[i][n-1-i];
    }

    if (suma_diag1 != suma_base || suma_diag2 != suma_base) {
        return false;
    }

    for (int i = 0; i < n; i++) {
        int suma_fila = 0;
        int suma_col = 0;

        for (int j = 0; j < n; j++) {
            suma_fila += matriz[i][j];
            suma_col += matriz[j][i];
        }

        if (suma_fila != suma_base || suma_col != suma_base) {
            return false;
        }
    }

    return true;
}

// Case 13: Detector de estrellas en galaxia
bool esEstrella(const int matriz[][8], int i, int j) {
    float promedio = (matriz[i][j] + matriz[i][j-1] + matriz[i][j+1] +
                      matriz[i-1][j] + matriz[i+1][j]) / 5.0f;
    return promedio > 6.0f;
}

int contarEstrellas(const int matriz[][8], int filas, int columnas) {
    int estrellas = 0;

    for (int i = 1; i < filas - 1; ++i) {
        for (int j = 1; j < columnas - 1; ++j) {
            if (esEstrella(matriz, i, j)) {
                estrellas++;
            }
        }
    }

    return estrellas;
}

// Case 14: Rotación de matriz 5x5
void imprimirMatriz(int matriz[5][5]) {
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            std::cout << matriz[i][j] << "\t";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

void rotar90(int original[5][5], int rotada[5][5]) {
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            rotada[j][5 - i - 1] = original[i][j];
        }
    }
}

void rotar180(int original[5][5], int rotada[5][5]) {
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            rotada[5 - i - 1][5 - j - 1] = original[i][j];
        }
    }
}

void rotar270(int original[5][5], int rotada[5][5]) {
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            rotada[5 - j - 1][i] = original[i][j];
        }
    }
}
