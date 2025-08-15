// Modify Project 8 from Chapter 5 so that it includes the following function.
//
// void find_closest_flight(int desired_time, int *departure_time, int
// *arrival_time);

#include <stdio.h>

#define DEPARTURE_COUNT 8

void find_closest_flight(int desired_time, int *departure_time,
                         int *arrival_time);

int main(void) {
  printf("enter a 24-hour time: ");
  int hour, minute;
  scanf("%d:%d", &hour, &minute);

  int desired_time = hour * 60 + minute;
  int arrival_time, departure_time;
  find_closest_flight(desired_time, &departure_time, &arrival_time);

  int arrival_hour = arrival_time / 60;
  int arrival_min = arrival_time % 60;
  int departure_hour = departure_time / 60;
  int departure_min = departure_time % 60;
  printf("closest departure time is %.2d:%.2d, arriving at %.2d:%.2d",
         departure_hour, departure_min, arrival_hour, arrival_min);

  return 0;
}

void find_closest_flight(int desired_time, int *departure_time,
                         int *arrival_time) {
  int departures[DEPARTURE_COUNT][2] = {
      {480, 616}, {583, 712},  {679, 811},   {767, 900},
      {840, 968}, {945, 1075}, {1140, 1280}, {1305, 1438},
  };

  int i;
  for (i = 0; i < DEPARTURE_COUNT - 1; i++) {
    int d1 = departures[i][0];
    int d2 = departures[i + 1][0];
    if (desired_time <= d1 + (d2 - d1) / 2) {
      break;
    }
  }

  *departure_time = departures[i][0];
  *arrival_time = departures[i][1];
}
