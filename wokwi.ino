#include <DHT.h>

#define DHTPIN 15
#define DHTTYPE DHT22 

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(115200);
  dht.begin();
}

// nesse codigo exemplo ele apenas lê a humidade e a temperatura
void loop() {
  float h = dht.readHumidity();
  float t = dht.readTemperature(); 

  if (isnan(h) || isnan(t)) {
    Serial.println("Erro ao ler DHT22!");
    return;
  }

  Serial.print("Umidade: ");
  Serial.print(h);
  Serial.print(" %  |  ");

  Serial.print("Temperatura: ");
  Serial.print(t);
  Serial.println(" °C");

  delay(2000); 
}