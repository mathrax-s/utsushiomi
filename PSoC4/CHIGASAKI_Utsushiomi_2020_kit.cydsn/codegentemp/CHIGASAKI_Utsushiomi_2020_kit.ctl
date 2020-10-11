-- ======================================================================
-- CHIGASAKI_Utsushiomi_2020_kit.ctl generated from CHIGASAKI_Utsushiomi_2020_kit
-- 10/11/2020 at 19:09
-- This file is auto generated. ANY EDITS YOU MAKE MAY BE LOST WHEN THIS FILE IS REGENERATED!!!
-- ======================================================================

-- TopDesign
-- =============================================================================
-- The following directives assign pins to the locations specific for the
-- CY8CKIT-042 kit.
-- =============================================================================

-- === RGB LED ===
attribute port_location of LED_1(0) : label is "PORT(0,2)"; -- GREEN LED
attribute port_location of LED_2(0) : label is "PORT(0,3)"; -- BLUE LED

-- === Slider ===
attribute port_location of \CapSense_CSD:Cmod(0)\ : label is "PORT(4,2)";
attribute port_location of \CapSense_CSD:Sns(0)\ : label is "PORT(1,1)";
attribute port_location of \CapSense_CSD:Sns(1)\ : label is "PORT(1,2)";
attribute port_location of \CapSense_CSD:Sns(2)\ : label is "PORT(1,3)";
attribute port_location of \CapSense_CSD:Sns(3)\ : label is "PORT(1,4)";
attribute port_location of \CapSense_CSD:Sns(4)\ : label is "PORT(1,5)";

-- PSoC Clock Editor
-- Directives Editor
-- Analog Device Editor
