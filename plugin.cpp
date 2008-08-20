#include <ida.hpp>
#include <idp.hpp>
#include <loader.hpp>
#include <kernwin.hpp>

#include "VCTaxo.h"

int idaapi init()
{
	return g_vctaxo.Init();
}

void idaapi run(int arg)
{
	g_vctaxo.Run(arg);
	return;
}

void idaapi term()
{
	g_vctaxo.Term();
	return;
}

plugin_t PLUGIN =
{
	IDP_INTERFACE_VERSION,
	PLUGIN_UNL,
	init,
	term,
	run,
	NULL,
	NULL,
	"VCTaxo",
	"Ctrl-+"
};