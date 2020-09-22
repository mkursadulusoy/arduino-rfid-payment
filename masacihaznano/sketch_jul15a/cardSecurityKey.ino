void CardSecurityKeyOlustur(){
// iki kart için 2 adet güvenlik anahtarı oluştur.
//  FFFFFFFFFFFFh fabrika çıkışında bu kod var. değiştirelim TODO
   key.keyByte[0] = 0xff;
   key.keyByte[1] = 0xff;
   key.keyByte[2] = 0xff;
   key.keyByte[3] = 0xff;
   key.keyByte[4] = 0xff;
   key.keyByte[5] = 0xff;
}
