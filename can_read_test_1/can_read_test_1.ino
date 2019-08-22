#include <SPI.h>
#include <mcp2515.h>

struct can_frame canMsg;
MCP2515 mcp2515(10);


void setup() {
  Serial.begin(9600);
  SPI.begin();
  
  mcp2515.reset();
  mcp2515.setBitrate(CAN_1000KBPS);
  mcp2515.setNormalMode();
  
  Serial.println("------- CAN Read ----------");
  Serial.println("ID  DLC   DATA");
}

void loop() {
  
  if (mcp2515.readMessage(&canMsg) == MCP2515::ERROR_OK) {
      
    Serial.print(canMsg.can_id, DEC); // print ID
    Serial.print(" "); 
    //Serial.print(canMsg.can_dlc, HEX); // print DLC
    //Serial.print(" ");
    //Serial.print(" ");
    
   /* for (int i = 0; i<canMsg.can_dlc; i++)  {  // print the data
        
      Serial.print(canMsg.data[i],HEX);
      Serial.print(" ");


    }

    Serial.println();      
  }*/

}
}
