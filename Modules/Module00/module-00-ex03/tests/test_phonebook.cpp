#include "gtest/gtest.h"
#include "PhoneBook.hpp"
#include "Contact.hpp"

TEST(PhoneBookTest, AddContact) {
    PhoneBook pb;
    pb.add("John", "Doe", "1234567890", "Johnny");
    ASSERT_EQ(pb.getContactsSize(), 1);
}

TEST(PhoneBookTest, SearchContact) {
    PhoneBook pb;
    pb.add("John", "Doe", "1234567890", "Johnny");
    pb.search();
    // Add assertions to verify the search results
}

TEST(PhoneBookTest, RemoveContactByIndex) {
    PhoneBook pb;
    pb.add("John", "Doe", "1234567890", "Johnny");
    pb.remove(0);
    ASSERT_EQ(pb.getContactsSize(), 0);
}

TEST(PhoneBookTest, RemoveContactByPhoneNumber) {
    PhoneBook pb;
    pb.add("John", "Doe", "1234567890", "Johnny");
    pb.remove("1234567890");
    ASSERT_EQ(pb.getContactsSize(), 0);
}

TEST(PhoneBookTest, BookmarkContact) {
    PhoneBook pb;
    pb.add("John", "Doe", "1234567890", "Johnny");
    pb.bookmark(0);
    // Add assertions to verify the bookmark status
}

TEST(PhoneBookTest, ListBookmarks) {
    PhoneBook pb;
    pb.add("John", "Doe", "1234567890", "Johnny");
    pb.bookmark(0);
    pb.listBookmarks();
    // Add assertions to verify the bookmarked contacts
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
