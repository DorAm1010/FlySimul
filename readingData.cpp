//
// Created by Laliv on 27/12/2019.
//

#include "readingData.h"

/* Null, because instance will be initialized on demand. */
ReadingData* ReadingData::instance = 0;

void ReadingData::initMapsKeys() {
    string sim;
    for (int i = 1; i < 36; i++) {
        // init i'th entry
        switch (i) {
            case 1: {
                // airspeed-indicator_indicated-speed-kt
                sim = "/instrumentation/airspeed-indicator/indicated-speed-kt";
                VarStruct varStruct1(sim, 0, false);
                simToVariableMap["airspeed-indicator_indicated-speed-kt"] = &varStruct1;
                break;
            }
            case 2: {
                // time_warp
                sim = "/sim/time/warp";
                VarStruct varStruct2(sim, 0, false);
                simToVariableMap["time_warp"] = &varStruct2;
                break;
            }
            case 3: {
                // switches_magnetos
                sim = "/controls/switches/magnetos";
                VarStruct varStruct3(sim, 0, false);
                simToVariableMap["switches_magnetos"] = &varStruct3;
                break;
            }
            case 4: {
                // heading-indicator_offset-deg
                sim = "/instrumentation/heading-indicator/offset-deg";
                VarStruct varStruct4(sim, 0, false);
                simToVariableMap["heading-indicator_offset-deg"] = &varStruct4;
                break;
            }
            case 5:{
                // altimeter_indicated-altitude-ft
                sim = "/instrumentation/altimeter/indicated-altitude-ft";
                VarStruct varStruct5(sim, 0, false);
                simToVariableMap["altimeter_indicated-altitude-ft"] = &varStruct5;
                break;
            }
            case 6: {
                // altimeter_pressure-alt-ft
                sim = "/instrumentation/altimeter/pressure-alt-ft";
                VarStruct varStruct6(sim, 0, false);
                simToVariableMap["altimeter_pressure-alt-ft"] = &varStruct6;
                break;
            }
            case 7: {
                // attitude-indicator_indicated-pitch-deg
                sim = "/instrumentation/attitude-indicator/indicated-pitch-deg";
                VarStruct varStruct7(sim, 0, false);
                simToVariableMap["attitude-indicator_indicated-pitch-deg"] = &varStruct7;
                break;
            }
            case 8:{
                // attitude-indicator_indicated-roll-deg
                sim = "/instrumentation/attitude-indicator/indicated-roll-deg";
                VarStruct varStruct8(sim, 0, false);
                simToVariableMap["attitude-indicator_indicated-roll-deg"] = &varStruct8;
            }

                break;
            case 9:{
                // attitude-indicator_internal-pitch-deg
                sim = "/instrumentation/attitude-indicator/internal-pitch-deg";
                VarStruct varStruct9(sim, 0, false);
                simToVariableMap["attitude-indicator_internal-pitch-deg"] = &varStruct9;
                break;
            }
            case 10:{
                // attitude-indicator_internal-roll-deg
                sim = "/instrumentation/attitude-indicator/internal-roll-deg";
                VarStruct varStruct10(sim, 0, false);
                simToVariableMap["attitude-indicator_internal-roll-deg"] = &varStruct10;
                break;
            }
            case 11:{
                // encoder_indicated-altitude-ft
                sim = "/instrumentation/encoder/indicated-altitude-ft";
                VarStruct varStruct11(sim, 0, false);
                simToVariableMap["encoder_indicated-altitude-ft"] = &varStruct11;
                break;
            }
            case 12:{
                // encoder_pressure-alt-ft
                sim = "/instrumentation/encoder/pressure-alt-ft";
                VarStruct varStruct12(sim, 0, false);
                simToVariableMap["encoder_pressure-alt-ft"] = &varStruct12;
                break;
            }
            case 13:{
                // gps_indicated-altitude-ft
                sim = "/instrumentation/gps/indicated-altitude-ft";
                VarStruct varStruct13(sim, 0, false);
                simToVariableMap["gps_indicated-altitude-ft"] = &varStruct13;
                break;
            }
            case 14:{
                // gps_indicated-ground-speed-kt
                sim = "/instrumentation/gps/indicated-ground-speed-kt";
                VarStruct varStruct14(sim, 0, false);
                simToVariableMap["gps_indicated-ground-speed-kt"] = &varStruct14;
                break;
            }
            case 15:{
                // gps_indicated-vertical-speed
                sim = "/instrumentation/gps/indicated-vertical-speed";
                VarStruct varStruct15(sim, 0, false);
                simToVariableMap["gps_indicated-vertical-speed"] = &varStruct15;
                break;
            }
            case 16:{
                // indicated-heading-deg
                sim = "/instrumentation/heading-indicator/indicated-heading-deg";
                VarStruct varStruct16(sim, 0, false);
                simToVariableMap["indicated-heading-deg"] = &varStruct16;
                break;
            }
            case 17:{
                // magnetic-compass_indicated-heading-deg
                sim = "/instrumentation/magnetic-compass/indicated-heading-deg";
                VarStruct varStruct17(sim, 0, false);
                simToVariableMap["magnetic-compass_indicated-heading-deg"] = &varStruct17;
                break;
            }
            case 18:{
                // slip-skid-ball_indicated-slip-skid
                sim = "/instrumentation/slip-skid-ball/indicated-slip-skid";
                VarStruct varStruct18(sim, 0, false);
                simToVariableMap["slip-skid-ball_indicated-slip-skid"] = &varStruct18;
                break;
            }
            case 19:{
                // turn-indicator_indicated-turn-rate
                sim = "/instrumentation/turn-indicator/indicated-turn-rate";
                VarStruct varStruct19(sim, 0, false);
                simToVariableMap["turn-indicator_indicated-turn-rate"] = &varStruct19;
                break;
            }
            case 20:{
                // vertical-speed-indicator_indicated-speed-fpm
                sim = "/instrumentation/vertical-speed-indicator/indicated-speed-fpm";
                VarStruct varStruct20(sim, 0, false);
                simToVariableMap["vertical-speed-indicator_indicated-speed-fpm"] = &varStruct20;
                break;
            }
            case 21:{
                // flight_aileron
                sim = "/controls/flight/aileron";
                VarStruct varStruct21(sim, 0, false);
                simToVariableMap["flight_aileron"] = &varStruct21;
                break;
            }
            case 22:{
                // flight_elevator
                sim = "/controls/flight/elevator";
                VarStruct varStruct22(sim, 0, false);
                simToVariableMap["flight_elevator"] = &varStruct22;
                break;
            }
            case 23:{
                // flight_rudder
                sim = "/controls/flight/rudder";
                VarStruct varStruct23(sim, 0, false);
                simToVariableMap["flight_rudder"] = &varStruct23;
                break;
            }
            case 24:{
                // flight_flaps
                sim = "/controls/flight/flaps";
                VarStruct varStruct24(sim, 0, false);
                simToVariableMap["flight_flaps"] = &varStruct24;
                break;
            }
            case 25:{
                // engine_throttle
                sim = "/controls/engines/engine/throttle";
                VarStruct varStruct25(sim, 0, false);
                simToVariableMap["engine_throttle"] = &varStruct25;
                break;
            }
            case 26:{
                // current-engine_throttle
                sim = "/controls/engines/current-engine/throttle";
                VarStruct varStruct26(sim, 0, false);
                simToVariableMap["current-engine_throttle"] = &varStruct26;
                break;
            }
            case 27:{
                // switches_master-avionics
                sim = "/controls/switches/master-avionics";
                VarStruct varStruct27(sim, 0, false);
                simToVariableMap["switches_master-avionics"] = &varStruct27;
                break;
            }
            case 28:{
                // switches_starter
                sim = "/controls/switches/starter";
                VarStruct varStruct28(sim, 0, false);
                simToVariableMap["switches_startert"] = &varStruct28;
                break;
            }
            case 29:{
                // active-engine_auto-start
                sim = "/engines/active-engine/auto-start";
                VarStruct varStruct29(sim, 0, false);
                simToVariableMap["active-engine_auto-start"] = &varStruct29;
                break;
            }
            case 30:{
                // flight_speedbrake
                sim = "/controls/flight/speedbrake";
                VarStruct varStruct30(sim, 0, false);
                simToVariableMap["flight_speedbrake"] = &varStruct30;
                break;
            }
            case 31:{
                // c172p_brake-parking
                sim = "/sim/model/c172p/brake-parking";
                VarStruct varStruct31(sim, 0, false);
                simToVariableMap["c172p_brake-parking"] = &varStruct31;
                break;
            }
            case 32:{
                // engine_primer
                sim = "/controls/engines/engine/primer";
                VarStruct varStruct32(sim, 0, false);
                simToVariableMap["engine_primer"] = &varStruct32;
                break;
            }
            case 33:{
                // current-engine_mixture
                sim = "/controls/engines/current-engine/mixture";
                VarStruct varStruct33(sim, 0, false);
                simToVariableMap["current-engine_mixture"] = &varStruct33;
                break;
            }
            case 34:{
                // switches_master-bat
                sim = "/controls/switches/master-bat";
                VarStruct varStruct34(sim, 0, false);
                simToVariableMap["switches_master-bat"] = &varStruct34;
                break;
            }
            case 35:{
                // switches_master-alt
                sim = "/controls/switches/master-alt";
                VarStruct varStruct35(sim, 0, false);
                simToVariableMap["switches_master-altt"] = &varStruct35;
            }
                break;
            case 36:{
                // engine_rpm
                sim = "/engines/engine/rpm";
                VarStruct varStruct36(sim, 0, false);
                simToVariableMap["engine_rpmt"] = &varStruct36;
                break;
            }
            default:
                break;
        }
    }
}

ReadingData* ReadingData::getInstance()
{
    if (instance == 0)
    {
        instance = new ReadingData();
    }

    return instance;
}

ReadingData::ReadingData()
{}


vector<string> ReadingData::getWordsVector()
{
    if (instance == 0)
    {
        instance = new ReadingData();
    }

    return instance->words;
}

unordered_map<string,VarStruct*> ReadingData::getNameToVariableMap()
{
    if (instance == 0)
    {
        instance = new ReadingData();
    }

    return instance->nameToVariableMap;
}

unordered_map<string,VarStruct*> ReadingData::getSimToVariableMap()
{
    if (instance == 0)
    {
        instance = new ReadingData();
    }

    return instance->simToVariableMap;
}

void ReadingData::setWords(vector<string> v)
{
    instance->words = v;
}

int ReadingData::getInd()
{
   return instance->index;
}

void ReadingData::incInd(int add)
{
    instance->index += add;
}

void ReadingData::setShouldRun(bool b) {
    instance->should_run = b;
}

bool ReadingData::getShouldRun() {
    return instance->should_run;
}