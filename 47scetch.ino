Код для передатчика:
#include <RH_ASK.h>
#include <SPI.h>

RH_ASK driver(2000, 11, 8, 10, false);

const char *on2 = "a";
const char *off2 = "b";
const char *on3 = "c";
const char *off3 = "d";

void setup()
{
    driver.init();

    pinMode(2, INPUT);
    pinMode(3, INPUT);
}

void loop()
{
    if (digitalRead(2) == HIGH)
    {
        driver.send((uint8_t *)on2, strlen(on2));
        driver.waitPacketSent();
        delay(200);
    }

    if (digitalRead(2) == LOW)
    {
        driver.send((uint8_t *)off2, strlen(off2));
        driver.waitPacketSent();
        delay(200);
    }

    if (digitalRead(3) == HIGH)
    {
        driver.send((uint8_t *)on3, strlen(on3));
        driver.waitPacketSent();
        delay(200);
    }

    if (digitalRead(3) == LOW)
    {
        driver.send((uint8_t *)off3, strlen(off3));
        driver.waitPacketSent();
        delay(200);
    }
}
