#include "joystick.h"
#include "pico/stdlib.h"


#define BAR_WIDTH 40
#define ADC_MAX ((1 << 12) - 1)

void init_adc() {
    adc_init();
    adc_gpio_init(26); // Configura GPIO 26 para entrada analógica (ADC0)
    adc_gpio_init(27); // Configura GPIO 27 para entrada analógica (ADC1)
}

uint read_adc_value(uint input) {
    adc_select_input(input);
    return adc_read();
}

void display_joystick(uint adc_x_raw, uint adc_y_raw) {
    uint bar_x_pos = adc_x_raw * BAR_WIDTH / ADC_MAX;
    uint bar_y_pos = adc_y_raw * BAR_WIDTH / ADC_MAX;
    
    printf("\rX: [");
    for (uint i = 0; i < BAR_WIDTH; ++i)
        putchar(i == bar_x_pos ? 'o' : ' ');
    printf("]  Y: [");
    for (uint i = 0; i < BAR_WIDTH; ++i)
        putchar(i == bar_y_pos ? 'o' : ' ');
    printf("]");
    fflush(stdout);
}




// int main() {
//     stdio_init_all();
//     init_adc();

//     while (1) {
//         uint adc_y_raw = read_adc_value(0); // Lê o ADC0 (Y)
//         uint adc_x_raw = read_adc_value(1); // Lê o ADC1 (X)
        
//         display_joystick(adc_x_raw, adc_y_raw);
//         sleep_ms(50);
//     }
// }