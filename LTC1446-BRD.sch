EESchema Schematic File Version 4
LIBS:LTC1446-BRD-cache
EELAYER 26 0
EELAYER END
$Descr USLetter 11000 8500
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
L Analog_DAC:LTC1446 U1
U 1 1 5B5FA897
P 5000 3850
F 0 "U1" H 4650 4300 50  0000 C CNN
F 1 "LTC1446" H 4750 4200 50  0000 C CNN
F 2 "Package_DIP:DIP-8_W7.62mm_Socket" H 5800 3550 50  0001 C CNN
F 3 "http://cds.linear.com/docs/en/datasheet/1446fa.pdf" H 5800 3550 50  0001 C CNN
	1    5000 3850
	1    0    0    -1  
$EndComp
$Comp
L power:GNDREF #PWR02
U 1 1 5B5FA951
P 5000 4350
F 0 "#PWR02" H 5000 4100 50  0001 C CNN
F 1 "GNDREF" H 5005 4177 50  0000 C CNN
F 2 "" H 5000 4350 50  0001 C CNN
F 3 "" H 5000 4350 50  0001 C CNN
	1    5000 4350
	1    0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_01x02 J2
U 1 1 5B5FAA7F
P 6050 3850
F 0 "J2" H 6130 3842 50  0000 L CNN
F 1 "Output to motherboard inputs" H 6130 3751 50  0000 L CNN
F 2 "Connector_PinSocket_2.54mm:PinSocket_1x02_P2.54mm_Vertical" H 6050 3850 50  0001 C CNN
F 3 "~" H 6050 3850 50  0001 C CNN
	1    6050 3850
	1    0    0    -1  
$EndComp
Text Label 5850 3850 2    50   ~ 0
VS
Text Label 5850 3950 2    50   ~ 0
VL
Text Label 5500 3750 0    50   ~ 0
VS
Text Label 5500 4050 0    50   ~ 0
VL
$Comp
L Connector_Generic:Conn_01x05 J1
U 1 1 5B5FB029
P 3550 3950
F 0 "J1" H 3630 3946 50  0000 L CNN
F 1 "Conn_01x05" H 3630 3901 50  0001 L CNN
F 2 "Connector_PinSocket_2.54mm:PinSocket_1x05_P2.54mm_Vertical" H 3550 3950 50  0001 C CNN
F 3 "~" H 3550 3950 50  0001 C CNN
	1    3550 3950
	1    0    0    -1  
$EndComp
Text Label 5000 3100 0    50   ~ 0
VCC
Text Label 3350 4050 2    50   ~ 0
VCC
$Comp
L power:GNDREF #PWR01
U 1 1 5B5FB1B6
P 3350 4150
F 0 "#PWR01" H 3350 3900 50  0001 C CNN
F 1 "GNDREF" H 3355 3977 50  0000 C CNN
F 2 "" H 3350 4150 50  0001 C CNN
F 3 "" H 3350 4150 50  0001 C CNN
	1    3350 4150
	1    0    0    -1  
$EndComp
Text Label 4500 3750 2    50   ~ 0
CLK
Text Label 4500 3850 2    50   ~ 0
D_IN
Text Label 4500 4050 2    50   ~ 0
CS
Text Label 4500 3950 2    50   ~ 0
D_OUT
NoConn ~ 4500 3950
Text Label 3350 3750 2    50   ~ 0
CLK
Text Label 3350 3850 2    50   ~ 0
D_IN
Text Label 3350 3950 2    50   ~ 0
CS
$Comp
L Device:C_Small C1
U 1 1 5B5FB48F
P 5300 3200
F 0 "C1" H 5392 3246 50  0000 L CNN
F 1 "0.1uF" H 5392 3155 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 5300 3200 50  0001 C CNN
F 3 "~" H 5300 3200 50  0001 C CNN
	1    5300 3200
	1    0    0    -1  
$EndComp
$Comp
L power:GNDREF #PWR03
U 1 1 5B5FB51D
P 5300 3300
F 0 "#PWR03" H 5300 3050 50  0001 C CNN
F 1 "GNDREF" H 5305 3127 50  0000 C CNN
F 2 "" H 5300 3300 50  0001 C CNN
F 3 "" H 5300 3300 50  0001 C CNN
	1    5300 3300
	1    0    0    -1  
$EndComp
Wire Wire Line
	5000 3450 5000 3100
Wire Wire Line
	5300 3100 5000 3100
$Comp
L Device:R_US R1
U 1 1 5B64C673
P 3950 3900
F 0 "R1" H 4018 3946 50  0000 L CNN
F 1 "10k" H 4018 3855 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" V 3990 3890 50  0001 C CNN
F 3 "~" H 3950 3900 50  0001 C CNN
	1    3950 3900
	1    0    0    -1  
$EndComp
Wire Wire Line
	3950 4050 4500 4050
Wire Wire Line
	3950 3750 3950 3100
Wire Wire Line
	3950 3100 5000 3100
Connection ~ 5000 3100
$EndSCHEMATC
