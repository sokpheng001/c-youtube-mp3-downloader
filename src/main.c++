#include <iostream>
#include <string>
#include <memory>
#include <vector>

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


int main() {

    // Music download section
    string url;
    cout << "Enter the YouTube URL to download as MP3: ";
    getline(cin, url);

    downloadMusic(url);

    return 0;
}
