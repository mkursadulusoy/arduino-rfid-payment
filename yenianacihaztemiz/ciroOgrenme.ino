void ciroogrenme(){
   // Kart yoksa bekle
    if ( ! mfrc522.PICC_ReadCardSerial())
         return;
dump_byte_array(mfrc522.uid.uidByte, mfrc522.uid.size);// Kartın UID bilgisi
if(hexToDec(byteArray[0])==79)
{  Serial.println("İLk kolon eşit");
delay(250);
if(hexToDec(byteArray[1])==32)
{Serial.println("ikinci kolon eşit");
delay(250);
if(hexToDec(byteArray[2])==179)
{Serial.println("üçüncü kolon eşit");
delay(250);
if(hexToDec(byteArray[3])==41)
{Serial.println("dördüncü kolon eşit");
lcd_ToplamCiro();

}}}
}
else
{ lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Lutfen Yetkili");
        lcd.setCursor(0,1);
        lcd.print("karti yerlestirin");}
  
  }


  void cirosil(){

     // Kart yoksa bekle
    if ( ! mfrc522.PICC_ReadCardSerial())
         return;
dump_byte_array(mfrc522.uid.uidByte, mfrc522.uid.size);// Kartın UID bilgisi
if(hexToDec(byteArray[0])==63)
{  Serial.println("İLk kolon eşit");
delay(250);
if(hexToDec(byteArray[1])==163)
{Serial.println("ikinci kolon eşit");
delay(250);
if(hexToDec(byteArray[2])==116)
{Serial.println("üçüncü kolon eşit");
delay(250);
if(hexToDec(byteArray[3])==41)
{Serial.println("dördüncü kolon eşit");
lcd_ciroSilinecek();
keypadkey = keypad.getKey();
while(!keypadkey){
  keypadkey = keypad.getKey();
  if (keypadkey)
  {break;}
  }
  if (keypadkey=='#')
{ 
 for (int i=18;i<EEPROM.length();i++)
 {if (EEPROM.read(i)!=0)
  {EEPROM.write(i, 0);}
  lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Kayitlar Siliniyor");
 }
 lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Ciro kayitlari");
        lcd.setCursor(0,1);
        lcd.print("tamamen silindi");
}
if (keypadkey=='*')
{
  loop();
}

}}}
}
else
{ lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Lutfen Yetkili");
        lcd.setCursor(0,1);
        lcd.print("karti yerlestirin");}
  
  }

  
