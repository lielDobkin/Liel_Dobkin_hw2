#pragma once
#include <string>
#include "User.h"

/*
 Represents a user's page within a profile in a social network.
 A page contains the user's status and their posts.
 */
class Page 
{
public:
    //--methods--
    /*
     Initializes a new page with an empty status and no posts.
     This function must be called before using the page object.
     */
    void init();

    /*
     Retrieves all the posts on the page.
     return A string containing all the posts, with each post on a new line.
     */
    std::string getPosts() const;

    /*
     Retrieves the current status of the page.
     return A string containing the user's status.
     (The status always appears at the top of the page).
     */
    std::string getStatus() const;

    /*
     Clears all posts from the page.
     */
    void clearPage();

    /*
     Sets the status of the page to a new value.
     param status The new status to set.
     */
    void setStatus(std::string status);

    /*
     Adds a new line to the page's posts.
     param new_line The content of the new post to add.
     */
    void addLineToPosts(std::string new_line);

private:
    //--fields--
    std::string status; // The status displayed at the top of the page. 
    std::string posts;  // The concatenated string of posts on the page.
};

