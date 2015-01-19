# OBJ-Solidizer-And-Voxelizer
Voxelizes OBJ geometry (vertices and faces) by interpreting it as a boundary of solid geometry.

Makes use syoyo's tinyobjloader for opening OBJ files: https://github.com/syoyo/tinyobjloader

Current status: infinitely deep alpha. Doesn't actually do what it's supposed to do (yet).

Issues / TODO / Plans:
- Writing the OBJ file is terribly slow and must be fixed ASAP (I've pinpointed the source of the problem).
- Voxelize the loaded geometry.
- Optimize the voxelization process by using octrees.
- Output the voxelization results to file / generate an OBJ made out of cubes based on the voxelization results.
- Various voxelization parameters.
- (Long-term goal) export the voxelization results to Minecraft.

This project was born out of the idea of recreating a map from a portal engine based game (Blade Of Darkness) in Minecraft (a voxel landscape game).
