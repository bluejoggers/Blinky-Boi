int rpin = 3;
int bpin = 5;
int gpin = 6;

void setup()
{
  pinMode(rpin, OUTPUT);
  pinMode(bpin, OUTPUT);
  pinMode(gpin, OUTPUT);
  Serial.begin(9600);    // sets up serial library baud rate to 9600
  Serial.println("Ready"); // prints ready
}

/**
 * @brief Function to control the LEDs.  
 * 
 * Modes:
 * @li 0 - off,
 * @li 1 - constant colour,
 * @li 2 - bloom to bright,
 * @li 3 - rainbow scroll (RGB),
 * @li 4 - rainbow scroll (natural),
 * @li 5 - blink in succession (Disco night).
 * 
 * @author Swastik Pal
 *
 * @param r the (max) intensity of the colour red
 * @param g the (max) intensity of the colour green
 * @param b the (max) intensity of the colour blue
 * @param mode the lighting method
 */

void LED_control(int r, int g, int b, int mode)
{

  switch (mode)
  {
  case 0: // off
    analogWrite(rpin, 0);
    analogWrite(gpin, 0);
    analogWrite(bpin, 0);
    break;

  case 1: // constant colour
    analogWrite(rpin, ((r * 255) / 10) % 255);
    analogWrite(gpin, ((g * 255) / 10) % 255);
    analogWrite(bpin, ((b * 255) / 10) % 255);
    break;

  case 2: // bloom to bright
    for (int i = 0; i <= 255; i += 5)
    {
      analogWrite(rpin, ((r * i) / 10) % 255);
      delay(50);
      analogWrite(gpin, ((g * i) / 10) % 255);
      delay(50);
      analogWrite(bpin, ((b * i) / 10) % 255);
      delay(50);
    }
    delay(321);
    break;

  case 3: // rainbow scroll (RGB)
    for (int i = 0; i <= ((r * 255) / 10) % 255; i += 5)
    {
      analogWrite(rpin, i);
      delay(500 / (r + 1));
    }
    analogWrite(rpin, 0);

    for (int i = 0; i <= ((g * 255) / 10) % 255; i += 5)
    {
      analogWrite(gpin, i);
      delay(500 / (g + 1));
    }
    analogWrite(gpin, 0);

    for (int i = 0; i <= ((b * 255) / 10) % 255; i += 5)
    {
      analogWrite(bpin, i);
      delay(500 / (b + 1));
    }
    analogWrite(bpin, 0);
    break;

  case 4: // rainbow scroll (natural)
    for (int i = 0; i <= ((r * 255) / 10) % 255; i += 5)
    {
      analogWrite(rpin, i);
      analogWrite(bpin, 255 - i);
      delay(500 / (r + 1));
    }
    analogWrite(bpin, 0);

    for (int i = 0; i <= ((g * 255) / 10) % 255; i += 5)
    {
      analogWrite(gpin, i);
      analogWrite(rpin, 255 - i);
      delay(500 / (g + 1));
    }
    analogWrite(rpin, 0);

    for (int i = 0; i <= ((b * 255) / 10) % 255; i += 5)
    {
      analogWrite(bpin, i);
      analogWrite(gpin, 255 - i);
      delay(500 / (b + 1));
    }
    analogWrite(gpin, 0);
    break;

  case 5: // blink in succession (Disco night)
    analogWrite(rpin, ((r * 255) / 10) % 255);
    delay(50);
    analogWrite(rpin, 0);
    analogWrite(gpin, ((g * 255) / 10) % 255);
    delay(50);
    analogWrite(gpin, 0);
    analogWrite(bpin, ((b * 255) / 10) % 255);
    delay(50);
    analogWrite(bpin, 0);
    break;

  default:
    break;
  }
}

void loop()
{
  char input[4];          // r, g, b, mode
  while (Serial.available() >= 4) // wait for 4 characters from serial port
  {
    if (Serial.readBytes(input, 4) == 4)
    {
      Serial.print("\nReceived: "); // print I received
      Serial.write(input, 4);     // send what you read
      break;
    }
  }

  LED_control(input[0] - '0', input[1] - '0', input[2] - '0', input[3] - '0');
}
