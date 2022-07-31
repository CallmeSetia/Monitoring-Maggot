//int pinPh[3] = {A3, A4, A5};
//float calibration_value[3] = {21.34 + 4.0, 21.34 + 4.0, 21.34 + 4.0};
//int phval[3] = {0, 0, 0};
//unsigned long int avgval[3];
//int buffer_arr[10], buffer_arr2[10], buffer_arr3[10];
//int temp[3];
//
//void bacaPh() {
//  Serial.println("Ph 1 = " + String(getPh(pinPh[0], calibration_value[0], avgval[0], temp[0], buffer_arr)));
//  Serial.println("Ph 2 = " + String(getPh(pinPh[1], calibration_value[1], avgval[1], temp[1], buffer_arr2)));
//  Serial.println("Ph 3 = " + String(getPh(pinPh[2], calibration_value[2], avgval[2], temp[2], buffer_arr3)));
//  //  Serial.println("Ph 1 = " + String(getPh(pinPh[0])));
//  //  Serial.println("Ph 2 = " + String(getPh(pinPh[1])));
//  //  Serial.println("Ph 3 = " + String(getPh(pinPh[2])));
//  delay(1000);
//}
//float getPh(int SensorPin, float cal_value, unsigned long int avg_value, int temp_value, int buffer_arrFun[]) {
//  for (int i = 0; i < 10; i++) {
//    buffer_arrFun[i] = analogRead(SensorPin);
//    delay(30);
//  }
//  for (int i = 0; i < 9; i++)
//  {
//    for (int j = i + 1; j < 10; j++)
//    {
//      if (buffer_arrFun[i] > buffer_arrFun[j])
//      {
//        temp_value = buffer_arrFun[i];
//        buffer_arrFun[i] = buffer_arrFun[j];
//        buffer_arrFun[j] = temp_value;
//      }
//    }
//  }
//  avg_value = 0;
//  for (int i = 2; i < 8; i++)
//    avg_value += buffer_arrFun[i];
//  float volt = (float)avg_value * 5.0 / 1024 / 6;
//  float ph_act = -5.70 * volt + cal_value;
//  return ph_act;
//}
////float getPh(int _sensor_pin) {
////  int adcPH = analogRead(_sensor_pin);
////  float voltage = adcPH * 5.0 / 1022;
////  return (6.4516 * voltage) - 5.7742;
////}

////===========================================================
//int pH_Value5 = A2;
//int pH_Value4 = A1;
int pH_Value3 = A5;
int pH_Value2 = A4;
int pH_Value1 = A3;

//float Voltage5;
//float Voltage4;
float Voltage3;
float Voltage2;
float Voltage1;

//float calibration_value5 = 24.04 - 1.2;
//float calibration_value4 = 24.04 - 0.3;
float calibration_value3 = 24.04 - 3.2; // bawah
float calibration_value2 = 24.04 - 2.1; // atas
float calibration_value1 = 24.04 - 2.9; // tengah

//int phval5 = 0;
//int phval4 = 0;
int phval3 = 0;
int phval2 = 0;
int phval1 = 0;


//unsigned long int avgval5;
//unsigned long int avgval4;
unsigned long int avgval3;
unsigned long int avgval2;
unsigned long int avgval1;

//int buffer_arr5[10], temp5;
//int buffer_arr4[10], temp4;
int buffer_arr3[10], temp3;
int buffer_arr2[10], temp2;
int buffer_arr1[10], temp1;

//float ph_act5;
//float ph_act4;
float ph_act3;
float ph_act2;
float ph_act1;

void ph_Init()
{
  //  pinMode(pH_Value5, INPUT);
  //  pinMode(pH_Value4, INPUT);
  pinMode(pH_Value3, INPUT);
  pinMode(pH_Value2, INPUT);
  pinMode(pH_Value1, INPUT);
}

void bacaPh()
{
  for (int i = 0; i < 10; i++)
  {
    //    buffer_arr5[i] = analogRead(pH_Value5);
    //    buffer_arr4[i] = analogRead(pH_Value4);
    buffer_arr3[i] = analogRead(pH_Value3);
    buffer_arr2[i] = analogRead(pH_Value2);
    buffer_arr1[i] = analogRead(pH_Value1);

    delay(30);
  }
  for (int i = 0; i < 9; i++)
  {
    for (int j = i + 1; j < 10; j++)
    {
      //      if (buffer_arr5[i] > buffer_arr5[j])
      //      {
      //        temp5 = buffer_arr5[i];
      //        buffer_arr5[i] = buffer_arr5[j];
      //        buffer_arr5[j] = temp5;
      //      }
      //
      //      if (buffer_arr4[i] > buffer_arr4[j])
      //      {
      //        temp4 = buffer_arr4[i];
      //        buffer_arr4[i] = buffer_arr4[j];
      //        buffer_arr4[j] = temp4;
      //      }

      if (buffer_arr3[i] > buffer_arr3[j])
      {
        temp3 = buffer_arr3[i];
        buffer_arr3[i] = buffer_arr3[j];
        buffer_arr3[j] = temp3;
      }

      if (buffer_arr2[i] > buffer_arr2[j])
      {
        temp2 = buffer_arr2[i];
        buffer_arr2[i] = buffer_arr2[j];
        buffer_arr2[j] = temp2;
      }

      if (buffer_arr1[i] > buffer_arr1[j])
      {
        temp1 = buffer_arr1[i];
        buffer_arr1[i] = buffer_arr1[j];
        buffer_arr1[j] = temp1;
      }
    }
  }
  //  avgval5 = 0;
  //  avgval4 = 0;
  avgval3 = 0;
  avgval2 = 0;
  avgval1 = 0;

  for (int i = 2; i < 8; i++) {
    //    avgval5 += buffer_arr5[i];
    //    avgval4 += buffer_arr4[i];
    avgval3 += buffer_arr3[i];
    avgval2 += buffer_arr2[i];
    avgval1 += buffer_arr1[i];
  }
  //  float volt5 = (float)avgval5 * 5.0 / 1024 / 6;
  //  float volt4 = (float)avgval4 * 5.0 / 1024 / 6;
  float volt3 = (float)avgval3 * 5.0 / 1024 / 6;
  float volt2 = (float)avgval2 * 5.0 / 1024 / 6;
  float volt1 = (float)avgval1 * 5.0 / 1024 / 6;

  //  ph_act5 = -5.70 * volt5 + calibration_value5;
  //  ph_act4 = -5.70 * volt4 + calibration_value4;
  ph_act3 = -5.70 * volt3 + calibration_value3;
  ph_act2 = -5.70 * volt2 + calibration_value2;
  ph_act1 = -5.70 * volt1 + calibration_value1;


  //  Serial.print("pH-5 Val: ");
  //  Serial.print(ph_act5);
  //  Serial.print(" pH-4 Val: ");
  //  Serial.print(ph_act4);
  ph_value[0] = ph_act2;
  ph_value[1] = ph_act1;
  ph_value[2] = ph_act3;

  if (DEBUG) {
    Serial.print("pH-3 Val: ");
    Serial.print(ph_act3);
    Serial.println();
    Serial.print("pH-2 Val: ");
    Serial.print(ph_act2);
    Serial.println();
    Serial.print("pH-1 Val: ");
    Serial.println(ph_act1);
    Serial.println();
  }

  //  pH_Value = analogRead(pH_Value);
  //  Voltage = (float) pH_Value * (5.0 / 1023.0);
  //  ph_act = -5.70 * Voltage + calibration_value;
  //  Serial.println(String(Voltage) + " - " + String(ph_act));

}
