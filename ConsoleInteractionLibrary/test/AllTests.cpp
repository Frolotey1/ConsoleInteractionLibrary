#define BOOST_TEST_MODULE "AllTests"
#define BOOST_TEST_NO_MAIN
#include <boost/test/included/unit_test.hpp>
#include <boost/test/data/test_case.hpp>
#include <boost/test/unit_test.hpp>

#include "../src/Registration.h"
#include "../src/Authorization.h"
#include "../src/ChangeUser.h"
#include "../src/DeleteUser.h"

void clean_database() {
    if (std::filesystem::exists("Database.txt"))
        std::filesystem::remove("Database.txt");
}

void create_test_user(const std::string& name, const std::string& password) {
    Registration reg;
    reg.write_to_database(name, password);
}

BOOST_AUTO_TEST_SUITE(RegistrationTests)

BOOST_AUTO_TEST_CASE(CheckData_ValidData_ReturnsTrue) {
    Registration reg;
    bool result = reg.check_data("valid123", "pass!@#123");
    BOOST_CHECK_EQUAL(result, true);
}

BOOST_AUTO_TEST_CASE(CheckData_EmptyName_ReturnsFalse) {
    Registration reg;
    bool result = reg.check_data("", "pass!@#123");
    BOOST_CHECK_EQUAL(result, false);
}

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(AuthorizationTests)

void clean_database() {
    if (std::filesystem::exists("Database.txt"))
        std::filesystem::remove("Database.txt");
}

void create_test_user(const std::string& name, const std::string& password) {
    Registration reg;
    reg.write_to_database(name, password);
}

BOOST_AUTO_TEST_CASE(GetFromDatabase_ValidData_ReturnsCorrectData) {
    clean_database();
    create_test_user("example", "example!@#1234");

    Authorization authorization;
    auto [name, password] = authorization.get_from_database("example", "example!@#1234");

    BOOST_CHECK_EQUAL(name, "example");
    BOOST_CHECK_EQUAL(password, "example!@#1234");

    clean_database();
}

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(ChangeUserTests)

bool user_exists_in_db(const std::string& name, const std::string& password) {
    std::ifstream file("Database.txt");
    std::string db_name, db_password;
    while (file >> db_name >> db_password) {
        if (db_name == name && db_password == password) {
            return true;
        }
    }
    return false;
}

std::pair<std::string, std::string> get_user_from_db(const std::string& name) {
    std::ifstream file("Database.txt");
    std::string db_name, db_password;
    while (file >> db_name >> db_password) {
        if (db_name == name) {
            return {db_name, db_password};
        }
    }
    return {"", ""};
}

BOOST_AUTO_TEST_CASE(ChangeUser_ValidData_ChangesSuccessfully) {
    clean_database();
    create_test_user("olduser", "oldpass!@#123");

    ChangeUser changer;
    changer.change_user_name = "olduser";
    changer.change_user_password = "oldpass!@#123";
    changer.new_name = "newuser";
    changer.new_password = "newpass!@#456";

    auto [old_name, old_password] = changer.get_from_database_and_change(
        changer.change_user_name,
        changer.change_user_password
        );

    bool old_exists = user_exists_in_db("olduser", "oldpass!@#123");
    BOOST_CHECK_EQUAL(old_exists, false);

    bool new_exists = user_exists_in_db("newuser", "newpass!@#456");
    BOOST_CHECK_EQUAL(new_exists, true);

    BOOST_CHECK_EQUAL(old_name, "olduser");
    BOOST_CHECK_EQUAL(old_password, "oldpass!@#123");

    clean_database();
}

BOOST_AUTO_TEST_CASE(ChangeUser_InvalidOldPassword_ReturnsEmpty) {
    clean_database();
    create_test_user("olduser", "oldpass!@#123");

    ChangeUser changer;
    changer.change_user_name = "olduser";
    changer.change_user_password = "wrongpassword";
    changer.new_name = "newuser";
    changer.new_password = "newpass!@#456";

    auto [old_name, old_password] = changer.get_from_database_and_change(
        changer.change_user_name,
        changer.change_user_password
        );

    bool old_exists = user_exists_in_db("olduser", "oldpass!@#123");
    BOOST_CHECK_EQUAL(old_exists, true);

    bool new_exists = user_exists_in_db("newuser", "newpass!@#456");
    BOOST_CHECK_EQUAL(new_exists, false);

    BOOST_CHECK_EQUAL(old_name.empty(), true);
    BOOST_CHECK_EQUAL(old_password.empty(), true);

    clean_database();
}

BOOST_AUTO_TEST_CASE(ChangeUser_NonExistingUser_ReturnsEmpty) {
    clean_database();

    ChangeUser changer;
    changer.change_user_name = "nonexistent";
    changer.change_user_password = "somepass!@#123";
    changer.new_name = "newuser";
    changer.new_password = "newpass!@#456";

    auto [old_name, old_password] = changer.get_from_database_and_change(
        changer.change_user_name,
        changer.change_user_password
        );

    BOOST_CHECK_EQUAL(old_name.empty(), true);
    BOOST_CHECK_EQUAL(old_password.empty(), true);

    clean_database();
}

BOOST_AUTO_TEST_CASE(ChangeUser_OnlyPasswordChanges_Correctly) {
    clean_database();
    create_test_user("user", "oldpass!@#123");

    ChangeUser changer;
    changer.change_user_name = "user";
    changer.change_user_password = "oldpass!@#123";
    changer.new_name = "user";
    changer.new_password = "newpass!@#456";

    auto [old_name, old_password] = changer.get_from_database_and_change(
        changer.change_user_name,
        changer.change_user_password
        );

    bool old_password_works = user_exists_in_db("user", "oldpass!@#123");
    BOOST_CHECK_EQUAL(old_password_works, false);

    bool new_password_works = user_exists_in_db("user", "newpass!@#456");
    BOOST_CHECK_EQUAL(new_password_works, true);

    clean_database();
}

BOOST_AUTO_TEST_CASE(ChangeUser_EmptyDatabase_ReturnsEmpty) {
    clean_database();

    ChangeUser changer;
    changer.change_user_name = "anyuser";
    changer.change_user_password = "anypass!@#123";
    changer.new_name = "newuser";
    changer.new_password = "newpass!@#456";

    auto [old_name, old_password] = changer.get_from_database_and_change(
        changer.change_user_name,
        changer.change_user_password
        );

    BOOST_CHECK_EQUAL(old_name.empty(), true);
    BOOST_CHECK_EQUAL(old_password.empty(), true);

    clean_database();
}

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(DeleteUserTests)

bool user_exists_in_db(const std::string& name) {
    std::ifstream file("Database.txt");
    std::string db_name, db_password;
    while (file >> db_name >> db_password) {
        if (db_name == name) {
            return true;
        }
    }
    return false;
}

BOOST_AUTO_TEST_CASE(DeleteUser_ExistingUser_DeletesSuccessfully) {
    clean_database();
    create_test_user("todelete", "pass!@#123");
    create_test_user("keepuser", "keep!@#456");

    DeleteUser deleter;
    bool result = deleter.delete_user("todelete");

    BOOST_CHECK_EQUAL(result, true);
    BOOST_CHECK_EQUAL(user_exists_in_db("todelete"), false);
    BOOST_CHECK_EQUAL(user_exists_in_db("keepuser"), true);

    clean_database();
}

BOOST_AUTO_TEST_CASE(DeleteUser_NonExistingUser_ReturnsFalse) {
    clean_database();
    create_test_user("existinguser", "pass!@#123");

    DeleteUser deleter;
    bool result = deleter.delete_user("nonexistent");

    BOOST_CHECK_EQUAL(result, false);
    BOOST_CHECK_EQUAL(user_exists_in_db("existinguser"), true);

    clean_database();
}

BOOST_AUTO_TEST_CASE(DeleteUser_EmptyDatabase_ReturnsFalse) {
    clean_database();

    DeleteUser deleter;
    bool result = deleter.delete_user("anyuser");

    BOOST_CHECK_EQUAL(result, false);
}

BOOST_AUTO_TEST_CASE(DeleteUser_LastUser_DeletesAndDatabaseEmpty) {
    clean_database();
    create_test_user("onlyuser", "pass!@#123");

    DeleteUser deleter;
    bool result = deleter.delete_user("onlyuser");

    BOOST_CHECK_EQUAL(result, true);
    BOOST_CHECK_EQUAL(user_exists_in_db("onlyuser"), false);

    std::ifstream file("Database.txt");
    bool file_empty = file.peek() == std::ifstream::traits_type::eof();
    BOOST_CHECK_EQUAL(file_empty, true);

    clean_database();
}

BOOST_AUTO_TEST_CASE(DeleteUser_MultipleUsers_DeletesOnlyCorrectOne) {
    clean_database();
    create_test_user("alice", "alice!@#123");
    create_test_user("bob", "bob!@#456");
    create_test_user("charlie", "charlie!@#789");

    DeleteUser deleter;
    bool result = deleter.delete_user("bob");

    BOOST_CHECK_EQUAL(result, true);
    BOOST_CHECK_EQUAL(user_exists_in_db("alice"), true);
    BOOST_CHECK_EQUAL(user_exists_in_db("bob"), false);
    BOOST_CHECK_EQUAL(user_exists_in_db("charlie"), true);

    clean_database();
}

BOOST_AUTO_TEST_CASE(DeleteUser_CaseSensitive_ExactMatchRequired) {
    clean_database();
    create_test_user("Alice", "alice!@#123");

    DeleteUser deleter;
    bool result = deleter.delete_user("alice");

    BOOST_CHECK_EQUAL(result, false);
    BOOST_CHECK_EQUAL(user_exists_in_db("Alice"), true);

    clean_database();
}

BOOST_AUTO_TEST_SUITE_END()
