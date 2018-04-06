##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=lost-dungeon
ConfigurationName      :=Debug
WorkspacePath          :=/home/mustamfst/projects/cpp/lost-dungeon
ProjectPath            :=/home/mustamfst/projects/cpp/lost-dungeon
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Paweł Mstowski
Date                   :=06/04/18
CodeLitePath           :=/home/mustamfst/.codelite
LinkerName             :=/usr/bin/g++
SharedObjectLinkerName :=/usr/bin/g++ -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.i
DebugSwitch            :=-g 
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputFile             :=$(IntermediateDirectory)/$(ProjectName)
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :="lost-dungeon.txt"
PCHCompileFlags        :=
MakeDirCommand         :=mkdir -p
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := $(LibrarySwitch)sfml-system $(LibrarySwitch)sfml-graphics $(LibrarySwitch)sfml-window 
ArLibs                 :=  "sfml-system" "sfml-graphics" "sfml-window" 
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := /usr/bin/ar rcu
CXX      := /usr/bin/g++
CC       := /usr/bin/gcc
CXXFLAGS :=  -g -O0 -std=c++14 -std=c++11 -Wall $(Preprocessors)
CFLAGS   :=  -g -O0 -std=c++14 -std=c++11 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := /usr/bin/as


##
## User defined environment variables
##
CodeLiteDir:=/usr/share/codelite
Objects0=$(IntermediateDirectory)/src_SplashState.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_main.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_Game.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_StateMachine.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_InputManager.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_GameState.cpp$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

PostBuild:
	@echo Executing Post Build commands ...
	cp -R assets -t ./Debug
	@echo Done

MakeIntermediateDirs:
	@test -d ./Debug || $(MakeDirCommand) ./Debug


$(IntermediateDirectory)/.d:
	@test -d ./Debug || $(MakeDirCommand) ./Debug

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/src_SplashState.cpp$(ObjectSuffix): src/SplashState.cpp $(IntermediateDirectory)/src_SplashState.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/mustamfst/projects/cpp/lost-dungeon/src/SplashState.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_SplashState.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_SplashState.cpp$(DependSuffix): src/SplashState.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_SplashState.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_SplashState.cpp$(DependSuffix) -MM src/SplashState.cpp

$(IntermediateDirectory)/src_SplashState.cpp$(PreprocessSuffix): src/SplashState.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_SplashState.cpp$(PreprocessSuffix) src/SplashState.cpp

$(IntermediateDirectory)/src_main.cpp$(ObjectSuffix): src/main.cpp $(IntermediateDirectory)/src_main.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/mustamfst/projects/cpp/lost-dungeon/src/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_main.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_main.cpp$(DependSuffix): src/main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_main.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_main.cpp$(DependSuffix) -MM src/main.cpp

$(IntermediateDirectory)/src_main.cpp$(PreprocessSuffix): src/main.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_main.cpp$(PreprocessSuffix) src/main.cpp

$(IntermediateDirectory)/src_Game.cpp$(ObjectSuffix): src/Game.cpp $(IntermediateDirectory)/src_Game.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/mustamfst/projects/cpp/lost-dungeon/src/Game.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_Game.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_Game.cpp$(DependSuffix): src/Game.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_Game.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_Game.cpp$(DependSuffix) -MM src/Game.cpp

$(IntermediateDirectory)/src_Game.cpp$(PreprocessSuffix): src/Game.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_Game.cpp$(PreprocessSuffix) src/Game.cpp

$(IntermediateDirectory)/src_StateMachine.cpp$(ObjectSuffix): src/StateMachine.cpp $(IntermediateDirectory)/src_StateMachine.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/mustamfst/projects/cpp/lost-dungeon/src/StateMachine.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_StateMachine.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_StateMachine.cpp$(DependSuffix): src/StateMachine.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_StateMachine.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_StateMachine.cpp$(DependSuffix) -MM src/StateMachine.cpp

$(IntermediateDirectory)/src_StateMachine.cpp$(PreprocessSuffix): src/StateMachine.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_StateMachine.cpp$(PreprocessSuffix) src/StateMachine.cpp

$(IntermediateDirectory)/src_InputManager.cpp$(ObjectSuffix): src/InputManager.cpp $(IntermediateDirectory)/src_InputManager.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/mustamfst/projects/cpp/lost-dungeon/src/InputManager.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_InputManager.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_InputManager.cpp$(DependSuffix): src/InputManager.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_InputManager.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_InputManager.cpp$(DependSuffix) -MM src/InputManager.cpp

$(IntermediateDirectory)/src_InputManager.cpp$(PreprocessSuffix): src/InputManager.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_InputManager.cpp$(PreprocessSuffix) src/InputManager.cpp

$(IntermediateDirectory)/src_GameState.cpp$(ObjectSuffix): src/GameState.cpp $(IntermediateDirectory)/src_GameState.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/mustamfst/projects/cpp/lost-dungeon/src/GameState.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_GameState.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_GameState.cpp$(DependSuffix): src/GameState.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_GameState.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_GameState.cpp$(DependSuffix) -MM src/GameState.cpp

$(IntermediateDirectory)/src_GameState.cpp$(PreprocessSuffix): src/GameState.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_GameState.cpp$(PreprocessSuffix) src/GameState.cpp


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Debug/


