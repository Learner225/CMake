/* Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
   file Copyright.txt or https://cmake.org/licensing for details.  */
#ifndef cmFunctionCommand_h
#define cmFunctionCommand_h

#include "cmConfigure.h" // IWYU pragma: keep

#include <string>
#include <vector>

#include "cmCommand.h"
#include "cmFunctionBlocker.h"
#include "cmListFileCache.h"

class cmExecutionStatus;
class cmMakefile;

class cmFunctionFunctionBlocker : public cmFunctionBlocker
{
public:
  bool IsFunctionBlocked(const cmListFileFunction&, cmMakefile& mf,
                         cmExecutionStatus&) override;
  bool ShouldRemove(const cmListFileFunction&, cmMakefile& mf) override;

  std::vector<std::string> Args;
  std::vector<cmListFileFunction> Functions;
  int Depth = 0;
};

/// Starts function() ... endfunction() block
class cmFunctionCommand : public cmCommand
{
public:
  /**
   * This is a virtual constructor for the command.
   */
  cmCommand* Clone() override { return new cmFunctionCommand; }

  /**
   * This is called when the command is first encountered in
   * the CMakeLists.txt file.
   */
  bool InitialPass(std::vector<std::string> const& args,
                   cmExecutionStatus& status) override;
};

#endif
