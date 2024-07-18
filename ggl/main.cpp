#include "Template2.cpp"

int main() {
    Template temp("The %dir% not found");
    temp.Register("dir", "%user%'s %path%");
    temp.Register("user", "bob");
    temp.Query();  // "Error" due to "%path" is not registered
    temp.Register("path", "home/%user%");
    temp.Query();  // "The bob's home/bob not found"

    Template temp2("The directory %dir% of owner %user%");
    temp2.Register("dir", "/home/%user%");
    temp2.Query();  // "Error" due to "user" is not registered
    temp2.Register("user", "bob");
    temp2.Query();  // "The directory /home/bob of owner bob"
    temp2.Register("user", "amy");
    temp2.Query();  // "The directory /home/amy of owner amy"
    temp2.Register("dir", "home");
    temp2.Query();  // "The directory home of owner amy"

    return 0;
}
