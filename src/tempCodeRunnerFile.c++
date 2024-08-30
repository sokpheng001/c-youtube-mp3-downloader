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