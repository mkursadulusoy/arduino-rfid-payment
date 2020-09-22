 void bakiyeyukleme(){
 // Kart yoksa bekle
    if ( ! mfrc522.PICC_ReadCardSerial())
         return;
 // Bazı kart bilgilerini gösterelim.TODO silinecek.
    Serial.print(F("UID:")); // Kartın UID bilgisi
    dump_byte_array(mfrc522.uid.uidByte, mfrc522.uid.size);// Kartın UID bilgisi
    Serial.println();
    MFRC522::PICC_Type piccType = mfrc522.PICC_GetType(mfrc522.uid.sak);

    // Uyumlu kartları kontrol et.
    if (    piccType != MFRC522::PICC_TYPE_MIFARE_MINI
        &&  piccType != MFRC522::PICC_TYPE_MIFARE_1K
        &&  piccType != MFRC522::PICC_TYPE_MIFARE_4K) {
        Serial.println(F("Geçersiz kart"));
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Gecersiz Kart");
        return;
    }
byte sector         = 1; //1. sektörü kullanacağız
byte blockAddr      = 4; //4.bloğu kullanacağız
byte trailerBlock   = 7;
MFRC522::StatusCode status;
byte size = sizeof(buffer);

    //databloğu içine standart olarak 0 dolduruyoruz1
for (byte i = 0; i < 16; i++) 
{
   dataBlock[i] = 0x00;
}


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

Serial.println("Yüklenecek kontör bekleniyor.");
lcd_yuklenecekKontorGirin();
keypaddenGiren="";
keypadkey = keypad.getKey();
while(keypadkey!='A'){
  keypadkey = keypad.getKey();
  int satirnumarasi=0;
  if (keypadkey && keypadkey!='A')
  {keypaddenGiren=keypaddenGiren+keypadkey;
      lcd.setCursor(satirnumarasi,3);
    lcd.print(keypaddenGiren);
    satirnumarasi++;}
  }
byte donecek=keypaddenGiren.toInt();
int ciroya=donecek;

//Önce kartın içi okunacak ve mevcut bakiye bulunacak
dump_byte_array(buffer, 16); Serial.println();
  karttabulunan=hexToDec(byteArray[4]);
  Serial.print("Cihaz içinde bulunan bakiye: ");Serial.println(karttabulunan);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Mevcut Bakiye:");
    lcd.setCursor(15,0);
    lcd.print(karttabulunan);
donecek=donecek+karttabulunan;
dump_byte_array(mfrc522.uid.uidByte, mfrc522.uid.size);// Kartın UID bilgisi

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
lcd_yazmabasarisiz();
    }
    else
    {Serial.println("Karta yazma işlemi başarıyla gerçekleştirildi.");
    Serial.print("Yeni bakiye: ");Serial.println(donecek);
     lcd.setCursor(0,1);
    lcd.print("Yeni Bakiye:");
    lcd.setCursor(13,1);
    lcd.print(donecek);
    ciroToplam=ciroToplam+ciroya;
      for (int i=0;i<addr;i++){
int  value = EEPROM.read(i);
  enSonAdres=enSonAdres+value;
}
  
  
  EEPROM.write(enSonAdres, ciroya);
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




 }
