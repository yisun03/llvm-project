//===--- DWARFEmitter.h - ---------------------------------------*- C++ -*-===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
/// \file
/// Common declarations for yaml2obj
//===----------------------------------------------------------------------===//

#ifndef LLVM_OBJECTYAML_DWARFEMITTER_H
#define LLVM_OBJECTYAML_DWARFEMITTER_H

#include "llvm/ADT/StringMap.h"
#include "llvm/ADT/StringRef.h"
#include "llvm/Support/Error.h"
#include "llvm/Support/Host.h"
#include "llvm/Support/MemoryBuffer.h"
#include <memory>

namespace llvm {

class raw_ostream;

namespace DWARFYAML {

struct Data;
struct PubSection;

void emitDebugAbbrev(raw_ostream &OS, const Data &DI);
void emitDebugStr(raw_ostream &OS, const Data &DI);

void emitDebugAranges(raw_ostream &OS, const Data &DI);
void emitDebugRanges(raw_ostream &OS, const Data &DI);
void emitPubSection(raw_ostream &OS, const PubSection &Sect,
                    bool IsLittleEndian);
void emitDebugInfo(raw_ostream &OS, const Data &DI);
void emitDebugLine(raw_ostream &OS, const Data &DI);

Expected<StringMap<std::unique_ptr<MemoryBuffer>>>
emitDebugSections(StringRef YAMLString, bool ApplyFixups = false,
                  bool IsLittleEndian = sys::IsLittleEndianHost);
} // end namespace DWARFYAML
} // end namespace llvm

#endif // LLVM_OBJECTYAML_DWARFEMITTER_H
