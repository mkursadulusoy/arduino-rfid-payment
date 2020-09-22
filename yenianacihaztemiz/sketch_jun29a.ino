



/*Kütüphane Tanımlamaları*/
#include <SPI.h>
#include <MFRC522.h>
#include <LiquidCrystal_I2C.h>
#include <Wire.h>
#include <Keypad.h>
#include <EEPROM.h>

/*Global Değişkenler*/
byte buffer[18]     ={0};
byte dataBlock[16];
String keypaddenGiren="";
String uid;
String gecici;
String byteArray[16];
char keypadkey;
int karttabulunan=0;
int guvenlikKolonuBir=0;
int guvenlikKolonuIki=0;
int ciroToplam=0;
int addr = 18; //EEPROM adreslerinde son kalınan yeri belirlemek için kullanılacak.
int enSonAdres=0;
/*Donanım Tanımlamaları*/
#define RST_PIN         5           // RFID okuyucu RST pin
#define SS_PIN          53          // RFID okuyucu SS pin
MFRC522 mfrc522(SS_PIN, RST_PIN);   // Kart okuyucu başlat
MFRC522::MIFARE_Key key;  //TODO:keyleri araştır. güvenlik için kullan

LiquidCrystal_I2C lcd(0x27,20,4);  // set the LCD address to 0x27 for a 16 chars and 2 line display

const byte ROWS = 4; //four rows
const byte COLS = 4; //four columns
char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
byte rowPins[ROWS] = {32, 33, 34, 35}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {36, 37, 38, 39}; //connect to the column pinouts of the keypad
Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );




void setup() {
Serial.begin(9600);
lcd.init();                     
lcd.backlight();
lcd_hosgeldinYazisi();
Serial.println("İşlemler hazır.");
SPI.begin();        // Init SPI yolunu başlat
mfrc522.PCD_Init(); // Kart okuyucuyu başlat
CardSecurityKeyOlustur();

}

void loop() {
// Kart okutulana kadar başka bir işlem yapılmayacak
if ( ! mfrc522.PICC_IsNewCardPresent())
   {return;}
lcd_karsilamaEkrani();

//Keypadden Tuşa Basılana Kadar Bekle
keypadkey = keypad.getKey();
while(!keypadkey){
  keypadkey = keypad.getKey();
  if (keypadkey)
  {break;}
  }
  Serial.println(keypadkey);
if (keypadkey=='A')
{ 
  bakiyeyukleme();
}
if (keypadkey=='B')
{
  kontorogrenme();
}
if (keypadkey=='C')
{
  ciroogrenme();
}
if (keypadkey=='D')
{
  cirosil();
}
  
mfrc522.PICC_HaltA(); // Halt PICC
mfrc522.PCD_StopCrypto1();  // Stop encryption on PCD
//Loop bitince kart okumayı devre dışı bırakalım ki yeni kart ile yeni işlemler tekrar başlayabilsin.
}
