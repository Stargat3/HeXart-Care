/** Fonction setup() */
unsigned long time;
void setup(){

  /* Initialise le port série pour le debug */
  Serial.begin(9600);

  /* Initialise le générateur de nombre aléatoire avec une graine aléatoire */
  randomSeed(analogRead(0));
}

/** Fonction loop() */
void loop(){

  /* Génére un nombre aléatoire entre 0 et 255 et l'affiche sur le port série */
  long nombre = random(70,90);
  time = millis();
  String info = String(nombre) + ';' + time + ' ';
  char texte[50];
  info.toCharArray(texte, 50);
  Serial.write(texte);
  delay(500);
}
