#pragma once

#include "Stocznia.hpp"
#include "ObjCounter.hpp"
#include "Statki.hpp"


unsigned int transportujFlota(unsigned int towar) {
    if (towar == 0) return 0; 

    Stocznia stocznia; 
    Stocznia::resetTotalCap(); 
    CountThis<Zaglowiec>::reset();  

    unsigned int transported = 0; 

    while (transported < towar) {
        Statek* statek = stocznia();  
        transported += statek->transportuj(); 
    }

    return CountThis<Zaglowiec>::get(); 
}