#include <LiquidCrystal_I2C.h>
#include <SPI.h>
#include <MFRC522.h>
#include <EEPROM.h>

byte buffer[18]     ={0};
int karttabulunan=0;
String byteArray[16];
int guvenlikKolonuBir=0;
int guvenlikKolonuIki=0;
String uid;
String gecici;
byte dataBlock[16];
int addr = 5; //EEPROM adreslerinde son kalınan yeri belirlemek için kullanılacak.
int enSonAdres=0;


#define RST_PIN         9           // RFID okuyucu RST pin
#define SS_PIN          10          // RFID okuyucu SS pin
MFRC522 mfrc522(SS_PIN, RST_PIN);   // Kart okuyucu başlat
MFRC522::MIFARE_Key key;  //TODO:keyleri araştır. güvenlik için kullan

LiquidCrystal_I2C lcd(0x27,16,2);  // set the LCD address to 0x27 for a 16 chars and 2 line display LCD yüklemesi

void setup()
{
  Serial.begin(9600);
  SPI.begin();        // Init SPI yolunu başlat
mfrc522.PCD_Init(); // Kart okuyucuyu başlat
CardSecurityKeyOlustur();
  pinMode(2,OUTPUT);
  pinMode(8,OUTPUT);
  lcd.init();                     
lcd.backlight();
digitalWrite(8,HIGH);
}

void loop()

{
    // Kart okutulana kadar başka bir işlem yapılmayacak
if ( ! mfrc522.PICC_IsNewCardPresent())
   {lcd.clear(); 
    lcd.setCursor(0,0);
lcd.print("Karti Okutunuz");
Serial.println("kartyok");
    return;

   }
lcd.clear(); 
    lcd.setCursor(0,0);
lcd.print("Kart Okundu");
Serial.println("kartvar");
  bakiyedusme();
  mfrc522.PICC_HaltA(); // Halt PICC
mfrc522.PCD_StopCrypto1();  // Stop encryption on PCD
}
