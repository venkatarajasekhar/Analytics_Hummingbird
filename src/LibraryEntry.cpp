#include "LibraryEntry.h"

/* LibraryEntry* = new LibraryEntry(json_object);

   Constructor for the LibraryEntry class. Defines all of the private members
   by parsing the final json_object created by the Library class.

   ex. LibraryEntry *le = new LibraryEntry(json_object_final);

   Pre-conditions: final json object created by getLibrary(). This constructor
   should really only be called from within getLibrary().

   Post-conditions: returns a fully constructed LibraryEntry. */

LibraryEntry::LibraryEntry(json_object *j)
{
    json_object *title_json;
    json_object_object_get_ex(j, "title", &title_json);
    title = std::string(json_object_get_string(title_json));

    json_object *synopsis_json;
    json_object_object_get_ex(j, "synopsis", &synopsis_json);
    synopsis = std::string(json_object_get_string(synopsis_json));

    json_object *airing_status_json;
    json_object_object_get_ex(j, "airing_status", &airing_status_json);
    airingStatus = std::string(json_object_get_string(airing_status_json));

    json_object *episode_count_json;
    json_object_object_get_ex(j, "episode_count", &episode_count_json);
    episodeCount = std::string(json_object_to_json_string(episode_count_json));

    json_object *episodes_watched_json;
    json_object_object_get_ex(j, "episodes_watched", &episodes_watched_json);
    episodesWatched = std::string(json_object_to_json_string(episodes_watched_json));

    json_object *library_status_json;
    json_object_object_get_ex(j, "library_status", &library_status_json);
    std::string libraryStatusString = std::string(json_object_get_string(library_status_json));

    if(libraryStatusString.compare("currently-watching") == 0)
        libraryStatus = CURRENTLY_WATCHING;
    else if(libraryStatusString.compare("plan-to-watch") == 0)
        libraryStatus = PLAN_TO_WATCH;
    else if(libraryStatusString.compare("completed") == 0)
        libraryStatus = COMPLETED;
    else if(libraryStatusString.compare("on-hold") == 0)
        libraryStatus = ON_HOLD;
    else if(libraryStatusString.compare("dropped") == 0)
        libraryStatus = DROPPED;
    else /* Undefined, this shouldn't happen (means anime isn't in the user's library) */
        libraryStatus = UNDEFINED;

    json_object *rating_json;
    json_object_object_get_ex(j, "rating", &rating_json);
    rating = std::string(json_object_to_json_string(rating_json));

    json_object *community_rating_json;
    json_object_object_get_ex(j, "community_rating", &community_rating_json);
    communityRating = json_object_get_double(community_rating_json);

    json_object *type_json;
    json_object_object_get_ex(j, "show_type", &type_json);
    type = std::string(json_object_get_string(type_json));

    json_object *genres_json;
    json_object_object_get_ex(j, "genres", &genres_json);
    genres.assign(json_object_array_length(genres_json),"");
    for(int i=0; i<json_object_array_length(genres_json); i++) {
        json_object *genre_json = json_object_array_get_idx(genres_json, i);
        json_object *genre_name_json;
        json_object_object_get_ex(genre_json, "name", &genre_name_json);
        genres[i] = std::string(json_object_get_string(genre_name_json));
    }
}

/* Destructor: nothing to do */
LibraryEntry::~LibraryEntry()
{
    //dtor
}
