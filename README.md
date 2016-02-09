# A simple C++ library for Hummingbird.me

### Summary

A C++ library that interfaces with [Hummingbird.me](https://hummingbird.me) API which allows users to search anime library to get information like ratings, genres and synopsis of the shows that user has watched and keep track of completed, on hold and dropped shows.   
### System Requirements

This project only works on Linux right now. It requires an internet connection to download information from Hummingbird.

### Dependencies

This library depends on the cURL and json-c shared libraries and the `make` command, so the first thing you should do is install them. To install them in Ubuntu run the following in a terminal:

    sudo apt-get install libjson0 libjson0-dev libcurl3 libcurl3-gnutls libcurl4-openssl-dev make
    
To install them in Fedora:

    sudo yum install json-c json-c-devel libcurl libcurl-devel make

### How to build

Now, download the project by running

    git clone https://github.com/surajr/Analytics_Hummingbird.git
    
in a terminal, and then change to the directory you just downloaded:
    
    cd Analytics_Hummingbird

Finally, compiling the example program is as simple as running

    make
    
in your terminal. Or, if you want, you can open the `Final Project.cbp` using Code::Blocks and compile it using Code::Blocks' "build" funtion.

Once you build the project, the output example program `main` will be saved in `bin/Release/` in the project folder. To make it easier to run the program without having to change directories, you could copy the program to the root of the project directory by typing

    cp bin/Release/main .

### How to run

Simply type 

    ./main [username]
    
to run the example program, which downloads a certain user's anime library and allows you to browse it. For example, [Josh](https://hummingbird.me/users/Josh/library) is the username of the co-founder of Hummingbird. To download and browse his library, simple type `./main Josh`.

Documentation on how the library works can be found in the library implementation files Library.cpp and LibraryEntry.cpp and their associated header files.


### Known Bugs

* Trying to download some users' libraries causes the following error while parsing the JSON objects returned by the Hummingbird API:

```
terminate called after throwing an instance of 'std::logic_error'
    what():  basic_string::_S_construct null not valid
```

* Sometimes cURL (or perhaps something else) seems to hang or get stuck while getting a user's library in getLibrary(). (This is probably the case if it takes more than a minute to download).
    

