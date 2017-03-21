/*
 Motion Direction Legend:
 1. Forward
 2. Right
 3. Backward
 4. Left
 5. Free Run ( this is just for our perception. Do not use it anywhere to denoe it.)
 6. Brake
*/


void leftTurn() {
  motion_direction=2;
  digitalWrite(InputAA, HIGH);
  digitalWrite(InputBA, HIGH);
  digitalWrite(InputBB, LOW);
  digitalWrite(InputAB, LOW);
}


void rightTurn() {
  motion_direction=3;
  digitalWrite(InputAA, LOW);
  digitalWrite(InputBA, LOW);
  digitalWrite(InputBB, HIGH);
  digitalWrite(InputAB, HIGH);
}


void forward() {
  motion_direction=1;
  digitalWrite(InputAA, HIGH);
  digitalWrite(InputBA, LOW);
  digitalWrite(InputBB, HIGH);
  digitalWrite(InputAB, LOW);
}


void backward() {
  motion_direction=4;
  digitalWrite(InputAA, LOW);
  digitalWrite(InputBA, HIGH);
  digitalWrite(InputBB, LOW);
  digitalWrite(InputAB, HIGH);
}

void freeRun() {
  digitalWrite(InputAA, LOW);
  digitalWrite(InputBA, LOW);
  digitalWrite(InputBB, LOW);
  digitalWrite(InputAB, LOW);
}

void brake() {
  motion_direction=6;
  digitalWrite(InputAA, HIGH);
  digitalWrite(InputBA, HIGH);
  digitalWrite(InputBB, HIGH);
  digitalWrite(InputAB, HIGH);
}
