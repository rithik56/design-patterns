#include<iostream>
using namespace std;

class ShowVisitor;

class FavoriteShow {
    public:
        int id;
        string name;
        string platform;
        double ratings;
        FavoriteShow(int id, string name, double ratings, string platform) {
            this->id = id;
            this->name = name;
            this->ratings = ratings;
            this->platform = platform;
        }
};

class NetflixShow {
    private:
        int netflix_id;
        string netflix_name;
        double netflix_ratings;
    public:
        NetflixShow(int netflix_id, string netflix_name, double netflix_ratings) {
            this->netflix_id = netflix_id;
            this->netflix_name = netflix_name;
            this->netflix_ratings = netflix_ratings;
        }
    friend class FavoriteShowVisitor;
};

class PrimeShow {
    private:
        int prime_id;
        string prime_name;
        double prime_ratings;
    public:
        PrimeShow(int prime_id, string prime_name, double prime_ratings) {
            this->prime_id = prime_id;
            this->prime_name = prime_name;
            this->prime_ratings = prime_ratings;
        }
    friend class FavoriteShowVisitor;
};

class HotstarShow {
    private:
        int hotstar_id;
        string hotstar_name;
        double hotstar_ratings;
    public:
        HotstarShow(int hotstar_id, string hotstar_name, double hotstar_ratings) {
            this->hotstar_id = hotstar_id;
            this->hotstar_name = hotstar_name;
            this->hotstar_ratings = hotstar_ratings;
        }
   friend class FavoriteShowVisitor;
}; 

class StreamingPlatform {
    public:
        virtual void accept(ShowVisitor* visitor) = 0;
};

class Netflix: public StreamingPlatform {
    private:
        vector<NetflixShow*> shows;
    public:
        Netflix(vector<NetflixShow*> shows) {
            this->shows = shows;
        }
        void accept(ShowVisitor* visitor) override;
        vector<NetflixShow*> getShows() {
            return this->shows;
        }
};

class Prime: public StreamingPlatform {
    private:
        vector<PrimeShow*> shows;
    public:
        Prime(vector<PrimeShow*> shows) {
            this->shows = shows;
        }
        void accept(ShowVisitor* visitor) override;
        vector<PrimeShow*> getShows() {
            return this->shows;
        }
};

class Hotstar: public StreamingPlatform {
    private:
        vector<HotstarShow*> shows;
    public:
        Hotstar(vector<HotstarShow*> shows) {
            this->shows = shows;
        }
        void accept(ShowVisitor* visitor) override;
        vector<HotstarShow*> getShows() {
            return this->shows;
        }
};

class ShowVisitor {
    public:
        virtual void visitNetflix(Netflix* netflix) = 0;
        virtual void visitPrime(Prime* prime) = 0;
        virtual void visitHotstar(Hotstar* hotstar) = 0;
};

class FavoriteShowVisitor: public ShowVisitor {
    private:
        vector<FavoriteShow*> shows;
    public:
        FavoriteShowVisitor() {

        }
        void visitNetflix(Netflix* netflix) {
            for (int i = 0; i < netflix->getShows().size(); i++) {
                if (netflix->getShows()[i]->netflix_ratings > 3.5) {
                    this->shows.push_back(new FavoriteShow(netflix->getShows()[i]->netflix_id, netflix->getShows()[i]->netflix_name, netflix->getShows()[i]->netflix_ratings,"netflix"));
                }
            }
        }
        void visitPrime(Prime* prime) {
            for (int i = 0; i < prime->getShows().size(); i++) {
                if (prime->getShows()[i]->prime_ratings > 3.5) {
                    this->shows.push_back(new FavoriteShow(prime->getShows()[i]->prime_id, prime->getShows()[i]->prime_name, prime->getShows()[i]->prime_ratings,"prime"));
                }
            }
        }
        void visitHotstar(Hotstar* hotstar) {
                        for (int i = 0; i < hotstar->getShows().size(); i++) {
                if (hotstar->getShows()[i]->hotstar_ratings > 3.5) {
                    this->shows.push_back(new FavoriteShow(hotstar->getShows()[i]->hotstar_id, hotstar->getShows()[i]->hotstar_name, hotstar->getShows()[i]->hotstar_ratings,"hotstar"));
                }
            }
        }
        vector<FavoriteShow*> getShows() {
            return this->shows;
        }
};

void Netflix::accept(ShowVisitor* visitor) {
    visitor->visitNetflix(this);
}

void Prime::accept(ShowVisitor* visitor) {
    visitor->visitPrime(this);
}

void Hotstar::accept(ShowVisitor* visitor) {
    visitor->visitHotstar(this);
}

int main() {
    vector<NetflixShow*> netflixShows;
    vector<PrimeShow*> primeShows;
    vector<HotstarShow*> hotstarShows;
    netflixShows.push_back(new NetflixShow(123, "friends", 4.9));
    primeShows.push_back(new PrimeShow(12321, "mirzapur", 4.8));
    hotstarShows.push_back(new HotstarShow(321, "special oops", 3));
    Netflix* netflix = new Netflix(netflixShows);
    Hotstar* hotstar = new Hotstar(hotstarShows);
    Prime* prime = new Prime(primeShows);
    FavoriteShowVisitor* visitor = new FavoriteShowVisitor();
    netflix->accept(visitor);
    prime->accept(visitor);
    hotstar->accept(visitor);
    vector<FavoriteShow*> favoriteShows = visitor->getShows();

    // 123 friends 4.9 netflix
    // 12321 mirzapur 4.8 prime
    for (int i = 0; i < favoriteShows.size(); i++) {
        cout << favoriteShows[i]->id << " " << favoriteShows[i]->name << " " << favoriteShows[i]->ratings << " " << favoriteShows[i]->platform << endl;
    }

    return 0;
}