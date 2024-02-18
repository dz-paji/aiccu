#include "hash_md5.h"
#include <stdio.h>
#include <string.h>

void md5_hash(const char *sString, char *sSignature, unsigned int siglen)
{
	struct MD5Context	md5c;
	unsigned char		signature[16];
	unsigned int		i;
	
	if (siglen < 32) return;

	/* Initialize MD5 structure */
	MD5Init(&md5c);
	/* Calculate MD5 of the string */
	MD5Update(&md5c, (unsigned char *)sString, (unsigned int)strlen(sString));
	MD5Final(signature, &md5c);
	
	memset(sSignature, 0, siglen);

	for (i=0; i < sizeof(signature); i++)
	{
		snprintf(&sSignature[i*2], 3, "%02x", signature[i]);
	}
}

int main() {
    char buf[1024], sSignature[33], sChallenge[1024];
    char output[33];
    char *password = "admin";
    strcpy(buf, "60d11a81a26df3738026b1839644a1ae");
	md5_hash(password, sSignature, sizeof(sSignature));
    printf("calculated hash of password is: %s\n", sSignature);
	snprintf(sChallenge, sizeof(sChallenge), "%s%s", &buf, sSignature);
    printf("challenge is: %s\n", sChallenge);
	md5_hash(sChallenge, sSignature, sizeof(sSignature));
    printf("calculated hash is: %s\n", sSignature);
    return 0;
}