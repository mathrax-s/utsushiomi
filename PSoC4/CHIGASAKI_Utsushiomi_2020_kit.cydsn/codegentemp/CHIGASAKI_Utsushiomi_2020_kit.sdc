# THIS FILE IS AUTOMATICALLY GENERATED
# Project: C:\Users\SHOZO\Documents\GitHub\utsushiomi\PSoC4\CHIGASAKI_Utsushiomi_2020_kit.cydsn\CHIGASAKI_Utsushiomi_2020_kit.cyprj
# Date: Sun, 11 Oct 2020 10:09:05 GMT
#set_units -time ns
create_clock -name {CapSense_CSD_SampleClk(FFB)} -period 10625 -waveform {0 5312.5} [list [get_pins {ClockBlock/ff_div_6}]]
create_clock -name {CapSense_CSD_SenseClk(FFB)} -period 10625 -waveform {0 5312.5} [list [get_pins {ClockBlock/ff_div_5}]]
create_clock -name {Clock_PWM(FFB)} -period 83.333333333333329 -waveform {0 41.6666666666667} [list [get_pins {ClockBlock/ff_div_8}]]
create_clock -name {UART_1_SCBCLK(FFB)} -period 1083.3333333333333 -waveform {0 541.666666666667} [list [get_pins {ClockBlock/ff_div_2}]]
create_clock -name {CyRouted1} -period 41.666666666666664 -waveform {0 20.8333333333333} [list [get_pins {ClockBlock/dsi_in_0}]]
create_clock -name {CyILO} -period 31250 -waveform {0 15625} [list [get_pins {ClockBlock/ilo}]]
create_clock -name {CyLFCLK} -period 31250 -waveform {0 15625} [list [get_pins {ClockBlock/lfclk}]]
create_clock -name {CyIMO} -period 41.666666666666664 -waveform {0 20.8333333333333} [list [get_pins {ClockBlock/imo}]]
create_clock -name {CyHFCLK} -period 41.666666666666664 -waveform {0 20.8333333333333} [list [get_pins {ClockBlock/hfclk}]]
create_clock -name {CySYSCLK} -period 41.666666666666664 -waveform {0 20.8333333333333} [list [get_pins {ClockBlock/sysclk}]]
create_generated_clock -name {CapSense_CSD_SampleClk} -source [get_pins {ClockBlock/hfclk}] -edges {1 255 511} [list]
create_generated_clock -name {CapSense_CSD_SenseClk} -source [get_pins {ClockBlock/hfclk}] -edges {1 255 511} [list]
create_generated_clock -name {Clock_PWM} -source [get_pins {ClockBlock/hfclk}] -edges {1 3 5} [list]
create_generated_clock -name {UART_1_SCBCLK} -source [get_pins {ClockBlock/hfclk}] -edges {1 27 53} -nominal_period 1083.3333333333333 [list]

set_false_path -from [get_pins {__ONE__/q}]

# Component constraints for C:\Users\SHOZO\Documents\GitHub\utsushiomi\PSoC4\CHIGASAKI_Utsushiomi_2020_kit.cydsn\TopDesign\TopDesign.cysch
# Project: C:\Users\SHOZO\Documents\GitHub\utsushiomi\PSoC4\CHIGASAKI_Utsushiomi_2020_kit.cydsn\CHIGASAKI_Utsushiomi_2020_kit.cyprj
# Date: Sun, 11 Oct 2020 10:09:02 GMT
