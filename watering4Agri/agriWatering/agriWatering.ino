int t_sensorPin = A0;     //アナログ0番ピンを指定
int t_sensorValue = 0;
int e_sensorPin = A1;
int e_sensorValue = 0;

void setup() {
  Serial.begin(9600);           //シリアルモニタ（9600）に表示する為の設定
  pinMode(13, OUTPUT);
  //pinMode(12, OUTPUT);
}
void loop() {
  t_sensorValue = analogRead(t_sensorPin);    //アナログ0番ピンからの入力値を取得
  float temp  = modTemp(t_sensorValue);     //温度センサーからの入力値を変換
  Serial.println("温度センサの値");
  Serial.println(temp);                   //結果をシリアルモニタに表示
  delay(500);
  e_sensorValue = analogRead(e_sensorPin);   //アナログ1番からの入力
  Serial.println("土壌センサの値");
  Serial.println(e_sensorValue);  //土壌センサの値をシリアルモニタに表示
  delay(500);

  //湿度判定で湿度が低いなら13番にLOW
  if (e_sensorValue < 100 && temp < 32) {
    Serial.println("----------------------->  dry");
    digitalWrite(13, HIGH);
    delay(500);
  } else {
    Serial.println("----------------------->  wet");
    digitalWrite(13, LOW);
    delay(500);
  }
}
//アナログ入力値を摂氏度℃に変換
float modTemp(int analog_val) {
  float v  = 3.3;     // 基準電圧値( V )
  float tempC = ((v * analog_val) / 1024) * 100; // 摂氏に換算
  return tempC;
}
