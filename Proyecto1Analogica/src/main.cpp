//Hector Manuel de Leon Salguero
//Universidad del Valle de Guatmala
//
//
//
//*****************************************************************************
//Librerias
//*****************************************************************************

#include <Arduino.h>
//*****************************************************************************
//Definicion de pines
//*****************************************************************************

#define ledV 0
#define ledA 2
#define ledR 15
#define pwmChannel 5  // 16 canales 0-15
#define pwmChannel2 4
#define pwmChannel3 3
#define freqPWM 5000  // Frecuencia en Hz
#define resolution 8  // 1-16 bits de resolución 

#define boton1 13

#define servo 12
// Paso 1: selección de parámetros de la señal PWM
#define pwmChnlServo 2 // 16 canales 0-15
#define freqPWMServo 50 // Frecuencia en Hz
//#define resolution 8  // 1-16 bits de resolución  creo que sobra


//*****************************************************************************
//Prototipos de funciones
//*****************************************************************************
void configurarPWM(void);
//*****************************************************************************
//Variables Globales
//*****************************************************************************
float temperatura = 0;

//variables al separar el valor del sensor
int decenas = 0;
int unidades = 0;
int decimales = 0;

//var para el interruptor del boton
int banderaB1 = 0;




//*****************************************************************************
//ISR
//*****************************************************************************

//*****************************************************************************
//Configuracion
//*****************************************************************************

void setup() {
  configurarPWM();

  void leds(void);
}

//*****************************************************************************
//Loop principal
//*****************************************************************************

void loop() {
  temperatura = 37.4;
  void leds();
}

//****************************************************************
// Función para configurar módulo PWM
//****************************************************************
void configurarPWM(void){

  // Paso 1: Configurar el módulo PWM
  ledcSetup(pwmChannel, freqPWM, resolution);
  ledcSetup(pwmChannel2, freqPWM, resolution);
  ledcSetup(pwmChannel3, freqPWM, resolution);

  ledcSetup(pwmChnlServo, freqPWMServo, resolution);


  // Paso 2: seleccionar en que GPIO tendremos nuestra señal PWM
  ledcAttachPin(ledV, pwmChannel);
  ledcAttachPin(ledA, pwmChannel2);
  ledcAttachPin(ledR, pwmChannel3);

  ledcAttachPin(servo, pwmChnlServo);

}

//*****************************************************************************
//Funcion Leds
//*****************************************************************************
void leds(){
  if (temperatura <= 37.0){
    ledcWrite(pwmChannel, 200);
    ledcWrite(pwmChannel2, 0);
    ledcWrite(pwmChannel3, 0);
  }

  if (37.0 < temperatura < 37.5){
    ledcWrite(pwmChannel, 0);
    ledcWrite(pwmChannel2, 200);
    ledcWrite(pwmChannel3, 0);
  }

  if (temperatura >= 37.5){
    ledcWrite(pwmChannel, 0);
    ledcWrite(pwmChannel2, 0);
    ledcWrite(pwmChannel3, 200);
  }

}