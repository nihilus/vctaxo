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

#include "VCClass.h"

using namespace std;
using namespace boost;

class VCTaxo
{
public:
	VCTaxo(void);
	~VCTaxo(void);

	int Init();
	void Run(int arg);
	void Term();

	void Reset();
	void StartAnalysis();
	void Populate();

private:
	map<ea_t, shared_ptr<VCVMT>> _addr_to_vmt;
	map<ea_t, shared_ptr<VCVirtualMethod>> _addr_to_virtualmethod;
};

extern VCTaxo g_vctaxo;