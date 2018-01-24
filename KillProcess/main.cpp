#include <iostream>
#include <windows.h>
#include <tlhelp32.h>
#include <vector>
#include <ctime>


BOOL TerminateMyProcess(DWORD dwProcessId, UINT uExitCode);

int main(int, char *[]) {

    clock_t startTime = clock(); //Start timer

    std::vector<DWORD> pids;
    std::wstring targetProcessName;

    std::cout << "Please enter the name of the process you want to kill: ";
    std::wcin >> targetProcessName;
    double secondsPassed;
    double secondsToDelay;
    std::cout << "Time to delay in min: ";
    std::cin >> secondsToDelay;

    secondsToDelay = secondsToDelay * 60;

    HANDLE snap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0); //all processes

    PROCESSENTRY32W entry; //current process
    entry.dwSize = sizeof entry;

    if (!Process32FirstW(snap, &entry)) { //start with the first in snapshot
        return 0;
    }

    do {
        if (std::wstring(entry.szExeFile) == targetProcessName) {
            pids.emplace_back(entry.th32ProcessID); //name matches; add to list
        }
    } while (Process32NextW(snap, &entry)); //keep going until end of snapshot

    bool flag = true;
    while(flag)
    {
        secondsPassed = (clock() - startTime) / CLOCKS_PER_SEC;
        if(secondsPassed >= secondsToDelay)
        {
            std::cout << secondsPassed << " seconds have passed" << std::endl;
            flag = false;
        }
    }

    for (int i(0); i < pids.size(); ++i) {
        std::cout << pids[i] << std::endl;
        TerminateMyProcess(pids[i],0);
    }

    system(EXIT_SUCCESS);
}

BOOL TerminateMyProcess(DWORD dwProcessId, UINT uExitCode)
{
    DWORD dwDesiredAccess = PROCESS_TERMINATE;
    BOOL  bInheritHandle  = FALSE;
    HANDLE hProcess = OpenProcess(dwDesiredAccess, bInheritHandle, dwProcessId);
    if (hProcess == NULL)
        return FALSE;

    BOOL result = TerminateProcess(hProcess, uExitCode);

    CloseHandle(hProcess);

    return result;
}