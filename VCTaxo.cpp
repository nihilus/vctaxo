#include "VCTaxo.h"

VCTaxo g_vctaxo;

VCTaxo::VCTaxo(void)
{
}

VCTaxo::~VCTaxo(void)
{
}

int VCTaxo::Init()
{
	return PLUGIN_OK;
}

void VCTaxo::Run(int arg)
{
}

void VCTaxo::Term()
{
}

void VCTaxo::Reset()
{
	_addr_to_vmt.clear();
	_addr_to_virtualmethod.clear();
}

void VCTaxo::StartAnalysis()
{
	Populate();
}

void VCTaxo::Populate()
{
	Reset();
	for(ea_t a = inf.minEA; a < inf.maxEA && a != BADADDR; a = next_head(a, inf.maxEA))
	{
		if(ua_ana0(a) == 0)
			continue;

		if(cmd.itype == NN_mov && (cmd.Operands[0].type == o_phrase || cmd.Operands[0].type == o_displ) && cmd.Operands[1].type == o_imm)
		{
			showAddr(a);
			// found a move of an immediate value into a register reference, check if it's an legal offset
			ea_t offset = cmd.Operands[1].value;
			if(offset < inf.minEA || offset > inf.maxEA)
				continue;
			//check the first dword of the vmt looks like a valid function offset
			ea_t first_offset = get_long(offset);
			if(first_offset < inf.minEA || first_offset > inf.maxEA)
				continue;
			// fairly sure this is a vmt init now
			if(_addr_to_vmt.find(offset) == _addr_to_vmt.end())
			{
			}
		}
	}
}