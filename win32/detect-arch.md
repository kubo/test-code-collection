I checked `PROCESSOR_ARCHITECTURE_*` and [`IMAGE_FILE_MACHINE_*`] values on Windows 11 x64 and arm64.

OS | executable | system info[^1] | native system info[^2] | process machine type info[^3] | wow64 process machine[^4] | wow64 native machine[^5]
------|---------|-------|---------|-------|---------|-------
arm64 | arm     | arm   | arm64   | arm   | arm     | arm64
arm64 | arm64   | arm64 | arm64   | arm64 | unknown | arm64
arm64 | [arm64ec] | x64   | x64     | x64   | unknown | arm64
arm64 | x64     | x64   | x64     | x64   | unknown | arm64
arm64 | x86     | x86   | x64[^6] | x86   | x86     | arm64
x64   | x64     | x64   | x64     | x64   | unknown | x64
x64   | x86     | x86   | x64     | x86   | x86     | x64

* [`GetSystemInfo`] and [`GetNativeSystemInfo`] aren't usable to check the OS architecture. The third argument of [`IsWow64Process2`] is usable instead.
* I don't know how to distinguish x64 processes from [arm64ec] processes. I guess that it can because the task manager distinguishs them.

[^1]: The [`wProcessorArchitecture`] field got by [`GetSystemInfo`]
[^2]: The [`wProcessorArchitecture`] field got by [`GetNativeSystemInfo`]
[^3]: The [`ProcessMachine`] field got by [`GetProcessInformation`] and [`ProcessMachineTypeInfo`] (available since Windows 11)
[^4]: The second argument of [`IsWow64Process2`]
[^5]: The third argument of [`IsWow64Process2`]
[^6]: It is x86 on Windows 10 arm64 according to [this document][`GetNativeSystemInfo`].

[arm64ec]: https://learn.microsoft.com/en-us/windows/arm/arm64ec
[`GetNativeSystemInfo`]: https://learn.microsoft.com/en-us/windows/win32/api/sysinfoapi/nf-sysinfoapi-getnativesysteminfo
[`GetProcessInformation`]: https://learn.microsoft.com/en-us/windows/win32/api/processthreadsapi/nf-processthreadsapi-getprocessinformation
[`GetSystemInfo`]: https://learn.microsoft.com/en-us/windows/win32/api/sysinfoapi/nf-sysinfoapi-getsysteminfo
[`IMAGE_FILE_MACHINE_*`]: https://learn.microsoft.com/en-us/windows/win32/sysinfo/image-file-machine-constants
[`IsWow64Process2`]: https://learn.microsoft.com/en-us/windows/win32/api/wow64apiset/nf-wow64apiset-iswow64process2
[`ProcessMachine`]: https://learn.microsoft.com/en-us/windows/win32/api/processthreadsapi/ns-processthreadsapi-process_machine_information
[`ProcessMachineTypeInfo`]: https://learn.microsoft.com/en-us/windows/win32/api/processthreadsapi/ne-processthreadsapi-process_information_class
[`wProcessorArchitecture`]: https://learn.microsoft.com/en-us/windows/win32/api/sysinfoapi/ns-sysinfoapi-system_info
