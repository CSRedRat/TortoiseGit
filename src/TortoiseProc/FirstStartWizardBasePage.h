// TortoiseGit - a Windows shell extension for easy version control

// Copyright (C) 2016 - TortoiseGit

// This program is free software; you can redistribute it and/or
// modify it under the terms of the GNU General Public License
// as published by the Free Software Foundation; either version 2
// of the License, or (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software Foundation,
// 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
//
#pragma once
#include "ResizablePageEx.h"
#include "AppUtils.h"
#include "CommonDialogFunctions.h"

/**
 * base class for the merge wizard property pages
 */
class CFirstStartWizardBasePage : public CResizablePageEx, protected CommonDialogFunctions<CResizablePageEx>
{
	DECLARE_DYNAMIC(CFirstStartWizardBasePage)
public:
	CFirstStartWizardBasePage()
		: CResizablePageEx()
		, CommonDialogFunctions(this)
		, m_bCancelled(false)
		{}
	explicit CFirstStartWizardBasePage(UINT nIDTemplate, UINT nIDCaption = 0)
		: CResizablePageEx(nIDTemplate, nIDCaption, 0)
		, CommonDialogFunctions(this)
		, m_bCancelled(false)
		{}
	explicit CFirstStartWizardBasePage(LPCTSTR lpszTemplateName, UINT nIDCaption = 0)
		: CResizablePageEx(lpszTemplateName, nIDCaption, 0)
		, CommonDialogFunctions(this)
		, m_bCancelled(false)
		{}

	virtual ~CFirstStartWizardBasePage() {}
	virtual bool	OkToCancel() { return true; }

protected:
	virtual void	SetButtonTexts();

	//virtual BOOL    Cancel() override { return m_bCancelled; }
private:
	bool			m_bCancelled;
};
