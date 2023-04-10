#include <iostream>
#include <string>

using namespace std;

string encrypt(string message, int shift_count)
{
    string encrypted_message = "";

    for (int i = 0; i < message.size(); i++) {
        if (isupper(message[i])) {
        encrypted_message+=char(int(message[i] + shift_count - 65) % 26 + 65);
        }
        else if (islower(message[i])) {
            encrypted_message += char(int(message[i] + shift_count - 97) % 26 + 97);
        }
        else
		 {
            encrypted_message += message[i];
        }
    }

    return encrypted_message;
}

string decrypt(string encrypted_message, int shift_count)
{
    return encrypt(encrypted_message, 26 - shift_count);
}

int main()
{
    string message = "holla ";
    int shift_count = 7;

    string encrypted_message = encrypt(message, shift_count);
    string decrypted_message = decrypt(encrypted_message, shift_count);

    cout << "initial message: " << message << endl;
    cout << "encryptedmessage: " << encrypted_message << endl;
    cout << "decryptedmessage: " << decrypted_message << endl;

    return 0;
}