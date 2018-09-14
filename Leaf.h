#ifndef LEAF_H
#define LEAF_H

namespace dequinox
{
	struct Leaf
	{
            bool reached{false};
            Vector pos{0,0};

            Leaf(Vector pos) : pos(pos) {}
            	
		void show(Bitmap &image)
		{
                	image.setPixel(pos.x, pos.y, 255, 255, 255);
            }
        
	    	void gotReached()
		{
            	reached = true;
            }
        	
		Vector getPos()
		{
        		return pos;
        	}
    	};
}

#endif // LEAF_H
