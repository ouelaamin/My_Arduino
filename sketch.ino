#include <Ethernet.h>

byte mac[] = {
  0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };
 
IPAddress ip(192,168,1,91);

int ledpin = 3;
int ldrpin = A1;
int value = 0;
int valeur = 0;

IPAddress server(192,168,1,90);

// Initialize the Ethernet server library
EthernetClient client;

void setup() {
 // Serial.begin starts the serial connection between computer and Arduino
  Serial.begin(9600);
 
 // start the Ethernet connection
  Ethernet.begin(mac,ip);
 
}

void loop()
{
  value = analogRead(ldrpin);
  value = constrain(value,100,1000);
  value = map(value,100,1000,255,0);
  int valeur = map(value,255,0,100,1000);

  Serial.println(valeur);
  analogWrite(ledpin, value);

/*
  Sending_To_phpmyadmindatabase(); 
  delay(30);
}


void Sending_To_phpmyadmindatabase() {
*/

  //value = analogRead(IR1); // Fill the sensorReading with the information from sensor
  //value2 = analogRead(IR2);
  // Connect to the server (your computer or web page) 
  if (client.connect(server, 3306)) {
 
    client.print("GET /write_data.php?"); // This
    client.print("valeur=");
    client.print(valeur);

    client.println(" HTTP/1.1"); // Part of the GET request
    client.println("Host: 192.168.1.90");
    client.println("Connection: close");
    client.println(); // Empty line
    client.println(); // Empty line
    client.stop();    // Closing connection to server

  }

  else {
    // If Arduino can't connect to the server (your computer or web page)
    Serial.println("--> connection failed\n");
    client.stop();
  }

  // Give the server some time to recieve the data and store it. I used 10 seconds here. Be advised when delaying. If u use a short delay, the server might not capture data because of Arduino transmitting new data too soon.
  //delay(1000);
}
