#ifndef OneDimensionalArrayH
#define OneDimensionalArrayH

/*
This thing needs some refactoring.
1. For now it's all in one .h file - should be split into .h and .cpp.
2. Initialize might fail when a huge file is specified (there may not be
   a contigous region of memory for a piece of data this big)
3. Init / DeInit / GetElement must have boundary and memory checks and proper
   return codes.
4. Probably I'm better off just using std::vector instead of all this, though.
*/

template <class T>
class OneDimensionalArray
{
public:

	OneDimensionalArray(int initSize)
	{
		initialize(initSize);
    }
	~OneDimensionalArray()
	{
        deInitialize();
    }

	T * getElement(int index)
	{
		return &(data[index]);
    }
	int getCount()
	{
		return count;
    }

private:

	void initialize(int initSize)
	{
		data = new T [initSize];
		count = initSize;
    }
	void deInitialize()
	{
		delete [] data;
    }
	int count;
	T * data;
};

#endif
