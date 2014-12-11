#ifndef __RESOURCE_H_
#define __RESOURCE_H_
class Resource
{
public:
	virtual ~Resource(void);

private:
	std::string path;
	void Init(std::string);

};

#endif

