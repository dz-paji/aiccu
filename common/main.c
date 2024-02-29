#include "hash_evp.h"
#include <stdio.h>
#include <string.h>
#include <openssl/evp.h>

int main()
{
    uint8_t digest[64];
    unsigned char msg[] = "admin";
    // char sChallenge[1024];
    // char salt[] = "RmgC.8eAtKJUAfs97KCZ!R96p*BuZKyu";
    // SHA256(msg, digest, strlen(msg));
    // printf("Digest: %s\n", digest);

    // snprintf(sChallenge, sizeof(sChallenge), "%s%s", salt, digest);
    // printf("sChallenge: %s\n", sChallenge);

    // SHA256(sChallenge, digest, strlen(sChallenge));
    // printf("Digest: %s\n", digest);

    EVP_MD_CTX *md = EVP_MD_CTX_create();

    SHA256Init(md);
	SHA256Update(md, (uint8_t *)msg, (unsigned int)strlen(msg));
	SHA256Final(md, digest);
    printf("Digest: %s\n", digest);
    return 0;
}