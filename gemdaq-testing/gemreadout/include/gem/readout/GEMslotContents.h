#ifndef gem_readout_GEMslotContents_h
#define gem_readout_GEMslotContents_h
#include <fstream>
#include <sstream>
#include <cstdlib>

namespace gem {
  namespace readout {
    
    //static uint16_t slot[24]; 
    //static bool isFileRead;

    void initSlots();
    void getSlotCfg();
    
    /*
     *  Slot Index converter from Hex ChipID
     */
    int GEBslotIndex(const uint32_t& GEBChipID);
    
  } //end namespace gem::readout
} //end namespace gem
#endif
