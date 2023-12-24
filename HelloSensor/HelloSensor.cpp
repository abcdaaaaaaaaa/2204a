#include "HelloSensor.h"
#include "Arduino.h"

HelloSensor::HelloSensor(int bitadc, float Rload, byte pin)
{
  _pin=pin;
  _Rload=Rload;
  _bitadc= pow(2,bitadc)-1;
}

void HelloSensor::begin()
{
  pinMode(_pin,INPUT);
}

//**************************************Ready Calibration**************************************

void HelloSensor::MQ2calibrate(){_R0 = 2.74;}
void HelloSensor::MQ3calibrate(){_R0 = 0.45;}
void HelloSensor::MQ4calibrate(){_R0 = 6.14;}
void HelloSensor::MQ5calibrate(){_R0 = 4.16;}
void HelloSensor::MQ6calibrate(){_R0 = 2.71;}
void HelloSensor::MQ7calibrate(){_R0 = 0.98;}
void HelloSensor::MQ8calibrate(){_R0 = 0.386;}
void HelloSensor::MQ9calibrate(){_R0 = 2.816;}
void HelloSensor::MQ131calibrate(){_R0 = 0.67;}
void HelloSensor::MQ135calibrate(){_R0 = 8.2809;}
void HelloSensor::MQ136calibrate(){_R0 = 7.5;}
void HelloSensor::MQ137calibrate(){_R0 = 7.5;}
void HelloSensor::MQ303Acalibrate(){_R0 = 27;}
void HelloSensor::MQ309Acalibrate(){_R0 = 2.458;}

float HelloSensor::readValue()
{
  _RS = ((_Rload/(analogRead(_pin)*(1/_bitadc)))-(_Rload));
  _ratio = ( _RS / _R0);
 return pow(_ratio,_vb)*_va;
}

//**************************************ppm Value**************************************

int HelloSensor::MQData100(){return map(analogRead(_pin),0,(_bitadc),0,100);}
//int HelloSensor::MQ2DataAir(){return map(analogRead(_pin),1,(_bitadc),200,10000);}
int HelloSensor::MQ3DataAir(){return map(analogRead(_pin),1,(_bitadc),25,500);}
int HelloSensor::MQ4DataAir(){return map(analogRead(_pin),1,(_bitadc),200,10000);}
int HelloSensor::MQ5DataAir(){return map(analogRead(_pin),1,(_bitadc),200,10000);}
int HelloSensor::MQ6DataAir(){return map(analogRead(_pin),1,(_bitadc),300,10000);}
int HelloSensor::MQ7DataAir(){return map(analogRead(_pin),1,(_bitadc),50,4000);}
int HelloSensor::MQ8DataAir(){return map(analogRead(_pin),1,(_bitadc),200,10000);}
int HelloSensor::MQ9DataAir(){return map(analogRead(_pin),1,(_bitadc),200,10000);}
int HelloSensor::MQ131DataAir(){return map(analogRead(_pin),1,(_bitadc),5,100);}
int HelloSensor::MQ135DataAir(){return map(analogRead(_pin),1,(_bitadc),10,200);}
int HelloSensor::MQ136DataAir(){return map(analogRead(_pin),1,(_bitadc),10,200);}
int HelloSensor::MQ137DataAir(){return map(analogRead(_pin),1,(_bitadc),10,200);}
int HelloSensor::MQ303ADataAir(){return (map(analogRead(_pin),1,(_bitadc),12,345));}
//float HelloSensor::MQ303ADataAir(){return (map(analogRead(_pin),1,(_bitadc),12,345))/10;}
int HelloSensor::MQ309ADataAir(){return map(analogRead(_pin),1,(_bitadc),160,260);}

//**************************************MQ-2**************************************

float HelloSensor::MQ2DataLPG(){_va = 17.6135;_vb =  -0.4539; return readValue();}
float HelloSensor::MQ2DataPropane(){_va = 19.5575;_vb = -0.461;return readValue();}
float HelloSensor::MQ2DataH2(){_va = 25.7473;_vb = -0.4731;return readValue();}
float HelloSensor::MQ2DataAlcohol(){_va = 19.2641;_vb = -0.3604;return readValue();}
float HelloSensor::MQ2DataCH4(){_va = 20.7074;_vb = -0.36;return readValue();}
float HelloSensor::MQ2Datasmoke(){_va = 26.4698;_vb = -0.3876;return readValue();}
float HelloSensor::MQ2DataCO(){_va = 28.024;_vb = -0.3182;return readValue();}

/*
Gas    | a       | b
LPG    | 17.6135 | -0.4539
propane| 19.5575 | -0.461 
H2     | 25.7473 | -0.4731
alcohol| 19.2641 | -0.3604
CH4    | 20.7074 | -0.36  
smoke  | 26.4698 | -0.3876
CO     | 28.024  | -0.3182
 */

//**************************************MQ-3**************************************

float HelloSensor::MQ3DataAlcohol(){_va = 0.5565;_vb = -0.6333;return readValue();}
float HelloSensor::MQ3DataBenzene(){_va = 1.7957;_vb = -0.369;return readValue();}
float HelloSensor::MQ3DataHexane(){_va = 22.9337;_vb = -0.358;return readValue();}
float HelloSensor::MQ3DataLPG(){_va = 27.8286;_vb = -0.2847;return readValue();}
float HelloSensor::MQ3DataCO(){_va = 31.9559;_vb = -0.2325;return readValue();}
float HelloSensor::MQ3DataCH4(){_va = 44.8389;_vb = -0.0476;return readValue();}

/*
Gas    | a       | b
Alcohol| 0.5565  | -0.6333
Benzene| 1.7957  | -0.369 
Hexane | 22.9337 | -0.358 
LPG    | 27.8286 | -0.2847
CO     | 31.9559 | -0.2325
CH4    | 44.8389 | -0.0476
 */

//**************************************MQ-4**************************************

float HelloSensor::MQ4DataCH4(){_va = 11.6605;_vb = -0.3558;return readValue();}
float HelloSensor::MQ4DataLPG(){_va = 13.9134;_vb = -0.3186;return readValue();}
float HelloSensor::MQ4DataH2(){_va = 9.6559;_vb = -0.1765;return readValue();}
float HelloSensor::MQ4DataSmoke(){_va = 7.05;_vb = -0.1065;return readValue();}
float HelloSensor::MQ4DataAlcohol(){_va = 5.7994;_vb = -0.0696;return readValue();}
float HelloSensor::MQ4DataCO(){_va = 5.4783;_vb = -0.0492;return readValue();}

/*
Gas    | a       | b
CH4    | 11.6605 | -0.3558
LPG    | 13.9134 | -0.3186
H2     | 9.6559  | -0.1765
smoke  | 7.05    | -0.1065
alcohol| 5.7994  | -0.0696
CO     | 5.4783  | -0.0492
 */

//**************************************MQ-5**************************************

float HelloSensor::MQ5DataLPG(){_va = 6.1067;_vb = -0.4102;return readValue();}
float HelloSensor::MQ5DataCH4(){_va = 6.987; _vb = -0.3777;return readValue();}
float HelloSensor::MQ5DataH2(){_va = 7.4265;_vb = -0.2847;return readValue();}
float HelloSensor::MQ5DataAlcohol(){_va = 10.8274;_vb = -0.2104;return readValue();}
float HelloSensor::MQ5DataCO(){_va = 8.2236;_vb = -0.1492;return readValue();}

/*
Gas    | a       | b
LPG    | 6.1067  | -0.4102
CH4    | 6.987   | -0.3777
H2     | 7.4265  | -0.2847
alcohol| 10.8274 | -0.2104
CO     | 8.2236  | -0.1492
 */

//**************************************MQ-6**************************************

float HelloSensor::MQ6DataLPG(){_va = 20.3079;_vb = -0.4349;return readValue();}
float HelloSensor::MQ6DataCH4(){_va = 22.011;_vb =  -0.4029; return readValue();}
float HelloSensor::MQ6DataH2(){_va = 26.9497;_vb = -0.2956;return readValue();}
float HelloSensor::MQ6DataAlcohol(){_va = 19.3261; _vb = -0.1655;return readValue();}
float HelloSensor::MQ6DataCO(){_va = 13.4917;_vb = -0.0777;return readValue();}

/*
Gas    | a       | b
LPG    | 20.3079 | -0.4349
CH4    | 22.011  | -0.4029
H2     | 26.9497 | -0.2956
Alcohol| 19.3261 | -0.1655
CO     | 13.4917 | -0.0777
 */

//**************************************MQ-7**************************************

float HelloSensor::MQ7DataH2(){_va = 21.1794;_vb = -0.7174;return readValue();}
float HelloSensor::MQ7DataCO(){_va = 20.89;_vb = -0.6568;return readValue();}
float HelloSensor::MQ7DataLPG(){_va = 14.9745;_vb = -0.1329;return readValue();}
float HelloSensor::MQ7DataCH4(){_va = 19.8094;_vb = -0.09;return readValue();}
float HelloSensor::MQ7DataAlcohol(){_va = 20.2524;_vb = -0.0655;return readValue();}

/*
Gas    | a       | b
H2     | 21.1794 | -0.7174
CO     | 20.89   | -0.6568
LPG    | 14.9745 | -0.1329
CH4    | 19.8094 | -0.09  
Alcohol| 20.2524 | -0.0655
 */

//**************************************MQ-8**************************************

float HelloSensor::MQ8DataH2(){_va = 18391.5667;_vb = -1.4494;return readValue();}
float HelloSensor::MQ8DataAlcohol(){_va = 468.8045;_vb = -0.5574;return readValue();}
float HelloSensor::MQ8DataLPG(){_va = 152.1255;_vb = -0.2922;return readValue();}
float HelloSensor::MQ8DataCH4(){_va = 117.9639;_vb = -0.1448;return readValue();}
float HelloSensor::MQ8DataCO(){_va = 126.605; _vb = -0.1173;return readValue();}

/*
Gas    | a       | b
H2     | 18391.5667| -1.4494
alcohol| 468.8045| -0.5574
LPG    | 152.1255| -0.2922
CH4    | 117.9639| -0.1448
CO     | 126.605 | -0.1173
 */

//**************************************MQ-9**************************************

float HelloSensor::MQ9DataCO(){_va = 17.3985;_vb = -0.4504;return readValue();}
float HelloSensor::MQ9DataLPG(){_va = 24.918;_vb = -0.4695;return readValue();}
float HelloSensor::MQ9DataCH4(){_va = 21.8247;_vb = -0.3663;return readValue();}

/*
Gas    | a       | b
CO     | 17.3985 | -0.4504
LPG    | 24.918  | -0.4695
CH4    | 21.8247 | -0.3663
 */

//**************************************MQ-131**************************************

float HelloSensor::MQ131DataO3(){_va = 16.0871;_vb = -0.8603;return readValue();}
float HelloSensor::MQ131DataCL2(){_va = 18.9693;_vb = -0.7132;return readValue();}
float HelloSensor::MQ131DataNOx(){_va = 16.7059;_vb = -0.4684;return readValue();}

/*
Gas    | a       | b
O3     | 16.0871 | -0.8603
CL2    | 18.9693 | -0.7132
NOx    | 16.7059 | -0.4684
 */

//**************************************MQ-135**************************************

float HelloSensor::MQ135DataAceton(){_va = 2.824;_vb = -0.2955;return readValue();}
float HelloSensor::MQ135DataToluen(){_va = 2.9897;_vb = -0.2909;return readValue();}
float HelloSensor::MQ135DataAlcohol(){_va = 3.8776;_vb = -0.3144;return readValue();}
float HelloSensor::MQ135DataCO2(){_va = 5.2146;_vb = -0.3574;return readValue();}
float HelloSensor::MQ135DataNH4(){_va = 6.4416;_vb = -0.3994;return readValue();}
float HelloSensor::MQ135DataCO(){_va = 5.0533;_vb = -0.2541;return readValue();}

/*
Gas    | a       | b
Aceton | 2.824   | -0.2955
Toluen | 2.9897  | -0.2909
Alcohol| 3.8776  | -0.3144
CO2    | 5.2146  | -0.3574
NH4    | 6.4416  | -0.3994
CO     | 5.0533  | -0.2541
 */

//**************************************MQ-136**************************************

float HelloSensor::MQ136DataH2S(){_va = 2.7684;_vb = -0.2832;return readValue();}
float HelloSensor::MQ136DataNH4(){_va = 6.4463;_vb = -0.4028;return readValue();}
float HelloSensor::MQ136DataCO(){_va = 5.277;_vb = -0.2622;return readValue();}

/*
Gas    | a       | b
H2S    | 2.7684  | -0.2832
NH4    | 6.4463  | -0.4028
CO     | 5.277   | -0.2622
 */

//**************************************MQ-137**************************************

float HelloSensor::MQ137DataCO(){_va = 5.2245;_vb = -0.2617;return readValue();}
float HelloSensor::MQ137DataEthanol(){_va = 6.3348;_vb = -0.3978;return readValue();}
float HelloSensor::MQ137DataNH3(){_va = 2.7756;_vb = -0.2837;return readValue();}

/*
Gas    | a       | b
CO     | 5.2245  | -0.2617
Ethanol| 6.3348  | -0.3978
NH3    | 2.7756  | -0.2837
 */

//**************************************MQ-303A**************************************

float HelloSensor::MQ303ADataHyd(){_va = 1.7955;_vb = -0.3767;return readValue();}
float HelloSensor::MQ303ADataEthanol(){_va = 1.5196;_vb = -0.367;return readValue();}
float HelloSensor::MQ303ADataIso(){_va = 1.9209;_vb = -0.3443;return readValue();}

/*
Gas    | a       | b
Hydrogen| 1.7955  | -0.3767
Ethanol| 1.5196  | -0.367 
IsoButane| 1.9209  | -0.3443
 */

//**************************************MQ-309A**************************************

float HelloSensor::MQ309ADataH2(){_va = 44.3713;_vb = -0.5136;return readValue();}
float HelloSensor::MQ309ADataCH4(){_va = 65.5612;_vb = -0.6033;return readValue();}
float HelloSensor::MQ309ADataAlcohol(){_va = 34.1956;_vb = -0.2666;return readValue();}
float HelloSensor::MQ309ADataCO(){_va = 30.3019;_vb = -0.2336;return readValue();}

/*
Gas    | a       | b
H2     | 44.3713 | -0.5136
CH4    | 65.5612 | -0.6033
alcohol| 34.1956 | -0.2666
CO     | 30.3019 | -0.2336
 */

GeigerCounterPin::GeigerCounterPin(byte pin2, int LOG_PERIOD1)
{
  _pin2=pin2;
  _LOG_PERIOD=LOG_PERIOD1;
}
 
unsigned long _counts;

void _impulse() {
   _counts++;
}

float outputSieverts(float x) {
    float y = x * 0.0057;
    return y;
}

void GeigerCounterPin::begin()
{
    _counts = 0;
    _currentCPM = 0;
    _averageCPM = 0;
    _sdCPM = 0;
    _calcCPM = 0;
    pinMode(_pin2, INPUT);
    attachInterrupt(digitalPinToInterrupt(_pin2), _impulse, FALLING);
}

void GeigerCounterPin::radyoactivite()
{
    count = _counts ;

    unsigned long currentMillis = millis();
  if (currentMillis - previousMillis > _LOG_PERIOD) {
    previousMillis = currentMillis;
    _CPMArray[_currentCPM] = _counts * 2;

    usvhr = outputSieverts(_CPMArray[_currentCPM]);

    _counts = 0;
    _averageCPM = 0;
    _sdCPM = 0;
  
    //calc avg and sd
    for (int x=0;x<_currentCPM+1;x++)  {
      _averageCPM = _averageCPM + _CPMArray[x];
    }
    _averageCPM = _averageCPM / (_currentCPM + 1);
    for (int x=0;x<_currentCPM+1;x++)  {
      _sdCPM = _sdCPM + sq(_CPMArray[x] - _averageCPM);
    }
    _sdCPM = sqrt(_sdCPM / _currentCPM) / sqrt(_currentCPM+1);

       Avg = outputSieverts(_averageCPM);
       sdCPM = outputSieverts(_sdCPM);
    _currentCPM = _currentCPM + 1;
}
}
