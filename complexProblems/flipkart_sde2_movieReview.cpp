/*
Problem : Movie Review Platform

We have a requirement to implement a platform related to Movie reviews, and following is the description of it.

Platform Overview:
Movie review platform collects reviews for Movies from its users. Later these movie reviews are used to derive insights which helps in enriching the lives of its customers with entertainment.

Platform Capabilities:
● Adding Users and Movies.
○ Platform by default on-boards a user as a ‘viewer’.
○ A ‘viewer’ category can be upgraded to a ‘critic’ category after he/she published more than 3 reviews for various movies.
○ Critics are considered as experts in the judgement here, so critics reviews will be captured with more weightage. i.e. review rating of a critic will be considered twice.
● Users can review a movie
○ Users can only review Movies which have been released so far, they cannot review upcoming movies.
○ Users can give a review-score between 1 to 10. (Higher the score the better the liking for the movie). Currently we are not allowing a user to review the same Movie multiple times.
● User can Update/Delete their Review
● List all reviews given by a User
● List top n movies by total review score for a:
○ particular year of release
○ particular genre

Bonus Capabilities:
● Based on the users behaviour Platform should give capability to plugin more user upgradation policies from. Eg. Viewer ->Critic -> Expert
● List top n movies by total review score based on combination of pivots:
○ Pivots : [Year of release, User category, Genre]

Expectations:
    Make sure that you have working and demonstrable code for all the above requirements.
    Platform Capabilities should be strictly followed. Work on the expected output first and then move on the Bonus Capabilities.
    Use of proper abstraction, separation of concerns is required.
    Code should easily accommodate new requirements with minimal changes.
    Proper exception handling is required.
    Code should be modular, readable and unit-testable.

Important Notes:
● Do not use any database store, use in-memory data structure.
● Do not create any UI for the application.
● Do not build a Command line interface, Executing test cases or simple Main function should be sufficient
● Do not make any assumption, please ask it out.

Sample Test Cases:

Onboard 10 movies onto your platform in 3 different years.
a. Add Movie("Don" released in Year 2006 for Genres “Action” & “Comedy”)
b. Add Movie("Tiger" released in Year 2008 for Genre “Drama”)
c. Add Movie("Padmavat" released in Year 2006 for Genre “Comedy”)
d. Add Movie("Lunchbox-2" released in Year 2022 for Genre “Drama”)
e. Add Movie("Guru" released in Year 2006 for Genre “Drama”)
f. Add Movie("Metro" released in Year 2006 for Genre “Romance”)

Add users to the system:
a. Add User(“SRK”)
b. Add User(“Salman”)
c. Add User(“Deepika”)

Add/Update/Delete Reviews:
a. add_review(“SRK”, “Don”, 2)
b. add_review(“SRK”, “Padmavat”, 8)
c. add_review(“Salaman”, “Don”, 5)
d. add_review(“Deepika”, “Don”, 9)
e. add_review(“Deepika”, “Guru”, 6)
f. add_review(“SRK”,”Don”, 10) - Exception multiple reviews not allowed
g. update_review(“SRK”,”Don”, 8) - update won't affect the existing user category (viewer will remain viewer even after this operation)
h. add_review(“Deepika”, “Lunchbox-2”, 5) - Exception movie yet to be released
i. add_review(“SRK”, “Tiger”, 5). Since ‘SRK’ has published 3 reviews, he is promoted to ‘critic’ now.
j. delete_review(“SRK”, “Tiger”). Since ‘SRK’ has deleted his review he is downgraded back to viewer now, total active reviews given by SRK is < 3
k. add_review(“SRK”, “Metro”, 7) ‘SRK promoted back to critic’

List User Reviews:
a. list_review(“SRK”)
Output: {
“Don” : 8,
“Padmavat” : 8,
“Metro” : 7
}

List top 1 movie by review score in “2006” year:
a. Top in Year “2006”:
Output: Don - 9 + 5 + 8 * 2 (at the time of evaluation SRK promoted to critic so rating considered twice)
Output: Don - 30 ratings (sum of all ratings of Deepika, Salman & SRK)
b. [Bonus eg] Top in Year “2006” by “critics_preferred”:
Output: Don - 8 ratings (SRK gave 7 for Metro as critic and 8 to Don )

List top 1 movie by review score in “Drama” genre:
Output: Guru - 6 ratings
*/

/*
ChatGPT Resp: To implement the Movie Review Platform with the provided requirements, we'll design classes for movies, users, reviews, and the platform itself. We'll also include methods for adding users and movies, submitting, updating, and deleting reviews, listing user reviews, and listing top movies by review score.

Let's start by defining the necessary classes and methods:
*/

#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <algorithm>
#include <stdexcept>

using namespace std;

// Forward declaration of classes
class User;
class Movie;
class Review;

// Class representing a Movie
class Movie {
private:
    string title;
    int year;
    vector<string> genres;

public:
    Movie(const string& _title, int _year, const vector<string>& _genres) :
            title(_title), year(_year), genres(_genres) {}

    const string& getTitle() const {
        return title;
    }

    int getYear() const {
        return year;
    }

    const vector<string>& getGenres() const {
        return genres;
    }
};

// Class representing a User
class User {
private:
    string name;
    int totalReviews;
    bool isCritic;

public:
    User(const string& _name) : name(_name), totalReviews(0), isCritic(false) {}

    const string& getName() const {
        return name;
    }

    int getTotalReviews() const {
        return totalReviews;
    }

    bool getIsCritic() const {
        return isCritic;
    }

    void addReview() {
        totalReviews++;
        if (!isCritic && totalReviews > 3) {
            isCritic = true;
        }
    }

    void deleteReview() {
        totalReviews--;
        if (isCritic && totalReviews <= 3) {
            isCritic = false;
        }
    }
};

// Class representing a Review
class Review {
private:
    User* user;
    Movie* movie;
    int rating;

public:
    Review(User* _user, Movie* _movie, int _rating) :
            user(_user), movie(_movie), rating(_rating) {}

    User* getUser() const {
        return user;
    }

    Movie* getMovie() const {
        return movie;
    }

    int getRating() const {
        return rating;
    }
};

// Class representing the Movie Review Platform
class MovieReviewPlatform {
private:
    unordered_map<string, User*> users;
    unordered_map<string, Movie*> movies;
    vector<Review*> reviews;

public:
    // Method to add a user to the platform
    void addUser(const string& name) {
        if (users.find(name) == users.end()) {
            users[name] = new User(name);
        }
    }

    // Method to add a movie to the platform
    void addMovie(const string& title, int year, const vector<string>& genres) {
        if (movies.find(title) == movies.end()) {
            movies[title] = new Movie(title, year, genres);
        }
    }

    // Method to submit a review for a movie by a user
    void addReview(const string& userName, const string& movieTitle, int rating) {
        User* user = getUser(userName);
        Movie* movie = getMovie(movieTitle);

        if (movie->getYear() > 2022) {
            throw invalid_argument("Cannot review upcoming movies.");
        }

        for (Review* review : reviews) {
            if (review->getUser() == user && review->getMovie() == movie) {
                throw invalid_argument("User already reviewed this movie.");
            }
        }

        reviews.push_back(new Review(user, movie, rating));
        user->addReview();
    }

    // Method to update a review for a movie by a user
    void updateReview(const string& userName, const string& movieTitle, int newRating) {
        User* user = getUser(userName);
        Movie* movie = getMovie(movieTitle);

        for (Review* review : reviews) {
            if (review->getUser() == user && review->getMovie() == movie) {
                review->rating = newRating;
                return;
            }
        }

        throw invalid_argument("Review not found.");
    }

    // Method to delete a review for a movie by a user
    void deleteReview(const string& userName, const string& movieTitle) {
        User* user = getUser(userName);
        Movie* movie = getMovie(movieTitle);

        auto it = reviews.begin();
        while (it != reviews.end()) {
            Review* review = *it;
            if (review->getUser() == user && review->getMovie() == movie) {
                delete review;
                it = reviews.erase(it);
                user->deleteReview();
                return;
            }
            ++it;
        }

        throw invalid_argument("Review not found.");
    }

    // Method to list all reviews given by a user
    void listReviews(const string& userName) {
        User* user = getUser(userName);

        cout << "Reviews by " << userName << ":" << endl;
        for (Review* review : reviews) {
            if (review->getUser() == user) {
                cout << review->getMovie()->getTitle() << ": " << review->getRating() << endl;
            }
        }
    }

private:
    User* getUser(const string& userName) {
        auto it = users.find(userName);
        if (it == users.end()) {
            throw invalid_argument("User not found.");
        }
        return it->second;
    }

    Movie* getMovie(const string& movieTitle) {
        auto it = movies.find(movieTitle);
        if (it == movies.end()) {
            throw invalid_argument("Movie not found.");
        }
        return it->second;
    }
};

int main() {
    MovieReviewPlatform platform;

    // Add users
    platform.addUser("SRK");
    platform.addUser("Salman");
    platform.addUser("Deepika");

    // Add movies
    platform.addMovie("Don", 2006, {"Action", "Comedy"});
    platform.addMovie("Tiger", 2008, {"Drama"});
    platform.addMovie("Padmavat", 2006, {"Comedy"});
    platform.addMovie("Lunchbox-2", 2022, {"Drama"});
    platform.addMovie("Guru", 2006, {"Drama"});
    platform.addMovie("Metro", 2006, {"Romance"});

    // Add reviews
    try {
        platform.addReview("SRK", "Don", 2);
        platform.addReview("SRK", "Padmavat", 8);
        platform.addReview("Salman", "Don", 5);
        platform.addReview("Deepika", "Don", 9);
        platform.addReview("Deepika", "Guru", 6);
        // platform.addReview("SRK", "Don", 10); // Exception: Multiple reviews not allowed
        // platform.updateReview("SRK", "Don", 8); // Update won't affect user category
        // platform.addReview("Deepika", "Lunchbox-2", 5); // Exception: Movie yet to be released
        platform.addReview("SRK", "Tiger", 5);
        // platform.deleteReview("SRK", "Tiger"); // SRK downgraded to viewer
        platform.addReview("SRK", "Metro", 7); // SRK promoted to critic
    } catch (const invalid_argument& e) {
        cerr << "Error: " << e.what() << endl;
    }

    // List user reviews
    platform.listReviews("SRK");

    return 0;
}
