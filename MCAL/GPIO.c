#include "GPIO.h"

void GPIO_setPortValue(u8 portId, u8 value)
{
    if ((PORTA != portId) && (PORTB != portId) && (PORTC != portId) && (PORTD != portId))
    {
        printf("WRONG ID!");
    }
    else
    {
        switch (portId)
        {
        case PORTA:
            PORTA_Ptr = value;
            printf("0x%x in PortAs", value);
            printf("Value assigned to PORTA_Ptr: 0x%x\n", PORTA_Ptr);
            break;
        case PORTB:
            PORTB_Ptr = value;
            printf("0x%x in PortBs", value);
            printf("Value assigned to PORTA_Ptr: 0x%x\n", PORTA_Ptr);
            break;
        case PORTC:
            PORTC_Ptr = value;
            printf("0x%x in PortCs", value);
            printf("Value assigned to PORTA_Ptr: 0x%x\n", PORTC_Ptr);
            break;
        case PORTD:
            PORTD_Ptr = value;
            printf("0x%x in PortD", value);
            printf("Value assigned to PORTA_Ptr: 0x%x\n", PORTA_Ptr);
            break;

        default:
            break;
        }
    }
}

void GPIO_setPinValue(u8 portId, u8 PinId, u8 value)
{
    if ((PORTA != portId) && (PORTB != portId) && (PORTC != portId) && (PORTD != portId))
    {
        printf("WRONG ID!");
    }
    else
    {
        if (value == high_value)
        {
            switch (portId)
            {
            case PORTA:
                PORTA_Ptr = PORTA_Ptr | (value << PinId);
                break;
            case PORTB:
                PORTB_Ptr = PORTB_Ptr | (value << PinId);
                break;
            case PORTC:
                PORTC_Ptr = PORTC_Ptr | (value << PinId);
                break;
            case PORTD:
                PORTD_Ptr = PORTD_Ptr | (value << PinId);
                break;
            default:
                PORTA_Ptr = PORTA_Ptr | 0x00;
                PORTA_Ptr = PORTA_Ptr | 0x00;
                PORTA_Ptr = PORTA_Ptr | 0x00;
                PORTD_Ptr = PORTD_Ptr | 0x00;
                break;
            }
        }
        else if (value == low_value)
        {
            switch (portId)
            {
            case PORTA:
                printf("%i", value);
                PORTA_Ptr = PORTA_Ptr & ~(1 << PinId);
                break;
            case PORTB:
                PORTB_Ptr = PORTB_Ptr & ~(1 << PinId);
                break;
            case PORTC:
                PORTC_Ptr = PORTC_Ptr & ~(1 << PinId);
                break;
            case PORTD:
                PORTD_Ptr = PORTD_Ptr & ~(1 << PinId);
                break;
            default:
                PORTA_Ptr = PORTA_Ptr | 0x00;
                PORTA_Ptr = PORTA_Ptr | 0x00;
                PORTA_Ptr = PORTA_Ptr | 0x00;
                PORTD_Ptr = PORTD_Ptr | 0x00;
                break;
            }
        }
        else
        {
            printf("can not assign 0%x to the pin", value);
        }
    }
}

void GPIO_setPortDirection(u8 portId, u8 PortDirectionValue)
{
    if ((PORTA != portId) && (PORTB != portId) && (PORTC != portId) && (PORTD != portId))
    {
        printf("WRONG ID!");
    }
    else
    {
        switch (portId)
        {
        case PORTA:
            DDRA_Ptr = PortDirectionValue;
            printf("Direction 0x%x in PortAs", PortDirectionValue);
            printf("Value assigned to PORTA_Ptr: 0x%x\n", DDRA_Ptr);
            break;
        case PORTB:
            DDRB_Ptr = PortDirectionValue;
            printf("0x%x in PortB", PortDirectionValue);
            printf("Value assigned to PORTA_Ptr: 0x%x\n", DDRB_Ptr);
            break;
        case PORTC:
            DDRC_Ptr = PortDirectionValue;
            printf("0x%x in PortC", PortDirectionValue);
            printf("Value assigned to PORTA_Ptr: 0x%x\n", DDRC_Ptr);
            break;
        case PORTD:
            DDRD_Ptr = PortDirectionValue;
            printf("0x%x in PortD", PortDirectionValue);
            printf("Value assigned to PORTA_Ptr: 0x%x\n", DDRD_Ptr);
            break;

        default:
            DDRA_Ptr |= (0x00);
            DDRB_Ptr |= (0x00);
            DDRC_Ptr |= (0x00);
            DDRD_Ptr |= (0x00);
            break;
        }
    }
}

void GPIO_setPindDirection(u8 portId, u8 PinId, u8 PintDirectionValue)
{
    if ((PORTA != portId) && (PORTB != portId) && (PORTC != portId) && (PORTD != portId))
    {
        printf("WRONG ID!");
    }
    else
    {
        if (Output_direction == PintDirectionValue)
        {
            switch (portId)
            {
            case PORTA:
                DDRA_Ptr = DDRA_Ptr | (PintDirectionValue << PinId);
                break;
            case PORTB:
                DDRB_Ptr = DDRB_Ptr | (PintDirectionValue << PinId);
                break;
            case PORTC:
                DDRC_Ptr = DDRC_Ptr | (PintDirectionValue << PinId);
                break;
            case PORTD:
                DDRD_Ptr = DDRD_Ptr | (PintDirectionValue << PinId);
                break;
            default:
                DDRA_Ptr |= (0x00);
                DDRB_Ptr |= (0x00);
                DDRC_Ptr |= (0x00);
                DDRD_Ptr |= (0x00);
                break;
            }
        }
        else if (low_value == PintDirectionValue)
        {
            switch (portId)
            {
            case PORTA:

                DDRA_Ptr = DDRA_Ptr & ~(PintDirectionValue << PinId);
                break;
            case PORTB:
                DDRB_Ptr = DDRB_Ptr & ~(PintDirectionValue << PinId);
                break;
            case PORTC:
                DDRC_Ptr = DDRC_Ptr & ~(PintDirectionValue << PinId);
                break;
            case PORTD:
                DDRD_Ptr = DDRD_Ptr & ~(PintDirectionValue << PinId);
                break;
            default:
                DDRA_Ptr |= (0x00);
                DDRB_Ptr |= (0x00);
                DDRC_Ptr |= (0x00);
                DDRD_Ptr |= (0x00);
                break;
            }
        }
        else
        {
            printf("can not assign 0%x to the pin", PintDirectionValue);
        }
    }
}

u8 GPIO_getPortValue(u8 portId)
{
    u8 portValue = NULL;
    if ((PORTA != portId) && (PORTB != portId) && (PORTC != portId) && (PORTD != portId))
    {
        printf("WRONG ID!");
    }
    else
    {
        switch (portId)
        {
        case PORTA:
            portValue = PINA_Ptr;
            break;
        case PORTB:
            portValue = PINB_Ptr;
            break;
        case PORTC:
            portValue = PINC_Ptr;
            break;
        case PORTD:
            portValue = PIND_Ptr;
            break;    
        default:
            break;
        }
    }
    
    return portValue;
}

u8 GPIO_PinValue(u8 portId, u8 PinId)
{
    //1 
    u8 PinValue = NULL;
    if ((PORTA != portId) && (PORTB != portId) && (PORTC != portId) && (PORTD != portId))
    {
        printf("WRONG ID!");
    }
    else
    {
        switch (portId)
        {
        case PORTA:
            PinValue = (PINA_Ptr>>PinId) &1;
            break;
        case PORTB:
            PinValue = (PINB_Ptr>>PinId) &1;
            break;
        case PORTC:
            PinValue = (PINC_Ptr>>PinId) &1;
            break;
        case PORTD:
            PinValue = (PIND_Ptr>>PinId) &1;
            break;
        default:
            break;
        }
    }
    return PinValue;
}
