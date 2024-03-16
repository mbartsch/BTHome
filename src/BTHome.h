#ifndef BT_HOME_H
#define BT_HOME_H

#include <string>

namespace bthome
{
	enum class DataType : uint8_t
	{
		packetId = 0x00,

		// Data type:	uint8 (1 byte)
		// Factor:		1
		// Example:		0161
		// Result:		97
		// Unit:		%
		battery = 0x01,

		// Data type:	sint16 (2 bytes)
		// Factor:		0.01
		// Example:		02CA09
		// Result:		25.06
		// Unit:		°C
		temperature = 0x02,

		// Data type:	uint16 (2 bytes)
		// Factor:		0.01
		// Example:		03BF13
		// Result:		50.55
		// Unit:		%
		humidity = 0x03,

		// Data type:	uint24 (3 bytes)
		// Factor:		0.01
		// Example:		04138A01
		// Result:		1008.83
		// Unit:		hPa
		pressure = 0x04,

		// Data type:	uint24 (3 bytes)
		// Factor:		0.01
		// Example:		05138A14
		// Result:		13460.67
		// Unit:		lux
		illuminance = 0x05,

		// Data type:	uint16 (2 byte)
		// Factor:		0.01
		// Example:		065E1F
		// Result:		80.3
		// Unit:		kg
		massKg = 0x06,

		// Data type:	uint16 (2 byte)
		// Factor:		0.01
		// Example:		073E1D
		// Result:		74.86
		// Unit:		lb
		massLb = 0x07,

		// Data type:	sint16 (2 bytes)
		// Factor:		0.01
		// Example:		08CA06
		// Result:		17.38
		// Unit:		°C
		dewpoint = 0x08,

		// Data type:	uint (1 bytes)
		// Factor:		1
		// Example:		0960
		// Result:		96
		// Unit:
		count1 = 0x09,

		// Data type:	uint24 (3 bytes)
		// Factor:		0.001
		// Example:
		// Result:
		// Unit:		kWh
		energy1 = 0X0A,

		// Data type:	uint24 (3 bytes)
		// Factor:		0.01
		// Example:		0B021B00
		// Result:		69.14
		// Unit:		W
		power = 0x0B,

		// Data type:	uint16 (2 bytes)
		// Factor:		0.001
		// Example:		0C020C
		// Result:		3.074
		// Unit:		V
		voltage = 0x0C,

		// Data type:	uint16 (2 bytes)
		// Factor:		1
		// Example:		0D120C
		// Result:		3090
		// Unit:		ug/m3
		pm2p5 = 0x0D,

		// Data type:	uint16 (2 bytes)
		// Factor:		1
		// Example:		0E021C
		// Result:		7170
		// Unit:		ug/m3
		pm10 = 0x0E,

		// Data type:	uint8 (1 byte)
		// Factor:		0.01
		// Example:		0F01
		// Result:		1 (True = On)
		genericBoolean = 0x0F,

		// Data type:	uint16 (2 bytes)
		// Factor:		1
		// Example:		12E204
		// Result:		1250
		// Unit:		ppm
		co2 = 0x12,

		// Data type:	uint (2 bytes)
		// Factor:		1
		// Example:		3D0960
		// Result:		24585
		// Unit:
		count2 = 0x3D,

		// Data type:	uint (4 bytes)
		// Factor:		1
		// Example:		3E2A2C0960
		// Result:		1611213866
		// Unit:
		count3 = 0x3E,

		// Data type:	uint16 (2 bytes)
		// Factor:		0.001
		// Example:		133301
		// Result:		307
		// Unit:		ug/m3
		current = 0x43,

		// Data type:	uint16 (2 bytes)
		// Factor:		1
		// Example:		400C00
		// Result:		12
		// Unit:		mm
		distanceMm = 0x40,

		// Data type:	uint16 (2 bytes)
		// Factor:		0.1
		// Example:		414E00
		// Result:		7.8
		// Unit:		m
		distanceM = 0x40,

		// Data type:	uint24 (3 bytes)
		// Factor:		0.001
		// Example:		424E3400
		// Result:		13.390
		// Unit:		s
		duration = 0x42,

		// Data type:	uint32 (4 bytes)
		// Factor:		0.001
		// Example:
		// Result:
		// Unit:		kWh
		energy = 0X4D,

		// Data type:	uint24 (3 bytes)
		// Factor:		0.001
		// Example:		4B138A14
		// Result:		1346.067
		// Unit:		m3
		gas = 0X4B,

		// Data type:	uint32 (4 bytes)
		// Factor:		0.001
		// Example:		4C41018A01
		// Result:		25821.505
		// Unit:		m3
		gas1 = 0X4C,

		// Data type:	uint16 (2 bytes)
		// Factor:		1
		// Example:		434E34
		// Result:		13.39
		// Unit:		A
		tvoc = 0x13,

		// Data type:	uint32 (4 byte)
		// Factor:		0.001
		// Example:		4E87562A01
		// Result:		19551.879
		// Unit:		L
		volume1 = 0x4E,
    	
		// Data type:	uint16 (2 byte)
		// Factor:		0.1
		// Example:		478756
		// Result:		2215.1
		// Unit:		L
		volume2 = 0x47,
    	
		// Data type:	uint16 (2 byte)
		// Factor:		1
		// Example:		48DC87
		// Result:		34780
		// Unit:		mL
		volume3 = 0x48,
    	
		// Data type:	uint32 (4 bytes)
		// Factor:		0.001
		// Example:		4E87562A01
		// Result:		19551.879
		// Unit:		L
		water = 0x4F,
	};

	struct ServiceDataItem
	{

		enum DataType dataType;
		uint64_t dataValue; // scaled data value
	};

	class PayloadBuilder
	{
	public:
		PayloadBuilder(std::string deviceName);

		void addCo2(uint16_t const data);
		void addCount(uint8_t const data);
		void addCount(uint16_t const data);
		void addCount(uint32_t const data);
		void addTvoc(uint16_t const data);
		void addTemperature(float const data);
		void addHumidity(float const data);
		void addPressure(float const data);
		void addGenericBoolean(bool const data);
		void addPm2p5(uint16_t const data);
		void addPm10(uint16_t const data);
		void addVolume(uint16_t const data);
		void addVolume(uint32_t const data);
		void addWater(uint16_t const data);
		std::string getAdvertisingPayload();
		void resetServiceData();

	protected:
		std::string deviceName;
		ServiceDataItem *serviceDataPayload;
		uint8_t serviceDataPayloadSize = 0;

		std::string getServiceData();
		void addServiceDataItem(DataType dataType, uint64_t dataValue);
	};

}

#endif