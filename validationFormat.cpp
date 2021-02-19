#include "validationFormat.h"
#include "Borne.h"
#include <string>
#include <array>
#include <iostream>
#include <sstream>
#include <cctype>

namespace util 
{
    bool validerPointCardinal(const std::string& p_cardinalite)
    {
        bool trouve = false;
        std::string listeValeurs[] = {"Nord", "Sud", "Est", "Ouest", "", "null"};
        for(unsigned int i = 0; i < 6; i++)
        {
            if(p_cardinalite == listeValeurs[i])
            {
                trouve = true;
            }
        }
        return trouve;
    }
}

bool isItADouble (std::string string_test)
{
  bool checkPoint = false;
  bool checkDigit = true;
  for (int i = 0; i < string_test.length (); i++)
    {
      if (string_test[i] == '.' || string_test[i] == ',')
        {
          checkPoint = true;
        }
      if ((string_test[i] != '.') && (string_test[i] != ',') && (string_test[i] != '-') && !(isdigit (string_test[i])))
        {
          checkDigit = false;
        }
    }
  return (checkPoint && checkDigit);
}

double convertirChaineEnDouble (const std::string& p_chaine)
{
  std::string chaineFormate = p_chaine;
  //on remplace la , en .
  for (unsigned int i = 0; i < chaineFormate.length (); i++)
    {
      if (chaineFormate[i] == ',')
        {
          chaineFormate[i] = '.';
        }
    }
  std::istringstream is (chaineFormate);
  double chaineConvertiEnDouble;
  is >> chaineConvertiEnDouble;

  return chaineConvertiEnDouble;
}

bool isItANumber (std::string string_test)
{
  bool check = true;
  for (unsigned int i = 0; i < string_test.length (); i++)
    {
      if (!(isdigit (string_test[i])) && string_test[i] != '.')
        {
          check = false;
        }
    }
  return check;
}

bool
valideLigneCVS (const std::string& p_ligne, std::ostringstream& p_parametres)
{
  bool check_CVS = false;
  const int size_ligne = p_ligne.length ();
  /* Vérifie tout d'abord si le nombre de séparateurs '|' est conforme au format CVS fournit */
  bool check_separateurs = false;
  int nb_separateurs = 0;

  for (unsigned int i = 0; i < size_ligne; i++)
    {
      if (p_ligne[i] == '|')
        {
          nb_separateurs++;
          if (nb_separateurs == 8)
            {
              check_separateurs = true;
            }
        }
    }

  if (!(check_separateurs))
    {
      return false;
    }


  std::string copy = p_ligne;
  std::string ID, orientation, lect_met, segment_ru, direction, nom_topog, no_borne, longitude, latitude;
  bool checkID = false;
  bool checkOrientation = false;
  bool checkLECT_MET = false;
  bool checkSEGMENT_RU = false;
  bool checkDirection = false;
  bool checkNom_topog = false;
  bool checkNo_Borne = false;
  bool checkLongitutde = false;
  bool checkLatitutde = false;

  int it1 = copy.find ('|');
  for (unsigned int k = 0; k < it1; k++)
    {
      ID += copy[k];
    }
  copy.erase (0, it1 + 1);

  int it2 = copy.find ('|');
  for (unsigned int j = 0; j < it2; j++)
    {
      orientation += copy[j];
    }
  copy.erase (0, it2 + 1);

  int it3 = copy.find ('|');
  for (unsigned int g = 0; g < it3; g++)
    {
      lect_met += copy[g];
    }
  copy.erase (0, it3 + 1);

  int it4 = copy.find ('|');
  for (unsigned int g = 0; g < it4; g++)
    {
      segment_ru += copy[g];
    }
  copy.erase (0, it4 + 1);

  int it5 = copy.find ('|');
  for (unsigned int g = 0; g < it5; g++)
    {
      direction += copy[g];
    }
  copy.erase (0, it5 + 1);

  int it6 = copy.find ('|');
  for (unsigned int g = 0; g < it6; g++)
    {
      nom_topog += copy[g];
    }
  copy.erase (0, it6 + 1);

  int it7 = copy.find ('|');
  for (unsigned int g = 0; g < it7; g++)
    {
      no_borne += copy[g];
    }
  copy.erase (0, it7 + 1);

  int it8 = copy.find ('|');
  for (unsigned int g = 0; g < it8; g++)
    {
      longitude += copy[g];
    }
  copy.erase (0, it8 + 1);

  latitude = copy;

  bool print_info = false;

  if (ID == "")
    {
      return false;
    }

  if (print_info)
    {
      std::cout << "ID: " << ID << std::endl;
      std::cout << "Orientation: " << orientation << std::endl;
      std::cout << "Lect_met: " << lect_met << std::endl;
      std::cout << "Segment_ru: " << segment_ru << std::endl;
      std::cout << "Direction: " << direction << std::endl;
      std::cout << "Nom_topog: " << nom_topog << std::endl;
      std::cout << "No_borne: " << no_borne << std::endl;
      std::cout << "Longitude: " << longitude << std::endl;
      std::cout << "Latitude: " << latitude << std::endl;
    }

  std::string orientationList[5] = {"Sud", "Ouest", "Est", "Nord", ""};
  if (isItANumber (ID)) /* ID */
    {
      checkID = true;
    }
  for (int i = 0; i < 5; i++) /* Orientation */
    {
      if (orientation == orientationList[i])
        {
          checkOrientation = true;
        }
    }
  if (isItANumber (lect_met) || (lect_met == "")) /* LECT_MET */
    {
      checkLECT_MET = true;
    }
  if (isItANumber (segment_ru) || (segment_ru == "")) /* SEGMENT_RU */
    {
      checkSEGMENT_RU = true;
    };
  if (isItADouble (longitude)) /* Longitude */
    {
      checkLongitutde = true;
    }
  if (isItADouble (latitude)) /* Latitude */
    {
      checkLatitutde = true;
    }

  if (check_separateurs && checkID && checkOrientation && checkLECT_MET && checkSEGMENT_RU && checkLongitutde && checkLatitutde)
    {
      p_parametres << stoi (ID) << "," << orientation << "," << convertirChaineEnDouble (lect_met) << "," << segment_ru << "," << direction << "," << nom_topog << "," << no_borne << "," << longitude << "," << latitude;
      return true;
    }
  else
    {
      return false;
    }
}

bool
validerGeom (const std::string& p_geom)
{
  if (p_geom.find ("POINT") == -1)
    {
      return false;
    }
  /* Placing into copy ONLY the latitude and the longitude */
  std::string copy = p_geom;
  int first_par = copy.find ('(');
  int second_par = copy.find (')');
  copy.erase (0, first_par + 1);
  copy.resize (copy.size () - 1);

  /* Placing latitude and longitude into string objects and confirming they're doubles' */
  int space = copy.find (' ');
  if (space == -1)
    {
      return false;
    }
  std::string long_string;
  for (int i = 0; i < space; i++)
    {
      long_string += copy[i];
    }
  copy.erase (0, space + 1);
  std::string lat_string = copy;

  if (isItADouble (long_string) && isItADouble (lat_string) && long_string != " " && lat_string != " ")
    {
      return true;
    }
  return false;


}

bool
valideStationnementGEOJSON (const std::string& p_enregistrement, std::ostringstream& p_attributs)
{
  int par = 0;
  bool checkSep = false;
  for (int i = 0; i < p_enregistrement.length (); i++)
    {
      if (p_enregistrement[i] == '{' || p_enregistrement[i] == '}')
        {
          par++;
          if (par == 6)
            {
              checkSep = true;
            }
        }
    }
  if (!(checkSep))
    {
      return false;
    }

  std::string copy = p_enregistrement;
  std::string ID, orientation, lect_met, segment_ru, direction, nom_topog, no_borne, longitude, latitude;
  std::string GEOM, no_civic, ID_VOIE_PUB;
  bool checkID = false;
  bool checkOrientation = false;
  bool checkLECT_MET = false;
  bool checkSEGMENT_RU = false;
  bool checkDirection = false;
  bool checkNom_topog = false;
  bool checkNo_Borne = false;
  bool checkLongitude = false;
  bool checkLatitutde = false;
  bool checkGEOM = false;

  int findType = copy.find ("type");
  int findGeo = copy.find ("geometry");
  int findCoordinates = copy.find ("coordinates");
  int findProperties = copy.find ("properties");
  if (findType == -1 || findGeo == -1 || findCoordinates == -1 || findProperties == -1)
    {
      return false;
    }

  int findID = copy.find ("ID");
  int findCOTE_RUE = copy.find ("COTE_RUE");
  int findLECT_MET = copy.find ("LECT_MET");
  int findSEGMENT_RUE = copy.find ("SEGMENT_RU");
  int findDIRECTION = copy.find ("DIRECTION");
  int findNOM_TOPOG = copy.find ("NOM_TOPOG");
  int findNO_BORNE = copy.find ("NO_BORNE");
  int findNO_CIVIQ = copy.find ("NO_CIVIQ");
  int findID_VOIE_PUB = copy.find ("ID_VOIE_PUB");
  int findGEOM = copy.find ("GEOM");
  int findPOINT = copy.find ("POINT");
  if (findID == -1 || findCOTE_RUE == -1 || findLECT_MET == -1 || findSEGMENT_RUE == -1 ||
      findDIRECTION == -1 || findNOM_TOPOG == -1 || findNO_BORNE == -1 || findNO_CIVIQ == -1 ||
      findID_VOIE_PUB == -1 || findGEOM == -1 || findPOINT == -1)
    {
      return false;
    }

  ID.assign (copy, findID + 7, copy.find ('\"', findID + 7) - (findID + 7));
  orientation.assign (copy, findCOTE_RUE + 13, copy.find ('\"', findCOTE_RUE + 13) - (findCOTE_RUE + 13));
  lect_met.assign (copy, findLECT_MET + 13, copy.find ('\"', findLECT_MET + 13) - (findLECT_MET + 13));
  segment_ru.assign (copy, findSEGMENT_RUE + 15, copy.find ('\"', findSEGMENT_RUE + 15) - (findSEGMENT_RUE + 15));
  direction.assign (copy, findDIRECTION + 14, copy.find ('\"', findDIRECTION + 14) - (findDIRECTION + 14));
  nom_topog.assign (copy, findNOM_TOPOG + 14, copy.find ('\"', findNOM_TOPOG + 14) - (findNOM_TOPOG + 14));
  no_borne.assign (copy, findNO_BORNE + 13, copy.find ('\"', findNO_BORNE + 13) - (findNO_BORNE + 13));
  GEOM.assign (copy, findGEOM + 9, copy.find ('\"', findGEOM + 9) - (findGEOM + 9));
  bool print_info = false;
  if (print_info)
    {
      std::cout << "ID: " << ID << std::endl;
      std::cout << "Orientation: " << orientation << std::endl;
      std::cout << "Lect_met: " << lect_met << std::endl;
      std::cout << "Segment_ru: " << segment_ru << std::endl;
      std::cout << "Direction: " << direction << std::endl;
      std::cout << "Nom_topog: " << nom_topog << std::endl;
      std::cout << "No_borne: " << no_borne << std::endl;
      std::cout << "geom: " << GEOM << std::endl;
    }

  std::string listVal[] = {ID, orientation, lect_met, segment_ru, direction, nom_topog, no_borne, GEOM};
  if (ID == "")
    {
      return false;
    }
  for (unsigned int i = 0; i < 8; i++)
    {
      for (unsigned int k = 0; k < 2; k++)
        if ((listVal[i])[k] == 'u' && (listVal[i])[k + 1] == 'l')
          {
            listVal[i].assign ("null");
          }
    }


  if (validerGeom (GEOM))
    {
      checkGEOM = true;
    }
  std::string orientationList[5] = {"Sud", "Ouest", "Est", "Nord", ""};
  if (isItANumber (ID)) /* ID */
    {
      checkID = true;
    }
  for (int i = 0; i < 5; i++) /* Orientation */
    {
      if (orientation == orientationList[i])
        {
          checkOrientation = true;
        }
    }
  if (isItANumber (lect_met) || (lect_met == "")) /* LECT_MET */
    {
      checkLECT_MET = true;
    }
  if (isItANumber (segment_ru) || (segment_ru == "")) /* SEGMENT_RU */
    {
      checkSEGMENT_RU = true;
    };


  if (checkGEOM && checkSep && checkID && checkOrientation && checkLECT_MET && checkSEGMENT_RU)
    {
      p_attributs << stoi (listVal[0]) << "," << listVal[1] << "," << convertirChaineEnDouble (listVal[2]) << "," << listVal[3] << "," << listVal[4] << "," << listVal[5] << "," << listVal[6] << "," << listVal[7];
      return true;
    }
  else
    {
      return false;
    }
}