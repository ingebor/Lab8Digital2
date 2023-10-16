//Universidad del Valle de Guatemala
//BE3015 - Electrónica Digital 2
//Ayleen Rubio 19003
//Laboratorio No 8

//Librerias
#include <SPI.h>
#include <SD.h>

//Variables globales
File camara;
File reloj;
File telefono;
File miArte;
String linea = "";

int seleccion = 0;

//Configuracion
void setup() {
  // Open serial communications and wait for port to open:
  Serial.begin(115200);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for Leonardo only
  }
  SPI.setModule(0);


  Serial.print("Initializing SD card...");
  // On the Ethernet Shield, CS is pin 4. It's set as an output by default.
  // Note that even if it's not used as the CS pin, the hardware SS pin
  // (10 on most Arduino boards, 53 on the Mega) must be left as an output
  // or the SD library functions will not work.
  pinMode(12, OUTPUT);

  if (!SD.begin(12)) {
    Serial.println("initialization failed!");
    return;
  }
  Serial.println("initialization done.");

}

//Loop principal
void loop() {
  // put your main code here, to run repeatedly: 
  Serial.println("\n¿Que desea hacer?: \n1. Ver camara \n2. Ver reloj \n3. Ver telefono \n4. Ver imagen de usuario \n5. Ingresar arte");
  while (1)
  {
    seleccion = Serial.read();
    if (seleccion == '1' || seleccion == '2' || seleccion == '3' || seleccion == '4' || seleccion == '5')
      break;
  }
  
  //Mostrar la primera imagen
  while (seleccion == '1')
  {
    camara = SD.open("camara.txt");
    if (camara) {
      Serial.println("\ncamara.txt:");
  
      // read from the file until there's nothing else in it:
      while (camara.available()) {
        Serial.write(camara.read());
      }
      // close the file:
      camara.close();
    } else {
      // if the file didn't open, print an error:
      Serial.println("error opening camara.txt");
    }
    seleccion = 0;
  }

  //Mostrar la segunda imagen
  while (seleccion == '2')
  {
    reloj = SD.open("reloj.txt");
    if (reloj) {
      Serial.println("\ntest.txt:");
  
      // read from the file until there's nothing else in it:
      while (reloj.available()) {
        Serial.write(reloj.read());
      }
      // close the file:
      reloj.close();
    } else {
      // if the file didn't open, print an error:
      Serial.println("error opening reloj.txt");
    }
    seleccion = 0;
  }

  //Mostrar la tercera imagen
  while (seleccion == '3')
  {
    telefono = SD.open("telefono.txt");
    if (telefono) {
      Serial.println("\ntelefono.txt:");
  
      // read from the file until there's nothing else in it:
      while (telefono.available()) {
        Serial.write(telefono.read());
      }
      // close the file:
      telefono.close();
    } else {
      // if the file didn't open, print an error:
      Serial.println("error opening telefono.txt");
    }
    seleccion = 0;
  }

  //Mostrar la imagen ingresada por el usuario
  while (seleccion == '4')
  {
    miArte = SD.open("miArte.txt");
    if (miArte) {
      Serial.println("\nmiArte.txt:");
  
      // read from the file until there's nothing else in it:
      while (miArte.available()) {
        Serial.write(miArte.read());
      }
      // close the file:
      miArte.close();
    } else {
      // if the file didn't open, print an error:
      Serial.println("error opening miArte.txt");
    }
    seleccion = 0;
  }

  //Ingresar una imagen de parte del usuario
  while (seleccion == '5')
  {
    Serial.print("Ingrese su arte, presione enter para cambiar de linea y 0 para salir");
    //Ingresar el ascii art
    while(1){
        if(Serial.available()>0)
        {
          char ingresado = Serial.read();
          if(ingresado == '0')
          {
            break;
          }
          else
          {
            linea+=ingresado;
          }
        }
        delay(100);
      }
    // open the file. note that only one file can be open at a time,
    // so you have to close this one before opening another.
    miArte = SD.open("miArte.txt", FILE_WRITE);
    // if the file opened okay, write to it:
    if (miArte) {      
      Serial.println("Escribiendo...");
      Serial.println(linea);
      miArte.println(linea.c_str());

      // close the file:
      miArte.close();
      Serial.println("\ndone.");
    } else {
      // if the file didn't open, print an error:
      Serial.println("error opening miArte.txt");
    }
    seleccion = 0;
  }
}
