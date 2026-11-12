#ifndef CONFIG_H
#define CONFIG_H

// Pinos do Driver X (Eixo X)
#define X_STEP_PIN 2
#define X_DIR_PIN  3
#define X_EN_PIN   4

// Pinos do Driver Y (Eixo Y)
#define Y_STEP_PIN 5
#define Y_DIR_PIN  6
#define Y_EN_PIN   7

// Pinos do Servo (Caneta)
#define SERVO_PIN  9

// Pinos dos Endstops
#define X_ENDSTOP_PIN 10
#define Y_ENDSTOP_PIN 11

// Parâmetros Mecânicos (Simulação Wokwi)
// Motor 1.8 graus = 200 passos/volta
// Fuso: 3mm por volta
// Microstepping: 1 (passo completo no simulador)
#define STEPS_PER_MM_X 66.67
#define STEPS_PER_MM_Y 66.67

// Limites de Curso
#define MAX_TRAVEL_X 38.0
#define MAX_TRAVEL_Y 38.0

// Ângulos do Servo (Caneta)
#define PEN_UP_ANGLE   90
#define PEN_DOWN_ANGLE 0
#define PEN_DWELL_MS   150

// Configurações de Movimento
#define ACCELERATION 100.0
#define DRAW_FEED    10.0
#define TRAVEL_FEED  15.0

#endif