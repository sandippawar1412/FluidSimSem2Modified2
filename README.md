FluidSimSem2
============
#NavierStokes#Water#Particles#LevelSet#WaterSurface
Project is about simulating liquid.. which uses NavierStokes equation as physics model and eulers approach to approximate it..
Done(as of now): 2D liquid simulator with complete implementation for routines,

calculate CFL(),
Advcet Particles,
calculate LevelSetDistances using Fast Sweeping Method,
Advection(advect velocities),
Add Gravity,
Projection,
Extrapolation,
create Surface Using Mraching Square,
//add Forces,
//add Viscosity,

Simulator is tested for real time results with grid size 64*64 on machine :
Processor - Intel Core 2 Duo T6600 @ 2.20GHz
cache size - 2048kb
RAM - 4096MB

-------
to do..

different Paths
1. extend it to 3D
2. work with openMP to get the real time results for Grid Size at least upto 1024*1024



