#ifndef MEASURE_DISTANCE_HPP
#define MEASURE_DISTANCE_HPP

#include <Arduino.h>

#define TRIG_PIN 12   // 超声波Trig引脚
#define ECHO_PIN 13  // 超声波Echo引脚

//引脚初始化
void Distance_init() {
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
}

float measureDistance() {
  // 确保Trig引脚初始为低电平（重要准备状态）
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);  // 短暂稳定
  
  // 发送10μs高电平脉冲（触发超声波发射）
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);  // 精确的触发信号时长
  digitalWrite(TRIG_PIN, LOW);

  // 测量Echo引脚的高电平持续时间（单位：微秒）
  // pulseIn()会等待引脚变为HIGH，开始计时，直到变为LOW停止
  long duration = pulseIn(ECHO_PIN, HIGH);

  // 距离计算公式分解：
  // 声速 = 343m/s = 0.0343 cm/μs
  // 时间包含往返距离，所以需要除以2
  return duration * 0.034 / 2; 
}


#endif // MEASURE_DISTANCE_HPP