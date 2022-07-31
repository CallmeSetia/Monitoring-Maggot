// 1 Lampu Tengah
// 2 POMPA 1
// 3 POMPA 2
// 4 POMPA 3
// 5 Kipas bawah
// 6 Kipas Tengah
// 7 Kipas Atas
// 8 Lampu Bawah
// 9 Lampu Atas

void Relay_Init() {
  for (int i = 0; i < 9; i++) {
    pinMode(pinRelay[i], OUTPUT);
    digitalWrite(pinRelay[i], HIGH);
  }
}
void LampuTengah_On() {
  Control_Relay(1, 1);
  relay_lampu[1] = 1;
}
void LampuTengah_Off() {
  Control_Relay(1, 0);
  relay_lampu[1] = 0;
}
void PompaAtas_On() {
  Control_Relay(2, 1);
  relay_pompa[0] = 1;
}
void PompaAtas_Off() {
  Control_Relay(2, 0);
  relay_pompa[0] = 0;
}
void PompaTengah_On() {
  Control_Relay(3, 1);
  relay_pompa[1] = 1;
}
void PompaTengah_Off() {
  Control_Relay(3, 0);
  relay_pompa[1] = 0;
}
void PompaBawah_On() {
  Control_Relay(4, 1);
  relay_pompa[2] = 1;
}
void PompaBawah_Off() {
  Control_Relay(4, 0);
  relay_pompa[2] = 0;
}
void KipasBawah_On() {
  Control_Relay(5, 1);
  relay_kipas[2] = 1;
}
void KipasBawah_Off() {
  Control_Relay(5, 0);
  relay_kipas[2] = 0;
}
void KipasTengah_On() {
  Control_Relay(6, 1);
  relay_kipas[1] = 1;
}
void KipasTengah_Off() {
  Control_Relay(6, 0);
  relay_kipas[1] = 0;
}
void LampuBawah_On() {
  Control_Relay(8, 1);
  relay_lampu[2] = 1;
}
void LampuBawah_Off() {
  Control_Relay(8, 0);
  relay_lampu[2] = 0;
}
void KipasAtas_On() {
  Control_Relay(9, 1);
  relay_lampu[0] = 1;
}
void KipasAtas_Off() {
  Control_Relay(9, 0);
  relay_lampu[0] = 0;
}

void Control_Relay(int num, int state) {
  int i = num - 1;
  if (state == 0) digitalWrite(pinRelay[i], HIGH);
  if (state == 1) digitalWrite(pinRelay[i], LOW);
}

void LoopTest_Relay() {
  for (int i = 0; i < 9; i++) {
    Serial.println("LOOP TEST RELAY UTAMA : " + String(i));
    digitalWrite(pinRelay[i], LOW);
    delay(1000);
    digitalWrite(pinRelay[i], HIGH);
    delay(1000);
  }
}
void Control_Pompa(int pompa, int state) {
  int i = pompa - 1;  // 1 - 1 = 0
  if (state == 1)  digitalWrite(pinRelay[i], LOW);
  if (state == 0)  digitalWrite(pinRelay[i], HIGH);
}
