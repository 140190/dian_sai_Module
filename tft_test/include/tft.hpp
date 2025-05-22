#ifndef TFT_HPP
#define TFT_HPP


#include <TFT_eSPI.h>
#include <Arduino.h>
#include <SPI.h>



TFT_eSPI tft = TFT_eSPI();  // 初始化TFT对象



  void updateDisplay(const char* id, uint8_t mess) {
    //static int row = 0;
    //int yPos = 60 + row * 20;  // 每行高度20像素+初始高度
  
    // 清空当前行
    tft.fillRect(10, 80, 220, 18, TFT_BLACK);
  
    // 显示货物编号（居中）
    tft.setTextSize(3);
    tft.setCursor(20, 80);
    tft.print(id);
  
    // 显示位置坐标（居中）
    tft.setCursor(120, 80);
    tft.print(mess);
  
    //row = row + 1;  // 限制显示10行（超出后覆盖最旧数据）
  }
  
  void updateDisplay1(uint8_t mess) {
    static int row = 0;
    int yPos = 60 + row * 20;  // 每行高度20像素+初始高度
  
    // 清空当前行
     
    tft.fillRect(10, yPos, 220, 18, TFT_BLACK);
  
    // // 显示货物编号（居中）
    // tft.setTextSize(2);
    // tft.setCursor(20, yPos);
    // tft.print(id);
  
    // 显示位置坐标（居中）
    tft.setCursor(120, yPos);
    tft.print(mess);
  
    row = row + 1;  // 限制显示10行（超出后覆盖最旧数据）
  }

  void tft_init(){
    tft.init();
    tft.setRotation(0);  // 屏幕旋转方向（根据实际调整）
    tft.fillScreen(TFT_BLACK);  // 清屏为黑色
    tft.setTextColor(TFT_WHITE, TFT_BLACK);  // 白字黑底 
  }

 
#endif