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
/* <k X0 i|NABLA-R12 |j l> : i,j \in electron 1; k,l \in electron 2
 * = (X0 i j|NABLA-R12 |k l) */
void CINTgout2e_int2e_x0_nablar12(double *gout,
double *g, FINT *idx, CINTEnvVars *envs, FINT gout_empty) {
FINT nf = envs->nf;
FINT nrys_roots = envs->nrys_roots;
FINT ix, iy, iz, i, n;
double *g0 = g;
double *g1 = g0 + envs->g_size * 3;
double *g2 = g1 + envs->g_size * 3;
double *g3 = g2 + envs->g_size * 3;
G2E_D_J(g1, g0, envs->i_l+1, envs->j_l+0, envs->k_l, envs->l_l);
G2E_D_I(g2, g0, envs->i_l+1, envs->j_l+0, envs->k_l, envs->l_l);
for (ix = 0; ix < envs->g_size * 3; ix++) {g1[ix] += g2[ix];}
G2E_R0I(g2, g0, envs->i_l+0, envs->j_l, envs->k_l, envs->l_l);
G2E_R0I(g3, g1, envs->i_l+0, envs->j_l, envs->k_l, envs->l_l);
double s[9];
for (n = 0; n < nf; n++) {
ix = idx[0+n*3];
iy = idx[1+n*3];
iz = idx[2+n*3];
for (i = 0; i < 9; i++) { s[i] = 0; }
for (i = 0; i < nrys_roots; i++) {
s[0] += g3[ix+i] * g0[iy+i] * g0[iz+i];
s[1] += g2[ix+i] * g1[iy+i] * g0[iz+i];
s[2] += g2[ix+i] * g0[iy+i] * g1[iz+i];
s[3] += g1[ix+i] * g2[iy+i] * g0[iz+i];
s[4] += g0[ix+i] * g3[iy+i] * g0[iz+i];
s[5] += g0[ix+i] * g2[iy+i] * g1[iz+i];
s[6] += g1[ix+i] * g0[iy+i] * g2[iz+i];
s[7] += g0[ix+i] * g1[iy+i] * g2[iz+i];
s[8] += g0[ix+i] * g0[iy+i] * g3[iz+i];
}
if (gout_empty) {
gout[n*3+0] = + s[0];
gout[n*3+1] = + s[1];
gout[n*3+2] = + s[2];
} else {
gout[n*3+0] += + s[0];
gout[n*3+1] += + s[1];
gout[n*3+2] += + s[2];
}}}
void int2e_x0_nablar12_optimizer(CINTOpt **opt, FINT *atm, FINT natm, FINT *bas, FINT nbas, double *env) {
FINT ng[] = {2, 1, 0, 0, 2, 1, 1, 3};
CINTall_2e_optimizer(opt, ng, atm, natm, bas, nbas, env);
}
CACHE_SIZE_T int2e_x0_nablar12_cart(double *out, FINT *dims, FINT *shls,
FINT *atm, FINT natm, FINT *bas, FINT nbas, double *env, CINTOpt *opt, double *cache) {
FINT ng[] = {2, 1, 0, 0, 2, 1, 1, 3};
CINTEnvVars envs;
CINTinit_int2e_EnvVars(&envs, ng, shls, atm, natm, bas, nbas, env);
envs.f_gout = &CINTgout2e_int2e_x0_nablar12;
envs.common_factor *= 1.0;
return CINT2e_drv(out, dims, &envs, opt, cache, &c2s_cart_2e1);
} // int2e_x0_nablar12_cart
CACHE_SIZE_T int2e_x0_nablar12_sph(double *out, FINT *dims, FINT *shls,
FINT *atm, FINT natm, FINT *bas, FINT nbas, double *env, CINTOpt *opt, double *cache) {
FINT ng[] = {2, 1, 0, 0, 2, 1, 1, 3};
CINTEnvVars envs;
CINTinit_int2e_EnvVars(&envs, ng, shls, atm, natm, bas, nbas, env);
envs.f_gout = &CINTgout2e_int2e_x0_nablar12;
envs.common_factor *= 1.0;
return CINT2e_drv(out, dims, &envs, opt, cache, &c2s_sph_2e1);
} // int2e_x0_nablar12_sph
CACHE_SIZE_T int2e_x0_nablar12_spinor(double complex *out, FINT *dims, FINT *shls,
FINT *atm, FINT natm, FINT *bas, FINT nbas, double *env, CINTOpt *opt, double *cache) {
FINT ng[] = {2, 1, 0, 0, 2, 1, 1, 3};
CINTEnvVars envs;
CINTinit_int2e_EnvVars(&envs, ng, shls, atm, natm, bas, nbas, env);
envs.f_gout = &CINTgout2e_int2e_x0_nablar12;
envs.common_factor *= 1.0;
return CINT2e_spinor_drv(out, dims, &envs, opt, cache, &c2s_sf_2e1, &c2s_sf_2e2);
} // int2e_x0_nablar12_spinor
ALL_CINT(int2e_x0_nablar12)
ALL_CINT_FORTRAN_(int2e_x0_nablar12)
/* <k Y0 i|NABLA-R12 |j l> : i,j \in electron 1; k,l \in electron 2
 * = (Y0 i j|NABLA-R12 |k l) */
void CINTgout2e_int2e_y0_nablar12(double *gout,
double *g, FINT *idx, CINTEnvVars *envs, FINT gout_empty) {
FINT nf = envs->nf;
FINT nrys_roots = envs->nrys_roots;
FINT ix, iy, iz, i, n;
double *g0 = g;
double *g1 = g0 + envs->g_size * 3;
double *g2 = g1 + envs->g_size * 3;
double *g3 = g2 + envs->g_size * 3;
G2E_D_J(g1, g0, envs->i_l+1, envs->j_l+0, envs->k_l, envs->l_l);
G2E_D_I(g2, g0, envs->i_l+1, envs->j_l+0, envs->k_l, envs->l_l);
for (ix = 0; ix < envs->g_size * 3; ix++) {g1[ix] += g2[ix];}
G2E_R0I(g2, g0, envs->i_l+0, envs->j_l, envs->k_l, envs->l_l);
G2E_R0I(g3, g1, envs->i_l+0, envs->j_l, envs->k_l, envs->l_l);
double s[9];
for (n = 0; n < nf; n++) {
ix = idx[0+n*3];
iy = idx[1+n*3];
iz = idx[2+n*3];
for (i = 0; i < 9; i++) { s[i] = 0; }
for (i = 0; i < nrys_roots; i++) {
s[0] += g3[ix+i] * g0[iy+i] * g0[iz+i];
s[1] += g2[ix+i] * g1[iy+i] * g0[iz+i];
s[2] += g2[ix+i] * g0[iy+i] * g1[iz+i];
s[3] += g1[ix+i] * g2[iy+i] * g0[iz+i];
s[4] += g0[ix+i] * g3[iy+i] * g0[iz+i];
s[5] += g0[ix+i] * g2[iy+i] * g1[iz+i];
s[6] += g1[ix+i] * g0[iy+i] * g2[iz+i];
s[7] += g0[ix+i] * g1[iy+i] * g2[iz+i];
s[8] += g0[ix+i] * g0[iy+i] * g3[iz+i];
}
if (gout_empty) {
gout[n*3+0] = + s[3];
gout[n*3+1] = + s[4];
gout[n*3+2] = + s[5];
} else {
gout[n*3+0] += + s[3];
gout[n*3+1] += + s[4];
gout[n*3+2] += + s[5];
}}}
void int2e_y0_nablar12_optimizer(CINTOpt **opt, FINT *atm, FINT natm, FINT *bas, FINT nbas, double *env) {
FINT ng[] = {2, 1, 0, 0, 2, 1, 1, 3};
CINTall_2e_optimizer(opt, ng, atm, natm, bas, nbas, env);
}
CACHE_SIZE_T int2e_y0_nablar12_cart(double *out, FINT *dims, FINT *shls,
FINT *atm, FINT natm, FINT *bas, FINT nbas, double *env, CINTOpt *opt, double *cache) {
FINT ng[] = {2, 1, 0, 0, 2, 1, 1, 3};
CINTEnvVars envs;
CINTinit_int2e_EnvVars(&envs, ng, shls, atm, natm, bas, nbas, env);
envs.f_gout = &CINTgout2e_int2e_y0_nablar12;
envs.common_factor *= 1.0;
return CINT2e_drv(out, dims, &envs, opt, cache, &c2s_cart_2e1);
} // int2e_y0_nablar12_cart
CACHE_SIZE_T int2e_y0_nablar12_sph(double *out, FINT *dims, FINT *shls,
FINT *atm, FINT natm, FINT *bas, FINT nbas, double *env, CINTOpt *opt, double *cache) {
FINT ng[] = {2, 1, 0, 0, 2, 1, 1, 3};
CINTEnvVars envs;
CINTinit_int2e_EnvVars(&envs, ng, shls, atm, natm, bas, nbas, env);
envs.f_gout = &CINTgout2e_int2e_y0_nablar12;
envs.common_factor *= 1.0;
return CINT2e_drv(out, dims, &envs, opt, cache, &c2s_sph_2e1);
} // int2e_y0_nablar12_sph
CACHE_SIZE_T int2e_y0_nablar12_spinor(double complex *out, FINT *dims, FINT *shls,
FINT *atm, FINT natm, FINT *bas, FINT nbas, double *env, CINTOpt *opt, double *cache) {
FINT ng[] = {2, 1, 0, 0, 2, 1, 1, 3};
CINTEnvVars envs;
CINTinit_int2e_EnvVars(&envs, ng, shls, atm, natm, bas, nbas, env);
envs.f_gout = &CINTgout2e_int2e_y0_nablar12;
envs.common_factor *= 1.0;
return CINT2e_spinor_drv(out, dims, &envs, opt, cache, &c2s_sf_2e1, &c2s_sf_2e2);
} // int2e_y0_nablar12_spinor
ALL_CINT(int2e_y0_nablar12)
ALL_CINT_FORTRAN_(int2e_y0_nablar12)
/* <k Z0 i|NABLA-R12 |j l> : i,j \in electron 1; k,l \in electron 2
 * = (Z0 i j|NABLA-R12 |k l) */
void CINTgout2e_int2e_z0_nablar12(double *gout,
double *g, FINT *idx, CINTEnvVars *envs, FINT gout_empty) {
FINT nf = envs->nf;
FINT nrys_roots = envs->nrys_roots;
FINT ix, iy, iz, i, n;
double *g0 = g;
double *g1 = g0 + envs->g_size * 3;
double *g2 = g1 + envs->g_size * 3;
double *g3 = g2 + envs->g_size * 3;
G2E_D_J(g1, g0, envs->i_l+1, envs->j_l+0, envs->k_l, envs->l_l);
G2E_D_I(g2, g0, envs->i_l+1, envs->j_l+0, envs->k_l, envs->l_l);
for (ix = 0; ix < envs->g_size * 3; ix++) {g1[ix] += g2[ix];}
G2E_R0I(g2, g0, envs->i_l+0, envs->j_l, envs->k_l, envs->l_l);
G2E_R0I(g3, g1, envs->i_l+0, envs->j_l, envs->k_l, envs->l_l);
double s[9];
for (n = 0; n < nf; n++) {
ix = idx[0+n*3];
iy = idx[1+n*3];
iz = idx[2+n*3];
for (i = 0; i < 9; i++) { s[i] = 0; }
for (i = 0; i < nrys_roots; i++) {
s[0] += g3[ix+i] * g0[iy+i] * g0[iz+i];
s[1] += g2[ix+i] * g1[iy+i] * g0[iz+i];
s[2] += g2[ix+i] * g0[iy+i] * g1[iz+i];
s[3] += g1[ix+i] * g2[iy+i] * g0[iz+i];
s[4] += g0[ix+i] * g3[iy+i] * g0[iz+i];
s[5] += g0[ix+i] * g2[iy+i] * g1[iz+i];
s[6] += g1[ix+i] * g0[iy+i] * g2[iz+i];
s[7] += g0[ix+i] * g1[iy+i] * g2[iz+i];
s[8] += g0[ix+i] * g0[iy+i] * g3[iz+i];
}
if (gout_empty) {
gout[n*3+0] = + s[6];
gout[n*3+1] = + s[7];
gout[n*3+2] = + s[8];
} else {
gout[n*3+0] += + s[6];
gout[n*3+1] += + s[7];
gout[n*3+2] += + s[8];
}}}
void int2e_z0_nablar12_optimizer(CINTOpt **opt, FINT *atm, FINT natm, FINT *bas, FINT nbas, double *env) {
FINT ng[] = {2, 1, 0, 0, 2, 1, 1, 3};
CINTall_2e_optimizer(opt, ng, atm, natm, bas, nbas, env);
}
CACHE_SIZE_T int2e_z0_nablar12_cart(double *out, FINT *dims, FINT *shls,
FINT *atm, FINT natm, FINT *bas, FINT nbas, double *env, CINTOpt *opt, double *cache) {
FINT ng[] = {2, 1, 0, 0, 2, 1, 1, 3};
CINTEnvVars envs;
CINTinit_int2e_EnvVars(&envs, ng, shls, atm, natm, bas, nbas, env);
envs.f_gout = &CINTgout2e_int2e_z0_nablar12;
envs.common_factor *= 1.0;
return CINT2e_drv(out, dims, &envs, opt, cache, &c2s_cart_2e1);
} // int2e_z0_nablar12_cart
CACHE_SIZE_T int2e_z0_nablar12_sph(double *out, FINT *dims, FINT *shls,
FINT *atm, FINT natm, FINT *bas, FINT nbas, double *env, CINTOpt *opt, double *cache) {
FINT ng[] = {2, 1, 0, 0, 2, 1, 1, 3};
CINTEnvVars envs;
CINTinit_int2e_EnvVars(&envs, ng, shls, atm, natm, bas, nbas, env);
envs.f_gout = &CINTgout2e_int2e_z0_nablar12;
envs.common_factor *= 1.0;
return CINT2e_drv(out, dims, &envs, opt, cache, &c2s_sph_2e1);
} // int2e_z0_nablar12_sph
CACHE_SIZE_T int2e_z0_nablar12_spinor(double complex *out, FINT *dims, FINT *shls,
FINT *atm, FINT natm, FINT *bas, FINT nbas, double *env, CINTOpt *opt, double *cache) {
FINT ng[] = {2, 1, 0, 0, 2, 1, 1, 3};
CINTEnvVars envs;
CINTinit_int2e_EnvVars(&envs, ng, shls, atm, natm, bas, nbas, env);
envs.f_gout = &CINTgout2e_int2e_z0_nablar12;
envs.common_factor *= 1.0;
return CINT2e_spinor_drv(out, dims, &envs, opt, cache, &c2s_sf_2e1, &c2s_sf_2e2);
} // int2e_z0_nablar12_spinor
ALL_CINT(int2e_z0_nablar12)
ALL_CINT_FORTRAN_(int2e_z0_nablar12)
/* <k R0 DOT NABLA i|R12 |j l> : i,j \in electron 1; k,l \in electron 2
 * = (R0 DOT NABLA i j|R12 |k l) */
void CINTgout2e_int2e_r0_nablar12(double *gout,
double *g, FINT *idx, CINTEnvVars *envs, FINT gout_empty) {
FINT nf = envs->nf;
FINT nrys_roots = envs->nrys_roots;
FINT ix, iy, iz, i, n;
double *g0 = g;
double *g1 = g0 + envs->g_size * 3;
double *g2 = g1 + envs->g_size * 3;
double *g3 = g2 + envs->g_size * 3;
G2E_R0I(g1, g0, envs->i_l+1, envs->j_l, envs->k_l, envs->l_l);
G2E_D_I(g2, g0, envs->i_l+0, envs->j_l, envs->k_l, envs->l_l);
G2E_D_I(g3, g1, envs->i_l+0, envs->j_l, envs->k_l, envs->l_l);
double s[9];
for (n = 0; n < nf; n++) {
ix = idx[0+n*3];
iy = idx[1+n*3];
iz = idx[2+n*3];
for (i = 0; i < 9; i++) { s[i] = 0; }
for (i = 0; i < nrys_roots; i++) {
s[0] += g3[ix+i] * g0[iy+i] * g0[iz+i];
s[1] += g2[ix+i] * g1[iy+i] * g0[iz+i];
s[2] += g2[ix+i] * g0[iy+i] * g1[iz+i];
s[3] += g1[ix+i] * g2[iy+i] * g0[iz+i];
s[4] += g0[ix+i] * g3[iy+i] * g0[iz+i];
s[5] += g0[ix+i] * g2[iy+i] * g1[iz+i];
s[6] += g1[ix+i] * g0[iy+i] * g2[iz+i];
s[7] += g0[ix+i] * g1[iy+i] * g2[iz+i];
s[8] += g0[ix+i] * g0[iy+i] * g3[iz+i];
}
if (gout_empty) {
gout[n*1+0] = + s[0] + s[4] + s[8];
} else {
gout[n*1+0] += + s[0] + s[4] + s[8];
}}}
void int2e_r0_nablar12_optimizer(CINTOpt **opt, FINT *atm, FINT natm, FINT *bas, FINT nbas, double *env) {
FINT ng[] = {2, 0, 0, 0, 2, 1, 1, 1};
CINTall_2e_optimizer(opt, ng, atm, natm, bas, nbas, env);
}
CACHE_SIZE_T int2e_r0_nablar12_cart(double *out, FINT *dims, FINT *shls,
FINT *atm, FINT natm, FINT *bas, FINT nbas, double *env, CINTOpt *opt, double *cache) {
FINT ng[] = {2, 0, 0, 0, 2, 1, 1, 1};
CINTEnvVars envs;
CINTinit_int2e_EnvVars(&envs, ng, shls, atm, natm, bas, nbas, env);
envs.f_gout = &CINTgout2e_int2e_r0_nablar12;
envs.common_factor *= 1.0;
return CINT2e_drv(out, dims, &envs, opt, cache, &c2s_cart_2e1);
} // int2e_r0_nablar12_cart
CACHE_SIZE_T int2e_r0_nablar12_sph(double *out, FINT *dims, FINT *shls,
FINT *atm, FINT natm, FINT *bas, FINT nbas, double *env, CINTOpt *opt, double *cache) {
FINT ng[] = {2, 0, 0, 0, 2, 1, 1, 1};
CINTEnvVars envs;
CINTinit_int2e_EnvVars(&envs, ng, shls, atm, natm, bas, nbas, env);
envs.f_gout = &CINTgout2e_int2e_r0_nablar12;
envs.common_factor *= 1.0;
return CINT2e_drv(out, dims, &envs, opt, cache, &c2s_sph_2e1);
} // int2e_r0_nablar12_sph
CACHE_SIZE_T int2e_r0_nablar12_spinor(double complex *out, FINT *dims, FINT *shls,
FINT *atm, FINT natm, FINT *bas, FINT nbas, double *env, CINTOpt *opt, double *cache) {
FINT ng[] = {2, 0, 0, 0, 2, 1, 1, 1};
CINTEnvVars envs;
CINTinit_int2e_EnvVars(&envs, ng, shls, atm, natm, bas, nbas, env);
envs.f_gout = &CINTgout2e_int2e_r0_nablar12;
envs.common_factor *= 1.0;
return CINT2e_spinor_drv(out, dims, &envs, opt, cache, &c2s_sf_2e1, &c2s_sf_2e2);
} // int2e_r0_nablar12_spinor
ALL_CINT(int2e_r0_nablar12)
ALL_CINT_FORTRAN_(int2e_r0_nablar12)
/* <k i|R12 |j l> : i,j \in electron 1; k,l \in electron 2
 * = (i j|R12 |k l) */
void CINTgout2e_int2e_r12(double *gout,
double *g, FINT *idx, CINTEnvVars *envs, FINT gout_empty) {
FINT nf = envs->nf;
FINT nrys_roots = envs->nrys_roots;
FINT ix, iy, iz, i, n;
double *g0 = g;
double s[1];
for (n = 0; n < nf; n++) {
ix = idx[0+n*3];
iy = idx[1+n*3];
iz = idx[2+n*3];
switch (nrys_roots) {
case 1:
s[0] = + g0[ix+0]*g0[iy+0]*g0[iz+0];
break;
case 2:
s[0] = + g0[ix+0]*g0[iy+0]*g0[iz+0]+ g0[ix+1]*g0[iy+1]*g0[iz+1];
break;
case 3:
s[0] = + g0[ix+0]*g0[iy+0]*g0[iz+0]+ g0[ix+1]*g0[iy+1]*g0[iz+1]+ g0[ix+2]*g0[iy+2]*g0[iz+2];
break;
case 4:
s[0] = + g0[ix+0]*g0[iy+0]*g0[iz+0]+ g0[ix+1]*g0[iy+1]*g0[iz+1]+ g0[ix+2]*g0[iy+2]*g0[iz+2]+ g0[ix+3]*g0[iy+3]*g0[iz+3];
break;
default:
for (i = 0; i < 1; i++) { s[i] = 0; }
for (i = 0; i < nrys_roots; i++) {
s[0] += g0[ix+i] * g0[iy+i] * g0[iz+i];
} break;}
if (gout_empty) {
gout[n*1+0] = + s[0];
} else {
gout[n*1+0] += + s[0];
}}}
void int2e_r12_optimizer(CINTOpt **opt, FINT *atm, FINT natm, FINT *bas, FINT nbas, double *env) {
FINT ng[] = {0, 0, 0, 0, 0, 1, 1, 1};
CINTall_2e_optimizer(opt, ng, atm, natm, bas, nbas, env);
}
CACHE_SIZE_T int2e_r12_cart(double *out, FINT *dims, FINT *shls,
FINT *atm, FINT natm, FINT *bas, FINT nbas, double *env, CINTOpt *opt, double *cache) {
FINT ng[] = {0, 0, 0, 0, 0, 1, 1, 1};
CINTEnvVars envs;
CINTinit_int2e_EnvVars(&envs, ng, shls, atm, natm, bas, nbas, env);
envs.f_gout = &CINTgout2e_int2e_r12;
envs.common_factor *= 1.0;
return CINT2e_drv(out, dims, &envs, opt, cache, &c2s_cart_2e1);
} // int2e_r12_cart
CACHE_SIZE_T int2e_r12_sph(double *out, FINT *dims, FINT *shls,
FINT *atm, FINT natm, FINT *bas, FINT nbas, double *env, CINTOpt *opt, double *cache) {
FINT ng[] = {0, 0, 0, 0, 0, 1, 1, 1};
CINTEnvVars envs;
CINTinit_int2e_EnvVars(&envs, ng, shls, atm, natm, bas, nbas, env);
envs.f_gout = &CINTgout2e_int2e_r12;
envs.common_factor *= 1.0;
return CINT2e_drv(out, dims, &envs, opt, cache, &c2s_sph_2e1);
} // int2e_r12_sph
CACHE_SIZE_T int2e_r12_spinor(double complex *out, FINT *dims, FINT *shls,
FINT *atm, FINT natm, FINT *bas, FINT nbas, double *env, CINTOpt *opt, double *cache) {
FINT ng[] = {0, 0, 0, 0, 0, 1, 1, 1};
CINTEnvVars envs;
CINTinit_int2e_EnvVars(&envs, ng, shls, atm, natm, bas, nbas, env);
envs.f_gout = &CINTgout2e_int2e_r12;
envs.common_factor *= 1.0;
return CINT2e_spinor_drv(out, dims, &envs, opt, cache, &c2s_sf_2e1, &c2s_sf_2e2);
} // int2e_r12_spinor
ALL_CINT(int2e_r12)
ALL_CINT_FORTRAN_(int2e_r12)
