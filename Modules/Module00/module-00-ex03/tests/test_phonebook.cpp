#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include "PhoneBook.hpp"
#include "Contact.hpp"

TEST_CASE("AddContact", "[PhoneBook]") {
    PhoneBook pb;
    pb.add("John", "Doe", "1234567890");
    REQUIRE(pb.getContactsSize() == 1);
}

TEST_CASE("SearchContact", "[PhoneBook]") {
    PhoneBook pb;
    pb.add("John", "Doe", "1234567890");
    pb.search();
    // Add assertions to verify the search results
}

TEST_CASE("RemoveContactByIndex", "[PhoneBook]") {
    PhoneBook pb;
    pb.add("John", "Doe", "1234567890");
    pb.remove(0);
    REQUIRE(pb.getContactsSize() == 0);
}

TEST_CASE("RemoveContactByPhoneNumber", "[PhoneBook]") {
    PhoneBook pb;
    pb.add("John", "Doe", "1234567890");
    pb.remove("1234567890");
    REQUIRE(pb.getContactsSize() == 0);
}

TEST_CASE("BookmarkContact", "[PhoneBook]") {
    PhoneBook pb;
    // Add test case for bookmarking a contact
}