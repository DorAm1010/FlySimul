#ifndef FLYSIMUL_COMMAND_H
#define FLYSIMUL_COMMAND_H

/**
 * Interface for classes that handle a single command.
 */
class Command {
public:
    virtual int execute()=0;
};
#endif //FLYSIM_COMMAND_H