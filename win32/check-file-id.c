/* -*- c-basic-offset: 4; indent-tabs-mode: nil -*- */
#include <stdio.h>
#include <windows.h>

/* My own definition of 128-bit file id.
 *
 * MS defines FILE_ID_128 in winnt.h to represent 128-bit file id.
 * But it isn't easy to use it as integers.
 */
typedef struct {
    ULONGLONG low64;
    ULONGLONG high64;
} file_id_128_t;

static void check_file_id(const char *file)
{
    HANDLE hFile = CreateFileA(file, 0, FILE_SHARE_READ | FILE_SHARE_WRITE | FILE_SHARE_DELETE,
                               NULL, OPEN_EXISTING, 0, NULL);
    BY_HANDLE_FILE_INFORMATION finfo;
    FILE_ID_INFO fidinfo;
    file_id_128_t file_id;

    if (hFile == INVALID_HANDLE_VALUE) {
        printf("Failed to open %s\n", file);
        return;
    }
    printf("Checking %s\n\n", file);

    if (!GetFileInformationByHandleEx(hFile, FileIdInfo, &fidinfo, sizeof(fidinfo))) {
        printf("Failed to call GetFileInformationByHandleEx(FileIdInfo)\n");
        CloseHandle(hFile);
        return;
    }
    file_id = *(file_id_128_t*)&fidinfo.FileId;
    printf("  GetFileInformationByHandleEx(FileIdInfo)\n");
    printf("    VolumeSerialNumber 0x%016I64x\n", fidinfo.VolumeSerialNumber);
    printf("    FileId 0x%016I64x%016I64x\n\n", file_id.high64, file_id.low64);

    if (!GetFileInformationByHandle(hFile, &finfo)) {
        printf("Failed to call GetFileInformationByHandle\n");
        CloseHandle(hFile);
        return;
    }
    printf("  GetFileInformationByHandle()\n");
    printf("    FileIndex              0x%08x%08x\n\n", finfo.nFileIndexHigh, finfo.nFileIndexLow);

    CloseHandle(hFile);
}

int main(int argc, char **argv)
{
    int i;

    for (i = 1; i < argc; i++) {
        check_file_id(argv[i]);
    }
}
