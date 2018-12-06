#ifndef TRAIN_SYSTEM_SYSTEMELEMENT_H
#define TRAIN_SYSTEM_SYSTEMELEMENT_H

class SystemElement {
public:
    SystemElement();

    void setActive();
    void setInactive();

    bool isActive();

private:
    bool active;
};


#endif //TRAIN_SYSTEM_SYSTEMELEMENT_H
