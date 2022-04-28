DESCRIPTION:
------------

A simple simulation of e-/e+ transport considering only elastic scattering as 
possible interactions described by scattering of spin-less e-/e+ on an 
exponentially screened Coulomb potential i.e. using the Rutherford DCS.

Each e-/e+ trajectory starts at the [0,0,0] position pointing toward to the 
[0,0,1] direction and followed until the cumulative track length reaches a given 
`limit`. This track length limit is the termination criterion for the individual 
trajectory history simulations. Therefore, each trajectory has exactly the same 
(`limit`) cumulated track length at termination but the corresponding final 
position will be different for each. This final position is used to generate the 
longitudinal (along the <z> axes) and the transverse (along the <xy> plane) 
position distributions after travelling `limit` length in the given `material` 
with the given `kinetic energy`. These distributions are written into files at 
the termination.

The configuration of the simulation can be given in the `main()` function.
 - theMaterial : material i.e. one of the WATER, AIR, BONE, TISSUE, GOLD
 - theEKin     : kinetic energy of the e-/e+ (there is no energy loss)
 - theLimit    : cumulated track length limit given in elastic mean free path units
 - theNumHists : number of trajectory histories to generate during teh simulation

The default settings, given in the `main()` function, should generate the same 
longitudinal and transverse distributions that are shown in my old presentation 
in slides #25 and #26 (see the link below). NOTE: there is a typo in the 
presentation below: 128 [MeV] should be 128 [keV] which is correct here in the 
default settings.

https://indico.fnal.gov/event/9717/contributions/115128/attachments/74561/89448/MihalyNovakGeant4CollaborationMeetingNewEMModels.pdf

Requirements:
	cmake 3.9
	C++11 compiler
	(OPTIONAL) MaxCompiler and MaxPower 2021.1
	(OPTIONAL) Vivado 2019.2
	(OPTIONAL) ant

(OPTIONAL) catch2 library required for testing: 
	git submodule update --init 
	
(OPTIONAL) Build FPGA Bitstream
--------------------
	1. cd FPGA/DFE 
	2. run ./buid.sh
	
Compile and Run
----------------
	1. mkdir build
	2. cd build
	3. cmake ../ 
		- -DCMAKE_BUILD_TYPE=Debug -> not optimised debug build with stack protectors and debug symbols
		- -DCMAKE_BUILD_TYPE=Release -> optimised build with no debug options
		- -DCMAKE_BUILD_TYPE=DebugOptimized -> optimised debug build with debug symbols
		- -DTESTS=ON -> build unit tests (requires catch2)
		- -DFPGA_BUILD=ON -> build FPGA CPU code (requires building FPGA bitstream)
	4. ./mccs [options]
		- -t number of threads to use (-t1 for sequential version)
		- -m material index  0 -> WATER, 1-> AIR, 2 -> BONE, 3 -> TISSUE, 4 -> GOLD
		- -n number of histories
		- -f filename writes the histograms to filename
	  	- -d uses DPFA accelerator
	   ./test/test executeds unit tests

Example usage:
	./mcss -m 3 -n 10000000

Acknowledgements: 
	1. topas for providing ks-test.cpp https://github.com/tumi8/topas/blob/master/detectionmodules/statmodules/wkp-module/ks-test.cpp
	2. Geant4 for providing the original algorithm https://geant4.web.cern.ch/
