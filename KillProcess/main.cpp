#include <iostream>
#include <windows.h>
#include <tlhelp32.h>
#include <vector>
#include <ctime>

BOOL TerminateMyProcess(DWORD dwProcessId, UINT uExitCode);
BOOL CheckString(std::wstring ProcessName);

int main(int, char *[]) {

    clock_t startTime = clock(); //Start timer

    std::vector<DWORD> pids;
    std::wstring targetProcessName = L"0";

    while(targetProcessName == L"0" || CheckString(targetProcessName))
    {
        std::cout << "Please enter the name of the process you want to kill: ";
        std::wcin >> targetProcessName;
    }

    double secondsPassed;
    double secondsToDelay = 0;

    while(secondsToDelay <= 0)
    {
        std::cout << "Time to delay in min: ";
        std::cin >> secondsToDelay;

        if(secondsToDelay <= 0)
            std::cout << "Please use a number greater than zero";
    }

    secondsToDelay = secondsToDelay * 60;

    HANDLE snap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0); //all processes

    PROCESSENTRY32W entry; //current process
    entry.dwSize = sizeof entry;

    if (!Process32FirstW(snap, &entry)) //start with the first in snapshot
    {
        return 0;
    }

    do
    {
        if (std::wstring(entry.szExeFile) == targetProcessName)
        {
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

    for (int i(0); i < pids.size(); ++i)
    {
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

BOOL CheckString(std::wstring ProcessName)
{
    if(ProcessName.find(L".exe") > 0)
        return false;
    else
        return true;

    //TODO: check if string may be a critical process that should not be forced to shut down
}