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
/* (i |X R12 R12 R12 |j) */
static void CINTgout2e_int2c2e_test_x(double *gout,
double *g, FINT *idx, CINTEnvVars *envs, FINT gout_empty) {
FINT nf = envs->nf;
FINT nrys_roots = envs->nrys_roots;
FINT ix, iy, iz, i, n;
double *g0 = g;
double *g1 = g0 + envs->g_size * 3;
G2E_R_J(g1, g0, envs->i_l+0, 0, envs->k_l, 0);
double s[3];
for (n = 0; n < nf; n++) {
ix = idx[0+n*3];
iy = idx[1+n*3];
iz = idx[2+n*3];
switch (nrys_roots) {
case 1:
s[0] = + g1[ix+0]*g0[iy+0]*g0[iz+0];
s[1] = + g0[ix+0]*g1[iy+0]*g0[iz+0];
s[2] = + g0[ix+0]*g0[iy+0]*g1[iz+0];
break;
case 2:
s[0] = + g1[ix+0]*g0[iy+0]*g0[iz+0]+ g1[ix+1]*g0[iy+1]*g0[iz+1];
s[1] = + g0[ix+0]*g1[iy+0]*g0[iz+0]+ g0[ix+1]*g1[iy+1]*g0[iz+1];
s[2] = + g0[ix+0]*g0[iy+0]*g1[iz+0]+ g0[ix+1]*g0[iy+1]*g1[iz+1];
break;
case 3:
s[0] = + g1[ix+0]*g0[iy+0]*g0[iz+0]+ g1[ix+1]*g0[iy+1]*g0[iz+1]+ g1[ix+2]*g0[iy+2]*g0[iz+2];
s[1] = + g0[ix+0]*g1[iy+0]*g0[iz+0]+ g0[ix+1]*g1[iy+1]*g0[iz+1]+ g0[ix+2]*g1[iy+2]*g0[iz+2];
s[2] = + g0[ix+0]*g0[iy+0]*g1[iz+0]+ g0[ix+1]*g0[iy+1]*g1[iz+1]+ g0[ix+2]*g0[iy+2]*g1[iz+2];
break;
case 4:
s[0] = + g1[ix+0]*g0[iy+0]*g0[iz+0]+ g1[ix+1]*g0[iy+1]*g0[iz+1]+ g1[ix+2]*g0[iy+2]*g0[iz+2]+ g1[ix+3]*g0[iy+3]*g0[iz+3];
s[1] = + g0[ix+0]*g1[iy+0]*g0[iz+0]+ g0[ix+1]*g1[iy+1]*g0[iz+1]+ g0[ix+2]*g1[iy+2]*g0[iz+2]+ g0[ix+3]*g1[iy+3]*g0[iz+3];
s[2] = + g0[ix+0]*g0[iy+0]*g1[iz+0]+ g0[ix+1]*g0[iy+1]*g1[iz+1]+ g0[ix+2]*g0[iy+2]*g1[iz+2]+ g0[ix+3]*g0[iy+3]*g1[iz+3];
break;
default:
for (i = 0; i < 3; i++) { s[i] = 0; }
for (i = 0; i < nrys_roots; i++) {
s[0] += g1[ix+i] * g0[iy+i] * g0[iz+i];
s[1] += g0[ix+i] * g1[iy+i] * g0[iz+i];
s[2] += g0[ix+i] * g0[iy+i] * g1[iz+i];
} break;}
if (gout_empty) {
gout[n*1+0] = + s[0];
} else {
gout[n*1+0] += + s[0];
}}}
void int2c2e_test_x_optimizer(CINTOpt **opt, FINT *atm, FINT natm, FINT *bas, FINT nbas, double *env) {
FINT ng[] = {0, 1, 0, 0, 1, 1, 1, 1};
CINTall_2c2e_optimizer(opt, ng, atm, natm, bas, nbas, env);
}
CACHE_SIZE_T int2c2e_test_x_cart(double *out, FINT *dims, FINT *shls,
FINT *atm, FINT natm, FINT *bas, FINT nbas, double *env, CINTOpt *opt, double *cache) {
FINT ng[] = {0, 1, 0, 0, 1, 1, 1, 1};
CINTEnvVars envs;
CINTinit_int2c2e_EnvVars(&envs, ng, shls, atm, natm, bas, nbas, env);
envs.f_gout = &CINTgout2e_int2c2e_test_x;
envs.common_factor *= 1.0;
return CINT2c2e_drv(out, dims, &envs, opt, cache, &c2s_cart_1e);
} // int2c2e_test_x_cart
CACHE_SIZE_T int2c2e_test_x_sph(double *out, FINT *dims, FINT *shls,
FINT *atm, FINT natm, FINT *bas, FINT nbas, double *env, CINTOpt *opt, double *cache) {
FINT ng[] = {0, 1, 0, 0, 1, 1, 1, 1};
CINTEnvVars envs;
CINTinit_int2c2e_EnvVars(&envs, ng, shls, atm, natm, bas, nbas, env);
envs.f_gout = &CINTgout2e_int2c2e_test_x;
envs.common_factor *= 1.0;
return CINT2c2e_drv(out, dims, &envs, opt, cache, &c2s_sph_1e);
} // int2c2e_test_x_sph
CACHE_SIZE_T int2c2e_test_x_spinor(double complex *out, FINT *dims, FINT *shls,
FINT *atm, FINT natm, FINT *bas, FINT nbas, double *env, CINTOpt *opt, double *cache) {
fprintf(stderr, "&c2s_sf_1e_spinor not implementedn");
return 0;
}
ALL_CINT(int2c2e_test_x)
ALL_CINT_FORTRAN_(int2c2e_test_x)
/* (i |Y R12 R12 R12 |j) */
static void CINTgout2e_int2c2e_test_y(double *gout,
double *g, FINT *idx, CINTEnvVars *envs, FINT gout_empty) {
FINT nf = envs->nf;
FINT nrys_roots = envs->nrys_roots;
FINT ix, iy, iz, i, n;
double *g0 = g;
double *g1 = g0 + envs->g_size * 3;
G2E_R_J(g1, g0, envs->i_l+0, 0, envs->k_l, 0);
double s[3];
for (n = 0; n < nf; n++) {
ix = idx[0+n*3];
iy = idx[1+n*3];
iz = idx[2+n*3];
switch (nrys_roots) {
case 1:
s[0] = + g1[ix+0]*g0[iy+0]*g0[iz+0];
s[1] = + g0[ix+0]*g1[iy+0]*g0[iz+0];
s[2] = + g0[ix+0]*g0[iy+0]*g1[iz+0];
break;
case 2:
s[0] = + g1[ix+0]*g0[iy+0]*g0[iz+0]+ g1[ix+1]*g0[iy+1]*g0[iz+1];
s[1] = + g0[ix+0]*g1[iy+0]*g0[iz+0]+ g0[ix+1]*g1[iy+1]*g0[iz+1];
s[2] = + g0[ix+0]*g0[iy+0]*g1[iz+0]+ g0[ix+1]*g0[iy+1]*g1[iz+1];
break;
case 3:
s[0] = + g1[ix+0]*g0[iy+0]*g0[iz+0]+ g1[ix+1]*g0[iy+1]*g0[iz+1]+ g1[ix+2]*g0[iy+2]*g0[iz+2];
s[1] = + g0[ix+0]*g1[iy+0]*g0[iz+0]+ g0[ix+1]*g1[iy+1]*g0[iz+1]+ g0[ix+2]*g1[iy+2]*g0[iz+2];
s[2] = + g0[ix+0]*g0[iy+0]*g1[iz+0]+ g0[ix+1]*g0[iy+1]*g1[iz+1]+ g0[ix+2]*g0[iy+2]*g1[iz+2];
break;
case 4:
s[0] = + g1[ix+0]*g0[iy+0]*g0[iz+0]+ g1[ix+1]*g0[iy+1]*g0[iz+1]+ g1[ix+2]*g0[iy+2]*g0[iz+2]+ g1[ix+3]*g0[iy+3]*g0[iz+3];
s[1] = + g0[ix+0]*g1[iy+0]*g0[iz+0]+ g0[ix+1]*g1[iy+1]*g0[iz+1]+ g0[ix+2]*g1[iy+2]*g0[iz+2]+ g0[ix+3]*g1[iy+3]*g0[iz+3];
s[2] = + g0[ix+0]*g0[iy+0]*g1[iz+0]+ g0[ix+1]*g0[iy+1]*g1[iz+1]+ g0[ix+2]*g0[iy+2]*g1[iz+2]+ g0[ix+3]*g0[iy+3]*g1[iz+3];
break;
default:
for (i = 0; i < 3; i++) { s[i] = 0; }
for (i = 0; i < nrys_roots; i++) {
s[0] += g1[ix+i] * g0[iy+i] * g0[iz+i];
s[1] += g0[ix+i] * g1[iy+i] * g0[iz+i];
s[2] += g0[ix+i] * g0[iy+i] * g1[iz+i];
} break;}
if (gout_empty) {
gout[n*1+0] = + s[1];
} else {
gout[n*1+0] += + s[1];
}}}
void int2c2e_test_y_optimizer(CINTOpt **opt, FINT *atm, FINT natm, FINT *bas, FINT nbas, double *env) {
FINT ng[] = {0, 1, 0, 0, 1, 1, 1, 1};
CINTall_2c2e_optimizer(opt, ng, atm, natm, bas, nbas, env);
}
CACHE_SIZE_T int2c2e_test_y_cart(double *out, FINT *dims, FINT *shls,
FINT *atm, FINT natm, FINT *bas, FINT nbas, double *env, CINTOpt *opt, double *cache) {
FINT ng[] = {0, 1, 0, 0, 1, 1, 1, 1};
CINTEnvVars envs;
CINTinit_int2c2e_EnvVars(&envs, ng, shls, atm, natm, bas, nbas, env);
envs.f_gout = &CINTgout2e_int2c2e_test_y;
envs.common_factor *= 1.0;
return CINT2c2e_drv(out, dims, &envs, opt, cache, &c2s_cart_1e);
} // int2c2e_test_y_cart
CACHE_SIZE_T int2c2e_test_y_sph(double *out, FINT *dims, FINT *shls,
FINT *atm, FINT natm, FINT *bas, FINT nbas, double *env, CINTOpt *opt, double *cache) {
FINT ng[] = {0, 1, 0, 0, 1, 1, 1, 1};
CINTEnvVars envs;
CINTinit_int2c2e_EnvVars(&envs, ng, shls, atm, natm, bas, nbas, env);
envs.f_gout = &CINTgout2e_int2c2e_test_y;
envs.common_factor *= 1.0;
return CINT2c2e_drv(out, dims, &envs, opt, cache, &c2s_sph_1e);
} // int2c2e_test_y_sph
CACHE_SIZE_T int2c2e_test_y_spinor(double complex *out, FINT *dims, FINT *shls,
FINT *atm, FINT natm, FINT *bas, FINT nbas, double *env, CINTOpt *opt, double *cache) {
fprintf(stderr, "&c2s_sf_1e_spinor not implementedn");
return 0;
}
ALL_CINT(int2c2e_test_y)
ALL_CINT_FORTRAN_(int2c2e_test_y)
/* (i |Z R12 R12 R12 |j) */
static void CINTgout2e_int2c2e_test_z(double *gout,
double *g, FINT *idx, CINTEnvVars *envs, FINT gout_empty) {
FINT nf = envs->nf;
FINT nrys_roots = envs->nrys_roots;
FINT ix, iy, iz, i, n;
double *g0 = g;
double *g1 = g0 + envs->g_size * 3;
G2E_R_J(g1, g0, envs->i_l+0, 0, envs->k_l, 0);
double s[3];
for (n = 0; n < nf; n++) {
ix = idx[0+n*3];
iy = idx[1+n*3];
iz = idx[2+n*3];
switch (nrys_roots) {
case 1:
s[0] = + g1[ix+0]*g0[iy+0]*g0[iz+0];
s[1] = + g0[ix+0]*g1[iy+0]*g0[iz+0];
s[2] = + g0[ix+0]*g0[iy+0]*g1[iz+0];
break;
case 2:
s[0] = + g1[ix+0]*g0[iy+0]*g0[iz+0]+ g1[ix+1]*g0[iy+1]*g0[iz+1];
s[1] = + g0[ix+0]*g1[iy+0]*g0[iz+0]+ g0[ix+1]*g1[iy+1]*g0[iz+1];
s[2] = + g0[ix+0]*g0[iy+0]*g1[iz+0]+ g0[ix+1]*g0[iy+1]*g1[iz+1];
break;
case 3:
s[0] = + g1[ix+0]*g0[iy+0]*g0[iz+0]+ g1[ix+1]*g0[iy+1]*g0[iz+1]+ g1[ix+2]*g0[iy+2]*g0[iz+2];
s[1] = + g0[ix+0]*g1[iy+0]*g0[iz+0]+ g0[ix+1]*g1[iy+1]*g0[iz+1]+ g0[ix+2]*g1[iy+2]*g0[iz+2];
s[2] = + g0[ix+0]*g0[iy+0]*g1[iz+0]+ g0[ix+1]*g0[iy+1]*g1[iz+1]+ g0[ix+2]*g0[iy+2]*g1[iz+2];
break;
case 4:
s[0] = + g1[ix+0]*g0[iy+0]*g0[iz+0]+ g1[ix+1]*g0[iy+1]*g0[iz+1]+ g1[ix+2]*g0[iy+2]*g0[iz+2]+ g1[ix+3]*g0[iy+3]*g0[iz+3];
s[1] = + g0[ix+0]*g1[iy+0]*g0[iz+0]+ g0[ix+1]*g1[iy+1]*g0[iz+1]+ g0[ix+2]*g1[iy+2]*g0[iz+2]+ g0[ix+3]*g1[iy+3]*g0[iz+3];
s[2] = + g0[ix+0]*g0[iy+0]*g1[iz+0]+ g0[ix+1]*g0[iy+1]*g1[iz+1]+ g0[ix+2]*g0[iy+2]*g1[iz+2]+ g0[ix+3]*g0[iy+3]*g1[iz+3];
break;
default:
for (i = 0; i < 3; i++) { s[i] = 0; }
for (i = 0; i < nrys_roots; i++) {
s[0] += g1[ix+i] * g0[iy+i] * g0[iz+i];
s[1] += g0[ix+i] * g1[iy+i] * g0[iz+i];
s[2] += g0[ix+i] * g0[iy+i] * g1[iz+i];
} break;}
if (gout_empty) {
gout[n*1+0] = + s[2];
} else {
gout[n*1+0] += + s[2];
}}}
void int2c2e_test_z_optimizer(CINTOpt **opt, FINT *atm, FINT natm, FINT *bas, FINT nbas, double *env) {
FINT ng[] = {0, 1, 0, 0, 1, 1, 1, 1};
CINTall_2c2e_optimizer(opt, ng, atm, natm, bas, nbas, env);
}
CACHE_SIZE_T int2c2e_test_z_cart(double *out, FINT *dims, FINT *shls,
FINT *atm, FINT natm, FINT *bas, FINT nbas, double *env, CINTOpt *opt, double *cache) {
FINT ng[] = {0, 1, 0, 0, 1, 1, 1, 1};
CINTEnvVars envs;
CINTinit_int2c2e_EnvVars(&envs, ng, shls, atm, natm, bas, nbas, env);
envs.f_gout = &CINTgout2e_int2c2e_test_z;
envs.common_factor *= 1.0;
return CINT2c2e_drv(out, dims, &envs, opt, cache, &c2s_cart_1e);
} // int2c2e_test_z_cart
CACHE_SIZE_T int2c2e_test_z_sph(double *out, FINT *dims, FINT *shls,
FINT *atm, FINT natm, FINT *bas, FINT nbas, double *env, CINTOpt *opt, double *cache) {
FINT ng[] = {0, 1, 0, 0, 1, 1, 1, 1};
CINTEnvVars envs;
CINTinit_int2c2e_EnvVars(&envs, ng, shls, atm, natm, bas, nbas, env);
envs.f_gout = &CINTgout2e_int2c2e_test_z;
envs.common_factor *= 1.0;
return CINT2c2e_drv(out, dims, &envs, opt, cache, &c2s_sph_1e);
} // int2c2e_test_z_sph
CACHE_SIZE_T int2c2e_test_z_spinor(double complex *out, FINT *dims, FINT *shls,
FINT *atm, FINT natm, FINT *bas, FINT nbas, double *env, CINTOpt *opt, double *cache) {
fprintf(stderr, "&c2s_sf_1e_spinor not implementedn");
return 0;
}
ALL_CINT(int2c2e_test_z)
ALL_CINT_FORTRAN_(int2c2e_test_z)
