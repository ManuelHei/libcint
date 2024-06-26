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
/* <X0 i|NABLA-RINV |j> */
void CINTgout1e_int1e_x0_nablarinv(double *gout, double *g, FINT *idx, CINTEnvVars *envs, FINT gout_empty) {
FINT nf = envs->nf;
FINT nrys_roots = envs->nrys_roots;
FINT ix, iy, iz, n, i;
double *g0 = g;
double *g1 = g0 + envs->g_size * 3;
double *g2 = g1 + envs->g_size * 3;
double *g3 = g2 + envs->g_size * 3;
G2E_D_J(g1, g0, envs->i_l+1, envs->j_l+0, 0, 0);
G2E_D_I(g2, g0, envs->i_l+1, envs->j_l+0, 0, 0);
for (ix = 0; ix < envs->g_size * 3; ix++) {g1[ix] += g2[ix];}
G2E_R0I(g2, g0, envs->i_l+0, envs->j_l, 0, 0);
G2E_R0I(g3, g1, envs->i_l+0, envs->j_l, 0, 0);
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
void int1e_x0_nablarinv_optimizer(CINTOpt **opt, FINT *atm, FINT natm, FINT *bas, FINT nbas, double *env) {
FINT ng[] = {2, 1, 0, 0, 2, 1, 0, 3};
CINTall_1e_optimizer(opt, ng, atm, natm, bas, nbas, env);
}
CACHE_SIZE_T int1e_x0_nablarinv_cart(double *out, FINT *dims, FINT *shls,
FINT *atm, FINT natm, FINT *bas, FINT nbas, double *env, CINTOpt *opt, double *cache) {
FINT ng[] = {2, 1, 0, 0, 2, 1, 0, 3};
CINTEnvVars envs;
CINTinit_int1e_EnvVars(&envs, ng, shls, atm, natm, bas, nbas, env);
envs.f_gout = &CINTgout1e_int1e_x0_nablarinv;
envs.common_factor *= 1.0;
return CINT1e_drv(out, dims, &envs, cache, &c2s_cart_1e, 1);
} // int1e_x0_nablarinv_cart
CACHE_SIZE_T int1e_x0_nablarinv_sph(double *out, FINT *dims, FINT *shls,
FINT *atm, FINT natm, FINT *bas, FINT nbas, double *env, CINTOpt *opt, double *cache) {
FINT ng[] = {2, 1, 0, 0, 2, 1, 0, 3};
CINTEnvVars envs;
CINTinit_int1e_EnvVars(&envs, ng, shls, atm, natm, bas, nbas, env);
envs.f_gout = &CINTgout1e_int1e_x0_nablarinv;
envs.common_factor *= 1.0;
return CINT1e_drv(out, dims, &envs, cache, &c2s_sph_1e, 1);
} // int1e_x0_nablarinv_sph
CACHE_SIZE_T int1e_x0_nablarinv_spinor(double complex *out, FINT *dims, FINT *shls,
FINT *atm, FINT natm, FINT *bas, FINT nbas, double *env, CINTOpt *opt, double *cache) {
FINT ng[] = {2, 1, 0, 0, 2, 1, 0, 3};
CINTEnvVars envs;
CINTinit_int1e_EnvVars(&envs, ng, shls, atm, natm, bas, nbas, env);
envs.f_gout = &CINTgout1e_int1e_x0_nablarinv;
envs.common_factor *= 1.0;
return CINT1e_spinor_drv(out, dims, &envs, cache, &c2s_sf_1e, 1);
} // int1e_x0_nablarinv_spinor
ALL_CINT1E(int1e_x0_nablarinv)
ALL_CINT1E_FORTRAN_(int1e_x0_nablarinv)
/* <Y0 i|NABLA-RINV |j> */
void CINTgout1e_int1e_y0_nablarinv(double *gout, double *g, FINT *idx, CINTEnvVars *envs, FINT gout_empty) {
FINT nf = envs->nf;
FINT nrys_roots = envs->nrys_roots;
FINT ix, iy, iz, n, i;
double *g0 = g;
double *g1 = g0 + envs->g_size * 3;
double *g2 = g1 + envs->g_size * 3;
double *g3 = g2 + envs->g_size * 3;
G2E_D_J(g1, g0, envs->i_l+1, envs->j_l+0, 0, 0);
G2E_D_I(g2, g0, envs->i_l+1, envs->j_l+0, 0, 0);
for (ix = 0; ix < envs->g_size * 3; ix++) {g1[ix] += g2[ix];}
G2E_R0I(g2, g0, envs->i_l+0, envs->j_l, 0, 0);
G2E_R0I(g3, g1, envs->i_l+0, envs->j_l, 0, 0);
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
void int1e_y0_nablarinv_optimizer(CINTOpt **opt, FINT *atm, FINT natm, FINT *bas, FINT nbas, double *env) {
FINT ng[] = {2, 1, 0, 0, 2, 1, 0, 3};
CINTall_1e_optimizer(opt, ng, atm, natm, bas, nbas, env);
}
CACHE_SIZE_T int1e_y0_nablarinv_cart(double *out, FINT *dims, FINT *shls,
FINT *atm, FINT natm, FINT *bas, FINT nbas, double *env, CINTOpt *opt, double *cache) {
FINT ng[] = {2, 1, 0, 0, 2, 1, 0, 3};
CINTEnvVars envs;
CINTinit_int1e_EnvVars(&envs, ng, shls, atm, natm, bas, nbas, env);
envs.f_gout = &CINTgout1e_int1e_y0_nablarinv;
envs.common_factor *= 1.0;
return CINT1e_drv(out, dims, &envs, cache, &c2s_cart_1e, 1);
} // int1e_y0_nablarinv_cart
CACHE_SIZE_T int1e_y0_nablarinv_sph(double *out, FINT *dims, FINT *shls,
FINT *atm, FINT natm, FINT *bas, FINT nbas, double *env, CINTOpt *opt, double *cache) {
FINT ng[] = {2, 1, 0, 0, 2, 1, 0, 3};
CINTEnvVars envs;
CINTinit_int1e_EnvVars(&envs, ng, shls, atm, natm, bas, nbas, env);
envs.f_gout = &CINTgout1e_int1e_y0_nablarinv;
envs.common_factor *= 1.0;
return CINT1e_drv(out, dims, &envs, cache, &c2s_sph_1e, 1);
} // int1e_y0_nablarinv_sph
CACHE_SIZE_T int1e_y0_nablarinv_spinor(double complex *out, FINT *dims, FINT *shls,
FINT *atm, FINT natm, FINT *bas, FINT nbas, double *env, CINTOpt *opt, double *cache) {
FINT ng[] = {2, 1, 0, 0, 2, 1, 0, 3};
CINTEnvVars envs;
CINTinit_int1e_EnvVars(&envs, ng, shls, atm, natm, bas, nbas, env);
envs.f_gout = &CINTgout1e_int1e_y0_nablarinv;
envs.common_factor *= 1.0;
return CINT1e_spinor_drv(out, dims, &envs, cache, &c2s_sf_1e, 1);
} // int1e_y0_nablarinv_spinor
ALL_CINT1E(int1e_y0_nablarinv)
ALL_CINT1E_FORTRAN_(int1e_y0_nablarinv)
/* <Z0 i|NABLA-RINV |j> */
void CINTgout1e_int1e_z0_nablarinv(double *gout, double *g, FINT *idx, CINTEnvVars *envs, FINT gout_empty) {
FINT nf = envs->nf;
FINT nrys_roots = envs->nrys_roots;
FINT ix, iy, iz, n, i;
double *g0 = g;
double *g1 = g0 + envs->g_size * 3;
double *g2 = g1 + envs->g_size * 3;
double *g3 = g2 + envs->g_size * 3;
G2E_D_J(g1, g0, envs->i_l+1, envs->j_l+0, 0, 0);
G2E_D_I(g2, g0, envs->i_l+1, envs->j_l+0, 0, 0);
for (ix = 0; ix < envs->g_size * 3; ix++) {g1[ix] += g2[ix];}
G2E_R0I(g2, g0, envs->i_l+0, envs->j_l, 0, 0);
G2E_R0I(g3, g1, envs->i_l+0, envs->j_l, 0, 0);
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
void int1e_z0_nablarinv_optimizer(CINTOpt **opt, FINT *atm, FINT natm, FINT *bas, FINT nbas, double *env) {
FINT ng[] = {2, 1, 0, 0, 2, 1, 0, 3};
CINTall_1e_optimizer(opt, ng, atm, natm, bas, nbas, env);
}
CACHE_SIZE_T int1e_z0_nablarinv_cart(double *out, FINT *dims, FINT *shls,
FINT *atm, FINT natm, FINT *bas, FINT nbas, double *env, CINTOpt *opt, double *cache) {
FINT ng[] = {2, 1, 0, 0, 2, 1, 0, 3};
CINTEnvVars envs;
CINTinit_int1e_EnvVars(&envs, ng, shls, atm, natm, bas, nbas, env);
envs.f_gout = &CINTgout1e_int1e_z0_nablarinv;
envs.common_factor *= 1.0;
return CINT1e_drv(out, dims, &envs, cache, &c2s_cart_1e, 1);
} // int1e_z0_nablarinv_cart
CACHE_SIZE_T int1e_z0_nablarinv_sph(double *out, FINT *dims, FINT *shls,
FINT *atm, FINT natm, FINT *bas, FINT nbas, double *env, CINTOpt *opt, double *cache) {
FINT ng[] = {2, 1, 0, 0, 2, 1, 0, 3};
CINTEnvVars envs;
CINTinit_int1e_EnvVars(&envs, ng, shls, atm, natm, bas, nbas, env);
envs.f_gout = &CINTgout1e_int1e_z0_nablarinv;
envs.common_factor *= 1.0;
return CINT1e_drv(out, dims, &envs, cache, &c2s_sph_1e, 1);
} // int1e_z0_nablarinv_sph
CACHE_SIZE_T int1e_z0_nablarinv_spinor(double complex *out, FINT *dims, FINT *shls,
FINT *atm, FINT natm, FINT *bas, FINT nbas, double *env, CINTOpt *opt, double *cache) {
FINT ng[] = {2, 1, 0, 0, 2, 1, 0, 3};
CINTEnvVars envs;
CINTinit_int1e_EnvVars(&envs, ng, shls, atm, natm, bas, nbas, env);
envs.f_gout = &CINTgout1e_int1e_z0_nablarinv;
envs.common_factor *= 1.0;
return CINT1e_spinor_drv(out, dims, &envs, cache, &c2s_sf_1e, 1);
} // int1e_z0_nablarinv_spinor
ALL_CINT1E(int1e_z0_nablarinv)
ALL_CINT1E_FORTRAN_(int1e_z0_nablarinv)
/* <R0 i|NABLA-RINV |j> */
void CINTgout1e_int1e_r0_nablarinv(double *gout, double *g, FINT *idx, CINTEnvVars *envs, FINT gout_empty) {
FINT nf = envs->nf;
FINT nrys_roots = envs->nrys_roots;
FINT ix, iy, iz, n, i;
double *g0 = g;
double *g1 = g0 + envs->g_size * 3;
double *g2 = g1 + envs->g_size * 3;
double *g3 = g2 + envs->g_size * 3;
G2E_D_J(g1, g0, envs->i_l+1, envs->j_l+0, 0, 0);
G2E_D_I(g2, g0, envs->i_l+1, envs->j_l+0, 0, 0);
for (ix = 0; ix < envs->g_size * 3; ix++) {g1[ix] += g2[ix];}
G2E_R0I(g2, g0, envs->i_l+0, envs->j_l, 0, 0);
G2E_R0I(g3, g1, envs->i_l+0, envs->j_l, 0, 0);
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
gout[n*9+0] = + s[0];
gout[n*9+1] = + s[1];
gout[n*9+2] = + s[2];
gout[n*9+3] = + s[3];
gout[n*9+4] = + s[4];
gout[n*9+5] = + s[5];
gout[n*9+6] = + s[6];
gout[n*9+7] = + s[7];
gout[n*9+8] = + s[8];
} else {
gout[n*9+0] += + s[0];
gout[n*9+1] += + s[1];
gout[n*9+2] += + s[2];
gout[n*9+3] += + s[3];
gout[n*9+4] += + s[4];
gout[n*9+5] += + s[5];
gout[n*9+6] += + s[6];
gout[n*9+7] += + s[7];
gout[n*9+8] += + s[8];
}}}
void int1e_r0_nablarinv_optimizer(CINTOpt **opt, FINT *atm, FINT natm, FINT *bas, FINT nbas, double *env) {
FINT ng[] = {2, 1, 0, 0, 2, 1, 0, 9};
CINTall_1e_optimizer(opt, ng, atm, natm, bas, nbas, env);
}
CACHE_SIZE_T int1e_r0_nablarinv_cart(double *out, FINT *dims, FINT *shls,
FINT *atm, FINT natm, FINT *bas, FINT nbas, double *env, CINTOpt *opt, double *cache) {
FINT ng[] = {2, 1, 0, 0, 2, 1, 0, 9};
CINTEnvVars envs;
CINTinit_int1e_EnvVars(&envs, ng, shls, atm, natm, bas, nbas, env);
envs.f_gout = &CINTgout1e_int1e_r0_nablarinv;
envs.common_factor *= 1.0;
return CINT1e_drv(out, dims, &envs, cache, &c2s_cart_1e, 1);
} // int1e_r0_nablarinv_cart
CACHE_SIZE_T int1e_r0_nablarinv_sph(double *out, FINT *dims, FINT *shls,
FINT *atm, FINT natm, FINT *bas, FINT nbas, double *env, CINTOpt *opt, double *cache) {
FINT ng[] = {2, 1, 0, 0, 2, 1, 0, 9};
CINTEnvVars envs;
CINTinit_int1e_EnvVars(&envs, ng, shls, atm, natm, bas, nbas, env);
envs.f_gout = &CINTgout1e_int1e_r0_nablarinv;
envs.common_factor *= 1.0;
return CINT1e_drv(out, dims, &envs, cache, &c2s_sph_1e, 1);
} // int1e_r0_nablarinv_sph
CACHE_SIZE_T int1e_r0_nablarinv_spinor(double complex *out, FINT *dims, FINT *shls,
FINT *atm, FINT natm, FINT *bas, FINT nbas, double *env, CINTOpt *opt, double *cache) {
FINT ng[] = {2, 1, 0, 0, 2, 1, 0, 9};
CINTEnvVars envs;
CINTinit_int1e_EnvVars(&envs, ng, shls, atm, natm, bas, nbas, env);
envs.f_gout = &CINTgout1e_int1e_r0_nablarinv;
envs.common_factor *= 1.0;
return CINT1e_spinor_drv(out, dims, &envs, cache, &c2s_sf_1e, 1);
} // int1e_r0_nablarinv_spinor
ALL_CINT1E(int1e_r0_nablarinv)
ALL_CINT1E_FORTRAN_(int1e_r0_nablarinv)
/* <X0 NABLA i|NUC |j> */
void CINTgout1e_int1e_x0_nablarnuc(double *gout, double *g, FINT *idx, CINTEnvVars *envs, FINT gout_empty) {
FINT nf = envs->nf;
FINT nrys_roots = envs->nrys_roots;
FINT ix, iy, iz, n, i;
double *g0 = g;
double *g1 = g0 + envs->g_size * 3;
double *g2 = g1 + envs->g_size * 3;
double *g3 = g2 + envs->g_size * 3;
G2E_R0I(g1, g0, envs->i_l+1, envs->j_l, 0, 0);
G2E_D_I(g2, g0, envs->i_l+0, envs->j_l, 0, 0);
G2E_D_I(g3, g1, envs->i_l+0, envs->j_l, 0, 0);
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
gout[n*3+1] = + s[3];
gout[n*3+2] = + s[6];
} else {
gout[n*3+0] += + s[0];
gout[n*3+1] += + s[3];
gout[n*3+2] += + s[6];
}}}
void int1e_x0_nablarnuc_optimizer(CINTOpt **opt, FINT *atm, FINT natm, FINT *bas, FINT nbas, double *env) {
FINT ng[] = {2, 0, 0, 0, 2, 1, 0, 3};
CINTall_1e_optimizer(opt, ng, atm, natm, bas, nbas, env);
}
CACHE_SIZE_T int1e_x0_nablarnuc_cart(double *out, FINT *dims, FINT *shls,
FINT *atm, FINT natm, FINT *bas, FINT nbas, double *env, CINTOpt *opt, double *cache) {
FINT ng[] = {2, 0, 0, 0, 2, 1, 0, 3};
CINTEnvVars envs;
CINTinit_int1e_EnvVars(&envs, ng, shls, atm, natm, bas, nbas, env);
envs.f_gout = &CINTgout1e_int1e_x0_nablarnuc;
envs.common_factor *= 1.0;
return CINT1e_drv(out, dims, &envs, cache, &c2s_cart_1e, 2);
} // int1e_x0_nablarnuc_cart
CACHE_SIZE_T int1e_x0_nablarnuc_sph(double *out, FINT *dims, FINT *shls,
FINT *atm, FINT natm, FINT *bas, FINT nbas, double *env, CINTOpt *opt, double *cache) {
FINT ng[] = {2, 0, 0, 0, 2, 1, 0, 3};
CINTEnvVars envs;
CINTinit_int1e_EnvVars(&envs, ng, shls, atm, natm, bas, nbas, env);
envs.f_gout = &CINTgout1e_int1e_x0_nablarnuc;
envs.common_factor *= 1.0;
return CINT1e_drv(out, dims, &envs, cache, &c2s_sph_1e, 2);
} // int1e_x0_nablarnuc_sph
CACHE_SIZE_T int1e_x0_nablarnuc_spinor(double complex *out, FINT *dims, FINT *shls,
FINT *atm, FINT natm, FINT *bas, FINT nbas, double *env, CINTOpt *opt, double *cache) {
FINT ng[] = {2, 0, 0, 0, 2, 1, 0, 3};
CINTEnvVars envs;
CINTinit_int1e_EnvVars(&envs, ng, shls, atm, natm, bas, nbas, env);
envs.f_gout = &CINTgout1e_int1e_x0_nablarnuc;
envs.common_factor *= 1.0;
return CINT1e_spinor_drv(out, dims, &envs, cache, &c2s_sf_1e, 2);
} // int1e_x0_nablarnuc_spinor
ALL_CINT1E(int1e_x0_nablarnuc)
ALL_CINT1E_FORTRAN_(int1e_x0_nablarnuc)
/* <Y0 NABLA i|NUC |j> */
void CINTgout1e_int1e_y0_nablarnuc(double *gout, double *g, FINT *idx, CINTEnvVars *envs, FINT gout_empty) {
FINT nf = envs->nf;
FINT nrys_roots = envs->nrys_roots;
FINT ix, iy, iz, n, i;
double *g0 = g;
double *g1 = g0 + envs->g_size * 3;
double *g2 = g1 + envs->g_size * 3;
double *g3 = g2 + envs->g_size * 3;
G2E_R0I(g1, g0, envs->i_l+1, envs->j_l, 0, 0);
G2E_D_I(g2, g0, envs->i_l+0, envs->j_l, 0, 0);
G2E_D_I(g3, g1, envs->i_l+0, envs->j_l, 0, 0);
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
gout[n*3+0] = + s[1];
gout[n*3+1] = + s[4];
gout[n*3+2] = + s[7];
} else {
gout[n*3+0] += + s[1];
gout[n*3+1] += + s[4];
gout[n*3+2] += + s[7];
}}}
void int1e_y0_nablarnuc_optimizer(CINTOpt **opt, FINT *atm, FINT natm, FINT *bas, FINT nbas, double *env) {
FINT ng[] = {2, 0, 0, 0, 2, 1, 0, 3};
CINTall_1e_optimizer(opt, ng, atm, natm, bas, nbas, env);
}
CACHE_SIZE_T int1e_y0_nablarnuc_cart(double *out, FINT *dims, FINT *shls,
FINT *atm, FINT natm, FINT *bas, FINT nbas, double *env, CINTOpt *opt, double *cache) {
FINT ng[] = {2, 0, 0, 0, 2, 1, 0, 3};
CINTEnvVars envs;
CINTinit_int1e_EnvVars(&envs, ng, shls, atm, natm, bas, nbas, env);
envs.f_gout = &CINTgout1e_int1e_y0_nablarnuc;
envs.common_factor *= 1.0;
return CINT1e_drv(out, dims, &envs, cache, &c2s_cart_1e, 2);
} // int1e_y0_nablarnuc_cart
CACHE_SIZE_T int1e_y0_nablarnuc_sph(double *out, FINT *dims, FINT *shls,
FINT *atm, FINT natm, FINT *bas, FINT nbas, double *env, CINTOpt *opt, double *cache) {
FINT ng[] = {2, 0, 0, 0, 2, 1, 0, 3};
CINTEnvVars envs;
CINTinit_int1e_EnvVars(&envs, ng, shls, atm, natm, bas, nbas, env);
envs.f_gout = &CINTgout1e_int1e_y0_nablarnuc;
envs.common_factor *= 1.0;
return CINT1e_drv(out, dims, &envs, cache, &c2s_sph_1e, 2);
} // int1e_y0_nablarnuc_sph
CACHE_SIZE_T int1e_y0_nablarnuc_spinor(double complex *out, FINT *dims, FINT *shls,
FINT *atm, FINT natm, FINT *bas, FINT nbas, double *env, CINTOpt *opt, double *cache) {
FINT ng[] = {2, 0, 0, 0, 2, 1, 0, 3};
CINTEnvVars envs;
CINTinit_int1e_EnvVars(&envs, ng, shls, atm, natm, bas, nbas, env);
envs.f_gout = &CINTgout1e_int1e_y0_nablarnuc;
envs.common_factor *= 1.0;
return CINT1e_spinor_drv(out, dims, &envs, cache, &c2s_sf_1e, 2);
} // int1e_y0_nablarnuc_spinor
ALL_CINT1E(int1e_y0_nablarnuc)
ALL_CINT1E_FORTRAN_(int1e_y0_nablarnuc)
/* <Z0 NABLA i|NUC |j> */
void CINTgout1e_int1e_z0_nablarnuc(double *gout, double *g, FINT *idx, CINTEnvVars *envs, FINT gout_empty) {
FINT nf = envs->nf;
FINT nrys_roots = envs->nrys_roots;
FINT ix, iy, iz, n, i;
double *g0 = g;
double *g1 = g0 + envs->g_size * 3;
double *g2 = g1 + envs->g_size * 3;
double *g3 = g2 + envs->g_size * 3;
G2E_R0I(g1, g0, envs->i_l+1, envs->j_l, 0, 0);
G2E_D_I(g2, g0, envs->i_l+0, envs->j_l, 0, 0);
G2E_D_I(g3, g1, envs->i_l+0, envs->j_l, 0, 0);
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
gout[n*3+0] = + s[2];
gout[n*3+1] = + s[5];
gout[n*3+2] = + s[8];
} else {
gout[n*3+0] += + s[2];
gout[n*3+1] += + s[5];
gout[n*3+2] += + s[8];
}}}
void int1e_z0_nablarnuc_optimizer(CINTOpt **opt, FINT *atm, FINT natm, FINT *bas, FINT nbas, double *env) {
FINT ng[] = {2, 0, 0, 0, 2, 1, 0, 3};
CINTall_1e_optimizer(opt, ng, atm, natm, bas, nbas, env);
}
CACHE_SIZE_T int1e_z0_nablarnuc_cart(double *out, FINT *dims, FINT *shls,
FINT *atm, FINT natm, FINT *bas, FINT nbas, double *env, CINTOpt *opt, double *cache) {
FINT ng[] = {2, 0, 0, 0, 2, 1, 0, 3};
CINTEnvVars envs;
CINTinit_int1e_EnvVars(&envs, ng, shls, atm, natm, bas, nbas, env);
envs.f_gout = &CINTgout1e_int1e_z0_nablarnuc;
envs.common_factor *= 1.0;
return CINT1e_drv(out, dims, &envs, cache, &c2s_cart_1e, 2);
} // int1e_z0_nablarnuc_cart
CACHE_SIZE_T int1e_z0_nablarnuc_sph(double *out, FINT *dims, FINT *shls,
FINT *atm, FINT natm, FINT *bas, FINT nbas, double *env, CINTOpt *opt, double *cache) {
FINT ng[] = {2, 0, 0, 0, 2, 1, 0, 3};
CINTEnvVars envs;
CINTinit_int1e_EnvVars(&envs, ng, shls, atm, natm, bas, nbas, env);
envs.f_gout = &CINTgout1e_int1e_z0_nablarnuc;
envs.common_factor *= 1.0;
return CINT1e_drv(out, dims, &envs, cache, &c2s_sph_1e, 2);
} // int1e_z0_nablarnuc_sph
CACHE_SIZE_T int1e_z0_nablarnuc_spinor(double complex *out, FINT *dims, FINT *shls,
FINT *atm, FINT natm, FINT *bas, FINT nbas, double *env, CINTOpt *opt, double *cache) {
FINT ng[] = {2, 0, 0, 0, 2, 1, 0, 3};
CINTEnvVars envs;
CINTinit_int1e_EnvVars(&envs, ng, shls, atm, natm, bas, nbas, env);
envs.f_gout = &CINTgout1e_int1e_z0_nablarnuc;
envs.common_factor *= 1.0;
return CINT1e_spinor_drv(out, dims, &envs, cache, &c2s_sf_1e, 2);
} // int1e_z0_nablarnuc_spinor
ALL_CINT1E(int1e_z0_nablarnuc)
ALL_CINT1E_FORTRAN_(int1e_z0_nablarnuc)
/* <R0 DOT NABLA i|NUC |j> */
void CINTgout1e_int1e_r0_nablarnuc(double *gout, double *g, FINT *idx, CINTEnvVars *envs, FINT gout_empty) {
FINT nf = envs->nf;
FINT nrys_roots = envs->nrys_roots;
FINT ix, iy, iz, n, i;
double *g0 = g;
double *g1 = g0 + envs->g_size * 3;
double *g2 = g1 + envs->g_size * 3;
double *g3 = g2 + envs->g_size * 3;
G2E_R0I(g1, g0, envs->i_l+1, envs->j_l, 0, 0);
G2E_D_I(g2, g0, envs->i_l+0, envs->j_l, 0, 0);
G2E_D_I(g3, g1, envs->i_l+0, envs->j_l, 0, 0);
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
void int1e_r0_nablarnuc_optimizer(CINTOpt **opt, FINT *atm, FINT natm, FINT *bas, FINT nbas, double *env) {
FINT ng[] = {2, 0, 0, 0, 2, 1, 0, 1};
CINTall_1e_optimizer(opt, ng, atm, natm, bas, nbas, env);
}
CACHE_SIZE_T int1e_r0_nablarnuc_cart(double *out, FINT *dims, FINT *shls,
FINT *atm, FINT natm, FINT *bas, FINT nbas, double *env, CINTOpt *opt, double *cache) {
FINT ng[] = {2, 0, 0, 0, 2, 1, 0, 1};
CINTEnvVars envs;
CINTinit_int1e_EnvVars(&envs, ng, shls, atm, natm, bas, nbas, env);
envs.f_gout = &CINTgout1e_int1e_r0_nablarnuc;
envs.common_factor *= 1.0;
return CINT1e_drv(out, dims, &envs, cache, &c2s_cart_1e, 2);
} // int1e_r0_nablarnuc_cart
CACHE_SIZE_T int1e_r0_nablarnuc_sph(double *out, FINT *dims, FINT *shls,
FINT *atm, FINT natm, FINT *bas, FINT nbas, double *env, CINTOpt *opt, double *cache) {
FINT ng[] = {2, 0, 0, 0, 2, 1, 0, 1};
CINTEnvVars envs;
CINTinit_int1e_EnvVars(&envs, ng, shls, atm, natm, bas, nbas, env);
envs.f_gout = &CINTgout1e_int1e_r0_nablarnuc;
envs.common_factor *= 1.0;
return CINT1e_drv(out, dims, &envs, cache, &c2s_sph_1e, 2);
} // int1e_r0_nablarnuc_sph
CACHE_SIZE_T int1e_r0_nablarnuc_spinor(double complex *out, FINT *dims, FINT *shls,
FINT *atm, FINT natm, FINT *bas, FINT nbas, double *env, CINTOpt *opt, double *cache) {
FINT ng[] = {2, 0, 0, 0, 2, 1, 0, 1};
CINTEnvVars envs;
CINTinit_int1e_EnvVars(&envs, ng, shls, atm, natm, bas, nbas, env);
envs.f_gout = &CINTgout1e_int1e_r0_nablarnuc;
envs.common_factor *= 1.0;
return CINT1e_spinor_drv(out, dims, &envs, cache, &c2s_sf_1e, 2);
} // int1e_r0_nablarnuc_spinor
ALL_CINT1E(int1e_r0_nablarnuc)
ALL_CINT1E_FORTRAN_(int1e_r0_nablarnuc)
