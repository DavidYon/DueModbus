#include <DueFlashStorage.h>
#include <efc.h>
#include <flash_efc.h>

#include <modbus.h>
#include <modbusDevice.h>
#include <modbusRegBank.h>
#include <modbusSlave.h>

/*
This example code shows a quick and dirty way to get an
arduino to talk to a modbus master device with a
device ID of 1 at 9600 baud.
*/

//Setup the brewtrollers register bank
//All of the data accumulated will be stored here
modbusDevice regBank(4096);
//Create the modbus slave protocol handler
modbusSlave slave;

void setup()
{   

//Assign the modbus device ID.  
  regBank.setId(1);

/*
modbus registers follow the following format
00001-09999  Digital Outputs, A master device can read and write to these registers
10001-19999  Digital Inputs, A master device can only read the values from these registers
30001-39999  Analog Inputs, A master device can only read the values from these registers
40001-49999  Analog Outputs, A master device can read and write to these registers 

Analog values are 16 bit unsigned words stored with a range of 0-32767
Digital values are stored as bytes, a zero value is OFF and any nonzer value is ON

It is best to configure registers of like type into contiguous blocks.  this
allows for more efficient register lookup and and reduces the number of messages
required by the master to retrieve the data
*/


/*
Assign the modbus device object to the protocol handler
This is where the protocol handler will look to read and write
register data.  Currently, a modbus slave protocol handler may
only have one device assigned to it.
*/
  slave._device = &regBank;  

// Initialize the serial port for coms at 19200 baud  
  slave.setBaud(19200);   
 
}

void loop()
{
 
 while(1)
  {
 
     slave.run();  
  }
}
