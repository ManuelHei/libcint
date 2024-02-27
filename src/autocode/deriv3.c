/*
 * Copyright (C) 2013-  Qiming Sun <osirpt.sun@gmail.com>
 * Description: code generated by  gen-code.cl
 */
#include <stdlib.h>
#include <stdio.h>
#include "cint_bas.h"
#include "cart2sph.h"
#include "g1e.h"
#include "g1e_grids.h"
#include "g2e.h"
#include "optimizer.h"
#include "cint1e.h"
#include "cint2e.h"
#include "misc.h"
#include "c2f.h"
/* <NABLA NABLA NABLA i|NUC |j> */
void CINTgout1e_int1e_ipipipnuc(double *gout, double *g, FINT *idx, CINTEnvVars *envs, FINT gout_empty) {
FINT nf = envs->nf;
FINT nrys_roots = envs->nrys_roots;
FINT ix, iy, iz, n, i;
double *g0 = g;
double *g1 = g0 + envs->g_size * 3;
double *g2 = g1 + envs->g_size * 3;
double *g3 = g2 + envs->g_size * 3;
double *g4 = g3 + envs->g_size * 3;
double *g5 = g4 + envs->g_size * 3;
double *g6 = g5 + envs->g_size * 3;
double *g7 = g6 + envs->g_size * 3;
G2E_D_I(g1, g0, envs->i_l+2, envs->j_l, 0, 0);
G2E_D_I(g2, g0, envs->i_l+1, envs->j_l, 0, 0);
G2E_D_I(g3, g1, envs->i_l+1, envs->j_l, 0, 0);
G2E_D_I(g4, g0, envs->i_l+0, envs->j_l, 0, 0);
G2E_D_I(g5, g1, envs->i_l+0, envs->j_l, 0, 0);
G2E_D_I(g6, g2, envs->i_l+0, envs->j_l, 0, 0);
G2E_D_I(g7, g3, envs->i_l+0, envs->j_l, 0, 0);
double s[27];
for (n = 0; n < nf; n++) {
ix = idx[0+n*3];
iy = idx[1+n*3];
iz = idx[2+n*3];
for (i = 0; i < 27; i++) { s[i] = 0; }
for (i = 0; i < nrys_roots; i++) {
s[0] += g7[ix+i] * g0[iy+i] * g0[iz+i];
s[1] += g6[ix+i] * g1[iy+i] * g0[iz+i];
s[2] += g6[ix+i] * g0[iy+i] * g1[iz+i];
s[3] += g5[ix+i] * g2[iy+i] * g0[iz+i];
s[4] += g4[ix+i] * g3[iy+i] * g0[iz+i];
s[5] += g4[ix+i] * g2[iy+i] * g1[iz+i];
s[6] += g5[ix+i] * g0[iy+i] * g2[iz+i];
s[7] += g4[ix+i] * g1[iy+i] * g2[iz+i];
s[8] += g4[ix+i] * g0[iy+i] * g3[iz+i];
s[9] += g3[ix+i] * g4[iy+i] * g0[iz+i];
s[10] += g2[ix+i] * g5[iy+i] * g0[iz+i];
s[11] += g2[ix+i] * g4[iy+i] * g1[iz+i];
s[12] += g1[ix+i] * g6[iy+i] * g0[iz+i];
s[13] += g0[ix+i] * g7[iy+i] * g0[iz+i];
s[14] += g0[ix+i] * g6[iy+i] * g1[iz+i];
s[15] += g1[ix+i] * g4[iy+i] * g2[iz+i];
s[16] += g0[ix+i] * g5[iy+i] * g2[iz+i];
s[17] += g0[ix+i] * g4[iy+i] * g3[iz+i];
s[18] += g3[ix+i] * g0[iy+i] * g4[iz+i];
s[19] += g2[ix+i] * g1[iy+i] * g4[iz+i];
s[20] += g2[ix+i] * g0[iy+i] * g5[iz+i];
s[21] += g1[ix+i] * g2[iy+i] * g4[iz+i];
s[22] += g0[ix+i] * g3[iy+i] * g4[iz+i];
s[23] += g0[ix+i] * g2[iy+i] * g5[iz+i];
s[24] += g1[ix+i] * g0[iy+i] * g6[iz+i];
s[25] += g0[ix+i] * g1[iy+i] * g6[iz+i];
s[26] += g0[ix+i] * g0[iy+i] * g7[iz+i];
}
if (gout_empty) {
gout[n*27+0] = + s[0];
gout[n*27+1] = + s[9];
gout[n*27+2] = + s[18];
gout[n*27+3] = + s[3];
gout[n*27+4] = + s[12];
gout[n*27+5] = + s[21];
gout[n*27+6] = + s[6];
gout[n*27+7] = + s[15];
gout[n*27+8] = + s[24];
gout[n*27+9] = + s[1];
gout[n*27+10] = + s[10];
gout[n*27+11] = + s[19];
gout[n*27+12] = + s[4];
gout[n*27+13] = + s[13];
gout[n*27+14] = + s[22];
gout[n*27+15] = + s[7];
gout[n*27+16] = + s[16];
gout[n*27+17] = + s[25];
gout[n*27+18] = + s[2];
gout[n*27+19] = + s[11];
gout[n*27+20] = + s[20];
gout[n*27+21] = + s[5];
gout[n*27+22] = + s[14];
gout[n*27+23] = + s[23];
gout[n*27+24] = + s[8];
gout[n*27+25] = + s[17];
gout[n*27+26] = + s[26];
} else {
gout[n*27+0] += + s[0];
gout[n*27+1] += + s[9];
gout[n*27+2] += + s[18];
gout[n*27+3] += + s[3];
gout[n*27+4] += + s[12];
gout[n*27+5] += + s[21];
gout[n*27+6] += + s[6];
gout[n*27+7] += + s[15];
gout[n*27+8] += + s[24];
gout[n*27+9] += + s[1];
gout[n*27+10] += + s[10];
gout[n*27+11] += + s[19];
gout[n*27+12] += + s[4];
gout[n*27+13] += + s[13];
gout[n*27+14] += + s[22];
gout[n*27+15] += + s[7];
gout[n*27+16] += + s[16];
gout[n*27+17] += + s[25];
gout[n*27+18] += + s[2];
gout[n*27+19] += + s[11];
gout[n*27+20] += + s[20];
gout[n*27+21] += + s[5];
gout[n*27+22] += + s[14];
gout[n*27+23] += + s[23];
gout[n*27+24] += + s[8];
gout[n*27+25] += + s[17];
gout[n*27+26] += + s[26];
}}}
void int1e_ipipipnuc_optimizer(CINTOpt **opt, FINT *atm, FINT natm, FINT *bas, FINT nbas, double *env) {
FINT ng[] = {3, 0, 0, 0, 3, 1, 0, 27};
CINTall_1e_optimizer(opt, ng, atm, natm, bas, nbas, env);
}
CACHE_SIZE_T int1e_ipipipnuc_cart(double *out, FINT *dims, FINT *shls,
FINT *atm, FINT natm, FINT *bas, FINT nbas, double *env, CINTOpt *opt, double *cache) {
FINT ng[] = {3, 0, 0, 0, 3, 1, 0, 27};
CINTEnvVars envs;
CINTinit_int1e_EnvVars(&envs, ng, shls, atm, natm, bas, nbas, env);
envs.f_gout = &CINTgout1e_int1e_ipipipnuc;
envs.common_factor *= 1.0;
return CINT1e_drv(out, dims, &envs, cache, &c2s_cart_1e, 2);
} // int1e_ipipipnuc_cart
CACHE_SIZE_T int1e_ipipipnuc_sph(double *out, FINT *dims, FINT *shls,
FINT *atm, FINT natm, FINT *bas, FINT nbas, double *env, CINTOpt *opt, double *cache) {
FINT ng[] = {3, 0, 0, 0, 3, 1, 0, 27};
CINTEnvVars envs;
CINTinit_int1e_EnvVars(&envs, ng, shls, atm, natm, bas, nbas, env);
envs.f_gout = &CINTgout1e_int1e_ipipipnuc;
envs.common_factor *= 1.0;
return CINT1e_drv(out, dims, &envs, cache, &c2s_sph_1e, 2);
} // int1e_ipipipnuc_sph
CACHE_SIZE_T int1e_ipipipnuc_spinor(double complex *out, FINT *dims, FINT *shls,
FINT *atm, FINT natm, FINT *bas, FINT nbas, double *env, CINTOpt *opt, double *cache) {
FINT ng[] = {3, 0, 0, 0, 3, 1, 0, 27};
CINTEnvVars envs;
CINTinit_int1e_EnvVars(&envs, ng, shls, atm, natm, bas, nbas, env);
envs.f_gout = &CINTgout1e_int1e_ipipipnuc;
envs.common_factor *= 1.0;
return CINT1e_spinor_drv(out, dims, &envs, cache, &c2s_sf_1e, 2);
} // int1e_ipipipnuc_spinor
ALL_CINT1E(int1e_ipipipnuc)
ALL_CINT1E_FORTRAN_(int1e_ipipipnuc)
/* <NABLA NABLA NABLA i|RINV |j> */
void CINTgout1e_int1e_ipipiprinv(double *gout, double *g, FINT *idx, CINTEnvVars *envs, FINT gout_empty) {
FINT nf = envs->nf;
FINT nrys_roots = envs->nrys_roots;
FINT ix, iy, iz, n, i;
double *g0 = g;
double *g1 = g0 + envs->g_size * 3;
double *g2 = g1 + envs->g_size * 3;
double *g3 = g2 + envs->g_size * 3;
double *g4 = g3 + envs->g_size * 3;
double *g5 = g4 + envs->g_size * 3;
double *g6 = g5 + envs->g_size * 3;
double *g7 = g6 + envs->g_size * 3;
G2E_D_I(g1, g0, envs->i_l+2, envs->j_l, 0, 0);
G2E_D_I(g2, g0, envs->i_l+1, envs->j_l, 0, 0);
G2E_D_I(g3, g1, envs->i_l+1, envs->j_l, 0, 0);
G2E_D_I(g4, g0, envs->i_l+0, envs->j_l, 0, 0);
G2E_D_I(g5, g1, envs->i_l+0, envs->j_l, 0, 0);
G2E_D_I(g6, g2, envs->i_l+0, envs->j_l, 0, 0);
G2E_D_I(g7, g3, envs->i_l+0, envs->j_l, 0, 0);
double s[27];
for (n = 0; n < nf; n++) {
ix = idx[0+n*3];
iy = idx[1+n*3];
iz = idx[2+n*3];
for (i = 0; i < 27; i++) { s[i] = 0; }
for (i = 0; i < nrys_roots; i++) {
s[0] += g7[ix+i] * g0[iy+i] * g0[iz+i];
s[1] += g6[ix+i] * g1[iy+i] * g0[iz+i];
s[2] += g6[ix+i] * g0[iy+i] * g1[iz+i];
s[3] += g5[ix+i] * g2[iy+i] * g0[iz+i];
s[4] += g4[ix+i] * g3[iy+i] * g0[iz+i];
s[5] += g4[ix+i] * g2[iy+i] * g1[iz+i];
s[6] += g5[ix+i] * g0[iy+i] * g2[iz+i];
s[7] += g4[ix+i] * g1[iy+i] * g2[iz+i];
s[8] += g4[ix+i] * g0[iy+i] * g3[iz+i];
s[9] += g3[ix+i] * g4[iy+i] * g0[iz+i];
s[10] += g2[ix+i] * g5[iy+i] * g0[iz+i];
s[11] += g2[ix+i] * g4[iy+i] * g1[iz+i];
s[12] += g1[ix+i] * g6[iy+i] * g0[iz+i];
s[13] += g0[ix+i] * g7[iy+i] * g0[iz+i];
s[14] += g0[ix+i] * g6[iy+i] * g1[iz+i];
s[15] += g1[ix+i] * g4[iy+i] * g2[iz+i];
s[16] += g0[ix+i] * g5[iy+i] * g2[iz+i];
s[17] += g0[ix+i] * g4[iy+i] * g3[iz+i];
s[18] += g3[ix+i] * g0[iy+i] * g4[iz+i];
s[19] += g2[ix+i] * g1[iy+i] * g4[iz+i];
s[20] += g2[ix+i] * g0[iy+i] * g5[iz+i];
s[21] += g1[ix+i] * g2[iy+i] * g4[iz+i];
s[22] += g0[ix+i] * g3[iy+i] * g4[iz+i];
s[23] += g0[ix+i] * g2[iy+i] * g5[iz+i];
s[24] += g1[ix+i] * g0[iy+i] * g6[iz+i];
s[25] += g0[ix+i] * g1[iy+i] * g6[iz+i];
s[26] += g0[ix+i] * g0[iy+i] * g7[iz+i];
}
if (gout_empty) {
gout[n*27+0] = + s[0];
gout[n*27+1] = + s[9];
gout[n*27+2] = + s[18];
gout[n*27+3] = + s[3];
gout[n*27+4] = + s[12];
gout[n*27+5] = + s[21];
gout[n*27+6] = + s[6];
gout[n*27+7] = + s[15];
gout[n*27+8] = + s[24];
gout[n*27+9] = + s[1];
gout[n*27+10] = + s[10];
gout[n*27+11] = + s[19];
gout[n*27+12] = + s[4];
gout[n*27+13] = + s[13];
gout[n*27+14] = + s[22];
gout[n*27+15] = + s[7];
gout[n*27+16] = + s[16];
gout[n*27+17] = + s[25];
gout[n*27+18] = + s[2];
gout[n*27+19] = + s[11];
gout[n*27+20] = + s[20];
gout[n*27+21] = + s[5];
gout[n*27+22] = + s[14];
gout[n*27+23] = + s[23];
gout[n*27+24] = + s[8];
gout[n*27+25] = + s[17];
gout[n*27+26] = + s[26];
} else {
gout[n*27+0] += + s[0];
gout[n*27+1] += + s[9];
gout[n*27+2] += + s[18];
gout[n*27+3] += + s[3];
gout[n*27+4] += + s[12];
gout[n*27+5] += + s[21];
gout[n*27+6] += + s[6];
gout[n*27+7] += + s[15];
gout[n*27+8] += + s[24];
gout[n*27+9] += + s[1];
gout[n*27+10] += + s[10];
gout[n*27+11] += + s[19];
gout[n*27+12] += + s[4];
gout[n*27+13] += + s[13];
gout[n*27+14] += + s[22];
gout[n*27+15] += + s[7];
gout[n*27+16] += + s[16];
gout[n*27+17] += + s[25];
gout[n*27+18] += + s[2];
gout[n*27+19] += + s[11];
gout[n*27+20] += + s[20];
gout[n*27+21] += + s[5];
gout[n*27+22] += + s[14];
gout[n*27+23] += + s[23];
gout[n*27+24] += + s[8];
gout[n*27+25] += + s[17];
gout[n*27+26] += + s[26];
}}}
void int1e_ipipiprinv_optimizer(CINTOpt **opt, FINT *atm, FINT natm, FINT *bas, FINT nbas, double *env) {
FINT ng[] = {3, 0, 0, 0, 3, 1, 0, 27};
CINTall_1e_optimizer(opt, ng, atm, natm, bas, nbas, env);
}
CACHE_SIZE_T int1e_ipipiprinv_cart(double *out, FINT *dims, FINT *shls,
FINT *atm, FINT natm, FINT *bas, FINT nbas, double *env, CINTOpt *opt, double *cache) {
FINT ng[] = {3, 0, 0, 0, 3, 1, 0, 27};
CINTEnvVars envs;
CINTinit_int1e_EnvVars(&envs, ng, shls, atm, natm, bas, nbas, env);
envs.f_gout = &CINTgout1e_int1e_ipipiprinv;
envs.common_factor *= 1.0;
return CINT1e_drv(out, dims, &envs, cache, &c2s_cart_1e, 1);
} // int1e_ipipiprinv_cart
CACHE_SIZE_T int1e_ipipiprinv_sph(double *out, FINT *dims, FINT *shls,
FINT *atm, FINT natm, FINT *bas, FINT nbas, double *env, CINTOpt *opt, double *cache) {
FINT ng[] = {3, 0, 0, 0, 3, 1, 0, 27};
CINTEnvVars envs;
CINTinit_int1e_EnvVars(&envs, ng, shls, atm, natm, bas, nbas, env);
envs.f_gout = &CINTgout1e_int1e_ipipiprinv;
envs.common_factor *= 1.0;
return CINT1e_drv(out, dims, &envs, cache, &c2s_sph_1e, 1);
} // int1e_ipipiprinv_sph
CACHE_SIZE_T int1e_ipipiprinv_spinor(double complex *out, FINT *dims, FINT *shls,
FINT *atm, FINT natm, FINT *bas, FINT nbas, double *env, CINTOpt *opt, double *cache) {
FINT ng[] = {3, 0, 0, 0, 3, 1, 0, 27};
CINTEnvVars envs;
CINTinit_int1e_EnvVars(&envs, ng, shls, atm, natm, bas, nbas, env);
envs.f_gout = &CINTgout1e_int1e_ipipiprinv;
envs.common_factor *= 1.0;
return CINT1e_spinor_drv(out, dims, &envs, cache, &c2s_sf_1e, 1);
} // int1e_ipipiprinv_spinor
ALL_CINT1E(int1e_ipipiprinv)
ALL_CINT1E_FORTRAN_(int1e_ipipiprinv)
/* <NABLA NABLA i|NUC |NABLA j> */
void CINTgout1e_int1e_ipipnucip(double *gout, double *g, FINT *idx, CINTEnvVars *envs, FINT gout_empty) {
FINT nf = envs->nf;
FINT nrys_roots = envs->nrys_roots;
FINT ix, iy, iz, n, i;
double *g0 = g;
double *g1 = g0 + envs->g_size * 3;
double *g2 = g1 + envs->g_size * 3;
double *g3 = g2 + envs->g_size * 3;
double *g4 = g3 + envs->g_size * 3;
double *g5 = g4 + envs->g_size * 3;
double *g6 = g5 + envs->g_size * 3;
double *g7 = g6 + envs->g_size * 3;
G2E_D_J(g1, g0, envs->i_l+2, envs->j_l+0, 0, 0);
G2E_D_I(g2, g0, envs->i_l+1, envs->j_l, 0, 0);
G2E_D_I(g3, g1, envs->i_l+1, envs->j_l, 0, 0);
G2E_D_I(g4, g0, envs->i_l+0, envs->j_l, 0, 0);
G2E_D_I(g5, g1, envs->i_l+0, envs->j_l, 0, 0);
G2E_D_I(g6, g2, envs->i_l+0, envs->j_l, 0, 0);
G2E_D_I(g7, g3, envs->i_l+0, envs->j_l, 0, 0);
double s[27];
for (n = 0; n < nf; n++) {
ix = idx[0+n*3];
iy = idx[1+n*3];
iz = idx[2+n*3];
for (i = 0; i < 27; i++) { s[i] = 0; }
for (i = 0; i < nrys_roots; i++) {
s[0] += g7[ix+i] * g0[iy+i] * g0[iz+i];
s[1] += g6[ix+i] * g1[iy+i] * g0[iz+i];
s[2] += g6[ix+i] * g0[iy+i] * g1[iz+i];
s[3] += g5[ix+i] * g2[iy+i] * g0[iz+i];
s[4] += g4[ix+i] * g3[iy+i] * g0[iz+i];
s[5] += g4[ix+i] * g2[iy+i] * g1[iz+i];
s[6] += g5[ix+i] * g0[iy+i] * g2[iz+i];
s[7] += g4[ix+i] * g1[iy+i] * g2[iz+i];
s[8] += g4[ix+i] * g0[iy+i] * g3[iz+i];
s[9] += g3[ix+i] * g4[iy+i] * g0[iz+i];
s[10] += g2[ix+i] * g5[iy+i] * g0[iz+i];
s[11] += g2[ix+i] * g4[iy+i] * g1[iz+i];
s[12] += g1[ix+i] * g6[iy+i] * g0[iz+i];
s[13] += g0[ix+i] * g7[iy+i] * g0[iz+i];
s[14] += g0[ix+i] * g6[iy+i] * g1[iz+i];
s[15] += g1[ix+i] * g4[iy+i] * g2[iz+i];
s[16] += g0[ix+i] * g5[iy+i] * g2[iz+i];
s[17] += g0[ix+i] * g4[iy+i] * g3[iz+i];
s[18] += g3[ix+i] * g0[iy+i] * g4[iz+i];
s[19] += g2[ix+i] * g1[iy+i] * g4[iz+i];
s[20] += g2[ix+i] * g0[iy+i] * g5[iz+i];
s[21] += g1[ix+i] * g2[iy+i] * g4[iz+i];
s[22] += g0[ix+i] * g3[iy+i] * g4[iz+i];
s[23] += g0[ix+i] * g2[iy+i] * g5[iz+i];
s[24] += g1[ix+i] * g0[iy+i] * g6[iz+i];
s[25] += g0[ix+i] * g1[iy+i] * g6[iz+i];
s[26] += g0[ix+i] * g0[iy+i] * g7[iz+i];
}
if (gout_empty) {
gout[n*27+0] = + s[0];
gout[n*27+1] = + s[1];
gout[n*27+2] = + s[2];
gout[n*27+3] = + s[9];
gout[n*27+4] = + s[10];
gout[n*27+5] = + s[11];
gout[n*27+6] = + s[18];
gout[n*27+7] = + s[19];
gout[n*27+8] = + s[20];
gout[n*27+9] = + s[3];
gout[n*27+10] = + s[4];
gout[n*27+11] = + s[5];
gout[n*27+12] = + s[12];
gout[n*27+13] = + s[13];
gout[n*27+14] = + s[14];
gout[n*27+15] = + s[21];
gout[n*27+16] = + s[22];
gout[n*27+17] = + s[23];
gout[n*27+18] = + s[6];
gout[n*27+19] = + s[7];
gout[n*27+20] = + s[8];
gout[n*27+21] = + s[15];
gout[n*27+22] = + s[16];
gout[n*27+23] = + s[17];
gout[n*27+24] = + s[24];
gout[n*27+25] = + s[25];
gout[n*27+26] = + s[26];
} else {
gout[n*27+0] += + s[0];
gout[n*27+1] += + s[1];
gout[n*27+2] += + s[2];
gout[n*27+3] += + s[9];
gout[n*27+4] += + s[10];
gout[n*27+5] += + s[11];
gout[n*27+6] += + s[18];
gout[n*27+7] += + s[19];
gout[n*27+8] += + s[20];
gout[n*27+9] += + s[3];
gout[n*27+10] += + s[4];
gout[n*27+11] += + s[5];
gout[n*27+12] += + s[12];
gout[n*27+13] += + s[13];
gout[n*27+14] += + s[14];
gout[n*27+15] += + s[21];
gout[n*27+16] += + s[22];
gout[n*27+17] += + s[23];
gout[n*27+18] += + s[6];
gout[n*27+19] += + s[7];
gout[n*27+20] += + s[8];
gout[n*27+21] += + s[15];
gout[n*27+22] += + s[16];
gout[n*27+23] += + s[17];
gout[n*27+24] += + s[24];
gout[n*27+25] += + s[25];
gout[n*27+26] += + s[26];
}}}
void int1e_ipipnucip_optimizer(CINTOpt **opt, FINT *atm, FINT natm, FINT *bas, FINT nbas, double *env) {
FINT ng[] = {2, 1, 0, 0, 3, 1, 0, 27};
CINTall_1e_optimizer(opt, ng, atm, natm, bas, nbas, env);
}
CACHE_SIZE_T int1e_ipipnucip_cart(double *out, FINT *dims, FINT *shls,
FINT *atm, FINT natm, FINT *bas, FINT nbas, double *env, CINTOpt *opt, double *cache) {
FINT ng[] = {2, 1, 0, 0, 3, 1, 0, 27};
CINTEnvVars envs;
CINTinit_int1e_EnvVars(&envs, ng, shls, atm, natm, bas, nbas, env);
envs.f_gout = &CINTgout1e_int1e_ipipnucip;
envs.common_factor *= 1.0;
return CINT1e_drv(out, dims, &envs, cache, &c2s_cart_1e, 2);
} // int1e_ipipnucip_cart
CACHE_SIZE_T int1e_ipipnucip_sph(double *out, FINT *dims, FINT *shls,
FINT *atm, FINT natm, FINT *bas, FINT nbas, double *env, CINTOpt *opt, double *cache) {
FINT ng[] = {2, 1, 0, 0, 3, 1, 0, 27};
CINTEnvVars envs;
CINTinit_int1e_EnvVars(&envs, ng, shls, atm, natm, bas, nbas, env);
envs.f_gout = &CINTgout1e_int1e_ipipnucip;
envs.common_factor *= 1.0;
return CINT1e_drv(out, dims, &envs, cache, &c2s_sph_1e, 2);
} // int1e_ipipnucip_sph
CACHE_SIZE_T int1e_ipipnucip_spinor(double complex *out, FINT *dims, FINT *shls,
FINT *atm, FINT natm, FINT *bas, FINT nbas, double *env, CINTOpt *opt, double *cache) {
FINT ng[] = {2, 1, 0, 0, 3, 1, 0, 27};
CINTEnvVars envs;
CINTinit_int1e_EnvVars(&envs, ng, shls, atm, natm, bas, nbas, env);
envs.f_gout = &CINTgout1e_int1e_ipipnucip;
envs.common_factor *= 1.0;
return CINT1e_spinor_drv(out, dims, &envs, cache, &c2s_sf_1e, 2);
} // int1e_ipipnucip_spinor
ALL_CINT1E(int1e_ipipnucip)
ALL_CINT1E_FORTRAN_(int1e_ipipnucip)
/* <NABLA NABLA i|RINV |NABLA j> */
void CINTgout1e_int1e_ipiprinvip(double *gout, double *g, FINT *idx, CINTEnvVars *envs, FINT gout_empty) {
FINT nf = envs->nf;
FINT nrys_roots = envs->nrys_roots;
FINT ix, iy, iz, n, i;
double *g0 = g;
double *g1 = g0 + envs->g_size * 3;
double *g2 = g1 + envs->g_size * 3;
double *g3 = g2 + envs->g_size * 3;
double *g4 = g3 + envs->g_size * 3;
double *g5 = g4 + envs->g_size * 3;
double *g6 = g5 + envs->g_size * 3;
double *g7 = g6 + envs->g_size * 3;
G2E_D_J(g1, g0, envs->i_l+2, envs->j_l+0, 0, 0);
G2E_D_I(g2, g0, envs->i_l+1, envs->j_l, 0, 0);
G2E_D_I(g3, g1, envs->i_l+1, envs->j_l, 0, 0);
G2E_D_I(g4, g0, envs->i_l+0, envs->j_l, 0, 0);
G2E_D_I(g5, g1, envs->i_l+0, envs->j_l, 0, 0);
G2E_D_I(g6, g2, envs->i_l+0, envs->j_l, 0, 0);
G2E_D_I(g7, g3, envs->i_l+0, envs->j_l, 0, 0);
double s[27];
for (n = 0; n < nf; n++) {
ix = idx[0+n*3];
iy = idx[1+n*3];
iz = idx[2+n*3];
for (i = 0; i < 27; i++) { s[i] = 0; }
for (i = 0; i < nrys_roots; i++) {
s[0] += g7[ix+i] * g0[iy+i] * g0[iz+i];
s[1] += g6[ix+i] * g1[iy+i] * g0[iz+i];
s[2] += g6[ix+i] * g0[iy+i] * g1[iz+i];
s[3] += g5[ix+i] * g2[iy+i] * g0[iz+i];
s[4] += g4[ix+i] * g3[iy+i] * g0[iz+i];
s[5] += g4[ix+i] * g2[iy+i] * g1[iz+i];
s[6] += g5[ix+i] * g0[iy+i] * g2[iz+i];
s[7] += g4[ix+i] * g1[iy+i] * g2[iz+i];
s[8] += g4[ix+i] * g0[iy+i] * g3[iz+i];
s[9] += g3[ix+i] * g4[iy+i] * g0[iz+i];
s[10] += g2[ix+i] * g5[iy+i] * g0[iz+i];
s[11] += g2[ix+i] * g4[iy+i] * g1[iz+i];
s[12] += g1[ix+i] * g6[iy+i] * g0[iz+i];
s[13] += g0[ix+i] * g7[iy+i] * g0[iz+i];
s[14] += g0[ix+i] * g6[iy+i] * g1[iz+i];
s[15] += g1[ix+i] * g4[iy+i] * g2[iz+i];
s[16] += g0[ix+i] * g5[iy+i] * g2[iz+i];
s[17] += g0[ix+i] * g4[iy+i] * g3[iz+i];
s[18] += g3[ix+i] * g0[iy+i] * g4[iz+i];
s[19] += g2[ix+i] * g1[iy+i] * g4[iz+i];
s[20] += g2[ix+i] * g0[iy+i] * g5[iz+i];
s[21] += g1[ix+i] * g2[iy+i] * g4[iz+i];
s[22] += g0[ix+i] * g3[iy+i] * g4[iz+i];
s[23] += g0[ix+i] * g2[iy+i] * g5[iz+i];
s[24] += g1[ix+i] * g0[iy+i] * g6[iz+i];
s[25] += g0[ix+i] * g1[iy+i] * g6[iz+i];
s[26] += g0[ix+i] * g0[iy+i] * g7[iz+i];
}
if (gout_empty) {
gout[n*27+0] = + s[0];
gout[n*27+1] = + s[1];
gout[n*27+2] = + s[2];
gout[n*27+3] = + s[9];
gout[n*27+4] = + s[10];
gout[n*27+5] = + s[11];
gout[n*27+6] = + s[18];
gout[n*27+7] = + s[19];
gout[n*27+8] = + s[20];
gout[n*27+9] = + s[3];
gout[n*27+10] = + s[4];
gout[n*27+11] = + s[5];
gout[n*27+12] = + s[12];
gout[n*27+13] = + s[13];
gout[n*27+14] = + s[14];
gout[n*27+15] = + s[21];
gout[n*27+16] = + s[22];
gout[n*27+17] = + s[23];
gout[n*27+18] = + s[6];
gout[n*27+19] = + s[7];
gout[n*27+20] = + s[8];
gout[n*27+21] = + s[15];
gout[n*27+22] = + s[16];
gout[n*27+23] = + s[17];
gout[n*27+24] = + s[24];
gout[n*27+25] = + s[25];
gout[n*27+26] = + s[26];
} else {
gout[n*27+0] += + s[0];
gout[n*27+1] += + s[1];
gout[n*27+2] += + s[2];
gout[n*27+3] += + s[9];
gout[n*27+4] += + s[10];
gout[n*27+5] += + s[11];
gout[n*27+6] += + s[18];
gout[n*27+7] += + s[19];
gout[n*27+8] += + s[20];
gout[n*27+9] += + s[3];
gout[n*27+10] += + s[4];
gout[n*27+11] += + s[5];
gout[n*27+12] += + s[12];
gout[n*27+13] += + s[13];
gout[n*27+14] += + s[14];
gout[n*27+15] += + s[21];
gout[n*27+16] += + s[22];
gout[n*27+17] += + s[23];
gout[n*27+18] += + s[6];
gout[n*27+19] += + s[7];
gout[n*27+20] += + s[8];
gout[n*27+21] += + s[15];
gout[n*27+22] += + s[16];
gout[n*27+23] += + s[17];
gout[n*27+24] += + s[24];
gout[n*27+25] += + s[25];
gout[n*27+26] += + s[26];
}}}
void int1e_ipiprinvip_optimizer(CINTOpt **opt, FINT *atm, FINT natm, FINT *bas, FINT nbas, double *env) {
FINT ng[] = {2, 1, 0, 0, 3, 1, 0, 27};
CINTall_1e_optimizer(opt, ng, atm, natm, bas, nbas, env);
}
CACHE_SIZE_T int1e_ipiprinvip_cart(double *out, FINT *dims, FINT *shls,
FINT *atm, FINT natm, FINT *bas, FINT nbas, double *env, CINTOpt *opt, double *cache) {
FINT ng[] = {2, 1, 0, 0, 3, 1, 0, 27};
CINTEnvVars envs;
CINTinit_int1e_EnvVars(&envs, ng, shls, atm, natm, bas, nbas, env);
envs.f_gout = &CINTgout1e_int1e_ipiprinvip;
envs.common_factor *= 1.0;
return CINT1e_drv(out, dims, &envs, cache, &c2s_cart_1e, 1);
} // int1e_ipiprinvip_cart
CACHE_SIZE_T int1e_ipiprinvip_sph(double *out, FINT *dims, FINT *shls,
FINT *atm, FINT natm, FINT *bas, FINT nbas, double *env, CINTOpt *opt, double *cache) {
FINT ng[] = {2, 1, 0, 0, 3, 1, 0, 27};
CINTEnvVars envs;
CINTinit_int1e_EnvVars(&envs, ng, shls, atm, natm, bas, nbas, env);
envs.f_gout = &CINTgout1e_int1e_ipiprinvip;
envs.common_factor *= 1.0;
return CINT1e_drv(out, dims, &envs, cache, &c2s_sph_1e, 1);
} // int1e_ipiprinvip_sph
CACHE_SIZE_T int1e_ipiprinvip_spinor(double complex *out, FINT *dims, FINT *shls,
FINT *atm, FINT natm, FINT *bas, FINT nbas, double *env, CINTOpt *opt, double *cache) {
FINT ng[] = {2, 1, 0, 0, 3, 1, 0, 27};
CINTEnvVars envs;
CINTinit_int1e_EnvVars(&envs, ng, shls, atm, natm, bas, nbas, env);
envs.f_gout = &CINTgout1e_int1e_ipiprinvip;
envs.common_factor *= 1.0;
return CINT1e_spinor_drv(out, dims, &envs, cache, &c2s_sf_1e, 1);
} // int1e_ipiprinvip_spinor
ALL_CINT1E(int1e_ipiprinvip)
ALL_CINT1E_FORTRAN_(int1e_ipiprinvip)
