#include <stdio.h>
#include <windows.h>

const char *processor_arch_to_name(WORD arch)
{
  switch (arch) {
  case PROCESSOR_ARCHITECTURE_AMD64:
    return "x64";
  case PROCESSOR_ARCHITECTURE_ARM:
    return "arm";
  case PROCESSOR_ARCHITECTURE_ARM64:
    return "arm64";
  case PROCESSOR_ARCHITECTURE_IA64:
    return "ia64";
  case PROCESSOR_ARCHITECTURE_INTEL:
    return "x86";
  case PROCESSOR_ARCHITECTURE_UNKNOWN:
    return "unknown";
  default:
    return "???";
  }
}

static const char *machine_to_name(USHORT arch)
{
    switch (arch) {
    case IMAGE_FILE_MACHINE_AMD64:
        return "x64";
    case IMAGE_FILE_MACHINE_ARM64:
        return "arm64";
    case IMAGE_FILE_MACHINE_ARMNT:
        return "arm";
    case IMAGE_FILE_MACHINE_I386:
        return "x86";
    case IMAGE_FILE_MACHINE_UNKNOWN:
        return "unknown";
    default:
        return "???";
    }
}

int main()
{
  HANDLE hProcess = GetCurrentProcess();
  SYSTEM_INFO si;
  GetSystemInfo(&si);
  WORD arch_syste_info = si.wProcessorArchitecture;
  GetNativeSystemInfo(&si);
  WORD arch_native_syste_info = si.wProcessorArchitecture;

  USHORT process_machine_info_machine = (USHORT)-1;
  PROCESS_MACHINE_INFORMATION pmi;
  if (GetProcessInformation(hProcess, ProcessMachineTypeInfo, &pmi, sizeof(pmi))) {
    process_machine_info_machine = pmi.ProcessMachine;
  }
  USHORT process_machine = (USHORT)-1;
  USHORT native_machine = (USHORT)-1;
  IsWow64Process2(hProcess, &process_machine, &native_machine);

  printf(" | %s | %s | %s | %s | %s\n",
         processor_arch_to_name(arch_syste_info),
         processor_arch_to_name(arch_native_syste_info),
         machine_to_name(process_machine_info_machine),
         machine_to_name(process_machine),
         machine_to_name(native_machine));
  return 0;
}
