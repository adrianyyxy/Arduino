#include <VirtualWire.h>

const int pinBuzzer = 9;

void setup()
{
    Serial.begin(115200);  // Debugging only
    Serial.println("setup");

    // Se inicializa el RF
    vw_setup(2000);  // velocidad: Bits per segundo
    vw_set_rx_pin(2);  //Pin 2 como entrada del RF
    vw_rx_start();       // Se inicia como receptor

}

void loop()
{
    uint8_t dato;
    uint8_t datoleng=1;
    //verificamos si hay un dato valido en el RF
    if (vw_get_message(&dato,&datoleng))
    {
      //tone(pin, frequencia, duracion);
      if((char)dato=='0'){
        noTone(pinBuzzer);
      }
      else if((char)dato=='1'){
        tone(pinBuzzer, 261, 1200);
      }
      else if((char)dato=='2'){
        tone(pinBuzzer, 294, 1200);
      }
      else if((char)dato=='3'){
        tone(pinBuzzer, 330, 1200);
      }
      else if((char)dato=='4'){
        tone(pinBuzzer, 370, 1200);
      }
      else if((char)dato=='5'){
        tone(pinBuzzer, 415, 1200);
      }
      else if((char)dato=='6'){
        tone(pinBuzzer, 466, 1200);
      }
    }
}
