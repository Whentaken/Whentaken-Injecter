// CODE FROM WHENTAKEN!!!!!!!
// YOUTUBE: https://youtube.com/@whentaken
// Discord Server: https://dsc.gg/whentakenhouse
// Download Injecter Source: https://github.com/Whentaken/Whentaken-Injecter
//
//░██╗░░░░░░░██╗██╗░░██╗███████╗███╗░░██╗████████╗░█████╗░██╗░░██╗███████╗███╗░░██╗
//░██║░░██╗░░██║██║░░██║██╔════╝████╗░██║╚══██╔══╝██╔══██╗██║░██╔╝██╔════╝████╗░██║
//░╚██╗████╗██╔╝███████║█████╗░░██╔██╗██║░░░██║░░░███████║█████═╝░█████╗░░██╔██╗██║
//░░████╔═████║░██╔══██║██╔══╝░░██║╚████║░░░██║░░░██╔══██║██╔═██╗░██╔══╝░░██║╚████║
//░░░╚═╝░░░╚═╝░░╚═╝░░╚═╝╚══════╝╚═╝░░╚══╝░░░╚═╝░░░╚═╝░░╚═╝╚═╝░░╚═╝╚══════╝╚═╝░░╚══╝



#include <Windows.h>
#include <iostream>
#include <string>
#include <thread>
#include <libloaderapi.h>

using namespace std;

void get_proc_id(const char* window_title, DWORD& process_id)
{
    GetWindowThreadProcessId(FindWindow(NULL, window_title), &process_id);
}

void error(const char* error_title, const char* error_message)
{
    MessageBox(NULL, error_message, error_title, NULL);
    exit(-1);
}

bool file_exists(string file_name)
{
    struct stat buffer;
    return (stat(file_name.c_str(), &buffer) == 0);
}

int main()
{
    {
        DWORD proc_id = NULL;
        char dll_path[MAX_PATH];
        const char* dll_name = "Your.Dll"; // name of the dll/cheat that the injects in process below ⤵
        const char* window_title = "Game Name"; // open your game and hover over it in ur taskbar and you will see the window title,

        if (!file_exists(dll_name))
        {
            error(":(", "File Does Not Exist!\n Get Help At dsc.gg/whentakenhouse"); // add your dll in \x64\Debug then
        }

        if (!GetFullPathName(dll_name, MAX_PATH, dll_path, nullptr))
        {
            error(":(", "Failed To Get Path:(\n Get Help At dsc.gg/whentakenhouse"); //delete everything in \x64\Debug and build (make sure its on debug)
        }
        get_proc_id(window_title, proc_id);
        if (proc_id == NULL)
        {
            error(":(", "Failed To Find Process\n Get Help At dsc.gg/whentakenhouse"); // make sure "window_title" is the name of the window
        }

        HANDLE h_process = OpenProcess(PROCESS_ALL_ACCESS, NULL, proc_id);
        if (!h_process)
        {
            error(":(", "Failed To Inject!\n Get Help At dsc.gg/whentakenhouse");
        }

        void* allocated_memory = VirtualAllocEx(h_process, nullptr, MAX_PATH, MEM_RESERVE | MEM_COMMIT, PAGE_READWRITE);
        if (!allocated_memory)
        {
            error(":(", "Failed to allocate memory\n Get Help At dsc.gg/whentakenhouse");
        }

        if (!WriteProcessMemory(h_process, allocated_memory, dll_path, MAX_PATH, nullptr))
        {
            error(":(", "Failed to process memory\n Get Help At dsc.gg/whentakenhouse");
        }

        HANDLE h_thread = CreateRemoteThread(h_process, nullptr, NULL, LPTHREAD_START_ROUTINE(LoadLibraryA), allocated_memory, NULL, nullptr);
        if (!h_thread)
        {
            error(":(", "Failed To Create Remote Thread\n Get Help At dsc.gg/whentakenhouse");
        }


        CloseHandle(h_process);
        VirtualFreeEx(h_process, allocated_memory, NULL, MEM_RELEASE);
        MessageBox(0, "successfully Injected!\nThe Base Of This Injecter Is Made By Whentaken", ":)", 0);
    }
}

// CODE FROM WHENTAKEN!!!!!!!
// YOUTUBE: https://youtube.com/@whentaken
// Project Core (Whentakens OGFN Server!): https://dsc.gg/projectcore
// Download Injecter Source: https://github.com/Whentaken/Whentaken-Injecter
//
//░██╗░░░░░░░██╗██╗░░██╗███████╗███╗░░██╗████████╗░█████╗░██╗░░██╗███████╗███╗░░██╗
//░██║░░██╗░░██║██║░░██║██╔════╝████╗░██║╚══██╔══╝██╔══██╗██║░██╔╝██╔════╝████╗░██║
//░╚██╗████╗██╔╝███████║█████╗░░██╔██╗██║░░░██║░░░███████║█████═╝░█████╗░░██╔██╗██║
//░░████╔═████║░██╔══██║██╔══╝░░██║╚████║░░░██║░░░██╔══██║██╔═██╗░██╔══╝░░██║╚████║
//░░░╚═╝░░░╚═╝░░╚═╝░░╚═╝╚══════╝╚═╝░░╚══╝░░░╚═╝░░░╚═╝░░╚═╝╚═╝░░╚═╝╚══════╝╚═╝░░╚══╝