#include "gem/readout/GEMslotContents.h"

// uint16_t gem::readout::slot = {
//   0xfff,0xfff,0xfff,0xfff,0xfff,0xfff,0xfff,0xfff,
//   0xfff,0xfff,0xfff,0xfff,0xfff,0xfff,0xfff,0xfff,
//   0xfff,0xfff,0xfff,0xfff,0xfff,0xfff,0xfff,0xfff,
// };

// bool gem::readout::isFileRead = false;

namespace gem {
  namespace readout {

    static uint16_t gem::readout::slot = {
      0xfff,0xfff,0xfff,0xfff,0xfff,0xfff,0xfff,0xfff,
      0xfff,0xfff,0xfff,0xfff,0xfff,0xfff,0xfff,0xfff,
      0xfff,0xfff,0xfff,0xfff,0xfff,0xfff,0xfff,0xfff,
    };
    
    static bool gem::readout::isFileRead = false;

    // Intialize slot array
    void initSlots() {
      for (int i = 0; i < 24; ++i)
        slot[i] = 0xfff;
      isFileRead = false;
      return;
    };
    
    void getSlotCfg() {
      std::ifstream ifile;
      std::string path = std::getenv("BUILD_HOME");
      path +="/gemdaq-testing/gemreadout/data/slot_table.csv";
      ifile.open(path);

      if(!ifile.is_open()) {
        std::cout << "\nThe file: " << ifile << " is missing.\n" << std::endl;
      };

      for (int row = 0; row < 3; row++)
        {
          std::string line;
          std::getline(ifile, line);
          std::istringstream iss(line);
          if ( !ifile.good() ) break;
          for (int col = 0; col < 8; col++)
            {
              std::string val;
              std::getline(iss,val,',');
              std::stringstream convertor(val);
              convertor >> std::hex >> gem::readout::slot[8*row+col];
            }
        }
      ifile.close();
      gem::readout::isFileRead = true;
    };

    /*
     *  Slot Index converter from Hex ChipID
     */
    int GEBslotIndex(const uint32_t& GEBChipID) {
      if (!isFileRead) getSlotCfg();
      int indxslot = -1;
      for (int islot = 0; islot < 24; islot++){
        if ( (GEBChipID & 0x0fff ) == gem::readout::slot[islot] ) indxslot = islot;
      }//end for slot
      
      return (indxslot);
    };
  } //end namespace gem::readout
} //end namespace gem
