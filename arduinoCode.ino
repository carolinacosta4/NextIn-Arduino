#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 10, 5, 4, 3, 2);

int backLight = 8;
int buzzer = 7;

void setup() {
  pinMode(backLight, OUTPUT);
  digitalWrite(backLight, HIGH);
  lcd.begin(16, 2);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Proxima senha:");
  lcd.setCursor(0, 1);
  lcd.print(" ");  // Limpa o campo da senha

  Serial.begin(9600);
  pinMode(buzzer, OUTPUT);
  digitalWrite(buzzer, LOW);
}

void loop() {
  // Verifica se há dados disponíveis na porta serial
  if (Serial.available() > 0) {
    String data = Serial.readStringUntil('\n'); // Lê a linha inteira com a senha formatada, como B01 ou C10

    // Toca o buzzer ao mudar o número
    tone(buzzer, 1500, 1000);
    delay(1000);
    noTone(buzzer);

    // Atualiza o display com o número da senha diretamente
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Proxima senha:");
    lcd.setCursor(0, 1);
    lcd.print(data); 
  }
}
