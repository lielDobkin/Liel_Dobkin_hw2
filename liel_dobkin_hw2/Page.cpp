#include "Page.h"
#include <iostream>

/*
 Initializes a new page with an empty status and no posts.
 This function must be called before using the page object.
*/
void Page::init()
{
    // Set the status to an empty string
    status = "";

    // Set the posts to an empty string
    posts = "";
}


/*
 Retrieves all the posts on the page.
 return A string containing all the posts, with each post on a new line.
*/
std::string Page::getPosts() const
{
    // Return the string containing all the posts
    return posts;
}


/*
 Retrieves the current status of the page.
 return A string containing the user's status.
 (The status always appears at the top of the page).
 */
std::string Page::getStatus() const
{
    // Return the current status of the page
    return status;
}


/*
 Clears all posts from the page.
 */
void Page::clearPage()
{
    // Reset the posts string to be empty
    posts = "";
}


/*
 Sets the status of the page to a new value.
 param status The new status to set.
 */
void Page::setStatus(std::string status)
{
    // Update the status of the page with the provided value
    Page::status = status;
}


/*
 Adds a new line to the page's posts.
 param new_line The content of the new post to add.
 */
void Page::addLineToPosts(std::string new_line)
{
    // Append the new line to the posts string, and a newline
    posts += new_line + "\n";
}
