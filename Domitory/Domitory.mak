# Microsoft Developer Studio Generated NMAKE File, Based on Domitory.dsp
!IF "$(CFG)" == ""
CFG=Domitory - Win32 Debug
!MESSAGE No configuration specified. Defaulting to Domitory - Win32 Debug.
!ENDIF 

!IF "$(CFG)" != "Domitory - Win32 Release" && "$(CFG)" != "Domitory - Win32 Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
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
!ERROR An invalid configuration is specified.
!ENDIF 

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE 
NULL=nul
!ENDIF 

CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "Domitory - Win32 Release"

OUTDIR=.\Release
INTDIR=.\Release
# Begin Custom Macros
OutDir=.\Release
# End Custom Macros

ALL : "$(OUTDIR)\Domitory.exe"


CLEAN :
	-@erase "$(INTDIR)\AddDIRecordDlg.obj"
	-@erase "$(INTDIR)\AdministratorRS.obj"
	-@erase "$(INTDIR)\Domitory.obj"
	-@erase "$(INTDIR)\Domitory.pch"
	-@erase "$(INTDIR)\Domitory.res"
	-@erase "$(INTDIR)\DomitoryDlg.obj"
	-@erase "$(INTDIR)\DomitoryInfoDlg.obj"
	-@erase "$(INTDIR)\DomitoryRS.obj"
	-@erase "$(INTDIR)\LoginDlg.obj"
	-@erase "$(INTDIR)\ODScoreRS.obj"
	-@erase "$(INTDIR)\OnDutyDlg.obj"
	-@erase "$(INTDIR)\OnDutyPage1.obj"
	-@erase "$(INTDIR)\OnDutyPage2.obj"
	-@erase "$(INTDIR)\OnDutyPage3.obj"
	-@erase "$(INTDIR)\OnDutyRS.obj"
	-@erase "$(INTDIR)\PersonODRS.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\StudentRS.obj"
	-@erase "$(INTDIR)\StuInfoDlg.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(OUTDIR)\Domitory.exe"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\Domitory.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x804 /fo"$(INTDIR)\Domitory.res" /d "NDEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\Domitory.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /incremental:no /pdb:"$(OUTDIR)\Domitory.pdb" /machine:I386 /out:"$(OUTDIR)\Domitory.exe" 
LINK32_OBJS= \
	"$(INTDIR)\AddDIRecordDlg.obj" \
	"$(INTDIR)\AdministratorRS.obj" \
	"$(INTDIR)\Domitory.obj" \
	"$(INTDIR)\DomitoryDlg.obj" \
	"$(INTDIR)\DomitoryInfoDlg.obj" \
	"$(INTDIR)\DomitoryRS.obj" \
	"$(INTDIR)\LoginDlg.obj" \
	"$(INTDIR)\ODScoreRS.obj" \
	"$(INTDIR)\OnDutyDlg.obj" \
	"$(INTDIR)\OnDutyPage1.obj" \
	"$(INTDIR)\OnDutyPage2.obj" \
	"$(INTDIR)\OnDutyPage3.obj" \
	"$(INTDIR)\OnDutyRS.obj" \
	"$(INTDIR)\PersonODRS.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\StuInfoDlg.obj" \
	"$(INTDIR)\Domitory.res" \
	"$(INTDIR)\StudentRS.obj"

"$(OUTDIR)\Domitory.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "Domitory - Win32 Debug"

OUTDIR=.\Debug
INTDIR=.\Debug
# Begin Custom Macros
OutDir=.\Debug
# End Custom Macros

ALL : "$(OUTDIR)\Domitory.exe" "$(OUTDIR)\Domitory.bsc"


CLEAN :
	-@erase "$(INTDIR)\AddDIRecordDlg.obj"
	-@erase "$(INTDIR)\AddDIRecordDlg.sbr"
	-@erase "$(INTDIR)\AdministratorRS.obj"
	-@erase "$(INTDIR)\AdministratorRS.sbr"
	-@erase "$(INTDIR)\Domitory.obj"
	-@erase "$(INTDIR)\Domitory.pch"
	-@erase "$(INTDIR)\Domitory.res"
	-@erase "$(INTDIR)\Domitory.sbr"
	-@erase "$(INTDIR)\DomitoryDlg.obj"
	-@erase "$(INTDIR)\DomitoryDlg.sbr"
	-@erase "$(INTDIR)\DomitoryInfoDlg.obj"
	-@erase "$(INTDIR)\DomitoryInfoDlg.sbr"
	-@erase "$(INTDIR)\DomitoryRS.obj"
	-@erase "$(INTDIR)\DomitoryRS.sbr"
	-@erase "$(INTDIR)\LoginDlg.obj"
	-@erase "$(INTDIR)\LoginDlg.sbr"
	-@erase "$(INTDIR)\ODScoreRS.obj"
	-@erase "$(INTDIR)\ODScoreRS.sbr"
	-@erase "$(INTDIR)\OnDutyDlg.obj"
	-@erase "$(INTDIR)\OnDutyDlg.sbr"
	-@erase "$(INTDIR)\OnDutyPage1.obj"
	-@erase "$(INTDIR)\OnDutyPage1.sbr"
	-@erase "$(INTDIR)\OnDutyPage2.obj"
	-@erase "$(INTDIR)\OnDutyPage2.sbr"
	-@erase "$(INTDIR)\OnDutyPage3.obj"
	-@erase "$(INTDIR)\OnDutyPage3.sbr"
	-@erase "$(INTDIR)\OnDutyRS.obj"
	-@erase "$(INTDIR)\OnDutyRS.sbr"
	-@erase "$(INTDIR)\PersonODRS.obj"
	-@erase "$(INTDIR)\PersonODRS.sbr"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\StdAfx.sbr"
	-@erase "$(INTDIR)\StudentRS.obj"
	-@erase "$(INTDIR)\StudentRS.sbr"
	-@erase "$(INTDIR)\StuInfoDlg.obj"
	-@erase "$(INTDIR)\StuInfoDlg.sbr"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(OUTDIR)\Domitory.bsc"
	-@erase "$(OUTDIR)\Domitory.exe"
	-@erase "$(OUTDIR)\Domitory.ilk"
	-@erase "$(OUTDIR)\Domitory.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /FR"$(INTDIR)\\" /Fp"$(INTDIR)\Domitory.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /GZ /c 
MTL_PROJ=/nologo /D "_DEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x804 /fo"$(INTDIR)\Domitory.res" /d "_DEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\Domitory.bsc" 
BSC32_SBRS= \
	"$(INTDIR)\AddDIRecordDlg.sbr" \
	"$(INTDIR)\AdministratorRS.sbr" \
	"$(INTDIR)\Domitory.sbr" \
	"$(INTDIR)\DomitoryDlg.sbr" \
	"$(INTDIR)\DomitoryInfoDlg.sbr" \
	"$(INTDIR)\DomitoryRS.sbr" \
	"$(INTDIR)\LoginDlg.sbr" \
	"$(INTDIR)\ODScoreRS.sbr" \
	"$(INTDIR)\OnDutyDlg.sbr" \
	"$(INTDIR)\OnDutyPage1.sbr" \
	"$(INTDIR)\OnDutyPage2.sbr" \
	"$(INTDIR)\OnDutyPage3.sbr" \
	"$(INTDIR)\OnDutyRS.sbr" \
	"$(INTDIR)\PersonODRS.sbr" \
	"$(INTDIR)\StdAfx.sbr" \
	"$(INTDIR)\StuInfoDlg.sbr" \
	"$(INTDIR)\StudentRS.sbr"

"$(OUTDIR)\Domitory.bsc" : "$(OUTDIR)" $(BSC32_SBRS)
    $(BSC32) @<<
  $(BSC32_FLAGS) $(BSC32_SBRS)
<<

LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /incremental:yes /pdb:"$(OUTDIR)\Domitory.pdb" /debug /machine:I386 /out:"$(OUTDIR)\Domitory.exe" /pdbtype:sept 
LINK32_OBJS= \
	"$(INTDIR)\AddDIRecordDlg.obj" \
	"$(INTDIR)\AdministratorRS.obj" \
	"$(INTDIR)\Domitory.obj" \
	"$(INTDIR)\DomitoryDlg.obj" \
	"$(INTDIR)\DomitoryInfoDlg.obj" \
	"$(INTDIR)\DomitoryRS.obj" \
	"$(INTDIR)\LoginDlg.obj" \
	"$(INTDIR)\ODScoreRS.obj" \
	"$(INTDIR)\OnDutyDlg.obj" \
	"$(INTDIR)\OnDutyPage1.obj" \
	"$(INTDIR)\OnDutyPage2.obj" \
	"$(INTDIR)\OnDutyPage3.obj" \
	"$(INTDIR)\OnDutyRS.obj" \
	"$(INTDIR)\PersonODRS.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\StuInfoDlg.obj" \
	"$(INTDIR)\Domitory.res" \
	"$(INTDIR)\StudentRS.obj"

"$(OUTDIR)\Domitory.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ENDIF 

.c{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.c{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<


!IF "$(NO_EXTERNAL_DEPS)" != "1"
!IF EXISTS("Domitory.dep")
!INCLUDE "Domitory.dep"
!ELSE 
!MESSAGE Warning: cannot find "Domitory.dep"
!ENDIF 
!ENDIF 


!IF "$(CFG)" == "Domitory - Win32 Release" || "$(CFG)" == "Domitory - Win32 Debug"
SOURCE=.\AddDIRecordDlg.cpp

!IF  "$(CFG)" == "Domitory - Win32 Release"


"$(INTDIR)\AddDIRecordDlg.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\Domitory.pch"


!ELSEIF  "$(CFG)" == "Domitory - Win32 Debug"


"$(INTDIR)\AddDIRecordDlg.obj"	"$(INTDIR)\AddDIRecordDlg.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\Domitory.pch"


!ENDIF 

SOURCE=.\AdministratorRS.cpp

!IF  "$(CFG)" == "Domitory - Win32 Release"


"$(INTDIR)\AdministratorRS.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\Domitory.pch"


!ELSEIF  "$(CFG)" == "Domitory - Win32 Debug"


"$(INTDIR)\AdministratorRS.obj"	"$(INTDIR)\AdministratorRS.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\Domitory.pch"


!ENDIF 

SOURCE=.\Domitory.cpp

!IF  "$(CFG)" == "Domitory - Win32 Release"


"$(INTDIR)\Domitory.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\Domitory.pch"


!ELSEIF  "$(CFG)" == "Domitory - Win32 Debug"


"$(INTDIR)\Domitory.obj"	"$(INTDIR)\Domitory.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\Domitory.pch"


!ENDIF 

SOURCE=.\Domitory.rc

"$(INTDIR)\Domitory.res" : $(SOURCE) "$(INTDIR)"
	$(RSC) $(RSC_PROJ) $(SOURCE)


SOURCE=.\DomitoryDlg.cpp

!IF  "$(CFG)" == "Domitory - Win32 Release"


"$(INTDIR)\DomitoryDlg.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\Domitory.pch"


!ELSEIF  "$(CFG)" == "Domitory - Win32 Debug"


"$(INTDIR)\DomitoryDlg.obj"	"$(INTDIR)\DomitoryDlg.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\Domitory.pch"


!ENDIF 

SOURCE=.\DomitoryInfoDlg.cpp

!IF  "$(CFG)" == "Domitory - Win32 Release"


"$(INTDIR)\DomitoryInfoDlg.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\Domitory.pch"


!ELSEIF  "$(CFG)" == "Domitory - Win32 Debug"


"$(INTDIR)\DomitoryInfoDlg.obj"	"$(INTDIR)\DomitoryInfoDlg.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\Domitory.pch"


!ENDIF 

SOURCE=.\DomitoryRS.cpp

!IF  "$(CFG)" == "Domitory - Win32 Release"


"$(INTDIR)\DomitoryRS.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\Domitory.pch"


!ELSEIF  "$(CFG)" == "Domitory - Win32 Debug"


"$(INTDIR)\DomitoryRS.obj"	"$(INTDIR)\DomitoryRS.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\Domitory.pch"


!ENDIF 

SOURCE=.\LoginDlg.cpp

!IF  "$(CFG)" == "Domitory - Win32 Release"


"$(INTDIR)\LoginDlg.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\Domitory.pch"


!ELSEIF  "$(CFG)" == "Domitory - Win32 Debug"


"$(INTDIR)\LoginDlg.obj"	"$(INTDIR)\LoginDlg.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\Domitory.pch"


!ENDIF 

SOURCE=.\ODScoreRS.cpp

!IF  "$(CFG)" == "Domitory - Win32 Release"


"$(INTDIR)\ODScoreRS.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\Domitory.pch"


!ELSEIF  "$(CFG)" == "Domitory - Win32 Debug"


"$(INTDIR)\ODScoreRS.obj"	"$(INTDIR)\ODScoreRS.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\Domitory.pch"


!ENDIF 

SOURCE=.\OnDutyDlg.cpp

!IF  "$(CFG)" == "Domitory - Win32 Release"


"$(INTDIR)\OnDutyDlg.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\Domitory.pch"


!ELSEIF  "$(CFG)" == "Domitory - Win32 Debug"


"$(INTDIR)\OnDutyDlg.obj"	"$(INTDIR)\OnDutyDlg.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\Domitory.pch"


!ENDIF 

SOURCE=.\OnDutyPage1.cpp

!IF  "$(CFG)" == "Domitory - Win32 Release"


"$(INTDIR)\OnDutyPage1.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\Domitory.pch"


!ELSEIF  "$(CFG)" == "Domitory - Win32 Debug"


"$(INTDIR)\OnDutyPage1.obj"	"$(INTDIR)\OnDutyPage1.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\Domitory.pch"


!ENDIF 

SOURCE=.\OnDutyPage2.cpp

!IF  "$(CFG)" == "Domitory - Win32 Release"


"$(INTDIR)\OnDutyPage2.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\Domitory.pch"


!ELSEIF  "$(CFG)" == "Domitory - Win32 Debug"


"$(INTDIR)\OnDutyPage2.obj"	"$(INTDIR)\OnDutyPage2.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\Domitory.pch"


!ENDIF 

SOURCE=.\OnDutyPage3.cpp

!IF  "$(CFG)" == "Domitory - Win32 Release"


"$(INTDIR)\OnDutyPage3.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\Domitory.pch"


!ELSEIF  "$(CFG)" == "Domitory - Win32 Debug"


"$(INTDIR)\OnDutyPage3.obj"	"$(INTDIR)\OnDutyPage3.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\Domitory.pch"


!ENDIF 

SOURCE=.\OnDutyRS.cpp

!IF  "$(CFG)" == "Domitory - Win32 Release"


"$(INTDIR)\OnDutyRS.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\Domitory.pch"


!ELSEIF  "$(CFG)" == "Domitory - Win32 Debug"


"$(INTDIR)\OnDutyRS.obj"	"$(INTDIR)\OnDutyRS.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\Domitory.pch"


!ENDIF 

SOURCE=.\PersonODRS.cpp

!IF  "$(CFG)" == "Domitory - Win32 Release"


"$(INTDIR)\PersonODRS.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\Domitory.pch"


!ELSEIF  "$(CFG)" == "Domitory - Win32 Debug"


"$(INTDIR)\PersonODRS.obj"	"$(INTDIR)\PersonODRS.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\Domitory.pch"


!ENDIF 

SOURCE=.\StdAfx.cpp

!IF  "$(CFG)" == "Domitory - Win32 Release"

CPP_SWITCHES=/nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\Domitory.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\Domitory.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "Domitory - Win32 Debug"

CPP_SWITCHES=/nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /FR"$(INTDIR)\\" /Fp"$(INTDIR)\Domitory.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /GZ /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\StdAfx.sbr"	"$(INTDIR)\Domitory.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ENDIF 

SOURCE=.\StudentRS.cpp

!IF  "$(CFG)" == "Domitory - Win32 Release"


"$(INTDIR)\StudentRS.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\Domitory.pch"


!ELSEIF  "$(CFG)" == "Domitory - Win32 Debug"


"$(INTDIR)\StudentRS.obj"	"$(INTDIR)\StudentRS.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\Domitory.pch"


!ENDIF 

SOURCE=.\StuInfoDlg.cpp

!IF  "$(CFG)" == "Domitory - Win32 Release"


"$(INTDIR)\StuInfoDlg.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\Domitory.pch"


!ELSEIF  "$(CFG)" == "Domitory - Win32 Debug"


"$(INTDIR)\StuInfoDlg.obj"	"$(INTDIR)\StuInfoDlg.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\Domitory.pch"


!ENDIF 


!ENDIF 

