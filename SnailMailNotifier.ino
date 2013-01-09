/*
  Adapted from: Snail Mail Push Alerts by Matt Richardson
  Additional library required: Avviso - http://avvisoapp.com/
    this example is designed to work with Prowl on iOS but can be modified to work the Android app "Notify My Android". 
 */

#include <SPI.h>
#include <Ethernet.h>
#include <HTTPClient.h>
#include <Avviso.h>

#define switchPin 7  // Snap action switch which closes when the mailbox door is opened.
int MailLED = 9; 
int count = 0; //counter

byte mac[] = {  0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };
byte ip[] = { 192,168,XXX,XXX }; // local Arduino IP
char serverName[] = "WEBSITE.COM"; // IP of your web server

EthernetClient client;

void setup() 
{
  Ethernet.begin(ip);
  Serial.begin(9600);

  Serial.println("begin mail notifier");

  pinMode(switchPin, INPUT);
  pinMode(MailLED, OUTPUT);

  delay(1000);

  Avviso.begin(); 
  Avviso.setApiKey("API KEY FROM PROWL"); //API key from Prowl
  Avviso.setApplicationName("Snail Mail Notifier");
}

void loop()
{
  if ((digitalRead(switchPin) == LOW) && count<5) // if mailbox is opened, check count and increase by 1
  {
      digitalWrite(MailLED, HIGH);
      Serial.println("Mailbox door opened");
      Avviso.push("New event", "Mail has arrived!", 0);
  if (client.connect(serverName, 80)) //connect to server
   { 
       Serial.println("connected to server");
       client.println("GET WEBSITE.COM/php"); //location of ProwlPHP script
       client.println();
       //delay(60000); //delay 1 minute
       delay(300000); //delay 5 minutes
    if (digitalRead(switchPin) == LOW)
    {
       count++;       
       Serial.println(count);
    }
 } 
if (count>=5) 
   {
    Serial.println("exceed maximum requests"); //print in serial monitor that exceed max amount. Need to hit reset button
    delay(1000);  
   }  
  }
}  

