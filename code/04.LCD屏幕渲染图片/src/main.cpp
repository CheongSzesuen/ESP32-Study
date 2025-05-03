#include <Arduino.h>
#include <TFT_eSPI.h>
#include <SPI.h>
#include "../image_data.h"  // 确保路径正确

TFT_eSPI tft = TFT_eSPI();

void setup() {
  tft.init();
  tft.setRotation(1);  // 设置屏幕旋转方向
  tft.setSwapBytes(true);  // 如果需要，交换字节顺序
  tft.fillScreen(TFT_WHITE);  // 填充屏幕为白色

  // 计算图片在屏幕上的居中位置
  int16_t x = (SCREEN_WIDTH - IMAGE_WIDTH) / 2;
  int16_t y = (SCREEN_HEIGHT - IMAGE_HEIGHT) / 2;

  // 确保 x 和 y 不为负值
  x = (x > 0) ? x : 0;  // 使用条件运算符替代 max
  y = (y > 0) ? y : 0;  // 使用条件运算符替代 max

  // 显示图片
  tft.pushImage(x, y, IMAGE_WIDTH, IMAGE_HEIGHT, const_cast<uint16_t *>(image_data));
}

void loop() {
  // 空循环，图片已经在 setup 中显示
}