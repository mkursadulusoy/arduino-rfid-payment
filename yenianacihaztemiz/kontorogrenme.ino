void kontorogrenme()

{ // Kart yoksa bekle
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

if (kontrolsonuc==karttabulunan)
{Serial.println("Güvenlik doğrulama sağlandı");
lcd.clear();
lcd.setCursor(0,0);
lcd.print("Bakiye:");
lcd.setCursor(7,0);
lcd.print(karttabulunan);


}
else
{Serial.println("Kaçak yükleme tespit edildi.");
lcd.clear();
lcd.setCursor(0,0);
lcd.print("Kacak Yukleme");
lcd.setCursor(0,1);
lcd.print("tespit edildi");
}


    
  
  }
