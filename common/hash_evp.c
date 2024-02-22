#include "hash_evp.h"
#include <stdio.h>
#include <string.h>

void SHA256(const char *message, char *digest, unsigned int siglen)
{
    EVP_MD_CTX *mdctx;
    const EVP_MD *md;
    unsigned char md_value[EVP_MAX_MD_SIZE];
    unsigned int i, md_len;

    OpenSSL_add_all_digests();
    md = EVP_get_digestbyname("sha256");

    if(!md) {
        printf("Unknown message digest\n");
        return;
    }

    mdctx = EVP_MD_CTX_create();
    EVP_DigestInit_ex(mdctx, md, NULL);
    EVP_DigestUpdate(mdctx, message, siglen);
    EVP_DigestFinal_ex(mdctx, md_value, &md_len);
    EVP_MD_CTX_destroy(mdctx);

    for (i = 0; i < md_len; i++) {
        snprintf(digest + (i * 2), 3, "%02x", md_value[i]);
    }
    EVP_cleanup();
    return;
}