#ifndef TRAIN_SYSTEM_SYSTEMELEMENT_H
#define TRAIN_SYSTEM_SYSTEMELEMENT_H

/**
 * A system element to be listed.
 */
class SystemElement {
public:
    /**
     * Create a new SystemElement object.
     */
    SystemElement();

    /**
     * Make the element active.
     */
    void setActive();
    /**
     * Make the element incative.
     */
    void setInactive();

    /**
     * Tells if the element is active.
     */
    bool isActive() const;

private:
    /**
     * Boolean holding the active status of the element.
     */
    bool active;
};


#endif //TRAIN_SYSTEM_SYSTEMELEMENT_H
