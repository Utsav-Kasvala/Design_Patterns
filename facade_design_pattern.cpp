#include <iostream>
using namespace std;

// Subsystem 1
class DVDPlayer {
public:
    void on() { cout << "DVD Player ON" << endl; }
    void play() { cout << "Playing DVD..." << endl; }
    void off() { cout << "DVD Player OFF" << endl; }
};

// Subsystem 2
class Projector {
public:
    void on() { cout << "Projector ON" << endl; }
    void wideScreenMode() { cout << "Projector in widescreen mode" << endl; }
    void off() { cout << "Projector OFF" << endl; }
};

// Subsystem 3
class SoundSystem {
public:
    void on() { cout << "Sound System ON" << endl; }
    void setVolume(int level) { cout << "Volume set to " << level << endl; }
    void off() { cout << "Sound System OFF" << endl; }
};

// 🎬 Facade class
class HomeTheaterFacade {
private:
    DVDPlayer* dvd;
    Projector* projector;
    SoundSystem* sound;

public:
    HomeTheaterFacade(DVDPlayer* d, Projector* p, SoundSystem* s)
        : dvd(d), projector(p), sound(s) {}

    void watchMovie() {
        cout << "--- Getting ready to watch a movie ---" << endl;
        dvd->on();
        projector->on();
        projector->wideScreenMode();
        sound->on();
        sound->setVolume(5);
        dvd->play();
    }

    void endMovie() {
        cout << "--- Shutting movie theater down ---" << endl;
        dvd->off();
        projector->off();
        sound->off();
    }
};

// Test the facade
int main() {
    // Create subsystem instances
    DVDPlayer dvd;
    Projector projector;
    SoundSystem sound;

    // Create facade
    HomeTheaterFacade homeTheater(&dvd, &projector, &sound);

    // Use simplified interface
    homeTheater.watchMovie();
    cout << endl;
    homeTheater.endMovie();

    return 0;
}
