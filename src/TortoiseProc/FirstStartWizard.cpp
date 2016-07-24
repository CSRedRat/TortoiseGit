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
#include "stdafx.h"
#include "TortoiseProc.h"
#include "FirstStartWizard.h"
#include "TaskbarUUID.h"

IMPLEMENT_DYNAMIC(CFirstStartWizard, CStandAloneDialogTmpl<CResizableSheetEx>)

CFirstStartWizard::CFirstStartWizard(UINT nIDCaption, CWnd* pParentWnd, UINT iSelectPage)
:CStandAloneDialogTmpl<CResizableSheetEx>(nIDCaption, pParentWnd)
	, m_FirstPageActivation(true)
{
	SetWizardMode();
	SetActivePage(iSelectPage);
	AddPage(&page1);
//	AddPage(&tree);
//	AddPage(&revrange);
//	AddPage(&options);

/*	switch (iSelectPage)
	{
	case 1:
		nRevRangeMerge = MERGEWIZARD_TREE;
		break;
	case 2:
		nRevRangeMerge = MERGEWIZARD_REVRANGE;
		break;
	}*/

	m_psh.dwFlags |= PSH_WIZARD97 | PSH_HEADER; // PSP_HASHELP | 
	m_psh.pszbmHeader = L"header"; //MAKEINTRESOURCE(IDB_MERGEWIZARDTITLE);

	m_psh.hInstance = AfxGetResourceHandle();
}

CFirstStartWizard::~CFirstStartWizard()
{
}

BEGIN_MESSAGE_MAP(CFirstStartWizard, CStandAloneDialogTmpl<CResizableSheetEx>)
	ON_WM_SYSCOMMAND()
	ON_COMMAND(IDCANCEL, &CFirstStartWizard::OnCancel)
END_MESSAGE_MAP()

// CFirstStartWizard message handlers
BOOL CFirstStartWizard::OnInitDialog()
{
	BOOL bResult = __super::OnInitDialog();
	CAppUtils::MarkWindowAsUnpinnable(m_hWnd);

	if (!m_pParentWnd  && hWndExplorer)
		CenterWindow(CWnd::FromHandle(hWndExplorer));
	EnableSaveRestore(L"FirstStartWizard");

	return bResult;
}

void CFirstStartWizard::OnSysCommand(UINT nID, LPARAM lParam)
{
	switch (nID & 0xFFF0)
	{
	case SC_CLOSE:
		{
			CFirstStartWizardBasePage* page = (CFirstStartWizardBasePage*)GetActivePage();
			if (page && !page->OkToCancel())
				break;
		}
		// fall through
	default:
		__super::OnSysCommand(nID, lParam);
		break;
	}
}

void CFirstStartWizard::OnCancel()
{
	CFirstStartWizardBasePage* page = (CFirstStartWizardBasePage*)GetActivePage();
	if (!page || page->OkToCancel())
		Default();
}
void CFirstStartWizard::SaveMode()
{
/*	CRegDWORD regMergeWizardMode(L"Software\\TortoiseSVN\\MergeWizardMode", 0);
	if (DWORD(regMergeWizardMode))
	{
		switch (nRevRangeMerge)
		{
		case IDD_MERGEWIZARD_REVRANGE:
			regMergeWizardMode = 2;
			break;
		case IDD_MERGEWIZARD_TREE:
			regMergeWizardMode = 1;
			break;
		default:
			regMergeWizardMode = 0;
			break;
		}
	}*/
}

LRESULT CFirstStartWizard::GetSecondPage()
{
/*	switch (nRevRangeMerge)
	{
	case MERGEWIZARD_REVRANGE:
		return IDD_MERGEWIZARD_REVRANGE;
	case MERGEWIZARD_TREE:
		return IDD_MERGEWIZARD_TREE;
	}
	return IDD_MERGEWIZARD_REVRANGE;*/
	return 0;
}
