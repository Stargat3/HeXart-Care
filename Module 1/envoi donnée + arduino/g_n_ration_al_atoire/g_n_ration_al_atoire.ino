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
  Serial.println(nombre);

  time = millis();

  Serial.println(time);
  delay(1000);

  /* Délai pour l'affichage */
  delay(500);
}
