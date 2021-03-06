/*
............::LYCOSID PROJECT 2017::...............
* COPYRIGHT
    Copyright (C) 2016  IR64 POLITEKNIK NEGERI JEMBER, http://www.polije.ac.id/
    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.
    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.
    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.

* AUTHOR
    Ahmad Waris Al H (warishafidz@gmail.com)
    ... (Dedy)
    ... (Nashrul)
    ... (Retno)
*/

#include <DynamixelSerial.h>

#define ILEG1_A  1
#define ILEG1_B  2
#define ILEG1_C  3
#define ILEG2_A  4
#define ILEG2_B  5
#define ILEG2_C  6
#define ILEG3_A  7
#define ILEG3_B  8
#define ILEG3_C  9
#define ILEG4_A  10
#define ILEG4_B  11
#define ILEG4_C  12
#define ILEG5_A  13
#define ILEG5_B  14
#define ILEG5_C  15
#define ILEG6_A  16
#define ILEG6_B  17
#define ILEG6_C  18

#define timer0   1000
#define timer1   1000
#define speed0   100
#define speed1   100

#define MAP(x)  ((int)map(x, 0, 300, 0, 1023))

//int 
//  LEG1_A [4] = {MAP(140), MAP(125), MAP(110), MAP(125)},
//  LEG1_B [4] = {MAP(150), MAP(160), MAP(150), MAP(150)},
//  LEG1_C [4] = {MAP(150), MAP(180), MAP(150), MAP(150)},
//
//  LEG2_A [4] = {MAP(135), MAP(150), MAP(165), MAP(135)},
//  LEG2_B [4] = {MAP(150), MAP(150), MAP(150), MAP(150)},
//  LEG2_C [4] = {MAP(150), MAP(150), MAP(150), MAP(180)},
//  
//  LEG3_A [4] = {MAP(190), MAP(175), MAP(160), MAP(175)},
//  LEG3_B [4] = {MAP(150), MAP(150), MAP(150), MAP(150)},
//  LEG3_C [4] = {MAP(150), MAP(180), MAP(150), MAP(150)},
//
//  LEG4_A [4] = {MAP(140), MAP(125), MAP(110), MAP(125)},
//  LEG4_B [4] = {MAP(150), MAP(150), MAP(150), MAP(150)},
//  LEG4_C [4] = {MAP(150), MAP(150), MAP(150), MAP(120)},
//  
//  LEG5_A [4] = {MAP(135), MAP(150), MAP(165), MAP(135)},
//  LEG5_B [4] = {MAP(150), MAP(150), MAP(150), MAP(150)},
//  LEG5_C [4] = {MAP(150), MAP(120), MAP(150), MAP(150)},
//  
//  LEG6_A [4] = {MAP(190), MAP(175), MAP(160), MAP(175)},
//  LEG6_B [4] = {MAP(150), MAP(150), MAP(150), MAP(150)},
//  LEG6_C [4] = {MAP(150), MAP(150), MAP(150), MAP(120)};

int
  LEG1_A [4] = {MAP(135), MAP(115), MAP(115), MAP(135)},
  LEG1_B [4] = {MAP(170), MAP(190), MAP(170), MAP(170)},
  LEG1_C [4] = {MAP(130), MAP(110), MAP(130), MAP(130)},

  LEG2_A [4] = {MAP(140), MAP(160), MAP(160), MAP(140)},
  LEG2_B [4] = {MAP(170), MAP(170), MAP(170), MAP(190)},
  LEG2_C [4] = {MAP(130), MAP(130), MAP(130), MAP(110)},
  
  LEG3_A [4] = {MAP(185), MAP(165), MAP(165), MAP(185)},
  LEG3_B [4] = {MAP(170), MAP(190), MAP(170), MAP(170)},
  LEG3_C [4] = {MAP(130), MAP(110), MAP(130), MAP(130)},

  LEG4_A [4] = {MAP(135), MAP(115), MAP(115), MAP(135)},
  LEG4_B [4] = {MAP(170), MAP(170), MAP(170), MAP(190)},
  LEG4_C [4] = {MAP(130), MAP(130), MAP(130), MAP(110)},
 
  LEG5_A [4] = {MAP(140), MAP(160), MAP(160), MAP(140)},
  LEG5_B [4] = {MAP(170), MAP(190), MAP(170), MAP(170)},
  LEG5_C [4] = {MAP(130), MAP(110), MAP(130), MAP(130)},
  
  LEG6_A [4] = {MAP(185), MAP(165), MAP(165), MAP(185)},
  LEG6_B [4] = {MAP(170), MAP(170), MAP(170), MAP(190)},
  LEG6_C [4] = {MAP(130), MAP(130), MAP(130), MAP(110)};

  

void setup() {
  int i;
  pinMode(13, OUTPUT);
  pinMode(6, INPUT_PULLUP);
  pinMode(8, INPUT_PULLUP);
  Dynamixel.begin(1000000, 3);
  delay(100);
  
  // put your setup code here, to run once:
  while(digitalRead(6) == HIGH);
  digitalWrite(13, HIGH);
  for (i = 1; i <= 18; i++)
    Dynamixel.moveSpeed(i, 512, 50);

  delay(1000);
  while(digitalRead(6) == HIGH); 
  digitalWrite(13, LOW);
}

void loop() {
  Dynamixel.moveSpeed(ILEG1_A, LEG1_A[0], speed0);
  Dynamixel.moveSpeed(ILEG1_B, LEG1_B[0], speed1);
  Dynamixel.moveSpeed(ILEG1_C, LEG1_C[0], speed1);
  
  Dynamixel.moveSpeed(ILEG2_A, LEG2_A[0], speed0);
  Dynamixel.moveSpeed(ILEG2_B, LEG2_B[0], speed1);
  Dynamixel.moveSpeed(ILEG2_C, LEG2_C[0], speed1);
  
  Dynamixel.moveSpeed(ILEG3_A, LEG3_A[0], speed0);
  Dynamixel.moveSpeed(ILEG3_B, LEG3_B[0], speed1);
  Dynamixel.moveSpeed(ILEG3_C, LEG3_C[0], speed1);
  
  Dynamixel.moveSpeed(ILEG4_A, LEG4_A[0], speed0);
  Dynamixel.moveSpeed(ILEG4_B, LEG4_B[0], speed1);
  Dynamixel.moveSpeed(ILEG4_C, LEG4_C[0], speed1);
  
  Dynamixel.moveSpeed(ILEG5_A, LEG5_A[0], speed0);
  Dynamixel.moveSpeed(ILEG5_B, LEG5_B[0], speed1);
  Dynamixel.moveSpeed(ILEG5_C, LEG5_C[0], speed0);
  
  Dynamixel.moveSpeed(ILEG6_A, LEG6_A[0], speed0);
  Dynamixel.moveSpeed(ILEG6_B, LEG6_B[0], speed1);
  Dynamixel.moveSpeed(ILEG6_C, LEG6_C[0], speed1); 
  delay(timer1);
  
  Dynamixel.moveSpeed(ILEG1_C, LEG1_C[1], speed1);
  Dynamixel.moveSpeed(ILEG1_B, LEG1_B[1], speed1);
  
  Dynamixel.moveSpeed(ILEG2_C, LEG2_C[1], speed1);
  Dynamixel.moveSpeed(ILEG2_B, LEG2_B[1], speed1);

  Dynamixel.moveSpeed(ILEG3_C, LEG3_C[1], speed1);
  Dynamixel.moveSpeed(ILEG3_B, LEG3_B[1], speed1);
  
  Dynamixel.moveSpeed(ILEG4_C, LEG4_C[1], speed1);
  Dynamixel.moveSpeed(ILEG4_B, LEG4_B[1], speed1);
  
  Dynamixel.moveSpeed(ILEG5_C, LEG5_C[1], speed1);
  Dynamixel.moveSpeed(ILEG5_B, LEG5_B[1], speed1);
    
  Dynamixel.moveSpeed(ILEG6_C, LEG6_C[1], speed1);
  Dynamixel.moveSpeed(ILEG6_B, LEG6_B[1], speed1);

  delay(timer0);
  Dynamixel.moveSpeed(ILEG1_A, LEG1_A[1], speed0);
  Dynamixel.moveSpeed(ILEG2_A, LEG2_A[1], speed0);
  Dynamixel.moveSpeed(ILEG3_A, LEG3_A[1], speed0);
  Dynamixel.moveSpeed(ILEG4_A, LEG4_A[1], speed0);
  Dynamixel.moveSpeed(ILEG5_A, LEG5_A[1], speed0);
  Dynamixel.moveSpeed(ILEG6_A, LEG6_A[1], speed0);

  delay(timer1);
  
  Dynamixel.moveSpeed(ILEG1_A, LEG1_A[2], speed0);
  Dynamixel.moveSpeed(ILEG2_A, LEG2_A[2], speed0);
  Dynamixel.moveSpeed(ILEG3_A, LEG3_A[2], speed0);
  Dynamixel.moveSpeed(ILEG4_A, LEG4_A[2], speed0);
  Dynamixel.moveSpeed(ILEG5_A, LEG5_A[2], speed0);
  Dynamixel.moveSpeed(ILEG6_A, LEG6_A[2], speed0);
  
  delay(timer0);
  Dynamixel.moveSpeed(ILEG1_C, LEG1_C[2], speed1);
  Dynamixel.moveSpeed(ILEG1_B, LEG1_B[2], speed1);
  
  Dynamixel.moveSpeed(ILEG2_C, LEG2_C[2], speed1);
  Dynamixel.moveSpeed(ILEG2_B, LEG2_B[1], speed1);

  Dynamixel.moveSpeed(ILEG3_C, LEG3_C[2], speed1);
  Dynamixel.moveSpeed(ILEG3_B, LEG3_B[2], speed1);
  
  Dynamixel.moveSpeed(ILEG4_C, LEG4_C[2], speed1);
  Dynamixel.moveSpeed(ILEG4_B, LEG4_B[2], speed1);
  
  Dynamixel.moveSpeed(ILEG5_C, LEG5_C[2], speed1);
  Dynamixel.moveSpeed(ILEG5_B, LEG5_B[2], speed1);
   
  Dynamixel.moveSpeed(ILEG6_C, LEG6_C[2], speed1);
  Dynamixel.moveSpeed(ILEG6_B, LEG6_B[2], speed1);

  delay(timer1);
  
  Dynamixel.moveSpeed(ILEG1_A, LEG1_A[3], speed0);
  Dynamixel.moveSpeed(ILEG1_B, LEG1_B[3], speed1);
  Dynamixel.moveSpeed(ILEG1_C, LEG1_C[3], speed1);
  
  Dynamixel.moveSpeed(ILEG2_A, LEG2_A[3], speed0);
  Dynamixel.moveSpeed(ILEG2_B, LEG2_B[3], speed1);
  Dynamixel.moveSpeed(ILEG2_C, LEG2_C[3], speed1);
  
  Dynamixel.moveSpeed(ILEG3_A, LEG3_A[3], speed0);
  Dynamixel.moveSpeed(ILEG3_B, LEG3_B[3], speed1);
  Dynamixel.moveSpeed(ILEG3_C, LEG3_C[3], speed1);
  
  Dynamixel.moveSpeed(ILEG4_A, LEG4_A[3], speed0);
  Dynamixel.moveSpeed(ILEG4_B, LEG4_B[3], speed1);
  Dynamixel.moveSpeed(ILEG4_C, LEG4_C[3], speed1);
  
  Dynamixel.moveSpeed(ILEG5_A, LEG5_A[3], speed0);
  Dynamixel.moveSpeed(ILEG5_B, LEG5_B[3], speed1);
  Dynamixel.moveSpeed(ILEG5_C, LEG5_C[3], speed1);
  
  Dynamixel.moveSpeed(ILEG6_A, LEG6_A[3], speed0);
  Dynamixel.moveSpeed(ILEG6_B, LEG6_B[3], speed1);
  Dynamixel.moveSpeed(ILEG6_C, LEG6_C[3], speed1); 
  delay(timer1);
}
