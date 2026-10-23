// ESP32 温度控制灯光系统
// DS18B20: GPIO26    LED: GPIO27
#include <OneWire.h>
#include <DallasTemperature.h>

#define TEMP_PIN  26
#define LED_PIN   27

OneWire oneWire(TEMP_PIN);
DallasTemperature sensors(&oneWire);

void setup() {
  Serial.begin(115200);
  sensors.begin();
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, LOW);
}

void loop() {
  sensors.requestTemperatures();
  float temp = sensors.getTempCByIndex(0);

  // 温度大于28℃，点亮LED；否则熄灭
  if(temp > 28){
    digitalWrite(LED_PIN, HIGH);
  }else{
    digitalWrite(LED_PIN, LOW);
  }

  Serial.print("当前温度：");
  Serial.print(temp,2);
  Serial.print(" ℃ | LED：");
  Serial.println(digitalRead(LED_PIN)?"开启":"关闭");

  delay(1000);
}
