#include <SoftwareSerial.h> // 引用程式庫

// 定義連接藍牙模組的序列埠
SoftwareSerial BTSerial(10,11); //RX TX

void setup() {
  Serial.begin(9600);
  Serial.println("Enter AT commands");
  BTSerial.begin(38400);  //藍芽模組傳輸速度
  pinMode(9,OUTPUT);
}
const byte LED_PIN = 9;
char var;
void loop() {
  if (BTSerial.available()) {
    var=BTSerial.read();
    Serial.print(var);
    if (var == '2') {
      digitalWrite(LED_PIN, HIGH);
      // 回應命令發送端，告知「已開燈」
      //BTSerial.println("LED ON");
    } 
    else if (var == '1') {
      digitalWrite(LED_PIN, LOW);
      // 回應命令發送端，告知「已關燈」
      //BTSerial.println("LED OFF");
    }
  }
}
