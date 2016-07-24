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
#include "FirstStartWizardBasePage.h"
#include "resource.h"

IMPLEMENT_DYNAMIC(CFirstStartWizardBasePage, CResizablePageEx)

void CFirstStartWizardBasePage::SetButtonTexts()
{
	CPropertySheet* psheet = (CPropertySheet*) GetParent();
	if (psheet)
	{
		/*psheet->GetDlgItem(ID_WIZFINISH)->SetWindowText(CString(MAKEINTRESOURCE(IDS_MERGE_MERGE)));
		psheet->GetDlgItem(ID_WIZBACK)->SetWindowText(CString(MAKEINTRESOURCE(IDS_PROPPAGE_BACK)));
		psheet->GetDlgItem(ID_WIZNEXT)->SetWindowText(CString(MAKEINTRESOURCE(IDS_PROPPAGE_NEXT)));
		psheet->GetDlgItem(IDHELP)->SetWindowText(CString(MAKEINTRESOURCE(IDS_PROPPAGE_HELP)));
		CAppUtils::SetAccProperty(psheet->GetDlgItem(IDHELP)->GetSafeHwnd(), PROPID_ACC_KEYBOARDSHORTCUT, L"F1");
		psheet->GetDlgItem(IDCANCEL)->SetWindowText(CString(MAKEINTRESOURCE(IDS_PROPPAGE_CANCEL)));
		CAppUtils::SetAccProperty(psheet->GetDlgItem(IDCANCEL)->GetSafeHwnd(), PROPID_ACC_KEYBOARDSHORTCUT, L"ESC");*/
	}
}
