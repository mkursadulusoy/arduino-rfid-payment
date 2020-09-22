void lcd_hosgeldinYazisi()
{
lcd.setCursor(2,0);
lcd.print("Oguzcan Eglence");
lcd.setCursor(6,1);
lcd.print("Merkezine");
lcd.setCursor(5,2);
lcd.print("Hosgeldiniz");
lcd.setCursor(1,3);
lcd.print("Karti Yerlestirin");
delay(2000);
}


  void lcd_karsilamaEkrani()
  {
lcd.clear();
Serial.println("Yapılacak İşlem");
Serial.println("A:Bakiye Yüklemek");
Serial.println("B:Bakiye Bilgisini Öğrenmek");
Serial.println("C:Günlük Yükleme Miktarını Öğrenmek");
lcd.setCursor(0,0);
lcd.print("A Bakiye Yukleme");
lcd.setCursor(0,1);
lcd.print("B Bakiye Ogrenme");
lcd.setCursor(0,2);
lcd.print("C Ciro Ogrenme");
lcd.setCursor(0,3);
lcd.print("D Ciro Temizleme");
}


    void lcd_yuklenecekKontorGirin()
    {
lcd.clear();
lcd.setCursor(1,0);
lcd.print("Yuklenecek kontor");
lcd.setCursor(2,1);
lcd.print("miktarini girin");
       }

       void lcd_yazmabasarisiz()
       {
                lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Yazma Basarisiz");
        lcd.setCursor(0,1);
        lcd.print("Karti Kaldirip");
        lcd.setCursor(0,2);
        lcd.print("Tekrar Deneyin");
        
        }


   void lcd_ToplamCiro()
       {
int cironekadar=0;

for (int i=18;i<EEPROM.length();i++)
{cironekadar=cironekadar+EEPROM.read(i);}
        
                lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Toplam Yuklenen Para");
        lcd.setCursor(0,1);
        lcd.print(cironekadar);
        }

        void lcd_ciroSilinecek(){
          
          lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Bu islem kayitli");
        lcd.setCursor(0,1);
        lcd.print("tum ciroyu silecek");
        lcd.setCursor(0,2);
        lcd.print("devam icin # kare");
        lcd.setCursor(0,3);
        lcd.print("iptal icin * yildiz");
          
          
          }


        
