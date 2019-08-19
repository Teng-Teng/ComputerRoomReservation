#pragma once
#include <iostream>
#include <fstream>
#include <map>
#include <string>
using namespace std;
#include "globalFile.h"

class ReservationFile {
public:
	ReservationFile();

	// update reservation record
	void updateReservation();

	// record the number of reservations
	int m_Size;

	// container for recording all reservation information, key: number of reservations, value: record key-value pair information
	map<int, map<string, string>> map_reservationData;
};
