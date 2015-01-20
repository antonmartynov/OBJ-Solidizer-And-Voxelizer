# OBJ Solidizer And Voxelizer
Voxelizes OBJ geometry (vertices and faces) by interpreting it as a boundary of solid geometry (brushes or portals).

Makes use of syoyo's tinyobjloader for opening OBJ files: https://github.com/syoyo/tinyobjloader

This project was born out of the idea of recreating a map from a [portal engine](http://en.wikipedia.org/wiki/Portal_rendering "Wikipedia: Portal rendering") based game (Blade Of Darkness) in Minecraft (a sandbox game with a voxel-like landscape); however, it can be used for voxelizing any OBJ geometry in general. In the future, I'll provide a small library for reading the output files of OBJ Solidizer And Voxelizer.

Current status: infinitely deep alpha. Doesn't actually do what it's supposed to do (yet).

*"I'm a solidizer*  
*Object voxelizer"*  
– Lolzo, upon seeing the project name

## Roadmap

Short-term plans:
- Make the working proof-of-concept version. Barely any optimizations.
- Fix the disastrously long operation of writing the OBJ file.

Medium-term plans:
- Implement multithreading
- Add various voxelization parameters
- Heavily optimize the engine:
 - More compact storage of voxel data
 - Algorithm optimizations
 - Use octrees for storing / accessing geometry - 
- Use std::vectors wherever possible

Long-term plans:
- Optimize the cube representation of the voxelized geometry
- Export the results to a Minecraft world
- Visualization of the process (or input / output data)
- Make a good-looking, user-friendly GUI