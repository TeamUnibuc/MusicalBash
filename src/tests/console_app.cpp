#include "player.hpp"
#include "console_app.hpp"

#include <bits/stdc++.h>
using namespace std;

namespace {
    Player player;

    void make_tick()
    {
        while (true)
            player.Step();
        this_thread::sleep_for(chrono::milliseconds(100));
    }

    void print_available_functions()
    {
        cout << "Available functions:\n";
        cout << "1. zip [file]\n    Zips the content of player in file\n";
        cout << "2. unzip [file]\n    Unzips the content of player from file\n";
        cout << "3. list music\n    Lists all available music\n";
        cout << "4. list album\n    Lists all available albums\n";
        cout << "5. list playlist\n    Lists all available playlists\n";
        cout << "6. play\n    Plays the music\n";
        cout << "7. pause\n    Pauses the music\n";
        cout << "8. stop\n    stops the music\n";
        cout << "9. add music\n    adds music to queue\n";
        cout << "10. add playlist\n    adds playlist to queue\n";
        cout << "11. add album\n    adds album to playlist\n";
        cout << "12. create album\n    creates an album\n";
        cout << "13. create playlist\n    creates a playlist\n";
        cout << "14. insert\n    inserts a song to a playlist\n";
        cout << "15. set [volume]\n    sets the volume [1..100]\n";
        cout << "16. help\n    prints this message\n";
        cout << "17. offset get\n    shows curent offset in music\n";
        cout << "18. offset set\n    sets the playing offset\n";
        cout << "19. status\n    show status of player\n";
    }

}
void StartConsoleApp()
{
    //thread step(make_tick);

    print_available_functions();

    while (true) {
        cout << " $ ";
        string s;
        cin >> s;
        if (s == "zip") {
            cout << "Where?\n $$ ";
            string where;
            cin >> where;
            ofstream out(where);
            out << player.Zip();
            out.close();
            cout << "Done!\n";
        }
        else if (s == "unzip") {
            cout << "From where?\n $$ ";
            string where;
            cin >> where;

            ifstream in;
            in.open(where);
            stringstream strStream;
            strStream << in.rdbuf(); //read the file
            string str = strStream.str();
            player = Player();
            player.Unzip(str);
            cout << "Done!\n";
        }
        else if (s == "list") {
            cin >> s;
            if (s == "music") {
                auto music = player.getAllMusic();
                cout << "All music:\n";
                for (auto i : music)
                    cout << i->getName() << " - " << i->getDuration() << "sec.\n";
            }
            else if (s == "album") {
                auto album = player.getAlbums();
                cout << "All albums:\n";
                for (auto i : album) {
                    cout << "Album at " << i->GetName() << " contains:\n";
                    for (auto j : i->GetMusic())
                        cout << j->getName() << '\n';
                }
            }
            else if (s == "playlist") {
                auto playlist = player.getPlaylists();
                cout << "All playlists:\n";
                for (auto i : playlist) {
                    cout << "Playlist at " << i->GetName() << " contains:\n";
                    for (auto j : i->GetMusic())
                        cout << j->getName() << '\n';
                }
            }
            else {
                cout << "Invalid argument\n";
            }
        }
        else if (s == "play") {
            player.PlayMusic();
        }
        else if (s == "pause") {
            player.PauseMusic();
        }
        else if (s == "stop") {
            player.StopMusic();
        }
        else if (s == "add") {
            cin >> s;
            if (s == "music") {
                auto music = player.getAllMusic();
                cout << "What music to add?\n $$ ";
                for (int i = 0; i < (int)music.size(); i++)
                    cout << i << ": " << music[i]->getName() << '\n';
                cout << " $$ ";
                int id;
                cin >> id;
                player.addMusicToQueue(music[id]);
            }
            else if (s == "playlist") {
                auto playlist = player.getPlaylists();
                cout << "What playlist to add?\n $$ ";
                for (int i = 0; i < (int)playlist.size(); i++)
                    cout << i << ": " << playlist[i]->GetName() << '\n';
                cout << " $$ ";
                int id;
                cin >> id;
                player.addPlaylistToQueue(playlist[id]);
            }
            else if (s == "album") {
                auto album = player.getAlbums();
                cout << "What album to add?\n $$ ";
                for (int i = 0; i < (int)album.size(); i++)
                    cout << i << ": " << album[i]->GetName() << '\n';
                cout << " $$ ";
                int id;
                cin >> id;
                player.addAlbumToQueue(album[id]);
            }
            else
                cout << "Invalid argument\n";
        }
        else if (s == "create") {
            cin >> s;
            if (s == "album") {
                cout << "What is the path of the album?\n $$ ";
                cin >> s;
                player.CreateAlbum(s);
                cout << "Done!\n";
            }
            else if (s == "playlist") {
                cout << "What is the name of the playlist?\n $$ ";
                cin >> s;
                player.CreatePlaylist(s);
                cout << "Done!\n";
            }
            else
                cout << "Invalid argument\n";;
        }
        else if (s == "insert") {
            auto playlist = player.getPlaylists();
            cout << "In what playlist do you want to add a song?\n";
            for (int i = 0; i < (int)playlist.size(); i++)
                cout << i << ": " << playlist[i]->GetName() << '\n';
            cout << " $$ ";
            int id;
            cin >> id;
            cout << "Selected playlist has:\n";
            for (auto i : playlist[id]->GetMusic())
                cout << i->getName() << '\n';
            cout << "All available music is:\n";
            auto music = player.getAllMusic();
            for (int i = 0; i < (int)music.size(); i++)
                cout << i << ": " << music[i]->getName() << '\n';

            cout << "What music do you want to add?\n $$ ";
            int id2;
            cin >> id2;
            playlist[id]->AddMusic(music[id2]);
        }
        else if (s == "set") {
            int volume;
            cin >> volume;
            player.setVolume(volume);
        }
        else if (s == "help") {
            print_available_functions();
        }
        else if (s == "offset") {
            cin >> s;
            if (s == "get")
                cout << "Offset is " << player.getActiveSongPlayingOffset() << '\n';
            else {
                cout << "Where to place cursor (in seconds)?\n $$ ";
                int x;
                cin >> x;
                player.setActiveSongPlayingOffset(x);
            }
        }
        else if (s == "length") {
            shared_ptr<PMusic> playing = player.getActiveSong();
            if (playing)
                cout << "Length is " << playing->getDuration() << '\n';
            else
                cout << "There is no song playing\n";
        }
        else if (s == "status") {
            int status = player.getPlayingStatus();
            if (status == -1)
                cout << "Player is stopped\n";
            if (status == 0)
                cout << "Player is playing\n";
            else if (status == 1)
                cout << "Player is paused\n";
            else
                throw runtime_error("Internal error");
        }
    }
}