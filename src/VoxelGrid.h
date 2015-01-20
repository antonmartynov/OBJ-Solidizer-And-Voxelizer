#ifndef VoxelGridH
#define VoxelGridH

struct AxisParameters
{
	float start;
	float step;
	float count;
	float getValue(int index)
	{
		return start + step * (float)index;
    }
};

struct Dimensions
{
	AxisParameters x;
	AxisParameters y;
	AxisParameters z;
};

class VoxelGrid
{
public:

	VoxelGrid();
	~VoxelGrid();

	void setDimensions(Dimensions initDimensions);
	void allocate();
	void deallocate();

private:

	Dimensions dimensions;
	bool *** data; // far from perfect, since bools take up much more than 1 bit of memory.
				   // I'll come up with a better solution soon
};

#endif
