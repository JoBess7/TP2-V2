#include "Borne.h"
#include "validationFormat.h"
#include <string>
#include <iostream>
#include <sstream>


namespace bornesQuebec
{
    Borne::Borne(std::string p_numBorne, std::string p_coteRue, double p_lectureMetrique, unsigned int p_segmentRue, std::string p_direction, std::string p_nomTopographique):
    m_numBorne(p_numBorne), m_coteRue(p_coteRue), m_lectureMetrique(p_lectureMetrique), m_segmentRue(p_segmentRue), m_direction(p_direction), m_nomTopographique(p_nomTopographique) {}

    std::string Borne::reqNumBorne() const {
        return m_numBorne;
    }
    std::string Borne::reqCoteRue() const {
        return m_coteRue;
    }
    double Borne::reqLectureMetrique() const {
        return m_lectureMetrique;
    }
    unsigned int Borne::reqSegmentRue() const {
        return m_segmentRue;
    }
    std::string Borne::reqDirection() const {
        return m_direction;
    }
    std::string Borne::reqNomTopographique() const {
        return m_nomTopographique;
    }
    void Borne::asgNomTopographique(std::string p_nouveauNomTopographique) {
        m_nomTopographique = p_nouveauNomTopographique;
    }
    std::string Borne::reqBorneFormate() const {
        std::ostringstream os;
        os  << "Numero de la borne      : " << reqNumBorne() << '\n'
            << "Cote de la rue    : " << reqCoteRue() << '\n'
            << "Distance mesuree  : " << reqLectureMetrique() << '\n'
            << "Segment de rue    : " << reqSegmentRue() << '\n'
            << "Direction         : " << reqDirection() << '\n'
            << "Nom topographique : " << reqNomTopographique() << '\n';
        
        std::string borneFormate = os.str();
        return borneFormate;
    }

    bool Borne::estEgal(const Borne& p_borne) {
        return m_numBorne == p_borne.m_numBorne &&
               m_coteRue == p_borne.m_coteRue &&
               m_lectureMetrique == p_borne.m_lectureMetrique &&
               m_segmentRue == p_borne.m_segmentRue &&
               m_direction == p_borne.m_direction &&
               m_nomTopographique == p_borne.m_nomTopographique;
    }
}

bool checkNumBorne(const std::string p_numBorne)
{
    if(p_numBorne == "")
    {
        return false;
    }
    return true;
}

bool checkCoteRue(const std::string p_coteRue)
{
    return util::validerPointCardinal(p_coteRue);
}

bool checkLectureMetrique(const double p_lectureMetrique)
{
    if(p_lectureMetrique < 0)
    {
        return false;
    }
    return true;
}

bool checkSegmentRue(const int p_segmentRue)
{
    if(p_segmentRue < 0)
    {
        return false;
    }
    return true;
}

bool checkDirection(const std::string p_direction)
{
    return util::validerPointCardinal(p_direction);
}

bool checkNomTopographique(const std::string p_nomTopographique)
{
    if(p_nomTopographique == "")
    {
        return false;
    }
    return true;
}

void executeProgramme()
{

    std::string numBorne;
    std::string coteRue;
    double lectureMetrique;
    int segmentRue;
    std::string direction;
    std::string nomTopographique;


    do {
        std::cout << "Entrez un numero de borne valide (string): ";
        std::cin >> numBorne;
    } while(!(checkNumBorne(numBorne)));

    do {
        std::cout << "Entrez un cote de rue valide (direction): ";
        std::cin >> coteRue;
    } while(!(checkCoteRue(coteRue)));

    do {
        std::cout << "Entrez une lecture metrique valide (double): ";
        std::cin >> lectureMetrique;
    } while(!(checkLectureMetrique(lectureMetrique)));

    do {
        std::cout << "Entrez un segment de rue valide (entier): ";
        std::cin >> segmentRue;
    } while(!(checkSegmentRue(segmentRue)));

    do {
        std::cout << "Entrez une direction valide (direction): ";
        std::cin >> direction;
    } while(!(checkDirection(direction)));

    do {
        std::cout << "Entrez un nom topographique valide (string): ";
        std::cin >> nomTopographique;
    } while(!(checkNomTopographique(nomTopographique)));

    bornesQuebec::Borne BorneUsager(numBorne, coteRue, lectureMetrique, segmentRue, direction, nomTopographique);
    std::cout << std::endl << BorneUsager.reqBorneFormate() << std::endl;
}


int main()
{
    executeProgramme();
}