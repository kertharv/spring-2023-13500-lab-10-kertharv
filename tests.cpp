/** 
* Spring 2023 - Lab 10
* Last name: Cataluna
* First name: Kert Harvey
* GitHub username: kertharv
* Instructor: Genady Maryash
* Recitation Instructor: Prof. Zamansky
*/

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "funcs.h"

TEST_CASE("minutesSinceMidnight(Time time) function")
{
    CHECK(minutesSinceMidnight({2,0}) == 120);
    CHECK(minutesSinceMidnight({6,29}) == 389);
    CHECK(minutesSinceMidnight({11,27}) == 687);
    CHECK(minutesSinceMidnight({23,52}) == 1432);
    CHECK(minutesSinceMidnight({21,36}) == 1296);
}


TEST_CASE("minutesUntil(Time earlier, Time later) fuction")
{
    CHECK(minutesUntil({10, 30}, {13, 40}) == 190);
    CHECK(minutesUntil({0, 30}, {13, 40}) == 790);
    CHECK(minutesUntil({0, 38}, {23, 59}) == 1401);
    CHECK(minutesUntil({7, 12}, {18, 26}) == 674);
}

TEST_CASE("addMinutes(Time time0, int min) function")
{
    CHECK(addMinutes({8, 10}, 75).h == 9);
    CHECK(addMinutes({8, 10}, 75).m == 25);

    CHECK(addMinutes({5, 41}, 346).h == 11);
    CHECK(addMinutes({5, 41}, 346).m == 27);

    CHECK(addMinutes({12, 59}, 492).h == 21);
    CHECK(addMinutes({12, 59}, 492).m == 11);
}

TEST_CASE("getTimeSlot(TimeSlot ts) function")
{
    TimeSlot morning = {{"Back to the Future", COMEDY, 116}, {9, 15}};  
    TimeSlot daytime = {{"Black Panther", ACTION, 134}, {12, 15}}; 
    TimeSlot evening = {{"Black Panther", ACTION, 134}, {16, 45}}; 

    CHECK(getTimeSlot(morning) == "Back to the Future COMEDY (116 min) [starts at 9:15, ends by 11:11] ");
    CHECK(getTimeSlot(daytime) == "Black Panther ACTION (134 min) [starts at 12:15, ends by 14:29] ");
    CHECK(getTimeSlot(evening) == "Black Panther ACTION (134 min) [starts at 16:45, ends by 18:59] ");
}

TEST_CASE("TimeSlot scheduleAfter(TimeSlot ts, Movie nextMovie) function")
{
    CHECK(scheduleAfter({{"Black Panther", ACTION, 134}, {16, 45}}, {"Evangelion: 3.0 + 1.0 Thrice Upon a Time", ACTION, 155}).startTime.h == 18);
    CHECK(scheduleAfter({{"Black Panther", ACTION, 134}, {16, 45}}, {"Evangelion: 3.0 + 1.0 Thrice Upon a Time", ACTION, 155}).startTime.m == 59);

    CHECK(scheduleAfter({{"Back to the Future", COMEDY, 116}, {9, 15}}, {"Evangelion: 3.0 + 1.0 Thrice Upon a Time", ACTION, 155}).startTime.h == 11);
    CHECK(scheduleAfter({{"Back to the Future", COMEDY, 116}, {9, 15}}, {"Evangelion: 3.0 + 1.0 Thrice Upon a Time", ACTION, 155}).startTime.m == 11);

    CHECK(scheduleAfter({{"Back to the Future", COMEDY, 120}, {16, 45}}, {"Koe no Katachi", ROMANCE, 129}).startTime.h == 18);
    CHECK(scheduleAfter({{"Back to the Future", COMEDY, 120}, {16, 45}}, {"Koe no Katachi", ROMANCE, 129}).startTime.m == 45);
}

TEST_CASE("timeOverlap(TimeSlot ts1, TimeSlot ts2)")
{

    CHECK(timeOverlap({{"Fake Movie", ROMANCE, 90}, {10, 0}}, {{"Koe no Katachi", ROMANCE, 129}, {11, 29}}) == true);
    CHECK(timeOverlap({{"Fake Movie", ROMANCE, 90}, {10, 0}}, {{"Koe no Katachi", ROMANCE, 129}, {11, 30}}) == true);
    CHECK(timeOverlap({{"Fake Movie", ROMANCE, 90}, {10, 0}}, {{"Koe no Katachi", ROMANCE, 129}, {11, 31}}) == false);
    CHECK(timeOverlap({{"Koe no Katachi", ROMANCE, 129}, {16, 15}}, {{"Evangelion: 3.0 + 1.0 Thrice Upon a Time", ACTION, 155}, {20, 31}}) == false);
    CHECK(timeOverlap({{"Koe no Katachi", ROMANCE, 129}, {16, 15}}, {{"Evangelion: 3.0 + 1.0 Thrice Upon a Time", ACTION, 155}, {18, 5}}) == true);
    CHECK(timeOverlap({{"Koe no Katachi", ROMANCE, 129}, {17, 15}}, {{"Evangelion: 3.0 + 1.0 Thrice Upon a Time", ACTION, 155}, {21, 30}}) == false);

}