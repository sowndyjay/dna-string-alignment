// Copyright 2025 Sowndaryan J, John Wesley Agojo
#define BOOST_TEST_MODULE EDistanceTests
#include <boost/test/included/unit_test.hpp>
#include "EDistance.hpp"
#include <iostream>
#include <sstream>

BOOST_AUTO_TEST_CASE(ValidConstructor) {
    std::string s1 = "ACGT";
    std::string s2 = "ACGT";
    EDistance ed(s1, s2);
    BOOST_CHECK(true);
}

// BOOST_AUTO_TEST_CASE(InvalidConstructor) {
//     std::string s1 = "ACGTX";
//     std::string s2 = "ACGT";

// }
BOOST_AUTO_TEST_CASE(Min3Function) {
    EDistance ed("ACGT", "ACGT");
    
    BOOST_CHECK_EQUAL(ed.min3(1, 2, 3), 1);
    BOOST_CHECK_EQUAL(ed.min3(3, 1, 2), 1);
    BOOST_CHECK_EQUAL(ed.min3(2, 3, 1), 1);
    BOOST_CHECK_EQUAL(ed.min3(3, 3, 3), 3);
    BOOST_CHECK_EQUAL(ed.min3(-1, 0, 1), -1);
}
BOOST_AUTO_TEST_CASE(PenaltyFunction) {
    EDistance ed("ACGT", "ACGT");

    BOOST_CHECK_EQUAL(ed.penalty('A', 'A'), 0);
    BOOST_CHECK_EQUAL(ed.penalty('C', 'C'), 0);
    BOOST_CHECK_EQUAL(ed.penalty('G', 'G'), 0);
    BOOST_CHECK_EQUAL(ed.penalty('T', 'T'), 0);
    

    BOOST_CHECK_EQUAL(ed.penalty('A', 'C'), 1);
    BOOST_CHECK_EQUAL(ed.penalty('G', 'T'), 1);
    BOOST_CHECK_EQUAL(ed.penalty('T', 'A'), 1);
    BOOST_CHECK_EQUAL(ed.penalty('C', 'G'), 1);
}


BOOST_AUTO_TEST_CASE(TestValidInputs)
{
    EDistance obj("GATTACA", "GCATGCU");

    BOOST_REQUIRE_NO_THROW(obj.optDistance());
    

    int distance = obj.optDistance();
    BOOST_CHECK(distance >= 0);
}

BOOST_AUTO_TEST_CASE(TestPenaltyFunction)
{

    BOOST_CHECK_EQUAL(EDistance::penalty('A', 'A'), 0);
    

    BOOST_CHECK_EQUAL(EDistance::penalty('A', 'T'), 1);
    BOOST_CHECK_EQUAL(EDistance::penalty('G', 'C'), 1);
}

BOOST_AUTO_TEST_CASE(TestMin3Function)
{

    BOOST_CHECK_EQUAL(EDistance::min3(3, 1, 2), 1);
    BOOST_CHECK_EQUAL(EDistance::min3(7, 5, 9), 5);
}

BOOST_AUTO_TEST_CASE(TestAlignment)
{
    EDistance obj("GATTACA", "GCATGCU");
    

    BOOST_REQUIRE_NO_THROW(obj.alignment());
    

    BOOST_CHECK(!obj.alignment().empty());
}


