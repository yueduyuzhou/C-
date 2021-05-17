/** Encodes a URL to a shortened URL. */
char* encode(char* longUrl) {
    unsigned char temp = 0x5a;
    char* res = longUrl;
    while (*longUrl != '\0')
    {
        *longUrl ^= temp;
        longUrl++;
    }
    return res;
}

/** Decodes a shortened URL to its original URL. */
char* decode(char* shortUrl) {
    unsigned char temp = 0x5a;
    char* res = shortUrl;
    while (*shortUrl != '\0')
    {
        *shortUrl ^= temp;
        shortUrl++;
    }
    return res;
}


unsigned char key = 0x5a;
char* encode(char* longUrl) {
    char* temp = longUrl;
    while (longUrl != NULL){
        *longUrl ^= key;
        longUrl++;
    }
    return temp;
}

char* decode(char* shortUrl) {
    char* temp = shortUrl;
    while (shortUrl != NULL){
        *shortUrl ^= key;
        shortUrl++;
    }
    return temp;
}
