#ifndef KMERUTIL_H
#define KMERUTIL_H
#include <stdint.h>// uint64_t 
#ifdef largeintlib

#include "LargeInt.hpp"

typedef LargeInt<kmer_precision> kmercode_length;

#else

#if (! defined kmercode_length) || (! defined _LP64)

typedef uint64_t kmercode_length;

#endif
#endif
#include <stddef.h> //NULL
#include <iostream>
#include <stdlib.h>//exit
#include <vector>
#include <unordered_map>

extern int kmer_size;
extern int gap_size;
extern kmercode_length kmer_mask;

class kmersUtil
{
 public:
  std::unordered_map<kmercode_length,unsigned int> counting_hash_table;
  /*kmersUtil();
 ~kmersUtil();*/
  void add2table(kmercode_length kmer,unsigned int count);
  unsigned int get_from_table (kmercode_length kmer);
  int nt2int(char nt);
  kmercode_length get_canonical_kmer_code(kmercode_length code);
  kmercode_length get_reverse_complement(kmercode_length code);
  int first_nt(kmercode_length kmer);
  int code2seq (kmercode_length code, char seq[]);
  kmercode_length next_kmer(kmercode_length kmer_code, int added_nt, int *strand);
  int rev_nt2int(int nt);
  int code2nt(kmercode_length code, int which_nt);
  void char_revcomp(char nt,char &cnt);
  void revcomp_sequence(std::vector<char> &sequence, int len);
  void get_kmers_one_read(std::string read, std::vector<kmercode_length> &kmers_list); 
  void get_reads_spiliting_around_Ns(std::string read_seq,int read_length,std::vector<std::string> & reads);
  float needleman_wunch(std::string a, std::string b);
};

#endif
