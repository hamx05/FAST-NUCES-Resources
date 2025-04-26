#include <iostream>
#include <vector>
#include <functional>
using namespace std;

class User {
    protected:
        string username;
        string email;
        string hashedPassword;

        string hashPassword(const string& password) const {
            hash<string> hasher;
            return to_string(hasher(password));
        }
    
    public:
        User () {}
        User (string UN, string EM, const string& _PW) {
            username = UN;
            email = EM;
            hashedPassword = hashPassword(_PW); 
        }

        // Method to verify password
        bool verifyPassword(const string& PW) const {
            return hashPassword(PW) == hashedPassword;
        }
};

class Post {
    protected:
        static int nextID;
        int postID;
        int likes;
        int noOfComments;
        int views;
        string content;
        vector <string> comments;
        vector<Post> likedPosts;

    public:
        Post () {}
        Post(string content) {
            this->content = content;
            likes = 0;
            noOfComments = 0;
            views = 0;
            nextID++;
            postID = nextID;
        }
        
        const int getLikes () {
            return likes;
        }
        const int getComments () {
            return noOfComments;
        }
        const int getViews () {
            return views;
        }
        vector<Post> getLikedPosts() const {
            return likedPosts;
        }
        void view (Post &post) {
            post.views++;
        }
        void like(Post &post) {
            post.likes++;
        }
        void increaseComment(Post &post) {
            post.noOfComments++;
        }

        void displayComments () {
            for (int i=0; i<comments.size(); i++) {
                cout<< "Comment " << i+1 << ": " << comments[i] << endl;
            }
        }

        void addComment (Post &post) { // user sends the reference to post on which they want to add the comment.
            string cmt;
            cout<<"Enter the comment: ";
            getline(cin, cmt);
            comments.push_back(cmt);    
            increaseComment(post);            
        }

        // void likePost(RegularUser &user, Post &post) {
        //     cout << "You have liked this post." << endl;
        //     likes++;
        //     user.likedPosts.push_back(post);
        // }
        

        void displayPostDetails () const {
            cout<<"Post ID: " << postID << endl;
            cout<<"Content: " << content << endl;
            cout<<"Likes: " << likes << ", Comments: " << noOfComments << ", Views: " << views << endl;
        }

        void multiplyLikes(int num, Post &post) {
            post.likes *= num;
        }

        void multiplyViews(int num, Post &post) {
            post.views *= num;
        }
};

int Post::nextID = 0;

class RegularUser : public User, public Post {
    protected:
    //The RegularUser class maintains an array feed to store pointers to Post objects
    static const int MAX_FEED_SIZE = 10;
    vector <Post> feed;

    public:
        RegularUser () {}
        RegularUser (string UN, string EM, string PW) : User(UN, EM, PW) {}
        
        void addToFeed(const Post &post) {
            if (feed.size() < MAX_FEED_SIZE) {
                feed.push_back(post);
                cout<<"You have added a post to your feed." << endl;
            } else {
                cout<<"More posts cannot be added because the feed limit has been reached." << endl;
            }
        } 

        void viewFeed() const {
            for (vector<Post>::const_iterator it = feed.begin(); it != feed.end(); ++it) {
                it->displayPostDetails();
                cout<<endl;
            }
        }
};

class BusinessUser : public User, public Post {
    protected:
        static const int MAX_PROMOTED_POSTS = 10;
        int promotedPostsCount;

    public:
        BusinessUser () {}
        BusinessUser (string UN, string EM, string PW) : User(UN, EM, PW) {
            promotedPostsCount = 0;
        }

        void promotePost(Post &post) {
            if (promotedPostsCount < MAX_PROMOTED_POSTS) {
                post.multiplyLikes(2, post);
                post.multiplyViews(3, post);
                promotedPostsCount++;
                cout<<"Post Promotion Successful. Your post have gained " << post.getLikes() << " likes and " << post.getViews() << " views after promotion." << endl;
            } else {
                cout<<"Post Promotion failed because promotion limit has been reached i.e. 10." << endl;
            }
        }

        int likesTrack (Post &post) {
            cout<<"You have " << post.getLikes() << " likes on this post." << endl;
        }
        
        int commentsTrack (Post &post) {
            cout<<"You have " << post.getComments() << " comments on this post." << endl;
        }

        int viewsTrack (Post &post) {
            cout<<"You have " << post.getViews() << " views on this post." << endl;
        }

};

int main() {
    cout<<"*************************" << endl;
    cout<<"* Name: Muhammad Hammad *" << endl;
    cout<<"* Roll Number: 23K-2005 *" << endl;
    cout<<"*************************" << endl << endl;
    cout<<"-----------------------------------------------------------------------" << endl;
    cout<<"\t\tVerifying User and Matching Password" << endl;
    User user("exampleUser", "user@example.com", "securePassword");
    cout << "Password is " << (user.verifyPassword("securePassword") ? "correct" : "incorrect") << endl;

    RegularUser RegU("user1", "user1@example.com", "password1");
    BusinessUser BizU("business1", "business1@example.com", "password2");
    Post post1("Test Post 1");
    Post post2("Test Post 2");
    Post post3("Test Post 3");
    
    cout<<"-----------------------------------------------------------------------" << endl;
    cout<<"\t\tLiking and Adding Comment on Post 1" << endl;
    RegU.like(post1);
    RegU.addComment(post1);

    cout<<"-----------------------------------------------------------------------" << endl;
    cout<<"\t\tDisplaying Comment on Post 1" << endl;
    RegU.displayComments();

    cout<<"-----------------------------------------------------------------------" << endl;
    cout<<"\t\tAdding Posts To Feed of Regular User" << endl;
    RegU.addToFeed(post1);
    RegU.addToFeed(post2);

    cout<<"-----------------------------------------------------------------------" << endl;
    cout<<"\t\tViewing Feed of Regular User" << endl;
    RegU.viewFeed();

    cout<<"-----------------------------------------------------------------------" << endl;
    cout<<"\t\tLiking and Adding Comment on Post 3" << endl;
    BizU.view(post3);
    BizU.like(post3);
    BizU.like(post3);
    BizU.addComment(post3);

    cout<<"-----------------------------------------------------------------------" << endl;
    cout<<"\t\tDisplaying Comment on Post 3" << endl;
    BizU.displayComments();

    cout<<"-----------------------------------------------------------------------" << endl;
    cout<<"\t\tPromoting Posts for Business User" << endl;
    BizU.promotePost(post3);

    return 0;
}