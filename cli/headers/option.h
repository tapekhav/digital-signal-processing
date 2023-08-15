#ifndef DIGITAL_SIGNAL_PROCESSING_OPTION_H
#define DIGITAL_SIGNAL_PROCESSING_OPTION_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <dirent.h>
#include <getopt.h>
#include <cstring>
#include <vector>


class Option
{
public:
    Option(int argc, char* argv[]);
    ~Option();

    void start();
private:
    void checkConditions();

    bool _flag;
    int _argc;
    char** _argv;
};

#endif //DIGITAL_SIGNAL_PROCESSING_OPTION_H
