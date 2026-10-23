// ESP32 温度+灯光检测控制系统
// 光敏：GPIO34  温度传感器（DS18B20）：GPIO26
// 执行器件：LED灯 GPIO27、风扇GPIO25
#include <OneWire.h>
#include <DallasTemperature.h>

// 引脚定义
#define LIGHT_PIN 34
#define TEMP_PIN  26
#define LED_PIN   27
#define FAN_PIN   25

OneWire oneWire(TEMP_PIN);
DallasTemperature sensors(&oneWire);

void setup() {
  Serial.begin(115200);
  sensors.begin();
  pinMode(LED_PIN, OUTPUT);
  pinMode(FAN_PIN, OUTPUT);
  digitalWrite(LED_PIN, LOW);
  digitalWrite(FAN_PIN, LOW);
}

void loop() {
  // 读取光照
  int lightVal = analogRead(LIGHT_PIN);
  float lightVolt = lightVal * 3.3 / 4095.0;

  // 读取温度
  sensors.requestTemperatures();
  float temp = sensors.getTempCByIndex(0);

  // 灯光自动控制：光线暗则开灯
  if(lightVal > 2000){
    digitalWrite(LED_PIN, HIGH);
  }else{
    digitalWrite(LED_PIN, LOW);
  }

  // 温度自动控制：温度高于阈值开风扇
  if(temp > 28){
    digitalWrite(FAN_PIN, HIGH);
  }else{
    digitalWrite(FAN_PIN, LOW);
  }

  // 串口打印信息
  Serial.print("光照原始值：");
  Serial.print(lightVal);
  Serial.print("  电压：");
  Serial.print(lightVolt,2);
  Serial.print("V | 温度：");
  Serial.print(temp,2);
  Serial.print("℃ | LED:");
  Serial.print(digitalRead(LED_PIN)?"开":"关");
  Serial.print(" | 风扇:");
  Serial.println(digitalRead(FAN_PIN)?"开":"关");

  delay(1000);
}