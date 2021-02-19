#ifndef VALIDATIONFORMAT_H_
#define VALIDATIONFORMAT_H_

#include <iostream>
#include <string>
#include <sstream>

bool isItADouble (std::string string_test);
double convertirChaineEnDouble (const std::string& p_chaine);
bool isItANumber (std::string string_test);

bool valideLigneCVS (const std::string& p_ligne, std::ostringstream& p_parametres);
bool validerGeom (const std::string& p_geom);
bool valideStationnementGEOJSON (const std::string& p_enregistrement, std::ostringstream& p_attributs);

namespace util 
{
    bool validerPointCardinal(const std::string& p_cardinalite);
}

#endif /* VALIDATIONFORMAT_H_ */
