#include "pitches.h"
#include <Arduino.h>

#define NOTE_REST 0  // 定义休止符为 0

#define BUZZER_PIN 25
#define NOTE_DURATION  250  // 单音持续时间（ms）
#define PAUSE_BETWEEN_NOTES 80  // 音符间基础间隔
#define INTER_PHRASE_PAUSE 500  // 乐句间额外间隔

int dongfanghong_melody[] = {
  // 第一乐句：东方红
  NOTE_G4, NOTE_G4, NOTE_A4, NOTE_D4,
  NOTE_C4, NOTE_C4, NOTE_A4, NOTE_D4,
  NOTE_G4, NOTE_G4, NOTE_REST,        // 插入休息符
  NOTE_A4, NOTE_C4, NOTE_A4, NOTE_G4,

  // 第二乐句：太阳升
  NOTE_C4, NOTE_C4, NOTE_A4, NOTE_D4,
  NOTE_G4, NOTE_D4, NOTE_C4, NOTE_B4, NOTE_A4,
  NOTE_REST,  // 乐句间休息
  
  // 副歌部分
  NOTE_G4, NOTE_G4, NOTE_D4, NOTE_E4, NOTE_D4,
  NOTE_C4, NOTE_C4, NOTE_A4, NOTE_D4, NOTE_E4, NOTE_D4,
  NOTE_C4, NOTE_D4, NOTE_C4, NOTE_B4, NOTE_A4,
  NOTE_G4
};

void setup() {
  pinMode(BUZZER_PIN, OUTPUT);
}

void playMelody() {
  int numNotes = sizeof(dongfanghong_melody) / sizeof(int);
  
  for (int i = 0; i < numNotes; i++) {
    if(dongfanghong_melody[i] == NOTE_REST) {
      delay(INTER_PHRASE_PAUSE);  // 乐句间长间隔
      continue;
    }
    
    tone(BUZZER_PIN, dongfanghong_melody[i], NOTE_DURATION);
    delay(NOTE_DURATION + PAUSE_BETWEEN_NOTES); // 基础间隔
    noTone(BUZZER_PIN);
    
    // 额外添加词句间间隔
    if(i % 8 == 7) delay(INTER_PHRASE_PAUSE); // 每8个音加长间隔
  }
}

void loop() {
  playMelody();
  delay(5000); // 整曲播放间隔
}