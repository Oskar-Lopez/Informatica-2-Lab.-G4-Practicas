#include <LiquidCrystal.h>

// Configuración de pines: RS, E, D4, D5, D6, D7
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  // Inicializa la comunicación serial
  Serial.begin(9600);
  
  // Inicializa la pantalla LCD (16 columnas y 2 filas)
  lcd.begin(16, 2);
  
  // Mensaje inicial en el monitor serial y en la pantalla LCD
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Ingrese Texto:");
  Serial.println("Por favor, ingrese una cadena de texto (max 32 caracteres):");
}

void loop() {
  // Verifica si hay datos disponibles en el Serial
  if (Serial.available() > 0) {
    // Lee la cadena ingresada por el usuario
    String cadenaOriginal = Serial.readString();
    
    // Elimina caracteres extras como nueva línea o retorno de carro
    cadenaOriginal.trim();

    // Imprime la cadena original en el monitor serial
    Serial.print("Original: ");
    Serial.println(cadenaOriginal);

    // Crea una nueva cadena para almacenar el resultado en mayúsculas
    String cadenaMayuscula = cadenaOriginal;

    // Recorre la cadena y convierte las letras minúsculas en mayúsculas
    for (int i = 0; i < cadenaOriginal.length(); i++) {
      if (cadenaOriginal[i] >= 'a' && cadenaOriginal[i] <= 'z') {
        // Convierte el carácter minúsculo a mayúscula restando 32 (diferencia en ASCII)
        cadenaMayuscula[i] = cadenaOriginal[i] - 32;
      }
    }

    // Imprime la cadena convertida a mayúsculas en el monitor serial
    Serial.print("En mayuscula: ");
    Serial.println(cadenaMayuscula);

    // Mostrar en la pantalla LCD
    lcd.clear();
    
    // Solo se muestran los primeros 16 caracteres en la primera línea del LCD
    lcd.setCursor(0, 0);
    lcd.print(cadenaMayuscula.substring(0, 16));  // Primera línea

    // Si la cadena tiene más de 16 caracteres, mostrar los siguientes en la segunda línea
    lcd.setCursor(0, 1);
    if (cadenaMayuscula.length() > 16) {
      lcd.print(cadenaMayuscula.substring(16, 32));  // Segunda línea
    } else {
      lcd.print("");  // Si no hay más, deja la segunda línea vacía
    }

    // Pausa para que el usuario vea el resultado
    delay(5000);
    
    // Pide al usuario que ingrese otra cadena
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Ingrese Texto:");
    Serial.println("\nPor favor, ingrese otra cadena de texto:");
  }
}
