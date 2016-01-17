/* Hjalte Durocher
 * CSCI 2270
 * Final Project
 * Rhonda Hoenigman
*/
#include "Library.h"
#include <iostream>
#include <cstdio>
#include <string>
#include <stdlib.h>

using namespace std;

int printMenu(string username)
{
    cout << "---------------Main Menu---------------" << endl;
    cout << "1. Print " << username << "'s Currently Watching list" << endl;
    cout << "2. Print " << username << "'s Plan to Watch list" << endl;
    cout << "3. Print " << username << "'s Completed list" << endl;
    cout << "4. Print " << username << "'s On Hold list" << endl;
    cout << "5. Print " << username << "'s Dropped list" << endl;
    cout << "6. Get more information about a show" << endl;
    cout << "7. Quit" << endl;

    string in;
    getline(cin, in);

    return atoi(in.c_str());
}

Library* downloadLibrary(string username) {
    cout << "Downloading " << username << "'s Hummingbird.me library..." << endl;
    cout << "(This can take a while)" << endl;
    Library *L = new Library(username);
    return L;
}

void getMoreInfo(Library *L) {

    /* String to store user input */
    string in;

    /* Stores library entry, if found */
    LibraryEntry* le;

    /* Get user input */
    while(1) {
        cout << "Type the name of a show to get more info about it:" << endl;
        getline(cin, in);
        le = L->getLibraryEntry(in);

        /* Let user exit by typing "q" */
        if(in.compare("q") == 0)
            return;
        /* Entry found */
        else if(le != NULL)
            break;
        /* Entry not found */
        else {
            cout << "Couldn't find \"" << in;
            cout << "\" (try again or type \"q\" to quit)" << endl << endl;
        }
    }

    /* Print title */
    cout << endl << "\"" << le->getTitle() << "\"" << endl;

    /* Print synopsis */
    cout << "#Synopsis: " << le->getSynopsis() << endl;

    /* Print airing status */
    cout << "#Status: " << le->getAiringStatus() << endl;

    /* Print type */
    cout << "#Type: " << le->getType() << endl;

    /* Print Genres */
    cout << "#Genres: ";
    vector<string> genres = le->getGenres();
    for(unsigned i=0; i<genres.size(); i++) {
        cout << genres[i];
        if(i+1<genres.size())
            cout << ", ";
    }
    cout << endl;

    /* Print community rating */
    cout << "#Community Rating: ";
    printf("%1.2f/5", le->getCommunityRating());
    cout << endl;

    /* Print number of episodes watched out of total episodes */
    cout << "#Watched: " << le->getEpisodesWatched() << "/" << le->getEpisodeCount() << endl;

    /* Print user's rating */
    cout << "#Rating: " << le->getRating() << endl << endl;
}

int main(int argc, char *argv[])
{
    int rc;
    string username;

    if(argc != 2) {
        cout << "Usage: main [username]";
        cout << " (Example: main Josh)" << endl;
        rc = 1;
    } else {
        username = string(argv[1]);

        Library *L = downloadLibrary(username);

        /* The library's size will have been set to -1 if it failed to download */
        if(L->getLibrarySize() != -1) {
            /* The user's library was downloaded and parsed succesfully! Here we use
               getLibrarySize() to get the number of entries in the library. */
            cout << "Done! (loaded " << L->getLibrarySize() << " entries)"<< endl << endl;
            rc = 0;
        }
        else {
            /* The user's library couldn't be downloaded or parsed :( */
            cout << "Failure! Couldn't download " << username <<"'s library"  << endl;
            rc = 1;
        }

        if(rc == 0) {
            int s;
            while(1) {
                s = printMenu(username);
                if(s == 1) {
                    vector<LibraryEntry*> v = L->getLibraryEntries(CURRENTLY_WATCHING);
                    for(unsigned i=0; i<v.size(); i++) {
                        cout << "\"" << v[i]->getTitle() << "\"" << " (";
                        cout << v[i]->getEpisodesWatched() << "/" << v[i]->getEpisodeCount() << ")" << endl;
                    }
                }
                else if(s == 2) {
                    vector<LibraryEntry*> v = L->getLibraryEntries(PLAN_TO_WATCH);
                    for(unsigned i=0; i<v.size(); i++)
                        cout << "\"" << v[i]->getTitle() << "\"" << endl;
                }
                else if(s == 3) {
                    vector<LibraryEntry*> v = L->getLibraryEntries(COMPLETED);
                    for(unsigned i=0; i<v.size(); i++)
                        cout << "\"" << v[i]->getTitle() << "\"" << endl;
                }
                else if(s == 4) {
                    vector<LibraryEntry*> v = L->getLibraryEntries(ON_HOLD);
                    for(unsigned i=0; i<v.size(); i++)
                        cout << "\"" << v[i]->getTitle() << "\"" << endl;
                }
                else if(s == 5) {
                    vector<LibraryEntry*> v = L->getLibraryEntries(DROPPED);
                    for(unsigned i=0; i<v.size(); i++)
                        cout << "\"" << v[i]->getTitle() << "\"" << endl;
                }
                else if(s == 6) {
                    getMoreInfo(L);
                }
                else if(s == 7) {
                    cout << "Goodbye!" << endl;
                    rc = 0;
                    break;
                } else {
                    cout << "Didn't understand that, please try again" << endl << endl;
                }
            }
        }

        delete L;
    }

    return rc;
}


