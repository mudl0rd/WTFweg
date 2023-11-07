#ifndef utils_h_
#define utils_h_

#include <iostream>
#include <fstream>
#include <string>
#include <iostream>
#include <filesystem>
#include <stdio.h>
#include <string>
#include <iostream>
#include <vector>

namespace MudUtil
{
  // misc
  unsigned get_filesize(const char *path);
  void *openlib(const char *path);
  void *getfunc(void *handle, const char *funcname);
  void freelib(void *handle);
  std::string get_wtfwegname();
  const char *get_filename_ext(const char *filename);
  void vector_appendbytes(std::vector<uint8_t> &vec, uint8_t *bytes, size_t len);
  std::vector<uint8_t> load_data(const char *path);
  bool save_data(unsigned char *data, unsigned size, const char *path);
  uint32_t pow2up(uint32_t v);
  std::string base64_decode(const std::string &in);
  std::string base64_encode(const std::string &in);
  std::string replace_all(std::string str, const std::string &from, const std::string &to);
  // crypto
  uint32_t crc32(uint32_t initial, const void *data, size_t length);
  uint32_t adler32(uint32_t adler, const uint8_t *data, size_t len);
  // compression
  std::vector<unsigned char> compress_deflate(unsigned char *buf, size_t size);
  std::vector<unsigned char> decompress_deflate(
      uint8_t *buf,
      size_t size, size_t uncomp_sz);
  std::vector<unsigned char> compress_lzma(unsigned char *buf, size_t size);
  std::vector<unsigned char> decompress_lzma(
      uint8_t *buf,
      size_t size, size_t uncomp_sz);
  /*
  BYTE hash_bytes[16] = {0};
    int namelen = lstrlen(name);
    MD5((BYTE *)name, namelen, (BYTE *)hash_bytes);

  BYTE hash_bytes[20] = {0};
    int namelen = lstrlen(name);
    SHA1((BYTE *)name, namelen, (BYTE *)hash_bytes);
    BYTE hash_bytes[32] = {0};
    int namelen = lstrlen(name);
    SHA256((BYTE *)name, namelen, (BYTE *)hash_bytes);
  */
  void SHA1(uint8_t *hash_data, uint8_t *data, size_t len);
  void MD5(uint8_t *hash_data, uint8_t *data, size_t len);
  void SHA256(uint8_t *hash_data, uint8_t *data, size_t len);
}

#define sizeof_array(arr) sizeof(arr) / sizeof(arr[0])

#endif