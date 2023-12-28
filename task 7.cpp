#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// Function declarations
void setupDonationSystem(vector<string>& charities);
void recordAndTotalDonation(const vector<string>& charities, vector<double>& donations, int charityChoice);
void showTotals(const vector<string>& charities, const vector<double>& donations);
void displayCharities(const vector<string>& charities);

int main() {
    vector<string> charities(3);
    vector<double> donations(3, 0.0);

    setupDonationSystem(charities);

    int choice;
    do {
        displayCharities(charities);
        cout << "Enter the charity number to donate (1, 2, or 3), or -1 to show totals: ";
        cin >> choice;

        if (choice >= 1 && choice <= 3) {
            recordAndTotalDonation(charities, donations, choice);
        } else if (choice != -1) {
            cout << "Invalid choice. Please enter a valid number.\n";
        }
    } while (choice != -1);

    showTotals(charities, donations);

    return 0;
}

void setupDonationSystem(vector<string>& charities) {
    cout << "Enter the names of three charities:\n";
    for (int i = 0; i < 3; ++i) {
        cout << "Charity " << (i + 1) << ": ";
        getline(cin, charities[i]);
    }
}

void recordAndTotalDonation(const vector<string>& charities, vector<double>& donations, int charityChoice) {
    double shoppingBill;

    cout << "Enter the value of your shopping bill: $";
    cin >> shoppingBill;

    double donation = shoppingBill * 0.01; // 1% of the shopping bill
    donations[charityChoice - 1] += donation;

    cout << "You have donated $" << donation << " to " << charities[charityChoice - 1] << ".\n";
}

void showTotals(const vector<string>& charities, const vector<double>& donations) {
    vector<pair<string, double>> charityTotals;
    for (size_t i = 0; i < charities.size(); ++i) {
        charityTotals.emplace_back(charities[i], donations[i]);
    }

    // Sort in descending order of donations
    sort(charityTotals.begin(), charityTotals.end(), [](const pair<string, double>& a, const pair<string, double>& b) {
        return a.second > b.second;
    });

    double grandTotal = 0;
    cout << "\nTotals donated to each charity:\n";
    for (const auto& charityTotal : charityTotals) {
        cout << charityTotal.first << ": $" << charityTotal.second << "\n";
        grandTotal += charityTotal.second;
    }

    cout << "\nGRAND TOTAL DONATED TO CHARITY: $" << grandTotal << endl;
}

void displayCharities(const vector<string>& charities) {
    cout << "\nCharities available for donation:\n";
    for (int i = 0; i < 3; ++i) {
        cout << i + 1 << ". " << charities[i] << endl;
    }
}

