#include "reservationFile.h"

ReservationFile::ReservationFile() {
	ifstream ifs;
	ifs.open(RESERVATION_FILE, ios::in);

	string date;
	string period;
	string stuId;
	string stuName;
	string roomId;
	// reservation status
	string status;

	// number of reservations
	this->m_Size = 0;

	while (ifs >> date && ifs >> period && ifs >> stuId && ifs >> stuName && ifs >> roomId && ifs >> status) {
		string key;
		string value;
		map<string, string> m;

		// intercept date
		int pos = date.find(":");
		if (pos != -1) {
			key = date.substr(0, pos);
			value = date.substr(pos + 1, date.size() - pos - 1);
			m.insert(make_pair(key, value));
		}

		// intercept period
		pos = period.find(":");
		if (pos != -1) {
			key = period.substr(0, pos);
			value = period.substr(pos + 1, period.size() - pos - 1);
			m.insert(make_pair(key, value));
		}

		// intercept student ID
		pos = stuId.find(":");
		if (pos != -1) {
			key = stuId.substr(0, pos);
			value = stuId.substr(pos + 1, stuId.size() - pos - 1);
			m.insert(make_pair(key, value));
		}

		// intercept student name
		pos = stuName.find(":");
		if (pos != -1) {
			key = stuName.substr(0, pos);
			value = stuName.substr(pos + 1, stuName.size() - pos - 1);
			m.insert(make_pair(key, value));
		}

		// intercept computer room number
		pos = roomId.find(":");
		if (pos != -1) {
			key = roomId.substr(0, pos);
			value = roomId.substr(pos + 1, roomId.size() - pos - 1);
			m.insert(make_pair(key, value));
		}
		
		// intercept review status
		pos = status.find(":");
		if (pos != -1) {
			key = status.substr(0, pos);
			value = status.substr(pos + 1, status.size() - pos - 1);
			m.insert(make_pair(key, value));
		}
		
		this->map_reservationData.insert(make_pair(this->m_Size, m));
		this->m_Size++;
	}

	ifs.close();

	// test
	/*for (map<int, map<string, string>>::iterator it = map_reservationData.begin(); it != map_reservationData.end(); it++) {
		cout << "Number of record = " << it->first << " value = " << endl;

		for (map<string, string>::iterator mit = (*it).second.begin(); mit != it->second.end(); mit++)
			cout << " key = " << mit->first << " value = " << mit->second << " ";
		cout << endl;
	}*/
}

// update reservation record
void ReservationFile::updateReservation() {
	if (this->m_Size == 0)
		return;

	ofstream ofs(RESERVATION_FILE, ios::out | ios::trunc);

	for (int i = 0; i < this->m_Size; i++) {
		ofs << "date:" << this->map_reservationData[i]["date"] << " ";
		ofs << "period:" << this->map_reservationData[i]["period"] << " ";
		ofs << "stuId:" << this->map_reservationData[i]["stuId"] << " ";
		ofs << "stuName" << this->map_reservationData[i]["stuName"] << " ";
		ofs << "roomId:" << this->map_reservationData[i]["roomId"] << " ";
		ofs << "status:" << this->map_reservationData[i]["status"] << endl;
	}

	ofs.close();
}
