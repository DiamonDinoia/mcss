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
  t_port_number m_internal_watch_llv_output;
  t_port_number m_y;
  t_port_number m_internal_watch_carriedposx_output;
  t_port_number m_internal_watch_carriedposz_output;
  t_port_number m_internal_watch_carrieddirx_output;
  t_port_number m_internal_watch_carriedlength_output;
  t_port_number m_internal_watch_posz_output;
  t_port_number m_internal_watch_dirx_output;
  t_port_number m_internal_watch_tracklength_output;
  t_port_number m_internal_watch_reset_output;
  t_port_number m_internal_watch_pastlimit_output;
  t_port_number m_internal_watch_lengthoffset_output;
  t_port_number m_internal_watch_length_output;
  t_port_number m_internal_watch_track_0_output;
  t_port_number m_internal_watch_track_1_output;
  t_port_number m_internal_watch_track_2_output;
  t_port_number m_internal_watch_track_3_output;
  t_port_number m_internal_watch_track_4_output;
  t_port_number m_internal_watch_track_5_output;
  t_port_number m_internal_watch_track_6_output;
  t_port_number m_z;
  HWOffsetFix<1,0,UNSIGNED> id1359out_value;

  HWOffsetFix<8,0,UNSIGNED> id2456out_value;

  HWOffsetFix<1,0,UNSIGNED> id3out_value;

  HWOffsetFix<1,0,UNSIGNED> id4out_output;

  long id4st_count;
  HWOffsetFix<1,0,UNSIGNED> id4st_value;

  HWOffsetFix<1,0,UNSIGNED> id2139out_output[4];

  HWFloat<8,24> id2112out_output[37];

  HWFloat<8,24> id25out_value;

  HWFloat<8,24> id26out_result[2];

  HWFloat<8,24> id2023out_value;

  HWOffsetFix<1,0,UNSIGNED> id27out_io_y_force_disabled;

  HWRawBits<96> id29out_data;

  HWOffsetFix<1,0,UNSIGNED> id29st_read_next_cycle;
  HWRawBits<96> id29st_last_read_value;

  HWFloat<8,24> id2022out_value;

  HWOffsetFix<1,0,UNSIGNED> id100out_result[3];

  HWOffsetFix<1,0,UNSIGNED> id2136out_output[48];

  HWFloat<8,24> id101out_value;

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id2093out_value;

  HWOffsetFix<25,-23,TWOSCOMPLEMENT> id2092out_value;

  HWRawBits<1> id40out_value;

  HWRawBits<31> id2021out_value;

  HWOffsetFix<1,0,UNSIGNED> id1381out_result[2];

  HWRawBits<23> id2113out_output[2];

  HWOffsetFix<1,0,UNSIGNED> id2114out_output[2];

  HWOffsetFix<25,-23,TWOSCOMPLEMENT> id2045out_result[2];

  HWOffsetFix<25,-23,TWOSCOMPLEMENT> id2020out_value;

  HWOffsetFix<1,0,UNSIGNED> id1384out_result[2];

  HWOffsetFix<1,0,UNSIGNED> id2116out_output[2];

  HWOffsetFix<8,0,UNSIGNED> id2115out_output[3];

  HWOffsetFix<7,0,UNSIGNED> id2019out_value;

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id51out_result[2];

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id2117out_output[2];

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id2018out_value;

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id59out_result[2];

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id60out_result[2];

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id2047out_result[2];

  HWRawBits<8> id2118out_output[30];

  HWFloat<8,24> id1310out_dout[3];

  HWFloat<8,24> id1310sta_rom_store[256];

  HWOffsetFix<1,0,UNSIGNED> id2119out_output[33];

  HWRawBits<108> id1292out_dout[3];

  HWRawBits<108> id1292sta_rom_store[128];

  HWRawBits<108> id1301out_dout[3];

  HWRawBits<108> id1301sta_rom_store[128];

  HWOffsetFix<27,-23,TWOSCOMPLEMENT> id81out_result[2];

  HWOffsetFix<25,-24,UNSIGNED> id2121out_output[3];

  HWOffsetFix<17,-17,UNSIGNED> id77out_result[2];

  HWOffsetFix<44,-40,TWOSCOMPLEMENT> id82out_result[5];

  HWOffsetFix<27,-23,TWOSCOMPLEMENT> id80out_result[2];

  HWOffsetFix<27,-23,TWOSCOMPLEMENT> id2125out_output[5];

  HWOffsetFix<45,-40,TWOSCOMPLEMENT> id83out_result[2];

  HWOffsetFix<25,-20,TWOSCOMPLEMENT> id84out_o[2];

  HWOffsetFix<17,-17,UNSIGNED> id2126out_output[7];

  HWOffsetFix<42,-37,TWOSCOMPLEMENT> id85out_result[5];

  HWOffsetFix<27,-23,TWOSCOMPLEMENT> id79out_result[2];

  HWOffsetFix<27,-23,TWOSCOMPLEMENT> id2128out_output[11];

  HWOffsetFix<43,-37,TWOSCOMPLEMENT> id86out_result[2];

  HWOffsetFix<25,-19,TWOSCOMPLEMENT> id87out_o[2];

  HWOffsetFix<17,-17,UNSIGNED> id2415out_output[7];

  HWOffsetFix<42,-36,TWOSCOMPLEMENT> id88out_result[5];

  HWOffsetFix<27,-23,TWOSCOMPLEMENT> id78out_result[2];

  HWOffsetFix<27,-23,TWOSCOMPLEMENT> id2131out_output[17];

  HWOffsetFix<42,-36,TWOSCOMPLEMENT> id89out_result[2];

  HWOffsetFix<25,-19,TWOSCOMPLEMENT> id90out_o[2];

  HWFloat<8,24> id91out_o[7];

  HWOffsetFix<25,-24,UNSIGNED> id95out_result[2];

  HWOffsetFix<25,-24,UNSIGNED> id2135out_output[19];

  HWFloat<8,24> id96out_o[7];

  HWFloat<8,24> id97out_result[9];

  HWFloat<8,24> id98out_result[13];

  HWFloat<8,24> id102out_result[2];

  HWFloat<8,24> id104out_result[9];

  HWFloat<8,24> id2137out_output[80];

  HWFloat<8,24> id105out_result[12];

  HWFloat<8,24> id2407out_output[36];

  HWFloat<8,24> id2417out_output[3];

  HWFloat<8,24> id2418out_output[6];

  HWFloat<8,24> id1268out_value;

  HWFloat<8,24> id1269out_result[2];

  HWFloat<8,24> id2017out_value;

  HWOffsetFix<1,0,UNSIGNED> id9out_result[3];

  HWOffsetFix<1,0,UNSIGNED> id10out_result[2];

  HWOffsetFix<1,0,UNSIGNED> id2358out_output[22];

  HWOffsetFix<1,0,UNSIGNED> id2422out_output[13];

  HWOffsetFix<1,0,UNSIGNED> id2423out_output[26];

  HWOffsetFix<1,0,UNSIGNED> id2424out_output[21];

  HWFloat<8,24> id11out_value;

  HWFloat<8,24> id12out_result[2];

  HWFloat<8,24> id2016out_value;

  HWOffsetFix<1,0,UNSIGNED> id107out_result[3];

  HWOffsetFix<1,0,UNSIGNED> id2249out_output[21];

  HWOffsetFix<1,0,UNSIGNED> id2426out_output[4];

  HWOffsetFix<1,0,UNSIGNED> id2427out_output[2];

  HWOffsetFix<1,0,UNSIGNED> id2428out_output[12];

  HWOffsetFix<1,0,UNSIGNED> id2429out_output[6];

  HWOffsetFix<1,0,UNSIGNED> id2430out_output[3];

  HWFloat<8,24> id2450out_output[19];

  HWFloat<8,24> id1191out_result[9];

  HWFloat<8,24> id2360out_output[22];

  HWFloat<8,24> id2440out_output[9];

  HWFloat<8,24> id2441out_output[40];

  HWFloat<8,24> id2442out_output[3];

  HWFloat<8,24> id2443out_output[19];

  HWOffsetFix<1,0,UNSIGNED> id1212out_result[2];

  HWFloat<8,24> id2015out_value;

  HWFloat<8,24> id129out_value;

  HWFloat<8,24> id130out_value;

  HWFloat<8,24> id2014out_value;

  HWFloat<8,24> id2013out_value;

  HWFloat<8,24> id121out_result[9];

  HWFloat<8,24> id2147out_output[15];

  HWFloat<8,24> id2012out_value;

  HWFloat<8,24> id123out_result[12];

  HWFloat<8,24> id2011out_value;

  HWFloat<8,24> id125out_result[12];

  HWFloat<8,24> id126out_result[29];

  HWFloat<8,24> id128out_result[12];

  HWOffsetFix<1,0,UNSIGNED> id131out_result[3];

  HWFloat<8,24> id2148out_output[3];

  HWFloat<8,24> id132out_result[2];

  HWOffsetFix<1,0,UNSIGNED> id133out_result[3];

  HWFloat<8,24> id2149out_output[3];

  HWFloat<8,24> id134out_result[2];

  HWFloat<8,24> id136out_result[12];

  HWFloat<8,24> id2150out_output[12];

  HWFloat<8,24> id2010out_value;

  HWFloat<8,24> id138out_result[12];

  HWFloat<8,24> id139out_result[9];

  HWFloat<8,24> id140out_result[29];

  HWFloat<8,24> id2009out_value;

  HWFloat<8,24> id2151out_output[29];

  HWFloat<8,24> id143out_result[9];

  HWFloat<8,24> id2153out_output[7];

  HWFloat<8,24> id2434out_output[2];

  HWRawBits<31> id1177out_value;

  HWOffsetFix<1,0,UNSIGNED> id1393out_result[2];

  HWRawBits<8> id1182out_value;

  HWOffsetFix<1,0,UNSIGNED> id1395out_result[2];

  HWRawBits<23> id2008out_value;

  HWOffsetFix<1,0,UNSIGNED> id1397out_result[2];

  HWOffsetFix<1,0,UNSIGNED> id1186out_result[2];

  HWOffsetFix<1,0,UNSIGNED> id1187out_result[2];

  HWOffsetFix<1,0,UNSIGNED> id2247out_output[80];

  HWOffsetFix<1,0,UNSIGNED> id672out_value;

  HWOffsetFix<7,0,UNSIGNED> id2006out_value;

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id2005out_value;

  HWOffsetFix<10,0,TWOSCOMPLEMENT> id2028out_result[2];

  HWOffsetFix<1,0,UNSIGNED> id2156out_output[6];

  HWRawBits<185> id683out_value;

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id2091out_value;

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id2055out_result[2];

  HWRawBits<185> id693out_dataout[5];

  HWRawBits<185> id692out_dataout[5];

  HWRawBits<185> id694out_result[2];

  HWOffsetFix<81,0,UNSIGNED> id698out_result[2];

  HWOffsetFix<80,0,UNSIGNED> id710out_output[2];

  HWOffsetFix<7,0,UNSIGNED> id711out_output[2];

  HWOffsetFix<7,0,UNSIGNED> id711st_one_hot_or;

  HWOffsetFix<8,0,TWOSCOMPLEMENT> id2001out_value;

  HWOffsetFix<8,0,TWOSCOMPLEMENT> id2000out_value;

  HWOffsetFix<10,0,TWOSCOMPLEMENT> id2030out_result[2];

  HWOffsetFix<8,0,TWOSCOMPLEMENT> id2157out_output[5];

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id1999out_value;

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id731out_result[2];

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id1998out_value;

  HWOffsetFix<1,0,UNSIGNED> id1406out_result[2];

  HWOffsetFix<1,0,UNSIGNED> id2162out_output[2];

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id1997out_value;

  HWOffsetFix<1,0,UNSIGNED> id1407out_result[2];

  HWOffsetFix<1,0,UNSIGNED> id1357out_value;

  HWOffsetFix<8,0,UNSIGNED> id2161out_output[2];

  HWOffsetFix<8,0,TWOSCOMPLEMENT> id1996out_value;

  HWOffsetFix<8,0,TWOSCOMPLEMENT> id1995out_value;

  HWOffsetFix<10,0,TWOSCOMPLEMENT> id2032out_result[2];

  HWOffsetFix<8,0,TWOSCOMPLEMENT> id1994out_value;

  HWOffsetFix<1,0,UNSIGNED> id1408out_result[2];

  HWOffsetFix<1,0,UNSIGNED> id2159out_output[4];

  HWOffsetFix<80,-79,TWOSCOMPLEMENT> id2158out_output[4];

  HWOffsetFix<80,-79,TWOSCOMPLEMENT> id2435out_output[5];

  HWRawBits<80> id724out_dataout[5];

  HWOffsetFix<80,-79,TWOSCOMPLEMENT> id726out_result[2];

  HWOffsetFix<24,-23,UNSIGNED> id732out_o[2];

  HWFloat<8,24> id741out_value;

  HWFloat<8,24> id742out_result[2];

  HWFloat<8,24> id745out_value;

  HWFloat<8,24> id746out_result[2];

  HWFloat<8,24> id2163out_output[2];

  HWFloat<8,24> id1993out_value;

  HWOffsetFix<1,0,UNSIGNED> id1169out_result[3];

  HWFloat<8,24> id1992out_value;

  HWOffsetFix<1,0,UNSIGNED> id1171out_result[3];

  HWOffsetFix<1,0,UNSIGNED> id1172out_result[2];

  HWOffsetFix<1,0,UNSIGNED> id2245out_output[65];

  HWFloat<8,24> id2007out_value;

  HWOffsetFix<1,0,UNSIGNED> id666out_result[3];

  HWRawBits<2> id2166out_output[2];

  HWRawBits<2> id2004out_value;

  HWRawBits<2> id703out_result[2];

  HWRawBits<2> id704out_result[2];

  HWRawBits<1> id2177out_output[28];

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id1991out_value;

  HWOffsetFix<7,0,UNSIGNED> id1990out_value;

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id2034out_result[2];

  HWOffsetFix<1,0,UNSIGNED> id2170out_output[5];

  HWOffsetFix<5,0,UNSIGNED> id765out_value;

  HWOffsetFix<25,-23,TWOSCOMPLEMENT> id2090out_value;

  HWRawBits<1> id757out_value;

  HWRawBits<31> id1989out_value;

  HWOffsetFix<1,0,UNSIGNED> id1412out_result[2];

  HWOffsetFix<25,-23,TWOSCOMPLEMENT> id2057out_result[2];

  HWRawBits<30> id776out_dataout[5];

  HWOffsetFix<7,0,UNSIGNED> id779out_value;

  HWOffsetFix<7,0,UNSIGNED> id780out_result[2];

  HWOffsetFix<7,0,UNSIGNED> id2171out_output[10];

  HWRawBits<128> id1329out_dout[3];

  HWRawBits<128> id1329sta_rom_store[128];

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id1988out_value;

  HWOffsetFix<7,0,UNSIGNED> id1987out_value;

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id2035out_result[2];

  HWOffsetFix<1,0,UNSIGNED> id2175out_output[5];

  HWOffsetFix<5,0,UNSIGNED> id966out_value;

  HWOffsetFix<25,-23,TWOSCOMPLEMENT> id2089out_value;

  HWRawBits<1> id958out_value;

  HWRawBits<31> id1986out_value;

  HWOffsetFix<1,0,UNSIGNED> id1416out_result[2];

  HWOffsetFix<25,-23,TWOSCOMPLEMENT> id2059out_result[2];

  HWRawBits<30> id977out_dataout[5];

  HWOffsetFix<7,0,UNSIGNED> id980out_value;

  HWOffsetFix<7,0,UNSIGNED> id981out_result[2];

  HWOffsetFix<7,0,UNSIGNED> id2176out_output[10];

  HWRawBits<128> id1338out_dout[3];

  HWRawBits<128> id1338sta_rom_store[128];

  HWFloat<8,24> id1159out_result[2];

  HWFloat<8,24> id2024out_floatOut[2];

  HWFloat<8,24> id2178out_output[4];

  HWRawBits<1> id2207out_output[7];

  HWOffsetFix<7,0,UNSIGNED> id1984out_value;

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id786out_result[2];

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id1983out_value;

  HWOffsetFix<1,0,UNSIGNED> id1418out_result[2];

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id1982out_value;

  HWOffsetFix<1,0,UNSIGNED> id1419out_result[2];

  HWOffsetFix<1,0,UNSIGNED> id795out_result[2];

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id1981out_value;

  HWOffsetFix<1,0,UNSIGNED> id1420out_result[2];

  HWOffsetFix<1,0,UNSIGNED> id2179out_output[2];

  HWOffsetFix<2,0,UNSIGNED> id2205out_output[6];

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id1980out_value;

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id1979out_value;

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id806out_result[2];

  HWOffsetFix<1,0,UNSIGNED> id1421out_result[2];

  HWRawBits<1> id942out_value;

  HWRawBits<1> id943out_result[2];

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id1978out_value;

  HWOffsetFix<1,0,UNSIGNED> id1423out_result[2];

  HWRawBits<1> id936out_value;

  HWRawBits<1> id937out_result[2];

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id1977out_value;

  HWOffsetFix<1,0,UNSIGNED> id1425out_result[2];

  HWRawBits<1> id930out_value;

  HWRawBits<1> id931out_result[2];

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id1976out_value;

  HWOffsetFix<1,0,UNSIGNED> id1427out_result[2];

  HWRawBits<1> id924out_value;

  HWRawBits<1> id925out_result[2];

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id1975out_value;

  HWOffsetFix<1,0,UNSIGNED> id1429out_result[2];

  HWRawBits<1> id918out_value;

  HWRawBits<1> id919out_result[2];

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id1974out_value;

  HWOffsetFix<1,0,UNSIGNED> id1431out_result[2];

  HWRawBits<1> id912out_value;

  HWRawBits<1> id913out_result[2];

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id1973out_value;

  HWOffsetFix<1,0,UNSIGNED> id1433out_result[2];

  HWRawBits<1> id906out_value;

  HWRawBits<1> id907out_result[2];

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id1972out_value;

  HWOffsetFix<1,0,UNSIGNED> id1435out_result[2];

  HWRawBits<1> id900out_value;

  HWRawBits<1> id901out_result[2];

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id1971out_value;

  HWOffsetFix<1,0,UNSIGNED> id1437out_result[2];

  HWRawBits<1> id894out_value;

  HWRawBits<1> id895out_result[2];

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id1970out_value;

  HWOffsetFix<1,0,UNSIGNED> id1439out_result[2];

  HWRawBits<1> id888out_value;

  HWRawBits<1> id889out_result[2];

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id1969out_value;

  HWOffsetFix<1,0,UNSIGNED> id1441out_result[2];

  HWRawBits<1> id882out_value;

  HWRawBits<1> id883out_result[2];

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id1968out_value;

  HWOffsetFix<1,0,UNSIGNED> id1443out_result[2];

  HWRawBits<1> id876out_value;

  HWRawBits<1> id877out_result[2];

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id1967out_value;

  HWOffsetFix<1,0,UNSIGNED> id1445out_result[2];

  HWRawBits<1> id870out_value;

  HWRawBits<1> id871out_result[2];

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id1966out_value;

  HWOffsetFix<1,0,UNSIGNED> id1447out_result[2];

  HWRawBits<1> id864out_value;

  HWRawBits<1> id865out_result[2];

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id1965out_value;

  HWOffsetFix<1,0,UNSIGNED> id1449out_result[2];

  HWRawBits<1> id858out_value;

  HWRawBits<1> id859out_result[2];

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id1964out_value;

  HWOffsetFix<1,0,UNSIGNED> id1451out_result[2];

  HWRawBits<1> id852out_value;

  HWRawBits<1> id853out_result[2];

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id1963out_value;

  HWOffsetFix<1,0,UNSIGNED> id1453out_result[2];

  HWRawBits<1> id846out_value;

  HWRawBits<1> id847out_result[2];

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id1962out_value;

  HWOffsetFix<1,0,UNSIGNED> id1455out_result[2];

  HWRawBits<1> id840out_value;

  HWRawBits<1> id841out_result[2];

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id1961out_value;

  HWOffsetFix<1,0,UNSIGNED> id1457out_result[2];

  HWRawBits<1> id834out_value;

  HWRawBits<1> id835out_result[2];

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id1960out_value;

  HWOffsetFix<1,0,UNSIGNED> id1459out_result[2];

  HWRawBits<1> id828out_value;

  HWRawBits<1> id829out_result[2];

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id1959out_value;

  HWOffsetFix<1,0,UNSIGNED> id1461out_result[2];

  HWRawBits<1> id822out_value;

  HWRawBits<1> id823out_result[2];

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id1958out_value;

  HWOffsetFix<1,0,UNSIGNED> id1463out_result[2];

  HWRawBits<1> id816out_value;

  HWRawBits<1> id817out_result[2];

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id1957out_value;

  HWOffsetFix<1,0,UNSIGNED> id1465out_result[2];

  HWRawBits<1> id810out_value;

  HWRawBits<1> id811out_result[2];

  HWOffsetFix<1,0,UNSIGNED> id804out_value;

  HWOffsetFix<5,0,UNSIGNED> id2203out_output[4];

  HWRawBits<24> id946out_dataout[5];

  HWOffsetFix<1,0,UNSIGNED> id787out_value;

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id799out_result[2];

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id1956out_value;

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id801out_result[2];

  HWRawBits<24> id803out_dataout[5];

  HWRawBits<24> id2206out_output[2];

  HWRawBits<24> id1955out_value;

  HWRawBits<24> id949out_result[2];

  HWRawBits<24> id951out_result[2];

  HWFloat<8,24> id953out_o[8];

  HWFloat<8,24> id2025out_floatOut[2];

  HWFloat<8,24> id2208out_output[4];

  HWRawBits<1> id2237out_output[7];

  HWOffsetFix<7,0,UNSIGNED> id1953out_value;

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id987out_result[2];

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id1952out_value;

  HWOffsetFix<1,0,UNSIGNED> id1489out_result[2];

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id1951out_value;

  HWOffsetFix<1,0,UNSIGNED> id1490out_result[2];

  HWOffsetFix<1,0,UNSIGNED> id996out_result[2];

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id1950out_value;

  HWOffsetFix<1,0,UNSIGNED> id1491out_result[2];

  HWOffsetFix<1,0,UNSIGNED> id2209out_output[2];

  HWOffsetFix<2,0,UNSIGNED> id2235out_output[6];

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id1949out_value;

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id1948out_value;

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id1007out_result[2];

  HWOffsetFix<1,0,UNSIGNED> id1492out_result[2];

  HWRawBits<1> id1143out_value;

  HWRawBits<1> id1144out_result[2];

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id1947out_value;

  HWOffsetFix<1,0,UNSIGNED> id1494out_result[2];

  HWRawBits<1> id1137out_value;

  HWRawBits<1> id1138out_result[2];

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id1946out_value;

  HWOffsetFix<1,0,UNSIGNED> id1496out_result[2];

  HWRawBits<1> id1131out_value;

  HWRawBits<1> id1132out_result[2];

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id1945out_value;

  HWOffsetFix<1,0,UNSIGNED> id1498out_result[2];

  HWRawBits<1> id1125out_value;

  HWRawBits<1> id1126out_result[2];

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id1944out_value;

  HWOffsetFix<1,0,UNSIGNED> id1500out_result[2];

  HWRawBits<1> id1119out_value;

  HWRawBits<1> id1120out_result[2];

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id1943out_value;

  HWOffsetFix<1,0,UNSIGNED> id1502out_result[2];

  HWRawBits<1> id1113out_value;

  HWRawBits<1> id1114out_result[2];

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id1942out_value;

  HWOffsetFix<1,0,UNSIGNED> id1504out_result[2];

  HWRawBits<1> id1107out_value;

  HWRawBits<1> id1108out_result[2];

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id1941out_value;

  HWOffsetFix<1,0,UNSIGNED> id1506out_result[2];

  HWRawBits<1> id1101out_value;

  HWRawBits<1> id1102out_result[2];

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id1940out_value;

  HWOffsetFix<1,0,UNSIGNED> id1508out_result[2];

  HWRawBits<1> id1095out_value;

  HWRawBits<1> id1096out_result[2];

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id1939out_value;

  HWOffsetFix<1,0,UNSIGNED> id1510out_result[2];

  HWRawBits<1> id1089out_value;

  HWRawBits<1> id1090out_result[2];

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id1938out_value;

  HWOffsetFix<1,0,UNSIGNED> id1512out_result[2];

  HWRawBits<1> id1083out_value;

  HWRawBits<1> id1084out_result[2];

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id1937out_value;

  HWOffsetFix<1,0,UNSIGNED> id1514out_result[2];

  HWRawBits<1> id1077out_value;

  HWRawBits<1> id1078out_result[2];

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id1936out_value;

  HWOffsetFix<1,0,UNSIGNED> id1516out_result[2];

  HWRawBits<1> id1071out_value;

  HWRawBits<1> id1072out_result[2];

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id1935out_value;

  HWOffsetFix<1,0,UNSIGNED> id1518out_result[2];

  HWRawBits<1> id1065out_value;

  HWRawBits<1> id1066out_result[2];

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id1934out_value;

  HWOffsetFix<1,0,UNSIGNED> id1520out_result[2];

  HWRawBits<1> id1059out_value;

  HWRawBits<1> id1060out_result[2];

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id1933out_value;

  HWOffsetFix<1,0,UNSIGNED> id1522out_result[2];

  HWRawBits<1> id1053out_value;

  HWRawBits<1> id1054out_result[2];

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id1932out_value;

  HWOffsetFix<1,0,UNSIGNED> id1524out_result[2];

  HWRawBits<1> id1047out_value;

  HWRawBits<1> id1048out_result[2];

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id1931out_value;

  HWOffsetFix<1,0,UNSIGNED> id1526out_result[2];

  HWRawBits<1> id1041out_value;

  HWRawBits<1> id1042out_result[2];

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id1930out_value;

  HWOffsetFix<1,0,UNSIGNED> id1528out_result[2];

  HWRawBits<1> id1035out_value;

  HWRawBits<1> id1036out_result[2];

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id1929out_value;

  HWOffsetFix<1,0,UNSIGNED> id1530out_result[2];

  HWRawBits<1> id1029out_value;

  HWRawBits<1> id1030out_result[2];

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id1928out_value;

  HWOffsetFix<1,0,UNSIGNED> id1532out_result[2];

  HWRawBits<1> id1023out_value;

  HWRawBits<1> id1024out_result[2];

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id1927out_value;

  HWOffsetFix<1,0,UNSIGNED> id1534out_result[2];

  HWRawBits<1> id1017out_value;

  HWRawBits<1> id1018out_result[2];

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id1926out_value;

  HWOffsetFix<1,0,UNSIGNED> id1536out_result[2];

  HWRawBits<1> id1011out_value;

  HWRawBits<1> id1012out_result[2];

  HWOffsetFix<1,0,UNSIGNED> id1005out_value;

  HWOffsetFix<5,0,UNSIGNED> id2233out_output[4];

  HWRawBits<24> id1147out_dataout[5];

  HWOffsetFix<1,0,UNSIGNED> id988out_value;

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id1000out_result[2];

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id1925out_value;

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id1002out_result[2];

  HWRawBits<24> id1004out_dataout[5];

  HWRawBits<24> id2236out_output[2];

  HWRawBits<24> id1924out_value;

  HWRawBits<24> id1150out_result[2];

  HWRawBits<24> id1152out_result[2];

  HWFloat<8,24> id1154out_o[8];

  HWFloat<8,24> id1155out_result[2];

  HWFloat<8,24> id1161out_result[9];

  HWFloat<8,24> id1160out_result[9];

  HWFloat<8,24> id1162out_result[9];

  HWFloat<8,24> id1158out_result[2];

  HWFloat<8,24> id2240out_output[9];

  HWFloat<8,24> id1163out_result[9];

  HWFloat<8,24> id1164out_result[12];

  HWFloat<8,24> id1157out_result[2];

  HWFloat<8,24> id1165out_result[9];

  HWFloat<8,24> id2242out_output[20];

  HWFloat<8,24> id1166out_result[12];

  HWFloat<8,24> id1156out_result[2];

  HWFloat<8,24> id2244out_output[39];

  HWFloat<8,24> id1167out_result[12];

  HWFloat<8,24> id1923out_value;

  HWFloat<8,24> id1174out_result[2];

  HWRawBits<2> id2003out_value;

  HWOffsetFix<1,0,UNSIGNED> id1404out_result[2];

  HWRawBits<2> id2002out_value;

  HWOffsetFix<1,0,UNSIGNED> id1405out_result[2];

  HWOffsetFix<1,0,UNSIGNED> id752out_result[2];

  HWOffsetFix<1,0,UNSIGNED> id2246out_output[77];

  HWFloat<8,24> id1188out_value;

  HWFloat<8,24> id1189out_result[2];

  HWFloat<8,24> id1190out_result[9];

  HWFloat<8,24> id2364out_output[59];

  HWFloat<8,24> id2347out_output[28];

  HWFloat<8,24> id2438out_output[19];

  HWFloat<8,24> id2439out_output[5];

  HWOffsetFix<1,0,UNSIGNED> id1222out_result[2];

  HWFloat<8,24> id2348out_output[86];

  HWFloat<8,24> id2432out_output[20];

  HWOffsetFix<1,0,UNSIGNED> id1197out_result[2];

  HWFloat<8,24> id2444out_output[4];

  HWFloat<8,24> id1198out_result[29];

  HWFloat<8,24> id1200out_result[2];

  HWRawBits<31> id651out_value;

  HWOffsetFix<1,0,UNSIGNED> id1561out_result[2];

  HWRawBits<8> id656out_value;

  HWOffsetFix<1,0,UNSIGNED> id1563out_result[2];

  HWRawBits<23> id1922out_value;

  HWOffsetFix<1,0,UNSIGNED> id1565out_result[2];

  HWOffsetFix<1,0,UNSIGNED> id660out_result[2];

  HWOffsetFix<1,0,UNSIGNED> id661out_result[2];

  HWOffsetFix<1,0,UNSIGNED> id2345out_output[80];

  HWOffsetFix<1,0,UNSIGNED> id149out_value;

  HWOffsetFix<7,0,UNSIGNED> id1921out_value;

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id1920out_value;

  HWOffsetFix<10,0,TWOSCOMPLEMENT> id2036out_result[2];

  HWOffsetFix<1,0,UNSIGNED> id2256out_output[6];

  HWRawBits<185> id160out_value;

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id2088out_value;

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id2066out_result[2];

  HWRawBits<185> id170out_dataout[5];

  HWRawBits<185> id169out_dataout[5];

  HWRawBits<185> id171out_result[2];

  HWOffsetFix<81,0,UNSIGNED> id175out_result[2];

  HWOffsetFix<80,0,UNSIGNED> id184out_output[2];

  HWOffsetFix<7,0,UNSIGNED> id185out_output[2];

  HWOffsetFix<7,0,UNSIGNED> id185st_one_hot_or;

  HWOffsetFix<8,0,TWOSCOMPLEMENT> id1917out_value;

  HWOffsetFix<8,0,TWOSCOMPLEMENT> id1916out_value;

  HWOffsetFix<10,0,TWOSCOMPLEMENT> id2038out_result[2];

  HWOffsetFix<8,0,TWOSCOMPLEMENT> id2257out_output[5];

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id1915out_value;

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id205out_result[2];

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id1914out_value;

  HWOffsetFix<1,0,UNSIGNED> id1574out_result[2];

  HWOffsetFix<1,0,UNSIGNED> id2262out_output[2];

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id1913out_value;

  HWOffsetFix<1,0,UNSIGNED> id1575out_result[2];

  HWOffsetFix<1,0,UNSIGNED> id1358out_value;

  HWOffsetFix<8,0,UNSIGNED> id2261out_output[2];

  HWOffsetFix<8,0,TWOSCOMPLEMENT> id1912out_value;

  HWOffsetFix<8,0,TWOSCOMPLEMENT> id1911out_value;

  HWOffsetFix<10,0,TWOSCOMPLEMENT> id2040out_result[2];

  HWOffsetFix<8,0,TWOSCOMPLEMENT> id1910out_value;

  HWOffsetFix<1,0,UNSIGNED> id1576out_result[2];

  HWOffsetFix<1,0,UNSIGNED> id2259out_output[4];

  HWOffsetFix<80,-79,TWOSCOMPLEMENT> id2258out_output[4];

  HWOffsetFix<80,-79,TWOSCOMPLEMENT> id2436out_output[5];

  HWRawBits<80> id198out_dataout[5];

  HWOffsetFix<80,-79,TWOSCOMPLEMENT> id200out_result[2];

  HWOffsetFix<24,-23,UNSIGNED> id206out_o[2];

  HWFloat<8,24> id215out_value;

  HWFloat<8,24> id216out_result[2];

  HWFloat<8,24> id219out_value;

  HWFloat<8,24> id220out_result[2];

  HWFloat<8,24> id2263out_output[2];

  HWFloat<8,24> id1909out_value;

  HWOffsetFix<1,0,UNSIGNED> id643out_result[3];

  HWFloat<8,24> id1908out_value;

  HWOffsetFix<1,0,UNSIGNED> id645out_result[3];

  HWOffsetFix<1,0,UNSIGNED> id646out_result[2];

  HWOffsetFix<1,0,UNSIGNED> id2343out_output[65];

  HWRawBits<1> id2275out_output[30];

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id1907out_value;

  HWOffsetFix<7,0,UNSIGNED> id1906out_value;

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id2042out_result[2];

  HWOffsetFix<1,0,UNSIGNED> id2268out_output[5];

  HWOffsetFix<5,0,UNSIGNED> id239out_value;

  HWOffsetFix<25,-23,TWOSCOMPLEMENT> id2087out_value;

  HWRawBits<1> id231out_value;

  HWRawBits<31> id1905out_value;

  HWOffsetFix<1,0,UNSIGNED> id1581out_result[2];

  HWOffsetFix<25,-23,TWOSCOMPLEMENT> id2068out_result[2];

  HWRawBits<30> id250out_dataout[5];

  HWOffsetFix<7,0,UNSIGNED> id253out_value;

  HWOffsetFix<7,0,UNSIGNED> id254out_result[2];

  HWOffsetFix<7,0,UNSIGNED> id2269out_output[10];

  HWRawBits<128> id1311out_dout[3];

  HWRawBits<128> id1311sta_rom_store[128];

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id1904out_value;

  HWOffsetFix<7,0,UNSIGNED> id1903out_value;

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id2043out_result[2];

  HWOffsetFix<1,0,UNSIGNED> id2273out_output[5];

  HWOffsetFix<5,0,UNSIGNED> id440out_value;

  HWOffsetFix<25,-23,TWOSCOMPLEMENT> id2086out_value;

  HWRawBits<1> id432out_value;

  HWRawBits<31> id1902out_value;

  HWOffsetFix<1,0,UNSIGNED> id1585out_result[2];

  HWOffsetFix<25,-23,TWOSCOMPLEMENT> id2070out_result[2];

  HWRawBits<30> id451out_dataout[5];

  HWOffsetFix<7,0,UNSIGNED> id454out_value;

  HWOffsetFix<7,0,UNSIGNED> id455out_result[2];

  HWOffsetFix<7,0,UNSIGNED> id2274out_output[10];

  HWRawBits<128> id1320out_dout[3];

  HWRawBits<128> id1320sta_rom_store[128];

  HWFloat<8,24> id633out_result[2];

  HWFloat<8,24> id2026out_floatOut[2];

  HWFloat<8,24> id2276out_output[4];

  HWRawBits<1> id2305out_output[7];

  HWOffsetFix<7,0,UNSIGNED> id1900out_value;

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id260out_result[2];

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id1899out_value;

  HWOffsetFix<1,0,UNSIGNED> id1587out_result[2];

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id1898out_value;

  HWOffsetFix<1,0,UNSIGNED> id1588out_result[2];

  HWOffsetFix<1,0,UNSIGNED> id269out_result[2];

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id1897out_value;

  HWOffsetFix<1,0,UNSIGNED> id1589out_result[2];

  HWOffsetFix<1,0,UNSIGNED> id2277out_output[2];

  HWOffsetFix<2,0,UNSIGNED> id2303out_output[6];

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id1896out_value;

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id1895out_value;

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id280out_result[2];

  HWOffsetFix<1,0,UNSIGNED> id1590out_result[2];

  HWRawBits<1> id416out_value;

  HWRawBits<1> id417out_result[2];

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id1894out_value;

  HWOffsetFix<1,0,UNSIGNED> id1592out_result[2];

  HWRawBits<1> id410out_value;

  HWRawBits<1> id411out_result[2];

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id1893out_value;

  HWOffsetFix<1,0,UNSIGNED> id1594out_result[2];

  HWRawBits<1> id404out_value;

  HWRawBits<1> id405out_result[2];

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id1892out_value;

  HWOffsetFix<1,0,UNSIGNED> id1596out_result[2];

  HWRawBits<1> id398out_value;

  HWRawBits<1> id399out_result[2];

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id1891out_value;

  HWOffsetFix<1,0,UNSIGNED> id1598out_result[2];

  HWRawBits<1> id392out_value;

  HWRawBits<1> id393out_result[2];

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id1890out_value;

  HWOffsetFix<1,0,UNSIGNED> id1600out_result[2];

  HWRawBits<1> id386out_value;

  HWRawBits<1> id387out_result[2];

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id1889out_value;

  HWOffsetFix<1,0,UNSIGNED> id1602out_result[2];

  HWRawBits<1> id380out_value;

  HWRawBits<1> id381out_result[2];

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id1888out_value;

  HWOffsetFix<1,0,UNSIGNED> id1604out_result[2];

  HWRawBits<1> id374out_value;

  HWRawBits<1> id375out_result[2];

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id1887out_value;

  HWOffsetFix<1,0,UNSIGNED> id1606out_result[2];

  HWRawBits<1> id368out_value;

  HWRawBits<1> id369out_result[2];

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id1886out_value;

  HWOffsetFix<1,0,UNSIGNED> id1608out_result[2];

  HWRawBits<1> id362out_value;

  HWRawBits<1> id363out_result[2];

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id1885out_value;

  HWOffsetFix<1,0,UNSIGNED> id1610out_result[2];

  HWRawBits<1> id356out_value;

  HWRawBits<1> id357out_result[2];

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id1884out_value;

  HWOffsetFix<1,0,UNSIGNED> id1612out_result[2];

  HWRawBits<1> id350out_value;

  HWRawBits<1> id351out_result[2];

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id1883out_value;

  HWOffsetFix<1,0,UNSIGNED> id1614out_result[2];

  HWRawBits<1> id344out_value;

  HWRawBits<1> id345out_result[2];

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id1882out_value;

  HWOffsetFix<1,0,UNSIGNED> id1616out_result[2];

  HWRawBits<1> id338out_value;

  HWRawBits<1> id339out_result[2];

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id1881out_value;

  HWOffsetFix<1,0,UNSIGNED> id1618out_result[2];

  HWRawBits<1> id332out_value;

  HWRawBits<1> id333out_result[2];

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id1880out_value;

  HWOffsetFix<1,0,UNSIGNED> id1620out_result[2];

  HWRawBits<1> id326out_value;

  HWRawBits<1> id327out_result[2];

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id1879out_value;

  HWOffsetFix<1,0,UNSIGNED> id1622out_result[2];

  HWRawBits<1> id320out_value;

  HWRawBits<1> id321out_result[2];

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id1878out_value;

  HWOffsetFix<1,0,UNSIGNED> id1624out_result[2];

  HWRawBits<1> id314out_value;

  HWRawBits<1> id315out_result[2];

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id1877out_value;

  HWOffsetFix<1,0,UNSIGNED> id1626out_result[2];

  HWRawBits<1> id308out_value;

  HWRawBits<1> id309out_result[2];

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id1876out_value;

  HWOffsetFix<1,0,UNSIGNED> id1628out_result[2];

  HWRawBits<1> id302out_value;

  HWRawBits<1> id303out_result[2];

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id1875out_value;

  HWOffsetFix<1,0,UNSIGNED> id1630out_result[2];

  HWRawBits<1> id296out_value;

  HWRawBits<1> id297out_result[2];

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id1874out_value;

  HWOffsetFix<1,0,UNSIGNED> id1632out_result[2];

  HWRawBits<1> id290out_value;

  HWRawBits<1> id291out_result[2];

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id1873out_value;

  HWOffsetFix<1,0,UNSIGNED> id1634out_result[2];

  HWRawBits<1> id284out_value;

  HWRawBits<1> id285out_result[2];

  HWOffsetFix<1,0,UNSIGNED> id278out_value;

  HWOffsetFix<5,0,UNSIGNED> id2301out_output[4];

  HWRawBits<24> id420out_dataout[5];

  HWOffsetFix<1,0,UNSIGNED> id261out_value;

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id273out_result[2];

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id1872out_value;

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id275out_result[2];

  HWRawBits<24> id277out_dataout[5];

  HWRawBits<24> id2304out_output[2];

  HWRawBits<24> id1871out_value;

  HWRawBits<24> id423out_result[2];

  HWRawBits<24> id425out_result[2];

  HWFloat<8,24> id427out_o[8];

  HWFloat<8,24> id2027out_floatOut[2];

  HWFloat<8,24> id2306out_output[4];

  HWRawBits<1> id2335out_output[7];

  HWOffsetFix<7,0,UNSIGNED> id1869out_value;

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id461out_result[2];

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id1868out_value;

  HWOffsetFix<1,0,UNSIGNED> id1658out_result[2];

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id1867out_value;

  HWOffsetFix<1,0,UNSIGNED> id1659out_result[2];

  HWOffsetFix<1,0,UNSIGNED> id470out_result[2];

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id1866out_value;

  HWOffsetFix<1,0,UNSIGNED> id1660out_result[2];

  HWOffsetFix<1,0,UNSIGNED> id2307out_output[2];

  HWOffsetFix<2,0,UNSIGNED> id2333out_output[6];

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id1865out_value;

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id1864out_value;

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id481out_result[2];

  HWOffsetFix<1,0,UNSIGNED> id1661out_result[2];

  HWRawBits<1> id617out_value;

  HWRawBits<1> id618out_result[2];

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id1863out_value;

  HWOffsetFix<1,0,UNSIGNED> id1663out_result[2];

  HWRawBits<1> id611out_value;

  HWRawBits<1> id612out_result[2];

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id1862out_value;

  HWOffsetFix<1,0,UNSIGNED> id1665out_result[2];

  HWRawBits<1> id605out_value;

  HWRawBits<1> id606out_result[2];

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id1861out_value;

  HWOffsetFix<1,0,UNSIGNED> id1667out_result[2];

  HWRawBits<1> id599out_value;

  HWRawBits<1> id600out_result[2];

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id1860out_value;

  HWOffsetFix<1,0,UNSIGNED> id1669out_result[2];

  HWRawBits<1> id593out_value;

  HWRawBits<1> id594out_result[2];

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id1859out_value;

  HWOffsetFix<1,0,UNSIGNED> id1671out_result[2];

  HWRawBits<1> id587out_value;

  HWRawBits<1> id588out_result[2];

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id1858out_value;

  HWOffsetFix<1,0,UNSIGNED> id1673out_result[2];

  HWRawBits<1> id581out_value;

  HWRawBits<1> id582out_result[2];

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id1857out_value;

  HWOffsetFix<1,0,UNSIGNED> id1675out_result[2];

  HWRawBits<1> id575out_value;

  HWRawBits<1> id576out_result[2];

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id1856out_value;

  HWOffsetFix<1,0,UNSIGNED> id1677out_result[2];

  HWRawBits<1> id569out_value;

  HWRawBits<1> id570out_result[2];

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id1855out_value;

  HWOffsetFix<1,0,UNSIGNED> id1679out_result[2];

  HWRawBits<1> id563out_value;

  HWRawBits<1> id564out_result[2];

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id1854out_value;

  HWOffsetFix<1,0,UNSIGNED> id1681out_result[2];

  HWRawBits<1> id557out_value;

  HWRawBits<1> id558out_result[2];

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id1853out_value;

  HWOffsetFix<1,0,UNSIGNED> id1683out_result[2];

  HWRawBits<1> id551out_value;

  HWRawBits<1> id552out_result[2];

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id1852out_value;

  HWOffsetFix<1,0,UNSIGNED> id1685out_result[2];

  HWRawBits<1> id545out_value;

  HWRawBits<1> id546out_result[2];

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id1851out_value;

  HWOffsetFix<1,0,UNSIGNED> id1687out_result[2];

  HWRawBits<1> id539out_value;

  HWRawBits<1> id540out_result[2];

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id1850out_value;

  HWOffsetFix<1,0,UNSIGNED> id1689out_result[2];

  HWRawBits<1> id533out_value;

  HWRawBits<1> id534out_result[2];

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id1849out_value;

  HWOffsetFix<1,0,UNSIGNED> id1691out_result[2];

  HWRawBits<1> id527out_value;

  HWRawBits<1> id528out_result[2];

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id1848out_value;

  HWOffsetFix<1,0,UNSIGNED> id1693out_result[2];

  HWRawBits<1> id521out_value;

  HWRawBits<1> id522out_result[2];

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id1847out_value;

  HWOffsetFix<1,0,UNSIGNED> id1695out_result[2];

  HWRawBits<1> id515out_value;

  HWRawBits<1> id516out_result[2];

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id1846out_value;

  HWOffsetFix<1,0,UNSIGNED> id1697out_result[2];

  HWRawBits<1> id509out_value;

  HWRawBits<1> id510out_result[2];

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id1845out_value;

  HWOffsetFix<1,0,UNSIGNED> id1699out_result[2];

  HWRawBits<1> id503out_value;

  HWRawBits<1> id504out_result[2];

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id1844out_value;

  HWOffsetFix<1,0,UNSIGNED> id1701out_result[2];

  HWRawBits<1> id497out_value;

  HWRawBits<1> id498out_result[2];

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id1843out_value;

  HWOffsetFix<1,0,UNSIGNED> id1703out_result[2];

  HWRawBits<1> id491out_value;

  HWRawBits<1> id492out_result[2];

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id1842out_value;

  HWOffsetFix<1,0,UNSIGNED> id1705out_result[2];

  HWRawBits<1> id485out_value;

  HWRawBits<1> id486out_result[2];

  HWOffsetFix<1,0,UNSIGNED> id479out_value;

  HWOffsetFix<5,0,UNSIGNED> id2331out_output[4];

  HWRawBits<24> id621out_dataout[5];

  HWOffsetFix<1,0,UNSIGNED> id462out_value;

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id474out_result[2];

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id1841out_value;

  HWOffsetFix<9,0,TWOSCOMPLEMENT> id476out_result[2];

  HWRawBits<24> id478out_dataout[5];

  HWRawBits<24> id2334out_output[2];

  HWRawBits<24> id1840out_value;

  HWRawBits<24> id624out_result[2];

  HWRawBits<24> id626out_result[2];

  HWFloat<8,24> id628out_o[8];

  HWFloat<8,24> id629out_result[2];

  HWFloat<8,24> id635out_result[9];

  HWFloat<8,24> id634out_result[9];

  HWFloat<8,24> id636out_result[9];

  HWFloat<8,24> id632out_result[2];

  HWFloat<8,24> id2338out_output[9];

  HWFloat<8,24> id637out_result[9];

  HWFloat<8,24> id638out_result[12];

  HWFloat<8,24> id631out_result[2];

  HWFloat<8,24> id639out_result[9];

  HWFloat<8,24> id2340out_output[20];

  HWFloat<8,24> id640out_result[12];

  HWFloat<8,24> id630out_result[2];

  HWFloat<8,24> id2342out_output[39];

  HWFloat<8,24> id641out_result[12];

  HWFloat<8,24> id1839out_value;

  HWFloat<8,24> id648out_result[2];

  HWRawBits<2> id1919out_value;

  HWOffsetFix<1,0,UNSIGNED> id1572out_result[2];

  HWRawBits<2> id1918out_value;

  HWOffsetFix<1,0,UNSIGNED> id1573out_result[2];

  HWOffsetFix<1,0,UNSIGNED> id226out_result[2];

  HWOffsetFix<1,0,UNSIGNED> id2344out_output[79];

  HWFloat<8,24> id662out_value;

  HWFloat<8,24> id663out_result[2];

  HWFloat<8,24> id664out_result[9];

  HWFloat<8,24> id2346out_output[20];

  HWFloat<8,24> id1224out_result[9];

  HWFloat<8,24> id1225out_result[9];

  HWFloat<8,24> id1226out_result[12];

  HWFloat<8,24> id1227out_result[2];

  HWRawBits<1> id2353out_output[3];

  HWFloat<8,24> id1837out_value;

  HWOffsetFix<1,0,UNSIGNED> id1229out_result[3];

  HWOffsetFix<1,0,UNSIGNED> id1231out_result[2];

  HWOffsetFix<1,0,UNSIGNED> id1237out_result[2];

  HWRawBits<31> id2354out_output[3];

  HWFloat<8,24> id1245out_result[2];

  HWFloat<8,24> id2356out_output[19];

  HWFloat<8,24> id1264out_value;

  HWFloat<8,24> id1265out_result[2];

  HWFloat<8,24> id2359out_output[22];

  HWFloat<8,24> id21out_value;

  HWFloat<8,24> id22out_result[2];

  HWFloat<8,24> id1213out_result[9];

  HWFloat<8,24> id1214out_result[9];

  HWFloat<8,24> id1215out_result[9];

  HWFloat<8,24> id1216out_result[12];

  HWFloat<8,24> id1217out_result[29];

  HWFloat<8,24> id2433out_output[2];

  HWFloat<8,24> id1218out_result[9];

  HWFloat<8,24> id1219out_result[12];

  HWFloat<8,24> id1220out_result[2];

  HWFloat<8,24> id1243out_result[2];

  HWFloat<8,24> id1262out_value;

  HWFloat<8,24> id1263out_result[2];

  HWFloat<8,24> id19out_value;

  HWFloat<8,24> id20out_result[2];

  HWFloat<8,24> id1192out_result[9];

  HWFloat<8,24> id1193out_result[12];

  HWFloat<8,24> id2367out_output[26];

  HWFloat<8,24> id1838out_value;

  HWOffsetFix<1,0,UNSIGNED> id1195out_result[3];

  HWOffsetFix<1,0,UNSIGNED> id2250out_output[21];

  HWOffsetFix<1,0,UNSIGNED> id2445out_output[3];

  HWOffsetFix<1,0,UNSIGNED> id2446out_output[19];

  HWOffsetFix<1,0,UNSIGNED> id1202out_result[2];

  HWFloat<8,24> id2437out_output[40];

  HWFloat<8,24> id1203out_result[9];

  HWFloat<8,24> id1204out_result[9];

  HWFloat<8,24> id1205out_result[9];

  HWFloat<8,24> id1206out_result[12];

  HWFloat<8,24> id1207out_result[29];

  HWFloat<8,24> id1208out_result[9];

  HWFloat<8,24> id1209out_result[12];

  HWFloat<8,24> id1210out_result[2];

  HWOffsetFix<1,0,UNSIGNED> id1233out_result[2];

  HWOffsetFix<1,0,UNSIGNED> id2375out_output[19];

  HWFloat<8,24> id1241out_result[2];

  HWFloat<8,24> id1260out_value;

  HWFloat<8,24> id1261out_result[2];

  HWFloat<8,24> id17out_value;

  HWFloat<8,24> id18out_result[2];

  HWFloat<8,24> id2369out_output[22];

  HWFloat<8,24> id2447out_output[9];

  HWFloat<8,24> id2448out_output[40];

  HWFloat<8,24> id2449out_output[3];

  HWFloat<8,24> id2416out_output[37];

  HWFloat<8,24> id1836out_value;

  HWOffsetFix<1,0,UNSIGNED> id2414out_output[59];

  HWFloat<8,24> id2378out_output[13];

  HWFloat<8,24> id117out_result[12];

  HWFloat<8,24> id2405out_output[9];

  HWFloat<8,24> id2452out_output[59];

  HWFloat<8,24> id1266out_value;

  HWFloat<8,24> id1267out_result[2];

  HWFloat<8,24> id23out_value;

  HWFloat<8,24> id24out_result[2];

  HWFloat<8,24> id109out_result[12];

  HWFloat<8,24> id110out_result[2];

  HWFloat<8,24> id111out_result[9];

  HWFloat<8,24> id112out_result[12];

  HWFloat<8,24> id1254out_value;

  HWFloat<8,24> id1255out_result[2];

  HWFloat<8,24> id2141out_output[79];

  HWFloat<8,24> id2454out_output[13];

  HWFloat<8,24> id15out_value;

  HWFloat<8,24> id16out_result[2];

  HWFloat<8,24> id115out_result[9];

  HWFloat<8,24> id116out_result[12];

  HWFloat<8,24> id1258out_value;

  HWFloat<8,24> id1259out_result[2];

  HWFloat<8,24> id2388out_output[79];

  HWFloat<8,24> id2455out_output[13];

  HWFloat<8,24> id2392out_output[91];

  HWFloat<8,24> id2421out_output[58];

  HWFloat<8,24> id2394out_output[12];

  HWFloat<8,24> id2451out_output[2];

  HWFloat<8,24> id2453out_output[20];

  HWOffsetFix<1,0,UNSIGNED> id2425out_output[13];

  HWOffsetFix<1,0,UNSIGNED> id2431out_output[2];

  HWFloat<8,24> id2409out_output[87];

  HWFloat<8,24> id2420out_output[9];

  HWFloat<8,24> id2419out_output[4];

  HWFloat<8,24> id1256out_value;

  HWFloat<8,24> id1257out_result[2];

  HWFloat<8,24> id13out_value;

  HWFloat<8,24> id14out_result[2];

  HWFloat<8,24> id2403out_output[79];

  HWFloat<8,24> id113out_result[9];

  HWFloat<8,24> id114out_result[12];

  HWOffsetFix<1,0,UNSIGNED> id118out_value;

  std::string format_string_loopKernel_1 (const char* _format_arg_format_string, const HWFloat<8,24> &_format_arg_0, const HWOffsetFix<1,0,UNSIGNED> &_format_arg_1);
  HWOffsetFix<1,0,UNSIGNED> id1272out_value;

  HWFloat<11,53> id1273out_value;

  HWFloat<8,24> id2410out_output[26];

  HWFloat<8,24> id1835out_value;

  HWOffsetFix<1,0,UNSIGNED> id1271out_result[3];

  std::string format_string_loopKernel_2 (const char* _format_arg_format_string, const HWFloat<11,53> &_format_arg_0, const HWFloat<8,24> &_format_arg_1, const HWFloat<8,24> &_format_arg_2, const HWFloat<8,24> &_format_arg_3, const HWFloat<8,24> &_format_arg_4, const HWOffsetFix<1,0,UNSIGNED> &_format_arg_5);
  HWOffsetFix<1,0,UNSIGNED> id1275out_io_z_force_disabled;

  HWOffsetFix<1,0,UNSIGNED> id1351out_value;

  HWOffsetFix<1,0,UNSIGNED> id1834out_value;

  HWOffsetFix<49,0,UNSIGNED> id1348out_value;

  HWOffsetFix<48,0,UNSIGNED> id1349out_count;
  HWOffsetFix<1,0,UNSIGNED> id1349out_wrap;

  HWOffsetFix<49,0,UNSIGNED> id1349st_count;

  HWOffsetFix<1,0,UNSIGNED> id0out_value;

  const HWOffsetFix<1,0,UNSIGNED> c_hw_fix_1_0_uns_bits;
  const HWOffsetFix<8,0,UNSIGNED> c_hw_fix_8_0_uns_bits;
  const HWOffsetFix<1,0,UNSIGNED> c_hw_fix_1_0_uns_bits_1;
  const HWFloat<8,24> c_hw_flt_8_24_bits;
  const HWFloat<8,24> c_hw_flt_8_24_bits_1;
  const HWFloat<8,24> c_hw_flt_8_24_bits_2;
  const HWOffsetFix<9,0,TWOSCOMPLEMENT> c_hw_fix_9_0_sgn_bits;
  const HWOffsetFix<25,-23,TWOSCOMPLEMENT> c_hw_fix_25_n23_sgn_bits;
  const HWRawBits<1> c_hw_bit_1_bits;
  const HWRawBits<31> c_hw_bit_31_bits;
  const HWOffsetFix<25,-23,TWOSCOMPLEMENT> c_hw_fix_25_n23_sgn_bits_1;
  const HWOffsetFix<7,0,UNSIGNED> c_hw_fix_7_0_uns_bits;
  const HWOffsetFix<9,0,TWOSCOMPLEMENT> c_hw_fix_9_0_sgn_bits_1;
  const HWFloat<8,24> c_hw_flt_8_24_bits_3;
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
  const HWRawBits<2> c_hw_bit_2_bits;
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
  const HWRawBits<2> c_hw_bit_2_bits_1;
  const HWRawBits<2> c_hw_bit_2_bits_2;
  const HWFloat<11,53> c_hw_flt_11_53_bits;
  const HWOffsetFix<49,0,UNSIGNED> c_hw_fix_49_0_uns_bits;
  const HWOffsetFix<49,0,UNSIGNED> c_hw_fix_49_0_uns_bits_1;
  const HWOffsetFix<49,0,UNSIGNED> c_hw_fix_49_0_uns_bits_2;

  void execute0();
};

}

#endif /* LOOPKERNEL_H_ */
