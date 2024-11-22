#pragma once
#include "User.h"
#include "UserList.h"
#include "Page.h"
#include <string>

/**
 This class represents a social media profile.
 A profile contains information about the owner, a Page for posts and status,
 and a list of friends.
 */
class Profile
{
public:
    /*
     Initializes a new profile for a given user.
     param owner The user who owns this profile.
     */
    void init(const User& owner);

    /*
     Clears all data associated with this profile.
    */
    void clear();

    /*
     Retrieves the owner of this profile.
     return A copy of the User object representing the owner of the profile.
     */
    User getOwner() const;

    /*
     Sets a new status for the profile's page.
     param new_status The new status string to set for the page.
     */
    void setStatus(const std::string& new_status);

    /*
     Adds a new post to the profile's page.
     param post The content of the post to add.
     */
    void addPostToProfilePage(const std::string& post);

    /**
     Adds a new friend to the profile's friend list.
     param friend_to_add The User object representing the friend to add.
     */
    void addFriend(const User& friend_to_add);

    /*
      Retrieves the current page contents of the profile, including status and posts.
      return A formatted string representing the profile's page.
     */
    std::string getPage() const;

    /*
     Retrieves a list of friends associated with the profile.
     return A comma-separated string of friends' usernames.
     */
    std::string getFriends() const;

    /*
     Retrieves a list of friends whose usernames have the same length as the profile owner's username.
     return a string of matching friends' usernames.
     */
    std::string getFriendsWithSameNameLength() const;

private:
    //--fields--
    User _owner; // The user who owns the profile.
    Page _page; // The page associated with the profile, containing status and posts.
    UserList _friends; // The list of friends associated with the profile.
};
