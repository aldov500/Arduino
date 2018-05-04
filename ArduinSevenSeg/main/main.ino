#include "SevenSeg.h"

SevenSeg Display;

void setup() {
  SevenSeg_Init(&Display);

}

void loop() {

 for(int i=0; i<15; i++){
  SevenSeg_SetNumber(&Display, i);
  SevenSeg_Display(Display);
  delay(200); 
 }
  
}
