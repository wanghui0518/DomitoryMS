# Microsoft Developer Studio Project File - Name="Domitory" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

CFG=Domitory - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "Domitory.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "Domitory.mak" CFG="Domitory - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "Domitory - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "Domitory - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "Domitory - Win32 Release"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 5
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /Yu"stdafx.h" /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x804 /d "NDEBUG" /d "_AFXDLL"
# ADD RSC /l 0x804 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /machine:I386
# ADD LINK32 /nologo /subsystem:windows /machine:I386

!ELSEIF  "$(CFG)" == "Domitory - Win32 Debug"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /Yu"stdafx.h" /FD /GZ /c
# ADD CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /FR /Yu"stdafx.h" /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x804 /d "_DEBUG" /d "_AFXDLL"
# ADD RSC /l 0x804 /d "_DEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept
# ADD LINK32 /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept

!ENDIF 

# Begin Target

# Name "Domitory - Win32 Release"
# Name "Domitory - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\AddDIRecordDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\AddForeRecordDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\AddOnDutyRDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\AddPRecordDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\AddStuReDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\AdministratorRS.cpp
# End Source File
# Begin Source File

SOURCE=.\Domitory.cpp
# End Source File
# Begin Source File

SOURCE=.\Domitory.rc
# End Source File
# Begin Source File

SOURCE=.\DomitoryDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\DomitoryInfoDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\DomitoryRS.cpp
# End Source File
# Begin Source File

SOURCE=.\ForeignRegDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\ForeignRegRS.cpp
# End Source File
# Begin Source File

SOURCE=.\FRegisterRS.cpp
# End Source File
# Begin Source File

SOURCE=.\LoginDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\ODScoreRS.cpp
# End Source File
# Begin Source File

SOURCE=.\OnDutyDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\OnDutyPage1.cpp
# End Source File
# Begin Source File

SOURCE=.\OnDutyPage2.cpp
# End Source File
# Begin Source File

SOURCE=.\OnDutyPage3.cpp
# End Source File
# Begin Source File

SOURCE=.\OnDutyRS.cpp
# End Source File
# Begin Source File

SOURCE=.\PersonODRS.cpp
# End Source File
# Begin Source File

SOURCE=.\StdAfx.cpp
# ADD CPP /Yc"stdafx.h"
# End Source File
# Begin Source File

SOURCE=.\StudentRS.cpp
# End Source File
# Begin Source File

SOURCE=.\StuInfoDlg.cpp
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\AddDIRecordDlg.h
# End Source File
# Begin Source File

SOURCE=.\AddForeRecordDlg.h
# End Source File
# Begin Source File

SOURCE=.\AddOnDutyRDlg.h
# End Source File
# Begin Source File

SOURCE=.\AddPRecordDlg.h
# End Source File
# Begin Source File

SOURCE=.\AddStuReDlg.h
# End Source File
# Begin Source File

SOURCE=.\AdministratorRS.h
# End Source File
# Begin Source File

SOURCE=.\Domitory.h
# End Source File
# Begin Source File

SOURCE=.\DomitoryDlg.h
# End Source File
# Begin Source File

SOURCE=.\DomitoryInfoDlg.h
# End Source File
# Begin Source File

SOURCE=.\DomitoryRS.h
# End Source File
# Begin Source File

SOURCE=.\ForeignRegDlg.h
# End Source File
# Begin Source File

SOURCE=.\ForeignRegRS.h
# End Source File
# Begin Source File

SOURCE=.\FRegisterRS.h
# End Source File
# Begin Source File

SOURCE=.\LoginDlg.h
# End Source File
# Begin Source File

SOURCE=.\ODScoreRS.h
# End Source File
# Begin Source File

SOURCE=.\OnDutyDlg.h
# End Source File
# Begin Source File

SOURCE=.\OnDutyPage1.h
# End Source File
# Begin Source File

SOURCE=.\OnDutyPage2.h
# End Source File
# Begin Source File

SOURCE=.\OnDutyPage3.h
# End Source File
# Begin Source File

SOURCE=.\OnDutyRS.h
# End Source File
# Begin Source File

SOURCE=.\PersonODRS.h
# End Source File
# Begin Source File

SOURCE=.\Resource.h
# End Source File
# Begin Source File

SOURCE=.\StdAfx.h
# End Source File
# Begin Source File

SOURCE=.\StudentRS.h
# End Source File
# Begin Source File

SOURCE=.\StuInfoDlg.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# Begin Source File

SOURCE=.\res\Domitory.ico
# End Source File
# Begin Source File

SOURCE=.\res\Domitory.rc2
# End Source File
# Begin Source File

SOURCE=".\res\hp_folder_boy(2).bmp"
# End Source File
# Begin Source File

SOURCE=.\res\hp_folder_boy.ico
# End Source File
# Begin Source File

SOURCE=.\res\hp_folder_boy3.bmp
# End Source File
# End Group
# Begin Source File

SOURCE=.\ReadMe.txt
# End Source File
# End Target
# End Project
