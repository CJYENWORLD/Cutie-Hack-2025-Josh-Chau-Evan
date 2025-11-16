#include <iostream>
#include "Location.h"
#include "app.h"

int main(int argc, char* argv[]) {
    if (argc < 2)
    {
        cout << "unable to run program. " << endl;
        return 1;
    }

    std::string path = argv[1];
    App app;
    app.run(path);

    return 0;
}