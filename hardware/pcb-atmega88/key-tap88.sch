EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L conn2:AMIGA-Keyboard-PINHEAD J4
U 1 1 605796D8
P 8350 1550
F 0 "J4" H 8768 1558 60  0000 L CNN
F 1 "AMIGA-Keyboard-PINHEAD" H 8768 1452 60  0000 L CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x08_Pitch2.54mm" H 8200 1550 60  0001 C CNN
F 3 "" H 8200 1550 60  0001 C CNN
	1    8350 1550
	1    0    0    -1  
$EndComp
$Comp
L own-ics:+5V #PWR0101
U 1 1 6058130C
P 7900 1150
F 0 "#PWR0101" H 7900 1000 50  0001 C CNN
F 1 "+5V" H 7900 1323 50  0000 C CNN
F 2 "" H 7900 1150 50  0001 C CNN
F 3 "" H 7900 1150 50  0001 C CNN
	1    7900 1150
	1    0    0    -1  
$EndComp
Wire Wire Line
	8000 1550 7900 1550
Wire Wire Line
	7900 1550 7900 1150
Wire Wire Line
	7400 1250 8000 1250
Wire Wire Line
	7400 1350 8000 1350
Wire Wire Line
	7400 1450 8000 1450
Wire Wire Line
	8000 1850 7400 1850
Wire Wire Line
	8000 1950 7400 1950
Wire Wire Line
	8000 1750 7900 1750
Wire Wire Line
	7900 1750 7900 2050
$Comp
L power-own:GND #PWR0102
U 1 1 60582821
P 7900 2050
F 0 "#PWR0102" H 7900 1800 50  0001 C CNN
F 1 "GND" H 7900 1877 50  0000 C CNN
F 2 "" H 7900 2050 50  0001 C CNN
F 3 "" H 7900 2050 50  0001 C CNN
	1    7900 2050
	1    0    0    -1  
$EndComp
$Comp
L own-ics:+5V #PWR0103
U 1 1 60582F2C
P 7900 2650
F 0 "#PWR0103" H 7900 2500 50  0001 C CNN
F 1 "+5V" H 7900 2823 50  0000 C CNN
F 2 "" H 7900 2650 50  0001 C CNN
F 3 "" H 7900 2650 50  0001 C CNN
	1    7900 2650
	1    0    0    -1  
$EndComp
Wire Wire Line
	8000 3050 7900 3050
Wire Wire Line
	7900 3050 7900 2650
Wire Wire Line
	7400 2750 8000 2750
Wire Wire Line
	7400 2850 8000 2850
Wire Wire Line
	7400 2950 8000 2950
Wire Wire Line
	8000 3350 7400 3350
Wire Wire Line
	8000 3450 7400 3450
Wire Wire Line
	8000 3250 7900 3250
Wire Wire Line
	7900 3250 7900 3550
$Comp
L power-own:GND #PWR0104
U 1 1 60582F44
P 7900 3550
F 0 "#PWR0104" H 7900 3300 50  0001 C CNN
F 1 "GND" H 7900 3377 50  0000 C CNN
F 2 "" H 7900 3550 50  0001 C CNN
F 3 "" H 7900 3550 50  0001 C CNN
	1    7900 3550
	1    0    0    -1  
$EndComp
$Comp
L conn2:AMIGA-Keyboard-PINHEAD J5
U 1 1 60582F22
P 8350 3050
F 0 "J5" H 8768 3058 60  0000 L CNN
F 1 "AMIGA-Keyboard-PINHEAD" H 8768 2952 60  0000 L CNN
F 2 "Socket_Strips:Socket_Strip_Straight_1x08_Pitch2.54mm" H 8200 3050 60  0001 C CNN
F 3 "" H 8200 3050 60  0001 C CNN
	1    8350 3050
	1    0    0    -1  
$EndComp
$Comp
L conn2:UART-CON-4 J2
U 1 1 6058539F
P 5850 3900
F 0 "J2" H 5825 4247 60  0000 C CNN
F 1 "UART-CON-4" H 5825 4141 60  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x04_Pitch2.54mm" H 5850 3900 60  0001 C CNN
F 3 "" H 5850 3900 60  0001 C CNN
	1    5850 3900
	1    0    0    -1  
$EndComp
$Comp
L conn2:CONN_01X08 J3
U 1 1 60586507
P 8650 4650
F 0 "J3" H 8728 4691 50  0000 L CNN
F 1 "CONN_01X08" H 8728 4600 50  0000 L CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x08_Pitch2.54mm" H 8650 4650 50  0001 C CNN
F 3 "" H 8650 4650 50  0001 C CNN
	1    8650 4650
	1    0    0    -1  
$EndComp
$Comp
L own-ics:AtMega48PA U1
U 1 1 605F02EB
P 2850 2200
F 0 "U1" H 3800 2467 50  0000 C CNN
F 1 "AtMega48PA" H 3800 2376 50  0000 C CNN
F 2 "Housings_QFP:TQFP-32_7x7mm_Pitch0.8mm" H 2850 2200 50  0001 C CNN
F 3 "" H 2850 2200 50  0001 C CNN
	1    2850 2200
	1    0    0    -1  
$EndComp
Wire Wire Line
	4750 3800 5500 3800
Wire Wire Line
	4750 3900 5500 3900
Wire Wire Line
	6150 3900 6200 3900
Wire Wire Line
	6200 3900 6200 3950
Wire Wire Line
	6150 3800 6200 3800
Wire Wire Line
	6200 3800 6200 3750
$Comp
L own-ics:+5V #PWR0105
U 1 1 605F5136
P 6200 3750
F 0 "#PWR0105" H 6200 3600 50  0001 C CNN
F 1 "+5V" H 6200 3923 50  0000 C CNN
F 2 "" H 6200 3750 50  0001 C CNN
F 3 "" H 6200 3750 50  0001 C CNN
	1    6200 3750
	1    0    0    -1  
$EndComp
$Comp
L power-own:GND #PWR0106
U 1 1 605F57D4
P 6200 3950
F 0 "#PWR0106" H 6200 3700 50  0001 C CNN
F 1 "GND" H 6200 3777 50  0000 C CNN
F 2 "" H 6200 3950 50  0001 C CNN
F 3 "" H 6200 3950 50  0001 C CNN
	1    6200 3950
	1    0    0    -1  
$EndComp
Wire Wire Line
	4750 4000 5200 4000
Wire Wire Line
	4750 4100 5200 4100
Wire Wire Line
	4750 4200 5200 4200
$Comp
L Device:C C1
U 1 1 605F947F
P 2400 2050
F 0 "C1" V 2350 1700 50  0000 C CNN
F 1 "100n" V 2450 1700 50  0000 C CNN
F 2 "discrete:C_0805" H 2438 1900 50  0001 C CNN
F 3 "~" H 2400 2050 50  0001 C CNN
	1    2400 2050
	0    1    1    0   
$EndComp
Wire Wire Line
	2850 2200 2750 2200
$Comp
L Device:C C3
U 1 1 605FB61F
P 2400 2600
F 0 "C3" V 2300 2250 50  0000 C CNN
F 1 "100n" V 2400 2250 50  0000 C CNN
F 2 "discrete:C_0805" H 2438 2450 50  0001 C CNN
F 3 "~" H 2400 2600 50  0001 C CNN
	1    2400 2600
	0    1    1    0   
$EndComp
Wire Wire Line
	2850 2600 2550 2600
Wire Wire Line
	2850 4300 2750 4300
Wire Wire Line
	2750 4300 2750 4400
Wire Wire Line
	2850 4400 2750 4400
Connection ~ 2750 4400
Wire Wire Line
	2750 4400 2750 4500
Wire Wire Line
	2850 4500 2750 4500
Connection ~ 2750 4500
Wire Wire Line
	2750 4500 2750 4600
$Comp
L power-own:GND #PWR0107
U 1 1 605FDFF7
P 2750 4600
F 0 "#PWR0107" H 2750 4350 50  0001 C CNN
F 1 "GND" H 2750 4427 50  0000 C CNN
F 2 "" H 2750 4600 50  0001 C CNN
F 3 "" H 2750 4600 50  0001 C CNN
	1    2750 4600
	1    0    0    -1  
$EndComp
Wire Wire Line
	2850 2500 2750 2500
Wire Wire Line
	2750 2500 2750 2300
Connection ~ 2750 2200
Wire Wire Line
	2850 2300 2750 2300
Connection ~ 2750 2300
Wire Wire Line
	2750 2300 2750 2200
Wire Wire Line
	2750 2200 2750 2050
$Comp
L own-ics:+5V #PWR0108
U 1 1 6060158B
P 2750 1950
F 0 "#PWR0108" H 2750 1800 50  0001 C CNN
F 1 "+5V" H 2750 2123 50  0000 C CNN
F 2 "" H 2750 1950 50  0001 C CNN
F 3 "" H 2750 1950 50  0001 C CNN
	1    2750 1950
	1    0    0    -1  
$EndComp
Wire Wire Line
	2200 2600 2250 2600
Wire Wire Line
	2200 2600 2200 2850
Connection ~ 2200 2600
$Comp
L power-own:GND #PWR0109
U 1 1 6060402D
P 2200 3500
F 0 "#PWR0109" H 2200 3250 50  0001 C CNN
F 1 "GND" H 2200 3327 50  0000 C CNN
F 2 "" H 2200 3500 50  0001 C CNN
F 3 "" H 2200 3500 50  0001 C CNN
	1    2200 3500
	1    0    0    -1  
$EndComp
$Comp
L Device:C C2
U 1 1 60604BF2
P 2400 2300
F 0 "C2" V 2350 1950 50  0000 C CNN
F 1 "100n" V 2450 1950 50  0000 C CNN
F 2 "discrete:C_0805" H 2438 2150 50  0001 C CNN
F 3 "~" H 2400 2300 50  0001 C CNN
	1    2400 2300
	0    1    1    0   
$EndComp
Wire Wire Line
	2250 2050 2200 2050
Wire Wire Line
	2200 2050 2200 2300
Wire Wire Line
	2550 2050 2750 2050
Connection ~ 2750 2050
Wire Wire Line
	2750 2050 2750 1950
Wire Wire Line
	2200 2300 2250 2300
Connection ~ 2200 2300
Wire Wire Line
	2200 2300 2200 2600
Wire Wire Line
	2550 2300 2750 2300
$Comp
L own-ics:AVR-ISP-6x J1
U 1 1 60609BFA
P 5850 2600
F 0 "J1" H 5825 2915 50  0000 C CNN
F 1 "AVR-ISP-6x" H 5825 2824 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_2x03_Pitch2.54mm" V 5330 2640 50  0001 C CNN
F 3 "" H 5825 2600 50  0001 C CNN
	1    5850 2600
	1    0    0    -1  
$EndComp
Wire Wire Line
	4750 2500 5500 2500
Wire Wire Line
	4750 2600 5500 2600
Wire Wire Line
	4750 2700 5500 2700
Wire Wire Line
	6150 2700 6200 2700
Wire Wire Line
	6200 2700 6200 2750
Wire Wire Line
	6150 2500 6200 2500
Wire Wire Line
	6200 2500 6200 2450
$Comp
L own-ics:+5V #PWR0110
U 1 1 60611D9C
P 6200 2450
F 0 "#PWR0110" H 6200 2300 50  0001 C CNN
F 1 "+5V" H 6200 2623 50  0000 C CNN
F 2 "" H 6200 2450 50  0001 C CNN
F 3 "" H 6200 2450 50  0001 C CNN
	1    6200 2450
	1    0    0    -1  
$EndComp
$Comp
L power-own:GND #PWR0111
U 1 1 6061208F
P 6200 2750
F 0 "#PWR0111" H 6200 2500 50  0001 C CNN
F 1 "GND" H 6200 2577 50  0000 C CNN
F 2 "" H 6200 2750 50  0001 C CNN
F 3 "" H 6200 2750 50  0001 C CNN
	1    6200 2750
	1    0    0    -1  
$EndComp
Wire Wire Line
	6150 2600 6500 2600
Wire Wire Line
	6500 2600 6500 3300
Wire Wire Line
	6500 3300 5250 3300
Wire Wire Line
	5250 3300 5250 3650
Wire Wire Line
	5250 3650 4750 3650
Text Label 5400 3300 0    50   ~ 0
~RESET
$Comp
L own-ics:+5V #PWR0112
U 1 1 606145D7
P 6500 2150
F 0 "#PWR0112" H 6500 2000 50  0001 C CNN
F 1 "+5V" H 6500 2323 50  0000 C CNN
F 2 "" H 6500 2150 50  0001 C CNN
F 3 "" H 6500 2150 50  0001 C CNN
	1    6500 2150
	1    0    0    -1  
$EndComp
$Comp
L Device:C C4
U 1 1 60614D16
P 6500 3500
F 0 "C4" H 6385 3454 50  0000 R CNN
F 1 "100n" H 6385 3545 50  0000 R CNN
F 2 "discrete:C_0805" H 6538 3350 50  0001 C CNN
F 3 "~" H 6500 3500 50  0001 C CNN
	1    6500 3500
	-1   0    0    1   
$EndComp
Wire Wire Line
	6500 3350 6500 3300
Connection ~ 6500 3300
$Comp
L power-own:GND #PWR0113
U 1 1 6061786B
P 6500 3700
F 0 "#PWR0113" H 6500 3450 50  0001 C CNN
F 1 "GND" H 6500 3527 50  0000 C CNN
F 2 "" H 6500 3700 50  0001 C CNN
F 3 "" H 6500 3700 50  0001 C CNN
	1    6500 3700
	1    0    0    -1  
$EndComp
Wire Wire Line
	6500 3650 6500 3700
$Comp
L Device:R R1
U 1 1 60619595
P 6500 2350
F 0 "R1" H 6570 2396 50  0000 L CNN
F 1 "4k7" H 6570 2305 50  0000 L CNN
F 2 "discrete:R_0805" V 6430 2350 50  0001 C CNN
F 3 "~" H 6500 2350 50  0001 C CNN
	1    6500 2350
	1    0    0    -1  
$EndComp
Wire Wire Line
	6500 2150 6500 2200
Wire Wire Line
	6500 2500 6500 2600
Connection ~ 6500 2600
Wire Wire Line
	8450 4300 7950 4300
Wire Wire Line
	8450 4400 7950 4400
Wire Wire Line
	8450 4500 7950 4500
Wire Wire Line
	8450 4600 7950 4600
Wire Wire Line
	8450 4700 7950 4700
Wire Wire Line
	8450 4800 7950 4800
Wire Wire Line
	8450 5000 7950 5000
Wire Wire Line
	4750 3050 4900 3050
Wire Wire Line
	4750 3150 4900 3150
Wire Wire Line
	4750 3250 4900 3250
Wire Wire Line
	4750 3350 4900 3350
Wire Wire Line
	4750 3450 4900 3450
Wire Wire Line
	4750 3550 4900 3550
Text GLabel 4900 3550 2    50   Output ~ 0
CF0
Text GLabel 4900 3450 2    50   Output ~ 0
CF1
Text GLabel 4900 3350 2    50   Output ~ 0
CF2
Text GLabel 4900 3250 2    50   Output ~ 0
CF3
Text GLabel 4900 3150 2    50   Output ~ 0
CF4
Text GLabel 4900 3050 2    50   Output ~ 0
CF5
Wire Wire Line
	8450 4900 7950 4900
Text GLabel 7950 4300 0    50   Input ~ 0
CF0
Text GLabel 7950 4400 0    50   Input ~ 0
CF1
Text GLabel 7950 4500 0    50   Input ~ 0
CF2
Text GLabel 7950 4600 0    50   Input ~ 0
CF3
Text GLabel 7950 4700 0    50   Input ~ 0
CF4
Text GLabel 7950 4800 0    50   Input ~ 0
CF5
Text GLabel 7950 4900 0    50   Input ~ 0
CF6
Text GLabel 7950 5000 0    50   Input ~ 0
CF7
Text GLabel 5200 4200 2    40   Input ~ 0
~KBRESET
Text GLabel 5200 4000 2    40   Input ~ 0
~KBCLK
Text GLabel 5200 4100 2    40   Input ~ 0
~KBDATA
Text GLabel 7400 2950 0    35   Input ~ 0
~KBRESET
Text GLabel 7400 2750 0    40   BiDi ~ 0
~KBCLK
Text GLabel 7400 2850 0    40   BiDi ~ 0
~KBDATA
Text GLabel 7400 1950 0    50   Input ~ 0
FLOPPY_LED
Text Notes 8250 950  0    50   ~ 0
Keyboard \nConnector
Text Notes 8250 2650 0    50   ~ 0
To Amiga
Text GLabel 7400 1250 0    40   BiDi ~ 0
~KBCLK
Text GLabel 7400 1350 0    35   BiDi ~ 0
~KBDATA
Text GLabel 7400 1450 0    35   Output ~ 0
~KBRESET
Text GLabel 7400 3450 0    50   Output ~ 0
FLOPPY_LED
Text GLabel 7400 1850 0    50   Input ~ 0
POWER_LED
Text GLabel 7400 3350 0    50   Output ~ 0
POWER_LED
Text GLabel 4900 2400 2    50   Output ~ 0
CF6
Text GLabel 4900 2300 2    50   Output ~ 0
CF7
Wire Wire Line
	4750 2300 4900 2300
Wire Wire Line
	4900 2400 4750 2400
Text Label 5200 2500 0    50   ~ 0
MOSI
Text Label 5200 2600 0    50   ~ 0
MISO
Text Label 5200 2700 0    50   ~ 0
SCK
Text Label 5200 3800 0    50   ~ 0
RXD
Text Label 5200 3900 0    50   ~ 0
TXD
Text Notes 7950 4100 0    50   ~ 0
Configuration Pins
NoConn ~ 2850 3900
NoConn ~ 2850 4000
NoConn ~ 4750 4500
NoConn ~ 4750 4300
NoConn ~ 4750 4400
$Comp
L Jumper:SolderJumper_2_Open JP1
U 1 1 606DD9FE
P 2600 2850
F 0 "JP1" H 2600 3055 50  0000 C CNN
F 1 "SolderJumper_2_Open" H 2600 2964 50  0000 C CNN
F 2 "Conn2:SMD-JUMPER" H 2600 2850 50  0001 C CNN
F 3 "~" H 2600 2850 50  0001 C CNN
	1    2600 2850
	1    0    0    -1  
$EndComp
Wire Wire Line
	4750 2200 4800 2200
Wire Wire Line
	2750 2850 2850 2850
Wire Wire Line
	2450 2850 2200 2850
Connection ~ 2200 2850
Wire Wire Line
	2200 2850 2200 3250
$Comp
L Jumper:SolderJumper_2_Open JP2
U 1 1 607014FB
P 2600 3250
F 0 "JP2" H 2600 3455 50  0000 C CNN
F 1 "SolderJumper_2_Open" H 2600 3364 50  0000 C CNN
F 2 "Conn2:SMD-JUMPER" H 2600 3250 50  0001 C CNN
F 3 "~" H 2600 3250 50  0001 C CNN
	1    2600 3250
	1    0    0    -1  
$EndComp
Wire Wire Line
	2750 3250 2850 3250
Wire Wire Line
	2450 3250 2200 3250
Connection ~ 2200 3250
Wire Wire Line
	2200 3250 2200 3500
$EndSCHEMATC
