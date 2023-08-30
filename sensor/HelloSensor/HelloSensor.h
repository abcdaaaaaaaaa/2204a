#ifndef HelloSensor_h
#define HelloSensor_h

#include "Arduino.h"

class HelloSensor
{
  private:
  float _ratio;
  int _bitadc;
  float _Rload;
  byte _pin;
  float _R0;
  float _RS;
  float _va;
  float _vb;
  public:
  HelloSensor(int bitadc, float Rload, byte pin);
  void begin();
  void MQ2calibrate();
  void MQ3calibrate();
  void MQ4calibrate();
  void MQ5calibrate();
  void MQ6calibrate();
  void MQ7calibrate();
  void MQ8calibrate();
  void MQ9calibrate();
  void MQ131calibrate();
  void MQ135calibrate();
  void MQ136calibrate();
  void MQ303Acalibrate();
  void MQ309Acalibrate();
  float MQData100();
  float readValue();
  float MQ2DataAir();
  float MQ3DataAir();
  float MQ4DataAir();
  float MQ5DataAir();
  float MQ6DataAir();
  float MQ7DataAir();
  float MQ8DataAir();
  float MQ9DataAir();
  float MQ131DataAir();
  float MQ135DataAir();
  float MQ136DataAir();
  float MQ303ADataAir();
  float MQ309ADataAir();
  float MQ2DataH2();
  float MQ2DataLPG();
  float MQ2DataCO();
  float MQ2DataAlcohol();
  float MQ2DataPropane();
  float MQ3DataLPG();
  float MQ3DataCH4();
  float MQ3DataCO();
  float MQ3DataAlcohol();
  float MQ3DataBenzene();
  float MQ3DataHexane();
  float MQ4DataLPG();
  float MQ4DataCH4();
  float MQ4DataCO();
  float MQ4DataAlcohol();
  float MQ4DataSmoke();
  float MQ5DataH2();
  float MQ5DataLPG();
  float MQ5DataCH4();
  float MQ5DataCO();
  float MQ5DataAlcohol();
  float MQ6DataH2();
  float MQ6DataLPG();
  float MQ6DataCH4();
  float MQ6DataCO();
  float MQ6DataAlcohol();
  float MQ7DataH2();
  float MQ7DataLPG();
  float MQ7DataCH4();
  float MQ7DataCO();
  float MQ7DataAlcohol();
  float MQ8DataH2();
  float MQ8DataLPG();
  float MQ8DataCH4();
  float MQ8DataCO();
  float MQ8DataAlcohol();
  float MQ9DataLPG();
  float MQ9DataCH4();
  float MQ9DataCO();
  float MQ131DataNOx();
  float MQ131DataCL2();
  float MQ131DataO3();
  float MQ135DataCO();
  float MQ135DataAlcohol();
  float MQ135DataCO2();
  float MQ135DataToluen();
  float MQ135DataNH4();
  float MQ135DataAceton();
  float MQ136DataH2S();
  float MQ136DataNH4();
  float MQ136DataCO();
  float MQ303ADataIso();
  float MQ303ADataHyd();
  float MQ303ADataEthanol();
  float MQ309ADataH2();
  float MQ309ADataCH4();
  float MQ309ADataCO();
  float MQ309ADataAlcohol();
};

class GeigerCounterPin
{
  private:
  byte _pin2;
  int _LOG_PERIOD;
  float _Avg;
  float _averageCPM;
  float _sdCPM;
  float _calcCPM;
  float _CPMArray[100];
  float _usvhr;
  float _count;
  int _currentCPM;
  unsigned long previousMillis;
  public:
  GeigerCounterPin(byte pin2, int LOG_PERIOD1);
  void begin();
  void radyoactivite();
  float usvhr;
  float count;
  float Avg;
  float sdCPM;
};

#endif