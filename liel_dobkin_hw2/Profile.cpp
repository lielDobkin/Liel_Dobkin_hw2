#include "Profile.h"

// Initialize a new profile with a user as the owner
void Profile::init(const User& owner)
{
    _owner = owner;  // Copy owner
    _page.init();    // Initialize page
    _friends.init(); // Initialize friend list
}

// Clear the profile and release any allocated resources
void Profile::clear() {
    _page.clearPage();  // Clear page posts
    _friends.clear();   // Clear the friend list
}

// Get the owner of the profile
User Profile::getOwner() const {
    return _owner;
}

// Set the status on the profile's page
void Profile::setStatus(const std::string& new_status) {
    _page.setStatus(new_status);
}

// Add a post to the profile's page
void Profile::addPostToProfilePage(const std::string& post) {
    _page.addLineToPosts(post);
}

// Add a friend to the profile's friend list
void Profile::addFriend(const User& friend_to_add) {
    _friends.add(friend_to_add);
}

// Get the profile page as a formatted string
std::string Profile::getPage() const {
    std::string page = "Status: " + _page.getStatus() + "\n";
    page += "*******************\n";
    page += "*******************\n";
    page += _page.getPosts();
    return page;
}

// Get the friends' names as a single string separated by commas
std::string Profile::getFriends() const {
    UserNode* current = _friends.get_first();
    std::string friends_list;

    while (current != nullptr) {
        friends_list += current->get_data().getUserName();
        current = current->get_next();
        if (current != nullptr) {
            friends_list += ",";
        }
    }

    return friends_list;
}

// Get friends with the same name length as the owner's name
std::string Profile::getFriendsWithSameNameLength() const {
    size_t owner_name_length = _owner.getUserName().length();
    UserNode* current = _friends.get_first();
    std::string same_length_friends;

    while (current != nullptr) {
        if (current->get_data().getUserName().length() == owner_name_length) {
            same_length_friends += current->get_data().getUserName();
            if (current->get_next() != nullptr) {
                same_length_friends += ",";
            }
        }
        current = current->get_next();
    }

    // Remove the last comma if it exists
    if (!same_length_friends.empty() && same_length_friends.back() == ',') {
        same_length_friends.pop_back();
    }

    return same_length_friends;
}
