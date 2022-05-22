
#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "catch.hpp"
#include "stats.h"

#include <math.h>

using namespace std;
TEST_CASE("reports average, minimum and maximum") {
    Statistics::StatisticsCalc* computeObj = new Statistics::StatisticsCalc();
    auto computedStats = computeObj->ComputeStatistics({1.5, 8.9, 3.2, 4.5});
    float epsilon = 0.001;
    REQUIRE(std::abs(computedStats.average - 4.525) < epsilon);
    REQUIRE(std::abs(computedStats.max - 8.9) < epsilon);
    REQUIRE(std::abs(computedStats.min - 1.5) < epsilon);
}

TEST_CASE("average is NaN for empty array") {
    Statistics::StatisticsCalc* computeObj = new Statistics::StatisticsCalc();
    auto computedStats = computeObj->ComputeStatistics({});
    //All fields of computedStats (average, max, min) must be
    //NAN (not-a-number), as defined in math.h
    
    REQUIRE(isnan(computedStats.average) == 1);
    REQUIRE(isnan(computedStats.min) ==1);
    REQUIRE(isnan(computedStats.max) == 1);
    //Design the REQUIRE statement here.
    //Use http://www.cplusplus.com/reference/cmath/isnan/
}

TEST_CASE("raises alerts when max is greater than threshold") {
    EmailAlert emailAlert;
    LedAlert ledAlert;
    std::vector<IAlert*> alerters = {&emailAlert, &ledAlert};
    
    const float maxThreshold = 10.2;
    StatsAlerter statsAlerter(maxThreshold, alerters);
    statsAlerter.checkAndAlert({99.8, 34.2, 4.5, 6.7});

    REQUIRE(emailAlert.emailSent);
    REQUIRE(ledAlert.ledGlows);
}

#endif
