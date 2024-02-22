#include "hash_evp.h"
#include <stdio.h>
#include <string.h>
#include <openssl/evp.h>

int main()
{
    unsigned char digest[64];
    unsigned char msg[] = "admin";
    char sChallenge[1024];
    char salt[] = "RmgC.8eAtKJUAfs97KCZ!R96p*BuZKyu";
    SHA256(msg, digest, strlen(msg));
    printf("Digest: %s\n", digest);

    snprintf(sChallenge, sizeof(sChallenge), "%s%s", salt, digest);
    printf("sChallenge: %s\n", sChallenge);

    SHA256(sChallenge, digest, strlen(sChallenge));
    printf("Digest: %s\n", digest);
    return 0;
}