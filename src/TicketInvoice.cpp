#include "TicketInvoice.h"

using namespace std;

TicketInvoice::TicketInvoice(Passenger* p, Trip* t) {
    this->passengerName = p->getName();
    this->sourceName = t->getSource()->getName();
    this->departureDate = t->getDepartureDate().getDateString();
    this->destName = t->getDest()->getName();
    this->arrivalDate = t->getArrivalDate().getDateString();
    this->price = 0;
}

const string TicketInvoice::getPassengerName() const {
    return passengerName;
}

const string TicketInvoice::getSourceName() const {
    return sourceName;
}

const string TicketInvoice::getDestName() const {
    return destName;
}

const string TicketInvoice::getPriceString() const {
    string priceString = to_string(price);
    priceString.insert(priceString.end()-2, ',');
    return priceString;
}

const uint TicketInvoice::getPrice() const {
    return price;
}

void TicketInvoice::setPrice(uint price) {
    this->price = price;
}

ostream & operator<<(ostream &os, TicketInvoice &in) {
    os << "\\\\\\\\\\\\\\\\\\CP - COMBOIOS DE PORTUGAL/////////" << endl;
    os << "Nome do passageiro: " << in.passengerName << endl;
    os << in.sourceName << " -> " << in.destName << endl;
    os << "Partida: " << in.departureDate << endl;
    os << "Chegada: " << in.arrivalDate << endl;
    os << "Preco: " << in.getPriceString() << " euros";
    return os;
}
