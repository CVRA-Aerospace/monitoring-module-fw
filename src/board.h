/*
    ChibiOS - Copyright (C) 2006..2015 Giovanni Di Sirio

    Licensed under the Apache License, Version 2.0 (the "License");
    you may not use this file except in compliance with the License.
    You may obtain a copy of the License at

        http://www.apache.org/licenses/LICENSE-2.0

    Unless required by applicable law or agreed to in writing, software
    distributed under the License is distributed on an "AS IS" BASIS,
    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
    See the License for the specific language governing permissions and
    limitations under the License.
*/

#ifndef _BOARD_H_
#define _BOARD_H_

/*
 * Board identifier.
 */
#define BOARD_F0
#define BOARD_NAME                  "Monitoring module RevA"

/*
 * Board oscillators-related settings.
 * NOTE: LSE not fitted.
 * NOTE: HSE not fitted.
 */
#if !defined(STM32_LSECLK)
#define STM32_LSECLK                0
#endif

#define STM32_LSEDRV                (3 << 3)

#define STM32_HSECLK                16000000

/*
 * MCU type as defined in the ST header.
 */
#define STM32F042x6

/*
 * IO pins assignments.
 */
#define GPIOA_NC_0                  0
#define GPIOA_V_BAT_MON_AD          1
#define GPIOA_EXP1                  2
#define GPIOA_EXP2                  3
#define GPIOA_EXP3                  4
#define GPIOA_EXP4                  5
#define GPIOA_EXP5                  6
#define GPIOA_EXP6                  7
#define GPIOA_HEARTBEAT_LED         8
#define GPIOA_UART1_TX              9
#define GPIOA_UART1_RX              10
#define GPIOA_NC_11                 11
#define GPIOA_NC_12                 12
#define GPIOA_SWDIO                 13
#define GPIOA_SWCLK                 14
#define GPIOA_ERROR_LED             15

#define GPIOB_NC_0                  0
#define GPIOB_H3LIS331DL_INT1       1
#define GPIOB_MPU6000_INT           2
#define GPIOB_SD_DETECT             3
#define GPIOB_NC_4                  4
#define GPIOB_NC_5                  5
#define GPIOB_I2C1_SCL              6
#define GPIOB_I2C1_SDA              7
#define GPIOB_NC_8                  8
#define GPIOB_NC_9                  9
#define GPIOB_NC_10                 10
#define GPIOB_NC_11                 11
#define GPIOB_SD_CS                 12
#define GPIOB_SD_SCK                13
#define GPIOB_SD_MISO               14
#define GPIOB_SD_MOSI               15

#define GPIOC_NC_13                 13
#define GPIOC_NC_14                 14
#define GPIOC_NC_15                 15

#define GPIOF_OSC_IN                0
#define GPIOF_OSC_OUT               1

/*
 * I/O ports initial setup, this configuration is established soon after reset
 * in the initialization code.
 * Please refer to the STM32 Reference Manual for details.
 */
#define PIN_MODE_INPUT(n)           (0U << ((n) * 2))
#define PIN_MODE_OUTPUT(n)          (1U << ((n) * 2))
#define PIN_MODE_ALTERNATE(n)       (2U << ((n) * 2))
#define PIN_MODE_ANALOG(n)          (3U << ((n) * 2))
#define PIN_ODR_LOW(n)              (0U << (n))
#define PIN_ODR_HIGH(n)             (1U << (n))
#define PIN_OTYPE_PUSHPULL(n)       (0U << (n))
#define PIN_OTYPE_OPENDRAIN(n)      (1U << (n))
#define PIN_OSPEED_2M(n)            (0U << ((n) * 2))
#define PIN_OSPEED_10M(n)           (1U << ((n) * 2))
#define PIN_OSPEED_40M(n)           (3U << ((n) * 2))
#define PIN_PUPDR_FLOATING(n)       (0U << ((n) * 2))
#define PIN_PUPDR_PULLUP(n)         (1U << ((n) * 2))
#define PIN_PUPDR_PULLDOWN(n)       (2U << ((n) * 2))
#define PIN_AFIO_AF(n, v)           ((v##U) << (((n) % 8) * 4))

/*
 * GPIOA setup:
 *
 * GPIOA_NC_0                       (input pulldown).
 * GPIOA_V_BAT_MON_AD               (analog).
 * GPIOA_EXP1                       (input pulldown).
 * GPIOA_EXP2                       (input pulldown).
 * GPIOA_EXP3                       (input pulldown).
 * GPIOA_EXP4                       (input pulldown).
 * GPIOA_EXP5                       (input pulldown).
 * GPIOA_EXP6                       (input pulldown).
 * GPIOA_HEARTBEAT_LED              (output low).
 * GPIOA_UART1_TX                   (alternate 1).
 * GPIOA_UART1_RX                   (alternate 1).
 * GPIOA_NC_11                      (input pulldown).
 * GPIOA_NC_12                      (input pulldown).
 * GPIOA_SWDIO                      (alternate 0).
 * GPIOA_SWCLK                      (alternate 0).
 * GPIOA_ERROR_LED                  (output low).
 */
#define VAL_GPIOA_MODER             (PIN_MODE_INPUT(GPIOA_NC_0) | \
                                     PIN_MODE_ANALOG(GPIOA_V_BAT_MON_AD) | \
                                     PIN_MODE_INPUT(GPIOA_EXP1) | \
                                     PIN_MODE_INPUT(GPIOA_EXP2) | \
                                     PIN_MODE_INPUT(GPIOA_EXP3) | \
                                     PIN_MODE_INPUT(GPIOA_EXP4) | \
                                     PIN_MODE_INPUT(GPIOA_EXP5) | \
                                     PIN_MODE_INPUT(GPIOA_EXP6) | \
                                     PIN_MODE_OUTPUT(GPIOA_HEARTBEAT_LED) | \
                                     PIN_MODE_ALTERNATE(GPIOA_UART1_TX) | \
                                     PIN_MODE_ALTERNATE(GPIOA_UART1_RX) | \
                                     PIN_MODE_INPUT(GPIOA_NC_11) | \
                                     PIN_MODE_INPUT(GPIOA_NC_12) | \
                                     PIN_MODE_ALTERNATE(GPIOA_SWDIO) | \
                                     PIN_MODE_ALTERNATE(GPIOA_SWCLK) | \
                                     PIN_MODE_OUTPUT(GPIOA_ERROR_LED))
#define VAL_GPIOA_OTYPER            (PIN_OTYPE_PUSHPULL(GPIOA_NC_0) | \
                                     PIN_OTYPE_PUSHPULL(GPIOA_V_BAT_MON_AD) | \
                                     PIN_OTYPE_PUSHPULL(GPIOA_EXP1) | \
                                     PIN_OTYPE_PUSHPULL(GPIOA_EXP2) | \
                                     PIN_OTYPE_PUSHPULL(GPIOA_EXP3) | \
                                     PIN_OTYPE_PUSHPULL(GPIOA_EXP4) | \
                                     PIN_OTYPE_PUSHPULL(GPIOA_EXP5) | \
                                     PIN_OTYPE_PUSHPULL(GPIOA_EXP6) | \
                                     PIN_OTYPE_PUSHPULL(GPIOA_HEARTBEAT_LED) | \
                                     PIN_OTYPE_PUSHPULL(GPIOA_UART1_TX) | \
                                     PIN_OTYPE_PUSHPULL(GPIOA_UART1_RX) | \
                                     PIN_OTYPE_PUSHPULL(GPIOA_NC_11) | \
                                     PIN_OTYPE_PUSHPULL(GPIOA_NC_12) | \
                                     PIN_OTYPE_PUSHPULL(GPIOA_SWDIO) | \
                                     PIN_OTYPE_PUSHPULL(GPIOA_SWCLK) | \
                                     PIN_OTYPE_PUSHPULL(GPIOA_ERROR_LED))
#define VAL_GPIOA_OSPEEDR           (PIN_OSPEED_40M(GPIOA_NC_0) | \
                                     PIN_OSPEED_40M(GPIOA_V_BAT_MON_AD) | \
                                     PIN_OSPEED_40M(GPIOA_EXP1) | \
                                     PIN_OSPEED_40M(GPIOA_EXP2) | \
                                     PIN_OSPEED_40M(GPIOA_EXP3) | \
                                     PIN_OSPEED_40M(GPIOA_EXP4) | \
                                     PIN_OSPEED_40M(GPIOA_EXP5) | \
                                     PIN_OSPEED_40M(GPIOA_EXP6) | \
                                     PIN_OSPEED_40M(GPIOA_HEARTBEAT_LED) | \
                                     PIN_OSPEED_40M(GPIOA_UART1_TX) | \
                                     PIN_OSPEED_40M(GPIOA_UART1_RX) | \
                                     PIN_OSPEED_40M(GPIOA_NC_11) | \
                                     PIN_OSPEED_40M(GPIOA_NC_12) | \
                                     PIN_OSPEED_40M(GPIOA_SWDIO) | \
                                     PIN_OSPEED_40M(GPIOA_SWCLK) | \
                                     PIN_OSPEED_40M(GPIOA_ERROR_LED))
#define VAL_GPIOA_PUPDR             (PIN_PUPDR_PULLDOWN(GPIOA_NC_0) | \
                                     PIN_PUPDR_FLOATING(GPIOA_V_BAT_MON_AD) | \
                                     PIN_PUPDR_PULLDOWN(GPIOA_EXP1) | \
                                     PIN_PUPDR_PULLDOWN(GPIOA_EXP2) | \
                                     PIN_PUPDR_PULLDOWN(GPIOA_EXP3) | \
                                     PIN_PUPDR_PULLDOWN(GPIOA_EXP4) | \
                                     PIN_PUPDR_PULLDOWN(GPIOA_EXP5) | \
                                     PIN_PUPDR_PULLDOWN(GPIOA_EXP6) | \
                                     PIN_PUPDR_FLOATING(GPIOA_HEARTBEAT_LED) | \
                                     PIN_PUPDR_FLOATING(GPIOA_UART1_TX) | \
                                     PIN_PUPDR_PULLUP(GPIOA_UART1_RX) | \
                                     PIN_PUPDR_PULLDOWN(GPIOA_NC_11) | \
                                     PIN_PUPDR_PULLDOWN(GPIOA_NC_12) | \
                                     PIN_PUPDR_PULLUP(GPIOA_SWDIO) | \
                                     PIN_PUPDR_PULLDOWN(GPIOA_SWCLK) | \
                                     PIN_PUPDR_FLOATING(GPIOA_ERROR_LED))
#define VAL_GPIOA_ODR               (PIN_ODR_LOW(GPIOA_NC_0) | \
                                     PIN_ODR_LOW(GPIOA_V_BAT_MON_AD) | \
                                     PIN_ODR_LOW(GPIOA_EXP1) | \
                                     PIN_ODR_LOW(GPIOA_EXP2) | \
                                     PIN_ODR_LOW(GPIOA_EXP3) | \
                                     PIN_ODR_LOW(GPIOA_EXP4) | \
                                     PIN_ODR_LOW(GPIOA_EXP5) | \
                                     PIN_ODR_LOW(GPIOA_EXP6) | \
                                     PIN_ODR_LOW(GPIOA_HEARTBEAT_LED) | \
                                     PIN_ODR_LOW(GPIOA_UART1_TX) | \
                                     PIN_ODR_LOW(GPIOA_UART1_RX) | \
                                     PIN_ODR_LOW(GPIOA_NC_11) | \
                                     PIN_ODR_LOW(GPIOA_NC_12) | \
                                     PIN_ODR_LOW(GPIOA_SWDIO) | \
                                     PIN_ODR_LOW(GPIOA_SWCLK) | \
                                     PIN_ODR_LOW(GPIOA_ERROR_LED))
#define VAL_GPIOA_AFRL              (PIN_AFIO_AF(GPIOA_NC_0, 0) | \
                                     PIN_AFIO_AF(GPIOA_V_BAT_MON_AD, 0) | \
                                     PIN_AFIO_AF(GPIOA_EXP1, 0) | \
                                     PIN_AFIO_AF(GPIOA_EXP2, 0) | \
                                     PIN_AFIO_AF(GPIOA_EXP3, 0) | \
                                     PIN_AFIO_AF(GPIOA_EXP4, 0) | \
                                     PIN_AFIO_AF(GPIOA_EXP5, 0) | \
                                     PIN_AFIO_AF(GPIOA_EXP6, 0))
#define VAL_GPIOA_AFRH              (PIN_AFIO_AF(GPIOA_HEARTBEAT_LED, 0) | \
                                     PIN_AFIO_AF(GPIOA_UART1_TX, 1) | \
                                     PIN_AFIO_AF(GPIOA_UART1_RX, 1) | \
                                     PIN_AFIO_AF(GPIOA_NC_11, 0) | \
                                     PIN_AFIO_AF(GPIOA_NC_12, 0) | \
                                     PIN_AFIO_AF(GPIOA_SWDIO, 0) | \
                                     PIN_AFIO_AF(GPIOA_SWCLK, 0) | \
                                     PIN_AFIO_AF(GPIOA_ERROR_LED, 0))

/*
 * GPIOB setup:
 *
 * GPIOB_NC_0                       (input pulldown).
 * GPIOB_H3LIS331DL_INT1            (input floating).
 * GPIOB_MPU6000_INT                (input floating).
 * GPIOB_SD_DETECT                  (input floating).
 * GPIOB_NC_4                       (input pulldown).
 * GPIOB_NC_5                       (input pulldown).
 * GPIOB_I2C1_SCL                   (alternate 1, opendrain).
 * GPIOB_I2C1_SDA                   (alternate 1, opendrain).
 * GPIOB_NC_8                       (input pulldown).
 * GPIOB_NC_9                       (input pulldown).
 * GPIOB_NC_10                      (input pulldown).
 * GPIOB_NC_11                      (input pulldown).
 * GPIOB_SD_CS                      (output high).
 * GPIOB_SD_SCK                     (alternate 0).
 * GPIOB_SD_MISO                    (alternate 0).
 * GPIOB_SD_MOSI                    (alternate 0).
 */
#define VAL_GPIOB_MODER             (PIN_MODE_INPUT(GPIOB_NC_0) | \
                                     PIN_MODE_INPUT(GPIOB_H3LIS331DL_INT1) | \
                                     PIN_MODE_INPUT(GPIOB_MPU6000_INT) | \
                                     PIN_MODE_INPUT(GPIOB_SD_DETECT) | \
                                     PIN_MODE_INPUT(GPIOB_NC_4) | \
                                     PIN_MODE_INPUT(GPIOB_NC_5) | \
                                     PIN_MODE_ALTERNATE(GPIOB_I2C1_SCL) | \
                                     PIN_MODE_ALTERNATE(GPIOB_I2C1_SDA) | \
                                     PIN_MODE_INPUT(GPIOB_NC_8) | \
                                     PIN_MODE_INPUT(GPIOB_NC_9) | \
                                     PIN_MODE_INPUT(GPIOB_NC_10) | \
                                     PIN_MODE_INPUT(GPIOB_NC_11) | \
                                     PIN_MODE_OUTPUT(GPIOB_SD_CS) | \
                                     PIN_MODE_ALTERNATE(GPIOB_SD_SCK) | \
                                     PIN_MODE_ALTERNATE(GPIOB_SD_MISO) | \
                                     PIN_MODE_ALTERNATE(GPIOB_SD_MOSI))
#define VAL_GPIOB_OTYPER            (PIN_OTYPE_PUSHPULL(GPIOB_NC_0) | \
                                     PIN_OTYPE_PUSHPULL(GPIOB_H3LIS331DL_INT1) | \
                                     PIN_OTYPE_PUSHPULL(GPIOB_MPU6000_INT) | \
                                     PIN_OTYPE_PUSHPULL(GPIOB_SD_DETECT) | \
                                     PIN_OTYPE_PUSHPULL(GPIOB_NC_4) | \
                                     PIN_OTYPE_PUSHPULL(GPIOB_NC_5) | \
                                     PIN_OTYPE_OPENDRAIN(GPIOB_I2C1_SCL) | \
                                     PIN_OTYPE_OPENDRAIN(GPIOB_I2C1_SDA) | \
                                     PIN_OTYPE_PUSHPULL(GPIOB_NC_8) | \
                                     PIN_OTYPE_PUSHPULL(GPIOB_NC_9) | \
                                     PIN_OTYPE_PUSHPULL(GPIOB_NC_10) | \
                                     PIN_OTYPE_PUSHPULL(GPIOB_NC_11) | \
                                     PIN_OTYPE_PUSHPULL(GPIOB_SD_CS) | \
                                     PIN_OTYPE_PUSHPULL(GPIOB_SD_SCK) | \
                                     PIN_OTYPE_PUSHPULL(GPIOB_SD_MISO) | \
                                     PIN_OTYPE_PUSHPULL(GPIOB_SD_MOSI))
#define VAL_GPIOB_OSPEEDR           (PIN_OSPEED_40M(GPIOB_NC_0) | \
                                     PIN_OSPEED_40M(GPIOB_H3LIS331DL_INT1) | \
                                     PIN_OSPEED_40M(GPIOB_MPU6000_INT) | \
                                     PIN_OSPEED_40M(GPIOB_SD_DETECT) | \
                                     PIN_OSPEED_40M(GPIOB_NC_4) | \
                                     PIN_OSPEED_40M(GPIOB_NC_5) | \
                                     PIN_OSPEED_40M(GPIOB_I2C1_SCL) | \
                                     PIN_OSPEED_40M(GPIOB_I2C1_SDA) | \
                                     PIN_OSPEED_40M(GPIOB_NC_8) | \
                                     PIN_OSPEED_40M(GPIOB_NC_9) | \
                                     PIN_OSPEED_40M(GPIOB_NC_10) | \
                                     PIN_OSPEED_40M(GPIOB_NC_11) | \
                                     PIN_OSPEED_40M(GPIOB_SD_CS) | \
                                     PIN_OSPEED_40M(GPIOB_SD_SCK) | \
                                     PIN_OSPEED_40M(GPIOB_SD_MISO) | \
                                     PIN_OSPEED_40M(GPIOB_SD_MOSI))
#define VAL_GPIOB_PUPDR             (PIN_PUPDR_PULLDOWN(GPIOB_NC_0) | \
                                     PIN_PUPDR_FLOATING(GPIOB_H3LIS331DL_INT1) | \
                                     PIN_PUPDR_FLOATING(GPIOB_MPU6000_INT) | \
                                     PIN_PUPDR_FLOATING(GPIOB_SD_DETECT) | \
                                     PIN_PUPDR_PULLDOWN(GPIOB_NC_4) | \
                                     PIN_PUPDR_PULLDOWN(GPIOB_NC_5) | \
                                     PIN_PUPDR_FLOATING(GPIOB_I2C1_SCL) | \
                                     PIN_PUPDR_FLOATING(GPIOB_I2C1_SDA) | \
                                     PIN_PUPDR_PULLDOWN(GPIOB_NC_8) | \
                                     PIN_PUPDR_PULLDOWN(GPIOB_NC_9) | \
                                     PIN_PUPDR_PULLDOWN(GPIOB_NC_10) | \
                                     PIN_PUPDR_PULLDOWN(GPIOB_NC_11) | \
                                     PIN_PUPDR_FLOATING(GPIOB_SD_CS) | \
                                     PIN_PUPDR_FLOATING(GPIOB_SD_SCK) | \
                                     PIN_PUPDR_FLOATING(GPIOB_SD_MISO) | \
                                     PIN_PUPDR_FLOATING(GPIOB_SD_MOSI))
#define VAL_GPIOB_ODR               (PIN_ODR_LOW(GPIOB_NC_0) | \
                                     PIN_ODR_LOW(GPIOB_H3LIS331DL_INT1) | \
                                     PIN_ODR_LOW(GPIOB_MPU6000_INT) | \
                                     PIN_ODR_LOW(GPIOB_SD_DETECT) | \
                                     PIN_ODR_LOW(GPIOB_NC_4) | \
                                     PIN_ODR_LOW(GPIOB_NC_5) | \
                                     PIN_ODR_LOW(GPIOB_I2C1_SCL) | \
                                     PIN_ODR_LOW(GPIOB_I2C1_SDA) | \
                                     PIN_ODR_LOW(GPIOB_NC_8) | \
                                     PIN_ODR_LOW(GPIOB_NC_9) | \
                                     PIN_ODR_LOW(GPIOB_NC_10) | \
                                     PIN_ODR_LOW(GPIOB_NC_11) | \
                                     PIN_ODR_HIGH(GPIOB_SD_CS) | \
                                     PIN_ODR_LOW(GPIOB_SD_SCK) | \
                                     PIN_ODR_LOW(GPIOB_SD_MISO) | \
                                     PIN_ODR_LOW(GPIOB_SD_MOSI))
#define VAL_GPIOB_AFRL              (PIN_AFIO_AF(GPIOB_NC_0, 0) | \
                                     PIN_AFIO_AF(GPIOB_H3LIS331DL_INT1, 0) | \
                                     PIN_AFIO_AF(GPIOB_MPU6000_INT, 0) | \
                                     PIN_AFIO_AF(GPIOB_SD_DETECT, 0) | \
                                     PIN_AFIO_AF(GPIOB_NC_4, 0) | \
                                     PIN_AFIO_AF(GPIOB_NC_5, 0) | \
                                     PIN_AFIO_AF(GPIOB_I2C1_SCL, 1) | \
                                     PIN_AFIO_AF(GPIOB_I2C1_SDA, 1))
#define VAL_GPIOB_AFRH              (PIN_AFIO_AF(GPIOB_NC_8, 0) | \
                                     PIN_AFIO_AF(GPIOB_NC_9, 0) | \
                                     PIN_AFIO_AF(GPIOB_NC_10, 0) | \
                                     PIN_AFIO_AF(GPIOB_NC_11, 0) | \
                                     PIN_AFIO_AF(GPIOB_SD_CS, 0) | \
                                     PIN_AFIO_AF(GPIOB_SD_SCK, 0) | \
                                     PIN_AFIO_AF(GPIOB_SD_MISO, 0) | \
                                     PIN_AFIO_AF(GPIOB_SD_MOSI, 0))

/*
 * GPIOC setup:
 *
 * GPIOC_NC_13                      (input pulldown).
 * GPIOC_NC_14                      (input pulldown).
 * GPIOC_NC_15                      (input pulldown).
 */
#define VAL_GPIOC_MODER             (PIN_MODE_INPUT(GPIOC_NC_13) | \
                                     PIN_MODE_INPUT(GPIOC_NC_14) | \
                                     PIN_MODE_INPUT(GPIOC_NC_15))
#define VAL_GPIOC_OTYPER            (PIN_OTYPE_PUSHPULL(GPIOC_NC_13) | \
                                     PIN_OTYPE_PUSHPULL(GPIOC_NC_14) | \
                                     PIN_OTYPE_PUSHPULL(GPIOC_NC_15))
#define VAL_GPIOC_OSPEEDR           (PIN_OSPEED_40M(GPIOC_NC_13) | \
                                     PIN_OSPEED_40M(GPIOC_NC_14) | \
                                     PIN_OSPEED_40M(GPIOC_NC_15))
#define VAL_GPIOC_PUPDR             (PIN_PUPDR_PULLDOWN(GPIOC_NC_13) | \
                                     PIN_PUPDR_PULLDOWN(GPIOC_NC_14) | \
                                     PIN_PUPDR_PULLDOWN(GPIOC_NC_15))
#define VAL_GPIOC_ODR               (PIN_ODR_LOW(GPIOC_NC_13) | \
                                     PIN_ODR_LOW(GPIOC_NC_14) | \
                                     PIN_ODR_LOW(GPIOC_NC_15))
#define VAL_GPIOC_AFRL              0
#define VAL_GPIOC_AFRH              (PIN_AFIO_AF(GPIOC_NC_13, 0) | \
                                     PIN_AFIO_AF(GPIOC_NC_14, 0) | \
                                     PIN_AFIO_AF(GPIOC_NC_15, 0))

/*
 * GPIOD setup:
 */
#define VAL_GPIOD_MODER             0
#define VAL_GPIOD_OTYPER            0
#define VAL_GPIOD_OSPEEDR           0
#define VAL_GPIOD_PUPDR             0
#define VAL_GPIOD_ODR               0
#define VAL_GPIOD_AFRL              0
#define VAL_GPIOD_AFRH              0

/*
 * GPIOF setup:
 *
 * GPIOF_OSC_IN                    (input pulldown).
 * GPIOF_OSC_OUT                   (input pulldown).
 */
#define VAL_GPIOF_MODER             (PIN_MODE_INPUT(GPIOF_OSC_IN) | \
                                     PIN_MODE_INPUT(GPIOF_OSC_OUT))
#define VAL_GPIOF_OTYPER            (PIN_OTYPE_PUSHPULL(GPIOF_OSC_IN) | \
                                     PIN_OTYPE_PUSHPULL(GPIOF_OSC_OUT))
#define VAL_GPIOF_OSPEEDR           (PIN_OSPEED_2M(GPIOF_OSC_IN) | \
                                     PIN_OSPEED_2M(GPIOF_OSC_OUT))
#define VAL_GPIOF_PUPDR             (PIN_PUPDR_PULLDOWN(GPIOF_OSC_IN) | \
                                     PIN_PUPDR_PULLDOWN(GPIOF_OSC_OUT))
#define VAL_GPIOF_ODR               (PIN_ODR_HIGH(GPIOF_OSC_IN) | \
                                     PIN_ODR_HIGH(GPIOF_OSC_OUT))
#define VAL_GPIOF_AFRL              (PIN_AFIO_AF(GPIOF_OSC_IN, 0) | \
                                     PIN_AFIO_AF(GPIOF_OSC_OUT, 0))
#define VAL_GPIOF_AFRH              0


#if !defined(_FROM_ASM_)
#ifdef __cplusplus
extern "C" {
#endif
  void boardInit(void);
#ifdef __cplusplus
}
#endif
#endif /* _FROM_ASM_ */

#endif /* _BOARD_H_ */
