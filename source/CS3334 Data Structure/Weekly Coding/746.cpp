#include <iostream>
#include <queue>

using namespace std;

int main() {
	int customers, arrivalTime, orderTime, others, leaveTime;

	while (cin >> customers) {
		queue<int> line;

		cin >> arrivalTime;
		cin >> orderTime;
		cin >> others;

		line.push(arrivalTime + orderTime);

		if (customers == 1) {
			cout << arrivalTime << endl;
		}
		else {
			for (int i = 1; i < customers - 1; i++) {
				cin >> arrivalTime;
				cin >> orderTime;
				cin >> others;
				while (!line.empty() && line.front() <= arrivalTime)
					line.pop();
				if (others >= line.size()) {
					if (arrivalTime > line.back())
						leaveTime = arrivalTime + orderTime;
					else
						leaveTime = line.back() + orderTime;
					line.push(leaveTime);
				}
			}

			cin >> arrivalTime >> orderTime >> others;
			while (!line.empty() && line.front() <= arrivalTime)
				line.pop();
			if (line.size() <= others) {
				if (arrivalTime > line.back())
					cout << arrivalTime << endl;
				else
					cout << line.back() << endl;
			}
			else
				cout << -1 << endl;
		}
	}

	return 0;
}
