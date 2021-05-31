#pragma once

class Shape{
public:

	//pure virtual function, requires the child to have its own draw function
	virtual void draw(float zindex = 0) const = 0;

	/* NORMAL VIRTUAL
	virtual void talk() const {
		cout<<"talk";
	}
	*/

//IF U HAVE ABSTRACT TYPE MAKE VIRTUAL DESTRUCTOR
	virtual ~Shape() {}
};
