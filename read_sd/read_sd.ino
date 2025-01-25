/*
  Adapted from the Adafruit and Xark's PDQ graphicstest sketch.

  See end of file for original header text and MIT license info.
*/

/*******************************************************************************
 * Start of Arduino_GFX setting
 ******************************************************************************/
#include <Arduino_GFX_Library.h>

/* OPTION 1: Uncomment a dev device in Arduino_GFX_dev_device.h */
#include "Arduino_GFX_dev_device.h"

#ifndef GFX_DEV_DEVICE
/* OPTION 2: Manual define hardware */

/* Step 1: Define pins in Arduino_GFX_databus.h */
#include "Arduino_GFX_pins.h"

/* Step 2: Uncomment your databus in Arduino_GFX_databus.h */
#include "Arduino_GFX_databus.h"

/* Step 3: Uncomment your display driver in Arduino_GFX_display.h */
#include "Arduino_GFX_display.h"
#include <Arduino.h>
#include <SPI.h>
#include <SD.h>
// #include <SdFat.h>

#endif /* Manual define hardware */
/*******************************************************************************
 * End of Arduino_GFX setting
 ******************************************************************************/

#ifdef ESP32
#undef F
#define F(s) (s)
#endif

#define TF_CS 42
#define TF_SDA 41
#define TF_SCL 40
#define TF_MISO 39

// SdFat SD;

int32_t w, h, n, n1, cx, cy, cx1, cy1, cn, cn1;
uint8_t tsa, tsb, tsc, ds;

void setup()
{
  #ifdef DEV_DEVICE_INIT
    DEV_DEVICE_INIT();
  #endif

  Serial.begin(115200);
  // Serial.setDebugOutput(true);
  Serial.println("Initializing SD card...");

  SPI.begin(TF_SCL, TF_MISO, TF_SDA, TF_CS);
  // 初始化 SD 卡
  if (!SD.begin(TF_CS)) {
    Serial.println("Card Mount Failed");
    return;
  }

  // File file = SD.open("test.txt", FILE_WRITE);
  // if (file) {
  //   file.println("Hello from SdFat!");
  //   file.close();
  //   Serial.println("File written successfully.");
  // } else {
  //   Serial.println("Failed to open file for writing.");
  // }

  uint8_t cardType = SD.cardType();

  if (cardType == CARD_NONE) {
    Serial.println("No SD card attached");
    return;
  }

  Serial.print("SD Card Type: ");
  if (cardType == CARD_MMC) {
    Serial.println("MMC");
  } else if (cardType == CARD_SD) {
    Serial.println("SDSC");
  } else if (cardType == CARD_SDHC) {
    Serial.println("SDHC");
  } else {
    Serial.println("UNKNOWN");
  }

}


void loop() {
  // 写入数据到SD卡
  // File file = SD.open("test.txt", FILE_WRITE);
  // if (!file) {
  //   Serial.println("无法打开文件进行写入!");
  //   return;
  // }
  
  // file.println("Hello, ESP32 S3!"); // 写入一行文本
  // file.close();                      // 关闭文件
  
  // // 读取数据从SD卡
  // File fileRead = SD.open("test.txt", FILE_READ);
  // if (!fileRead) {
  //   Serial.println("无法打开文件进行读取!");
  //   return;
  // }
  
  // while (true) {
  //   String line = "";
  //   char c;
  //   while ((c = fileRead.read()) != '\0') { // 逐字符读取
  //     line += c;
  //     if (c == '\n') break;               // 到换行符结束
  //   }
  //   Serial.println(line);                  // 输出到串口监视器
  //   if (line.length() == 0) break;         // 如果没有更多数据，退出循环
  // }
  
  // fileRead.close();                        // 关闭读取文件
  
  // delay(1000);                             // 延时1秒
}
