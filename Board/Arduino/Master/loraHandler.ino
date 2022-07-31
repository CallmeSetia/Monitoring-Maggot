#include <SPI.h>              // include libraries
#include <LoRa.h>

const int csPin = 53;          // LoRa radio chip select
const int resetPin = 11;       // LoRa radio reset
const int irqPin = 9;         // change for your board; must be a hardware interrupt pin

String outgoing;              // outgoing message

byte msgCount = 0;            // count of outgoing messages`
byte localAddress = 0xBB;     // address of this device
byte destination = 0xBA;      // destination to send to
long lastSendTime = 0;        // last send time
int interval = 2000;          // interval between sends

void Lora_Init() {
  Serial.println("LoRa Duplex Init");
  LoRa.setPins(csPin, resetPin, irqPin); // set CS, reset, IRQ pin

  if (!LoRa.begin(915E6)) {
    Serial.println("LoRa init failed. Check your connections.");
    while (true);
  }
  Serial.println("LoRa init succeeded.");
}

void Lora_KirimData(String outgoing) {

  // increment message ID
  LoRa.beginPacket();                   // start packet
  LoRa.write(destination);              // add destination address
  LoRa.write(localAddress);             // add sender address
  LoRa.write(msgCount);                 // add message ID
  LoRa.write(outgoing.length());        // add payload length
  LoRa.print(outgoing);                 // add payload
  LoRa.endPacket();                     // finish packet and send it
  msgCount++;

}
