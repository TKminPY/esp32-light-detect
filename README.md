# esp32-light-detect
基于ESP32的温度控制灯光系统

## 项目功能
1. DS18B20采集环境温度
2. 根据温度阈值自动控制LED灯光：温度高于设定值开灯/低于设定值关灯
3. 串口实时打印温度数值、LED工作状态

## 硬件清单
- ESP32开发板
- DS18B20温度传感器 + 4.7kΩ上拉电阻
- LED灯、220Ω限流电阻

## 开发环境
Arduino IDE
依赖库：OneWire、DallasTemperature

## 引脚分配
DS18B20：GPIO26
LED灯：GPIO27
