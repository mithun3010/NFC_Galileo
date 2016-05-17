#include <EasyTransfer.h>
 
EasyTransfer ET;

 
struct DATA_STRUCTURE{
int uid_data;
char ndef_data;
};
 
DATA_STRUCTURE cache;
 
int counter;
 
void setup()
{

 Serial.begin(9600);
 ET.begin(details(cache), &Serial);
 
counter = 0;
}
 
void loop()
{
cache.uid_data = counter;
cache.ndef_data = counter++;
ET.sendData();
delay(1000);
}
