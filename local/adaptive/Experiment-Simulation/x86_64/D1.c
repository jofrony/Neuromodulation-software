/* Created by Language version: 7.7.0 */
/* VECTORIZED */
#define NRN_VECTORIZED 1
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "scoplib_ansi.h"
#undef PI
#define nil 0
#include "md1redef.h"
#include "section.h"
#include "nrniv_mf.h"
#include "md2redef.h"
 
#if METHOD3
extern int _method3;
#endif

#if !NRNGPU
#undef exp
#define exp hoc_Exp
extern double hoc_Exp(double);
#endif
 
#define nrn_init _nrn_init__D1
#define _nrn_initial _nrn_initial__D1
#define nrn_cur _nrn_cur__D1
#define _nrn_current _nrn_current__D1
#define nrn_jacob _nrn_jacob__D1
#define nrn_state _nrn_state__D1
#define _net_receive _net_receive__D1 
#define rates rates__D1 
#define states states__D1 
 
#define _threadargscomma_ _p, _ppvar, _thread, _nt,
#define _threadargsprotocomma_ double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt,
#define _threadargs_ _p, _ppvar, _thread, _nt
#define _threadargsproto_ double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt
 	/*SUPPRESS 761*/
	/*SUPPRESS 762*/
	/*SUPPRESS 763*/
	/*SUPPRESS 765*/
	 extern double *getarg();
 /* Thread safe. No static _p or _ppvar. */
 
#define t _nt->_t
#define dt _nt->_dt
#define kGaolfGTPase _p[0]
#define kfPKA_2cAMP _p[1]
#define krPKA_2cAMP _p[2]
#define krPKAc_PKAr _p[3]
#define kfPKAc_PKAr _p[4]
#define kfPKA2cAMP_2cAMP _p[5]
#define krPKA2cAMP_2cAMP _p[6]
#define kactGolf _p[7]
#define kcatPDE4_cAMP _p[8]
#define kfPDE4_cAMP _p[9]
#define krPDE4_cAMP _p[10]
#define krPDE10_cAMP _p[11]
#define kcatPDE10c_cAMP _p[12]
#define kfPDE10_cAMP _p[13]
#define kfcAMP_PDE10 _p[14]
#define krcAMP_PDE10 _p[15]
#define kcatcAMP_PDE10 _p[16]
#define kcatAC5GaolfGTP_ATP _p[17]
#define kicatAC5GaolfGTP_ATP _p[18]
#define kcatAC5_ATP _p[19]
#define kicatAC5_ATP _p[20]
#define kfAC5_ATP _p[21]
#define kGolfback _p[22]
#define kfAC5GaolfGTP_ATP _p[23]
#define kfD1R_Golf _p[24]
#define krD1R_Golf _p[25]
#define kfD1RDA_Golf _p[26]
#define krD1RDA_Golf _p[27]
#define krAC5X_ATP _p[28]
#define kfAC5XGaolfGTP _p[29]
#define krAC5XGaolfGTP _p[30]
#define krgso _p[31]
#define kfPDE10c_cAMP _p[32]
#define krPDE10c_cAMP _p[33]
#define kfD1R_DA _p[34]
#define kfD1RGolf_DA _p[35]
#define krD1R_DA _p[36]
#define krD1RGolf_DA _p[37]
#define kfPP1_Target1p _p[38]
#define krPP1_Target1p _p[39]
#define kfPKAc_Target1 _p[40]
#define krPKAc_Target1 _p[41]
#define kcatPP1_Target1p _p[42]
#define kcatPKAc_Target1 _p[43]
#define tscale _p[44]
#define Spine _p[45]
#define init_GaolfGDP _p[46]
#define init_Gbgolf _p[47]
#define init_GaolfGTP _p[48]
#define init_D1RDAGolf _p[49]
#define init_Golf _p[50]
#define init_D1RGolf _p[51]
#define init_D1RDA _p[52]
#define init_D1R _p[53]
#define init_cAMP _p[54]
#define init_AC5 _p[55]
#define init_AC5GaolfGTP _p[56]
#define init_PDE4 _p[57]
#define init_PKA _p[58]
#define init_PKAcAMP2 _p[59]
#define init_PKAcAMP4 _p[60]
#define init_PKAreg _p[61]
#define init_PKAc _p[62]
#define init_PP1 _p[63]
#define init_DA _p[64]
#define init_AMP _p[65]
#define init_PDE4_cAMP _p[66]
#define init_PDE10c _p[67]
#define init_PDE10 _p[68]
#define init_PDE10_cAMP _p[69]
#define init_PDE10c_cAMP _p[70]
#define init_ATP _p[71]
#define init_AC5GaolfGTP_ATP _p[72]
#define init_AC5_ATP _p[73]
#define init_PP1_Target1p _p[74]
#define init_Target1p _p[75]
#define init_PKAc_Target1 _p[76]
#define init_Target1 _p[77]
#define r_r_1 _p[78]
#define r_r_2 _p[79]
#define r_r_3 _p[80]
#define r_r_4 _p[81]
#define r_r_5 _p[82]
#define r_r_6 _p[83]
#define r_r_7 _p[84]
#define r_r_8 _p[85]
#define r_r_9 _p[86]
#define r_r_10 _p[87]
#define r_r_11 _p[88]
#define r_r_12 _p[89]
#define r_r_13 _p[90]
#define r_r_14 _p[91]
#define r_r_15 _p[92]
#define r_ir_1 _p[93]
#define r_ir_2 _p[94]
#define r_ir_3 _p[95]
#define r_ir_4 _p[96]
#define r_ir_5 _p[97]
#define r_ir_6 _p[98]
#define r_ir_7 _p[99]
#define r_ir_8 _p[100]
#define r_ir_9 _p[101]
#define r_ir_10 _p[102]
#define r_ir_11 _p[103]
#define r_ir_12 _p[104]
#define r_r_17 _p[105]
#define r_r_16 _p[106]
#define r_ir_14 _p[107]
#define r_ir_15 _p[108]
#define GaolfGDP _p[109]
#define Gbgolf _p[110]
#define GaolfGTP _p[111]
#define D1RDAGolf _p[112]
#define Golf _p[113]
#define D1RGolf _p[114]
#define D1RDA _p[115]
#define D1R _p[116]
#define cAMP _p[117]
#define AC5 _p[118]
#define AC5GaolfGTP _p[119]
#define PDE4 _p[120]
#define PKA _p[121]
#define PKAcAMP2 _p[122]
#define PKAcAMP4 _p[123]
#define PKAreg _p[124]
#define PKAc _p[125]
#define PP1 _p[126]
#define DA _p[127]
#define AMP _p[128]
#define PDE4_cAMP _p[129]
#define PDE10c _p[130]
#define PDE10 _p[131]
#define PDE10_cAMP _p[132]
#define PDE10c_cAMP _p[133]
#define ATP _p[134]
#define AC5GaolfGTP_ATP _p[135]
#define AC5_ATP _p[136]
#define PP1_Target1p _p[137]
#define Target1p _p[138]
#define PKAc_Target1 _p[139]
#define Target1 _p[140]
#define rate_GaolfGDP _p[141]
#define rate_PKAreg _p[142]
#define rate_AC5_ATP _p[143]
#define rate_AC5GaolfGTP_ATP _p[144]
#define rate_PKAcAMP4 _p[145]
#define rate_AC5GaolfGTP _p[146]
#define rate_PP1 _p[147]
#define rate_Gbgolf _p[148]
#define rate_PDE10 _p[149]
#define rate_GaolfGTP _p[150]
#define rate_PDE10_cAMP _p[151]
#define rate_Target1p _p[152]
#define rate_PDE10c _p[153]
#define rate_cAMP _p[154]
#define rate_AC5 _p[155]
#define rate_PDE10c_cAMP _p[156]
#define rate_D1RDAGolf _p[157]
#define rate_D1RGolf _p[158]
#define rate_PKAc_Target1 _p[159]
#define rate_Target1 _p[160]
#define rate_D1R _p[161]
#define rate_D1RDA _p[162]
#define rate_PP1_Target1p _p[163]
#define rate_Golf _p[164]
#define rate_PKA _p[165]
#define rate_PKAc _p[166]
#define rate_PDE4 _p[167]
#define rate_PDE4_cAMP _p[168]
#define rate_PKAcAMP2 _p[169]
#define DGaolfGDP _p[170]
#define DGbgolf _p[171]
#define DGaolfGTP _p[172]
#define DD1RDAGolf _p[173]
#define DGolf _p[174]
#define DD1RGolf _p[175]
#define DD1RDA _p[176]
#define DD1R _p[177]
#define DcAMP _p[178]
#define DAC5 _p[179]
#define DAC5GaolfGTP _p[180]
#define DPDE4 _p[181]
#define DPKA _p[182]
#define DPKAcAMP2 _p[183]
#define DPKAcAMP4 _p[184]
#define DPKAreg _p[185]
#define DPKAc _p[186]
#define DPP1 _p[187]
#define DDA _p[188]
#define DAMP _p[189]
#define DPDE4_cAMP _p[190]
#define DPDE10c _p[191]
#define DPDE10 _p[192]
#define DPDE10_cAMP _p[193]
#define DPDE10c_cAMP _p[194]
#define DATP _p[195]
#define DAC5GaolfGTP_ATP _p[196]
#define DAC5_ATP _p[197]
#define DPP1_Target1p _p[198]
#define DTarget1p _p[199]
#define DPKAc_Target1 _p[200]
#define DTarget1 _p[201]
#define v _p[202]
#define _g _p[203]
#define _nd_area  *_ppvar[0]._pval
 
#if MAC
#if !defined(v)
#define v _mlhv
#endif
#if !defined(h)
#define h _mlhh
#endif
#endif
 
#if defined(__cplusplus)
extern "C" {
#endif
 static int hoc_nrnpointerindex =  -1;
 static Datum* _extcall_thread;
 static Prop* _extcall_prop;
 /* external NEURON variables */
 /* declaration of user functions */
 static double _hoc_rates();
 static int _mechtype;
extern void _nrn_cacheloop_reg(int, int);
extern void hoc_register_prop_size(int, int, int);
extern void hoc_register_limits(int, HocParmLimits*);
extern void hoc_register_units(int, HocParmUnits*);
extern void nrn_promote(Prop*, int, int);
extern Memb_func* memb_func;
 
#define NMODL_TEXT 1
#if NMODL_TEXT
static const char* nmodl_file_text;
static const char* nmodl_filename;
extern void hoc_reg_nmodl_text(int, const char*);
extern void hoc_reg_nmodl_filename(int, const char*);
#endif

 extern Prop* nrn_point_prop_;
 static int _pointtype;
 static void* _hoc_create_pnt(_ho) Object* _ho; { void* create_point_process();
 return create_point_process(_pointtype, _ho);
}
 static void _hoc_destroy_pnt();
 static double _hoc_loc_pnt(_vptr) void* _vptr; {double loc_point_process();
 return loc_point_process(_pointtype, _vptr);
}
 static double _hoc_has_loc(_vptr) void* _vptr; {double has_loc_point();
 return has_loc_point(_vptr);
}
 static double _hoc_get_loc_pnt(_vptr)void* _vptr; {
 double get_loc_point_process(); return (get_loc_point_process(_vptr));
}
 extern void _nrn_setdata_reg(int, void(*)(Prop*));
 static void _setdata(Prop* _prop) {
 _extcall_prop = _prop;
 }
 static void _hoc_setdata(void* _vptr) { Prop* _prop;
 _prop = ((Point_process*)_vptr)->_prop;
   _setdata(_prop);
 }
 /* connect user functions to hoc names */
 static VoidFunc hoc_intfunc[] = {
 0,0
};
 static Member_func _member_func[] = {
 "loc", _hoc_loc_pnt,
 "has_loc", _hoc_has_loc,
 "get_loc", _hoc_get_loc_pnt,
 "rates", _hoc_rates,
 0, 0
};
 /* declare global and static user variables */
 /* some parameters have upper and lower limits */
 static HocParmLimits _hoc_parm_limits[] = {
 0,0,0
};
 static HocParmUnits _hoc_parm_units[] = {
 "tscale", "kHz",
 0,0
};
 static double AC5_ATP0 = 0;
 static double AC5GaolfGTP_ATP0 = 0;
 static double ATP0 = 0;
 static double AMP0 = 0;
 static double AC5GaolfGTP0 = 0;
 static double AC50 = 0;
 static double DA0 = 0;
 static double D1R0 = 0;
 static double D1RDA0 = 0;
 static double D1RGolf0 = 0;
 static double D1RDAGolf0 = 0;
 static double Golf0 = 0;
 static double GaolfGTP0 = 0;
 static double Gbgolf0 = 0;
 static double GaolfGDP0 = 0;
 static double PKAc_Target10 = 0;
 static double PP1_Target1p0 = 0;
 static double PDE10c_cAMP0 = 0;
 static double PDE10_cAMP0 = 0;
 static double PDE100 = 0;
 static double PDE10c0 = 0;
 static double PDE4_cAMP0 = 0;
 static double PP10 = 0;
 static double PKAc0 = 0;
 static double PKAreg0 = 0;
 static double PKAcAMP40 = 0;
 static double PKAcAMP20 = 0;
 static double PKA0 = 0;
 static double PDE40 = 0;
 static double Target10 = 0;
 static double Target1p0 = 0;
 static double cAMP0 = 0;
 static double delta_t = 0.01;
 /* connect global user variables to hoc */
 static DoubScal hoc_scdoub[] = {
 0,0
};
 static DoubVec hoc_vdoub[] = {
 0,0,0
};
 static double _sav_indep;
 static void nrn_alloc(Prop*);
static void  nrn_init(_NrnThread*, _Memb_list*, int);
static void nrn_state(_NrnThread*, _Memb_list*, int);
 static void nrn_cur(_NrnThread*, _Memb_list*, int);
static void  nrn_jacob(_NrnThread*, _Memb_list*, int);
 static void _hoc_destroy_pnt(_vptr) void* _vptr; {
   destroy_point_process(_vptr);
}
 
static int _ode_count(int);
static void _ode_map(int, double**, double**, double*, Datum*, double*, int);
static void _ode_spec(_NrnThread*, _Memb_list*, int);
static void _ode_matsol(_NrnThread*, _Memb_list*, int);
 
#define _cvode_ieq _ppvar[2]._i
 static void _ode_matsol_instance1(_threadargsproto_);
 /* connect range variables in _p that hoc is supposed to know about */
 static const char *_mechanism[] = {
 "7.7.0",
"D1",
 "kGaolfGTPase",
 "kfPKA_2cAMP",
 "krPKA_2cAMP",
 "krPKAc_PKAr",
 "kfPKAc_PKAr",
 "kfPKA2cAMP_2cAMP",
 "krPKA2cAMP_2cAMP",
 "kactGolf",
 "kcatPDE4_cAMP",
 "kfPDE4_cAMP",
 "krPDE4_cAMP",
 "krPDE10_cAMP",
 "kcatPDE10c_cAMP",
 "kfPDE10_cAMP",
 "kfcAMP_PDE10",
 "krcAMP_PDE10",
 "kcatcAMP_PDE10",
 "kcatAC5GaolfGTP_ATP",
 "kicatAC5GaolfGTP_ATP",
 "kcatAC5_ATP",
 "kicatAC5_ATP",
 "kfAC5_ATP",
 "kGolfback",
 "kfAC5GaolfGTP_ATP",
 "kfD1R_Golf",
 "krD1R_Golf",
 "kfD1RDA_Golf",
 "krD1RDA_Golf",
 "krAC5X_ATP",
 "kfAC5XGaolfGTP",
 "krAC5XGaolfGTP",
 "krgso",
 "kfPDE10c_cAMP",
 "krPDE10c_cAMP",
 "kfD1R_DA",
 "kfD1RGolf_DA",
 "krD1R_DA",
 "krD1RGolf_DA",
 "kfPP1_Target1p",
 "krPP1_Target1p",
 "kfPKAc_Target1",
 "krPKAc_Target1",
 "kcatPP1_Target1p",
 "kcatPKAc_Target1",
 "tscale",
 "Spine",
 "init_GaolfGDP",
 "init_Gbgolf",
 "init_GaolfGTP",
 "init_D1RDAGolf",
 "init_Golf",
 "init_D1RGolf",
 "init_D1RDA",
 "init_D1R",
 "init_cAMP",
 "init_AC5",
 "init_AC5GaolfGTP",
 "init_PDE4",
 "init_PKA",
 "init_PKAcAMP2",
 "init_PKAcAMP4",
 "init_PKAreg",
 "init_PKAc",
 "init_PP1",
 "init_DA",
 "init_AMP",
 "init_PDE4_cAMP",
 "init_PDE10c",
 "init_PDE10",
 "init_PDE10_cAMP",
 "init_PDE10c_cAMP",
 "init_ATP",
 "init_AC5GaolfGTP_ATP",
 "init_AC5_ATP",
 "init_PP1_Target1p",
 "init_Target1p",
 "init_PKAc_Target1",
 "init_Target1",
 0,
 "r_r_1",
 "r_r_2",
 "r_r_3",
 "r_r_4",
 "r_r_5",
 "r_r_6",
 "r_r_7",
 "r_r_8",
 "r_r_9",
 "r_r_10",
 "r_r_11",
 "r_r_12",
 "r_r_13",
 "r_r_14",
 "r_r_15",
 "r_ir_1",
 "r_ir_2",
 "r_ir_3",
 "r_ir_4",
 "r_ir_5",
 "r_ir_6",
 "r_ir_7",
 "r_ir_8",
 "r_ir_9",
 "r_ir_10",
 "r_ir_11",
 "r_ir_12",
 "r_r_17",
 "r_r_16",
 "r_ir_14",
 "r_ir_15",
 0,
 "GaolfGDP",
 "Gbgolf",
 "GaolfGTP",
 "D1RDAGolf",
 "Golf",
 "D1RGolf",
 "D1RDA",
 "D1R",
 "cAMP",
 "AC5",
 "AC5GaolfGTP",
 "PDE4",
 "PKA",
 "PKAcAMP2",
 "PKAcAMP4",
 "PKAreg",
 "PKAc",
 "PP1",
 "DA",
 "AMP",
 "PDE4_cAMP",
 "PDE10c",
 "PDE10",
 "PDE10_cAMP",
 "PDE10c_cAMP",
 "ATP",
 "AC5GaolfGTP_ATP",
 "AC5_ATP",
 "PP1_Target1p",
 "Target1p",
 "PKAc_Target1",
 "Target1",
 0,
 0};
 
extern Prop* need_memb(Symbol*);

static void nrn_alloc(Prop* _prop) {
	Prop *prop_ion;
	double *_p; Datum *_ppvar;
  if (nrn_point_prop_) {
	_prop->_alloc_seq = nrn_point_prop_->_alloc_seq;
	_p = nrn_point_prop_->param;
	_ppvar = nrn_point_prop_->dparam;
 }else{
 	_p = nrn_prop_data_alloc(_mechtype, 204, _prop);
 	/*initialize range parameters*/
 	kGaolfGTPase = 30;
 	kfPKA_2cAMP = 0.026;
 	krPKA_2cAMP = 350;
 	krPKAc_PKAr = 50;
 	kfPKAc_PKAr = 0.03;
 	kfPKA2cAMP_2cAMP = 0.0346;
 	krPKA2cAMP_2cAMP = 50;
 	kactGolf = 15;
 	kcatPDE4_cAMP = 2.5;
 	kfPDE4_cAMP = 0.03;
 	krPDE4_cAMP = 1;
 	krPDE10_cAMP = 1;
 	kcatPDE10c_cAMP = 10;
 	kfPDE10_cAMP = 1e-06;
 	kfcAMP_PDE10 = 0.1;
 	krcAMP_PDE10 = 2;
 	kcatcAMP_PDE10 = 3;
 	kcatAC5GaolfGTP_ATP = 50;
 	kicatAC5GaolfGTP_ATP = 2.55;
 	kcatAC5_ATP = 1;
 	kicatAC5_ATP = 0.002;
 	kfAC5_ATP = 0.0001;
 	kGolfback = 100;
 	kfAC5GaolfGTP_ATP = 0.00255;
 	kfD1R_Golf = 0.06;
 	krD1R_Golf = 250;
 	kfD1RDA_Golf = 0.06;
 	krD1RDA_Golf = 250;
 	krAC5X_ATP = 1;
 	kfAC5XGaolfGTP = 10;
 	krAC5XGaolfGTP = 1;
 	krgso = 1;
 	kfPDE10c_cAMP = 0.1;
 	krPDE10c_cAMP = 2;
 	kfD1R_DA = 0.05;
 	kfD1RGolf_DA = 0.05;
 	krD1R_DA = 250;
 	krD1RGolf_DA = 250;
 	kfPP1_Target1p = 0.001;
 	krPP1_Target1p = 10;
 	kfPKAc_Target1 = 0.08;
 	krPKAc_Target1 = 10;
 	kcatPP1_Target1p = 5;
 	kcatPKAc_Target1 = 10;
 	tscale = 0.001;
 	Spine = 1e-15;
 	init_GaolfGDP = 0.0100831;
 	init_Gbgolf = 29.8851;
 	init_GaolfGTP = 0.00891348;
 	init_D1RDAGolf = 2.0089;
 	init_Golf = 1453.07;
 	init_D1RGolf = 515.033;
 	init_D1RDA = 5.95922;
 	init_D1R = 1477;
 	init_cAMP = 38.186;
 	init_AC5 = 2.66945;
 	init_AC5GaolfGTP = 0.11809;
 	init_PDE4 = 1506.81;
 	init_PKA = 1157.14;
 	init_PKAcAMP2 = 3.28243;
 	init_PKAcAMP4 = 0.0867374;
 	init_PKAreg = 39.4895;
 	init_PKAc = 3.66078;
 	init_PP1 = 2927.34;
 	init_DA = 20;
 	init_AMP = 0;
 	init_PDE4_cAMP = 493.192;
 	init_PDE10c = 0.578101;
 	init_PDE10 = 396.456;
 	init_PDE10_cAMP = 302.782;
 	init_PDE10c_cAMP = 0.183962;
 	init_ATP = 5e+06;
 	init_AC5GaolfGTP_ATP = 29.748;
 	init_AC5_ATP = 667.464;
 	init_PP1_Target1p = 73.6574;
 	init_Target1p = 377.428;
 	init_PKAc_Target1 = 36.8287;
 	init_Target1 = 2515.09;
  }
 	_prop->param = _p;
 	_prop->param_size = 204;
  if (!nrn_point_prop_) {
 	_ppvar = nrn_prop_datum_alloc(_mechtype, 3, _prop);
  }
 	_prop->dparam = _ppvar;
 	/*connect ionic variables to this model*/
 
}
 static void _initlists();
  /* some states have an absolute tolerance */
 static Symbol** _atollist;
 static HocStateTolerance _hoc_state_tol[] = {
 0,0
};
 extern Symbol* hoc_lookup(const char*);
extern void _nrn_thread_reg(int, int, void(*)(Datum*));
extern void _nrn_thread_table_reg(int, void(*)(double*, Datum*, Datum*, _NrnThread*, int));
extern void hoc_register_tolerance(int, HocStateTolerance*, Symbol***);
extern void _cvode_abstol( Symbol**, double*, int);

 void _D1_reg() {
	int _vectorized = 1;
  _initlists();
 	_pointtype = point_register_mech(_mechanism,
	 nrn_alloc,nrn_cur, nrn_jacob, nrn_state, nrn_init,
	 hoc_nrnpointerindex, 1,
	 _hoc_create_pnt, _hoc_destroy_pnt, _member_func);
 _mechtype = nrn_get_mechtype(_mechanism[1]);
     _nrn_setdata_reg(_mechtype, _setdata);
 #if NMODL_TEXT
  hoc_reg_nmodl_text(_mechtype, nmodl_file_text);
  hoc_reg_nmodl_filename(_mechtype, nmodl_filename);
#endif
  hoc_register_prop_size(_mechtype, 204, 3);
  hoc_register_dparam_semantics(_mechtype, 0, "area");
  hoc_register_dparam_semantics(_mechtype, 1, "pntproc");
  hoc_register_dparam_semantics(_mechtype, 2, "cvodeieq");
 	hoc_register_cvode(_mechtype, _ode_count, _ode_map, _ode_spec, _ode_matsol);
 	hoc_register_tolerance(_mechtype, _hoc_state_tol, &_atollist);
 	hoc_register_var(hoc_scdoub, hoc_vdoub, hoc_intfunc);
 	ivoc_help("help ?1 D1 /home/jofrony/Documents/Repositories/BasalGangliaExperiments/Neuromodulation-software/local/adaptive/Experiment-Simulation/x86_64/D1.mod\n");
 hoc_register_limits(_mechtype, _hoc_parm_limits);
 hoc_register_units(_mechtype, _hoc_parm_units);
 }
static int _reset;
static char *modelname = "Mod file for component: Component(id=D1_reduced_cascade2_0 type=D1_reduced_cascade2)";

static int error;
static int _ninits = 0;
static int _match_recurse=1;
static void _modl_cleanup(){ _match_recurse=1;}
static int rates(_threadargsproto_);
 
static int _ode_spec1(_threadargsproto_);
/*static int _ode_matsol1(_threadargsproto_);*/
 static int _slist1[29], _dlist1[29];
 static int states(_threadargsproto_);
 
/*CVODE*/
 static int _ode_spec1 (double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt) {int _reset = 0; {
   rates ( _threadargs_ ) ;
   DGaolfGDP = rate_GaolfGDP ;
   DPKAreg = rate_PKAreg ;
   DAC5_ATP = rate_AC5_ATP ;
   DAC5GaolfGTP_ATP = rate_AC5GaolfGTP_ATP ;
   DPKAcAMP4 = rate_PKAcAMP4 ;
   DAC5GaolfGTP = rate_AC5GaolfGTP ;
   DPP1 = rate_PP1 ;
   DGbgolf = rate_Gbgolf ;
   DPDE10 = rate_PDE10 ;
   DGaolfGTP = rate_GaolfGTP ;
   DPDE10_cAMP = rate_PDE10_cAMP ;
   DTarget1p = rate_Target1p ;
   DPDE10c = rate_PDE10c ;
   DcAMP = rate_cAMP ;
   DAC5 = rate_AC5 ;
   DPDE10c_cAMP = rate_PDE10c_cAMP ;
   DD1RDAGolf = rate_D1RDAGolf ;
   DD1RGolf = rate_D1RGolf ;
   DPKAc_Target1 = rate_PKAc_Target1 ;
   DTarget1 = rate_Target1 ;
   DD1R = rate_D1R ;
   DD1RDA = rate_D1RDA ;
   DPP1_Target1p = rate_PP1_Target1p ;
   DGolf = rate_Golf ;
   DPKA = rate_PKA ;
   DPKAc = rate_PKAc ;
   DPDE4 = rate_PDE4 ;
   DPDE4_cAMP = rate_PDE4_cAMP ;
   DPKAcAMP2 = rate_PKAcAMP2 ;
   }
 return _reset;
}
 static int _ode_matsol1 (double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt) {
 rates ( _threadargs_ ) ;
 DGaolfGDP = DGaolfGDP  / (1. - dt*( 0.0 )) ;
 DPKAreg = DPKAreg  / (1. - dt*( 0.0 )) ;
 DAC5_ATP = DAC5_ATP  / (1. - dt*( 0.0 )) ;
 DAC5GaolfGTP_ATP = DAC5GaolfGTP_ATP  / (1. - dt*( 0.0 )) ;
 DPKAcAMP4 = DPKAcAMP4  / (1. - dt*( 0.0 )) ;
 DAC5GaolfGTP = DAC5GaolfGTP  / (1. - dt*( 0.0 )) ;
 DPP1 = DPP1  / (1. - dt*( 0.0 )) ;
 DGbgolf = DGbgolf  / (1. - dt*( 0.0 )) ;
 DPDE10 = DPDE10  / (1. - dt*( 0.0 )) ;
 DGaolfGTP = DGaolfGTP  / (1. - dt*( 0.0 )) ;
 DPDE10_cAMP = DPDE10_cAMP  / (1. - dt*( 0.0 )) ;
 DTarget1p = DTarget1p  / (1. - dt*( 0.0 )) ;
 DPDE10c = DPDE10c  / (1. - dt*( 0.0 )) ;
 DcAMP = DcAMP  / (1. - dt*( 0.0 )) ;
 DAC5 = DAC5  / (1. - dt*( 0.0 )) ;
 DPDE10c_cAMP = DPDE10c_cAMP  / (1. - dt*( 0.0 )) ;
 DD1RDAGolf = DD1RDAGolf  / (1. - dt*( 0.0 )) ;
 DD1RGolf = DD1RGolf  / (1. - dt*( 0.0 )) ;
 DPKAc_Target1 = DPKAc_Target1  / (1. - dt*( 0.0 )) ;
 DTarget1 = DTarget1  / (1. - dt*( 0.0 )) ;
 DD1R = DD1R  / (1. - dt*( 0.0 )) ;
 DD1RDA = DD1RDA  / (1. - dt*( 0.0 )) ;
 DPP1_Target1p = DPP1_Target1p  / (1. - dt*( 0.0 )) ;
 DGolf = DGolf  / (1. - dt*( 0.0 )) ;
 DPKA = DPKA  / (1. - dt*( 0.0 )) ;
 DPKAc = DPKAc  / (1. - dt*( 0.0 )) ;
 DPDE4 = DPDE4  / (1. - dt*( 0.0 )) ;
 DPDE4_cAMP = DPDE4_cAMP  / (1. - dt*( 0.0 )) ;
 DPKAcAMP2 = DPKAcAMP2  / (1. - dt*( 0.0 )) ;
  return 0;
}
 /*END CVODE*/
 static int states (double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt) { {
   rates ( _threadargs_ ) ;
    GaolfGDP = GaolfGDP - dt*(- ( rate_GaolfGDP ) ) ;
    PKAreg = PKAreg - dt*(- ( rate_PKAreg ) ) ;
    AC5_ATP = AC5_ATP - dt*(- ( rate_AC5_ATP ) ) ;
    AC5GaolfGTP_ATP = AC5GaolfGTP_ATP - dt*(- ( rate_AC5GaolfGTP_ATP ) ) ;
    PKAcAMP4 = PKAcAMP4 - dt*(- ( rate_PKAcAMP4 ) ) ;
    AC5GaolfGTP = AC5GaolfGTP - dt*(- ( rate_AC5GaolfGTP ) ) ;
    PP1 = PP1 - dt*(- ( rate_PP1 ) ) ;
    Gbgolf = Gbgolf - dt*(- ( rate_Gbgolf ) ) ;
    PDE10 = PDE10 - dt*(- ( rate_PDE10 ) ) ;
    GaolfGTP = GaolfGTP - dt*(- ( rate_GaolfGTP ) ) ;
    PDE10_cAMP = PDE10_cAMP - dt*(- ( rate_PDE10_cAMP ) ) ;
    Target1p = Target1p - dt*(- ( rate_Target1p ) ) ;
    PDE10c = PDE10c - dt*(- ( rate_PDE10c ) ) ;
    cAMP = cAMP - dt*(- ( rate_cAMP ) ) ;
    AC5 = AC5 - dt*(- ( rate_AC5 ) ) ;
    PDE10c_cAMP = PDE10c_cAMP - dt*(- ( rate_PDE10c_cAMP ) ) ;
    D1RDAGolf = D1RDAGolf - dt*(- ( rate_D1RDAGolf ) ) ;
    D1RGolf = D1RGolf - dt*(- ( rate_D1RGolf ) ) ;
    PKAc_Target1 = PKAc_Target1 - dt*(- ( rate_PKAc_Target1 ) ) ;
    Target1 = Target1 - dt*(- ( rate_Target1 ) ) ;
    D1R = D1R - dt*(- ( rate_D1R ) ) ;
    D1RDA = D1RDA - dt*(- ( rate_D1RDA ) ) ;
    PP1_Target1p = PP1_Target1p - dt*(- ( rate_PP1_Target1p ) ) ;
    Golf = Golf - dt*(- ( rate_Golf ) ) ;
    PKA = PKA - dt*(- ( rate_PKA ) ) ;
    PKAc = PKAc - dt*(- ( rate_PKAc ) ) ;
    PDE4 = PDE4 - dt*(- ( rate_PDE4 ) ) ;
    PDE4_cAMP = PDE4_cAMP - dt*(- ( rate_PDE4_cAMP ) ) ;
    PKAcAMP2 = PKAcAMP2 - dt*(- ( rate_PKAcAMP2 ) ) ;
   }
  return 0;
}
 
static int  rates ( _threadargsproto_ ) {
   r_r_1 = ( Spine * ( ( ( kfD1RGolf_DA * D1RGolf ) * DA ) - ( krD1RGolf_DA * D1RDAGolf ) ) ) ;
   r_r_2 = ( Spine * ( ( ( kfD1R_DA * D1R ) * DA ) - ( krD1R_DA * D1RDA ) ) ) ;
   r_r_3 = ( Spine * ( ( ( kfD1R_Golf * D1R ) * Golf ) - ( krD1R_Golf * D1RGolf ) ) ) ;
   r_r_4 = ( Spine * ( ( ( kfD1RDA_Golf * Golf ) * D1RDA ) - ( krD1RDA_Golf * D1RDAGolf ) ) ) ;
   r_r_5 = ( Spine * ( ( ( kfAC5XGaolfGTP * AC5 ) * GaolfGTP ) - ( krAC5XGaolfGTP * AC5GaolfGTP ) ) ) ;
   r_r_6 = ( Spine * ( ( ( kfAC5GaolfGTP_ATP * AC5GaolfGTP ) * ATP ) - ( krAC5X_ATP * AC5GaolfGTP_ATP ) ) ) ;
   r_r_7 = ( Spine * ( ( ( kfAC5_ATP * AC5 ) * ATP ) - ( krAC5X_ATP * AC5_ATP ) ) ) ;
   r_r_8 = ( Spine * ( ( ( kfAC5XGaolfGTP * GaolfGTP ) * AC5_ATP ) - ( krAC5XGaolfGTP * AC5GaolfGTP_ATP ) ) ) ;
   r_r_9 = ( Spine * ( ( ( kfPDE4_cAMP * cAMP ) * PDE4 ) - ( krPDE4_cAMP * PDE4_cAMP ) ) ) ;
   r_r_10 = ( Spine * ( ( ( kfPDE10_cAMP * PDE10 ) * ( pow( cAMP , 2.0 ) ) ) - ( krPDE10_cAMP * PDE10c ) ) ) ;
   r_r_11 = ( Spine * ( ( ( kfcAMP_PDE10 * cAMP ) * PDE10 ) - ( krcAMP_PDE10 * PDE10_cAMP ) ) ) ;
   r_r_12 = ( Spine * ( ( ( kfPDE10c_cAMP * cAMP ) * PDE10c ) - ( krPDE10c_cAMP * PDE10c_cAMP ) ) ) ;
   r_r_13 = ( Spine * ( ( ( kfPKA_2cAMP * cAMP ) * PKA ) - ( krPKA_2cAMP * PKAcAMP2 ) ) ) ;
   r_r_14 = ( Spine * ( ( ( kfPKA2cAMP_2cAMP * cAMP ) * PKAcAMP2 ) - ( krPKA2cAMP_2cAMP * PKAcAMP4 ) ) ) ;
   r_r_15 = ( Spine * ( ( krPKAc_PKAr * PKAcAMP4 ) - ( ( kfPKAc_PKAr * PKAc ) * PKAreg ) ) ) ;
   r_ir_1 = ( ( Spine * kactGolf ) * D1RDAGolf ) ;
   r_ir_2 = ( ( Spine * kGaolfGTPase ) * GaolfGTP ) ;
   r_ir_3 = ( ( ( Spine * kGolfback ) * GaolfGDP ) * Gbgolf ) ;
   r_ir_4 = ( ( Spine * kcatAC5GaolfGTP_ATP ) * AC5GaolfGTP_ATP ) ;
   r_ir_5 = ( ( ( Spine * kicatAC5GaolfGTP_ATP ) * cAMP ) * AC5GaolfGTP ) ;
   r_ir_6 = ( ( Spine * kcatAC5_ATP ) * AC5_ATP ) ;
   r_ir_7 = ( ( ( Spine * kicatAC5_ATP ) * cAMP ) * AC5 ) ;
   r_ir_8 = ( ( Spine * krgso ) * AC5GaolfGTP ) ;
   r_ir_9 = ( ( Spine * krgso ) * AC5GaolfGTP_ATP ) ;
   r_ir_10 = ( ( Spine * kcatPDE4_cAMP ) * PDE4_cAMP ) ;
   r_ir_11 = ( ( Spine * kcatcAMP_PDE10 ) * PDE10_cAMP ) ;
   r_ir_12 = ( ( Spine * kcatPDE10c_cAMP ) * PDE10c_cAMP ) ;
   r_r_17 = ( Spine * ( ( ( kfPP1_Target1p * PP1 ) * Target1p ) - ( krPP1_Target1p * PP1_Target1p ) ) ) ;
   r_r_16 = ( Spine * ( ( ( kfPKAc_Target1 * Target1 ) * PKAc ) - ( krPKAc_Target1 * PKAc_Target1 ) ) ) ;
   r_ir_14 = ( ( Spine * kcatPKAc_Target1 ) * PKAc_Target1 ) ;
   r_ir_15 = ( ( Spine * kcatPP1_Target1p ) * PP1_Target1p ) ;
   rate_AC5GaolfGTP = tscale * ( r_r_5 - r_r_6 + r_ir_4 - r_ir_5 - r_ir_8 ) / Spine ;
   rate_Gbgolf = tscale * ( r_ir_1 - r_ir_3 ) / Spine ;
   rate_PDE4_cAMP = tscale * ( r_r_9 - r_ir_10 ) / Spine ;
   rate_AC5GaolfGTP_ATP = tscale * ( r_r_6 + r_r_8 - r_ir_4 + r_ir_5 - r_ir_9 ) / Spine ;
   rate_PP1 = tscale * ( - 1.0 * r_r_17 + r_ir_15 ) / Spine ;
   rate_PDE4 = tscale * ( - 1.0 * r_r_9 + r_ir_10 ) / Spine ;
   rate_PKAreg = tscale * ( r_r_15 ) / Spine ;
   rate_GaolfGDP = tscale * ( r_ir_2 - r_ir_3 + r_ir_8 + r_ir_9 ) / Spine ;
   rate_AC5 = tscale * ( - 1.0 * r_r_5 - r_r_7 + r_ir_6 - r_ir_7 + r_ir_8 ) / Spine ;
   rate_cAMP = tscale * ( - 1.0 * r_r_9 - r_r_10 * 2.0 - r_r_11 - r_r_12 - r_r_13 - r_r_14 + r_ir_4 - r_ir_5 + r_ir_6 - r_ir_7 ) / Spine ;
   rate_GaolfGTP = tscale * ( - 1.0 * r_r_5 - r_r_8 + r_ir_1 - r_ir_2 ) / Spine ;
   rate_PDE10_cAMP = tscale * ( r_r_11 - r_ir_11 ) / Spine ;
   rate_PKAcAMP4 = tscale * ( r_r_14 - r_r_15 ) / Spine ;
   rate_PDE10c = tscale * ( r_r_10 - r_r_12 + r_ir_12 ) / Spine ;
   rate_PDE10c_cAMP = tscale * ( r_r_12 - r_ir_12 ) / Spine ;
   rate_PDE10 = tscale * ( - 1.0 * r_r_10 - r_r_11 + r_ir_11 ) / Spine ;
   rate_Target1 = tscale * ( - 1.0 * r_r_16 + r_ir_15 ) / Spine ;
   rate_Target1p = tscale * ( - 1.0 * r_r_17 + r_ir_14 ) / Spine ;
   rate_D1RDA = tscale * ( r_r_2 - r_r_4 + r_ir_1 ) / Spine ;
   rate_D1R = tscale * ( - 1.0 * r_r_2 - r_r_3 ) / Spine ;
   rate_Golf = tscale * ( - 1.0 * r_r_3 - r_r_4 + r_ir_3 ) / Spine ;
   rate_PKA = tscale * ( - 1.0 * r_r_13 ) / Spine ;
   rate_PKAc_Target1 = tscale * ( r_r_16 - r_ir_14 ) / Spine ;
   rate_PKAc = tscale * ( r_r_15 - r_r_16 + r_ir_14 ) / Spine ;
   rate_PP1_Target1p = tscale * ( r_r_17 - r_ir_15 ) / Spine ;
   rate_PKAcAMP2 = tscale * ( r_r_13 - r_r_14 ) / Spine ;
   rate_D1RDAGolf = tscale * ( r_r_1 + r_r_4 - r_ir_1 ) / Spine ;
   rate_D1RGolf = tscale * ( - 1.0 * r_r_1 + r_r_3 ) / Spine ;
   rate_AC5_ATP = tscale * ( r_r_7 - r_r_8 - r_ir_6 + r_ir_7 + r_ir_9 ) / Spine ;
    return 0; }
 
static double _hoc_rates(void* _vptr) {
 double _r;
   double* _p; Datum* _ppvar; Datum* _thread; _NrnThread* _nt;
   _p = ((Point_process*)_vptr)->_prop->param;
  _ppvar = ((Point_process*)_vptr)->_prop->dparam;
  _thread = _extcall_thread;
  _nt = (_NrnThread*)((Point_process*)_vptr)->_vnt;
 _r = 1.;
 rates ( _p, _ppvar, _thread, _nt );
 return(_r);
}
 
static int _ode_count(int _type){ return 29;}
 
static void _ode_spec(_NrnThread* _nt, _Memb_list* _ml, int _type) {
   double* _p; Datum* _ppvar; Datum* _thread;
   Node* _nd; double _v; int _iml, _cntml;
  _cntml = _ml->_nodecount;
  _thread = _ml->_thread;
  for (_iml = 0; _iml < _cntml; ++_iml) {
    _p = _ml->_data[_iml]; _ppvar = _ml->_pdata[_iml];
    _nd = _ml->_nodelist[_iml];
    v = NODEV(_nd);
     _ode_spec1 (_p, _ppvar, _thread, _nt);
 }}
 
static void _ode_map(int _ieq, double** _pv, double** _pvdot, double* _pp, Datum* _ppd, double* _atol, int _type) { 
	double* _p; Datum* _ppvar;
 	int _i; _p = _pp; _ppvar = _ppd;
	_cvode_ieq = _ieq;
	for (_i=0; _i < 29; ++_i) {
		_pv[_i] = _pp + _slist1[_i];  _pvdot[_i] = _pp + _dlist1[_i];
		_cvode_abstol(_atollist, _atol, _i);
	}
 }
 
static void _ode_matsol_instance1(_threadargsproto_) {
 _ode_matsol1 (_p, _ppvar, _thread, _nt);
 }
 
static void _ode_matsol(_NrnThread* _nt, _Memb_list* _ml, int _type) {
   double* _p; Datum* _ppvar; Datum* _thread;
   Node* _nd; double _v; int _iml, _cntml;
  _cntml = _ml->_nodecount;
  _thread = _ml->_thread;
  for (_iml = 0; _iml < _cntml; ++_iml) {
    _p = _ml->_data[_iml]; _ppvar = _ml->_pdata[_iml];
    _nd = _ml->_nodelist[_iml];
    v = NODEV(_nd);
 _ode_matsol_instance1(_threadargs_);
 }}

static void initmodel(double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt) {
  int _i; double _save;{
  AC5_ATP = AC5_ATP0;
  AC5GaolfGTP_ATP = AC5GaolfGTP_ATP0;
  ATP = ATP0;
  AMP = AMP0;
  AC5GaolfGTP = AC5GaolfGTP0;
  AC5 = AC50;
  DA = DA0;
  D1R = D1R0;
  D1RDA = D1RDA0;
  D1RGolf = D1RGolf0;
  D1RDAGolf = D1RDAGolf0;
  Golf = Golf0;
  GaolfGTP = GaolfGTP0;
  Gbgolf = Gbgolf0;
  GaolfGDP = GaolfGDP0;
  PKAc_Target1 = PKAc_Target10;
  PP1_Target1p = PP1_Target1p0;
  PDE10c_cAMP = PDE10c_cAMP0;
  PDE10_cAMP = PDE10_cAMP0;
  PDE10 = PDE100;
  PDE10c = PDE10c0;
  PDE4_cAMP = PDE4_cAMP0;
  PP1 = PP10;
  PKAc = PKAc0;
  PKAreg = PKAreg0;
  PKAcAMP4 = PKAcAMP40;
  PKAcAMP2 = PKAcAMP20;
  PKA = PKA0;
  PDE4 = PDE40;
  Target1 = Target10;
  Target1p = Target1p0;
  cAMP = cAMP0;
 {
   rates ( _threadargs_ ) ;
   rates ( _threadargs_ ) ;
   GaolfGDP = init_GaolfGDP ;
   Gbgolf = init_Gbgolf ;
   GaolfGTP = init_GaolfGTP ;
   D1RDAGolf = init_D1RDAGolf ;
   Golf = init_Golf ;
   D1RGolf = init_D1RGolf ;
   D1RDA = init_D1RDA ;
   D1R = init_D1R ;
   cAMP = init_cAMP ;
   AC5 = init_AC5 ;
   AC5GaolfGTP = init_AC5GaolfGTP ;
   PDE4 = init_PDE4 ;
   PKA = init_PKA ;
   PKAcAMP2 = init_PKAcAMP2 ;
   PKAcAMP4 = init_PKAcAMP4 ;
   PKAreg = init_PKAreg ;
   PKAc = init_PKAc ;
   PP1 = init_PP1 ;
   DA = init_DA ;
   AMP = init_AMP ;
   PDE4_cAMP = init_PDE4_cAMP ;
   PDE10c = init_PDE10c ;
   PDE10 = init_PDE10 ;
   PDE10_cAMP = init_PDE10_cAMP ;
   PDE10c_cAMP = init_PDE10c_cAMP ;
   ATP = init_ATP ;
   AC5GaolfGTP_ATP = init_AC5GaolfGTP_ATP ;
   AC5_ATP = init_AC5_ATP ;
   PP1_Target1p = init_PP1_Target1p ;
   Target1p = init_Target1p ;
   PKAc_Target1 = init_PKAc_Target1 ;
   Target1 = init_Target1 ;
   }
 
}
}

static void nrn_init(_NrnThread* _nt, _Memb_list* _ml, int _type){
double* _p; Datum* _ppvar; Datum* _thread;
Node *_nd; double _v; int* _ni; int _iml, _cntml;
#if CACHEVEC
    _ni = _ml->_nodeindices;
#endif
_cntml = _ml->_nodecount;
_thread = _ml->_thread;
for (_iml = 0; _iml < _cntml; ++_iml) {
 _p = _ml->_data[_iml]; _ppvar = _ml->_pdata[_iml];
#if CACHEVEC
  if (use_cachevec) {
    _v = VEC_V(_ni[_iml]);
  }else
#endif
  {
    _nd = _ml->_nodelist[_iml];
    _v = NODEV(_nd);
  }
 v = _v;
 initmodel(_p, _ppvar, _thread, _nt);
}
}

static double _nrn_current(double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt, double _v){double _current=0.;v=_v;{
} return _current;
}

static void nrn_cur(_NrnThread* _nt, _Memb_list* _ml, int _type) {
double* _p; Datum* _ppvar; Datum* _thread;
Node *_nd; int* _ni; double _rhs, _v; int _iml, _cntml;
#if CACHEVEC
    _ni = _ml->_nodeindices;
#endif
_cntml = _ml->_nodecount;
_thread = _ml->_thread;
for (_iml = 0; _iml < _cntml; ++_iml) {
 _p = _ml->_data[_iml]; _ppvar = _ml->_pdata[_iml];
#if CACHEVEC
  if (use_cachevec) {
    _v = VEC_V(_ni[_iml]);
  }else
#endif
  {
    _nd = _ml->_nodelist[_iml];
    _v = NODEV(_nd);
  }
 
}
 
}

static void nrn_jacob(_NrnThread* _nt, _Memb_list* _ml, int _type) {
double* _p; Datum* _ppvar; Datum* _thread;
Node *_nd; int* _ni; int _iml, _cntml;
#if CACHEVEC
    _ni = _ml->_nodeindices;
#endif
_cntml = _ml->_nodecount;
_thread = _ml->_thread;
for (_iml = 0; _iml < _cntml; ++_iml) {
 _p = _ml->_data[_iml];
#if CACHEVEC
  if (use_cachevec) {
	VEC_D(_ni[_iml]) += _g;
  }else
#endif
  {
     _nd = _ml->_nodelist[_iml];
	NODED(_nd) += _g;
  }
 
}
 
}

static void nrn_state(_NrnThread* _nt, _Memb_list* _ml, int _type) {
double* _p; Datum* _ppvar; Datum* _thread;
Node *_nd; double _v = 0.0; int* _ni; int _iml, _cntml;
#if CACHEVEC
    _ni = _ml->_nodeindices;
#endif
_cntml = _ml->_nodecount;
_thread = _ml->_thread;
for (_iml = 0; _iml < _cntml; ++_iml) {
 _p = _ml->_data[_iml]; _ppvar = _ml->_pdata[_iml];
 _nd = _ml->_nodelist[_iml];
#if CACHEVEC
  if (use_cachevec) {
    _v = VEC_V(_ni[_iml]);
  }else
#endif
  {
    _nd = _ml->_nodelist[_iml];
    _v = NODEV(_nd);
  }
 v=_v;
{
 {   states(_p, _ppvar, _thread, _nt);
  } {
   }
}}

}

static void terminal(){}

static void _initlists(){
 double _x; double* _p = &_x;
 int _i; static int _first = 1;
  if (!_first) return;
 _slist1[0] = &(GaolfGDP) - _p;  _dlist1[0] = &(DGaolfGDP) - _p;
 _slist1[1] = &(PKAreg) - _p;  _dlist1[1] = &(DPKAreg) - _p;
 _slist1[2] = &(AC5_ATP) - _p;  _dlist1[2] = &(DAC5_ATP) - _p;
 _slist1[3] = &(AC5GaolfGTP_ATP) - _p;  _dlist1[3] = &(DAC5GaolfGTP_ATP) - _p;
 _slist1[4] = &(PKAcAMP4) - _p;  _dlist1[4] = &(DPKAcAMP4) - _p;
 _slist1[5] = &(AC5GaolfGTP) - _p;  _dlist1[5] = &(DAC5GaolfGTP) - _p;
 _slist1[6] = &(PP1) - _p;  _dlist1[6] = &(DPP1) - _p;
 _slist1[7] = &(Gbgolf) - _p;  _dlist1[7] = &(DGbgolf) - _p;
 _slist1[8] = &(PDE10) - _p;  _dlist1[8] = &(DPDE10) - _p;
 _slist1[9] = &(GaolfGTP) - _p;  _dlist1[9] = &(DGaolfGTP) - _p;
 _slist1[10] = &(PDE10_cAMP) - _p;  _dlist1[10] = &(DPDE10_cAMP) - _p;
 _slist1[11] = &(Target1p) - _p;  _dlist1[11] = &(DTarget1p) - _p;
 _slist1[12] = &(PDE10c) - _p;  _dlist1[12] = &(DPDE10c) - _p;
 _slist1[13] = &(cAMP) - _p;  _dlist1[13] = &(DcAMP) - _p;
 _slist1[14] = &(AC5) - _p;  _dlist1[14] = &(DAC5) - _p;
 _slist1[15] = &(PDE10c_cAMP) - _p;  _dlist1[15] = &(DPDE10c_cAMP) - _p;
 _slist1[16] = &(D1RDAGolf) - _p;  _dlist1[16] = &(DD1RDAGolf) - _p;
 _slist1[17] = &(D1RGolf) - _p;  _dlist1[17] = &(DD1RGolf) - _p;
 _slist1[18] = &(PKAc_Target1) - _p;  _dlist1[18] = &(DPKAc_Target1) - _p;
 _slist1[19] = &(Target1) - _p;  _dlist1[19] = &(DTarget1) - _p;
 _slist1[20] = &(D1R) - _p;  _dlist1[20] = &(DD1R) - _p;
 _slist1[21] = &(D1RDA) - _p;  _dlist1[21] = &(DD1RDA) - _p;
 _slist1[22] = &(PP1_Target1p) - _p;  _dlist1[22] = &(DPP1_Target1p) - _p;
 _slist1[23] = &(Golf) - _p;  _dlist1[23] = &(DGolf) - _p;
 _slist1[24] = &(PKA) - _p;  _dlist1[24] = &(DPKA) - _p;
 _slist1[25] = &(PKAc) - _p;  _dlist1[25] = &(DPKAc) - _p;
 _slist1[26] = &(PDE4) - _p;  _dlist1[26] = &(DPDE4) - _p;
 _slist1[27] = &(PDE4_cAMP) - _p;  _dlist1[27] = &(DPDE4_cAMP) - _p;
 _slist1[28] = &(PKAcAMP2) - _p;  _dlist1[28] = &(DPKAcAMP2) - _p;
_first = 0;
}

#if defined(__cplusplus)
} /* extern "C" */
#endif

#if NMODL_TEXT
static const char* nmodl_filename = "/home/jofrony/Documents/Repositories/BasalGangliaExperiments/Neuromodulation-software/local/adaptive/Experiment-Simulation/mechanisms-ptr/D1.mod";
static const char* nmodl_file_text = 
  "TITLE Mod file for component: Component(id=D1_reduced_cascade2_0 type=D1_reduced_cascade2)\n"
  "\n"
  "COMMENT\n"
  "    \n"
  "    reduced speedy cascade from DA to phosphorylated target\n"
  "    - second version \n"
  "    \n"
  "    - original cascade implemented and exported to SBML by Anu Nair; nair at kth . se\n"
  "        based on published cascade in Nair et al., 2016 with removed dependencies and\n"
  "        addition of excitable target.\n"
  "    \n"
  "    - transformation from SBML to mod by Robert Lindroos; robert . lindroos at ki . se\n"
  "        using NeuroML and a custom made python script that searches \n"
  "        the xml file and replaces the ID's of the substrates for the names.\n"
  "        The script also shortens long names (e.g. reversable_reaction -> r_r)\n"
  "        the name of the mechanism has alos been manually changed from D1_LTP_cascade... to\n"
  "            D1_reduced_cascade2_0\n"
  "            \n"
  "\n"
  "    This NEURON file has been generated by org.neuroml.export (see https://github.com/NeuroML/org.neuroml.export)\n"
  "         org.neuroml.export  v1.4.2\n"
  "         org.neuroml.model   v1.4.2\n"
  "         jLEMS               v0.9.7.3\n"
  "\n"
  "ENDCOMMENT\n"
  "\n"
  "NEURON {\n"
  "    THREADSAFE\n"
  "    POINT_PROCESS D1\n"
  "    RANGE kGaolfGTPase: parameter\n"
  "    RANGE kfPKA_2cAMP: parameter\n"
  "    RANGE krPKA_2cAMP: parameter\n"
  "    RANGE krPKAc_PKAr: parameter\n"
  "    RANGE kfPKAc_PKAr: parameter\n"
  "    RANGE kfPKA2cAMP_2cAMP: parameter\n"
  "    RANGE krPKA2cAMP_2cAMP: parameter\n"
  "    RANGE kactGolf: parameter\n"
  "    RANGE kcatPDE4_cAMP: parameter\n"
  "    RANGE kfPDE4_cAMP: parameter\n"
  "    RANGE krPDE4_cAMP: parameter\n"
  "    RANGE krPDE10_cAMP: parameter\n"
  "    RANGE kcatPDE10c_cAMP: parameter\n"
  "    RANGE kfPDE10_cAMP: parameter\n"
  "    RANGE kfcAMP_PDE10: parameter\n"
  "    RANGE krcAMP_PDE10: parameter\n"
  "    RANGE kcatcAMP_PDE10: parameter\n"
  "    RANGE kcatAC5GaolfGTP_ATP: parameter\n"
  "    RANGE kicatAC5GaolfGTP_ATP: parameter\n"
  "    RANGE kcatAC5_ATP: parameter\n"
  "    RANGE kicatAC5_ATP: parameter\n"
  "    RANGE kfAC5_ATP: parameter\n"
  "    RANGE kGolfback: parameter\n"
  "    RANGE kfAC5GaolfGTP_ATP: parameter\n"
  "    RANGE kfD1R_Golf: parameter\n"
  "    RANGE krD1R_Golf: parameter\n"
  "    RANGE kfD1RDA_Golf: parameter\n"
  "    RANGE krD1RDA_Golf: parameter\n"
  "    RANGE krAC5X_ATP: parameter\n"
  "    RANGE kfAC5XGaolfGTP: parameter\n"
  "    RANGE krAC5XGaolfGTP: parameter\n"
  "    RANGE krgso: parameter\n"
  "    RANGE kfPDE10c_cAMP: parameter\n"
  "    RANGE krPDE10c_cAMP: parameter\n"
  "    RANGE kfD1R_DA: parameter\n"
  "    RANGE kfD1RGolf_DA: parameter\n"
  "    RANGE krD1R_DA: parameter\n"
  "    RANGE krD1RGolf_DA: parameter\n"
  "    RANGE kfPP1_Target1p                    : parameter\n"
  "    RANGE krPP1_Target1p                    : parameter\n"
  "    RANGE kfPKAc_Target1                    : parameter\n"
  "    RANGE krPKAc_Target1                    : parameter\n"
  "    RANGE kcatPP1_Target1p                  : parameter\n"
  "    RANGE kcatPKAc_Target1                  : parameter\n"
  "    RANGE tscale                            : parameter\n"
  "    RANGE Spine: parameter\n"
  "    RANGE init_GaolfGDP: parameter\n"
  "    RANGE init_Gbgolf: parameter\n"
  "    RANGE init_GaolfGTP: parameter\n"
  "    RANGE init_D1RDAGolf: parameter\n"
  "    RANGE init_Golf: parameter\n"
  "    RANGE init_D1RGolf: parameter\n"
  "    RANGE init_D1RDA: parameter\n"
  "    RANGE init_D1R: parameter\n"
  "    RANGE init_cAMP: parameter\n"
  "    RANGE init_AC5: parameter\n"
  "    RANGE init_AC5GaolfGTP: parameter\n"
  "    RANGE init_PDE4: parameter\n"
  "    RANGE init_PKA: parameter\n"
  "    RANGE init_PKAcAMP2: parameter\n"
  "    RANGE init_PKAcAMP4: parameter\n"
  "    RANGE init_PKAreg: parameter\n"
  "    RANGE init_PKAc: parameter\n"
  "    RANGE init_PP1: parameter\n"
  "    RANGE init_DA: parameter\n"
  "    RANGE init_AMP: parameter\n"
  "    RANGE init_PDE4_cAMP: parameter\n"
  "    RANGE init_PDE10c: parameter\n"
  "    RANGE init_PDE10: parameter\n"
  "    RANGE init_PDE10_cAMP: parameter\n"
  "    RANGE init_PDE10c_cAMP: parameter\n"
  "    RANGE init_ATP: parameter\n"
  "    RANGE init_AC5GaolfGTP_ATP: parameter\n"
  "    RANGE init_AC5_ATP: parameter\n"
  "    RANGE init_PP1_Target1p                 : parameter\n"
  "    RANGE init_Target1p                     : parameter\n"
  "    RANGE init_PKAc_Target1                 : parameter\n"
  "    RANGE init_Target1                      : parameter\n"
  "    RANGE r_r_1               : derived variable\n"
  "    RANGE r_r_2               : derived variable\n"
  "    RANGE r_r_3               : derived variable\n"
  "    RANGE r_r_4               : derived variable\n"
  "    RANGE r_r_5               : derived variable\n"
  "    RANGE r_r_6               : derived variable\n"
  "    RANGE r_r_7               : derived variable\n"
  "    RANGE r_r_8               : derived variable\n"
  "    RANGE r_r_9               : derived variable\n"
  "    RANGE r_r_10              : derived variable\n"
  "    RANGE r_r_11              : derived variable\n"
  "    RANGE r_r_12              : derived variable\n"
  "    RANGE r_r_13              : derived variable\n"
  "    RANGE r_r_14              : derived variable\n"
  "    RANGE r_r_15              : derived variable\n"
  "    RANGE r_ir_1             : derived variable\n"
  "    RANGE r_ir_2             : derived variable\n"
  "    RANGE r_ir_3             : derived variable\n"
  "    RANGE r_ir_4             : derived variable\n"
  "    RANGE r_ir_5             : derived variable\n"
  "    RANGE r_ir_6             : derived variable\n"
  "    RANGE r_ir_7             : derived variable\n"
  "    RANGE r_ir_8             : derived variable\n"
  "    RANGE r_ir_9             : derived variable\n"
  "    RANGE r_ir_10            : derived variable\n"
  "    RANGE r_ir_11            : derived variable\n"
  "    RANGE r_ir_12            : derived variable\n"
  "    RANGE r_r_17              : derived variable\n"
  "    RANGE r_r_16              : derived variable\n"
  "    RANGE r_ir_14            : derived variable\n"
  "    RANGE r_ir_15            : derived variable\n"
  "    \n"
  "}\n"
  "\n"
  "UNITS {\n"
  "    \n"
  "    (nA) = (nanoamp)\n"
  "    (uA) = (microamp)\n"
  "    (mA) = (milliamp)\n"
  "    (A) = (amp)\n"
  "    (mV) = (millivolt)\n"
  "    (mS) = (millisiemens)\n"
  "    (uS) = (microsiemens)\n"
  "    (molar) = (1/liter)\n"
  "    (kHz) = (kilohertz)\n"
  "    (mM) = (millimolar)\n"
  "    (um) = (micrometer)\n"
  "    (umol) = (micromole)\n"
  "    (S) = (siemens)\n"
  "    \n"
  "}\n"
  "\n"
  "PARAMETER {\n"
  "    \n"
  "    kGaolfGTPase = 30 \n"
  "    kfPKA_2cAMP = 0.026 \n"
  "    krPKA_2cAMP = 350 \n"
  "    krPKAc_PKAr = 50 \n"
  "    kfPKAc_PKAr = 0.03 \n"
  "    kfPKA2cAMP_2cAMP = 0.0346 \n"
  "    krPKA2cAMP_2cAMP = 50 \n"
  "    kactGolf = 15 \n"
  "    kcatPDE4_cAMP = 2.5 \n"
  "    kfPDE4_cAMP = 0.03 \n"
  "    krPDE4_cAMP = 1 \n"
  "    krPDE10_cAMP = 1 \n"
  "    kcatPDE10c_cAMP = 10 \n"
  "    kfPDE10_cAMP = 1.0E-6 \n"
  "    kfcAMP_PDE10 = 0.1 \n"
  "    krcAMP_PDE10 = 2 \n"
  "    kcatcAMP_PDE10 = 3 \n"
  "    kcatAC5GaolfGTP_ATP = 50 \n"
  "    kicatAC5GaolfGTP_ATP = 2.55 \n"
  "    kcatAC5_ATP = 1 \n"
  "    kicatAC5_ATP = 0.002 \n"
  "    kfAC5_ATP = 1.0E-4 \n"
  "    kGolfback = 100 \n"
  "    kfAC5GaolfGTP_ATP = 0.00255 \n"
  "    kfD1R_Golf = 0.06 \n"
  "    krD1R_Golf = 250 \n"
  "    kfD1RDA_Golf = 0.06 \n"
  "    krD1RDA_Golf = 250 \n"
  "    krAC5X_ATP = 1 \n"
  "    kfAC5XGaolfGTP = 10 \n"
  "    krAC5XGaolfGTP = 1 \n"
  "    krgso = 1 \n"
  "    kfPDE10c_cAMP = 0.1 \n"
  "    krPDE10c_cAMP = 2 \n"
  "    kfD1R_DA = 0.05 \n"
  "    kfD1RGolf_DA = 0.05 \n"
  "    krD1R_DA = 250 \n"
  "    krD1RGolf_DA = 250 \n"
  "    kfPP1_Target1p = 0.001 \n"
  "    krPP1_Target1p = 10 \n"
  "    kfPKAc_Target1 = 0.08 \n"
  "    krPKAc_Target1 = 10 \n"
  "    kcatPP1_Target1p = 5 \n"
  "    kcatPKAc_Target1 = 10 \n"
  "    tscale = 0.001 (kHz)\n"
  "    Spine = 1.0E-15 \n"
  "    init_GaolfGDP = 0.010083121 \n"
  "    init_Gbgolf = 29.885124 \n"
  "    init_GaolfGTP = 0.008913481 \n"
  "    init_D1RDAGolf = 2.008902 \n"
  "    init_Golf = 1453.0726 \n"
  "    init_D1RGolf = 515.0334 \n"
  "    init_D1RDA = 5.959225 \n"
  "    init_D1R = 1476.9984 \n"
  "    init_cAMP = 38.186016 \n"
  "    init_AC5 = 2.6694465 \n"
  "    init_AC5GaolfGTP = 0.118090406 \n"
  "    init_PDE4 = 1506.8085 \n"
  "    init_PKA = 1157.1414 \n"
  "    init_PKAcAMP2 = 3.2824342 \n"
  "    init_PKAcAMP4 = 0.08673742 \n"
  "    init_PKAreg = 39.48949 \n"
  "    init_PKAc = 3.6607807 \n"
  "    init_PP1 = 2927.3425 \n"
  "    init_DA = 20 \n"
  "    init_AMP = 0 \n"
  "    init_PDE4_cAMP = 493.19153 \n"
  "    init_PDE10c = 0.5781013 \n"
  "    init_PDE10 = 396.45627 \n"
  "    init_PDE10_cAMP = 302.78168 \n"
  "    init_PDE10c_cAMP = 0.18396154 \n"
  "    init_ATP = 5000000 \n"
  "    init_AC5GaolfGTP_ATP = 29.748037 \n"
  "    init_AC5_ATP = 667.4644 \n"
  "    init_PP1_Target1p = 73.65742 \n"
  "    init_Target1p = 377.42807 \n"
  "    init_PKAc_Target1 = 36.82871 \n"
  "    init_Target1 = 2515.0857 \n"
  "}\n"
  "\n"
  "ASSIGNED {\n"
  "    \n"
  "    r_r_1                    : derived variable\n"
  "    \n"
  "    r_r_2                    : derived variable\n"
  "    \n"
  "    r_r_3                    : derived variable\n"
  "    \n"
  "    r_r_4                    : derived variable\n"
  "    \n"
  "    r_r_5                    : derived variable\n"
  "    \n"
  "    r_r_6                    : derived variable\n"
  "    \n"
  "    r_r_7                    : derived variable\n"
  "    \n"
  "    r_r_8                    : derived variable\n"
  "    \n"
  "    r_r_9                    : derived variable\n"
  "    \n"
  "    r_r_10                   : derived variable\n"
  "    \n"
  "    r_r_11                   : derived variable\n"
  "    \n"
  "    r_r_12                   : derived variable\n"
  "    \n"
  "    r_r_13                   : derived variable\n"
  "    \n"
  "    r_r_14                   : derived variable\n"
  "    \n"
  "    r_r_15                   : derived variable\n"
  "    \n"
  "    r_ir_1                  : derived variable\n"
  "    \n"
  "    r_ir_2                  : derived variable\n"
  "    \n"
  "    r_ir_3                  : derived variable\n"
  "    \n"
  "    r_ir_4                  : derived variable\n"
  "    \n"
  "    r_ir_5                  : derived variable\n"
  "    \n"
  "    r_ir_6                  : derived variable\n"
  "    \n"
  "    r_ir_7                  : derived variable\n"
  "    \n"
  "    r_ir_8                  : derived variable\n"
  "    \n"
  "    r_ir_9                  : derived variable\n"
  "    \n"
  "    r_ir_10                 : derived variable\n"
  "    \n"
  "    r_ir_11                 : derived variable\n"
  "    \n"
  "    r_ir_12                 : derived variable\n"
  "    \n"
  "    r_r_17                   : derived variable\n"
  "    \n"
  "    r_r_16                   : derived variable\n"
  "    \n"
  "    r_ir_14                 : derived variable\n"
  "    \n"
  "    r_ir_15                 : derived variable\n"
  "    rate_GaolfGDP (/ms)\n"
  "    rate_PKAreg (/ms)\n"
  "    rate_AC5_ATP (/ms)\n"
  "    rate_AC5GaolfGTP_ATP (/ms)\n"
  "    rate_PKAcAMP4 (/ms)\n"
  "    rate_AC5GaolfGTP (/ms)\n"
  "    rate_PP1 (/ms)\n"
  "    rate_Gbgolf (/ms)\n"
  "    rate_PDE10 (/ms)\n"
  "    rate_GaolfGTP (/ms)\n"
  "    rate_PDE10_cAMP (/ms)\n"
  "    rate_Target1p (/ms)\n"
  "    rate_PDE10c (/ms)\n"
  "    rate_cAMP (/ms)\n"
  "    rate_AC5 (/ms)\n"
  "    rate_PDE10c_cAMP (/ms)\n"
  "    rate_D1RDAGolf (/ms)\n"
  "    rate_D1RGolf (/ms)\n"
  "    rate_PKAc_Target1 (/ms)\n"
  "    rate_Target1 (/ms)\n"
  "    rate_D1R (/ms)\n"
  "    rate_D1RDA (/ms)\n"
  "    rate_PP1_Target1p (/ms)\n"
  "    rate_Golf (/ms)\n"
  "    rate_PKA (/ms)\n"
  "    rate_PKAc (/ms)\n"
  "    rate_PDE4 (/ms)\n"
  "    rate_PDE4_cAMP (/ms)\n"
  "    rate_PKAcAMP2 (/ms)\n"
  "    \n"
  "}\n"
  "\n"
  "STATE {\n"
  "    GaolfGDP \n"
  "    Gbgolf \n"
  "    GaolfGTP \n"
  "    D1RDAGolf \n"
  "    Golf \n"
  "    D1RGolf \n"
  "    D1RDA \n"
  "    D1R \n"
  "    cAMP \n"
  "    AC5 \n"
  "    AC5GaolfGTP \n"
  "    PDE4 \n"
  "    PKA \n"
  "    PKAcAMP2 \n"
  "    PKAcAMP4 \n"
  "    PKAreg \n"
  "    PKAc \n"
  "    PP1 \n"
  "    DA \n"
  "    AMP \n"
  "    PDE4_cAMP \n"
  "    PDE10c \n"
  "    PDE10 \n"
  "    PDE10_cAMP \n"
  "    PDE10c_cAMP \n"
  "    ATP \n"
  "    AC5GaolfGTP_ATP \n"
  "    AC5_ATP \n"
  "    PP1_Target1p \n"
  "    Target1p \n"
  "    PKAc_Target1 \n"
  "    Target1 \n"
  "    \n"
  "}\n"
  "\n"
  "INITIAL {\n"
  "    rates()\n"
  "    rates() ? To ensure correct initialisation.\n"
  "    \n"
  "    GaolfGDP = init_GaolfGDP\n"
  "    \n"
  "    Gbgolf = init_Gbgolf\n"
  "    \n"
  "    GaolfGTP = init_GaolfGTP\n"
  "    \n"
  "    D1RDAGolf = init_D1RDAGolf\n"
  "    \n"
  "    Golf = init_Golf\n"
  "    \n"
  "    D1RGolf = init_D1RGolf\n"
  "    \n"
  "    D1RDA = init_D1RDA\n"
  "    \n"
  "    D1R = init_D1R\n"
  "    \n"
  "    cAMP = init_cAMP\n"
  "    \n"
  "    AC5 = init_AC5\n"
  "    \n"
  "    AC5GaolfGTP = init_AC5GaolfGTP\n"
  "    \n"
  "    PDE4 = init_PDE4\n"
  "    \n"
  "    PKA = init_PKA\n"
  "    \n"
  "    PKAcAMP2 = init_PKAcAMP2\n"
  "    \n"
  "    PKAcAMP4 = init_PKAcAMP4\n"
  "    \n"
  "    PKAreg = init_PKAreg\n"
  "    \n"
  "    PKAc = init_PKAc\n"
  "    \n"
  "    PP1 = init_PP1\n"
  "    \n"
  "    DA = init_DA\n"
  "    \n"
  "    AMP = init_AMP\n"
  "    \n"
  "    PDE4_cAMP = init_PDE4_cAMP\n"
  "    \n"
  "    PDE10c = init_PDE10c\n"
  "    \n"
  "    PDE10 = init_PDE10\n"
  "    \n"
  "    PDE10_cAMP = init_PDE10_cAMP\n"
  "    \n"
  "    PDE10c_cAMP = init_PDE10c_cAMP\n"
  "    \n"
  "    ATP = init_ATP\n"
  "    \n"
  "    AC5GaolfGTP_ATP = init_AC5GaolfGTP_ATP\n"
  "    \n"
  "    AC5_ATP = init_AC5_ATP\n"
  "    \n"
  "    PP1_Target1p = init_PP1_Target1p\n"
  "    \n"
  "    Target1p = init_Target1p\n"
  "    \n"
  "    PKAc_Target1 = init_PKAc_Target1\n"
  "    \n"
  "    Target1 = init_Target1\n"
  "    \n"
  "}\n"
  "\n"
  "BREAKPOINT {\n"
  "    \n"
  "    SOLVE states METHOD cnexp\n"
  "    \n"
  "    \n"
  "}\n"
  "\n"
  "DERIVATIVE states {\n"
  "    rates()\n"
  "    GaolfGDP' = rate_GaolfGDP \n"
  "    PKAreg' = rate_PKAreg \n"
  "    AC5_ATP' = rate_AC5_ATP \n"
  "    AC5GaolfGTP_ATP' = rate_AC5GaolfGTP_ATP \n"
  "    PKAcAMP4' = rate_PKAcAMP4 \n"
  "    AC5GaolfGTP' = rate_AC5GaolfGTP \n"
  "    PP1' = rate_PP1 \n"
  "    Gbgolf' = rate_Gbgolf \n"
  "    PDE10' = rate_PDE10 \n"
  "    GaolfGTP' = rate_GaolfGTP \n"
  "    PDE10_cAMP' = rate_PDE10_cAMP \n"
  "    Target1p' = rate_Target1p \n"
  "    PDE10c' = rate_PDE10c \n"
  "    cAMP' = rate_cAMP \n"
  "    AC5' = rate_AC5 \n"
  "    PDE10c_cAMP' = rate_PDE10c_cAMP \n"
  "    D1RDAGolf' = rate_D1RDAGolf \n"
  "    D1RGolf' = rate_D1RGolf \n"
  "    PKAc_Target1' = rate_PKAc_Target1 \n"
  "    Target1' = rate_Target1 \n"
  "    D1R' = rate_D1R \n"
  "    D1RDA' = rate_D1RDA \n"
  "    PP1_Target1p' = rate_PP1_Target1p \n"
  "    Golf' = rate_Golf \n"
  "    PKA' = rate_PKA \n"
  "    PKAc' = rate_PKAc \n"
  "    PDE4' = rate_PDE4 \n"
  "    PDE4_cAMP' = rate_PDE4_cAMP \n"
  "    PKAcAMP2' = rate_PKAcAMP2 \n"
  "    \n"
  "}\n"
  "\n"
  "PROCEDURE rates() {\n"
  "    \n"
  "    r_r_1 = (  Spine   * (((  kfD1RGolf_DA   *    D1RGolf   ) *    DA   ) - (  krD1RGolf_DA   *    D1RDAGolf   ))) ? evaluable\n"
  "    r_r_2 = (  Spine   * (((  kfD1R_DA   *    D1R   ) *    DA   ) - (  krD1R_DA   *    D1RDA   ))) ? evaluable\n"
  "    r_r_3 = (  Spine   * (((  kfD1R_Golf   *    D1R   ) *    Golf   ) - (  krD1R_Golf   *    D1RGolf   ))) ? evaluable\n"
  "    r_r_4 = (  Spine   * (((  kfD1RDA_Golf   *    Golf   ) *    D1RDA   ) - (  krD1RDA_Golf   *    D1RDAGolf   ))) ? evaluable\n"
  "    r_r_5 = (  Spine   * (((  kfAC5XGaolfGTP   *    AC5   ) *    GaolfGTP   ) - (  krAC5XGaolfGTP   *    AC5GaolfGTP   ))) ? evaluable\n"
  "    r_r_6 = (  Spine   * (((  kfAC5GaolfGTP_ATP   *    AC5GaolfGTP   ) *    ATP   ) - (  krAC5X_ATP   *    AC5GaolfGTP_ATP   ))) ? evaluable\n"
  "    r_r_7 = (  Spine   * (((  kfAC5_ATP   *    AC5   ) *    ATP   ) - (  krAC5X_ATP   *    AC5_ATP   ))) ? evaluable\n"
  "    r_r_8 = (  Spine   * (((  kfAC5XGaolfGTP   *    GaolfGTP   ) *    AC5_ATP   ) - (  krAC5XGaolfGTP   *    AC5GaolfGTP_ATP   ))) ? evaluable\n"
  "    r_r_9 = (  Spine   * (((  kfPDE4_cAMP   *    cAMP   ) *    PDE4   ) - (  krPDE4_cAMP   *    PDE4_cAMP   ))) ? evaluable\n"
  "    r_r_10 = (  Spine   * (((  kfPDE10_cAMP   *    PDE10   ) * (   cAMP    ^ 2.0)) - (  krPDE10_cAMP   *    PDE10c   ))) ? evaluable\n"
  "    r_r_11 = (  Spine   * (((  kfcAMP_PDE10   *    cAMP   ) *    PDE10   ) - (  krcAMP_PDE10   *    PDE10_cAMP   ))) ? evaluable\n"
  "    r_r_12 = (  Spine   * (((  kfPDE10c_cAMP   *    cAMP   ) *    PDE10c   ) - (  krPDE10c_cAMP   *    PDE10c_cAMP   ))) ? evaluable\n"
  "    r_r_13 = (  Spine   * (((  kfPKA_2cAMP   *    cAMP   ) *    PKA   ) - (  krPKA_2cAMP   *    PKAcAMP2   ))) ? evaluable\n"
  "    r_r_14 = (  Spine   * (((  kfPKA2cAMP_2cAMP   *    cAMP   ) *    PKAcAMP2   ) - (  krPKA2cAMP_2cAMP   *    PKAcAMP4   ))) ? evaluable\n"
  "    r_r_15 = (  Spine   * ((  krPKAc_PKAr   *    PKAcAMP4   ) - ((  kfPKAc_PKAr   *    PKAc   ) *    PKAreg   ))) ? evaluable\n"
  "    r_ir_1 = ((  Spine   *   kactGolf  ) *    D1RDAGolf   ) ? evaluable\n"
  "    r_ir_2 = ((  Spine   *   kGaolfGTPase  ) *    GaolfGTP   ) ? evaluable\n"
  "    r_ir_3 = (((  Spine   *   kGolfback  ) *    GaolfGDP   ) *    Gbgolf   ) ? evaluable\n"
  "    r_ir_4 = ((  Spine   *   kcatAC5GaolfGTP_ATP  ) *    AC5GaolfGTP_ATP   ) ? evaluable\n"
  "    r_ir_5 = (((  Spine   *   kicatAC5GaolfGTP_ATP  ) *    cAMP   ) *    AC5GaolfGTP   ) ? evaluable\n"
  "    r_ir_6 = ((  Spine   *   kcatAC5_ATP  ) *    AC5_ATP   ) ? evaluable\n"
  "    r_ir_7 = (((  Spine   *   kicatAC5_ATP  ) *    cAMP   ) *    AC5   ) ? evaluable\n"
  "    r_ir_8 = ((  Spine   *   krgso  ) *    AC5GaolfGTP   ) ? evaluable\n"
  "    r_ir_9 = ((  Spine   *   krgso  ) *    AC5GaolfGTP_ATP   ) ? evaluable\n"
  "    r_ir_10 = ((  Spine   *   kcatPDE4_cAMP  ) *    PDE4_cAMP   ) ? evaluable\n"
  "    r_ir_11 = ((  Spine   *   kcatcAMP_PDE10  ) *    PDE10_cAMP   ) ? evaluable\n"
  "    r_ir_12 = ((  Spine   *   kcatPDE10c_cAMP  ) *    PDE10c_cAMP   ) ? evaluable\n"
  "    r_r_17 = (  Spine   * (((  kfPP1_Target1p   *    PP1   ) *    Target1p   ) - (  krPP1_Target1p   *    PP1_Target1p   ))) ? evaluable\n"
  "    r_r_16 = (  Spine   * (((  kfPKAc_Target1   *    Target1   ) *    PKAc   ) - (  krPKAc_Target1   *    PKAc_Target1   ))) ? evaluable\n"
  "    r_ir_14 = ((  Spine   *   kcatPKAc_Target1  ) *    PKAc_Target1   ) ? evaluable\n"
  "    r_ir_15 = ((  Spine   *   kcatPP1_Target1p  ) *    PP1_Target1p   ) ? evaluable\n"
  "    rate_AC5GaolfGTP = tscale  * (  r_r_5   -  r_r_6  +  r_ir_4  -  r_ir_5  -   r_ir_8  ) /  Spine ? Note units of all quantities used here need to be consistent!\n"
  "    rate_Gbgolf = tscale  * (  r_ir_1   -   r_ir_3  ) /  Spine ? Note units of all quantities used here need to be consistent!\n"
  "    rate_PDE4_cAMP = tscale  * (  r_r_9   -   r_ir_10  ) /  Spine ? Note units of all quantities used here need to be consistent!\n"
  "    rate_AC5GaolfGTP_ATP = tscale  * (  r_r_6   +  r_r_8  -  r_ir_4  +  r_ir_5  -   r_ir_9  ) /  Spine ? Note units of all quantities used here need to be consistent!\n"
  "    rate_PP1 = tscale  * (-1*  r_r_17   +   r_ir_15  ) /  Spine ? Note units of all quantities used here need to be consistent!\n"
  "    rate_PDE4 = tscale  * (-1*  r_r_9   +   r_ir_10  ) /  Spine ? Note units of all quantities used here need to be consistent!\n"
  "    rate_PKAreg = tscale  * (  r_r_15  ) /  Spine ? Note units of all quantities used here need to be consistent!\n"
  "    rate_GaolfGDP = tscale  * (  r_ir_2   -  r_ir_3  +  r_ir_8  +   r_ir_9  ) /  Spine ? Note units of all quantities used here need to be consistent!\n"
  "    rate_AC5 = tscale  * (-1*  r_r_5   -  r_r_7  +  r_ir_6  -  r_ir_7  +   r_ir_8  ) /  Spine ? Note units of all quantities used here need to be consistent!\n"
  "    rate_cAMP = tscale  * (-1*  r_r_9   -  r_r_10  * 2.0 -  r_r_11  -  r_r_12  -  r_r_13  -  r_r_14  +  r_ir_4  -  r_ir_5  +  r_ir_6  -   r_ir_7  ) /  Spine ? Note units of all quantities used here need to be consistent!\n"
  "    rate_GaolfGTP = tscale  * (-1*  r_r_5   -  r_r_8  +  r_ir_1  -   r_ir_2  ) /  Spine ? Note units of all quantities used here need to be consistent!\n"
  "    rate_PDE10_cAMP = tscale  * (  r_r_11   -   r_ir_11  ) /  Spine ? Note units of all quantities used here need to be consistent!\n"
  "    rate_PKAcAMP4 = tscale  * (  r_r_14   -   r_r_15  ) /  Spine ? Note units of all quantities used here need to be consistent!\n"
  "    rate_PDE10c = tscale  * (  r_r_10   -  r_r_12  +   r_ir_12  ) /  Spine ? Note units of all quantities used here need to be consistent!\n"
  "    rate_PDE10c_cAMP = tscale  * (  r_r_12   -   r_ir_12  ) /  Spine ? Note units of all quantities used here need to be consistent!\n"
  "    rate_PDE10 = tscale  * (-1*  r_r_10   -  r_r_11  +   r_ir_11  ) /  Spine ? Note units of all quantities used here need to be consistent!\n"
  "    rate_Target1 = tscale  * (-1*  r_r_16   +   r_ir_15  ) /  Spine ? Note units of all quantities used here need to be consistent!\n"
  "    rate_Target1p = tscale  * (-1*  r_r_17   +   r_ir_14  ) /  Spine ? Note units of all quantities used here need to be consistent!\n"
  "    rate_D1RDA = tscale  * (  r_r_2   -  r_r_4  +   r_ir_1  ) /  Spine ? Note units of all quantities used here need to be consistent!\n"
  "    rate_D1R = tscale  * (-1*  r_r_2   -   r_r_3  ) /  Spine ? Note units of all quantities used here need to be consistent!\n"
  "    rate_Golf = tscale  * (-1*  r_r_3   -  r_r_4  +   r_ir_3  ) /  Spine ? Note units of all quantities used here need to be consistent!\n"
  "    rate_PKA = tscale  * (-1*  r_r_13  ) /  Spine ? Note units of all quantities used here need to be consistent!\n"
  "    rate_PKAc_Target1 = tscale  * (  r_r_16   -   r_ir_14  ) /  Spine ? Note units of all quantities used here need to be consistent!\n"
  "    rate_PKAc = tscale  * (  r_r_15   -  r_r_16  +   r_ir_14  ) /  Spine ? Note units of all quantities used here need to be consistent!\n"
  "    rate_PP1_Target1p = tscale  * (  r_r_17   -   r_ir_15  ) /  Spine ? Note units of all quantities used here need to be consistent!\n"
  "    rate_PKAcAMP2 = tscale  * (  r_r_13   -   r_r_14  ) /  Spine ? Note units of all quantities used here need to be consistent!\n"
  "    rate_D1RDAGolf = tscale  * (  r_r_1   +  r_r_4  -   r_ir_1  ) /  Spine ? Note units of all quantities used here need to be consistent!\n"
  "    rate_D1RGolf = tscale  * (-1*  r_r_1   +   r_r_3  ) /  Spine ? Note units of all quantities used here need to be consistent!\n"
  "    rate_AC5_ATP = tscale  * (  r_r_7   -  r_r_8  -  r_ir_6  +  r_ir_7  +   r_ir_9  ) /  Spine ? Note units of all quantities used here need to be consistent!\n"
  "    \n"
  "     \n"
  "    \n"
  "}\n"
  ;
#endif
