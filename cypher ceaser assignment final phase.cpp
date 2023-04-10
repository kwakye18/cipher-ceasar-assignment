#include <iostream>
#include <string>

using namespace std;

string encrypt(string message, int shiftcount, string decryptedmessage, string encrypted_message)
{
    encrypted_message = "";

    for (int i = 0; i < message.size(); i++) {
        if (isupper(message[i])) {
        encrypted_message+=char(int(message[i] + shiftcount - 65) % 26 + 65);
        }
        else if (islower(message[i])) {
            encrypted_message += char(int(message[i] + shiftcount - 97) % 26 + 97);
        }
        else
   {
            encrypted_message += message[i];
        }
    }

    return encrypted_message;
}

string decrypt(string encryptedmessage, int shift_count)
{
    return encrypt(encryptedmessage, shift_count, "", "");
}

int main()
{
    // allowing user to enter some inputs
    string message, decrypted_message, encrypted_message;
    int shift_count;

    cout << "Enter the message you want to encrypt: ";
    getline(cin, message);

    cout << "Enter the shift count: ";
    cin >> shift_count;

    // call the encryption function
    encrypted_message = encrypt(message, shift_count, decrypted_message, encrypted_message);

    // print the encrypted message
    cout << "Encrypted message: " << encrypted_message << endl;

    // call the decryption function
    decrypted_message = decrypt(encrypted_message, shift_count);

    // print the decrypted message
    cout << "Decrypted message: " << decrypted_message << endl;

    return 0;
}