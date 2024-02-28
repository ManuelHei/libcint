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
/* <X0 i|OVLP |j> */
void CINTgout1e_int2c2e_test_x(double *gout, double *g, FINT *idx, CINTEnvVars *envs, FINT gout_empty) {
FINT nf = envs->nf;
FINT ix, iy, iz, n;
double *g0 = g;
double *g1 = g0 + envs->g_size * 3;
double s[3];
G1E_R0I(g1, g0, envs->i_l+0, envs->j_l, 0);
for (n = 0; n < nf; n++) {
ix = idx[0+n*3];
iy = idx[1+n*3];
iz = idx[2+n*3];
s[0] = + g1[ix+0]*g0[iy+0]*g0[iz+0];
s[1] = + g0[ix+0]*g1[iy+0]*g0[iz+0];
s[2] = + g0[ix+0]*g0[iy+0]*g1[iz+0];
if (gout_empty) {
gout[n*1+0] = + s[0];
} else {
gout[n*1+0] += + s[0];
}}}
void int2c2e_test_x_optimizer(CINTOpt **opt, FINT *atm, FINT natm, FINT *bas, FINT nbas, double *env) {
FINT ng[] = {1, 0, 0, 0, 1, 1, 1, 1};
CINTall_1e_optimizer(opt, ng, atm, natm, bas, nbas, env);
}
CACHE_SIZE_T int2c2e_test_x_cart(double *out, FINT *dims, FINT *shls,
FINT *atm, FINT natm, FINT *bas, FINT nbas, double *env, CINTOpt *opt, double *cache) {
FINT ng[] = {1, 0, 0, 0, 1, 1, 1, 1};
CINTEnvVars envs;
CINTinit_int1e_EnvVars(&envs, ng, shls, atm, natm, bas, nbas, env);
envs.f_gout = &CINTgout1e_int2c2e_test_x;
envs.common_factor *= 1.0;
return CINT1e_drv(out, dims, &envs, cache, &c2s_cart_1e, 0);
} // int2c2e_test_x_cart
CACHE_SIZE_T int2c2e_test_x_sph(double *out, FINT *dims, FINT *shls,
FINT *atm, FINT natm, FINT *bas, FINT nbas, double *env, CINTOpt *opt, double *cache) {
FINT ng[] = {1, 0, 0, 0, 1, 1, 1, 1};
CINTEnvVars envs;
CINTinit_int1e_EnvVars(&envs, ng, shls, atm, natm, bas, nbas, env);
envs.f_gout = &CINTgout1e_int2c2e_test_x;
envs.common_factor *= 1.0;
return CINT1e_drv(out, dims, &envs, cache, &c2s_sph_1e, 0);
} // int2c2e_test_x_sph
CACHE_SIZE_T int2c2e_test_x_spinor(double complex *out, FINT *dims, FINT *shls,
FINT *atm, FINT natm, FINT *bas, FINT nbas, double *env, CINTOpt *opt, double *cache) {
FINT ng[] = {1, 0, 0, 0, 1, 1, 1, 1};
CINTEnvVars envs;
CINTinit_int1e_EnvVars(&envs, ng, shls, atm, natm, bas, nbas, env);
envs.f_gout = &CINTgout1e_int2c2e_test_x;
envs.common_factor *= 1.0;
return CINT1e_spinor_drv(out, dims, &envs, cache, &c2s_sf_1e, 0);
} // int2c2e_test_x_spinor
ALL_CINT1E(int2c2e_test_x)
ALL_CINT1E_FORTRAN_(int2c2e_test_x)
/* <Y0 i|OVLP |j> */
void CINTgout1e_int2c2e_test_y(double *gout, double *g, FINT *idx, CINTEnvVars *envs, FINT gout_empty) {
FINT nf = envs->nf;
FINT ix, iy, iz, n;
double *g0 = g;
double *g1 = g0 + envs->g_size * 3;
double s[3];
G1E_R0I(g1, g0, envs->i_l+0, envs->j_l, 0);
for (n = 0; n < nf; n++) {
ix = idx[0+n*3];
iy = idx[1+n*3];
iz = idx[2+n*3];
s[0] = + g1[ix+0]*g0[iy+0]*g0[iz+0];
s[1] = + g0[ix+0]*g1[iy+0]*g0[iz+0];
s[2] = + g0[ix+0]*g0[iy+0]*g1[iz+0];
if (gout_empty) {
gout[n*1+0] = + s[1];
} else {
gout[n*1+0] += + s[1];
}}}
void int2c2e_test_y_optimizer(CINTOpt **opt, FINT *atm, FINT natm, FINT *bas, FINT nbas, double *env) {
FINT ng[] = {1, 0, 0, 0, 1, 1, 1, 1};
CINTall_1e_optimizer(opt, ng, atm, natm, bas, nbas, env);
}
CACHE_SIZE_T int2c2e_test_y_cart(double *out, FINT *dims, FINT *shls,
FINT *atm, FINT natm, FINT *bas, FINT nbas, double *env, CINTOpt *opt, double *cache) {
FINT ng[] = {1, 0, 0, 0, 1, 1, 1, 1};
CINTEnvVars envs;
CINTinit_int1e_EnvVars(&envs, ng, shls, atm, natm, bas, nbas, env);
envs.f_gout = &CINTgout1e_int2c2e_test_y;
envs.common_factor *= 1.0;
return CINT1e_drv(out, dims, &envs, cache, &c2s_cart_1e, 0);
} // int2c2e_test_y_cart
CACHE_SIZE_T int2c2e_test_y_sph(double *out, FINT *dims, FINT *shls,
FINT *atm, FINT natm, FINT *bas, FINT nbas, double *env, CINTOpt *opt, double *cache) {
FINT ng[] = {1, 0, 0, 0, 1, 1, 1, 1};
CINTEnvVars envs;
CINTinit_int1e_EnvVars(&envs, ng, shls, atm, natm, bas, nbas, env);
envs.f_gout = &CINTgout1e_int2c2e_test_y;
envs.common_factor *= 1.0;
return CINT1e_drv(out, dims, &envs, cache, &c2s_sph_1e, 0);
} // int2c2e_test_y_sph
CACHE_SIZE_T int2c2e_test_y_spinor(double complex *out, FINT *dims, FINT *shls,
FINT *atm, FINT natm, FINT *bas, FINT nbas, double *env, CINTOpt *opt, double *cache) {
FINT ng[] = {1, 0, 0, 0, 1, 1, 1, 1};
CINTEnvVars envs;
CINTinit_int1e_EnvVars(&envs, ng, shls, atm, natm, bas, nbas, env);
envs.f_gout = &CINTgout1e_int2c2e_test_y;
envs.common_factor *= 1.0;
return CINT1e_spinor_drv(out, dims, &envs, cache, &c2s_sf_1e, 0);
} // int2c2e_test_y_spinor
ALL_CINT1E(int2c2e_test_y)
ALL_CINT1E_FORTRAN_(int2c2e_test_y)
/* <Z0 i|OVLP |j> */
void CINTgout1e_int2c2e_test_z(double *gout, double *g, FINT *idx, CINTEnvVars *envs, FINT gout_empty) {
FINT nf = envs->nf;
FINT ix, iy, iz, n;
double *g0 = g;
double *g1 = g0 + envs->g_size * 3;
double s[3];
G1E_R0I(g1, g0, envs->i_l+0, envs->j_l, 0);
for (n = 0; n < nf; n++) {
ix = idx[0+n*3];
iy = idx[1+n*3];
iz = idx[2+n*3];
s[0] = + g1[ix+0]*g0[iy+0]*g0[iz+0];
s[1] = + g0[ix+0]*g1[iy+0]*g0[iz+0];
s[2] = + g0[ix+0]*g0[iy+0]*g1[iz+0];
if (gout_empty) {
gout[n*1+0] = + s[2];
} else {
gout[n*1+0] += + s[2];
}}}
void int2c2e_test_z_optimizer(CINTOpt **opt, FINT *atm, FINT natm, FINT *bas, FINT nbas, double *env) {
FINT ng[] = {1, 0, 0, 0, 1, 1, 1, 1};
CINTall_1e_optimizer(opt, ng, atm, natm, bas, nbas, env);
}
CACHE_SIZE_T int2c2e_test_z_cart(double *out, FINT *dims, FINT *shls,
FINT *atm, FINT natm, FINT *bas, FINT nbas, double *env, CINTOpt *opt, double *cache) {
FINT ng[] = {1, 0, 0, 0, 1, 1, 1, 1};
CINTEnvVars envs;
CINTinit_int1e_EnvVars(&envs, ng, shls, atm, natm, bas, nbas, env);
envs.f_gout = &CINTgout1e_int2c2e_test_z;
envs.common_factor *= 1.0;
return CINT1e_drv(out, dims, &envs, cache, &c2s_cart_1e, 0);
} // int2c2e_test_z_cart
CACHE_SIZE_T int2c2e_test_z_sph(double *out, FINT *dims, FINT *shls,
FINT *atm, FINT natm, FINT *bas, FINT nbas, double *env, CINTOpt *opt, double *cache) {
FINT ng[] = {1, 0, 0, 0, 1, 1, 1, 1};
CINTEnvVars envs;
CINTinit_int1e_EnvVars(&envs, ng, shls, atm, natm, bas, nbas, env);
envs.f_gout = &CINTgout1e_int2c2e_test_z;
envs.common_factor *= 1.0;
return CINT1e_drv(out, dims, &envs, cache, &c2s_sph_1e, 0);
} // int2c2e_test_z_sph
CACHE_SIZE_T int2c2e_test_z_spinor(double complex *out, FINT *dims, FINT *shls,
FINT *atm, FINT natm, FINT *bas, FINT nbas, double *env, CINTOpt *opt, double *cache) {
FINT ng[] = {1, 0, 0, 0, 1, 1, 1, 1};
CINTEnvVars envs;
CINTinit_int1e_EnvVars(&envs, ng, shls, atm, natm, bas, nbas, env);
envs.f_gout = &CINTgout1e_int2c2e_test_z;
envs.common_factor *= 1.0;
return CINT1e_spinor_drv(out, dims, &envs, cache, &c2s_sf_1e, 0);
} // int2c2e_test_z_spinor
ALL_CINT1E(int2c2e_test_z)
ALL_CINT1E_FORTRAN_(int2c2e_test_z)
