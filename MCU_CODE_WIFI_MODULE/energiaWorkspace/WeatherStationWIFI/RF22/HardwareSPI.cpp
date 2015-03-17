// HardwareSPI.h
// Author: Mike McCauley (mikem@airspayce.com)
// Copyright (C) 2011 Mike McCauley
// Contributed by Joanna Rutkowska
// $Id: HardwareSPI.cpp,v 1.1 2014/04/01 05:06:44 mikem Exp mikem $

#include "HardwareSPI.h"


   HardwareSPIClass::HardwareSPIClass(uint8_t SSIModule):spi(SSIModule){

   }

    uint8_t  HardwareSPIClass::transfer(uint8_t data)
    {
        return spi.transfer(data);
    }


    void  HardwareSPIClass::attachInterrupt()
    {
       // return spi.attachInterrupt(); //NOT SUPPORTED YET
    }


    void  HardwareSPIClass::detachInterrupt()
    {
       // return spi.detachInterrupt(); //NOT SUPPORTED YET
    }


    void HardwareSPIClass::begin()
    {
        return spi.begin();
    }


    void HardwareSPIClass::end()
    {
        return spi.end();
    }


    void HardwareSPIClass::setBitOrder(uint8_t bitOrder)
    {
    	spi.setBitOrder (bitOrder);
    }

    /// Sets the SPI data mode: that is, clock polarity and phase.
    /// See the Wikipedia article on SPI for details.
    /// \param[in] mode The mode to use: SPI_MODE0 SPI_MODE1 SPI_MODE2 SPI_MODE3
    void HardwareSPIClass::setDataMode(uint8_t mode)
    {
    	spi.setDataMode (mode);
    }

    void HardwareSPIClass::setClockDivider(uint8_t rate)
    {
    	spi.setClockDivider (rate);
    }

// Declare a single instance of the hardware SPI interface class
#define DefaultSSIModuleForRFM23BModule 3
    //This is SSI3 module , on PortD , pins:  {GPIO_PD0_SSI3CLK, GPIO_PD1_SSI3FSS, GPIO_PD2_SSI3RX, GPIO_PD3_SSI3TX}
HardwareSPIClass Hardware_spi(DefaultSSIModuleForRFM23BModule);