#include "SPI.h"
void SPI_Master_Init()
{
    /* Enable SPI, Master, set clock rate fck/16 */
    SPCR |= (1 << MSTR) | (1 << SPE) | (1 << SPR0);
    SPCR &= ~(1 << SPR1);
    /* Disable speed doubler */
    SPSR &= ~(1 << SPI2X);
    /* Set MOSI and SCK output, all others input */
    DDRB_Ptr |= (1 << MOSI) | (1 << SCK);
    DDRB_Ptr &= ~(1 << MISO);
}

void SPI_Slave_Init()
{
    /*Enable Slave*/
    SPCR &= ~(1 << MSTR);
    /*Enable SPI*/
    SPCR |= (1 << SPE);
    /*Set MOSI and SCK input*/
    DDRB_Ptr &= ~(1 << MOSI);
    DDRA_Ptr &= ~(1 << SCK);
    /*Set MISO output*/
    DDRB_Ptr |= (1 << MISO);
}

void SPI_MasterTransmit(char cData)
{
    /* Start transmission */
    SPDR = cData;
    /* Wait for transmission complete */
    while (!(SPSR & (1 << SPIF)))
        ;
}

char SPI_SlaveReceive(void)
{
    /* Wait for reception complete */
    while (!(SPSR & (1 << SPIF)));
    /* Return data register */
    return SPDR;
}