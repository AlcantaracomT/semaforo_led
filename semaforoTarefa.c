#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/timer.h"

const uint red = 13;
const uint green = 11;
const uint yellow = 12;

void init();
bool callback(repeating_timer_t *t);
void alternar_leds();  

volatile int estado_led = 0; 

int main() {
  stdio_init_all();
  init();

  repeating_timer_t timer;

  //chamar a cada 500ms
  add_repeating_timer_ms(3000, callback, NULL, &timer);

  while (1) 
  {
    printf("funcionando\n");
    sleep_ms(1000);
  }
}

// Inicializa os pinos
void init() {
    gpio_init(red);
    gpio_init(yellow);
    gpio_init(green);

    gpio_set_dir(red, GPIO_OUT);
    gpio_set_dir(yellow, GPIO_OUT);
    gpio_set_dir(green, GPIO_OUT);
}

// Callback do timer
bool callback(repeating_timer_t *t) {
  alternar_leds();
  return true;  
}

// Alterna os LEDs a cada chamada do timer
void alternar_leds() {
  gpio_put(red, 0);
  gpio_put(yellow, 0);
  gpio_put(green, 0);

  if (estado_led == 0) 
  {
    gpio_put(red, 1);
  } 
  else if (estado_led == 1) 
  {
    gpio_put(yellow, 1);
  } 
  else 
  {
    gpio_put(green, 1);
  }

  estado_led = (estado_led + 1) % 3;
}
