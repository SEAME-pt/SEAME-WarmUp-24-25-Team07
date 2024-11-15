#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include "PhoneBook.hpp"
#include "Contact.hpp"

TEST_CASE("AddContact", "[PhoneBook]") {
    std::cout << "AddContact" << std::endl;
	PhoneBook pb;
    pb.add("John", "Doe", "1234567890");
    REQUIRE(pb.getContactsSize() == 1);
}

TEST_CASE("AddMultipleContacts", "[PhoneBook]") {
    std::cout << "AddMultipleContacts" << std::endl;
	PhoneBook pb;
    pb.add("John", "Doe", "1234567890");
    pb.add("Jane", "Doe", "0987654321");
    REQUIRE(pb.getContactsSize() == 2);
}

TEST_CASE("AddDuplicateContact", "[PhoneBook]") {
    std::cout << "AddDuplicateContact" << std::endl;
	PhoneBook pb;
    pb.add("John", "Doe", "1234567890");
    pb.add("John", "Doe", "1234567890");
    REQUIRE(pb.getContactsSize() == 1);
}

TEST_CASE("SearchContact", "[PhoneBook]") {
    std::cout << "SearchContact" << std::endl;
	PhoneBook pb;
    pb.add("John", "Doe", "1234567890");
    pb.add("Jane", "Doe", "0987654321");

    std::streambuf* orig = std::cin.rdbuf();
    std::istringstream input("s\n0\nq\n");
    std::cin.rdbuf(input.rdbuf());

    std::ostringstream output;
    std::streambuf* origOut = std::cout.rdbuf();
    std::cout.rdbuf(output.rdbuf());

    pb.search();

    std::cin.rdbuf(orig);
    std::cout.rdbuf(origOut);

    std::string expectedOutput = R"(
  Name    :  "Jane"
  Nickname      :  "Doe"
  Phone Number  :  "0987654321"
  Bookmark      :  "No"

)";
    REQUIRE(output.str().find(expectedOutput) != std::string::npos);
}

TEST_CASE("RemoveContactByIndex", "[PhoneBook]") {
    std::cout << "RemoveContactByIndex" << std::endl;
	PhoneBook pb;
    pb.add("John", "Doe", "1234567890");
    pb.remove(0);
    REQUIRE(pb.getContactsSize() == 0);
}

TEST_CASE("RemoveContactByPhoneNumber", "[PhoneBook]") {
    std::cout << "RemoveContactByPhoneNumber" << std::endl;
	PhoneBook pb;
    pb.add("John", "Doe", "1234567890");
    pb.remove("1234567890");
    REQUIRE(pb.getContactsSize() == 0);
}

TEST_CASE("SearchNonExistentContact", "[PhoneBook]") {
    std::cout << "SearchNonExistentContact" << std::endl;
	PhoneBook pb;
    pb.add("John", "Doe", "1234567890");

    std::streambuf* orig = std::cin.rdbuf();
    std::istringstream input("s\n1\n");
    std::cin.rdbuf(input.rdbuf());

    std::ostringstream output;
    std::streambuf* origOut = std::cout.rdbuf();
    std::cout.rdbuf(output.rdbuf());

    pb.search();

    std::cin.rdbuf(orig);
    std::cout.rdbuf(origOut);
    std::string expectedOutput = R"(██████  NO CONTACT AT INDEX 1  ██████████████████████)";
    REQUIRE(output.str().find(expectedOutput) != std::string::npos);
}

TEST_CASE("RemoveNonExistentContactByIndex", "[PhoneBook]") {
    std::cout << "RemoveNonExistentContactByIndex" << std::endl;
	PhoneBook pb;
    pb.add("John", "Doe", "1234567890");
    pb.remove(1);
    REQUIRE(pb.getContactsSize() == 1);
}

TEST_CASE("RemoveNonExistentContactByPhoneNumber", "[PhoneBook]") {
    std::cout << "RemoveNonExistentContactByPhoneNumber" << std::endl;
	PhoneBook pb;
    pb.add("John", "Doe", "1234567890");
    pb.remove("0987654321");
    REQUIRE(pb.getContactsSize() == 1);
}

TEST_CASE("ClearAllContacts", "[PhoneBook]") {
    std::cout << "ClearAllContacts" << std::endl;
	PhoneBook pb;
    pb.add("John", "Doe", "1234567890");
    pb.add("Jane", "Doe", "0987654321");
    pb.remove(0);
    pb.remove(0);
    REQUIRE(pb.getContactsSize() == 0);
}

TEST_CASE("BookmarkContact", "[PhoneBook]") {
    std::cout << "BookmarkContact" << std::endl;
	PhoneBook pb;
    pb.add("John", "Doe", "1234567890");
    pb.add("Jane", "Doe", "0987654321");

    pb.bookmark(0);

    std::ostringstream output;
    std::streambuf* origOut = std::cout.rdbuf();
    std::cout.rdbuf(output.rdbuf());

    pb.bookmark(0);

    std::cout.rdbuf(origOut);

    std::string expectedOutput = "\n██████  CONTACT BOOKMARKED  ██████████████████████████\n";
    REQUIRE(output.str().find(expectedOutput) != std::string::npos);
}

	

