#include <iostream>
#include <string>
using namespace std;

// Target interface expected by the client
class MediaPlayer {
public:
    // Pure virtual function that all media players must implement
    virtual void play(string audioType, string fileName) = 0;
    virtual ~MediaPlayer() = default;
};

// Adaptee 1: Has a different interface
class VlcPlayer {
public:
    void playVlc(string fileName) {
        cout << "Playing vlc file. Name: " << fileName << endl;
    }
};

// Adaptee 2: Has a different interface
class Mp4Player {
public:
    void playMp4(string fileName) {
        cout << "Playing mp4 file. Name: " << fileName << endl;
    }
};

// Adapter: Implements the target interface and adapts the Adaptees
class MediaAdapter : public MediaPlayer {
private:
    VlcPlayer vlcPlayer;
    Mp4Player mp4Player;

public:
    void play(string audioType, string fileName) override {
        // Delegates the work to the appropriate Adaptee
        if (audioType == "vlc") {
            vlcPlayer.playVlc(fileName);
        } else if (audioType == "mp4") {
            mp4Player.playMp4(fileName);
        }
    }
};

// Client class that uses the Adapter
class AudioPlayer : public MediaPlayer {
private:
    MediaAdapter* mediaAdapter;

public:
    void play(string audioType, string fileName) override {
        // mp3 is natively supported
        if (audioType == "mp3") {
            cout << "Playing mp3 file. Name: " << fileName << endl;
        } 
        // vlc and mp4 are supported through an adapter
        else if (audioType == "vlc" || audioType == "mp4") {
            mediaAdapter = new MediaAdapter();
            mediaAdapter->play(audioType, fileName);
            delete mediaAdapter;  // Clean up memory
        } 
        // Unsupported format
        else {
            cout << "Invalid media. " << audioType << " format not supported." << endl;
        }
    }
};

// Main function to test the adapter pattern
int main() {
    AudioPlayer player;

    player.play("mp3", "song.mp3");     // Native support
    player.play("mp4", "video.mp4");    // Via adapter
    player.play("vlc", "movie.vlc");    // Via adapter
    player.play("avi", "clip.avi");     // Unsupported

    return 0;
}
