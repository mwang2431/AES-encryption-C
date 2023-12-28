
#include <stdio.h>
#include "aes.h"
#include "generate_key.h"
/////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////

int main (int argc, char *argv[])
{
    // 256 bit key
    unsigned char key[AES_KEY_SIZE];

    // A 128 bit IV
    unsigned char iv[AES_BLOCK_SIZE];

    unsigned char plaintext[128];

    /* Message to be encrypted */
    if(argc == 2)
    {
    	strcpy((char *)plaintext, argv[1]);
    }
    else
    {
    	strcpy((char *)plaintext, "admin123");
    }
    /*
     * Buffer for ciphertext. Ensure the buffer is long enough for the
     * ciphertext which may be longer than the plaintext, depending on the
     * algorithm and mode.
     */
    unsigned char ciphertext[128];

    /* Buffer for the decrypted text */
    unsigned char decryptedtext[128];

    int decryptedtext_len, ciphertext_len;

    // generate 256-bit key and 128-bit iv
    generate_random_chars(key, AES_KEY_SIZE);
    generate_random_chars(iv, AES_BLOCK_SIZE);

    // Encrypt the plaintext
    ciphertext_len = encrypt (plaintext, strlen ((char *)plaintext), key, iv,
                              ciphertext);

    // print out encrypted text
    printf("Encrypted text is:\n");
    BIO_dump_fp (stdout, (const char *)ciphertext, ciphertext_len);

    // Decrypt the ciphertext
    decryptedtext_len = decrypt(ciphertext, ciphertext_len, key, iv,
                                decryptedtext);

    // Add a NULL terminator. We are expecting printable text
    decryptedtext[decryptedtext_len] = '\0';

    // print out the decrypted text
    printf("Decrypted text is:\n");
    printf("%s\n", decryptedtext);


    return 0;
}
