#ifndef gem_readout_GEMDataAMCformat_h
#define gem_readout_GEMDataAMCformat_h

#include <iostream>
#include <iomanip> 
#include <fstream>
#include <string>
#include <vector>

namespace gem {
  namespace readout {

    struct VFATData {
      uint16_t BC;          // 1010:4,   BC:12 
      uint16_t EC;          // 1100:4,   EC:8,      Flags:4
      uint16_t ChipID;      // 1110,     ChipID:12
      uint64_t lsData;      // channels from 1to64
      uint64_t msData;      // channels from 65to128
      uint16_t BXfrOH;      // :16       BX from OH  
      uint16_t crc;         // :16       CRC
    };    
    
    struct GEBData {
      uint64_t header;      // ZSFlag:24 ChamID:12
      uint64_t runhed;      // RunType:4 VT1:8 VT2:8 minTH:8 maxTH:8 Step:8 - Threshold Scan Header
                            // RunType:4                                    - Latency Scan Header
                            // RunType:4                                    - Cosmic Run Header 
                            // RunType:4                                    - Data Takiing
      std::vector<VFATData> vfats;
      uint64_t trailer;     // OHcrc: 16 OHwCount:16  ChamStatus:16
    };

    struct GEMData {
      uint64_t header1;    // AmcNo:4      0000:4     LV1ID:24   BXID:12     DataLgth:20 
      uint64_t header2;    // User:32      OrN:16     BoardID:16
      uint64_t header3;    // DAVList:24   BufStat:24 DAVCount:5 FormatVer:3 MP7BordStat:8 
      std::vector<GEBData> gebs;
      uint64_t trailer2;   // EventStat:32 GEBerrFlag:24  
      uint64_t trailer1;   // crc:32       LV1IDT:8   0000:4     DataLgth:20 
    };

    /*
     * GEM Data
     */

    bool writeGEMhd1(std::string file, int event, const GEMData& gem);
    bool writeGEMhd1Binary(std::string file, int event, const GEMData& gem);
    bool readGEMhd1Binary(std::ifstream& inpf, const GEMData& gem);
    bool readGEMhd1(std::ifstream& inpf, GEMData& gem);
    bool writeGEMhd2(std::string file, int event, const GEMData& gem);
    bool writeGEMhd2Binary(std::string file, int event, const GEMData& gem);
    bool readGEMhd2Binary(std::ifstream& inpf, const GEMData& gem);
    bool readGEMhd2(std::ifstream& inpf, GEMData& gem);
    bool writeGEMhd3(std::string file, int event, const GEMData& gem);
    bool writeGEMhd3Binary(std::string file, int event, const GEMData& gem);
    bool readGEMhd3Binary(std::ifstream& inpf, const GEMData& gem);
    bool readGEMhd3(std::ifstream& inpf, GEMData& gem);

    /*
     * GEB Data (One GEB board, 24 VFATs)
     */

    bool writeGEBheader(std::string file, int event, const GEBData& geb);
    bool writeGEBheaderBinary(std::string file, int event, const GEBData& geb);
    bool readGEBheaderBinary(std::ifstream& inpf, const GEBData& geb);
    bool readGEBheader(std::ifstream& inpf, GEBData& geb);
    bool printGEBheader(int event, const GEBData& geb);
    bool writeGEBrunhed(std::string file, int event, const GEBData& geb);
    bool writeGEBrunhedBinary(std::string file, int event, const GEBData& geb);
    bool readGEBrunhedBinary(std::ifstream& inpf, const GEBData& geb);
    bool readGEBrunhed(std::ifstream& inpf, GEBData& geb);
    bool writeGEBtrailer(std::string file, int event, const GEBData& geb);
    bool writeGEBtrailerBinary(std::string file, int event, const GEBData& geb);
    bool readGEBtrailerBinary(std::ifstream& inpf, const GEBData& geb);
    bool readGEBtrailer(std::ifstream& inpf, GEBData& geb);
    bool printGEBtrailer(int event, const GEBData& geb);
    bool writeGEMtr2(std::string file, int event, const GEMData& gem);
    bool writeGEMtr2Binary(std::string file, int event, const GEMData& gem);
    bool readGEMtr2Binary(std::ifstream& inpf, const GEMData& gem);
    bool readGEMtr2(std::ifstream& inpf, GEMData& gem);
    bool writeGEMtr1(std::string file, int event, const GEMData& gem);
    bool writeGEMtr1Binary(std::string file, int event, const GEMData& gem);
    bool readGEMtr1Binary(std::ifstream& inpf, const GEMData& gem);
    bool readGEMtr1(std::ifstream& inpf, GEMData& gem);
    bool writeVFATdata(std::string file, int event, const VFATData& vfat);
    bool printVFATdata(int event, const VFATData& vfat);
    bool writeVFATdataBinary(std::string file, int event, const VFATData& vfat);
    bool readVFATdataBinary(std::ifstream& inpf, int event, VFATData& vfat);
    bool readVFATdata(std::ifstream& inpf, int event, VFATData& vfat);

    //
    // Useful printouts 
    //
    void show4bits( uint8_t  x);
    void show16bits(uint16_t x);
    void show24bits(uint32_t x);
    void show32bits(uint32_t x);
    void show64bits(uint64_t x);

    bool printVFATdataBits(int event, const VFATData& vfat);
    bool writeZEROline(std::string file);	  

  } //end namespace gem::readout
} //end namespace gem
#endif
