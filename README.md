# C++ Youtube Mp3 Download System
- **Requriments**    
    1. **Install Python**: <a href="https://www.python.org/downloads/">python.org</a>  
    2. **Install python module**: ``` pip install yt-dlp ```        
    3. **Set Up Environment Variables (If Needed)**:   
        - If you did not check Add Python to PATH during installation, you might need to manually add Python and pip to your PATH.
        - Open Environment Variables
            - Right-click on This PC or Computer on the desktop or in File Explorer.
            - Select Properties.
            - Click Advanced system settings.
            - Click Environment Variables.
        - Add Python to PATH:
            - In the System variables section, find the Path variable and select it.
            - Click Edit.
            - Add the path to the Python installation ```(e.g 
            C:\Python39 or wherever Python is installed).```
            - Also, add the path to the Scripts directory ```(e.g., 
                C:\Program Files\Python312\Scripts\).```
            - Click OK to close all dialog boxes.
    4. **Confirm Environment Setup**:
        - Open a new Command Prompt and type:
            ``` bash 
                python --version
                yt-dlp --version 
            ```
        - Verify that both commands are recognized and return the correct versions.
    ----
    5. **Download ffmpeg for Windows (Release Essentials Build)**
        - Download link: https://www.gyan.dev/ffmpeg/builds/ffmpeg-release-essentials.zip
    6. **Extract the ffmpeg Archive**:  
        - Once the download is complete, extract the .zip file to a location of your choice, such as ```C:\ffmpeg```   
        - The folder should contain a bin directory where the ``` ffmpeg.exe, ffplay.exe, and ffprobe.exe ``` binaries are located.
    7. **Add ffmpeg to the System PATH**:  
    - To make **ffmpeg** accessible from any command prompt without navigating to the directory, you need to add it to your system's PATH.  
        - Right-click on This PC or My Computer and select Properties.
        - Click on Advanced system settings on the left.
        - In the System Properties window, click on Environment Variables.
        - Under the System variables section, scroll down and find the Path variable. Select it and click Edit.
        - Click New and add the path to the ffmpeg\bin directory. For example, ```C:\ffmpeg\bin```
        - Click OK to close all windows.
    8. ***Verify Installation**:  
    - To ensure that ffmpeg is installed correctly:  
        - Open a Command Prompt and type:
        ``` bash
        ffmpeg -version
        ```
        - You should see the version information of ffmpeg, confirming that it's installed and available globally.
