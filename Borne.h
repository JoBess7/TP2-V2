#ifndef BORNE_H
#define BORNE_H


#include "validationFormat.h"
#include <string>

namespace bornesQuebec {
    class Borne
    {
        private:
            std::string m_numBorne;
            std::string m_coteRue;
            double m_lectureMetrique;
            unsigned int m_segmentRue;
            std::string m_direction;
            std::string m_nomTopographique;

        public:
            Borne(std::string p_numBorne, std::string p_coteRue, double p_lectureMetrique, 
                unsigned int p_segmentRue, std::string p_direction, std::string p_nomTopographique);
            std::string reqNumBorne() const;
            std::string reqCoteRue() const;
            double reqLectureMetrique() const;
            unsigned int reqSegmentRue() const;
            std::string reqDirection() const;
            std::string reqNomTopographique() const;
            void asgNomTopographique(std::string nouveauNomTopographique);
            std::string reqBorneFormate() const;
            bool estEgal(const Borne& p_borne);
    };
}

bool checkNumBorne(const std::string p_numBorne);
bool checkCoteRue(const std::string p_coteRue);
bool checkLectureMetrique(const double p_lectureMetrique);
bool checkSegmentRue(const int p_segmentRue);
bool checkDirection(const std::string p_direction);
bool checkNomTopographique(const std::string p_nomTopographique);

#endif