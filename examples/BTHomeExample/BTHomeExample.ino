#include "NimBLEDevice.h"
#include "NimBLEBeacon.h"
#include <BTHome.h>

#define BEACON_UUID "a4cd8f8f-ef4c-4832-bb71-61da7ac94815"

BLEAdvertising *pAdvertising = BLEDevice::getAdvertising();
bthome::PayloadBuilder btHomePayloadBuilder("BTHomeExample");
int counter = 0;

void setBeacon()
{
  BLEBeacon bleBeacon = BLEBeacon();
  bleBeacon.setManufacturerId(0x4C00); // fake Apple 0x004C LSB (ENDIAN_CHANGE_U16!)
  bleBeacon.setProximityUUID(BLEUUID(BEACON_UUID));
  BLEAdvertisementData oAdvertisementData = BLEAdvertisementData();
  BLEAdvertisementData oScanResponseData = BLEAdvertisementData();

  oAdvertisementData.setFlags(0x06);
  btHomePayloadBuilder.resetServiceData();

  btHomePayloadBuilder.addTemperature(counter);
  btHomePayloadBuilder.addHumidity(counter % 100);
  btHomePayloadBuilder.addGenericBoolean(counter % 2 == 0);

  oAdvertisementData.addData(btHomePayloadBuilder.getAdvertisingPayload());
  pAdvertising->setAdvertisementData(oAdvertisementData);
  pAdvertising->setScanResponseData(oScanResponseData);
  pAdvertising->setAdvertisementType(BLE_GAP_CONN_MODE_NON);
}

void setup()
{
  Serial.begin(115200);

  BLEDevice::init("");
}

void loop()
{
  counter++;
  if (counter > 200)
  {
    counter = 0;
  }
  setBeacon();
  pAdvertising->start();
  Serial.printf("Advertizing %d\n", counter);
  delay(5000);
  pAdvertising->stop();
  delay(1000);
}