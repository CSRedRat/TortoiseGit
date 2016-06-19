﻿// TortoiseGit - a Windows shell extension for easy version control

// Copyright (C) 2015-2016 - TortoiseGit
// Copyright (C) 2003-2011 - TortoiseSVN

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
#include "StringUtils.h"

TEST(CStringUtils, WordWrap)
{
	CString longline = _T("this is a test of how a string can be splitted into several lines");
	CString splittedline = CStringUtils::WordWrap(longline, 10, true, false, 4);
	EXPECT_STREQ(_T("this is a\n test of\n how a\n string\n can be\n splitted\n into\n several\n lines"), splittedline);
	longline = _T("c:\\this_is_a_very_long\\path_on_windows and of course some other words added to make the line longer");
	splittedline = CStringUtils::WordWrap(longline, 10, true, false, 4);
	EXPECT_STREQ(_T("...\\pat...\n and of\n course\n some\n other\n words\n added to\n make the\n line\n longer"), splittedline);
	longline = _T("Forced failure in https://myserver.com/a_long_url_to_split PROPFIND error");
	splittedline = CStringUtils::WordWrap(longline, 20, true, false, 4);
	EXPECT_STREQ(_T("Forced failure in\n https://myserver.com/a_long_url_to_split\n PROPFIND error"), splittedline);
	longline = _T("Forced\nfailure in https://myserver.com/a_long_url_to_split PROPFIND\nerror");
	splittedline = CStringUtils::WordWrap(longline, 40, true, false, 4);
	EXPECT_STREQ(_T("Forced\nfailure in\n https://myserver.com/a_long_url_to_split\n PROPFIND\nerror"), splittedline);
	longline = _T("Failed to add file\nc:\\export\\spare\\Devl-JBoss\\development\\head\\src\\something\\CoreApplication\\somethingelse\\src\\com\\yetsomthingelse\\shipper\\DAO\\ShipmentInfoDAO1.java\nc:\\export\\spare\\Devl-JBoss\\development\\head\\src\\something\\CoreApplication\\somethingelse\\src\\com\\yetsomthingelse\\shipper\\DAO\\ShipmentInfoDAO2.java");
	splittedline = CStringUtils::WordWrap(longline, 80, true, false, 4);
	EXPECT_STREQ(_T("Failed to add\n file\nc:\\export\\spare\\Devl-JBoss\\development\\head\\src\\something\\CoreApplication\\somethingelse\\src\\com\\yetsomthingelse\\shipper\\DAO\\ShipmentInfoDAO1.java\nc:\\export\\spare\\Devl-JBoss\\development\\head\\src\\something\\CoreApplication\\somethingelse\\src\\com\\yetsomthing\n"), splittedline);
}

TEST(CStringUtils, LinesWrap)
{
	CString longline = _T("this is a test of how a string can be splitted into several lines");
	CString splittedline = CStringUtils::LinesWrap(longline, 10, true);
	EXPECT_STREQ(_T("this is a\n test of\n how a\n string\n can be\n splitted\n into\n several\n lines"), splittedline);
	longline = _T("c:\\this_is_a_very_long\\path_on_windows and of course some other words added to make the line longer");
	splittedline = CStringUtils::LinesWrap(longline, 10);
	EXPECT_STREQ(_T("c:\\this_is_a_very_long\\path_on_windows\n and of\n course\n some\n other\n words\n added to\n make the\n line\n longer"), splittedline);
	longline = _T("Forced failure in https://myserver.com/a_long_url_to_split PROPFIND error");
	splittedline = CStringUtils::LinesWrap(longline, 20, true);
	EXPECT_STREQ(_T("Forced failure in\n https://myserver.com/a_long_url_to_split\n PROPFIND error"), splittedline);
	longline = _T("Forced\nfailure in https://myserver.com/a_long_url_to_split PROPFIND\nerror");
	splittedline = CStringUtils::LinesWrap(longline, 40);
	EXPECT_STREQ(_T("Forced\nfailure in\n https://myserver.com/a_long_url_to_split\n PROPFIND\nerror"), splittedline);
	longline = _T("Failed to add file\nc:\\export\\spare\\Devl-JBoss\\development\\head\\src\\something\\CoreApplication\\somethingelse\\src\\com\\yetsomthingelse\\shipper\\DAO\\ShipmentInfoDAO1.java\nc:\\export\\spare\\Devl-JBoss\\development\\head\\src\\something\\CoreApplication\\somethingelse\\src\\com\\yetsomthingelse\\shipper\\DAO\\ShipmentInfoDAO2.java");
	splittedline = CStringUtils::LinesWrap(longline);
	EXPECT_STREQ(_T("Failed to add file\nc:\\export\\spare\\Devl-JBoss\\development\\head\\src\\something\\CoreApplication\\somethingelse\\src\\com\\yetsomthingelse\\shipper\\DAO\\ShipmentInfoDAO1.java\n\nc:\\export\\spare\\Devl-JBoss\\development\\head\\src\\something\\CoreApplication\\somethingelse\\src\\com\\yetsomthingelse\\shipper\\DAO\\ShipmentInfoDAO2.java"), splittedline);
	longline = _T("The commit comment is not properly formatted.\nFormat:\n  Field 1 : Field 2 : Field 3\nWhere:\nField 1 - Team Name|Triage|Merge|Goal\nField 2 - V1 Backlog Item ID|Triage Number|SVNBranch|Goal Name\nField 3 - Description of change\nExamples:\n\nTeam Gamma : B-12345 : Changed some code\n  Triage : 123 : Fixed production release bug\n  Merge : sprint0812 : Merged sprint0812 into prod\n  Goal : Implement Pre-Commit Hook : Commit message hook impl");
	splittedline = CStringUtils::LinesWrap(longline, 80);
	EXPECT_STREQ(_T("The commit comment is not properly formatted.\nFormat:\n  Field 1 : Field 2 : Field 3\nWhere:\nField 1 - Team Name|Triage|Merge|Goal\nField 2 - V1 Backlog Item ID|Triage Number|SVNBranch|Goal Name\nField 3 - Description of change\nExamples:\n\nTeam Gamma : B-12345 : Changed some code\n  Triage : 123 : Fixed production release bug\n  Merge : sprint0812 : Merged sprint0812 into prod\n  Goal : Implement Pre-Commit Hook : Commit message hook impl"), splittedline);
}

TEST(CStringUtils, RemoveAccelerators)
{
	CString empty;
	CStringUtils::RemoveAccelerators(empty);
	EXPECT_TRUE(empty.IsEmpty());

	CString text1 = L"&Accellerator";
	CStringUtils::RemoveAccelerators(text1);
	EXPECT_STREQ(L"Accellerator", text1);

	CString text1a = L"Ac&cellerator";
	CStringUtils::RemoveAccelerators(text1a);
	EXPECT_STREQ(L"Accellerator", text1a);

	CString text2 = L"Accellerator&";
	CStringUtils::RemoveAccelerators(text2);
	EXPECT_STREQ(L"Accellerator", text2);

	CString text3 = L"Some & text";
	CStringUtils::RemoveAccelerators(text3);
	EXPECT_STREQ(L"Some & text", text3);

	CString text4 = L"&&Accellerator";
	CStringUtils::RemoveAccelerators(text4);
	EXPECT_STREQ(L"&Accellerator", text4);

	CString text5 = L"Acce&&&llerator";
	CStringUtils::RemoveAccelerators(text5);
	EXPECT_STREQ(L"Acce&llerator", text5);

	CString text6 = L"Some & te&xt";
	CStringUtils::RemoveAccelerators(text6);
	EXPECT_STREQ(L"Some & text", text6);
}

TEST(CStringUtils, ParseEmailAddress)
{
	CString mail, name;
	CStringUtils::ParseEmailAddress(_T(""), mail, &name);
	EXPECT_STREQ(_T(""), mail);
	EXPECT_STREQ(_T(""), name);

	CStringUtils::ParseEmailAddress(_T(" "), mail, &name);
	EXPECT_STREQ(_T(""), mail);
	EXPECT_STREQ(_T(""), name);

	mail.Empty();
	CStringUtils::ParseEmailAddress(_T("test@example.com "), mail);
	EXPECT_STREQ(_T("test@example.com"), mail);

	mail.Empty();
	CStringUtils::ParseEmailAddress(_T(" test@example.com"), mail);
	EXPECT_STREQ(_T("test@example.com"), mail);

	mail.Empty();
	CStringUtils::ParseEmailAddress(_T("test@example.com"), mail);
	EXPECT_STREQ(_T("test@example.com"), mail);

	mail.Empty();
	CStringUtils::ParseEmailAddress(_T("John Doe <johndoe>"), mail);
	EXPECT_STREQ(_T("johndoe"), mail);

	mail.Empty();
	name.Empty();
	CStringUtils::ParseEmailAddress(_T("test@example.com"), mail, &name);
	EXPECT_STREQ(_T("test@example.com"), mail);
	EXPECT_STREQ(_T("test@example.com"), name);

	mail.Empty();
	name.Empty();
	CStringUtils::ParseEmailAddress(_T("<test@example.com>"), mail, &name);
	EXPECT_STREQ(_T("test@example.com"), mail);
	EXPECT_STREQ(_T("test@example.com"), name);

	mail.Empty();
	name.Empty();
	CStringUtils::ParseEmailAddress(_T("John Doe <test@example.com>"), mail, &name);
	EXPECT_STREQ(_T("test@example.com"), mail);
	EXPECT_STREQ(_T("John Doe"), name);

	mail.Empty();
	name.Empty();
	CStringUtils::ParseEmailAddress(_T("\"John Doe\" <test@example.com>"), mail, &name);
	EXPECT_STREQ(_T("test@example.com"), mail);
	EXPECT_STREQ(_T("John Doe"), name);

	mail.Empty();
	name.Empty();
	CStringUtils::ParseEmailAddress(_T("<test@example.com"), mail, &name);
	EXPECT_STREQ(_T("test@example.com"), mail);
	EXPECT_STREQ(_T("test@example.com"), name);

	mail.Empty();
	name.Empty();
	CStringUtils::ParseEmailAddress(_T("test@example.com>"), mail, &name);
	EXPECT_STREQ(_T("test@example.com"), mail);
	EXPECT_STREQ(_T("test@example.com"), name);

	mail.Empty();
	name.Empty();
	CStringUtils::ParseEmailAddress(_T("John Doe <johndoe>"), mail, &name);
	EXPECT_STREQ(_T("johndoe"), mail);
	EXPECT_STREQ(_T("John Doe"), name);

	mail.Empty();
	name.Empty();
	CStringUtils::ParseEmailAddress(_T("john.doe@example.com (John Doe)"), mail, &name);
	EXPECT_STREQ(_T("john.doe@example.com"), mail);
	EXPECT_STREQ(_T("John Doe"), name);

	mail.Empty();
	name.Empty();
	CStringUtils::ParseEmailAddress(_T("John (zzz) Doe <john.doe@example.com> (Comment)"), mail, &name);
	EXPECT_STREQ(_T("john.doe@example.com"), mail);
	EXPECT_STREQ(_T("John (zzz) Doe (Comment)"), name);

	mail.Empty();
	name.Empty();
	CStringUtils::ParseEmailAddress(L"\"john.doe@example.com >> John Doe\" <john.doe@example.com>", mail, &name);
	EXPECT_STREQ(_T("john.doe@example.com"), mail);
	EXPECT_STREQ(_T("john.doe@example.com >> John Doe"), name);

	mail.Empty();
	name.Empty();
	CStringUtils::ParseEmailAddress(L"\"John<something> Doe\" <john.doe@example.com>", mail, &name);
	EXPECT_STREQ(_T("john.doe@example.com"), mail);
	EXPECT_STREQ(_T("John<something> Doe"), name);

	mail.Empty();
	name.Empty();
	CStringUtils::ParseEmailAddress(L"\"John<something@example.com> Doe\" <john.doe@example.com>", mail, &name);
	EXPECT_STREQ(_T("john.doe@example.com"), mail);
	EXPECT_STREQ(_T("John<something@example.com> Doe"), name);

	mail.Empty();
	name.Empty();
	CStringUtils::ParseEmailAddress(L"\"something@example.com\" <john.doe@example.com>", mail, &name);
	EXPECT_STREQ(_T("john.doe@example.com"), mail);
	EXPECT_STREQ(_T("something@example.com"), name);

	mail.Empty();
	name.Empty();
	CStringUtils::ParseEmailAddress(L"\"John D\\\"o\\\"e\" <john.doe@example.com>", mail, &name);
	EXPECT_STREQ(_T("john.doe@example.com"), mail);
	EXPECT_STREQ(_T("John D\"o\"e"), name);

	mail.Empty();
	name.Empty();
	CStringUtils::ParseEmailAddress(_T("<test@example.com> \"John Doe\""), mail, &name);
	EXPECT_STREQ(_T("test@example.com"), mail);
	EXPECT_STREQ(_T("John Doe"), name);
}

TEST(CStringUtils, IsPlainReadableASCII)
{
	EXPECT_TRUE(CStringUtils::IsPlainReadableASCII(L""));
	EXPECT_TRUE(CStringUtils::IsPlainReadableASCII(L" 1234,#+*.:-&!\\<>|\"$%&/()=567890abcdefSBDUDB[](!}~"));
	EXPECT_FALSE(CStringUtils::IsPlainReadableASCII(L"\n"));
	EXPECT_FALSE(CStringUtils::IsPlainReadableASCII(L"\u2302"));
	EXPECT_FALSE(CStringUtils::IsPlainReadableASCII(L"é"));
	EXPECT_FALSE(CStringUtils::IsPlainReadableASCII(L"\u2550"));
	EXPECT_FALSE(CStringUtils::IsPlainReadableASCII(L"ä"));
	EXPECT_FALSE(CStringUtils::IsPlainReadableASCII(L"€"));
	EXPECT_FALSE(CStringUtils::IsPlainReadableASCII(L"\u570B"));
	EXPECT_FALSE(CStringUtils::IsPlainReadableASCII(L"\u7ACB"));
}

TEST(CStringUtils, EnDecrypt)
{
	CString widecrypt = CStringUtils::Encrypt(L"test");
	auto wide = CStringUtils::Decrypt(widecrypt);
	EXPECT_TRUE(wcscmp(wide.get(), L"test") == 0);
	CStringA charcrypt = CStringUtils::Encrypt("test");
	auto charnorm = CStringUtils::Decrypt(charcrypt);
	EXPECT_TRUE(strcmp(charnorm.get(), "test") == 0);

	std::string encrypted = CStringUtils::Encrypt("test", "test");
	std::string decrypted = CStringUtils::Decrypt(encrypted, "test");
	EXPECT_TRUE(decrypted.compare("test") == 0);
}
