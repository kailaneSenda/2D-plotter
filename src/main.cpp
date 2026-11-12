#include <Arduino.h>
#include <Servo.h>
#include "config.h"

Servo penServo;

void setup() {
  Serial.begin(115200);
  
  // Configura os pinos dos motores como saída
  pinMode(X_STEP_PIN, OUTPUT);
  pinMode(X_DIR_PIN, OUTPUT);
  pinMode(X_EN_PIN, OUTPUT);
  
  pinMode(Y_STEP_PIN, OUTPUT);
  pinMode(Y_DIR_PIN, OUTPUT);
  pinMode(Y_EN_PIN, OUTPUT);

  // Habilita os motores (Active LOW no A4988)
  digitalWrite(X_EN_PIN, LOW);
  digitalWrite(Y_EN_PIN, LOW);

  // Inicializa o Servo
  penServo.attach(SERVO_PIN);
  penServo.write(PEN_UP_ANGLE); // Começa com a caneta para cima

  Serial.println("Plotter Iniciado!");
}

void loop() {
  // Teste 1: Gira o motor X 200 passos (1 volta) para a direita
  digitalWrite(X_DIR_PIN, HIGH);
  for (int i = 0; i < 200; i++) {
    digitalWrite(X_STEP_PIN, HIGH);
    delayMicroseconds(500);
    digitalWrite(X_STEP_PIN, LOW);
    delayMicroseconds(500);
  }

  // Teste 2: Abaixa a caneta
  penServo.write(PEN_DOWN_ANGLE);
  delay(PEN_DWELL_MS); // Tempo de espera obrigatório

  // Teste 3: Gira o motor X 200 passos para a esquerda
  digitalWrite(X_DIR_PIN, LOW);
  for (int i = 0; i < 200; i++) {
    digitalWrite(X_STEP_PIN, HIGH);
    delayMicroseconds(500);
    digitalWrite(X_STEP_PIN, LOW);
    delayMicroseconds(500);
  }

  // Teste 4: Levanta a caneta
  penServo.write(PEN_UP_ANGLE);
  delay(PEN_DWELL_MS);
  
  delay(2000); // Pausa antes de repetir o loop
}