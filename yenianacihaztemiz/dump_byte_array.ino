/* Kartın değerlerini görmek için fonksiyon.*/
void dump_byte_array(byte *buffer, byte bufferSize) {
  uid="";
  gecici="";
for (byte i = 0; i < bufferSize; i++) {
if (buffer[i] < 0x10)
{Serial.print(" 0");
uid+=" 0";}
else
{Serial.print(" ");
uid+=" ";}
Serial.print(buffer[i], HEX);  
String gecici=String(buffer[i], HEX);
uid+=gecici; 
}
 if(uid.substring(0,1)==" ")
{uid.remove(0,1);}
int j=0;
int k=2;
for (int i=0;i<bufferSize;i++)
{
  byteArray[i]=uid.substring(j,k);
  j=j+3;
  k=k+3; 
}

}
/* Kartın değerlerini görmek için fonksiyon.*/
