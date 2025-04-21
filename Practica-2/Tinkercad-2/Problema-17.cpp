#include <LiquidCrystal.h>

// LCD: RS, E, D4, D5, D6, D7
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

bool esperandoEntrada = true;

// Función optimizada para sumar divisores propios
int sumaDivisoresPropios(int num) {
  int suma = 1; // 1 siempre es divisor (excepto de 1 mismo)
  for (int i = 2; i * i <= num; i++) {
    if (num % i == 0) {
      suma += i;
      int otro = num / i;
      if (otro != i) suma += otro;
    }
  }
  return (num == 1) ? 0 : suma;
}

// Limpia el buffer del serial
void limpiarSerial() {
  while (Serial.available() > 0) Serial.read();
}

void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Ingrese n:");
  Serial.println("Ingrese un numero mayor a 1:");
}

void loop() {
  if (esperandoEntrada && Serial.available() > 0) {
    int n = Serial.parseInt();
    limpiarSerial();

    if (n <= 1) {
      Serial.println("Numero invalido. Intente de nuevo.");
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Numero invalido");
      delay(2000);
      lcd.clear();
      lcd.print("Ingrese n:");
      Serial.println("Ingrese un numero mayor a 1:");
      return;
    }

    esperandoEntrada = false;
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Calculando...");
    Serial.print("Buscando pares amigables < ");
    Serial.println(n);

    int sumaTotal = 0;
    int totalPares = 0;

    for (int a = 2; a < n; a++) {
      int b = sumaDivisoresPropios(a);
      if (b > a && b < n) {
        if (sumaDivisoresPropios(b) == a) {
          sumaTotal += a + b;
          totalPares++;

          Serial.print("Par: ");
          Serial.print(a);
          Serial.print(" y ");
          Serial.print(b);
          Serial.print(" -> Suma: ");
          Serial.println(a + b);

          // LCD solo muestra el último par encontrado
          lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print("Par:");
          lcd.print(a);
          lcd.print(",");
          lcd.print(b);
          lcd.setCursor(0, 1);
          lcd.print("Suma:");
          lcd.print(a + b);
          delay(500); // Tiempo breve visible
        }
      }
    }

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Suma total:");
    lcd.setCursor(0, 1);
    lcd.print(sumaTotal);

    Serial.print("Suma total de pares: ");
    Serial.println(sumaTotal);
    Serial.println();

    delay(3000); // Mostrar la suma total unos segundos

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Ingrese otro n:");
    Serial.println("Ingrese otro numero:");
    esperandoEntrada = true;
  }
}
