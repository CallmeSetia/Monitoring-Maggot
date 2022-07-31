// 1 POMPA ATAS UP
// 2 POMPA ATAS DOWN
// 3 POMPA TENGAH UP
// 4 POMPA TENGA DOWN
// 5 POMPA BAWAH UP
// 6 POMPA BAWAH DOWN

void PompaExt_Init() {
  for (int i = 0; i < 6; i++) {
    pinMode(pinRelayPompaExt[i], OUTPUT);
    digitalWrite(pinRelayPompaExt[i], HIGH);
  }
}

void LoopTest_Pompa() {
  for (int i = 0; i < 6; i++) {
    Serial.println("LOOP TEST RELAY POMPA : " + String(i));
    digitalWrite(pinRelayPompaExt[i], LOW);
    delay(4000);
    digitalWrite(pinRelayPompaExt[i], HIGH);
    delay(4000);
  }
}
void PompaAtasUp_On() {
  Control_PompaExt(1, 1);
  relay_pompaExt[0] = 1;
}
void PompaAtasUp_Off() {
  Control_PompaExt(1, 0);
  relay_pompaExt[0] = 0;
}
void PompaAtasDown_On() {
  Control_PompaExt(2, 1);
  relay_pompaExt[1] = 1;
}
void PompaAtasDown_Off() {
  Control_PompaExt(2, 0);
  relay_pompaExt[1] = 0;
}
void PompaTengahUp_On() {
  Control_PompaExt(3, 1);
  relay_pompaExt[2] = 1;
}
void PompaTengahUp_Off() {
  Control_PompaExt(3, 0);
  relay_pompaExt[2] = 0;
}
void PompaTengahDown_On() {
  Control_PompaExt(4, 1);
  relay_pompaExt[3] = 1;
}
void PompaTengahDown_Off() {
  Control_PompaExt(4, 0);
  relay_pompaExt[3] = 0;
}
void PompaBawahUp_On() {
  Control_PompaExt(5, 1);
  relay_pompaExt[4] = 1;
}
void PompaBawahUp_Off() {
  Control_PompaExt(5, 0);
  relay_pompaExt[4] = 0;
}
void PompaBawahDown_On() {
  Control_PompaExt(6, 1);
  relay_pompaExt[5] = 1;
}
void PompaBawahDown_Off() {
  Control_PompaExt(6, 0);
  relay_pompaExt[5] = 0;
}

void Control_PompaExt(int pompa, int state) {
  int i = pompa - 1;  // 1 - 1 = 0
  if (state == 1)  digitalWrite(pinRelayPompaExt[i], LOW);
  if (state == 0)  digitalWrite(pinRelayPompaExt[i], HIGH);
}
