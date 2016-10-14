#ifndef __AES_H__
#define __AES_H__

#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>

#define uchar unsigned char // 8-bit byte
#define uint unsigned long // 32-bit word
#define NUM_ROUNDS 10
#define ENCRYPT 1
#define DECRYPT 2
#define VERBOSE_ENCRYPT 5 // 101
#define VERBOSE_DECRYPT 6 // 110
#define BUFFER_SIZE 16

uint d(uchar in[], uchar out[][4], uint Nb);

uint print_matrix(uchar m[][4], uint Nb);

uint add_round_key(uchar pt[][4], uchar key[][4], uint Nb);

uint sub_bytes(uchar pt[][4], uint Nb);

uint inv_sub_bytes(uchar pt[][4], uint Nb);

uint shift_rows(uchar pt[][4], uint Nb);

uchar xtime(uchar a);

uint mix_column(uchar a[], uchar b[], uint Nb);

uint inv_mix_column(uchar a[], uchar b[], uint Nb);

uint mix_columns(uchar in[][4], uint Nb);

uint rotate_word(uint in);

uint word(uchar a, uchar b, uchar c, uchar d);

uint sub_word(uint in);

uint key_exp(uchar key[][4], uint Nk, uint sched[4 * (NUM_ROUNDS + 1)]);

uint break_int(uchar to[4], uint from);

uint to_matrix(uint aa, uint bb, uint cc, uint dd, uchar to[][4], uint Nb);

uint key_exp_enc(uchar key[][4], uint Nk, uint sched[NUM_ROUNDS + 1][4]);

uint key_exp_dec(uchar key[][4], uint Nk, uint schedule[NUM_ROUNDS + 1][4]);

uint aes_128_enc(uchar plaintext[16], uchar key[16], uchar cyphertext[16]);

uint aes_128_enc_verbose(uchar plaintext[16], uchar key[16], uchar cyphertext[16]);

uint aes_128_dec(uchar cyphertext[16], uchar key[16], uchar plaintext[16]);

uint aes_128_dec_verbose(uchar cyphertext[BUFFER_SIZE], uchar key[BUFFER_SIZE], uchar plaintext[BUFFER_SIZE]);

#endif
