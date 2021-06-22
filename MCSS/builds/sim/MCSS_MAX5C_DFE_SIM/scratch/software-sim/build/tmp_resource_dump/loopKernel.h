#ifndef LOOPKERNEL_H_
#define LOOPKERNEL_H_

// #include "KernelManagerBlockSync.h"


namespace maxcompilersim {

class loopKernel : public KernelManagerBlockSync {
public:
  loopKernel(const std::string &instance_name);

protected:
  virtual void runComputationCycle();
  virtual void ramInitialise();
  virtual void resetComputation();
  virtual void resetComputationAfterFlush();
          void updateState();
          void preExecute();
  virtual int  getFlushLevelStart();

private:
  t_port_number m_y;
  t_port_number m_z;
  HWFloat<8,24> id2068out_output[76];

  HWFloat<8,24> id1980out_value;

  HWOffsetFix<1,0,UNSIGNED> id7out_result[3];

  HWOffsetFix<1,0,UNSIGNED> id2out_value;

  HWOffsetFix<1,0,UNSIGNED> id3out_output;

  long id3st_count;
  HWOffsetFix<1,0,UNSIGNED> id3st_value;

  HWOffsetFix<1,0,UNSIGNED> id8out_result[2];

  HWFloat<8,24> id2346out_output[4];

  HWFloat<8,24> id23out_value;

  HWFloat<8,24> id24out_result[2];

  HWFloat<8,24> id1979out_value;

  HWOffsetFix<1,0,UNSIGNED> id1978out_value;

  HWOffsetFix<32,0,UNSIGNED> id2373out_value;

  HWOffsetFix<32,0,UNSIGNED> id5out_count;
  HWOffsetFix<1,0,UNSIGNED> id5out_wrap;

  HWOffsetFix<33,0,UNSIGNED> id5st_count;

  HWOffsetFix<32,0,UNSIGNED> id1977out_value;

  HWOffsetFix<1,0,UNSIGNED> id1335out_result[2];

  HWOffsetFix<1,0,UNSIGNED> id27out_io_y_force_disabled;

  HWRawBits<96> id30out_data;

  HWOffsetFix<1,0,UNSIGNED> id30st_read_next_cycle;
  HWRawBits<96> id30st_last_read_value;

  HWFloat<8,24> id1976out_value;

  HWOffsetFix<1,0,UNSIGNED> id101out_result[3];

  HWOffsetFix<1,0,UNSIGNED> id2093out_output[48];

  HWFloat<8,24> id102out_value;

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id2050out_value;

  HWOffsetFix<25,-23,TWOSCOMPLEMENT> id2049out_value;

  HWRawBits<1> id41out_value;

  HWRawBits<31> id1975out_value;

  HWOffsetFix<1,0,UNSIGNED> id1338out_result[2];

  HWRawBits<23> id2070out_output[2];

  HWOffsetFix<1,0,UNSIGNED> id2071out_output[2];

  HWOffsetFix<25,-23,TWOSCOMPLEMENT> id2002out_result[2];

  HWOffsetFix<25,-23,TWOSCOMPLEMENT> id1974out_value;

  HWOffsetFix<1,0,UNSIGNED> id1341out_result[2];

  HWOffsetFix<1,0,UNSIGNED> id2073out_output[2];

  HWOffsetFix<8,0,UNSIGNED> id2072out_output[3];

  HWOffsetFix<7,0,UNSIGNED> id1973out_value;

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id52out_result[2];

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id2074out_output[2];

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id1972out_value;

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id60out_result[2];

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id61out_result[2];

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id2004out_result[2];

  HWRawBits<8> id2075out_output[30];

  HWFloat<8,24> id1286out_dout[3];

  HWFloat<8,24> id1286sta_rom_store[256];

  HWOffsetFix<1,0,UNSIGNED> id2076out_output[33];

  HWRawBits<108> id1268out_dout[3];

  HWRawBits<108> id1268sta_rom_store[128];

  HWRawBits<108> id1277out_dout[3];

  HWRawBits<108> id1277sta_rom_store[128];

  HWOffsetFix<27,-23,TWOSCOMPLEMENT> id82out_result[2];

  HWOffsetFix<25,-24,UNSIGNED> id2078out_output[3];

  HWOffsetFix<17,-17,UNSIGNED> id78out_result[2];

  HWOffsetFix<44,-40,TWOSCOMPLEMENT> id83out_result[5];

  HWOffsetFix<27,-23,TWOSCOMPLEMENT> id81out_result[2];

  HWOffsetFix<27,-23,TWOSCOMPLEMENT> id2082out_output[5];

  HWOffsetFix<45,-40,TWOSCOMPLEMENT> id84out_result[2];

  HWOffsetFix<25,-20,TWOSCOMPLEMENT> id85out_o[2];

  HWOffsetFix<17,-17,UNSIGNED> id2083out_output[7];

  HWOffsetFix<42,-37,TWOSCOMPLEMENT> id86out_result[5];

  HWOffsetFix<27,-23,TWOSCOMPLEMENT> id80out_result[2];

  HWOffsetFix<27,-23,TWOSCOMPLEMENT> id2085out_output[11];

  HWOffsetFix<43,-37,TWOSCOMPLEMENT> id87out_result[2];

  HWOffsetFix<25,-19,TWOSCOMPLEMENT> id88out_o[2];

  HWOffsetFix<17,-17,UNSIGNED> id2347out_output[7];

  HWOffsetFix<42,-36,TWOSCOMPLEMENT> id89out_result[5];

  HWOffsetFix<27,-23,TWOSCOMPLEMENT> id79out_result[2];

  HWOffsetFix<27,-23,TWOSCOMPLEMENT> id2088out_output[17];

  HWOffsetFix<42,-36,TWOSCOMPLEMENT> id90out_result[2];

  HWOffsetFix<25,-19,TWOSCOMPLEMENT> id91out_o[2];

  HWFloat<8,24> id92out_o[7];

  HWOffsetFix<25,-24,UNSIGNED> id96out_result[2];

  HWOffsetFix<25,-24,UNSIGNED> id2092out_output[19];

  HWFloat<8,24> id97out_o[7];

  HWFloat<8,24> id98out_result[9];

  HWFloat<8,24> id99out_result[13];

  HWFloat<8,24> id103out_result[2];

  HWFloat<8,24> id2094out_output[33];

  HWFloat<8,24> id105out_result[9];

  HWFloat<8,24> id106out_result[12];

  HWFloat<8,24> id1971out_value;

  HWOffsetFix<1,0,UNSIGNED> id108out_result[3];

  HWOffsetFix<32,0,UNSIGNED> id2095out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id1970out_value;

  HWOffsetFix<32,0,UNSIGNED> id1254out_result[2];

  HWOffsetFix<1,0,UNSIGNED> id1349out_result[2];

  HWOffsetFix<1,0,UNSIGNED> id2096out_output[108];

  HWOffsetFix<1,0,UNSIGNED> id1256out_result[2];

  HWOffsetFix<1,0,UNSIGNED> id1257out_io_z_force_disabled;

  HWOffsetFix<1,0,UNSIGNED> id2345out_output[20];

  HWFloat<8,24> id2098out_output[57];

  HWFloat<8,24> id21out_value;

  HWFloat<8,24> id22out_result[2];

  HWFloat<8,24> id2099out_output[3];

  HWFloat<8,24> id2353out_output[13];

  HWFloat<8,24> id2100out_output[14];

  HWFloat<8,24> id1969out_value;

  HWFloat<8,24> id110out_result[12];

  HWFloat<8,24> id111out_result[2];

  HWFloat<8,24> id118out_result[12];

  HWFloat<8,24> id2097out_output[9];

  HWFloat<8,24> id2102out_output[57];

  HWFloat<8,24> id13out_value;

  HWFloat<8,24> id14out_result[2];

  HWFloat<8,24> id2339out_output[23];

  HWOffsetFix<1,0,UNSIGNED> id2312out_output[48];

  HWOffsetFix<1,0,UNSIGNED> id2348out_output[21];

  HWOffsetFix<1,0,UNSIGNED> id2349out_output[2];

  HWOffsetFix<1,0,UNSIGNED> id2350out_output[2];

  HWFloat<8,24> id2369out_output[22];

  HWFloat<8,24> id2370out_output[28];

  HWFloat<8,24> id2371out_output[17];

  HWFloat<8,24> id2372out_output[5];

  HWOffsetFix<1,0,UNSIGNED> id2318out_output[15];

  HWOffsetFix<1,0,UNSIGNED> id2351out_output[19];

  HWOffsetFix<1,0,UNSIGNED> id2352out_output[3];

  HWFloat<8,24> id2207out_output[22];

  HWFloat<8,24> id2364out_output[9];

  HWFloat<8,24> id2365out_output[40];

  HWFloat<8,24> id2366out_output[21];

  HWOffsetFix<1,0,UNSIGNED> id2368out_output[21];

  HWOffsetFix<1,0,UNSIGNED> id1201out_result[2];

  HWFloat<8,24> id1967out_value;

  HWFloat<8,24> id128out_value;

  HWFloat<8,24> id129out_value;

  HWFloat<8,24> id1966out_value;

  HWFloat<8,24> id1965out_value;

  HWFloat<8,24> id120out_result[9];

  HWFloat<8,24> id2108out_output[15];

  HWFloat<8,24> id1964out_value;

  HWFloat<8,24> id122out_result[12];

  HWFloat<8,24> id1963out_value;

  HWFloat<8,24> id124out_result[12];

  HWFloat<8,24> id125out_result[29];

  HWFloat<8,24> id127out_result[12];

  HWOffsetFix<1,0,UNSIGNED> id130out_result[3];

  HWFloat<8,24> id2109out_output[3];

  HWFloat<8,24> id131out_result[2];

  HWOffsetFix<1,0,UNSIGNED> id132out_result[3];

  HWFloat<8,24> id2110out_output[3];

  HWFloat<8,24> id133out_result[2];

  HWFloat<8,24> id135out_result[12];

  HWFloat<8,24> id2111out_output[12];

  HWFloat<8,24> id1962out_value;

  HWFloat<8,24> id137out_result[12];

  HWFloat<8,24> id138out_result[9];

  HWFloat<8,24> id139out_result[29];

  HWFloat<8,24> id1961out_value;

  HWFloat<8,24> id142out_result[9];

  HWFloat<8,24> id2116out_output[29];

  HWFloat<8,24> id2356out_output[7];

  HWFloat<8,24> id2357out_output[2];

  HWRawBits<31> id650out_value;

  HWOffsetFix<1,0,UNSIGNED> id1351out_result[2];

  HWRawBits<8> id655out_value;

  HWOffsetFix<1,0,UNSIGNED> id1353out_result[2];

  HWRawBits<23> id1960out_value;

  HWOffsetFix<1,0,UNSIGNED> id1355out_result[2];

  HWOffsetFix<1,0,UNSIGNED> id659out_result[2];

  HWOffsetFix<1,0,UNSIGNED> id660out_result[2];

  HWOffsetFix<1,0,UNSIGNED> id2206out_output[80];

  HWOffsetFix<1,0,UNSIGNED> id148out_value;

  HWOffsetFix<7,0,UNSIGNED> id1959out_value;

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id1958out_value;

  HWOffsetFix<10,0,TWOSCOMPLEMENT> id1985out_result[2];

  HWOffsetFix<1,0,UNSIGNED> id2117out_output[6];

  HWRawBits<185> id159out_value;

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id2048out_value;

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id2012out_result[2];

  HWRawBits<185> id169out_dataout[5];

  HWRawBits<185> id168out_dataout[5];

  HWRawBits<185> id170out_result[2];

  HWOffsetFix<81,0,UNSIGNED> id174out_result[2];

  HWOffsetFix<80,0,UNSIGNED> id183out_output[2];

  HWOffsetFix<7,0,UNSIGNED> id184out_output[2];

  HWOffsetFix<7,0,UNSIGNED> id184st_one_hot_or;

  HWOffsetFix<8,0,TWOSCOMPLEMENT> id1955out_value;

  HWOffsetFix<8,0,TWOSCOMPLEMENT> id1954out_value;

  HWOffsetFix<10,0,TWOSCOMPLEMENT> id1987out_result[2];

  HWOffsetFix<8,0,TWOSCOMPLEMENT> id2118out_output[5];

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id1953out_value;

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id204out_result[2];

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id1952out_value;

  HWOffsetFix<1,0,UNSIGNED> id1364out_result[2];

  HWOffsetFix<1,0,UNSIGNED> id2123out_output[2];

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id1951out_value;

  HWOffsetFix<1,0,UNSIGNED> id1365out_result[2];

  HWOffsetFix<1,0,UNSIGNED> id1333out_value;

  HWOffsetFix<8,0,UNSIGNED> id2122out_output[2];

  HWOffsetFix<8,0,TWOSCOMPLEMENT> id1950out_value;

  HWOffsetFix<8,0,TWOSCOMPLEMENT> id1949out_value;

  HWOffsetFix<10,0,TWOSCOMPLEMENT> id1989out_result[2];

  HWOffsetFix<8,0,TWOSCOMPLEMENT> id1948out_value;

  HWOffsetFix<1,0,UNSIGNED> id1366out_result[2];

  HWOffsetFix<1,0,UNSIGNED> id2120out_output[4];

  HWOffsetFix<80,-79,TWOSCOMPLEMENT> id2119out_output[4];

  HWOffsetFix<80,-79,TWOSCOMPLEMENT> id2358out_output[5];

  HWRawBits<80> id197out_dataout[5];

  HWOffsetFix<80,-79,TWOSCOMPLEMENT> id199out_result[2];

  HWOffsetFix<24,-23,UNSIGNED> id205out_o[2];

  HWFloat<8,24> id214out_value;

  HWFloat<8,24> id215out_result[2];

  HWFloat<8,24> id218out_value;

  HWFloat<8,24> id219out_result[2];

  HWFloat<8,24> id2124out_output[2];

  HWFloat<8,24> id1947out_value;

  HWOffsetFix<1,0,UNSIGNED> id642out_result[3];

  HWFloat<8,24> id1946out_value;

  HWOffsetFix<1,0,UNSIGNED> id644out_result[3];

  HWOffsetFix<1,0,UNSIGNED> id645out_result[2];

  HWOffsetFix<1,0,UNSIGNED> id2204out_output[65];

  HWRawBits<1> id2136out_output[30];

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id1945out_value;

  HWOffsetFix<7,0,UNSIGNED> id1944out_value;

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id1991out_result[2];

  HWOffsetFix<1,0,UNSIGNED> id2129out_output[5];

  HWOffsetFix<5,0,UNSIGNED> id238out_value;

  HWOffsetFix<25,-23,TWOSCOMPLEMENT> id2047out_value;

  HWRawBits<1> id230out_value;

  HWRawBits<31> id1943out_value;

  HWOffsetFix<1,0,UNSIGNED> id1371out_result[2];

  HWOffsetFix<25,-23,TWOSCOMPLEMENT> id2014out_result[2];

  HWRawBits<30> id249out_dataout[5];

  HWOffsetFix<7,0,UNSIGNED> id252out_value;

  HWOffsetFix<7,0,UNSIGNED> id253out_result[2];

  HWOffsetFix<7,0,UNSIGNED> id2130out_output[10];

  HWRawBits<128> id1287out_dout[3];

  HWRawBits<128> id1287sta_rom_store[128];

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id1942out_value;

  HWOffsetFix<7,0,UNSIGNED> id1941out_value;

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id1992out_result[2];

  HWOffsetFix<1,0,UNSIGNED> id2134out_output[5];

  HWOffsetFix<5,0,UNSIGNED> id439out_value;

  HWOffsetFix<25,-23,TWOSCOMPLEMENT> id2046out_value;

  HWRawBits<1> id431out_value;

  HWRawBits<31> id1940out_value;

  HWOffsetFix<1,0,UNSIGNED> id1375out_result[2];

  HWOffsetFix<25,-23,TWOSCOMPLEMENT> id2016out_result[2];

  HWRawBits<30> id450out_dataout[5];

  HWOffsetFix<7,0,UNSIGNED> id453out_value;

  HWOffsetFix<7,0,UNSIGNED> id454out_result[2];

  HWOffsetFix<7,0,UNSIGNED> id2135out_output[10];

  HWRawBits<128> id1296out_dout[3];

  HWRawBits<128> id1296sta_rom_store[128];

  HWFloat<8,24> id632out_result[2];

  HWFloat<8,24> id1981out_floatOut[2];

  HWFloat<8,24> id2137out_output[4];

  HWRawBits<1> id2166out_output[7];

  HWOffsetFix<7,0,UNSIGNED> id1938out_value;

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id259out_result[2];

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id1937out_value;

  HWOffsetFix<1,0,UNSIGNED> id1377out_result[2];

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id1936out_value;

  HWOffsetFix<1,0,UNSIGNED> id1378out_result[2];

  HWOffsetFix<1,0,UNSIGNED> id268out_result[2];

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id1935out_value;

  HWOffsetFix<1,0,UNSIGNED> id1379out_result[2];

  HWOffsetFix<1,0,UNSIGNED> id2138out_output[2];

  HWOffsetFix<2,0,UNSIGNED> id2164out_output[6];

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id1934out_value;

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id1933out_value;

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id279out_result[2];

  HWOffsetFix<1,0,UNSIGNED> id1380out_result[2];

  HWRawBits<1> id415out_value;

  HWRawBits<1> id416out_result[2];

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id1932out_value;

  HWOffsetFix<1,0,UNSIGNED> id1382out_result[2];

  HWRawBits<1> id409out_value;

  HWRawBits<1> id410out_result[2];

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id1931out_value;

  HWOffsetFix<1,0,UNSIGNED> id1384out_result[2];

  HWRawBits<1> id403out_value;

  HWRawBits<1> id404out_result[2];

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id1930out_value;

  HWOffsetFix<1,0,UNSIGNED> id1386out_result[2];

  HWRawBits<1> id397out_value;

  HWRawBits<1> id398out_result[2];

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id1929out_value;

  HWOffsetFix<1,0,UNSIGNED> id1388out_result[2];

  HWRawBits<1> id391out_value;

  HWRawBits<1> id392out_result[2];

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id1928out_value;

  HWOffsetFix<1,0,UNSIGNED> id1390out_result[2];

  HWRawBits<1> id385out_value;

  HWRawBits<1> id386out_result[2];

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id1927out_value;

  HWOffsetFix<1,0,UNSIGNED> id1392out_result[2];

  HWRawBits<1> id379out_value;

  HWRawBits<1> id380out_result[2];

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id1926out_value;

  HWOffsetFix<1,0,UNSIGNED> id1394out_result[2];

  HWRawBits<1> id373out_value;

  HWRawBits<1> id374out_result[2];

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id1925out_value;

  HWOffsetFix<1,0,UNSIGNED> id1396out_result[2];

  HWRawBits<1> id367out_value;

  HWRawBits<1> id368out_result[2];

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id1924out_value;

  HWOffsetFix<1,0,UNSIGNED> id1398out_result[2];

  HWRawBits<1> id361out_value;

  HWRawBits<1> id362out_result[2];

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id1923out_value;

  HWOffsetFix<1,0,UNSIGNED> id1400out_result[2];

  HWRawBits<1> id355out_value;

  HWRawBits<1> id356out_result[2];

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id1922out_value;

  HWOffsetFix<1,0,UNSIGNED> id1402out_result[2];

  HWRawBits<1> id349out_value;

  HWRawBits<1> id350out_result[2];

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id1921out_value;

  HWOffsetFix<1,0,UNSIGNED> id1404out_result[2];

  HWRawBits<1> id343out_value;

  HWRawBits<1> id344out_result[2];

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id1920out_value;

  HWOffsetFix<1,0,UNSIGNED> id1406out_result[2];

  HWRawBits<1> id337out_value;

  HWRawBits<1> id338out_result[2];

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id1919out_value;

  HWOffsetFix<1,0,UNSIGNED> id1408out_result[2];

  HWRawBits<1> id331out_value;

  HWRawBits<1> id332out_result[2];

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id1918out_value;

  HWOffsetFix<1,0,UNSIGNED> id1410out_result[2];

  HWRawBits<1> id325out_value;

  HWRawBits<1> id326out_result[2];

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id1917out_value;

  HWOffsetFix<1,0,UNSIGNED> id1412out_result[2];

  HWRawBits<1> id319out_value;

  HWRawBits<1> id320out_result[2];

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id1916out_value;

  HWOffsetFix<1,0,UNSIGNED> id1414out_result[2];

  HWRawBits<1> id313out_value;

  HWRawBits<1> id314out_result[2];

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id1915out_value;

  HWOffsetFix<1,0,UNSIGNED> id1416out_result[2];

  HWRawBits<1> id307out_value;

  HWRawBits<1> id308out_result[2];

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id1914out_value;

  HWOffsetFix<1,0,UNSIGNED> id1418out_result[2];

  HWRawBits<1> id301out_value;

  HWRawBits<1> id302out_result[2];

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id1913out_value;

  HWOffsetFix<1,0,UNSIGNED> id1420out_result[2];

  HWRawBits<1> id295out_value;

  HWRawBits<1> id296out_result[2];

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id1912out_value;

  HWOffsetFix<1,0,UNSIGNED> id1422out_result[2];

  HWRawBits<1> id289out_value;

  HWRawBits<1> id290out_result[2];

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id1911out_value;

  HWOffsetFix<1,0,UNSIGNED> id1424out_result[2];

  HWRawBits<1> id283out_value;

  HWRawBits<1> id284out_result[2];

  HWOffsetFix<1,0,UNSIGNED> id277out_value;

  HWOffsetFix<5,0,UNSIGNED> id2162out_output[4];

  HWRawBits<24> id419out_dataout[5];

  HWOffsetFix<1,0,UNSIGNED> id260out_value;

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id272out_result[2];

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id1910out_value;

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id274out_result[2];

  HWRawBits<24> id276out_dataout[5];

  HWRawBits<24> id2165out_output[2];

  HWRawBits<24> id1909out_value;

  HWRawBits<24> id422out_result[2];

  HWRawBits<24> id424out_result[2];

  HWFloat<8,24> id426out_o[8];

  HWFloat<8,24> id1982out_floatOut[2];

  HWFloat<8,24> id2167out_output[4];

  HWRawBits<1> id2196out_output[7];

  HWOffsetFix<7,0,UNSIGNED> id1907out_value;

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id460out_result[2];

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id1906out_value;

  HWOffsetFix<1,0,UNSIGNED> id1448out_result[2];

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id1905out_value;

  HWOffsetFix<1,0,UNSIGNED> id1449out_result[2];

  HWOffsetFix<1,0,UNSIGNED> id469out_result[2];

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id1904out_value;

  HWOffsetFix<1,0,UNSIGNED> id1450out_result[2];

  HWOffsetFix<1,0,UNSIGNED> id2168out_output[2];

  HWOffsetFix<2,0,UNSIGNED> id2194out_output[6];

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id1903out_value;

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id1902out_value;

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id480out_result[2];

  HWOffsetFix<1,0,UNSIGNED> id1451out_result[2];

  HWRawBits<1> id616out_value;

  HWRawBits<1> id617out_result[2];

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id1901out_value;

  HWOffsetFix<1,0,UNSIGNED> id1453out_result[2];

  HWRawBits<1> id610out_value;

  HWRawBits<1> id611out_result[2];

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id1900out_value;

  HWOffsetFix<1,0,UNSIGNED> id1455out_result[2];

  HWRawBits<1> id604out_value;

  HWRawBits<1> id605out_result[2];

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id1899out_value;

  HWOffsetFix<1,0,UNSIGNED> id1457out_result[2];

  HWRawBits<1> id598out_value;

  HWRawBits<1> id599out_result[2];

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id1898out_value;

  HWOffsetFix<1,0,UNSIGNED> id1459out_result[2];

  HWRawBits<1> id592out_value;

  HWRawBits<1> id593out_result[2];

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id1897out_value;

  HWOffsetFix<1,0,UNSIGNED> id1461out_result[2];

  HWRawBits<1> id586out_value;

  HWRawBits<1> id587out_result[2];

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id1896out_value;

  HWOffsetFix<1,0,UNSIGNED> id1463out_result[2];

  HWRawBits<1> id580out_value;

  HWRawBits<1> id581out_result[2];

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id1895out_value;

  HWOffsetFix<1,0,UNSIGNED> id1465out_result[2];

  HWRawBits<1> id574out_value;

  HWRawBits<1> id575out_result[2];

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id1894out_value;

  HWOffsetFix<1,0,UNSIGNED> id1467out_result[2];

  HWRawBits<1> id568out_value;

  HWRawBits<1> id569out_result[2];

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id1893out_value;

  HWOffsetFix<1,0,UNSIGNED> id1469out_result[2];

  HWRawBits<1> id562out_value;

  HWRawBits<1> id563out_result[2];

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id1892out_value;

  HWOffsetFix<1,0,UNSIGNED> id1471out_result[2];

  HWRawBits<1> id556out_value;

  HWRawBits<1> id557out_result[2];

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id1891out_value;

  HWOffsetFix<1,0,UNSIGNED> id1473out_result[2];

  HWRawBits<1> id550out_value;

  HWRawBits<1> id551out_result[2];

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id1890out_value;

  HWOffsetFix<1,0,UNSIGNED> id1475out_result[2];

  HWRawBits<1> id544out_value;

  HWRawBits<1> id545out_result[2];

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id1889out_value;

  HWOffsetFix<1,0,UNSIGNED> id1477out_result[2];

  HWRawBits<1> id538out_value;

  HWRawBits<1> id539out_result[2];

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id1888out_value;

  HWOffsetFix<1,0,UNSIGNED> id1479out_result[2];

  HWRawBits<1> id532out_value;

  HWRawBits<1> id533out_result[2];

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id1887out_value;

  HWOffsetFix<1,0,UNSIGNED> id1481out_result[2];

  HWRawBits<1> id526out_value;

  HWRawBits<1> id527out_result[2];

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id1886out_value;

  HWOffsetFix<1,0,UNSIGNED> id1483out_result[2];

  HWRawBits<1> id520out_value;

  HWRawBits<1> id521out_result[2];

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id1885out_value;

  HWOffsetFix<1,0,UNSIGNED> id1485out_result[2];

  HWRawBits<1> id514out_value;

  HWRawBits<1> id515out_result[2];

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id1884out_value;

  HWOffsetFix<1,0,UNSIGNED> id1487out_result[2];

  HWRawBits<1> id508out_value;

  HWRawBits<1> id509out_result[2];

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id1883out_value;

  HWOffsetFix<1,0,UNSIGNED> id1489out_result[2];

  HWRawBits<1> id502out_value;

  HWRawBits<1> id503out_result[2];

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id1882out_value;

  HWOffsetFix<1,0,UNSIGNED> id1491out_result[2];

  HWRawBits<1> id496out_value;

  HWRawBits<1> id497out_result[2];

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id1881out_value;

  HWOffsetFix<1,0,UNSIGNED> id1493out_result[2];

  HWRawBits<1> id490out_value;

  HWRawBits<1> id491out_result[2];

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id1880out_value;

  HWOffsetFix<1,0,UNSIGNED> id1495out_result[2];

  HWRawBits<1> id484out_value;

  HWRawBits<1> id485out_result[2];

  HWOffsetFix<1,0,UNSIGNED> id478out_value;

  HWOffsetFix<5,0,UNSIGNED> id2192out_output[4];

  HWRawBits<24> id620out_dataout[5];

  HWOffsetFix<1,0,UNSIGNED> id461out_value;

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id473out_result[2];

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id1879out_value;

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id475out_result[2];

  HWRawBits<24> id477out_dataout[5];

  HWRawBits<24> id2195out_output[2];

  HWRawBits<24> id1878out_value;

  HWRawBits<24> id623out_result[2];

  HWRawBits<24> id625out_result[2];

  HWFloat<8,24> id627out_o[8];

  HWFloat<8,24> id628out_result[2];

  HWFloat<8,24> id634out_result[9];

  HWFloat<8,24> id633out_result[9];

  HWFloat<8,24> id635out_result[9];

  HWFloat<8,24> id631out_result[2];

  HWFloat<8,24> id2199out_output[9];

  HWFloat<8,24> id636out_result[9];

  HWFloat<8,24> id637out_result[12];

  HWFloat<8,24> id630out_result[2];

  HWFloat<8,24> id638out_result[9];

  HWFloat<8,24> id2201out_output[20];

  HWFloat<8,24> id639out_result[12];

  HWFloat<8,24> id629out_result[2];

  HWFloat<8,24> id2203out_output[39];

  HWFloat<8,24> id640out_result[12];

  HWFloat<8,24> id1877out_value;

  HWFloat<8,24> id647out_result[2];

  HWRawBits<2> id1957out_value;

  HWOffsetFix<1,0,UNSIGNED> id1362out_result[2];

  HWRawBits<2> id1956out_value;

  HWOffsetFix<1,0,UNSIGNED> id1363out_result[2];

  HWOffsetFix<1,0,UNSIGNED> id225out_result[2];

  HWOffsetFix<1,0,UNSIGNED> id2205out_output[79];

  HWFloat<8,24> id661out_value;

  HWFloat<8,24> id662out_result[2];

  HWFloat<8,24> id663out_result[9];

  HWFloat<8,24> id2331out_output[20];

  HWFloat<8,24> id2359out_output[40];

  HWFloat<8,24> id1202out_result[9];

  HWFloat<8,24> id1203out_result[9];

  HWFloat<8,24> id2362out_output[40];

  HWFloat<8,24> id2363out_output[21];

  HWOffsetFix<1,0,UNSIGNED> id1211out_result[2];

  HWRawBits<31> id1176out_value;

  HWOffsetFix<1,0,UNSIGNED> id1520out_result[2];

  HWRawBits<8> id1181out_value;

  HWOffsetFix<1,0,UNSIGNED> id1522out_result[2];

  HWRawBits<23> id1876out_value;

  HWOffsetFix<1,0,UNSIGNED> id1524out_result[2];

  HWOffsetFix<1,0,UNSIGNED> id1185out_result[2];

  HWOffsetFix<1,0,UNSIGNED> id1186out_result[2];

  HWOffsetFix<1,0,UNSIGNED> id2308out_output[80];

  HWOffsetFix<1,0,UNSIGNED> id671out_value;

  HWOffsetFix<7,0,UNSIGNED> id1874out_value;

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id1873out_value;

  HWOffsetFix<10,0,TWOSCOMPLEMENT> id1993out_result[2];

  HWOffsetFix<1,0,UNSIGNED> id2217out_output[6];

  HWRawBits<185> id682out_value;

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id2045out_value;

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id2023out_result[2];

  HWRawBits<185> id692out_dataout[5];

  HWRawBits<185> id691out_dataout[5];

  HWRawBits<185> id693out_result[2];

  HWOffsetFix<81,0,UNSIGNED> id697out_result[2];

  HWOffsetFix<80,0,UNSIGNED> id709out_output[2];

  HWOffsetFix<7,0,UNSIGNED> id710out_output[2];

  HWOffsetFix<7,0,UNSIGNED> id710st_one_hot_or;

  HWOffsetFix<8,0,TWOSCOMPLEMENT> id1869out_value;

  HWOffsetFix<8,0,TWOSCOMPLEMENT> id1868out_value;

  HWOffsetFix<10,0,TWOSCOMPLEMENT> id1995out_result[2];

  HWOffsetFix<8,0,TWOSCOMPLEMENT> id2218out_output[5];

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id1867out_value;

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id730out_result[2];

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id1866out_value;

  HWOffsetFix<1,0,UNSIGNED> id1533out_result[2];

  HWOffsetFix<1,0,UNSIGNED> id2223out_output[2];

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id1865out_value;

  HWOffsetFix<1,0,UNSIGNED> id1534out_result[2];

  HWOffsetFix<1,0,UNSIGNED> id1334out_value;

  HWOffsetFix<8,0,UNSIGNED> id2222out_output[2];

  HWOffsetFix<8,0,TWOSCOMPLEMENT> id1864out_value;

  HWOffsetFix<8,0,TWOSCOMPLEMENT> id1863out_value;

  HWOffsetFix<10,0,TWOSCOMPLEMENT> id1997out_result[2];

  HWOffsetFix<8,0,TWOSCOMPLEMENT> id1862out_value;

  HWOffsetFix<1,0,UNSIGNED> id1535out_result[2];

  HWOffsetFix<1,0,UNSIGNED> id2220out_output[4];

  HWOffsetFix<80,-79,TWOSCOMPLEMENT> id2219out_output[4];

  HWOffsetFix<80,-79,TWOSCOMPLEMENT> id2360out_output[5];

  HWRawBits<80> id723out_dataout[5];

  HWOffsetFix<80,-79,TWOSCOMPLEMENT> id725out_result[2];

  HWOffsetFix<24,-23,UNSIGNED> id731out_o[2];

  HWFloat<8,24> id740out_value;

  HWFloat<8,24> id741out_result[2];

  HWFloat<8,24> id744out_value;

  HWFloat<8,24> id745out_result[2];

  HWFloat<8,24> id2224out_output[2];

  HWFloat<8,24> id1861out_value;

  HWOffsetFix<1,0,UNSIGNED> id1168out_result[3];

  HWFloat<8,24> id1860out_value;

  HWOffsetFix<1,0,UNSIGNED> id1170out_result[3];

  HWOffsetFix<1,0,UNSIGNED> id1171out_result[2];

  HWOffsetFix<1,0,UNSIGNED> id2306out_output[65];

  HWFloat<8,24> id1875out_value;

  HWOffsetFix<1,0,UNSIGNED> id665out_result[3];

  HWRawBits<2> id2227out_output[2];

  HWRawBits<2> id1872out_value;

  HWRawBits<2> id702out_result[2];

  HWRawBits<2> id703out_result[2];

  HWRawBits<1> id2238out_output[28];

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id1859out_value;

  HWOffsetFix<7,0,UNSIGNED> id1858out_value;

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id1999out_result[2];

  HWOffsetFix<1,0,UNSIGNED> id2231out_output[5];

  HWOffsetFix<5,0,UNSIGNED> id764out_value;

  HWOffsetFix<25,-23,TWOSCOMPLEMENT> id2044out_value;

  HWRawBits<1> id756out_value;

  HWRawBits<31> id1857out_value;

  HWOffsetFix<1,0,UNSIGNED> id1539out_result[2];

  HWOffsetFix<25,-23,TWOSCOMPLEMENT> id2025out_result[2];

  HWRawBits<30> id775out_dataout[5];

  HWOffsetFix<7,0,UNSIGNED> id778out_value;

  HWOffsetFix<7,0,UNSIGNED> id779out_result[2];

  HWOffsetFix<7,0,UNSIGNED> id2232out_output[10];

  HWRawBits<128> id1305out_dout[3];

  HWRawBits<128> id1305sta_rom_store[128];

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id1856out_value;

  HWOffsetFix<7,0,UNSIGNED> id1855out_value;

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id2000out_result[2];

  HWOffsetFix<1,0,UNSIGNED> id2236out_output[5];

  HWOffsetFix<5,0,UNSIGNED> id965out_value;

  HWOffsetFix<25,-23,TWOSCOMPLEMENT> id2043out_value;

  HWRawBits<1> id957out_value;

  HWRawBits<31> id1854out_value;

  HWOffsetFix<1,0,UNSIGNED> id1543out_result[2];

  HWOffsetFix<25,-23,TWOSCOMPLEMENT> id2027out_result[2];

  HWRawBits<30> id976out_dataout[5];

  HWOffsetFix<7,0,UNSIGNED> id979out_value;

  HWOffsetFix<7,0,UNSIGNED> id980out_result[2];

  HWOffsetFix<7,0,UNSIGNED> id2237out_output[10];

  HWRawBits<128> id1314out_dout[3];

  HWRawBits<128> id1314sta_rom_store[128];

  HWFloat<8,24> id1158out_result[2];

  HWFloat<8,24> id1983out_floatOut[2];

  HWFloat<8,24> id2239out_output[4];

  HWRawBits<1> id2268out_output[7];

  HWOffsetFix<7,0,UNSIGNED> id1852out_value;

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id785out_result[2];

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id1851out_value;

  HWOffsetFix<1,0,UNSIGNED> id1545out_result[2];

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id1850out_value;

  HWOffsetFix<1,0,UNSIGNED> id1546out_result[2];

  HWOffsetFix<1,0,UNSIGNED> id794out_result[2];

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id1849out_value;

  HWOffsetFix<1,0,UNSIGNED> id1547out_result[2];

  HWOffsetFix<1,0,UNSIGNED> id2240out_output[2];

  HWOffsetFix<2,0,UNSIGNED> id2266out_output[6];

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id1848out_value;

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id1847out_value;

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id805out_result[2];

  HWOffsetFix<1,0,UNSIGNED> id1548out_result[2];

  HWRawBits<1> id941out_value;

  HWRawBits<1> id942out_result[2];

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id1846out_value;

  HWOffsetFix<1,0,UNSIGNED> id1550out_result[2];

  HWRawBits<1> id935out_value;

  HWRawBits<1> id936out_result[2];

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id1845out_value;

  HWOffsetFix<1,0,UNSIGNED> id1552out_result[2];

  HWRawBits<1> id929out_value;

  HWRawBits<1> id930out_result[2];

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id1844out_value;

  HWOffsetFix<1,0,UNSIGNED> id1554out_result[2];

  HWRawBits<1> id923out_value;

  HWRawBits<1> id924out_result[2];

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id1843out_value;

  HWOffsetFix<1,0,UNSIGNED> id1556out_result[2];

  HWRawBits<1> id917out_value;

  HWRawBits<1> id918out_result[2];

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id1842out_value;

  HWOffsetFix<1,0,UNSIGNED> id1558out_result[2];

  HWRawBits<1> id911out_value;

  HWRawBits<1> id912out_result[2];

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id1841out_value;

  HWOffsetFix<1,0,UNSIGNED> id1560out_result[2];

  HWRawBits<1> id905out_value;

  HWRawBits<1> id906out_result[2];

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id1840out_value;

  HWOffsetFix<1,0,UNSIGNED> id1562out_result[2];

  HWRawBits<1> id899out_value;

  HWRawBits<1> id900out_result[2];

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id1839out_value;

  HWOffsetFix<1,0,UNSIGNED> id1564out_result[2];

  HWRawBits<1> id893out_value;

  HWRawBits<1> id894out_result[2];

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id1838out_value;

  HWOffsetFix<1,0,UNSIGNED> id1566out_result[2];

  HWRawBits<1> id887out_value;

  HWRawBits<1> id888out_result[2];

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id1837out_value;

  HWOffsetFix<1,0,UNSIGNED> id1568out_result[2];

  HWRawBits<1> id881out_value;

  HWRawBits<1> id882out_result[2];

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id1836out_value;

  HWOffsetFix<1,0,UNSIGNED> id1570out_result[2];

  HWRawBits<1> id875out_value;

  HWRawBits<1> id876out_result[2];

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id1835out_value;

  HWOffsetFix<1,0,UNSIGNED> id1572out_result[2];

  HWRawBits<1> id869out_value;

  HWRawBits<1> id870out_result[2];

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id1834out_value;

  HWOffsetFix<1,0,UNSIGNED> id1574out_result[2];

  HWRawBits<1> id863out_value;

  HWRawBits<1> id864out_result[2];

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id1833out_value;

  HWOffsetFix<1,0,UNSIGNED> id1576out_result[2];

  HWRawBits<1> id857out_value;

  HWRawBits<1> id858out_result[2];

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id1832out_value;

  HWOffsetFix<1,0,UNSIGNED> id1578out_result[2];

  HWRawBits<1> id851out_value;

  HWRawBits<1> id852out_result[2];

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id1831out_value;

  HWOffsetFix<1,0,UNSIGNED> id1580out_result[2];

  HWRawBits<1> id845out_value;

  HWRawBits<1> id846out_result[2];

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id1830out_value;

  HWOffsetFix<1,0,UNSIGNED> id1582out_result[2];

  HWRawBits<1> id839out_value;

  HWRawBits<1> id840out_result[2];

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id1829out_value;

  HWOffsetFix<1,0,UNSIGNED> id1584out_result[2];

  HWRawBits<1> id833out_value;

  HWRawBits<1> id834out_result[2];

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id1828out_value;

  HWOffsetFix<1,0,UNSIGNED> id1586out_result[2];

  HWRawBits<1> id827out_value;

  HWRawBits<1> id828out_result[2];

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id1827out_value;

  HWOffsetFix<1,0,UNSIGNED> id1588out_result[2];

  HWRawBits<1> id821out_value;

  HWRawBits<1> id822out_result[2];

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id1826out_value;

  HWOffsetFix<1,0,UNSIGNED> id1590out_result[2];

  HWRawBits<1> id815out_value;

  HWRawBits<1> id816out_result[2];

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id1825out_value;

  HWOffsetFix<1,0,UNSIGNED> id1592out_result[2];

  HWRawBits<1> id809out_value;

  HWRawBits<1> id810out_result[2];

  HWOffsetFix<1,0,UNSIGNED> id803out_value;

  HWOffsetFix<5,0,UNSIGNED> id2264out_output[4];

  HWRawBits<24> id945out_dataout[5];

  HWOffsetFix<1,0,UNSIGNED> id786out_value;

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id798out_result[2];

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id1824out_value;

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id800out_result[2];

  HWRawBits<24> id802out_dataout[5];

  HWRawBits<24> id2267out_output[2];

  HWRawBits<24> id1823out_value;

  HWRawBits<24> id948out_result[2];

  HWRawBits<24> id950out_result[2];

  HWFloat<8,24> id952out_o[8];

  HWFloat<8,24> id1984out_floatOut[2];

  HWFloat<8,24> id2269out_output[4];

  HWRawBits<1> id2298out_output[7];

  HWOffsetFix<7,0,UNSIGNED> id1821out_value;

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id986out_result[2];

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id1820out_value;

  HWOffsetFix<1,0,UNSIGNED> id1616out_result[2];

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id1819out_value;

  HWOffsetFix<1,0,UNSIGNED> id1617out_result[2];

  HWOffsetFix<1,0,UNSIGNED> id995out_result[2];

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id1818out_value;

  HWOffsetFix<1,0,UNSIGNED> id1618out_result[2];

  HWOffsetFix<1,0,UNSIGNED> id2270out_output[2];

  HWOffsetFix<2,0,UNSIGNED> id2296out_output[6];

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id1817out_value;

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id1816out_value;

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id1006out_result[2];

  HWOffsetFix<1,0,UNSIGNED> id1619out_result[2];

  HWRawBits<1> id1142out_value;

  HWRawBits<1> id1143out_result[2];

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id1815out_value;

  HWOffsetFix<1,0,UNSIGNED> id1621out_result[2];

  HWRawBits<1> id1136out_value;

  HWRawBits<1> id1137out_result[2];

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id1814out_value;

  HWOffsetFix<1,0,UNSIGNED> id1623out_result[2];

  HWRawBits<1> id1130out_value;

  HWRawBits<1> id1131out_result[2];

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id1813out_value;

  HWOffsetFix<1,0,UNSIGNED> id1625out_result[2];

  HWRawBits<1> id1124out_value;

  HWRawBits<1> id1125out_result[2];

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id1812out_value;

  HWOffsetFix<1,0,UNSIGNED> id1627out_result[2];

  HWRawBits<1> id1118out_value;

  HWRawBits<1> id1119out_result[2];

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id1811out_value;

  HWOffsetFix<1,0,UNSIGNED> id1629out_result[2];

  HWRawBits<1> id1112out_value;

  HWRawBits<1> id1113out_result[2];

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id1810out_value;

  HWOffsetFix<1,0,UNSIGNED> id1631out_result[2];

  HWRawBits<1> id1106out_value;

  HWRawBits<1> id1107out_result[2];

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id1809out_value;

  HWOffsetFix<1,0,UNSIGNED> id1633out_result[2];

  HWRawBits<1> id1100out_value;

  HWRawBits<1> id1101out_result[2];

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id1808out_value;

  HWOffsetFix<1,0,UNSIGNED> id1635out_result[2];

  HWRawBits<1> id1094out_value;

  HWRawBits<1> id1095out_result[2];

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id1807out_value;

  HWOffsetFix<1,0,UNSIGNED> id1637out_result[2];

  HWRawBits<1> id1088out_value;

  HWRawBits<1> id1089out_result[2];

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id1806out_value;

  HWOffsetFix<1,0,UNSIGNED> id1639out_result[2];

  HWRawBits<1> id1082out_value;

  HWRawBits<1> id1083out_result[2];

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id1805out_value;

  HWOffsetFix<1,0,UNSIGNED> id1641out_result[2];

  HWRawBits<1> id1076out_value;

  HWRawBits<1> id1077out_result[2];

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id1804out_value;

  HWOffsetFix<1,0,UNSIGNED> id1643out_result[2];

  HWRawBits<1> id1070out_value;

  HWRawBits<1> id1071out_result[2];

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id1803out_value;

  HWOffsetFix<1,0,UNSIGNED> id1645out_result[2];

  HWRawBits<1> id1064out_value;

  HWRawBits<1> id1065out_result[2];

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id1802out_value;

  HWOffsetFix<1,0,UNSIGNED> id1647out_result[2];

  HWRawBits<1> id1058out_value;

  HWRawBits<1> id1059out_result[2];

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id1801out_value;

  HWOffsetFix<1,0,UNSIGNED> id1649out_result[2];

  HWRawBits<1> id1052out_value;

  HWRawBits<1> id1053out_result[2];

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id1800out_value;

  HWOffsetFix<1,0,UNSIGNED> id1651out_result[2];

  HWRawBits<1> id1046out_value;

  HWRawBits<1> id1047out_result[2];

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id1799out_value;

  HWOffsetFix<1,0,UNSIGNED> id1653out_result[2];

  HWRawBits<1> id1040out_value;

  HWRawBits<1> id1041out_result[2];

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id1798out_value;

  HWOffsetFix<1,0,UNSIGNED> id1655out_result[2];

  HWRawBits<1> id1034out_value;

  HWRawBits<1> id1035out_result[2];

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id1797out_value;

  HWOffsetFix<1,0,UNSIGNED> id1657out_result[2];

  HWRawBits<1> id1028out_value;

  HWRawBits<1> id1029out_result[2];

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id1796out_value;

  HWOffsetFix<1,0,UNSIGNED> id1659out_result[2];

  HWRawBits<1> id1022out_value;

  HWRawBits<1> id1023out_result[2];

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id1795out_value;

  HWOffsetFix<1,0,UNSIGNED> id1661out_result[2];

  HWRawBits<1> id1016out_value;

  HWRawBits<1> id1017out_result[2];

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id1794out_value;

  HWOffsetFix<1,0,UNSIGNED> id1663out_result[2];

  HWRawBits<1> id1010out_value;

  HWRawBits<1> id1011out_result[2];

  HWOffsetFix<1,0,UNSIGNED> id1004out_value;

  HWOffsetFix<5,0,UNSIGNED> id2294out_output[4];

  HWRawBits<24> id1146out_dataout[5];

  HWOffsetFix<1,0,UNSIGNED> id987out_value;

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id999out_result[2];

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id1793out_value;

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id1001out_result[2];

  HWRawBits<24> id1003out_dataout[5];

  HWRawBits<24> id2297out_output[2];

  HWRawBits<24> id1792out_value;

  HWRawBits<24> id1149out_result[2];

  HWRawBits<24> id1151out_result[2];

  HWFloat<8,24> id1153out_o[8];

  HWFloat<8,24> id1154out_result[2];

  HWFloat<8,24> id1160out_result[9];

  HWFloat<8,24> id1159out_result[9];

  HWFloat<8,24> id1161out_result[9];

  HWFloat<8,24> id1157out_result[2];

  HWFloat<8,24> id2301out_output[9];

  HWFloat<8,24> id1162out_result[9];

  HWFloat<8,24> id1163out_result[12];

  HWFloat<8,24> id1156out_result[2];

  HWFloat<8,24> id1164out_result[9];

  HWFloat<8,24> id2303out_output[20];

  HWFloat<8,24> id1165out_result[12];

  HWFloat<8,24> id1155out_result[2];

  HWFloat<8,24> id2305out_output[39];

  HWFloat<8,24> id1166out_result[12];

  HWFloat<8,24> id1791out_value;

  HWFloat<8,24> id1173out_result[2];

  HWRawBits<2> id1871out_value;

  HWOffsetFix<1,0,UNSIGNED> id1531out_result[2];

  HWRawBits<2> id1870out_value;

  HWOffsetFix<1,0,UNSIGNED> id1532out_result[2];

  HWOffsetFix<1,0,UNSIGNED> id751out_result[2];

  HWOffsetFix<1,0,UNSIGNED> id2307out_output[77];

  HWFloat<8,24> id1187out_value;

  HWFloat<8,24> id1188out_result[2];

  HWFloat<8,24> id1189out_result[9];

  HWFloat<8,24> id2316out_output[59];

  HWFloat<8,24> id1212out_result[9];

  HWFloat<8,24> id1213out_result[9];

  HWFloat<8,24> id1214out_result[9];

  HWFloat<8,24> id1215out_result[12];

  HWOffsetFix<1,0,UNSIGNED> id1196out_result[2];

  HWFloat<8,24> id2367out_output[4];

  HWFloat<8,24> id1197out_result[29];

  HWFloat<8,24> id1199out_result[2];

  HWFloat<8,24> id1216out_result[29];

  HWFloat<8,24> id2333out_output[86];

  HWFloat<8,24> id2354out_output[20];

  HWFloat<8,24> id2355out_output[2];

  HWFloat<8,24> id1217out_result[9];

  HWFloat<8,24> id1218out_result[12];

  HWFloat<8,24> id1219out_result[2];

  HWFloat<8,24> id1242out_result[2];

  HWFloat<8,24> id17out_value;

  HWFloat<8,24> id18out_result[2];

  HWFloat<8,24> id2309out_output[22];

  HWFloat<8,24> id2361out_output[9];

  HWFloat<8,24> id1204out_result[9];

  HWFloat<8,24> id1205out_result[12];

  HWFloat<8,24> id1206out_result[29];

  HWFloat<8,24> id1207out_result[9];

  HWFloat<8,24> id1208out_result[12];

  HWFloat<8,24> id1209out_result[2];

  HWFloat<8,24> id1968out_value;

  HWOffsetFix<1,0,UNSIGNED> id1228out_result[3];

  HWOffsetFix<1,0,UNSIGNED> id1230out_result[2];

  HWOffsetFix<1,0,UNSIGNED> id1232out_result[2];

  HWOffsetFix<1,0,UNSIGNED> id2326out_output[21];

  HWFloat<8,24> id1240out_result[2];

  HWFloat<8,24> id15out_value;

  HWFloat<8,24> id16out_result[2];

  HWFloat<8,24> id1190out_result[9];

  HWFloat<8,24> id1191out_result[9];

  HWFloat<8,24> id1192out_result[12];

  HWFloat<8,24> id2329out_output[26];

  HWFloat<8,24> id1790out_value;

  HWOffsetFix<1,0,UNSIGNED> id1194out_result[3];

  HWOffsetFix<1,0,UNSIGNED> id2325out_output[21];

  HWOffsetFix<1,0,UNSIGNED> id1221out_result[2];

  HWFloat<8,24> id1223out_result[9];

  HWFloat<8,24> id1224out_result[9];

  HWFloat<8,24> id1225out_result[12];

  HWFloat<8,24> id1226out_result[2];

  HWOffsetFix<1,0,UNSIGNED> id1236out_result[2];

  HWFloat<8,24> id1244out_result[2];

  HWFloat<8,24> id2337out_output[7];

  HWFloat<8,24> id19out_value;

  HWFloat<8,24> id20out_result[2];

  HWFloat<8,24> id2338out_output[15];

  HWFloat<8,24> id116out_result[9];

  HWFloat<8,24> id117out_result[12];

  HWFloat<8,24> id2340out_output[57];

  HWFloat<8,24> id11out_value;

  HWFloat<8,24> id12out_result[2];

  HWFloat<8,24> id2341out_output[23];

  HWFloat<8,24> id114out_result[9];

  HWFloat<8,24> id115out_result[12];

  HWFloat<8,24> id2342out_output[57];

  HWFloat<8,24> id9out_value;

  HWFloat<8,24> id10out_result[2];

  HWFloat<8,24> id2343out_output[23];

  HWFloat<8,24> id112out_result[9];

  HWFloat<8,24> id113out_result[12];

  HWOffsetFix<1,0,UNSIGNED> id1327out_value;

  HWOffsetFix<1,0,UNSIGNED> id1789out_value;

  HWOffsetFix<49,0,UNSIGNED> id1324out_value;

  HWOffsetFix<48,0,UNSIGNED> id1325out_count;
  HWOffsetFix<1,0,UNSIGNED> id1325out_wrap;

  HWOffsetFix<49,0,UNSIGNED> id1325st_count;

  HWOffsetFix<1,0,UNSIGNED> id0out_value;

  const HWFloat<8,24> c_hw_flt_8_24_bits;
  const HWOffsetFix<1,0,UNSIGNED> c_hw_fix_1_0_uns_bits;
  const HWOffsetFix<1,0,UNSIGNED> c_hw_fix_1_0_uns_bits_1;
  const HWFloat<8,24> c_hw_flt_8_24_bits_1;
  const HWFloat<8,24> c_hw_flt_8_24_bits_2;
  const HWOffsetFix<32,0,UNSIGNED> c_hw_fix_32_0_uns_bits;
  const HWOffsetFix<33,0,UNSIGNED> c_hw_fix_33_0_uns_bits;
  const HWOffsetFix<33,0,UNSIGNED> c_hw_fix_33_0_uns_bits_1;
  const HWOffsetFix<32,0,UNSIGNED> c_hw_fix_32_0_uns_bits_1;
  const HWFloat<8,24> c_hw_flt_8_24_bits_3;
  const HWOffsetFix<9,0,TWOSCOMPLEMENT> c_hw_fix_9_0_sgn_bits;
  const HWOffsetFix<25,-23,TWOSCOMPLEMENT> c_hw_fix_25_n23_sgn_bits;
  const HWRawBits<1> c_hw_bit_1_bits;
  const HWRawBits<31> c_hw_bit_31_bits;
  const HWOffsetFix<25,-23,TWOSCOMPLEMENT> c_hw_fix_25_n23_sgn_bits_1;
  const HWOffsetFix<7,0,UNSIGNED> c_hw_fix_7_0_uns_bits;
  const HWOffsetFix<9,0,TWOSCOMPLEMENT> c_hw_fix_9_0_sgn_bits_1;
  const HWOffsetFix<32,0,UNSIGNED> c_hw_fix_32_0_uns_bits_2;
  const HWFloat<8,24> c_hw_flt_8_24_bits_4;
  const HWFloat<8,24> c_hw_flt_8_24_bits_5;
  const HWFloat<8,24> c_hw_flt_8_24_bits_6;
  const HWFloat<8,24> c_hw_flt_8_24_bits_7;
  const HWFloat<8,24> c_hw_flt_8_24_bits_8;
  const HWFloat<8,24> c_hw_flt_8_24_bits_9;
  const HWRawBits<31> c_hw_bit_31_bits_1;
  const HWRawBits<8> c_hw_bit_8_bits;
  const HWRawBits<23> c_hw_bit_23_bits;
  const HWOffsetFix<9,0,TWOSCOMPLEMENT> c_hw_fix_9_0_sgn_bits_2;
  const HWRawBits<185> c_hw_bit_185_bits;
  const HWOffsetFix<80,0,UNSIGNED> c_hw_fix_80_0_uns_1_0val;
  const HWOffsetFix<7,0,UNSIGNED> c_hw_fix_7_0_uns_bits_1;
  const HWOffsetFix<7,0,UNSIGNED> c_hw_fix_7_0_uns_bits_2;
  const HWOffsetFix<7,0,UNSIGNED> c_hw_fix_7_0_uns_bits_3;
  const HWOffsetFix<7,0,UNSIGNED> c_hw_fix_7_0_uns_bits_4;
  const HWOffsetFix<7,0,UNSIGNED> c_hw_fix_7_0_uns_bits_5;
  const HWOffsetFix<7,0,UNSIGNED> c_hw_fix_7_0_uns_bits_6;
  const HWOffsetFix<7,0,UNSIGNED> c_hw_fix_7_0_uns_bits_7;
  const HWOffsetFix<7,0,UNSIGNED> c_hw_fix_7_0_uns_bits_8;
  const HWOffsetFix<7,0,UNSIGNED> c_hw_fix_7_0_uns_bits_9;
  const HWOffsetFix<7,0,UNSIGNED> c_hw_fix_7_0_uns_bits_10;
  const HWOffsetFix<7,0,UNSIGNED> c_hw_fix_7_0_uns_bits_11;
  const HWOffsetFix<7,0,UNSIGNED> c_hw_fix_7_0_uns_bits_12;
  const HWOffsetFix<7,0,UNSIGNED> c_hw_fix_7_0_uns_bits_13;
  const HWOffsetFix<7,0,UNSIGNED> c_hw_fix_7_0_uns_bits_14;
  const HWOffsetFix<7,0,UNSIGNED> c_hw_fix_7_0_uns_bits_15;
  const HWOffsetFix<7,0,UNSIGNED> c_hw_fix_7_0_uns_bits_16;
  const HWOffsetFix<7,0,UNSIGNED> c_hw_fix_7_0_uns_bits_17;
  const HWOffsetFix<7,0,UNSIGNED> c_hw_fix_7_0_uns_bits_18;
  const HWOffsetFix<7,0,UNSIGNED> c_hw_fix_7_0_uns_bits_19;
  const HWOffsetFix<7,0,UNSIGNED> c_hw_fix_7_0_uns_bits_20;
  const HWOffsetFix<7,0,UNSIGNED> c_hw_fix_7_0_uns_bits_21;
  const HWOffsetFix<7,0,UNSIGNED> c_hw_fix_7_0_uns_bits_22;
  const HWOffsetFix<7,0,UNSIGNED> c_hw_fix_7_0_uns_bits_23;
  const HWOffsetFix<7,0,UNSIGNED> c_hw_fix_7_0_uns_bits_24;
  const HWOffsetFix<7,0,UNSIGNED> c_hw_fix_7_0_uns_bits_25;
  const HWOffsetFix<7,0,UNSIGNED> c_hw_fix_7_0_uns_bits_26;
  const HWOffsetFix<7,0,UNSIGNED> c_hw_fix_7_0_uns_bits_27;
  const HWOffsetFix<7,0,UNSIGNED> c_hw_fix_7_0_uns_bits_28;
  const HWOffsetFix<7,0,UNSIGNED> c_hw_fix_7_0_uns_bits_29;
  const HWOffsetFix<7,0,UNSIGNED> c_hw_fix_7_0_uns_bits_30;
  const HWOffsetFix<7,0,UNSIGNED> c_hw_fix_7_0_uns_bits_31;
  const HWOffsetFix<7,0,UNSIGNED> c_hw_fix_7_0_uns_bits_32;
  const HWOffsetFix<7,0,UNSIGNED> c_hw_fix_7_0_uns_bits_33;
  const HWOffsetFix<7,0,UNSIGNED> c_hw_fix_7_0_uns_bits_34;
  const HWOffsetFix<7,0,UNSIGNED> c_hw_fix_7_0_uns_bits_35;
  const HWOffsetFix<7,0,UNSIGNED> c_hw_fix_7_0_uns_bits_36;
  const HWOffsetFix<7,0,UNSIGNED> c_hw_fix_7_0_uns_bits_37;
  const HWOffsetFix<7,0,UNSIGNED> c_hw_fix_7_0_uns_bits_38;
  const HWOffsetFix<7,0,UNSIGNED> c_hw_fix_7_0_uns_bits_39;
  const HWOffsetFix<7,0,UNSIGNED> c_hw_fix_7_0_uns_bits_40;
  const HWOffsetFix<7,0,UNSIGNED> c_hw_fix_7_0_uns_bits_41;
  const HWOffsetFix<7,0,UNSIGNED> c_hw_fix_7_0_uns_bits_42;
  const HWOffsetFix<7,0,UNSIGNED> c_hw_fix_7_0_uns_bits_43;
  const HWOffsetFix<7,0,UNSIGNED> c_hw_fix_7_0_uns_bits_44;
  const HWOffsetFix<7,0,UNSIGNED> c_hw_fix_7_0_uns_bits_45;
  const HWOffsetFix<7,0,UNSIGNED> c_hw_fix_7_0_uns_bits_46;
  const HWOffsetFix<7,0,UNSIGNED> c_hw_fix_7_0_uns_bits_47;
  const HWOffsetFix<7,0,UNSIGNED> c_hw_fix_7_0_uns_bits_48;
  const HWOffsetFix<7,0,UNSIGNED> c_hw_fix_7_0_uns_bits_49;
  const HWOffsetFix<7,0,UNSIGNED> c_hw_fix_7_0_uns_bits_50;
  const HWOffsetFix<7,0,UNSIGNED> c_hw_fix_7_0_uns_bits_51;
  const HWOffsetFix<7,0,UNSIGNED> c_hw_fix_7_0_uns_bits_52;
  const HWOffsetFix<7,0,UNSIGNED> c_hw_fix_7_0_uns_bits_53;
  const HWOffsetFix<7,0,UNSIGNED> c_hw_fix_7_0_uns_bits_54;
  const HWOffsetFix<7,0,UNSIGNED> c_hw_fix_7_0_uns_bits_55;
  const HWOffsetFix<7,0,UNSIGNED> c_hw_fix_7_0_uns_bits_56;
  const HWOffsetFix<7,0,UNSIGNED> c_hw_fix_7_0_uns_bits_57;
  const HWOffsetFix<7,0,UNSIGNED> c_hw_fix_7_0_uns_bits_58;
  const HWOffsetFix<7,0,UNSIGNED> c_hw_fix_7_0_uns_bits_59;
  const HWOffsetFix<7,0,UNSIGNED> c_hw_fix_7_0_uns_bits_60;
  const HWOffsetFix<7,0,UNSIGNED> c_hw_fix_7_0_uns_bits_61;
  const HWOffsetFix<7,0,UNSIGNED> c_hw_fix_7_0_uns_bits_62;
  const HWOffsetFix<7,0,UNSIGNED> c_hw_fix_7_0_uns_bits_63;
  const HWOffsetFix<7,0,UNSIGNED> c_hw_fix_7_0_uns_bits_64;
  const HWOffsetFix<7,0,UNSIGNED> c_hw_fix_7_0_uns_bits_65;
  const HWOffsetFix<7,0,UNSIGNED> c_hw_fix_7_0_uns_bits_66;
  const HWOffsetFix<7,0,UNSIGNED> c_hw_fix_7_0_uns_bits_67;
  const HWOffsetFix<7,0,UNSIGNED> c_hw_fix_7_0_uns_bits_68;
  const HWOffsetFix<7,0,UNSIGNED> c_hw_fix_7_0_uns_bits_69;
  const HWOffsetFix<7,0,UNSIGNED> c_hw_fix_7_0_uns_bits_70;
  const HWOffsetFix<7,0,UNSIGNED> c_hw_fix_7_0_uns_bits_71;
  const HWOffsetFix<7,0,UNSIGNED> c_hw_fix_7_0_uns_bits_72;
  const HWOffsetFix<7,0,UNSIGNED> c_hw_fix_7_0_uns_bits_73;
  const HWOffsetFix<7,0,UNSIGNED> c_hw_fix_7_0_uns_bits_74;
  const HWOffsetFix<7,0,UNSIGNED> c_hw_fix_7_0_uns_bits_75;
  const HWOffsetFix<7,0,UNSIGNED> c_hw_fix_7_0_uns_bits_76;
  const HWOffsetFix<7,0,UNSIGNED> c_hw_fix_7_0_uns_bits_77;
  const HWOffsetFix<7,0,UNSIGNED> c_hw_fix_7_0_uns_bits_78;
  const HWOffsetFix<7,0,UNSIGNED> c_hw_fix_7_0_uns_bits_79;
  const HWOffsetFix<7,0,UNSIGNED> c_hw_fix_7_0_uns_bits_80;
  const HWOffsetFix<8,0,TWOSCOMPLEMENT> c_hw_fix_8_0_sgn_bits;
  const HWOffsetFix<8,0,TWOSCOMPLEMENT> c_hw_fix_8_0_sgn_bits_1;
  const HWOffsetFix<9,0,TWOSCOMPLEMENT> c_hw_fix_9_0_sgn_bits_3;
  const HWOffsetFix<9,0,TWOSCOMPLEMENT> c_hw_fix_9_0_sgn_bits_4;
  const HWOffsetFix<8,0,TWOSCOMPLEMENT> c_hw_fix_8_0_sgn_bits_2;
  const HWOffsetFix<8,0,TWOSCOMPLEMENT> c_hw_fix_8_0_sgn_bits_3;
  const HWFloat<8,24> c_hw_flt_8_24_bits_10;
  const HWFloat<8,24> c_hw_flt_8_24_bits_11;
  const HWOffsetFix<9,0,TWOSCOMPLEMENT> c_hw_fix_9_0_sgn_bits_5;
  const HWOffsetFix<5,0,UNSIGNED> c_hw_fix_5_0_uns_bits;
  const HWFloat<8,24> c_hw_flt_8_24_128_0val;
  const HWOffsetFix<9,0,TWOSCOMPLEMENT> c_hw_fix_9_0_sgn_bits_6;
  const HWOffsetFix<9,0,TWOSCOMPLEMENT> c_hw_fix_9_0_sgn_bits_7;
  const HWOffsetFix<9,0,TWOSCOMPLEMENT> c_hw_fix_9_0_sgn_bits_8;
  const HWOffsetFix<9,0,TWOSCOMPLEMENT> c_hw_fix_9_0_sgn_bits_9;
  const HWOffsetFix<9,0,TWOSCOMPLEMENT> c_hw_fix_9_0_sgn_bits_10;
  const HWOffsetFix<9,0,TWOSCOMPLEMENT> c_hw_fix_9_0_sgn_bits_11;
  const HWOffsetFix<9,0,TWOSCOMPLEMENT> c_hw_fix_9_0_sgn_bits_12;
  const HWOffsetFix<9,0,TWOSCOMPLEMENT> c_hw_fix_9_0_sgn_bits_13;
  const HWOffsetFix<9,0,TWOSCOMPLEMENT> c_hw_fix_9_0_sgn_bits_14;
  const HWOffsetFix<9,0,TWOSCOMPLEMENT> c_hw_fix_9_0_sgn_bits_15;
  const HWOffsetFix<9,0,TWOSCOMPLEMENT> c_hw_fix_9_0_sgn_bits_16;
  const HWOffsetFix<9,0,TWOSCOMPLEMENT> c_hw_fix_9_0_sgn_bits_17;
  const HWOffsetFix<9,0,TWOSCOMPLEMENT> c_hw_fix_9_0_sgn_bits_18;
  const HWOffsetFix<9,0,TWOSCOMPLEMENT> c_hw_fix_9_0_sgn_bits_19;
  const HWOffsetFix<9,0,TWOSCOMPLEMENT> c_hw_fix_9_0_sgn_bits_20;
  const HWOffsetFix<9,0,TWOSCOMPLEMENT> c_hw_fix_9_0_sgn_bits_21;
  const HWOffsetFix<9,0,TWOSCOMPLEMENT> c_hw_fix_9_0_sgn_bits_22;
  const HWOffsetFix<9,0,TWOSCOMPLEMENT> c_hw_fix_9_0_sgn_bits_23;
  const HWOffsetFix<9,0,TWOSCOMPLEMENT> c_hw_fix_9_0_sgn_bits_24;
  const HWOffsetFix<9,0,TWOSCOMPLEMENT> c_hw_fix_9_0_sgn_bits_25;
  const HWOffsetFix<9,0,TWOSCOMPLEMENT> c_hw_fix_9_0_sgn_bits_26;
  const HWOffsetFix<9,0,TWOSCOMPLEMENT> c_hw_fix_9_0_sgn_bits_27;
  const HWOffsetFix<9,0,TWOSCOMPLEMENT> c_hw_fix_9_0_sgn_bits_28;
  const HWRawBits<24> c_hw_bit_24_bits;
  const HWRawBits<2> c_hw_bit_2_bits;
  const HWRawBits<2> c_hw_bit_2_bits_1;
  const HWRawBits<2> c_hw_bit_2_bits_2;
  const HWOffsetFix<49,0,UNSIGNED> c_hw_fix_49_0_uns_bits;
  const HWOffsetFix<49,0,UNSIGNED> c_hw_fix_49_0_uns_bits_1;
  const HWOffsetFix<49,0,UNSIGNED> c_hw_fix_49_0_uns_bits_2;

  void execute0();
};

}

#endif /* LOOPKERNEL_H_ */
