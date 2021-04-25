#pragma once


class CBlender_example : public IBlender
{
public:
	virtual LPCSTR getComment() { return "Write here whatever you want"; }
	virtual BOOL canBeDetailed() { return FALSE; }
	virtual BOOL canBeLMAPped() { return FALSE; }

	virtual void Compile(CBlender_Compile& C);

	CBlender_example();
	virtual ~CBlender_example();
};
