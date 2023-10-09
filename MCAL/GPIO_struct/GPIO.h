#ifndef _GPIO_H
#define _GPIO_H
// Includes
#include "../MCAL_REGs.h"

// defines
//@ref ports

typedef enum
{
    PORTA,
    PORTB,
    PORTC,
    PORTD,
} port_t;
//@ref pins
typedef enum
{
    PIN0,
    PIN1,
    PIN2,
    PIN3,
    PIN4,
    PIN5,
    PIN6,
    PIN7,
} pin_t;
//@ref pin value
typedef enum
{
    low_value,
    high_value,
} pin_val_t;
//@ref pin direction
typedef enum
{
    Input_pin_direction,
    Output_pin_direction,
} pin_direction_t;
//@ref pin state
typedef enum
{
    state_low,
    state_high,
} pin_state_t;
//@ref port dicrection
typedef enum
{
    Input_Port_direction = 0x00,
    Out_Port_direction = 0xff,
} port_dicrection_t;

// API

typedef struct
{
    port_t port;
    pin_t pin;
    pin_direction_t direction;
    pin_val_t logic;
} GPIO_pin_t;

typedef struct
{
    port_t port;
    port_dicrection_t direction;
    u8 logic;
} GPIO_port_t;
/**
 * Sets the logic value for all pins in the specified GPIO port.
 *
 * @param port_ptr   Pointer to the GPIO port structure.
 * @param logic      The logic value to be set for all pins (0 or 1).
 * @return           Error_state indicating the success or failure of the operation.
 */
Error_state GPIO_setPortValue(GPIO_port_t *port_ptr, u8 logic);

/**
 * Sets the logic value for a specific GPIO pin.
 *
 * @param pin_ptr    Pointer to the GPIO pin structure.
 * @param logic      The logic value to be set for the pin (0 or 1).
 * @return           Error_state indicating the success or failure of the operation.
 */
Error_state GPIO_setPinValue(GPIO_pin_t *pin_ptr, pin_val_t logic);

/**
 * Sets the direction (input or output) for all pins in the specified GPIO port.
 *
 * @param port_ptr   Pointer to the GPIO port structure.
 * @param direction  The direction to be set for all pins (input or output).
 * @return           Error_state indicating the success or failure of the operation.
 */
Error_state GPIO_setPortDirection(GPIO_port_t *port_ptr, port_dicrection_t direction);

/**
 * Sets the direction (input or output) for a specific GPIO pin.
 *
 * @param pin_ptr    Pointer to the GPIO pin structure.
 * @param direction  The direction to be set for the pin (input or output).
 * @return           Error_state indicating the success or failure of the operation.
 */
Error_state GPIO_setPindDirection(GPIO_pin_t *pin_ptr, pin_direction_t direction);

/**
 * Retrieves the logic value of all pins in the specified GPIO port.
 *
 * @param port_ptr   Pointer to the GPIO port structure.
 * @param val        Pointer to store the retrieved input value.
 * @return           Error_state indicating the success or failure of the operation.
 */
Error_state GPIO_getPortValue(GPIO_port_t *port_ptr, u8 *val);

/**
 * Retrieves the logic value of a specific GPIO pin.
 *
 * @param pin_ptr    Pointer to the GPIO pin structure.
 * @param val        Pointer to store the retrieved input value.
 * @return           Error_state indicating the success or failure of the operation.
 */
Error_state GPIO_getPIN(GPIO_pin_t *pin_ptr,pin_state_t * val);

/**
 * Enables the pull-up resistor for a specific GPIO pin.
 *
 * @param pin_ptr    Pointer to the GPIO pin structure.
 * @return           Error_state indicating the success or failure of the operation.
 */
Error_state GPIO_setPin_PUll_UP(GPIO_pin_t *pin_ptr);
#endif