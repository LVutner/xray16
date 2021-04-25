#include "stdafx.h"

#include "blender_example.h"

CBlender_example::CBlender_example() { description.CLS = 0; }

CBlender_example::~CBlender_example()
{
}

void CBlender_example::Compile(CBlender_Compile& C)
{
	IBlender::Compile(C);
	
	//You can add up to 6 different shaders/passes.
	switch (C.iElement)
	{
	case 0: //Our vertex shader is "stub_screen_space" (take it from Anomaly), and our pixel shader is "example"
		C.r_Pass("stub_screen_space", "copy_nomsaa", FALSE, FALSE, FALSE);
		
		//Our scene sampler
		C.r_dx10Texture("s_image", r2_RT_generic0);

		//Our MRT
		C.r_dx10Texture("s_position", r2_RT_P);
		C.r_dx10Texture("s_diffuse", r2_RT_albedo);
		
		//Sampler states
		C.r_dx10Sampler("smp_base");
		C.r_dx10Sampler("smp_nofilter");
		C.r_dx10Sampler("smp_rtlinear");
		C.r_End();
		break;	
	}
}
