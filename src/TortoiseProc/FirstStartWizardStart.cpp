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
#include "FirstStartWizardStart.h"

IMPLEMENT_DYNAMIC(CFirstStartWizardStart, CFirstStartWizardBasePage)

CFirstStartWizardStart::CFirstStartWizardStart() : CFirstStartWizardBasePage(CFirstStartWizardStart::IDD)
{
	m_psp.dwFlags |= PSP_DEFAULT | PSP_USEHEADERTITLE | PSP_USEHEADERSUBTITLE;
	m_psp.pszHeaderTitle = L"headertitle";// MAKEINTRESOURCE(IDS_MERGEWIZARD_STARTTITLE);
	m_psp.pszHeaderSubTitle = L"subtitle";//MAKEINTRESOURCE(IDS_MERGEWIZARD_STARTSUBTITLE);
}

CFirstStartWizardStart::~CFirstStartWizardStart()
{
}

void CFirstStartWizardStart::DoDataExchange(CDataExchange* pDX)
{
	CFirstStartWizardBasePage::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CFirstStartWizardStart, CFirstStartWizardBasePage)
END_MESSAGE_MAP()

LRESULT CFirstStartWizardStart::OnWizardNext()
{
	//int nButton = GetCheckedRadioButton(IDC_MERGE_REVRANGE, IDC_MERGE_TREE);

	CFirstStartWizard* wiz = (CFirstStartWizard*)GetParent();
	/*switch (nButton)
	{
	case IDC_MERGE_REVRANGE:
		wiz->nRevRangeMerge = MERGEWIZARD_REVRANGE;
		break;
	case IDC_MERGE_TREE:
		wiz->nRevRangeMerge = MERGEWIZARD_TREE;
		break;
	}*/

	wiz->SaveMode();

	return wiz->GetSecondPage();
}

BOOL CFirstStartWizardStart::OnInitDialog()
{
	CFirstStartWizardBasePage::OnInitDialog();

/*	AdjustControlSize(IDC_MERGE_REVRANGE);
	AdjustControlSize(IDC_MERGE_TREE);

	AddAnchor(IDC_MERGETYPEGROUP, TOP_LEFT, BOTTOM_RIGHT);
	AddAnchor(IDC_MERGE_REVRANGE, TOP_LEFT);
	AddAnchor(IDC_MERGERANGELABEL, TOP_LEFT, TOP_RIGHT);
	AddAnchor(IDC_MERGE_TREE, TOP_LEFT);
	AddAnchor(IDC_TREELABEL, TOP_LEFT, TOP_RIGHT);*/

	return TRUE;
}

BOOL CFirstStartWizardStart::OnSetActive()
{
	CFirstStartWizard* wiz = (CFirstStartWizard*)GetParent();

	wiz->SetWizardButtons(PSWIZB_NEXT);
	SetButtonTexts();

	/*int nButton = IDC_MERGE_REVRANGE;
	switch (wiz->nRevRangeMerge)
	{
	case MERGEWIZARD_REVRANGE:
		nButton = IDC_MERGE_REVRANGE;
		break;
	case MERGEWIZARD_TREE:
		nButton = IDC_MERGE_TREE;
		break;
	}
	CheckRadioButton(
		IDC_MERGE_REVRANGE, IDC_MERGE_TREE,
		nButton);*/

	return CFirstStartWizardBasePage::OnSetActive();
}
