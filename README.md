Wireless Snail Mail Notifier
==============
Get snail mail notifications automatically with an arduino, ethernet shield, TP-Link 703N and a snap action switch.  

**Overview** 
This project was inspired by Matt Richardson's Snail Mail Push Alerts project: http://blog.makezine.com/2010/12/29/snail-mail-push-alerts/

An arduino with ethernet shield is wired to a snap action switch installed outside in the mailbox. The arduino is plugged directly into a TP-Link 703N router that has been modified to work as a wireless client.

The sketch on the arduino is designed to check if the mailbox is open or not. If the box is opened, it will send two things:
- push notification to iOS app Prowl (done with Avviso library on the arduino). This can also be configured to work with Android.
- email to end user (done with php code - this can be easily found on the web)

The arduino will then wait 5 minutes and check again. If the mailbox is still open, it will send out the two notifications again. It will repeat this 5 times and then stop. 

The reason the 5 minute delay is in the event that the mailbox is open for longer than a few seconds or opened and closed several times while mail is being inserted. Plus, the 5 emails in a row are a nice way to know if a pakage or large envelope has been delivered.

The arduino will also turn a green LED on to indicate the mailbox has been opened. This is a great visual cue for when you're around but haven't checked email or device notifications lately. 

To reset the device for the next day, simply hit the reset button. 

**tutorial & photos**
http://www.shatteredhaven.com/2013/01/1392365-wireless-arduino-snail-mail.html

**Software Used**
- Avviso library
- Ethernet library
- some misc php code for email notifications

**Files**
- SnailMailNotifier.ino - arduino sketch
- SnailMailNotifier.fzz - frizing schematic of arduino wiring
- Avviso library for arudino

**Materials Used**
- Arduino Uno
- Ethernet Shield (common shield that uses W5100 chip)
- a snap action switch
- mini breadboard
- 10K resistor (2?)
- TP-Link 703N router
- misc wires

**Notes**
The TP-Link 703N took me awhile to configure. This instructables really helped: http://www.instructables.com/id/How-to-set-up-OpenWRT-on-a-pocket-router-WR703N/
Specifically this document for setting up the device to connect via WiFi and pass the connection to the ethernet jack: https://www.dropbox.com/sh/ity5ho0jq3vwq4l/KoV1O95wvZ/Digest%20WR703N%20setup/02%20Network%20WiFi/_WiFi/_wifi%20client%20setup/example%20setup%20WiFi%20client%20and%20internet%20connection%20transfer%20to%20eth0.txt