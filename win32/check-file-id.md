As far as I checked, lower 64-bit of 128-bit file identifiers retrieved by
[GetFileInformationByHandleEx][](FileIdInfo) are same with
the the 64-bit file identifiers retrieved by [GetFileInformationByHandle][]()

[GetFileInformationByHandleEx]: https://msdn.microsoft.com/en-us/library/windows/desktop/aa364953(v=vs.85).aspx
[GetFileInformationByHandle]: https://msdn.microsoft.com/en-us/library/windows/desktop/aa364952(v=vs.85).aspx

Test results on my machine:
```
c:\test>cl /MD check-file-id.c
c:\test>check-file-id.exe check-file-id.c check-file-id.exe

Checking check-file-id.c

  GetFileInformationByHandleEx(FileIdInfo)
    VolumeSerialNumber 0xc4d4d0c1d4d0b740
    FileId 0x00000000000000000021000000006645

  GetFileInformationByHandle()
    FileIndex              0x0021000000006645

Checking check-file-id.exe

  GetFileInformationByHandleEx(FileIdInfo)
    VolumeSerialNumber 0xc4d4d0c1d4d0b740
    FileId 0x00000000000000000040000000001418

  GetFileInformationByHandle()
    FileIndex              0x0040000000001418

```
