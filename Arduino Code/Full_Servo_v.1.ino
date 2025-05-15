#include <Servo.h>

Servo servos[13];
int currentPositions[13] = {90, 90, 90, 90, 90, 90, 90, 90, 90, 90, 90, 90, 90};
int servoPins[13] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13};
int pickCounter = 1;

void setup() {
  Serial.begin(9600);
  for (int i = 0; i < 13; i++) {
    servos[i].attach(servoPins[i]);
    servos[i].write(currentPositions[i]);
  }
  Serial.println("Enter servo positions in format (Pick: s1, 90, s2, 180, ...):");
}

void loop() {
  if (Serial.available() > 0) {
    String input = Serial.readStringUntil('\n');
    input.trim();
    if (input.startsWith("Pick: ")) {
      input = input.substring(6);
    }
    processPickCommand(input);
    Serial.println("Pick " + String(pickCounter++) + ": OK");
    printServoPositions();
    Serial.println("Enter servo positions in format (Pick: s1, 90, s2, 180, ...):");
  }
}

void processPickCommand(String input) {
  int pos = 0;
  int targetPosition6 = -1, targetPosition7 = -1;
  while (pos < input.length()) {
    int nextComma = input.indexOf(',', pos);
    String servo = input.substring(pos, nextComma);
    servo.trim();
    int servoIndex = servo.substring(1).toInt() - 1;
    pos = nextComma + 1;
    nextComma = input.indexOf(',', pos);
    if (nextComma == -1) nextComma = input.length();
    int targetPosition = input.substring(pos, nextComma).toInt();
    pos = nextComma + 1;
    if (servoIndex == 6) targetPosition7 = targetPosition;
    else if (servoIndex == 5) targetPosition6 = targetPosition;
    else moveServoToPosition(servoIndex, targetPosition);
  }
  if (targetPosition6 != -1 || targetPosition7 != -1) {
    moveServosTogether(5, targetPosition6, 6, targetPosition7);
  }
}

void moveServoToPosition(int servoIndex, int targetPosition) {
  int currentPosition = currentPositions[servoIndex];
  int distanceToTarget = abs(targetPosition - currentPosition);
  int degreesMoved = 0;
  
  while (degreesMoved < 10 && currentPosition != targetPosition) {
    currentPosition += (currentPosition < targetPosition) ? 1 : -1;
    servos[servoIndex].write(currentPosition);
    delay(50);
    degreesMoved++;
  }
  
  while (degreesMoved < distanceToTarget - 10 && currentPosition != targetPosition) {
    currentPosition += (currentPosition < targetPosition) ? 1 : -1;
    servos[servoIndex].write(currentPosition);
    delay(20);
    degreesMoved++;
  }
  
  while (currentPosition != targetPosition) {
    currentPosition += (currentPosition < targetPosition) ? 1 : -1;
    servos[servoIndex].write(currentPosition);
    delay(50);
  }
  
  currentPositions[servoIndex] = targetPosition;
}

void moveServosTogether(int servoIndex1, int targetPosition1, int servoIndex2, int targetPosition2) {
  int pos1 = currentPositions[servoIndex1], pos2 = currentPositions[servoIndex2];
  int distanceToTarget1 = abs(targetPosition1 - pos1), distanceToTarget2 = abs(targetPosition2 - pos2);
  int degreesMoved1 = 0, degreesMoved2 = 0;

  while (pos1 != targetPosition1 || pos2 != targetPosition2) {
    if (degreesMoved1 < 10 || degreesMoved2 < 10) {
      if (pos1 != targetPosition1) {
        pos1 += (targetPosition1 > pos1) ? 1 : -1;
        servos[servoIndex1].write(pos1);
      }
      if (pos2 != targetPosition2) {
        pos2 += (targetPosition2 > pos2) ? 1 : -1;
        servos[servoIndex2].write(pos2);
      }
      delay(50);
    } else if (degreesMoved1 < distanceToTarget1 - 10 || degreesMoved2 < distanceToTarget2 - 10) {
      if (pos1 != targetPosition1) {
        pos1 += (targetPosition1 > pos1) ? 1 : -1;
        servos[servoIndex1].write(pos1);
      }
      if (pos2 != targetPosition2) {
        pos2 += (targetPosition2 > pos2) ? 1 : -1;
        servos[servoIndex2].write(pos2);
      }
      delay(20);
    } else {
      if (pos1 != targetPosition1) {
        pos1 += (targetPosition1 > pos1) ? 1 : -1;
        servos[servoIndex1].write(pos1);
      }
      if (pos2 != targetPosition2) {
        pos2 += (targetPosition2 > pos2) ? 1 : -1;
        servos[servoIndex2].write(pos2);
      }
      delay(50);
    }
    degreesMoved1++;
    degreesMoved2++;
  }

  currentPositions[servoIndex1] = pos1;
  currentPositions[servoIndex2] = pos2;
}

void printServoPositions() {
  Serial.print("Current Positions: ");
  for (int i = 0; i < 13; i++) {
    Serial.print("s" + String(i + 1) + ": " + String(currentPositions[i]));
    if (i < 12) Serial.print(", ");
  }
  Serial.println();
}
