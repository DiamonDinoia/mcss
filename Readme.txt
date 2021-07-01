
FILES:
------
  
  - Readme.txt : this Readme file 
  - mcss.cc    : the single c++ source file 
  

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


Compile and Run
----------------

There is no any dependencies and everything is implemented in the single `mcss.cc`
source file. Some C++11 functionalities are used to generate uniformly random 
variable values on [0,1) so easy to compile and execute:  

    Compile :  g++ -std=c++11 -O3 -o mcss mcss.cc 
    Run     : ./mcss
