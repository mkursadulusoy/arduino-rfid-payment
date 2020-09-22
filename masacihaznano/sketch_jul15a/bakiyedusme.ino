void bakiyedusme(){// Kart yoksa bekle
    if ( ! mfrc522.PICC_ReadCardSerial())
         return;
 // Bazı kart bilgilerini gösterelim.TODO silinecek.
    Serial.print(F("UID:")); // Kartın UID bilgisi
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
int cironekadar=0;

for (int i=5;i<EEPROM.length();i++)
{cironekadar=cironekadar+EEPROM.read(i);}
        
                lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Toplam Okunan Bakiye");
        lcd.setCursor(0,1);
        lcd.print(cironekadar);
        delay(3000);

}}}
}


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
lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Ciro Siliniyor");

 for (int i=5;i<EEPROM.length();i++)
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
        digitalWrite(2,HIGH);
    delay(100);
    digitalWrite(2,LOW);
    delay(100);
     digitalWrite(2,HIGH);
    delay(100);
    digitalWrite(2,LOW);
        delay(3000);
}
}}}



    
    Serial.println();
    MFRC522::PICC_Type piccType = mfrc522.PICC_GetType(mfrc522.uid.sak);

    // Uyumlu kartları kontrol et.
    if (    piccType != MFRC522::PICC_TYPE_MIFARE_MINI
        &&  piccType != MFRC522::PICC_TYPE_MIFARE_1K
        &&  piccType != MFRC522::PICC_TYPE_MIFARE_4K) {
        Serial.println(F("Geçersiz kart"));
lcd.clear(); 
    lcd.setCursor(0,0);
lcd.print("Gecersiz kart");
        return;
    }
byte sector         = 1; //1. sektörü kullanacağız
byte blockAddr      = 4; //4.bloğu kullanacağız
byte trailerBlock   = 7;
MFRC522::StatusCode status;
byte size = sizeof(buffer);

byte block=0;
  //Serial.println(F("Authenticating using key A..."));
  status = mfrc522.PCD_Authenticate(MFRC522::PICC_CMD_MF_AUTH_KEY_A, block, &key, &(mfrc522.uid));
  if (status != MFRC522::STATUS_OK) {
    Serial.print(F("PCD_Authenticate() failed: "));
    Serial.println(mfrc522.GetStatusCodeName(status));
    return;
  }


    
  // şu anda tüm sektörde ne yazıyor
    Serial.println(F("Sektörün şu anki değerleri:"));
    mfrc522.PICC_DumpMifareClassicSectorToSerial(&(mfrc522.uid), &key, sector);
    Serial.println();
    status = (MFRC522::StatusCode) mfrc522.MIFARE_Read(blockAddr, buffer, &size);
    if (status != MFRC522::STATUS_OK) {
        Serial.print(F("MIFARE_Read() failed: "));
        Serial.println(mfrc522.GetStatusCodeName(status));
    }


dump_byte_array(buffer, 16); Serial.println();
  karttabulunan=hexToDec(byteArray[4]);
  guvenlikKolonuBir=hexToDec(byteArray[5]);
guvenlikKolonuIki=hexToDec(byteArray[6]);
int kartidsibir=hexToDec(byteArray[0]);

int kontrolsonuc=(guvenlikKolonuBir+guvenlikKolonuIki)-kartidsibir;
int donecek=karttabulunan-1;

if (kontrolsonuc==karttabulunan && karttabulunan>0)
{Serial.println("Güvenlik doğrulama sağlandı");


dataBlock[0]    = hexToDec(byteArray[0]);
dataBlock[1]    = hexToDec(byteArray[1]);
dataBlock[2]    = hexToDec(byteArray[2]);
dataBlock[3]    = hexToDec(byteArray[3]);
dataBlock[4]    = donecek;
int guvenliksayisi=hexToDec(byteArray[0])+donecek;
guvenlikKolonuBir=0;
guvenlikKolonuIki=0;
if(guvenliksayisi>255)
{guvenlikKolonuBir=255;
guvenlikKolonuIki=guvenliksayisi-255;
  }
 else
 {guvenlikKolonuBir=guvenliksayisi;}
dataBlock[5]    =guvenlikKolonuBir;
dataBlock[6]    =guvenlikKolonuIki;
 status = (MFRC522::StatusCode) mfrc522.MIFARE_Write(blockAddr, dataBlock, 16);
    if (status != MFRC522::STATUS_OK) {
        Serial.print(F("Karta yazma başarısız. "));
        Serial.println(mfrc522.GetStatusCodeName(status));

    }
    else
    {Serial.println("Karta yazma işlemi başarıyla gerçekleştirildi.");
    Serial.print("Yeni bakiye: ");Serial.println(donecek);
}


     lcd.clear(); 
    lcd.setCursor(0,0);
lcd.print(karttabulunan);
    digitalWrite(2,HIGH);
    digitalWrite(8,LOW);
    delay(1000);
    digitalWrite(2,LOW);
    digitalWrite(8,HIGH);
  delay(3000);
  
      for (int i=0;i<addr;i++){
int  value = EEPROM.read(i);
  enSonAdres=enSonAdres+value;
}


  EEPROM.write(enSonAdres, 1);
  for (int i=0;i<addr;i++)
  {
   int okunan=EEPROM.read(i);
   if(okunan==0)
   { int asilAdres=EEPROM.read(i-1);
    if (EEPROM.read(asilAdres)+1>255)
    {EEPROM.write(i, EEPROM.read(i)+1);}
    else
    {EEPROM.write(i-1, EEPROM.read(i-1)+1);}
    break;
    }
    }



}
else
{Serial.println("Kaçak yükleme tespit edildi.");
 lcd.clear(); 
    lcd.setCursor(0,0);
 if (karttabulunan==0)
 {lcd.print("Yetersiz Bakiye");}
  else
   {lcd.print("Kacak Yukleme");}
   digitalWrite(2,HIGH);
    delay(100);
    digitalWrite(2,LOW);
    delay(100);
     digitalWrite(2,HIGH);
    delay(100);
    digitalWrite(2,LOW);
    delay(100);
     digitalWrite(2,HIGH);
    delay(100);
    digitalWrite(2,LOW);
    delay(100);
  delay(3000);
 
}


  
  }
