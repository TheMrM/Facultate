package com.example.textapp;

import com.google.firebase.database.DatabaseReference;

public class TriviaQuestionManager {

    public static void createSecurityQuestions(DatabaseReference triviaRef) {
        // Create first question
        triviaRef.child("security1").child("questionText").setValue("What is Phishing?");
        triviaRef.child("security1").child("answer").child("0").setValue("A type of computer virus");
        triviaRef.child("security1").child("answer").child("1").setValue("An attempt to acquire sensitive information");
        triviaRef.child("security1").child("answer").child("2").setValue("A firewall technology");
        triviaRef.child("security1").child("answer").child("3").setValue("A data analysis technique");
        triviaRef.child("security1").child("correctAnswer").setValue(1);

        // Question 2
        triviaRef.child("security2").child("questionText").setValue("Which of these is considered a strong password?");
        triviaRef.child("security2").child("answer").child("0").setValue("123456");
        triviaRef.child("security2").child("answer").child("1").setValue("password123");
        triviaRef.child("security2").child("answer").child("2").setValue("yourname123");
        triviaRef.child("security2").child("answer").child("3").setValue("9v!pS*42");
        triviaRef.child("security2").child("correctAnswer").setValue(3);

        // Question 3
        triviaRef.child("security3").child("questionText").setValue("What does HTTPS stand for?");
        triviaRef.child("security3").child("answer").child("0").setValue("HyperText Transfer Protocol Secure");
        triviaRef.child("security3").child("answer").child("1").setValue("HyperText Transfer Protocol Simple");
        triviaRef.child("security3").child("answer").child("2").setValue("HyperText Transfer Product Secure");
        triviaRef.child("security3").child("answer").child("3").setValue("HyperText Test Protocol Secure");
        triviaRef.child("security3").child("correctAnswer").setValue(0);

        // Question 4
        triviaRef.child("security4").child("questionText").setValue("Which of the following is not a type of malware?");
        triviaRef.child("security4").child("answer").child("0").setValue("Virus");
        triviaRef.child("security4").child("answer").child("1").setValue("Trojan");
        triviaRef.child("security4").child("answer").child("2").setValue("Worm");
        triviaRef.child("security4").child("answer").child("3").setValue("Cipher");
        triviaRef.child("security4").child("correctAnswer").setValue(3);

        // Question 5
        triviaRef.child("security5").child("questionText").setValue("What is the main purpose of a VPN?");
        triviaRef.child("security5").child("answer").child("0").setValue("To increase internet speed");
        triviaRef.child("security5").child("answer").child("1").setValue("To monitor data");
        triviaRef.child("security5").child("answer").child("2").setValue("To secure internet connection");
        triviaRef.child("security5").child("answer").child("3").setValue("To provide storage space");
        triviaRef.child("security5").child("correctAnswer").setValue(2);

        // Question 6
        triviaRef.child("security6").child("questionText").setValue("What is a Man-in-the-Middle attack?");
        triviaRef.child("security6").child("answer").child("0").setValue("An attack where the attacker secretly relays and possibly alters the communications between two parties who believe they are directly communicating with each other.");
        triviaRef.child("security6").child("answer").child("1").setValue("An attack that sends unsolicited messages over Bluetooth to mobile phones.");
        triviaRef.child("security6").child("answer").child("2").setValue("A software that enables administrator-level access to a computer network.");
        triviaRef.child("security6").child("answer").child("3").setValue("A malware that locks or encrypts data, demanding a ransom to restore access.");
        triviaRef.child("security6").child("correctAnswer").setValue(0);

        // Question 7
        triviaRef.child("security7").child("questionText").setValue("What is the function of a firewall?");
        triviaRef.child("security7").child("answer").child("0").setValue("To manage the data sent to the internet");
        triviaRef.child("security7").child("answer").child("1").setValue("To protect a computer network from unauthorized access");
        triviaRef.child("security7").child("answer").child("2").setValue("To enhance the performance of network connections");
        triviaRef.child("security7").child("answer").child("3").setValue("To provide data storage solutions");
        triviaRef.child("security7").child("correctAnswer").setValue(1);

        // Question 8
        triviaRef.child("security8").child("questionText").setValue("Which technology is used to record cryptocurrency transactions?");
        triviaRef.child("security8").child("answer").child("0").setValue("Digital metering");
        triviaRef.child("security8").child("answer").child("1").setValue("Blockchain");
        triviaRef.child("security8").child("answer").child("2").setValue("Cloud computing");
        triviaRef.child("security8").child("answer").child("3").setValue("SQL databases");
        triviaRef.child("security8").child("correctAnswer").setValue(1);

        // Question 9
        triviaRef.child("security9").child("questionText").setValue("What type of cyber-attack involves overwhelming the victim's system with excessive requests?");
        triviaRef.child("security9").child("answer").child("0").setValue("SQL Injection");
        triviaRef.child("security9").child("answer").child("1").setValue("Phishing");
        triviaRef.child("security9").child("answer").child("2").setValue("Denial of Service (DoS)");
        triviaRef.child("security9").child("answer").child("3").setValue("Cross-site Scripting (XSS)");
        triviaRef.child("security9").child("correctAnswer").setValue(2);

        // Question 10
        triviaRef.child("security10").child("questionText").setValue("Which security measure helps to verify the user's identity by requiring multiple pieces of evidence?");
        triviaRef.child("security10").child("answer").child("0").setValue("Encryption");
        triviaRef.child("security10").child("answer").child("1").setValue("Antivirus software");
        triviaRef.child("security10").child("answer").child("2").setValue("Multi-factor authentication");
        triviaRef.child("security10").child("answer").child("3").setValue("Firewall");
        triviaRef.child("security10").child("correctAnswer").setValue(2);
    }

    public static void createNetworkingQuestions(DatabaseReference triviaRef) {
        // Question 1
        triviaRef.child("networking1").child("questionText").setValue("What does IP stand for in the context of networking?");
        triviaRef.child("networking1").child("answer").child("0").setValue("Internet Provider");
        triviaRef.child("networking1").child("answer").child("1").setValue("Internet Port");
        triviaRef.child("networking1").child("answer").child("2").setValue("Internet Protocol");
        triviaRef.child("networking1").child("answer").child("3").setValue("Internal Protocol");
        triviaRef.child("networking1").child("correctAnswer").setValue(2);

        // Question 2
        triviaRef.child("networking2").child("questionText").setValue("Which device forwards data packets between computer networks?");
        triviaRef.child("networking2").child("answer").child("0").setValue("Switch");
        triviaRef.child("networking2").child("answer").child("1").setValue("Router");
        triviaRef.child("networking2").child("answer").child("2").setValue("Hub");
        triviaRef.child("networking2").child("answer").child("3").setValue("Repeater");
        triviaRef.child("networking2").child("correctAnswer").setValue(1);

        // Question 3
        triviaRef.child("networking3").child("questionText").setValue("What is a subnet mask used for?");
        triviaRef.child("networking3").child("answer").child("0").setValue("To identify the network and host portions of an IP address");
        triviaRef.child("networking3").child("answer").child("1").setValue("To encrypt data traffic on a network");
        triviaRef.child("networking3").child("answer").child("2").setValue("To boost the signal strength of a network");
        triviaRef.child("networking3").child("answer").child("3").setValue("To detect network intrusions");
        triviaRef.child("networking3").child("correctAnswer").setValue(0);

        // Question 4
        triviaRef.child("networking4").child("questionText").setValue("What protocol is used to find the hardware address of a local device?");
        triviaRef.child("networking4").child("answer").child("0").setValue("RARP");
        triviaRef.child("networking4").child("answer").child("1").setValue("ARP");
        triviaRef.child("networking4").child("answer").child("2").setValue("TCP");
        triviaRef.child("networking4").child("answer").child("3").setValue("UDP");
        triviaRef.child("networking4").child("correctAnswer").setValue(1);

        // Question 5
        triviaRef.child("networking5").child("questionText").setValue("What is the main purpose of the OSI model?");
        triviaRef.child("networking5").child("answer").child("0").setValue("To define network standards and protocols");
        triviaRef.child("networking5").child("answer").child("1").setValue("To create and distribute Internet access");
        triviaRef.child("networking5").child("answer").child("2").setValue("To develop software applications");
        triviaRef.child("networking5").child("answer").child("3").setValue("To monitor network traffic");
        triviaRef.child("networking5").child("correctAnswer").setValue(0);

        // Question 6
        triviaRef.child("networking6").child("questionText").setValue("Which layer of the OSI model is responsible for end-to-end communication?");
        triviaRef.child("networking6").child("answer").child("0").setValue("Transport");
        triviaRef.child("networking6").child("answer").child("1").setValue("Network");
        triviaRef.child("networking6").child("answer").child("2").setValue("Data Link");
        triviaRef.child("networking6").child("answer").child("3").setValue("Physical");
        triviaRef.child("networking6").child("correctAnswer").setValue(0);

        // Question 7
        triviaRef.child("networking7").child("questionText").setValue("What type of cable is used to connect a computer to a switch?");
        triviaRef.child("networking7").child("answer").child("0").setValue("Coaxial");
        triviaRef.child("networking7").child("answer").child("1").setValue("Fiber optic");
        triviaRef.child("networking7").child("answer").child("2").setValue("Twisted pair");
        triviaRef.child("networking7").child("answer").child("3").setValue("USB");
        triviaRef.child("networking7").child("correctAnswer").setValue(2);

        // Question 8
        triviaRef.child("networking8").child("questionText").setValue("What is the purpose of a DHCP server?");
        triviaRef.child("networking8").child("answer").child("0").setValue("To provide dynamic IP addresses to devices on a network");
        triviaRef.child("networking8").child("answer").child("1").setValue("To filter out unwanted network traffic");
        triviaRef.child("networking8").child("answer").child("2").setValue("To encrypt network traffic");
        triviaRef.child("networking8").child("answer").child("3").setValue("To provide storage for network data");
        triviaRef.child("networking8").child("correctAnswer").setValue(0);

        // Question 9
        triviaRef.child("networking9").child("questionText").setValue("What protocol provides secure communications over the Internet?");
        triviaRef.child("networking9").child("answer").child("0").setValue("HTTP");
        triviaRef.child("networking9").child("answer").child("1").setValue("HTTPS");
        triviaRef.child("networking9").child("answer").child("2").setValue("FTP");
        triviaRef.child("networking9").child("answer").child("3").setValue("SMTP");
        triviaRef.child("networking9").child("correctAnswer").setValue(1);

        // Question 10
        triviaRef.child("networking10").child("questionText").setValue("What is the primary function of ARP?");
        triviaRef.child("networking10").child("answer").child("0").setValue("Translate URLs to IP addresses");
        triviaRef.child("networking10").child("answer").child("1").setValue("Resolve domain names to MAC addresses");
        triviaRef.child("networking10").child("answer").child("2").setValue("Resolve IP addresses to MAC addresses");
        triviaRef.child("networking10").child("answer").child("3").setValue("Encrypt data packets");
        triviaRef.child("networking10").child("correctAnswer").setValue(2);
    }

    public static void createProgrammingQuestions(DatabaseReference triviaRef) {
        // Question 1
        triviaRef.child("programming1").child("questionText").setValue("Which language is primarily used for Android App Development?");
        triviaRef.child("programming1").child("answer").child("0").setValue("Swift");
        triviaRef.child("programming1").child("answer").child("1").setValue("Java");
        triviaRef.child("programming1").child("answer").child("2").setValue("Kotlin");
        triviaRef.child("programming1").child("answer").child("3").setValue("C#");
        triviaRef.child("programming1").child("correctAnswer").setValue(2);

        // Question 2
        triviaRef.child("programming2").child("questionText").setValue("What does 'OOP' stand for in computer programming?");
        triviaRef.child("programming2").child("answer").child("0").setValue("Only Object Programming");
        triviaRef.child("programming2").child("answer").child("1").setValue("Object Oriented Programming");
        triviaRef.child("programming2").child("answer").child("2").setValue("Oriented Object Programming");
        triviaRef.child("programming2").child("answer").child("3").setValue("Objects and Procedures Programming");
        triviaRef.child("programming2").child("correctAnswer").setValue(1);

        // Question 3
        triviaRef.child("programming3").child("questionText").setValue("What is the purpose of the 'finally' block in Java?");
        triviaRef.child("programming3").child("answer").child("0").setValue("To execute code after a try-catch block regardless of an exception being thrown");
        triviaRef.child("programming3").child("answer").child("1").setValue("To handle exceptions");
        triviaRef.child("programming3").child("answer").child("2").setValue("To finalize variables");
        triviaRef.child("programming3").child("answer").child("3").setValue("To improve performance");
        triviaRef.child("programming3").child("correctAnswer").setValue(0);

        // Question 4
        triviaRef.child("programming4").child("questionText").setValue("Which data structure uses LIFO (Last In, First Out) principle?");
        triviaRef.child("programming4").child("answer").child("0").setValue("Queue");
        triviaRef.child("programming4").child("answer").child("1").setValue("Stack");
        triviaRef.child("programming4").child("answer").child("2").setValue("LinkedList");
        triviaRef.child("programming4").child("answer").child("3").setValue("Array");
        triviaRef.child("programming4").child("correctAnswer").setValue(1);

        // Question 5
        triviaRef.child("programming5").child("questionText").setValue("What is a common use of Python's 'decorators'?");
        triviaRef.child("programming5").child("answer").child("0").setValue("To add new keywords to the language");
        triviaRef.child("programming5").child("answer").child("1").setValue("To enhance the functionality of a function or method");
        triviaRef.child("programming5").child("answer").child("2").setValue("To declare classes");
        triviaRef.child("programming5").child("answer").child("3").setValue("To debug programs");
        triviaRef.child("programming5").child("correctAnswer").setValue(1);

        // Question 6
        triviaRef.child("programming6").child("questionText").setValue("Which HTML tag is used to define an internal style sheet?");
        triviaRef.child("programming6").child("answer").child("0").setValue("<style>");
        triviaRef.child("programming6").child("answer").child("1").setValue("<script>");
        triviaRef.child("programming6").child("answer").child("2").setValue("<link>");
        triviaRef.child("programming6").child("answer").child("3").setValue("<css>");
        triviaRef.child("programming6").child("correctAnswer").setValue(0);

        // Question 7
        triviaRef.child("programming7").child("questionText").setValue("What is the correct JSON format for an array?");
        triviaRef.child("programming7").child("answer").child("0").setValue("{ 'data': [1, 2, 3] }");
        triviaRef.child("programming7").child("answer").child("1").setValue("[1, 2, 3]");
        triviaRef.child("programming7").child("answer").child("2").setValue("{ 'data': 1, 2, 3 }");
        triviaRef.child("programming7").child("answer").child("3").setValue("[{ 'data': 1 }, { 'data': 2 }, { 'data': 3 }]");
        triviaRef.child("programming7").child("correctAnswer").setValue(1);

        // Question 8
        triviaRef.child("programming8").child("questionText").setValue("Which protocol is primarily used for sending email?");
        triviaRef.child("programming8").child("answer").child("0").setValue("HTTP");
        triviaRef.child("programming8").child("answer").child("1").setValue("SMTP");
        triviaRef.child("programming8").child("answer").child("2").setValue("FTP");
        triviaRef.child("programming8").child("answer").child("3").setValue("IMAP");
        triviaRef.child("programming8").child("correctAnswer").setValue(1);

        // Question 9
        triviaRef.child("programming9").child("questionText").setValue("What does SQL stand for?");
        triviaRef.child("programming9").child("answer").child("0").setValue("Structured Question Language");
        triviaRef.child("programming9").child("answer").child("1").setValue("Structured Query Language");
        triviaRef.child("programming9").child("answer").child("2").setValue("Statement Question Language");
        triviaRef.child("programming9").child("answer").child("3").setValue("Stylesheet Query Language");
        triviaRef.child("programming9").child("correctAnswer").setValue(1);

        // Question 10
        triviaRef.child("programming10").child("questionText").setValue("What is the main advantage of using Git?");
        triviaRef.child("programming10").child("answer").child("0").setValue("Centralized version control");
        triviaRef.child("programming10").child("answer").child("1").setValue("Distributed version control");
        triviaRef.child("programming10").child("answer").child("2").setValue("Client-server architecture");
        triviaRef.child("programming10").child("answer").child("3").setValue("Linear development");
        triviaRef.child("programming10").child("correctAnswer").setValue(1);
    }
}
