#pragma config(Motor,  motorA,          motorA,        tmotorNormal, PIDControl, encoder)
#pragma config(Motor,  motorB,          motorB,        tmotorNormal, PIDControl, encoder)
#pragma config(Motor,  motorC,          motorC,        tmotorNormal, PIDControl, encoder)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#define SPEED 50

void spin(int speed);
void forward(int speed);
void left(int speed);
void right(int speed);
void stopMoves();
void arc(int speed, int radius);
void moveWithAngle(int speed, float angle);

task main
{
  /*spin(SPEED);
  wait1Msec(2000);
  forward(SPEED);
  wait1Msec(1000);
  left(SPEED);
  wait1Msec(1000);
  right(SPEED);
  wait1Msec(1000);
  stopMoves();*/
  arc(SPEED, 1000);
}

void spin(int speed)
{
  motor[motorA] = speed;
  motor[motorB] = speed;
  motor[motorC] = speed;
}

void stopMoves()
{
  motor[motorA] = 0;
  motor[motorB] = 0;
  motor[motorC] = 0;
}

void forward(int speed)
{
  eraseDisplay();
  nxtDisplayTextLine(1, "%s", "Forward");
  motor[motorA] = speed;
  motor[motorB] = speed;
  motor[motorC] = 0;
}

void left(int speed)
{
  eraseDisplay();
  nxtDisplayTextLine(1, "%s", "Left");
  motor[motorA] = 0;
  motor[motorB] = speed;
  motor[motorC] = speed;
}

void right(int speed)
{
  eraseDisplay();
  nxtDisplayTextLine(1, "%s", "Right");
  motor[motorA] = speed;
  motor[motorB] = 0;
  motor[motorC] = speed;
}

void arc(int speed, int radius)
{
  int i, x = 0;
  while(i < 4){
    while(x != 360){
      moveWithAngle(speed, x);
      wait1Msec(radius);
      x += 15;
    }
    i++;
  }
  stopMoves();
}

void moveWithAngle(int speed, float angle)
{
  float p, q, r;
  p = cosDegrees(angle)*1 - sinDegrees(angle)*0;
  q = cosDegrees(angle+120)*1 - sinDegrees(angle+120)*0;
  r = cosDegrees(angle+240)*1 - sinDegrees(angle+240)*0;
  stopMoves();
  //OnRev(OUT_B, speed*p);
  //OnRev(OUT_A, speed*q);
  //OnRev(OUT_C, speed*r);
  if(q>0){
    abs(q);
    motor[motorA] = -1*(speed*q);
  }else{
    abs(q);
    motor[motorA] = (speed*q);
  }
  if(p>0){
    abs(p);
    motor[motorB] = -1*(speed*p);
  }else{
    abs(p);
    motor[motorB] = (speed*p);
  }
  if(r>0){
    abs(r);
    motor[motorC] = -1*(speed*r);
  }else{
    abs(r);
    motor[motorC] = (speed*r);
  }
}