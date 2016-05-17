#include <EasyTransfer.h>
 
EasyTransfer ET;
 
struct DATA_STRUCTURE{
int uid_data;
char ndef_data;
};
 
DATA_STRUCTURE cache;
 
void setup()
{
 Serial.begin(9600);
 ET.begin(details(cache), &Serial);
}
 
void loop()
{

 if(ET.receiveData())
 {
Serial.println(cache.uid_data);
Serial.println(cache.ndef_data);
delay(500);
 }
 
}
