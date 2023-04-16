/** 
* Spring 2023 - Lab 10
* Last name: Cataluna
* First name: Kert Harvey
* GitHub username: kertharv
* Instructor: Genady Maryash
* Recitation Instructor: Prof. Zamansky
*/

#include <iostream>
#include "funcs.h"

int main()
{
Time earlier = {10, 30};
Time later = {13, 40};
Time time0 = {8, 10};
Movie movie1 = {"Back to the Future", COMEDY, 116};
Movie movie2 = {"Black Panther", ACTION, 134};
Movie movie3 = {"Evangelion: 3.0 + 1.0 Thrice Upon a Time", ACTION, 155};
Movie movie4 = {"Koe no Katachi", ROMANCE, 129};
Movie movie5 = {"Fake Movie", ROMANCE, 90};

TimeSlot morning = {movie1, {9, 15}};  
TimeSlot daytime = {movie2, {12, 15}}; 
TimeSlot evening = {movie2, {16, 45}}; 
TimeSlot nextSchedule = scheduleAfter(evening, movie3);
TimeSlot ts1 = {movie5, {10, 0}};
TimeSlot ts2 = {movie4, {11, 29}};

std::cout << minutesUntil(earlier, later) << "\n";

std::cout << addMinutes(time0, 75).h << ", "<< addMinutes(time0, 75).m << "\n";

std::cout << getTimeSlot(morning) << "\n";

std::cout << getTimeSlot(daytime) << "\n";

std::cout << getTimeSlot(evening) << "\n";

std::cout << getTimeSlot(nextSchedule) << "\n";

std::cout << getTimeSlot(ts1) << "\n";

std::cout << getTimeSlot(ts2) << "\n";

std::cout << "If 2 timeslot overlaps: " << timeOverlap(ts1, ts2) << "\n";

}