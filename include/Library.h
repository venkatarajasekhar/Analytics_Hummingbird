#ifndef LIBRARY_H
#define LIBRARY_H
#include "LibraryEntry.h"
#include <string>
#include <vector>
#include <algorithm>
#include <json-c/json.h>

/* Defines the Library class, which includes the LibraryEntry class.
   The Library class has 4 public methods and the LibraryEntry class
   has 10 public methods, almost all of which are simple getters.
   The Library class contains a hash table that stores LibraryEntries.
   Each LibraryEntry object corresponds to an anime with metadata
   downloaded from the Hummingbird API, and the Library object
   stores all of the LibraryEntries contained in a user's Hummingbird
   library. */

class Library
{

    /* Structure that wraps LibraryEntries so that we can make chains
       (linked lists) to deal with collisions in the hash table.
       (Private to the Library class) */
    struct LibraryEntryWrapper {
        LibraryEntry *entry;
        LibraryEntryWrapper *next;
        LibraryEntryWrapper *previous;

        /* Constructor */
        LibraryEntryWrapper(){
            entry = NULL;
            next = NULL;
            previous = NULL;
        }
    };

    public:
        Library(std:: string username);
        virtual ~Library();
        LibraryEntry* getLibraryEntry(std::string title);
        std::vector<LibraryEntry*> getLibraryEntries(library_status ls);
        static bool libraryEntryTitleSort(LibraryEntry* i, LibraryEntry* j);
        int getLibrarySize();

    protected:
    private:
        int getLibrary(std::string username);
        void addEntry(LibraryEntry *x);
        int hashSum(std::string title);
        static size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp);
        bool curl_setup;
        json_object *library_json;
        int library_size;
        int hash_size;
        LibraryEntryWrapper *hashTable;
};

#endif // LIBRARY_H
