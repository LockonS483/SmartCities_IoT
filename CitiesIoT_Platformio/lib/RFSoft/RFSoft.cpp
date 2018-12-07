#include <Arduino.h>
#include "RFSoft.h"

byte* c(int message){
  //Calculate Size   (2 Sync, 1 Header, 1 ORG, x Data, )
  int size = 0;

  //Create output array
  byte* mOut[size];
  *mOut[0] = syncBytes[0];
  *mOut[1] = syncBytes[1];
  //ORG Values: (0xD2: VLD)
  *mOut[2] = 0xD2;
  return *mOut;
}
