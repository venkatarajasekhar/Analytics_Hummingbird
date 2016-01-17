#ifndef LIBRARYENTRY_H
#define LIBRARYENTRY_H
#include <string>
#include <json-c/json.h>
#include <vector>

/* Possible values for libraryStatus */
enum library_status {
    CURRENTLY_WATCHING,
    PLAN_TO_WATCH,
    COMPLETED,
    ON_HOLD,
    DROPPED,
    UNDEFINED
};

class LibraryEntry
{
    public:
        LibraryEntry(json_object *j);
        virtual ~LibraryEntry();
        std::string getTitle() { return title; }
        std::string getSynopsis() { return synopsis; }
        std::string getAiringStatus() { return airingStatus; }
        std::string getEpisodeCount() { return episodeCount; }
        std::string getType() { return type; }
        library_status getLibraryStatus() { return libraryStatus; }
        std::string getEpisodesWatched() { return episodesWatched; }
        std::string getRating() { return rating; }
        double getCommunityRating() { return communityRating; }
        std::vector<std::string> getGenres() { return genres; }
    protected:
    private:
        std::string title;
        std::string synopsis;
        std::vector<std::string> genres;
        std::string airingStatus;
        std::string episodeCount;
        std::string type;
        library_status libraryStatus;
        std::string episodesWatched;
        std::string rating;
        double communityRating;
};
#endif // LIBRARYENTRY_H
