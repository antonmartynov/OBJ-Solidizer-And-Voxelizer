#ifndef VoxelGridH
#define VoxelGridH

struct AxisParameters
{
	float start;
	float step;
	int count;
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
	float getXValue(int index)
	{
		return x.getValue(index);
	}
	float getYValue(int index)
	{
		return y.getValue(index);
	}
	float getZValue(int index)
	{
        return z.getValue(index);
    }
};

class VoxelGrid
{
public:

	VoxelGrid(Dimensions initDimensions);
	~VoxelGrid();
	void allocate();
	void deallocate();
	Dimensions getDimensions();
	bool *** getData();

private:

	Dimensions dimensions;
	bool *** data; // far from perfect, since bools take up much more than 1 bit of memory.
				   // I'll come up with a better solution soon

	void setDimensions(Dimensions initDimensions);
};

#endif
