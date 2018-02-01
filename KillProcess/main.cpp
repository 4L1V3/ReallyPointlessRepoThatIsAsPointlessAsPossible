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

    int setTimeScale;

    double secondsPassed;
    double secondsToDelay = 0;

    bool exists = false;

    while(targetProcessName == L"0" || CheckString(targetProcessName))
    {
        std::cout << "Please enter the name of the process you want to kill: ";
        std::wcin >> targetProcessName;
        system("cls");
    }

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
            exists = true;
        }
    } while (Process32NextW(snap, &entry)); //keep going until end of snapshot

    bool flag = true;

    if(exists == true)
    {
        std::cout << "Set scale of timer:" << std::endl;
        std::cout << "1: Seconds\n2: Minutes\n3: Hours\n4: Instant" << std::endl;
        std::cin >> setTimeScale;

        switch(setTimeScale)
        {
            case 1:
                while (secondsToDelay <= 0) {
                    std::cout << "Time to delay in seconds: ";
                    std::cin >> secondsToDelay;

                    if (secondsToDelay <= 0)
                        std::cout << "Please use a number greater than zero";
                };
                break;
            case 2:
                while (secondsToDelay <= 0) {
                    std::cout << "Time to delay in minutes: ";
                    std::cin >> secondsToDelay;

                    if (secondsToDelay <= 0)
                        std::cout << "Please use a number greater than zero";
                    secondsToDelay *= 60;
                };
                break;
            case 3:
                while (secondsToDelay <= 0) {
                    std::cout << "Time to delay in hours: ";
                    std::cin >> secondsToDelay;

                    if (secondsToDelay <= 0)
                        std::cout << "Please use a number greater than zero";
                    secondsToDelay *= (3600);
                };
                break;
            case 4:
                secondsToDelay = 0;
                break;
            /*default:
                std::cout << "Input was not correct, exiting . . .";
                system(0);
                break;*/
        }


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
            TerminateMyProcess(pids[i], 0);
        }

        system(EXIT_SUCCESS);

    }
    else
    {
        std::cout << "Name of the process was not correct or it didn't exist." << std::endl << std::endl;
        system("pause");
    }

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