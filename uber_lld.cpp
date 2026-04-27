#include <iostream>
#include <unordered_set>
using namespace std;

class Ride;
class RideScheduler;
class FareCalculator;

class User
{
private:
    string name;
    string user_id;
    vector<Ride *> rideHistory;
    Ride *current_ride;

public:
    User(string name, string user_id)
    {
        this->name = name;
        this->user_id = user_id;
        this->current_ride = nullptr;
    }
    void requestRide(pair<int, int> src, pair<int, int> dest);
    void selectRide();
    void rideConfirmed();
    void rideStarted()
    {
        cout << "ride started" << endl;
    }
    void rideEnded()
    {
        cout << "Ride ended. Please complete the payment." << endl;
    }
    void completePayment();
    void paymentSuccessful()
    {
        this->current_ride = nullptr;
    }
    void showRideHistory();
};

class Driver
{
private:
    string driver_id;
    string driver_name;
    string driver_status;
    Ride *current_ride;
    pair<int, int> current_location;

public:
    Driver(string driver_id, string driver_name, pair<int, int> current_location)
    {
        this->driver_id = driver_id;
        this->driver_name = driver_name;
        this->current_location = current_location;
        this->driver_status = "OFFLINE";
        this->current_ride = nullptr;
    }
    void goOnline();
    void goOffline();
    void acceptRide();
    void rejectRide();
    void startRide();
    void endRide();
    void notify(Ride *ride);
    pair<int, int> getLocation()
    {
        return this->current_location;
    }
    string getStatus()
    {
        return this->driver_status;
    }
    string getName()
    {
        return this->driver_name;
    }
};

class RideScheduler
{
private:
    static unordered_set<Driver *> drivers;

public:
    static void scheduleRide(Ride *ride);
    static void addDriver(Driver *driver)
    {
        drivers.insert(driver);
    }
    static void removeDriver(Driver *driver)
    {
        drivers.erase(driver);
    }
};

class Ride
{
private:
    User *user;
    Driver *driver;
    pair<int, int> src;
    pair<int, int> dest;
    string payment_status;
    string ride_status;
    int fare;
    unordered_set<Driver *> blacklistedDrivers;

public:
    Ride(User *user, pair<int, int> src, pair<int, int> dest, int fare)
    {
        this->user = user;
        this->src = src;
        this->dest = dest;
        this->ride_status = "NOT_ASSIGNED";
        this->fare = fare;
    }
    void confirmRide(Driver *driver)
    {
        this->driver = driver;
        this->ride_status = "CONFIRMED";
        this->user->rideConfirmed();
        RideScheduler::removeDriver(driver);
    }
    void rejectRide(Driver *driver)
    {
        blacklistedDrivers.insert(driver);
        RideScheduler::scheduleRide(this);
    }
    void rideStarted()
    {
        this->ride_status = "STARTED";
        this->user->rideStarted();
    }
    void rideEnded()
    {
        this->ride_status = "COMPLETED";
        RideScheduler::addDriver(driver);
        this->user->rideEnded();
    }
    void processPayment()
    {
        this->payment_status = "PENDING";
        cout << "payment status: pending" << endl;
        this->payment_status = "COMPLETED";
        cout << "payment status: done" << endl;
        this->user->paymentSuccessful();
    }
    pair<int, int> getSourceLocation()
    {
        return this->src;
    }
    pair<int, int> getDestLocation()
    {
        return this->dest;
    }
    string getDriverName()
    {
        return this->driver->getName();
    }
    string getPaymentStatus()
    {
        return this->payment_status;
    }
    string getRideStatus()
    {
        return this->ride_status;
    }
    int getFare()
    {
        return this->fare;
    }
    unordered_set<Driver *> getBlackListedDrivers()
    {
        return this->blacklistedDrivers;
    }
};

class FareCalculator
{
public:
    static Ride *calculateFare(User *user, pair<int, int> src, pair<int, int> dest)
    {
        int dist = abs(src.first - dest.first) + abs(src.second - dest.second);
        int time = dist * 2;
        int fare = (dist * 7) + time;
        return new Ride(user, src, dest, fare);
    }
};

unordered_set<Driver *> RideScheduler::drivers;

void User::requestRide(pair<int, int> src, pair<int, int> dest)
{
    Ride *ride = FareCalculator::calculateFare(this, src, dest);
    current_ride = ride;
}

void User::selectRide()
{
    RideScheduler::scheduleRide(this->current_ride);
}

void User::rideConfirmed()
{
    this->rideHistory.push_back(this->current_ride);
    cout << "ride confirmed by " + this->current_ride->getDriverName() << endl;
}

void User::completePayment()
{
    this->current_ride->processPayment();
}

void User::showRideHistory()
{
    for (int i = 0; i < rideHistory.size(); i++)
    {
        cout << "Ride details " << endl;
        cout << "src: " << rideHistory[i]->getSourceLocation().first << "," << rideHistory[i]->getSourceLocation().second << endl;
        cout << "dest: " << rideHistory[i]->getDestLocation().first << "," << rideHistory[i]->getDestLocation().second << endl;
        cout << "driver: " << rideHistory[i]->getDriverName() << endl;
        cout << "price: " << rideHistory[i]->getFare() << endl;
        cout << "payment status: " << rideHistory[i]->getPaymentStatus() << endl;
        cout << endl;
    }
}

void Driver::acceptRide()
{
    this->current_ride->confirmRide(this);
}

void Driver::rejectRide()
{
    this->current_ride->rejectRide(this);
}

void Driver::startRide()
{
    this->current_ride->rideStarted();
}

void Driver::endRide()
{
    this->current_ride->rideEnded();
}

void Driver::goOnline()
{
    this->driver_status = "AVAILABLE";
    RideScheduler::addDriver(this);
}

void Driver::goOffline()
{
    this->driver_status = "OFFLINE";
    RideScheduler::removeDriver(this);
}

void Driver::notify(Ride *ride)
{
    this->current_ride = ride;
}

void RideScheduler::scheduleRide(Ride *ride)
{
    if (RideScheduler::drivers.size() == 0)
    {
        cout << "sorry no drivers available at the moment" << endl;
        return;
    }
    Driver *nearestAvailableDriver = nullptr;
    int min_distance = INT_MAX;
    for (auto it = RideScheduler::drivers.begin(); it != RideScheduler::drivers.end(); it++)
    {
        if (ride->getBlackListedDrivers().find(*it) == ride->getBlackListedDrivers().end())
        {
            pair<int, int> srcLocation = ride->getSourceLocation();
            pair<int, int> driverLocation = (*it)->getLocation();
            int curr_distance = abs(srcLocation.first - driverLocation.first) + abs(srcLocation.second - driverLocation.second);
            if (curr_distance < min_distance)
            {
                min_distance = min(min_distance, curr_distance);
                nearestAvailableDriver = *it;
            }
        }
    }
    nearestAvailableDriver->notify(ride);
}

int main()
{
    // sorry no drivers available at the moment
    // ride confirmed by mukesh
    // ride started
    // Ride ended. Please complete the payment.
    // payment status: pending
    // payment status: done
    // Ride details
    // src: 0,0
    // dest: 5,5
    // driver: mukesh
    // price: 90
    // payment status: COMPLETED
    User *user = new User("rithik", "1");
    user->requestRide(make_pair(0, 0), make_pair(5, 5));
    user->selectRide();
    Driver *driver = new Driver("1", "mukesh", make_pair(1, 1));
    driver->goOnline();
    user->selectRide();
    driver->acceptRide();
    driver->startRide();
    driver->endRide();
    user->completePayment();
    user->showRideHistory();
    return 0;
}