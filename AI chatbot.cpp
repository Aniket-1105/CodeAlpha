#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

// Simple sentiment analysis function
string analyzeSentiment(const string& input) {
    vector<string> positiveWords = {"good", "great", "excellent", "happy", "love", "amazing"};
    vector<string> negativeWords = {"bad", "sad", "terrible", "hate", "awful", "angry"};

    int positiveCount = 0, negativeCount = 0;
    string word;
    for (char ch : input) {
        if (isalpha(ch)) {
            word += tolower(ch);
        } else if (!word.empty()) {
            if (find(positiveWords.begin(), positiveWords.end(), word) != positiveWords.end())
                positiveCount++;
            else if (find(negativeWords.begin(), negativeWords.end(), word) != negativeWords.end())
                negativeCount++;
            word.clear();
        }
    }
    if (!word.empty()) {
        if (find(positiveWords.begin(), positiveWords.end(), word) != positiveWords.end())
            positiveCount++;
        else if (find(negativeWords.begin(), negativeWords.end(), word) != negativeWords.end())
            negativeCount++;
    }

    if (positiveCount > negativeCount)
        return "Positive";
    else if (negativeCount > positiveCount)
        return "Negative";
    else
        return "Neutral";
}

// Simple rule-based dialogue management
string manageDialogue(const string& input) {
    unordered_map<string, string> responses = {
        {"hello", "Hi there! How can I help you today?"},
        {"how are you", "I'm just a program, but I'm doing great! How about you?"},
        {"what is your name", "I'm ChatGPT, your AI assistant."},
        {"bye", "Goodbye! Have a great day!"}
    };

    string lowerInput = input;
    transform(lowerInput.begin(), lowerInput.end(), lowerInput.begin(), ::tolower);

    for (const auto& [key, response] : responses) {
        if (lowerInput.find(key) != string::npos) {
            return response;
        }
    }
    return "I'm sorry, I didn't understand that. Could you please elaborate?";
}

// Simple question-answering system
string answerQuestion(const string& input) {
    if (input.find("what is") != string::npos) {
        return "That's a complex question. I recommend checking reliable sources for accurate information.";
    }
    if (input.find("who is") != string::npos) {
        return "I'm not sure, but I can help you look it up if you'd like!";
    }
    if (input.find("why") != string::npos) {
        return "That's a deep question. Can you provide more context?";
    }
    return "I'm not sure how to answer that. Could you ask it differently?";
}

// Main chatbot function
void chatbot() {
    cout << "AI Chatbot: Hello! How can I assist you today?" << endl;

    while (true) {
        cout << "You: ";
        string input;
        getline(cin, input);

        if (input == "exit" || input == "quit") {
            cout << "AI Chatbot: Goodbye!" << endl;
            break;
        }

        // Perform sentiment analysis
        string sentiment = analyzeSentiment(input);
        cout << "AI Chatbot [Sentiment: " << sentiment << "]: ";

        // Manage dialogue or answer questions
        if (input.find("?") != string::npos) {
            cout << answerQuestion(input) << endl;
        } else {
            cout << manageDialogue(input) << endl;
        }
    }
}

int main() {
    chatbot();
    return 0;
}
