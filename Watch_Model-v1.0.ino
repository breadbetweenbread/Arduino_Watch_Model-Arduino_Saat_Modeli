int saat = 23;
int dakika = 59;
int saniye = 55;

unsigned long eski_zaman;
unsigned long yeni_zaman;

void sayac() {
  yeni_zaman = millis() / 1000;
  if (eski_zaman < yeni_zaman) {
    saniye++;
    eski_zaman = yeni_zaman;
  }

  if (saniye > 59) {
    dakika++;
    saniye = 0;
  } else if (dakika > 59) {
    saat++;
    dakika = 0;
    saniye = 0;
  } else if (saat > 23) {
    saat = 0;
    dakika = 0;
    saniye = 0;
  }
}

void setup() {
  Serial.begin(9600);
}

void loop() {
  sayac();

  
  Serial.print(saat);
  Serial.print(".");
  Serial.print(dakika);
  Serial.print(".");
  Serial.println(saniye);
}