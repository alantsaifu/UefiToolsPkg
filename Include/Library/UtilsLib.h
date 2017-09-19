/*
 * Copyright (C) 2017 Andrei Evgenievich Warkentin
 *
 * This program and the accompanying materials
 * are licensed and made available under the terms and conditions of the BSD License
 * which accompanies this distribution.  The full text of the license may be found at
 * http://opensource.org/licenses/bsd-license.php
 *
 * THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,
 * WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.
 */

#ifndef _UTILS_LIB_H_
#define _UTILS_LIB_H_

#include <Uefi.h>

typedef struct GET_OPT_CONTEXT {
  CHAR16 Opt;
  CHAR16 *OptArg;
  UINTN OptIndex;
} GET_OPT_CONTEXT;

#define INIT_GET_OPT_CONTEXT(ContextPointer) do {\
    (ContextPointer)->Opt = L'\0';               \
    (ContextPointer)->OptArg = NULL;             \
    (ContextPointer)->OptIndex = 1;              \
  } while (0)

EFI_STATUS
GetOpt(IN UINTN Argc,
       IN CHAR16 **Argv,
       IN CHAR16 *OptionsWithArgs,
       IN OUT GET_OPT_CONTEXT *Context);

EFI_STATUS
FileSystemSave (
                IN EFI_HANDLE Handle,
                IN CHAR16 *VolSubDir,
                IN CHAR16 *Path,
                IN VOID *Table,
                IN UINTN TableSize
                );

VOID *
GetTable (
          IN EFI_GUID *Guid
          );

#ifndef ARRAY_SIZE
#define ARRAY_SIZE(x) (sizeof(x) / sizeof((x)[0]))
#endif

CHAR16
CharToUpper (
             IN CHAR16 Char
             );

INTN
StriCmp (
         IN CONST CHAR16 *FirstString,
         IN CONST CHAR16 *SecondString
         );

EFI_STATUS
RangeIsMapped (
               IN UINTN RangeStart,
               IN UINTN RangeLength,
               IN BOOLEAN WarnIfNotFound
               );

#endif /* _UTILS_LIB_H_ */
