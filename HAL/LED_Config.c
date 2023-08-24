#include "LED_Config.h"
// please enter the the id of all leds in these enum
typedef enum
{
    led0,
    led1,
    ledgnth,
}LED_ID_t;
u8 NumberOfLeds = ledgnth;
// please enter the the specs of leds
LED_T Arr_Leds[ledgnth] = {
    {led0, LED_PORT0, LED_PIN0},
    {led1, LED_PORT1, LED_PIN1}};
