#include <gtest/gtest.h>
#include <string>
#include <sstream>
#include <fstream>
#include <cstdio>

// Helper function to execute the program and capture the output
std::string run_program_with_args(const std::string &command, const std::string &input_string) {
    // Creates a command with the format `./convert command "string"`
    std::string full_command = "./convert " + command + " \"" + input_string + "\" > temp_output.txt";
    
    // Executes the command
    std::system(full_command.c_str());
    
    // Reads the output result from the temporary file
    std::ifstream output_file("temp_output.txt");
    std::stringstream output;
    output << output_file.rdbuf();
    output_file.close();

    // Removes the temporary file after reading
    std::remove("temp_output.txt");

    return output.str();
}

// Test to verify the `up` command (converts to uppercase)
TEST(ToupperProgramTest, ConvertsToUppercase) {
    std::string command = "up";
    std::string input_string = "hello world";
    std::string expected_output = "HELLO WORLD\n";
    EXPECT_EQ(run_program_with_args(command, input_string), expected_output);
}

// Test to verify the `down` command (converts to lowercase)
TEST(ToupperProgramTest, ConvertsToLowercase) {
    std::string command = "down";
    std::string input_string = "HELLO @\tWORLD";
    std::string expected_output = "hello @\tworld\n";
    EXPECT_EQ(run_program_with_args(command, input_string), expected_output);
}

// Test to check that the `up` command does not alter characters already in uppercase
TEST(ToupperProgramTest, RetainsUppercaseWhenUp) {
    std::string command = "up";
    std::string input_string = "HELLO";
    std::string expected_output = "HELLO\n";
    EXPECT_EQ(run_program_with_args(command, input_string), expected_output);
}

// Test to check that the `down` command does not alter characters already in lowercase
TEST(ToupperProgramTest, RetainsLowercaseWhenDown) {
    std::string command = "down";
    std::string input_string = "hello";
    std::string expected_output = "hello\n";
    EXPECT_EQ(run_program_with_args(command, input_string), expected_output);
}

// Test for mixed characters and numbers (verifies that only letters are altered)
TEST(ToupperProgramTest, MixedCharacters) {
    std::string command_up = "up";
    std::string input_string = "Hello123!";
    std::string expected_output_up = "HELLO123!\n";
    EXPECT_EQ(run_program_with_args(command_up, input_string), expected_output_up);

    std::string command_down = "down";
    std::string expected_output_down = "hello123!\n";
    EXPECT_EQ(run_program_with_args(command_down, input_string), expected_output_down);
}

// test with args and params
TEST(ToupperProgramTest, TestWithArgs) {
    std::string command = "extract";
    std::string input_string = "hello world";
    std::string expected_output = "HELLO WORLD\n";
    EXPECT_EQ(run_program_with_args(command, input_string), expected_output);
}