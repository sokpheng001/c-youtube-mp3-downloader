#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include<atomic>
#include<chrono>
#include<thread>
#include <conio.h> // For _kbhit and _getch
#include <windows.h> // For process management

using namespace std;

void downloadMusic(const std::string& url, const std::string& outputDirectory = "./music/") {
    std::string ffmpegPath = "D:\\Downloads\\ffmpeg-7.0.2-essentials_build\\ffmpeg-7.0.2-essentials_build\\bin"; // Path to the directory containing ffmpeg.exe
    std::string command = "yt-dlp -x --audio-format mp3 --ffmpeg-location \"" + ffmpegPath + "\" -o \"" + outputDirectory + "/%(title)s.%(ext)s\" " + url;

    std::cout << "Executing command: " << command << std::endl; // Debug output

    int result = system(command.c_str());

    if (result == 0) {
        std::cout << "Download complete!" << std::endl;
    } else {
        std::cerr << "Download failed! Please check the URL and try again." << std::endl;
    }
}

// on windows

std::atomic<bool> stopMusic(false);

void listenForInput() {
    while (!stopMusic) {
        if (_kbhit()) {
            char ch = _getch();
            if (ch == 'q' || ch == 'Q') {
                stopMusic = true;
            }
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(100)); // Prevent CPU hogging
    }
}

void playMusicOnWindows(const std::string& filePath) {
    stopMusic = false;
    
    // Start a separate thread to listen for user input
    std::thread inputThread(listenForInput);
    
    // Command to play the music
    std::string command = "ffplay -nodisp -autoexit \"" + filePath + "\"";
    
    // Use CreateProcess to launch ffplay and get its process handle
    STARTUPINFO si = { sizeof(si) };
    PROCESS_INFORMATION pi;
    
    if (!CreateProcess(NULL, (LPSTR)command.c_str(), NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi)) {
        std::cerr << "CreateProcess failed with error: " << GetLastError() << std::endl;
        return;
    }
    
    // Wait for ffplay to exit or for the stopMusic flag to be set
    while (WaitForSingleObject(pi.hProcess, 0) != WAIT_OBJECT_0 && !stopMusic) {
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
    
    // If stopMusic flag is set, terminate the ffplay process
    if (stopMusic) {
        TerminateProcess(pi.hProcess, 0);
    }
    
    // Clean up process handles
    CloseHandle(pi.hProcess);
    CloseHandle(pi.hThread);
    
    // Wait for the input thread to finish
    inputThread.join();
}
// on mac or linux
// #include <cstdlib>
// #include <string>

void playMusicOnMac(const std::string& filePath) {
     //std::string command = "xdg-open \"" + filePath + "\""; // For Linux
    std::string command = "open \"" + filePath + "\""; // For macOS
     system(command.c_str());
}


int main() {

    // Music download section
    // string url;
    // cout << "Enter the YouTube URL to download as MP3: ";
    // getline(cin, url);

    // downloadMusic(url);
    cout<<"================================================\n";
    playMusicOnWindows("./music/TooSweet(Lyrics).mp3");
    while(1){
        int a;
        cout<<"\nEnter the YouTube URL to download: ";cin>>a;
    }
    //this function is called
    return 0;
}
