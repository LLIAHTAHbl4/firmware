#ifndef _VARIANT_PROMICRO_DIY_
#define _VARIANT_PROMICRO_DIY_

/** Master clock frequency */
#define VARIANT_MCK (64000000ul)

// #define USE_LFXO // Board uses 32khz crystal for LF
#define USE_LFRC // Board uses RC for LF

#define PROMICRO_DIY_TCXO

/*----------------------------------------------------------------------------
 *        Headers
 *----------------------------------------------------------------------------*/

#include "WVariant.h"

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

/*
NRF52 PRO MICRO PIN ASSIGNMENT

| Pin   | Function    |     | Pin      | Function     | RF95  |
| ----- | ----------- | --- | -------- | ------------ | ----- |
| Gnd   |             |     | vbat     |              |       |
| P0.06 | Serial2 RX  |     | vbat     |              |       |
| P0.08 | Serial2 TX  |     | Gnd      |              |       |
| Gnd   |             |     | reset    |              |       |
| Gnd   |             |     | ext_vcc  | *see 0.13    |       |
| P0.17 | RXEN        |     | P0.31    | BATTERY_PIN  |       |
| P0.20 | GPS_TX      |     | P0.29    | BUSY         | DIO0  |
| P0.22 | GPS_RX      |     | P0.02    | MISO         | MISO  |
| P0.24 | GPS_EN      |     | P1.15    | MOSI         | MOSI  |
| P1.00 | BUTTON_PIN  |     | P1.13    | CS           | CS    |
| P0.11 | SCL         |     | P1.11    | SCK          | SCK   |
| P1.04 | SDA         |     | P0.10    | DIO1/IRQ     | DIO1  |
| P1.06 | Free pin    |     | P0.09    | RESET        | RST   |
|       |             |     |          |              |       |
|       | Mid board   |     |          | Internal     |       |
| P1.01 | Free pin    |     | 0.15     | LED          |       |
| P1.02 | Free pin    |     | 0.13     | 3V3_EN       |       |
| P1.07 | Free pin    |     |          |              |       |
*/

// Number of pins defined in PinDescription array
#define PINS_COUNT (48)
#define NUM_DIGITAL_PINS (48)
#define NUM_ANALOG_INPUTS (1)
#define NUM_ANALOG_OUTPUTS (0)

// Pin 13 enables 3.3V periphery. If the Lora module is on this pin, then it should stay enabled at all times.
#define PIN_3V3_EN (0 + 13) // P0.13

// Analog pins
#define BATTERY_PIN (0 + 31) // P0.31 Battery ADC
#define ADC_CHANNEL ADC1_GPIO4_CHANNEL
#define ADC_RESOLUTION 14
#define BATTERY_SENSE_RESOLUTION_BITS 12
#define BATTERY_SENSE_RESOLUTION 4096.0
#define VBAT_MV_PER_LSB (0.73242188F)
#define VBAT_DIVIDER (0.6F)
#define VBAT_DIVIDER_COMP (1.73)
#define REAL_VBAT_MV_PER_LSB (VBAT_DIVIDER_COMP * VBAT_MV_PER_LSB)
#undef AREF_VOLTAGE
#define AREF_VOLTAGE 3.0
#define VBAT_AR_INTERNAL AR_INTERNAL_3_0
#define ADC_MULTIPLIER VBAT_DIVIDER_COMP
#define VBAT_RAW_TO_SCALED(x) (REAL_VBAT_MV_PER_LSB * x)

// WIRE IC AND IIC PINS
#define WIRE_INTERFACES_COUNT 1
#define PIN_WIRE_SDA (32 + 4) // P1.04
#define PIN_WIRE_SCL (0 + 11) // P0.11

// LED
#define PIN_LED1 (0 + 15) // P0.15
#define LED_BUILTIN PIN_LED1
#define LED_BLUE PIN_LED1
#define LED_STATE_ON 1

// Button
#define BUTTON_PIN (32 + 0) // P1.00

// GPS
#define GPS_TX_PIN (0 + 20) // P0.20
#define GPS_RX_PIN (0 + 22) // P0.22
#define PIN_GPS_EN (0 + 24) // P0.24
#define GPS_UBLOX

// UART interfaces
#define PIN_SERIAL1_TX GPS_TX_PIN
#define PIN_SERIAL1_RX GPS_RX_PIN
#define PIN_SERIAL2_RX (0 + 6) // P0.06
#define PIN_SERIAL2_TX (0 + 8) // P0.08

// Serial interfaces
#define SPI_INTERFACES_COUNT 1
#define PIN_SPI_MISO (0 + 2)   // P0.02
#define PIN_SPI_MOSI (32 + 15) // P1.15
#define PIN_SPI_SCK  (32 + 11) // P1.11

// ----------------- LoRa module pins (исправленные) -----------------
#define LORA_MISO PIN_SPI_MISO
#define LORA_MOSI PIN_SPI_MOSI
#define LORA_SCK  PIN_SPI_SCK
#define LORA_CS   (32 + 13) // P1.13
#define LORA_RESET (0 + 9)  // P0.09
#define LORA_DIO0 (0 + 29)  // P0.29 BUSY
#define LORA_DIO1 (0 + 10)  // P0.10 IRQ
#define RF95_RXEN RADIOLIB_NC
#define RF95_TXEN RADIOLIB_NC
#define SX126X_CS    LORA_CS
#define SX126X_BUSY  LORA_DIO0
#define SX126X_RESET LORA_RESET
#define SX126X_DIO1  LORA_DIO1
#define SX126X_TXEN  RADIOLIB_NC
// -------------------------------------------------------------------

#define USE_LLCC68
#define USE_SX1262
#define USE_RF95
#define USE_SX1268
#define USE_LR1121

// LR1121
#ifdef USE_LR1121
#define LR1121_IRQ_PIN (0 + 10)
#define LR1121_NRESET_PIN LORA_RESET
#define LR1121_BUSY_PIN (0 + 29)
#define LR1121_SPI_NSS_PIN LORA_CS
#define LR1121_SPI_SCK_PIN LORA_SCK
#define LR1121_SPI_MOSI_PIN LORA_MOSI
#define LR1121_SPI_MISO_PIN LORA_MISO
#define LR11X0_DIO3_TCXO_VOLTAGE 1.8
#define LR11X0_DIO_AS_RF_SWITCH
#endif

#define SX126X_DIO3_TCXO_VOLTAGE 1.8
#define TCXO_OPTIONAL

// E-Ink DIY
#define PIN_EINK_CS   (32 + 7)
#define PIN_EINK_DC   (32 + 2)
#define PIN_EINK_RES  (32 + 1)
#define PIN_EINK_BUSY (32 + 6)

#ifdef __cplusplus
}
#endif

#endi
