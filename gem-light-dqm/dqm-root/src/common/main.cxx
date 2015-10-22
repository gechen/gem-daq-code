#include "gemtreewriter/src/common/gemTreeWriter.cxx"
#include "dqm-root/src/common/treeReader.cxx"

using namespace std;
int main(int argc, char** argv)
{
  if (argc<3) 
  {
      cout << "Please provide input filenames" << endl;
      cout << "Usage: <path>/rundqm inputFile.dat slot_file.csv" << endl;
      return 0;
  }
  string m_dat_filename = argv[1];
  string m_slot_file = argv[2];
  gemTreeWriter *m_gemTreeWriter = new gemTreeWriter();
  m_gemTreeWriter->makeTree(m_dat_filename, m_slot_file);
  string m_raw_filename;
  m_raw_filename = m_gemTreeWriter->getOutputFileName();
  std::cout << "[MAIN]: ROOT TTree is finished" << std::endl;
  gemTreeReader *m_gemTreeReader = new gemTreeReader(m_raw_filename);
  m_gemTreeReader->createHistograms();

  return 0;
}
