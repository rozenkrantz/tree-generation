#ifndef BRANCH_H
#define BRANCH_H

namespace dequinox
{
	struct Branch
	{
        	float len{5};
        	int16_t counter{0};
        	Vector pos{0,0};
        	Vector dir{0,0};
        	Vector saveDir{0,0};
        	Branch *parent{nullptr};

		Branch(Vector p, Vector d) : pos(p), dir(d) {}
		
		Branch(Branch *p)
		{
		    	parent = p;
		    	pos = parent->next();
		    	dir = parent->dir;
		    	saveDir = dir;
		}

		void operator=(const Branch &o)
		{
		    	pos = o.pos;
		    	dir = o.dir;
		    	parent = o.parent;
		    	counter = o.counter;
		    	len = o.len;
		    	saveDir = o.saveDir;
		}

		void reset()
		{
		    	counter = 0;
		    	dir = saveDir;
		}

		Vector next() const
		{
		    	Vector v = dir * len;
			Vector next = pos + v;
			return next;
		}
	};
}

#endif // BRANCH_H
