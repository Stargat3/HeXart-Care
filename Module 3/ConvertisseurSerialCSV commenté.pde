//From Arduino to Processing to Txt or cvs etc.
//https://learn.sparkfun.com/tutorials/connecting-arduino-to-processing/all

//import
import processing.serial.*; //   Class for sending and receiving data using the serial communication protocol.

//declare
PrintWriter output; // Permet d'imprimer dans un flux de sortie texte
Serial udSerial; // The serial port --> udSerial // Create object from Serial class

void setup() { // Configuration, initialisation(s)// we’re going to find the serial port our Arduino is connected to and set up our Serial object to listen to that port.
  udSerial = new Serial(this, Serial.list()[0], 9600); // // Open the port you are using at the rate you want:
  output = createWriter ("Battements.csv"); //output est assigné à la création d'un nouveau fichier de sortie : "Battements.csv" 
}

void draw() { // Fonction draw (écriture des informations dans le fichier) instead of loop
// reply only when you receive data
    if (udSerial.available() > 0) { 
      String SenVal = udSerial.readString(); // création de la chaîne de caractère SenVal prenant la valeur --> Serial.readString() reads characters from the serial buffer into a string.
      if (SenVal != null) { // condition --> Si la chaîne de caractère est non nul -->
        output.println(SenVal);//Prints data to the serial port as human-readable ASCII text followed by a carriage return character (ASCII 13, or '\r') and a newline character (ASCII 10, or '\n').
      }
    }
  }

void keyPressed(){ // Fonction keyPressed (dernière vérifications avant fermeture du fichier et du programme)
    output.flush(); // Writes the remaining data to the file
    output.close(); // Finishes the file
    exit(); // Stops the program
  }
