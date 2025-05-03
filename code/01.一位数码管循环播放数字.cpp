#include <Arduino.h>

int a= 13;
int b= 12;
int c= 14;
int d= 27;
int e= 26;
int f= 25;
int g= 33;
int point=32;


int pin_array[] = {a, b, c, d, e, f, g, point};

int number_array[11][8] = {
  {1, 1, 1, 1, 1, 1, 0, 0}, // 0 -> 点亮a, b, c, d, e, f，关闭g和小数点
  {0, 1, 1, 0, 0, 0, 0, 0}, // 1 -> 点亮b, c，关闭其他段和小数点
  {1, 1, 0, 1, 1, 0, 1, 0}, // 2 -> 点亮a, b, d, e, g，关闭c, f和小数点
  {1, 1, 1, 1, 0, 0, 1, 0}, // 3 -> 点亮a, b, c, d, g，关闭e, f和小数点
  {0, 1, 1, 0, 0, 1, 1, 0}, // 4 -> 点亮b, c, f, g，关闭a, d, e和小数点
  {1, 0, 1, 1, 0, 1, 1, 0}, // 5 -> 点亮a, c, d, f, g，关闭b, e和小数点
  {1, 0, 1, 1, 1, 1, 1, 0}, // 6 -> 点亮a, c, d, e, f, g，关闭b和小数点
  {1, 1, 1, 0, 0, 0, 0, 0}, // 7 -> 点亮a, b, c，关闭d, e, f, g和小数点
  {1, 1, 1, 1, 1, 1, 1, 0}, // 8 -> 点亮所有段，关闭小数点
  {1, 1, 1, 1, 0, 1, 1, 0}, // 9 -> 点亮a, b, c, d, f, g，关闭e和小数点
  {0, 0, 0, 0, 0, 0, 0, 1}  // 小数点 -> 仅点亮小数点，关闭所有段
};

void display_number(int num) {
  for (int i=0;i<8;i++){
    digitalWrite(pin_array[i], number_array[num][i]); // 设置每个引脚的电平状态;
  }
}

void setup() {
  for (int i = 0; i < 8; i++) {
    pinMode(pin_array[i], OUTPUT);       // 设置所有引脚为输出模式
    digitalWrite(pin_array[i], LOW);   // 初始化所有引脚为高电平（熄灭状态）
  }
}

void loop() {
  for (int num = 0; num <= 10; num++)
  {
    display_number(num);
    delay(1000); // 延时1秒
  }
}