#include <LiquidCrystal.h>

// Configuración de pines LCD
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

// Denominaciones de billetes y monedas
const long denominaciones[] = {50000, 20000, 10000, 5000, 2000, 1000, 500, 200, 100, 50};
const int numDenominaciones = 10;

// Variables de control
int paginaActual = 0;
unsigned long ultimoCambio = 0;
bool mostrandoResultados = false;
int resultado[10] = {0};
long cantidad = 0;
long faltante = 0;

void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);
  
  lcd.clear();
  lcd.print("Sistema Listo");
  delay(800);
  mostrarMensajeInicial();
}

void loop() {
  // Procesar nueva entrada
  if (Serial.available() > 0) {
    procesarEntrada();
    paginaActual = 0;
    ultimoCambio = millis();
    mostrandoResultados = true;
  }

  // Control de visualización de resultados
  if (mostrandoResultados) {
    if (millis() - ultimoCambio > 2000) { // Cambio 2 segundos
      paginaActual++;
      
      if (paginaActual > 3) { // Solo tenemos 4 páginas de resultados
        mostrandoResultados = false;
        mostrarMensajeInicial();
      } else {
        mostrarPaginaLCD();
        ultimoCambio = millis();
      }
    }
  }
}

void procesarEntrada() {
  String input = "";
  
  while (Serial.available() > 0) {
    char c = Serial.read();
    if (isDigit(c)) input += c;
    delay(5);
  }

  if (input.length() == 0) {
    mostrarError();
    return;
  }

  cantidad = input.toInt();
  
  if (cantidad <= 0) {
    mostrarError();
    return;
  }

  calcularDesglose();
  mostrarResultadosSerial();
  mostrarPaginaLCD();
}

void calcularDesglose() {
  faltante = cantidad;
  
  for (int i = 0; i < numDenominaciones; i++) {
    resultado[i] = (faltante >= denominaciones[i]) ? faltante / denominaciones[i] : 0;
    faltante %= denominaciones[i];
  }
}

void mostrarPaginaLCD() {
  lcd.clear();
  
  switch(paginaActual) {
    case 0: // Billetes grandes
      lcd.setCursor(0, 0);
      lcd.print("$50K:");
      lcd.print(resultado[0]);
      lcd.print(" $20K:");
      lcd.print(resultado[1]);
      
      lcd.setCursor(0, 1);
      lcd.print("$10K:");
      lcd.print(resultado[2]);
      lcd.print(" $5K:");
      lcd.print(resultado[3]);
      break;
      
    case 1: // Billetes medianos
      lcd.setCursor(0, 0);
      lcd.print("$2K:");
      lcd.print(resultado[4]);
      lcd.print(" $1K:");
      lcd.print(resultado[5]);
      
      lcd.setCursor(0, 1);
      lcd.print("$500:");
      lcd.print(resultado[6]);
      lcd.print(" $200:");
      lcd.print(resultado[7]);
      break;
      
    case 2: // Monedas y faltante
      lcd.setCursor(0, 0);
      lcd.print("$100:");
      lcd.print(resultado[8]);
      lcd.print(" $50:");
      lcd.print(resultado[9]);
      
      lcd.setCursor(0, 1);
      lcd.print("Faltante: $");
      lcd.print(faltante);
      break;
      
    case 3: // Resumen rápido
      lcd.setCursor(0, 0);
      lcd.print("Total: $");
      lcd.print(cantidad);
      lcd.setCursor(0, 1);
      lcd.print("Fin desglose");
      break;
  }
}

void mostrarResultadosSerial() {
  Serial.print("\nDesglose de $");
  Serial.println(cantidad);
  Serial.println("------------------");
  
  for (int i = 0; i < numDenominaciones; i++) {
    if (resultado[i] > 0) {
      Serial.print("$");
      Serial.print(denominaciones[i]);
      Serial.print(": ");
      Serial.println(resultado[i]);
    }
  }
  Serial.print("Faltante: $");
  Serial.println(faltante);
  Serial.println("------------------");
}

void mostrarMensajeInicial() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Ingrese cantidad");
  lcd.setCursor(0, 1);
  lcd.print("Ej: 47810");
  
  Serial.println("\nIngrese nueva cantidad:");
}

void mostrarError() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Error: Solo");
  lcd.setCursor(0, 1);
  lcd.print("numeros positivos");
  
  Serial.println("Error: Ingrese solo números positivos");
  delay(1500);
  mostrarMensajeInicial();
}

