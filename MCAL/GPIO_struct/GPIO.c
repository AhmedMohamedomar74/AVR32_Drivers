#include "GPIO.h"

Error_state GPIO_setPortValue(GPIO_port_t *port_ptr, u8 logic)
{
    Error_state locall_err = Unvalid_Port;
    if (NULL != port_ptr)
    {
        switch (port_ptr->port)
        {
        case PORTA:
            PORTA_Ptr = logic;
            locall_err = Valid_Port;
            break;
        case PORTB:
            PORTB_Ptr = logic;
            locall_err = Valid_Port;
            break;
        case PORTC:
            PORTC_Ptr = logic;
            locall_err = Valid_Port;
            break;
        case PORTD:
            PORTD_Ptr = logic;
            locall_err = Valid_Port;
            break;
        default:
            break;
        }
    }
    else
    {
        locall_err = NULL_POINTER;
    }

    return locall_err;
}

Error_state GPIO_setPinValue(GPIO_pin_t *pin_ptr, pin_val_t logic)
{
    Error_state locall_err = Unvalid_Port;
    if (NULL != pin_ptr)
    {
        if (logic == high_value)
        {
            switch (pin_ptr->port)
            {
            case PORTA:
                PORTA_Ptr |= (1 << (pin_ptr->pin));
                locall_err = Valid_Port;
                break;
            case PORTB:
                locall_err = Valid_Port;
                PORTB_Ptr |= (1 << (pin_ptr->pin));
                break;
            case PORTC:
                locall_err = Valid_Port;
                PORTC_Ptr |= (1 << (pin_ptr->pin));
                break;
            case PORTD:
                locall_err = Valid_Port;
                PORTD_Ptr |= (1 << (pin_ptr->pin));
                break;
            default:
                locall_err = Unvalid_Port;
                break;
            }
        }
        else if (logic == low_value)
        {
            switch (pin_ptr->port)
            {
            case PORTA:
                PORTA_Ptr &= ~(1 << (pin_ptr->pin));
                locall_err = Valid_Port;
                break;
            case PORTB:
                locall_err = Valid_Port;
                PORTB_Ptr &= ~(1 << (pin_ptr->pin));
                break;
            case PORTC:
                locall_err = Valid_Port;
                PORTC_Ptr &= ~(1 << (pin_ptr->pin));
                break;
            case PORTD:
                locall_err = Valid_Port;
                PORTD_Ptr &= ~(1 << (pin_ptr->pin));
                break;
            default:
                locall_err = Unvalid_Port;
                break;
            }
        }
    }

    else
    {
        locall_err = NULL_POINTER;
    }
    return locall_err;
}

Error_state GPIO_setPortDirection(GPIO_port_t *port_ptr, port_dicrection_t direction)
{
    Error_state locall_err = Unvalid_Port;
    if (NULL != port_ptr)
    {
        switch (port_ptr->port)
        {
        case PORTA:
            DDRA_Ptr = direction;
            locall_err = Valid_Port;
            break;
        case PORTB:
            DDRB_Ptr = direction;
            locall_err = Valid_Port;
            break;
        case PORTC:
            DDRC_Ptr = direction;
            locall_err = Valid_Port;
            break;
        case PORTD:
            DDRD_Ptr = direction;
            locall_err = Valid_Port;
            break;
        default:
            break;
        }
    }
    else
    {
        locall_err = NULL_POINTER;
    }

    return locall_err;
}

Error_state GPIO_setPindDirection(GPIO_pin_t *pin_ptr, pin_direction_t direction)
{
    Error_state locall_err = Unvalid_Port;
    if (NULL != pin_ptr)
    {
        if (direction == Output_pin_direction)
        {
            switch (pin_ptr->port)
            {
            case PORTA:
                DDRA_Ptr |= (1 << (pin_ptr->pin));
                locall_err = Valid_Port;
                break;
            case PORTB:
                locall_err = Valid_Port;
                DDRB_Ptr |= (1 << (pin_ptr->pin));
                break;
            case PORTC:
                locall_err = Valid_Port;
                DDRC_Ptr |= (1 << (pin_ptr->pin));
                break;
            case PORTD:
                locall_err = Valid_Port;
                DDRD_Ptr |= (1 << (pin_ptr->pin));
                break;
            default:
                locall_err = Unvalid_Port;
                break;
            }
        }
        else if (direction == Input_pin_direction)
        {
            switch (pin_ptr->port)
            {
            case PORTA:
                DDRA_Ptr &= ~(1 << (pin_ptr->pin));
                locall_err = Valid_Port;
                break;
            case PORTB:
                locall_err = Valid_Port;
                DDRB_Ptr &= ~(1 << (pin_ptr->pin));
                break;
            case PORTC:
                locall_err = Valid_Port;
                DDRC_Ptr &= ~(1 << (pin_ptr->pin));
                break;
            case PORTD:
                locall_err = Valid_Port;
                DDRD_Ptr &= ~(1 << (pin_ptr->pin));
                break;
            default:
                locall_err = Unvalid_Port;
                break;
            }
        }
    }

    else
    {
        locall_err = NULL_POINTER;
    }
    return locall_err;
}

Error_state GPIO_getPortValue(GPIO_port_t *port_ptr, u8 *val)
{
    Error_state locall_err = Unvalid_Port;
    if (NULL != port_ptr)
    {
        switch (port_ptr->port)
        {
        case PORTA:
            *val = PINA_Ptr;
            locall_err = Valid_Port;
            break;
        case PORTB:
            *val = PINB_Ptr;
            locall_err = Valid_Port;
            break;
        case PORTC:
            *val = PINC_Ptr;
            locall_err = Valid_Port;
            break;
        case PORTD:
            *val = PIND_Ptr;
            locall_err = Valid_Port;
            break;
        default:
            break;
        }
    }
    else
    {
        locall_err = NULL_POINTER;
    }

    return locall_err;
}

Error_state GPIO_getPIN(GPIO_pin_t *pin_ptr, pin_state_t *val)
{
    Error_state locall_err = Unvalid_Port;
    if (NULL != pin_ptr)
    {

        switch (pin_ptr->port)
        {
        case PORTA:
            *val = (PINA_Ptr >> (pin_ptr->pin)) & 1;
            locall_err = Valid_Port;
            break;
        case PORTB:
            locall_err = Valid_Port;
            *val = (PINB_Ptr >> (pin_ptr->pin)) & 1;
            break;
        case PORTC:
            locall_err = Valid_Port;
            *val = (PINC_Ptr >> (pin_ptr->pin)) & 1;
            break;
        case PORTD:
            locall_err = Valid_Port;
            *val = (PIND_Ptr >> (pin_ptr->pin)) & 1;
            break;
        default:
            locall_err = Unvalid_Port;
            break;
        }
    }

    else
    {
        locall_err = NULL_POINTER;
    }
    return locall_err;
}

Error_state GPIO_setPin_PUll_UP(GPIO_pin_t *pin_ptr)
{
    Error_state locall_err = Unvalid_Port;
    if (NULL != pin_ptr)
    {
        locall_err = GPIO_setPindDirection(pin_ptr, Input_pin_direction);
        locall_err = GPIO_setPinValue(pin_ptr, high_value);
    }

    else
    {
        locall_err = NULL_POINTER;
    }
    return locall_err;
}
