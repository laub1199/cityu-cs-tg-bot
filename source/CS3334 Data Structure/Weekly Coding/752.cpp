#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <cmath>
#include <queue> 


using namespace std;

class Process {
private:
	int id;
	int arrivingTime;
	int processingTime;
	int priority;
	int doneTime;
public:
	Process() = default;
	Process(int, int, int, int);
	int getId();
	int getArrivingTime();
	int getProcessingTime();
	int getPriority();
	int getDoneTime();
	void setId(int);
	void setArrvingTime(int);
	void setProcessingTime(int);
	void setPriority(int);
	void setDoneTime(int);
};


int main() {
	int num;

	while (cin >> num) {
		int at, pt, pr, dt = 0;
		queue<Process> high;
		queue<Process> low;

		Process* process = new Process[num];

		for (int i = 0; i < num; i++) {
			cin >> at >> pt >> pr;
			process[i].setId(i);
			process[i].setArrvingTime(at);
			process[i].setProcessingTime(pt);
			process[i].setPriority(pr);
		}

		bool processing = false;

		for (int ri = 0; ri < 6000; ri++) {
			for (int i = 0; i < num; i++) {
				if (process[i].getArrivingTime() == ri) {
					if (process[i].getPriority() == 0) {
						high.push(process[i]);
					}
					else {
						low.push(process[i]);
					}
				}
				else {
					continue;
				}
			}

			if (dt == ri) {
				processing = false;
			}

			if (!processing) {
				if (!high.empty()) {
					Process temp = high.front();
					for (int i = 0; i < num; i++) {
						if (temp.getId() == i) {
							process[i].setDoneTime(ri);
							dt = process[i].getDoneTime();
							high.pop();
							processing = true;
							break;
						}
					}
				}
				else if (!low.empty()) {
					Process temp = low.front();
					for (int i = 0; i < num; i++) {
						if (temp.getId() == i) {
							process[i].setDoneTime(ri);
							dt = process[i].getDoneTime();
							low.pop();
							processing = true;
							break;
						}
					}
				}
			}
		}
		for (int i = 0; i < num - 1; i++) {
			cout << process[i].getDoneTime() << " ";
		}

		cout << process[num - 1].getDoneTime();
		cout << endl;
		delete[] process;
	}

	system("pause");
	return 0;
}

Process::Process(int inID, int aT, int pT, int pri) {
	id = inID;
	arrivingTime = aT;
	processingTime = pT;
	priority = pri;
}
int Process::getId() { return id; }
int Process::getArrivingTime() { return arrivingTime; }
int Process::getProcessingTime() { return processingTime; }
int Process::getPriority() { return priority; }
int Process::getDoneTime() { return doneTime; }
void Process::setId(int inID) { id = inID; }
void Process::setArrvingTime(int aT) { arrivingTime = aT; }
void Process::setProcessingTime(int pT) { processingTime = pT; }
void Process::setPriority(int pri) { priority = pri; }
void Process::setDoneTime(int dT) { doneTime = dT + processingTime; }