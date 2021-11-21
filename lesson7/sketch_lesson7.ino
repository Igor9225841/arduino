/* Подключение датчика CJMCU8118 к Arduino UNO
   VCC -> 3.3V
   GND -> GND
   SCL -> A5
   SDA -> A4
   WAK -> GND
*/

/* При нажатии на кнопку в обработчике прерывания выставляется флаг в 1.
 * В цикле проводится проверка состояния флага, если флаг выставлен в 1,
 * то выполняется выведение данных с датчика в последовательный порт.
 * На время передачи в полседовательный порт производится вкл. светодиода.
 * 
 * 
 * 
 */

#include <Wire.h>
#include <Adafruit_CCS811.h>
#include <ClosedCube_HDC1080.h>
#include <TFT.h>                 // Подключаем библиотеку TFT  
#include <SPI.h>                 // Подключаем библиотеку SPI

#define cs   10                  // Указываем пины cs
#define dc   9                   // Указываем пины dc (A0)
#define rst  8                   // Указываем пины reset
#define button 2                 // Вход кнопки
#define led    3                 // Выход на светодиод   

Adafruit_CCS811 ccs;
ClosedCube_HDC1080 hdc1080;
TFT TFTscreen = TFT(cs, dc, rst);

char sensorT [5];               //Массив символов для значения температуры
char sensorH [5];               //Массив символов для значения влажности
char sensorTVO [5];             // Массив символов для значения TVO
char sensorCO2 [5];             //Массив символов для значения СО2
double dataT= 0;                //Сохранение значения температуры
double dataH= 0;                //Сохранение значения влажности
double dataTVO= 0;                //Сохранение значения TVO
double dataCO2= 0;                //Сохранение значения CO2
volatile boolean intFlag= false;  //Флаг состояния кнопки

void setup()
{
  Serial.begin(9600);
  Serial.println("HDC1080 TEST");
  Serial.println("CCS811 TEST");
  hdc1080.begin(0x40);

  pinMode (button, INPUT_PULLUP);
  pinMode (led, OUTPUT);
  attachInterrupt (0, buttonTick, FALLING);

  if (!ccs.begin())
  {
    Serial.println("Couldn't find sensor!");
    while (1);
  }
  while (!ccs.available());

  TFTscreen.begin();
  TFTscreen.background(0, 0, 0); // Очистим экран дисплея
  TFTscreen.setTextSize(2);      // Устанавливаем размер шрифта
}

//Функция выведения данных датчика в последовательный порт
void terminalPrint (double dataT, double dataH, double dataTVO, double dataCO2);

// Обработчик прерывания
void buttonTick ()
{
  intFlag= true;                
}

void loop()
{
  if (ccs.available())
  {
    if (!ccs.readData())
    {
      dataT= hdc1080.readTemperature();
      dataH= hdc1080.readHumidity();
      dataTVO= ccs.getTVOC();
      dataCO2= ccs.geteCO2();
    }
    else
    {
      Serial.println("ERROR!");
      while (1);
    }
  }
  
//Преобразование типов значений с датчиков: double -> string -> char[] 
  (String (dataT, 5)).toCharArray(sensorT, 5);
  (String (dataH, 5)).toCharArray(sensorH, 5);
  (String (dataTVO, 5)).toCharArray(sensorTVO, 5);
  (String (dataCO2, 5)).toCharArray(sensorCO2, 5);

  /*Установка цвета фона TFTscreen.background ( r , g , b )
    где, r, g и b являются значениями RGB для заданного цвета
  */
  TFTscreen.background ( 0 , 0 , 0 );
  /*Команда установки цвета фона TFTscreen.stroke ( r , g , b )
    где, r, g и b являются значениями RGB для заданного цвета
  */
  TFTscreen.stroke(255, 0, 0);
  TFTscreen.setTextSize(2);      // Устанавливаем размер шрифта
  TFTscreen.text("T=", 5, 17);
  TFTscreen.text(sensorT, 35, 17);
  TFTscreen.text("C", 90, 17);
  TFTscreen.text("H=", 5, 42);
  TFTscreen.text(sensorH, 35, 42);
  TFTscreen.text("%", 90, 42);
  TFTscreen.text("co2=", 5, 67);
  TFTscreen.text(sensorCO2, 60, 67);
  TFTscreen.setTextSize(1);      // Устанавливаем размер шрифта
  TFTscreen.text("ppm", 110, 67);
  TFTscreen.setTextSize(2);      // Устанавливаем размер шрифта
  TFTscreen.text("tvo=", 5, 92);
  TFTscreen.text(sensorTVO, 58, 95);
  TFTscreen.setTextSize(1);      // Устанавливаем размер шрифта
  TFTscreen.text("ppb", 110, 92);
  delay(5000);  // Задержка 1 с

  if (intFlag)
  {
    intFlag= false;      //Сбрасываем состояние флага
    terminalPrint (dataT, dataH, dataTVO, dataCO2);
  }
}

void terminalPrint (double dataT, double dataH, double dataTVO, double dataCO2)
{
  digitalWrite (led, HIGH); //Включаем светодиод на время передачи данных в посл.порт
  Serial.print("Temp: ");
  Serial.print (dataT);
  Serial.print("^C, Hum: ");
  Serial.print(dataH);
  Serial.println("%");
  Serial.print(__DATE__);
  Serial.print(", ");
  Serial.print(__TIME__);
  Serial.print(" -> ");
  Serial.print("CO2: ");
  Serial.print(dataCO2);
  Serial.print("ppm, TVOsensorC: ");
  Serial.print(dataTVO);
  Serial.print("ppb, ");
  digitalWrite (led, LOW);  //Отключение светодиода передачи данных
}
