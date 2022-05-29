#include "hwinit.h"
#include "hw.h"
#include "hardware/vreg.h"
#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "hardware/i2c.h"
#include "hardware/adc.h"

void hw_init()
{
    // Core voltage
    //vreg_set_voltage(VREG_VOLTAGE_1_10); // default, not work.
    //vreg_set_voltage(VREG_VOLTAGE_1_15); // not work.
    //vreg_set_voltage(VREG_VOLTAGE_1_20); // not work.
    vreg_set_voltage(VREG_VOLTAGE_1_25); // good!
    sleep_ms(10);

    // System clock
    set_sys_clock_khz(300000, true);    // 300MHz

    // PC
    gpio_init(DEF_PINNUM_PC0);
    gpio_set_dir(DEF_PINNUM_PC0, GPIO_OUT);
    gpio_init(DEF_PINNUM_PC1);
    gpio_set_dir(DEF_PINNUM_PC1, GPIO_OUT);
    gpio_init(DEF_PINNUM_PC2);
    gpio_set_dir(DEF_PINNUM_PC2, GPIO_IN);
    gpio_init(DEF_PINNUM_PC3);
    gpio_set_dir(DEF_PINNUM_PC3, GPIO_IN);

    // SFP
    gpio_init(DEF_PINNUM_SFP_RX);
    gpio_set_dir(DEF_PINNUM_SFP_RX, GPIO_IN);
    gpio_init(DEF_PINNUM_SFP_TX);
    gpio_set_dir(DEF_PINNUM_SFP_TX, GPIO_OUT);
    gpio_init(DEF_PINNUM_SFP_TX_FAULT);
    gpio_set_dir(DEF_PINNUM_SFP_TX_FAULT, GPIO_IN);
    gpio_init(DEF_PINNUM_SFP_RX_LOS);
    gpio_set_dir(DEF_PINNUM_SFP_RX_LOS, GPIO_IN);

    i2c_init(i2c_default, 100 * 1000);
    gpio_set_function(DEF_PINNUM_SFP_SDA, GPIO_FUNC_I2C);
    gpio_set_function(DEF_PINNUM_SFP_SCL, GPIO_FUNC_I2C);
    gpio_pull_up(DEF_PINNUM_SFP_SDA);
    gpio_pull_up(DEF_PINNUM_SFP_SCL);

    // ADC
    gpio_init(DEF_PINNUM_AD1_SCK);
    gpio_set_dir(DEF_PINNUM_AD1_SCK, GPIO_OUT);
    gpio_init(DEF_PINNUM_AD1_SDO);
    gpio_set_dir(DEF_PINNUM_AD1_SDO, GPIO_IN);
    gpio_init(DEF_PINNUM_AD1_CONV);
    gpio_set_dir(DEF_PINNUM_AD1_CONV, GPIO_OUT);

    gpio_init(DEF_PINNUM_AD2_SCK);
    gpio_set_dir(DEF_PINNUM_AD2_SCK, GPIO_OUT);
    gpio_init(DEF_PINNUM_AD2_SDO);
    gpio_set_dir(DEF_PINNUM_AD2_SDO, GPIO_IN);
    gpio_init(DEF_PINNUM_AD2_CONV);
    gpio_set_dir(DEF_PINNUM_AD2_CONV, GPIO_OUT);

    gpio_init(DEF_PINNUM_AD3_SCK);
    gpio_set_dir(DEF_PINNUM_AD3_SCK, GPIO_OUT);
    gpio_init(DEF_PINNUM_AD3_SDO);
    gpio_set_dir(DEF_PINNUM_AD3_SDO, GPIO_IN);
    gpio_init(DEF_PINNUM_AD3_CONV);
    gpio_set_dir(DEF_PINNUM_AD3_CONV, GPIO_OUT);

    // LED
    gpio_init(DEF_PINNUM_LED0);
    gpio_set_dir(DEF_PINNUM_LED0, GPIO_OUT);
    gpio_init(DEF_PINNUM_LED1);
    gpio_set_dir(DEF_PINNUM_LED1, GPIO_OUT);
    gpio_init(DEF_PINNUM_LED2);
    gpio_set_dir(DEF_PINNUM_LED2, GPIO_OUT);

    // SW
    gpio_init(DEF_PINNUM_SW0);
    gpio_set_dir(DEF_PINNUM_SW0, GPIO_IN);

    // GPIO
    gpio_init(DEF_PINNUM_GPIO20);                   // TODO
    gpio_set_dir(DEF_PINNUM_GPIO20, GPIO_OUT);      // TODO
    gpio_init(DEF_PINNUM_GPIO21);                   // TODO
    gpio_set_dir(DEF_PINNUM_GPIO21, GPIO_OUT);      // TODO

    // Battery voltage monitor
    adc_init();
    // Make sure GPIO is high-impedance, no pullups etc
    adc_gpio_init(DEF_PINNUM_VBAT_MONI);
    // Select ADC input 0 (DEF_PINNUM_VBAT_MONI)
    adc_select_input(0);

}
