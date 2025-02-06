# Trivia Game with Messaging Panel

You can see a preview of how the app works by watching this short video: [How the app works](https://youtube.com/shorts/qr_Ne4vKZEU).

## Description
This documentation provides a detailed overview of the Android mobile application developed to offer users an interactive platform for communication and entertainment through quizzes. The application allows users to authenticate, participate in various customized quizzes based on category and difficulty, and interact through messaging within the community. Additionally, the app includes a competitive component, enabling users to view their scores and overall ranking.

## Purpose
The main goal of this application is to create an engaging and educational experience for users, allowing them to enhance their general and technical knowledge in a fun and interactive way. The app encourages continuous learning and healthy competition through quiz questions covering various fields, from cybersecurity to programming and networking.

## Key Features
- **Authentication & Registration:** Users can create personal accounts and log in.
- **Real-time Messaging:** Users can send and receive messages.
- **Interactive Quiz:** Participate in quizzes with multiple difficulty levels and categories.
- **Custom Configuration:** Users can choose quiz categories and difficulty levels.
- **Leaderboard & Scores:** Displays scores and rankings to promote competition.

## Technologies Used
The application uses Firebase for authentication, data storage, and quiz session management. The user interface is built using Android Studio, following material design principles for a smooth and intuitive experience.

## Application Structure
This documentation details each component of the application, from initial setup to a detailed description of each activity and functionality. Error handling and navigation between different screens are also explained to help developers and end users efficiently understand and navigate the app.

## Key Components
### **AndroidManifest.xml**
This file provides essential information about the application to the Android operating system, including app components (activities, services, broadcast receivers, content providers) and required permissions.

### **Structure & Key Elements**
1. **Permissions:**
   - `android.permission.INTERNET`: Allows the app to open network sockets.
   - `android.permission.ACCESS_NETWORK_STATE`: Access network information to determine if an internet connection is available.

2. **Application Configurations:**
   - `allowBackup`: Enables or disables app data backup.
   - `icon`, `roundIcon`: App icons.
   - `label`: App name displayed on the device.
   - `supportsRtl`: Support for right-to-left reading mode.
   - `theme`: App theme configuration.
   - `usesCleartextTraffic`: Allows or disallows unencrypted traffic.
   - `networkSecurityConfig`: Defines network security configurations.

3. **Activities:**
   - `MainActivity`: Entry point, configured as LAUNCHER.
   - `HomeActivity`: Accessed after authentication, allows messaging.
   - `QuizMenuActivity`: For quiz category and difficulty selection.
   - `CategorySelectionActivity`: Enables users to select a quiz category.
   - `TriviaActivity`: Hosts the quiz interface.
   - `ScoreboardActivity`: Displays user scores.
   - `RegisterActivity`: Allows user registration.

## **Navigation & Hierarchy**
Activities are configured using `parentActivityName`, ensuring intuitive navigation. Special configurations are included to handle screen rotations and size changes without recreating the activity.

## **Core Components**
### **1. MainActivity**
- Handles user login and registration.
- Includes options for password reset.
- Uses Firebase for authentication.

### **2. HomeActivity**
- Manages user messaging functionality.
- Loads and displays messages from Firebase.
- Allows users to send messages in real time.

### **3. Firebase Integration**
- **Firebase Authentication:** Manages user authentication.
- **Firebase Database:** Stores and retrieves messages.

### **4. User Flow**
1. **Login:** Users enter credentials and authenticate.
2. **Registration:** New users create an account.
3. **Password Reset:** Users can request a password reset via email.
4. **Messaging:** Users send and view messages after logging in.

### **5. Error Handling**
- Authentication errors are displayed using toast messages.
- Network/server issues are communicated to the user via appropriate messages.

## **Additional Components**
### **1. RegisterActivity**
- Handles new user registration.
- Ensures password confirmation and email validation.

### **2. Message System**
- Users can send and receive messages.
- Messages include user ID, email, text, and timestamp.
- Stored and retrieved from Firebase.

### **3. Quiz Components**
- **CategorySelectionActivity:** Enables category selection for quizzes.
- **QuizMenuActivity:** Allows users to choose difficulty levels.
- **QuizTimer:** Manages countdown for quiz questions.
- **TriviaActivity:** Handles quiz interactions, scoring, and feedback.

### **4. Notification System**
- Custom notifications for correct, incorrect, or time-expired answers.
- Provides visual and auditory feedback to users.

### **5. Scoreboard & Ranking**
- **ScoreboardActivity:** Displays user scores with sorting options.
- **ScoreEntry:** Represents user scores, including accuracy calculations.
- **ScoreboardAdapter:** Manages score display in a RecyclerView.

## **User Interaction Flow**
1. Users authenticate or register.
2. They select a quiz category and difficulty level.
3. The quiz starts with a countdown timer.
4. Users answer questions, receive immediate feedback, and track their score.
5. At the end of the quiz, scores are updated, and rankings are displayed.

## **Conclusion**
This application provides an engaging way for users to test and improve their knowledge while interacting with others in a competitive environment. The integration of Firebase ensures seamless authentication and real-time messaging, while intuitive navigation and responsive design enhance the overall user experience.

