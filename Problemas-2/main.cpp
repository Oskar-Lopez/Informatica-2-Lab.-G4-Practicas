#include <iostream>

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
    std::cout << "Ingrese su opcion (1-8): ";
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

        auto numeroAleatorio = [](int limite) {
            static int semilla = 1;
            semilla = (semilla + 1) % 100;
            return semilla % limite;
        };

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

        auto compararCadenas = [](const char* cad1, const char* cad2) -> bool {
            int i = 0;
            while (cad1[i] != '\0' && cad2[i] != '\0') i++;

            if (cad1[i] != cad2[i]) return false;

            for (i = 0; cad1[i] != '\0'; i++) {
                if (cad1[i] != cad2[i]) return false;
            }

            return true;
        };

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

        auto cadenaAEntero = [](const char* cadena) -> int {
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
        };

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

        auto convertirEnteroACadena = [](int numero, char* cadena) {
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
        };

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

        auto convertirMinusculasAMayusculas = [](char* cadena) {
            int i = 0;

            while (cadena[i] != '\0') {
                if (cadena[i] >= 'a' && cadena[i] <= 'z') {
                    cadena[i] = cadena[i] - ('a' - 'A');
                }
                i++;
            }
        };

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

    std::cin.ignore(); // Limpiar buffer

    auto eliminarRepetidos = [](char* cadena) {
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
    };

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

    auto separarNumerosTexto = [](const char* entrada, char* salidaTexto, char* salidaNumeros) {
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
    };

    std::cout << "\n[SEPARADOR DE NÚMEROS Y TEXTO]" << std::endl;
    std::cout << "Ingrese una cadena: ";
    std::cin.getline(cadena, MAX_LONGITUD);

    separarNumerosTexto(cadena, texto, numeros);
    std::cout << "Original: " << cadena << std::endl;
    std::cout << "Texto: " << texto << ". Números: " << numeros << std::endl;
    break;
}

default:
    std::cout << "\n[!] Opcion no valida. Por favor seleccione 1-8." << std::endl;
    break;
}

return 0;
}
