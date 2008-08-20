#pragma once

#include <vector>
#include <map>
#include <algorithm>
#include <string>
#include <sstream>
#include <boost/shared_ptr.hpp>

#include <ida.hpp>
#include <idp.hpp>
#include <loader.hpp>
#include <kernwin.hpp>
#include <allins.hpp>
#include <name.hpp>

using namespace std;
using namespace boost;

class VCClass;
class VCBaseClass;
class VCVMT;
class VCVirtualMethod;
class VCVirtualMethodPrototype;
class VCMemberVariable;

class VCClass
{
public:
	vector<shared_ptr<VCBaseClass>> _baseclasses;
};


class VCBaseClass
{
public:
	shared_ptr<VCVMT> _vmt;
};

class VCVMT
{
public:
	ea_t _address;
	shared_ptr<VCBaseClass> _baseclass;
	vector<shared_ptr<VCVirtualMethod>> _virtualmethods;
};

class VCVirtualMethod
{
public:
	ea_t _address;
};

class VCVirtualMethodPrototype
{
public:
	shared_ptr<VCBaseClass> _owner;
};

class VCMemberVariable
{
public:
};