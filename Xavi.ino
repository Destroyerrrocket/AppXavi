// Licenciat sota la GPLv3

#include <SoftwareSerial.h>
#include <Servo.h>

char accio;
int speed = 0;
int ang = 90;

// declaració de bluetooth i servo
Servo motor;
SoftwareSerial blue (2, 3);

// bluetooth config
char NOMBRE[21] = "ElPolLoPeta.RTFM.<3 ";
char BPS = '4';
char PASS[5] = "1234";

void setup()
{
  blue.begin(9600);

  blue.print("AT");
  delay(1000);

  blue.print("AT+NAME");
  blue.print(NOMBRE);
  delay(1000);

  blue.print("AT+BAUD");
  blue.print(BPS);
  delay(1000);

  blue.print("AT+PIN");
  blue.print(PASS);
  delay(1000);
  motor.attach(9, 600, 2400); // us poso el pin que toca https://www.arduino.cc/en/Reference/ServoAttach
  blue.begin(9600);
}

void loop()
{
  if (blue.available() >= 2) //llegir per saber què fer
  {
    accio = blue.read();          //què farem
    speed = intensity(blue.read()); //a quina velocitat
  }
  switch (accio)
  {
    case 'f': // cap endavant
      motor.write(speed);
    case 'b': // cap enrere
      motormotor.write(-1 * speed);
    default: // pot ser que no haguem rebut res. Farem res.
      break;
  }
  delay(1000); // temps per a que el bluetooth parli i no ens avancem a ell. Això és una suposició del Pol
}

int intensity (char blueRead)
{
  switch (blueRead)
  {
    case 'a': // si revem a, és que vol anar to fast to furius
      return 80;
    case 'b': // si revem b... no
      return 10;
    default:
      return 0;
  }
  return 0; // no arrivarem aquí, però per costum, 0
}
