#include <LiquidCrystal.h>

// Configuración de pines: RS, E, D4, D5, D6, D7
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

// Función para convertir un carácter romano a su valor arábigo
int valorRomano(char c) {
  switch(c) {
    case 'M': return 1000;
    case 'D': return 500;
    case 'C': return 100;
    case 'L': return 50;
    case 'X': return 10;
    case 'V': return 5;
    case 'I': return 1;
    default: return 0;  // En caso de que el carácter no sea válido
  }
}

void setup() {
  // Inicializa la comunicación serial
  Serial.begin(9600);
  
  // Inicializa la pantalla LCD (16 columnas y 2 filas)
  lcd.begin(16, 2);
  
  // Mensaje inicial en el Monitor Serial
  Serial.println("Ingrese un numero en sistema romano (ej. DCLXVI):");

  // Mensaje inicial en la pantalla LCD
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Ingrese num:");
}

void loop() {
  // Verifica si hay datos disponibles en el Serial
  if (Serial.available() > 0) {
    // Lee la cadena ingresada por el usuario
    String numeroRomano = Serial.readString();
    numeroRomano.trim();  // Elimina espacios o caracteres de nueva línea
    
    // Variable para almacenar el total en arábigo
    int totalArabigo = 0;
    
    // Recorre cada carácter en la cadena
    for (int i = 0; i < numeroRomano.length(); i++) {
      int valorActual = valorRomano(numeroRomano[i]);
      int valorSiguiente = valorRomano(numeroRomano[i + 1]);  // Valor del siguiente carácter
      
      // Aplica las reglas de suma y resta
      if (valorActual < valorSiguiente) {
        // Si el valor actual es menor que el siguiente, se resta
        totalArabigo -= valorActual;
      } else {
        // Si el valor actual es mayor o igual, se suma
        totalArabigo += valorActual;
      }
    }
    
    // Imprime el resultado en el Monitor Serial
    Serial.print("El numero ingresado fue: ");
    Serial.println(numeroRomano);
    Serial.print("Que corresponde a: ");
    Serial.println(totalArabigo);
    
    // Mostrar el resultado en la pantalla LCD
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Roman: ");
    lcd.print(numeroRomano.substring(0, 8));  // Mostrar los primeros 8 caracteres del número romano

    lcd.setCursor(0, 1);
    lcd.print("Arabigo: ");
    lcd.print(totalArabigo);  // Muestra el número convertido
    
    // Pausa para que el usuario vea el resultado durante 5 segundos
    delay(5000);
    
    // Pide al usuario que ingrese otro número
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Ingrese num:");
    Serial.println("\nIngrese otro numero en sistema romano:");
  }
}
