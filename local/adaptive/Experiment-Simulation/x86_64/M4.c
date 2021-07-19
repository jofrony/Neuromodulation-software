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
 
#define nrn_init _nrn_init__M4
#define _nrn_initial _nrn_initial__M4
#define nrn_cur _nrn_cur__M4
#define _nrn_current _nrn_current__M4
#define nrn_jacob _nrn_jacob__M4
#define nrn_state _nrn_state__M4
#define _net_receive _net_receive__M4 
#define kin kin__M4 
 
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
#define tau1 _p[0]
#define tau2 _p[1]
#define concentration _p[2]
#define conc_acetylcholine _p[3]
#define Ach _p[4]
#define M4R _p[5]
#define Ach_M4R _p[6]
#define Giabg _p[7]
#define Giabg_M4R _p[8]
#define Ach_M4R_Giabg _p[9]
#define GiaGTP _p[10]
#define GiaGDP _p[11]
#define Gbg _p[12]
#define A _p[13]
#define B _p[14]
#define DAch _p[15]
#define DM4R _p[16]
#define DAch_M4R _p[17]
#define DGiabg _p[18]
#define DGiabg_M4R _p[19]
#define DAch_M4R_Giabg _p[20]
#define DGiaGTP _p[21]
#define DGiaGDP _p[22]
#define DGbg _p[23]
#define DA _p[24]
#define DB _p[25]
#define i _p[26]
#define g _p[27]
#define factor _p[28]
#define v _p[29]
#define _g _p[30]
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
 static double _hoc_Total_Gi();
 static double _hoc_acetylcholine();
 static double _hoc_total_M4R();
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
 "Total_Gi", _hoc_Total_Gi,
 "acetylcholine", _hoc_acetylcholine,
 "total_M4R", _hoc_total_M4R,
 0, 0
};
#define Total_Gi Total_Gi_M4
#define acetylcholine acetylcholine_M4
#define total_M4R total_M4R_M4
 extern double Total_Gi( _threadargsproto_ );
 extern double acetylcholine( _threadargsproto_ );
 extern double total_M4R( _threadargsproto_ );
 /* declare global and static user variables */
#define cc cc_M4
 double cc = 1e-06;
#define e e_M4
 double e = 0;
#define init_Gbg init_Gbg_M4
 double init_Gbg = 120;
#define init_GiaGDP init_GiaGDP_M4
 double init_GiaGDP = 0;
#define init_GiaGTP init_GiaGTP_M4
 double init_GiaGTP = 80;
#define init_Ach_M4R_Giabg init_Ach_M4R_Giabg_M4
 double init_Ach_M4R_Giabg = 0;
#define init_Giabg_M4R init_Giabg_M4R_M4
 double init_Giabg_M4R = 80;
#define init_Giabg init_Giabg_M4
 double init_Giabg = 1680;
#define init_Ach_M4R init_Ach_M4R_M4
 double init_Ach_M4R = 0;
#define init_M4R init_M4R_M4
 double init_M4R = 120;
#define init_Ach init_Ach_M4
 double init_Ach = 105;
#define init_AChE init_AChE_M4
 double init_AChE = 1;
#define kb_GiaGDP kb_GiaGDP_M4
 double kb_GiaGDP = 0;
#define kf_GiaGDP kf_GiaGDP_M4
 double kf_GiaGDP = 2;
#define kb_GiaGTP kb_GiaGTP_M4
 double kb_GiaGTP = 0;
#define kf_GiaGTP kf_GiaGTP_M4
 double kf_GiaGTP = 4;
#define kb_Ach_M4R_Gi kb_Ach_M4R_Gi_M4
 double kb_Ach_M4R_Gi = 0;
#define kf_Ach_M4R_Gi kf_Ach_M4R_Gi_M4
 double kf_Ach_M4R_Gi = 8;
#define kb_AchM4RxGiabg kb_AchM4RxGiabg_M4
 double kb_AchM4RxGiabg = 3.36;
#define kf_AchM4RxGiabg kf_AchM4RxGiabg_M4
 double kf_AchM4RxGiabg = 0.192;
#define kb_M4RxGiabg kb_M4RxGiabg_M4
 double kb_M4RxGiabg = 0.42;
#define kf_M4RxGiabg kf_M4RxGiabg_M4
 double kf_M4RxGiabg = 0.00178;
#define kbAchxM4R_Gi kbAchxM4R_Gi_M4
 double kbAchxM4R_Gi = 20;
#define kf_AchxM4R_Gi kf_AchxM4R_Gi_M4
 double kf_AchxM4R_Gi = 0.036;
#define kb_AchxM4R kb_AchxM4R_M4
 double kb_AchxM4R = 2.5;
#define kf_AchxM4R kf_AchxM4R_M4
 double kf_AchxM4R = 0.000338;
#define one_s_rs one_s_rs_M4
 double one_s_rs = 0.001;
#define two_s_rs two_s_rs_M4
 double two_s_rs = 1000;
 /* some parameters have upper and lower limits */
 static HocParmLimits _hoc_parm_limits[] = {
 "tau2", 1e-09, 1e+09,
 "tau1", 1e-09, 1e+09,
 0,0,0
};
 static HocParmUnits _hoc_parm_units[] = {
 "two_s_rs_M4", "kHz",
 "one_s_rs_M4", "kHz",
 "e_M4", "mV",
 "tau1", "ms",
 "tau2", "ms",
 "conc_acetylcholine", "1",
 0,0
};
 static double A0 = 0;
 static double Ach_M4R_Giabg0 = 0;
 static double Ach_M4R0 = 0;
 static double Ach0 = 0;
 static double B0 = 0;
 static double Gbg0 = 0;
 static double GiaGDP0 = 0;
 static double GiaGTP0 = 0;
 static double Giabg_M4R0 = 0;
 static double Giabg0 = 0;
 static double M4R0 = 0;
 static double delta_t = 0.01;
 /* connect global user variables to hoc */
 static DoubScal hoc_scdoub[] = {
 "kf_AchxM4R_M4", &kf_AchxM4R_M4,
 "kb_AchxM4R_M4", &kb_AchxM4R_M4,
 "kf_AchxM4R_Gi_M4", &kf_AchxM4R_Gi_M4,
 "kbAchxM4R_Gi_M4", &kbAchxM4R_Gi_M4,
 "kf_M4RxGiabg_M4", &kf_M4RxGiabg_M4,
 "kb_M4RxGiabg_M4", &kb_M4RxGiabg_M4,
 "kf_AchM4RxGiabg_M4", &kf_AchM4RxGiabg_M4,
 "kb_AchM4RxGiabg_M4", &kb_AchM4RxGiabg_M4,
 "kf_Ach_M4R_Gi_M4", &kf_Ach_M4R_Gi_M4,
 "kb_Ach_M4R_Gi_M4", &kb_Ach_M4R_Gi_M4,
 "kf_GiaGTP_M4", &kf_GiaGTP_M4,
 "kb_GiaGTP_M4", &kb_GiaGTP_M4,
 "kf_GiaGDP_M4", &kf_GiaGDP_M4,
 "kb_GiaGDP_M4", &kb_GiaGDP_M4,
 "init_AChE_M4", &init_AChE_M4,
 "init_Ach_M4", &init_Ach_M4,
 "init_M4R_M4", &init_M4R_M4,
 "init_Ach_M4R_M4", &init_Ach_M4R_M4,
 "init_Giabg_M4", &init_Giabg_M4,
 "init_Giabg_M4R_M4", &init_Giabg_M4R_M4,
 "init_Ach_M4R_Giabg_M4", &init_Ach_M4R_Giabg_M4,
 "init_GiaGTP_M4", &init_GiaGTP_M4,
 "init_GiaGDP_M4", &init_GiaGDP_M4,
 "init_Gbg_M4", &init_Gbg_M4,
 "cc_M4", &cc_M4,
 "two_s_rs_M4", &two_s_rs_M4,
 "one_s_rs_M4", &one_s_rs_M4,
 "e_M4", &e_M4,
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
"M4",
 "tau1",
 "tau2",
 "concentration",
 0,
 "conc_acetylcholine",
 0,
 "Ach",
 "M4R",
 "Ach_M4R",
 "Giabg",
 "Giabg_M4R",
 "Ach_M4R_Giabg",
 "GiaGTP",
 "GiaGDP",
 "Gbg",
 "A",
 "B",
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
 	_p = nrn_prop_data_alloc(_mechtype, 31, _prop);
 	/*initialize range parameters*/
 	tau1 = 100;
 	tau2 = 500;
 	concentration = 0;
  }
 	_prop->param = _p;
 	_prop->param_size = 31;
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
 static void _thread_cleanup(Datum*);
 extern Symbol* hoc_lookup(const char*);
extern void _nrn_thread_reg(int, int, void(*)(Datum*));
extern void _nrn_thread_table_reg(int, void(*)(double*, Datum*, Datum*, _NrnThread*, int));
extern void hoc_register_tolerance(int, HocStateTolerance*, Symbol***);
extern void _cvode_abstol( Symbol**, double*, int);

 void _M4_reg() {
	int _vectorized = 1;
  _initlists();
 	_pointtype = point_register_mech(_mechanism,
	 nrn_alloc,nrn_cur, nrn_jacob, nrn_state, nrn_init,
	 hoc_nrnpointerindex, 3,
	 _hoc_create_pnt, _hoc_destroy_pnt, _member_func);
  _extcall_thread = (Datum*)ecalloc(2, sizeof(Datum));
 _mechtype = nrn_get_mechtype(_mechanism[1]);
     _nrn_setdata_reg(_mechtype, _setdata);
     _nrn_thread_reg(_mechtype, 0, _thread_cleanup);
 #if NMODL_TEXT
  hoc_reg_nmodl_text(_mechtype, nmodl_file_text);
  hoc_reg_nmodl_filename(_mechtype, nmodl_filename);
#endif
  hoc_register_prop_size(_mechtype, 31, 3);
  hoc_register_dparam_semantics(_mechtype, 0, "area");
  hoc_register_dparam_semantics(_mechtype, 1, "pntproc");
  hoc_register_dparam_semantics(_mechtype, 2, "cvodeieq");
 	hoc_register_cvode(_mechtype, _ode_count, _ode_map, _ode_spec, _ode_matsol);
 	hoc_register_tolerance(_mechtype, _hoc_state_tol, &_atollist);
 	hoc_register_var(hoc_scdoub, hoc_vdoub, hoc_intfunc);
 	ivoc_help("help ?1 M4 /home/jofrony/Documents/Repositories/BasalGangliaExperiments/Neuromodulation-software/local/adaptive/Experiment-Simulation/x86_64/M4.mod\n");
 hoc_register_limits(_mechtype, _hoc_parm_limits);
 hoc_register_units(_mechtype, _hoc_parm_units);
 }
static int _reset;
static char *modelname = "Mod file for component: Component(id=M4)";

static int error;
static int _ninits = 0;
static int _match_recurse=1;
static void _modl_cleanup(){ _match_recurse=1;}
 extern double *_nrn_thread_getelm();
 
#define _MATELM1(_row,_col) *(_nrn_thread_getelm(_so, _row + 1, _col + 1))
 
#define _RHS1(_arg) _rhs[_arg+1]
  
#define _linmat1  0
 static int _spth1 = 1;
 static int _cvspth1 = 0;
 
static int _ode_spec1(_threadargsproto_);
/*static int _ode_matsol1(_threadargsproto_);*/
 static int _slist1[9], _dlist1[9]; static double *_temp1;
 static int kin();
 
static int kin (void* _so, double* _rhs, double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt)
 {int _reset=0;
 {
   double b_flux, f_flux, _term; int _i;
 {int _i; double _dt1 = 1.0/dt;
for(_i=0;_i<9;_i++){
  	_RHS1(_i) = -_dt1*(_p[_slist1[_i]] - _p[_dlist1[_i]]);
	_MATELM1(_i, _i) = _dt1;
      
} }
 /* ~ Ach + M4R <-> Ach_M4R ( kf_AchxM4R * two_s_rs , kb_AchxM4R * one_s_rs )*/
 f_flux =  kf_AchxM4R * two_s_rs * M4R * Ach ;
 b_flux =  kb_AchxM4R * one_s_rs * Ach_M4R ;
 _RHS1( 8) -= (f_flux - b_flux);
 _RHS1( 2) -= (f_flux - b_flux);
 _RHS1( 1) += (f_flux - b_flux);
 
 _term =  kf_AchxM4R * two_s_rs * Ach ;
 _MATELM1( 8 ,8)  += _term;
 _MATELM1( 2 ,8)  += _term;
 _MATELM1( 1 ,8)  -= _term;
 _term =  kf_AchxM4R * two_s_rs * M4R ;
 _MATELM1( 8 ,2)  += _term;
 _MATELM1( 2 ,2)  += _term;
 _MATELM1( 1 ,2)  -= _term;
 _term =  kb_AchxM4R * one_s_rs ;
 _MATELM1( 8 ,1)  -= _term;
 _MATELM1( 2 ,1)  -= _term;
 _MATELM1( 1 ,1)  += _term;
 /*REACTION*/
  /* ~ Ach_M4R + Giabg <-> Ach_M4R_Giabg ( kf_AchM4RxGiabg * two_s_rs , kb_AchM4RxGiabg * one_s_rs )*/
 f_flux =  kf_AchM4RxGiabg * two_s_rs * Giabg * Ach_M4R ;
 b_flux =  kb_AchM4RxGiabg * one_s_rs * Ach_M4R_Giabg ;
 _RHS1( 7) -= (f_flux - b_flux);
 _RHS1( 1) -= (f_flux - b_flux);
 _RHS1( 0) += (f_flux - b_flux);
 
 _term =  kf_AchM4RxGiabg * two_s_rs * Ach_M4R ;
 _MATELM1( 7 ,7)  += _term;
 _MATELM1( 1 ,7)  += _term;
 _MATELM1( 0 ,7)  -= _term;
 _term =  kf_AchM4RxGiabg * two_s_rs * Giabg ;
 _MATELM1( 7 ,1)  += _term;
 _MATELM1( 1 ,1)  += _term;
 _MATELM1( 0 ,1)  -= _term;
 _term =  kb_AchM4RxGiabg * one_s_rs ;
 _MATELM1( 7 ,0)  -= _term;
 _MATELM1( 1 ,0)  -= _term;
 _MATELM1( 0 ,0)  += _term;
 /*REACTION*/
  /* ~ Ach_M4R_Giabg <-> GiaGTP + Ach_M4R + Gbg ( kf_Ach_M4R_Gi * one_s_rs , kb_Ach_M4R_Gi )*/
 f_flux =  kf_Ach_M4R_Gi * one_s_rs * Ach_M4R_Giabg ;
 b_flux =  kb_Ach_M4R_Gi * Gbg * Ach_M4R * GiaGTP ;
 _RHS1( 0) -= (f_flux - b_flux);
 _RHS1( 3) += (f_flux - b_flux);
 _RHS1( 1) += (f_flux - b_flux);
 _RHS1( 5) += (f_flux - b_flux);
 
 _term =  kf_Ach_M4R_Gi * one_s_rs ;
 _MATELM1( 0 ,0)  += _term;
 _MATELM1( 3 ,0)  -= _term;
 _MATELM1( 1 ,0)  -= _term;
 _MATELM1( 5 ,0)  -= _term;
 _term =  kb_Ach_M4R_Gi * Ach_M4R * GiaGTP ;
 _MATELM1( 0 ,3)  -= _term;
 _MATELM1( 3 ,3)  += _term;
 _MATELM1( 1 ,3)  += _term;
 _MATELM1( 5 ,3)  += _term;
 _term =  kb_Ach_M4R_Gi * Gbg * GiaGTP ;
 _MATELM1( 0 ,1)  -= _term;
 _MATELM1( 3 ,1)  += _term;
 _MATELM1( 1 ,1)  += _term;
 _MATELM1( 5 ,1)  += _term;
 _term =  kb_Ach_M4R_Gi * Gbg * Ach_M4R ;
 _MATELM1( 0 ,5)  -= _term;
 _MATELM1( 3 ,5)  += _term;
 _MATELM1( 1 ,5)  += _term;
 _MATELM1( 5 ,5)  += _term;
 /*REACTION*/
  /* ~ M4R + Giabg <-> Giabg_M4R ( kf_M4RxGiabg * two_s_rs , kb_M4RxGiabg * one_s_rs )*/
 f_flux =  kf_M4RxGiabg * two_s_rs * Giabg * M4R ;
 b_flux =  kb_M4RxGiabg * one_s_rs * Giabg_M4R ;
 _RHS1( 7) -= (f_flux - b_flux);
 _RHS1( 8) -= (f_flux - b_flux);
 _RHS1( 6) += (f_flux - b_flux);
 
 _term =  kf_M4RxGiabg * two_s_rs * M4R ;
 _MATELM1( 7 ,7)  += _term;
 _MATELM1( 8 ,7)  += _term;
 _MATELM1( 6 ,7)  -= _term;
 _term =  kf_M4RxGiabg * two_s_rs * Giabg ;
 _MATELM1( 7 ,8)  += _term;
 _MATELM1( 8 ,8)  += _term;
 _MATELM1( 6 ,8)  -= _term;
 _term =  kb_M4RxGiabg * one_s_rs ;
 _MATELM1( 7 ,6)  -= _term;
 _MATELM1( 8 ,6)  -= _term;
 _MATELM1( 6 ,6)  += _term;
 /*REACTION*/
  /* ~ GiaGTP <-> GiaGDP ( kf_GiaGTP * one_s_rs , kb_GiaGTP )*/
 f_flux =  kf_GiaGTP * one_s_rs * GiaGTP ;
 b_flux =  kb_GiaGTP * GiaGDP ;
 _RHS1( 5) -= (f_flux - b_flux);
 _RHS1( 4) += (f_flux - b_flux);
 
 _term =  kf_GiaGTP * one_s_rs ;
 _MATELM1( 5 ,5)  += _term;
 _MATELM1( 4 ,5)  -= _term;
 _term =  kb_GiaGTP ;
 _MATELM1( 5 ,4)  -= _term;
 _MATELM1( 4 ,4)  += _term;
 /*REACTION*/
  /* ~ GiaGDP + Gbg <-> Giabg ( kf_GiaGDP * one_s_rs , kb_GiaGDP )*/
 f_flux =  kf_GiaGDP * one_s_rs * Gbg * GiaGDP ;
 b_flux =  kb_GiaGDP * Giabg ;
 _RHS1( 3) -= (f_flux - b_flux);
 _RHS1( 4) -= (f_flux - b_flux);
 _RHS1( 7) += (f_flux - b_flux);
 
 _term =  kf_GiaGDP * one_s_rs * GiaGDP ;
 _MATELM1( 3 ,3)  += _term;
 _MATELM1( 4 ,3)  += _term;
 _MATELM1( 7 ,3)  -= _term;
 _term =  kf_GiaGDP * one_s_rs * Gbg ;
 _MATELM1( 3 ,4)  += _term;
 _MATELM1( 4 ,4)  += _term;
 _MATELM1( 7 ,4)  -= _term;
 _term =  kb_GiaGDP ;
 _MATELM1( 3 ,7)  -= _term;
 _MATELM1( 4 ,7)  -= _term;
 _MATELM1( 7 ,7)  += _term;
 /*REACTION*/
  /* ~ Ach + Giabg_M4R <-> Ach_M4R_Giabg ( kf_AchxM4R_Gi * two_s_rs , kbAchxM4R_Gi * one_s_rs )*/
 f_flux =  kf_AchxM4R_Gi * two_s_rs * Giabg_M4R * Ach ;
 b_flux =  kbAchxM4R_Gi * one_s_rs * Ach_M4R_Giabg ;
 _RHS1( 6) -= (f_flux - b_flux);
 _RHS1( 2) -= (f_flux - b_flux);
 _RHS1( 0) += (f_flux - b_flux);
 
 _term =  kf_AchxM4R_Gi * two_s_rs * Ach ;
 _MATELM1( 6 ,6)  += _term;
 _MATELM1( 2 ,6)  += _term;
 _MATELM1( 0 ,6)  -= _term;
 _term =  kf_AchxM4R_Gi * two_s_rs * Giabg_M4R ;
 _MATELM1( 6 ,2)  += _term;
 _MATELM1( 2 ,2)  += _term;
 _MATELM1( 0 ,2)  -= _term;
 _term =  kbAchxM4R_Gi * one_s_rs ;
 _MATELM1( 6 ,0)  -= _term;
 _MATELM1( 2 ,0)  -= _term;
 _MATELM1( 0 ,0)  += _term;
 /*REACTION*/
    } return _reset;
 }
 
double total_M4R ( _threadargsproto_ ) {
   double _ltotal_M4R;
 _ltotal_M4R = M4R + Ach_M4R + Ach_M4R_Giabg + Giabg_M4R ;
   
return _ltotal_M4R;
 }
 
static double _hoc_total_M4R(void* _vptr) {
 double _r;
   double* _p; Datum* _ppvar; Datum* _thread; _NrnThread* _nt;
   _p = ((Point_process*)_vptr)->_prop->param;
  _ppvar = ((Point_process*)_vptr)->_prop->dparam;
  _thread = _extcall_thread;
  _nt = (_NrnThread*)((Point_process*)_vptr)->_vnt;
 _r =  total_M4R ( _p, _ppvar, _thread, _nt );
 return(_r);
}
 
double Total_Gi ( _threadargsproto_ ) {
   double _lTotal_Gi;
 _lTotal_Gi = Giabg + Giabg_M4R + GiaGTP + GiaGDP + Ach_M4R_Giabg ;
   
return _lTotal_Gi;
 }
 
static double _hoc_Total_Gi(void* _vptr) {
 double _r;
   double* _p; Datum* _ppvar; Datum* _thread; _NrnThread* _nt;
   _p = ((Point_process*)_vptr)->_prop->param;
  _ppvar = ((Point_process*)_vptr)->_prop->dparam;
  _thread = _extcall_thread;
  _nt = (_NrnThread*)((Point_process*)_vptr)->_vnt;
 _r =  Total_Gi ( _p, _ppvar, _thread, _nt );
 return(_r);
}
 
double acetylcholine ( _threadargsproto_ ) {
   double _lacetylcholine;
 _lacetylcholine = conc_acetylcholine ;
   
return _lacetylcholine;
 }
 
static double _hoc_acetylcholine(void* _vptr) {
 double _r;
   double* _p; Datum* _ppvar; Datum* _thread; _NrnThread* _nt;
   _p = ((Point_process*)_vptr)->_prop->param;
  _ppvar = ((Point_process*)_vptr)->_prop->dparam;
  _thread = _extcall_thread;
  _nt = (_NrnThread*)((Point_process*)_vptr)->_vnt;
 _r =  acetylcholine ( _p, _ppvar, _thread, _nt );
 return(_r);
}
 
/*CVODE ode begin*/
 static int _ode_spec1(double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt) {int _reset=0;{
 double b_flux, f_flux, _term; int _i;
 {int _i; for(_i=0;_i<9;_i++) _p[_dlist1[_i]] = 0.0;}
 /* ~ Ach + M4R <-> Ach_M4R ( kf_AchxM4R * two_s_rs , kb_AchxM4R * one_s_rs )*/
 f_flux =  kf_AchxM4R * two_s_rs * M4R * Ach ;
 b_flux =  kb_AchxM4R * one_s_rs * Ach_M4R ;
 DM4R -= (f_flux - b_flux);
 DAch -= (f_flux - b_flux);
 DAch_M4R += (f_flux - b_flux);
 
 /*REACTION*/
  /* ~ Ach_M4R + Giabg <-> Ach_M4R_Giabg ( kf_AchM4RxGiabg * two_s_rs , kb_AchM4RxGiabg * one_s_rs )*/
 f_flux =  kf_AchM4RxGiabg * two_s_rs * Giabg * Ach_M4R ;
 b_flux =  kb_AchM4RxGiabg * one_s_rs * Ach_M4R_Giabg ;
 DGiabg -= (f_flux - b_flux);
 DAch_M4R -= (f_flux - b_flux);
 DAch_M4R_Giabg += (f_flux - b_flux);
 
 /*REACTION*/
  /* ~ Ach_M4R_Giabg <-> GiaGTP + Ach_M4R + Gbg ( kf_Ach_M4R_Gi * one_s_rs , kb_Ach_M4R_Gi )*/
 f_flux =  kf_Ach_M4R_Gi * one_s_rs * Ach_M4R_Giabg ;
 b_flux =  kb_Ach_M4R_Gi * Gbg * Ach_M4R * GiaGTP ;
 DAch_M4R_Giabg -= (f_flux - b_flux);
 DGbg += (f_flux - b_flux);
 DAch_M4R += (f_flux - b_flux);
 DGiaGTP += (f_flux - b_flux);
 
 /*REACTION*/
  /* ~ M4R + Giabg <-> Giabg_M4R ( kf_M4RxGiabg * two_s_rs , kb_M4RxGiabg * one_s_rs )*/
 f_flux =  kf_M4RxGiabg * two_s_rs * Giabg * M4R ;
 b_flux =  kb_M4RxGiabg * one_s_rs * Giabg_M4R ;
 DGiabg -= (f_flux - b_flux);
 DM4R -= (f_flux - b_flux);
 DGiabg_M4R += (f_flux - b_flux);
 
 /*REACTION*/
  /* ~ GiaGTP <-> GiaGDP ( kf_GiaGTP * one_s_rs , kb_GiaGTP )*/
 f_flux =  kf_GiaGTP * one_s_rs * GiaGTP ;
 b_flux =  kb_GiaGTP * GiaGDP ;
 DGiaGTP -= (f_flux - b_flux);
 DGiaGDP += (f_flux - b_flux);
 
 /*REACTION*/
  /* ~ GiaGDP + Gbg <-> Giabg ( kf_GiaGDP * one_s_rs , kb_GiaGDP )*/
 f_flux =  kf_GiaGDP * one_s_rs * Gbg * GiaGDP ;
 b_flux =  kb_GiaGDP * Giabg ;
 DGbg -= (f_flux - b_flux);
 DGiaGDP -= (f_flux - b_flux);
 DGiabg += (f_flux - b_flux);
 
 /*REACTION*/
  /* ~ Ach + Giabg_M4R <-> Ach_M4R_Giabg ( kf_AchxM4R_Gi * two_s_rs , kbAchxM4R_Gi * one_s_rs )*/
 f_flux =  kf_AchxM4R_Gi * two_s_rs * Giabg_M4R * Ach ;
 b_flux =  kbAchxM4R_Gi * one_s_rs * Ach_M4R_Giabg ;
 DGiabg_M4R -= (f_flux - b_flux);
 DAch -= (f_flux - b_flux);
 DAch_M4R_Giabg += (f_flux - b_flux);
 
 /*REACTION*/
    } return _reset;
 }
 
/*CVODE matsol*/
 static int _ode_matsol1(void* _so, double* _rhs, double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt) {int _reset=0;{
 double b_flux, f_flux, _term; int _i;
   b_flux = f_flux = 0.;
 {int _i; double _dt1 = 1.0/dt;
for(_i=0;_i<9;_i++){
  	_RHS1(_i) = _dt1*(_p[_dlist1[_i]]);
	_MATELM1(_i, _i) = _dt1;
      
} }
 /* ~ Ach + M4R <-> Ach_M4R ( kf_AchxM4R * two_s_rs , kb_AchxM4R * one_s_rs )*/
 _term =  kf_AchxM4R * two_s_rs * Ach ;
 _MATELM1( 8 ,8)  += _term;
 _MATELM1( 2 ,8)  += _term;
 _MATELM1( 1 ,8)  -= _term;
 _term =  kf_AchxM4R * two_s_rs * M4R ;
 _MATELM1( 8 ,2)  += _term;
 _MATELM1( 2 ,2)  += _term;
 _MATELM1( 1 ,2)  -= _term;
 _term =  kb_AchxM4R * one_s_rs ;
 _MATELM1( 8 ,1)  -= _term;
 _MATELM1( 2 ,1)  -= _term;
 _MATELM1( 1 ,1)  += _term;
 /*REACTION*/
  /* ~ Ach_M4R + Giabg <-> Ach_M4R_Giabg ( kf_AchM4RxGiabg * two_s_rs , kb_AchM4RxGiabg * one_s_rs )*/
 _term =  kf_AchM4RxGiabg * two_s_rs * Ach_M4R ;
 _MATELM1( 7 ,7)  += _term;
 _MATELM1( 1 ,7)  += _term;
 _MATELM1( 0 ,7)  -= _term;
 _term =  kf_AchM4RxGiabg * two_s_rs * Giabg ;
 _MATELM1( 7 ,1)  += _term;
 _MATELM1( 1 ,1)  += _term;
 _MATELM1( 0 ,1)  -= _term;
 _term =  kb_AchM4RxGiabg * one_s_rs ;
 _MATELM1( 7 ,0)  -= _term;
 _MATELM1( 1 ,0)  -= _term;
 _MATELM1( 0 ,0)  += _term;
 /*REACTION*/
  /* ~ Ach_M4R_Giabg <-> GiaGTP + Ach_M4R + Gbg ( kf_Ach_M4R_Gi * one_s_rs , kb_Ach_M4R_Gi )*/
 _term =  kf_Ach_M4R_Gi * one_s_rs ;
 _MATELM1( 0 ,0)  += _term;
 _MATELM1( 3 ,0)  -= _term;
 _MATELM1( 1 ,0)  -= _term;
 _MATELM1( 5 ,0)  -= _term;
 _term =  kb_Ach_M4R_Gi * Ach_M4R * GiaGTP ;
 _MATELM1( 0 ,3)  -= _term;
 _MATELM1( 3 ,3)  += _term;
 _MATELM1( 1 ,3)  += _term;
 _MATELM1( 5 ,3)  += _term;
 _term =  kb_Ach_M4R_Gi * Gbg * GiaGTP ;
 _MATELM1( 0 ,1)  -= _term;
 _MATELM1( 3 ,1)  += _term;
 _MATELM1( 1 ,1)  += _term;
 _MATELM1( 5 ,1)  += _term;
 _term =  kb_Ach_M4R_Gi * Gbg * Ach_M4R ;
 _MATELM1( 0 ,5)  -= _term;
 _MATELM1( 3 ,5)  += _term;
 _MATELM1( 1 ,5)  += _term;
 _MATELM1( 5 ,5)  += _term;
 /*REACTION*/
  /* ~ M4R + Giabg <-> Giabg_M4R ( kf_M4RxGiabg * two_s_rs , kb_M4RxGiabg * one_s_rs )*/
 _term =  kf_M4RxGiabg * two_s_rs * M4R ;
 _MATELM1( 7 ,7)  += _term;
 _MATELM1( 8 ,7)  += _term;
 _MATELM1( 6 ,7)  -= _term;
 _term =  kf_M4RxGiabg * two_s_rs * Giabg ;
 _MATELM1( 7 ,8)  += _term;
 _MATELM1( 8 ,8)  += _term;
 _MATELM1( 6 ,8)  -= _term;
 _term =  kb_M4RxGiabg * one_s_rs ;
 _MATELM1( 7 ,6)  -= _term;
 _MATELM1( 8 ,6)  -= _term;
 _MATELM1( 6 ,6)  += _term;
 /*REACTION*/
  /* ~ GiaGTP <-> GiaGDP ( kf_GiaGTP * one_s_rs , kb_GiaGTP )*/
 _term =  kf_GiaGTP * one_s_rs ;
 _MATELM1( 5 ,5)  += _term;
 _MATELM1( 4 ,5)  -= _term;
 _term =  kb_GiaGTP ;
 _MATELM1( 5 ,4)  -= _term;
 _MATELM1( 4 ,4)  += _term;
 /*REACTION*/
  /* ~ GiaGDP + Gbg <-> Giabg ( kf_GiaGDP * one_s_rs , kb_GiaGDP )*/
 _term =  kf_GiaGDP * one_s_rs * GiaGDP ;
 _MATELM1( 3 ,3)  += _term;
 _MATELM1( 4 ,3)  += _term;
 _MATELM1( 7 ,3)  -= _term;
 _term =  kf_GiaGDP * one_s_rs * Gbg ;
 _MATELM1( 3 ,4)  += _term;
 _MATELM1( 4 ,4)  += _term;
 _MATELM1( 7 ,4)  -= _term;
 _term =  kb_GiaGDP ;
 _MATELM1( 3 ,7)  -= _term;
 _MATELM1( 4 ,7)  -= _term;
 _MATELM1( 7 ,7)  += _term;
 /*REACTION*/
  /* ~ Ach + Giabg_M4R <-> Ach_M4R_Giabg ( kf_AchxM4R_Gi * two_s_rs , kbAchxM4R_Gi * one_s_rs )*/
 _term =  kf_AchxM4R_Gi * two_s_rs * Ach ;
 _MATELM1( 6 ,6)  += _term;
 _MATELM1( 2 ,6)  += _term;
 _MATELM1( 0 ,6)  -= _term;
 _term =  kf_AchxM4R_Gi * two_s_rs * Giabg_M4R ;
 _MATELM1( 6 ,2)  += _term;
 _MATELM1( 2 ,2)  += _term;
 _MATELM1( 0 ,2)  -= _term;
 _term =  kbAchxM4R_Gi * one_s_rs ;
 _MATELM1( 6 ,0)  -= _term;
 _MATELM1( 2 ,0)  -= _term;
 _MATELM1( 0 ,0)  += _term;
 /*REACTION*/
    } return _reset;
 }
 
/*CVODE end*/
 
static int _ode_count(int _type){ return 9;}
 
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
	for (_i=0; _i < 9; ++_i) {
		_pv[_i] = _pp + _slist1[_i];  _pvdot[_i] = _pp + _dlist1[_i];
		_cvode_abstol(_atollist, _atol, _i);
	}
 }
 
static void _ode_matsol_instance1(_threadargsproto_) {
 _cvode_sparse_thread(&_thread[_cvspth1]._pvoid, 9, _dlist1, _p, _ode_matsol1, _ppvar, _thread, _nt);
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
 
static void _thread_cleanup(Datum* _thread) {
   _nrn_destroy_sparseobj_thread(_thread[_cvspth1]._pvoid);
   _nrn_destroy_sparseobj_thread(_thread[_spth1]._pvoid);
 }

static void initmodel(double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt) {
  int _i; double _save;{
  A = A0;
  Ach_M4R_Giabg = Ach_M4R_Giabg0;
  Ach_M4R = Ach_M4R0;
  Ach = Ach0;
  B = B0;
  Gbg = Gbg0;
  GiaGDP = GiaGDP0;
  GiaGTP = GiaGTP0;
  Giabg_M4R = Giabg_M4R0;
  Giabg = Giabg0;
  M4R = M4R0;
 {
   double _ltp ;
 if ( tau1 / tau2 > 0.9999 ) {
     tau1 = 0.9999 * tau2 ;
     }
   if ( tau1 / tau2 < 1e-9 ) {
     tau1 = tau2 * 1e-9 ;
     }
   A = 0.0 ;
   B = 0.0 ;
   _ltp = ( tau1 * tau2 ) / ( tau2 - tau1 ) * log ( tau2 / tau1 ) ;
   factor = - exp ( - _ltp / tau1 ) + exp ( - _ltp / tau2 ) ;
   factor = 1.0 / factor ;
   Ach = init_Ach * cc ;
   M4R = init_M4R * cc ;
   Ach_M4R = init_Ach_M4R * cc ;
   Giabg = init_Giabg * cc ;
   Giabg_M4R = init_Giabg_M4R * cc ;
   Ach_M4R_Giabg = init_Ach_M4R_Giabg * cc ;
   GiaGTP = init_GiaGTP * cc ;
   GiaGDP = init_GiaGDP * cc ;
   Gbg = init_Gbg * cc ;
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
double _dtsav = dt;
if (secondorder) { dt *= 0.5; }
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
 {  sparse_thread(&_thread[_spth1]._pvoid, 9, _slist1, _dlist1, _p, &t, dt, kin, _linmat1, _ppvar, _thread, _nt);
     if (secondorder) {
    int _i;
    for (_i = 0; _i < 9; ++_i) {
      _p[_slist1[_i]] += dt*_p[_dlist1[_i]];
    }}
 } {
   total_M4R ( _threadargs_ ) ;
   Total_Gi ( _threadargs_ ) ;
   Ach = acetylcholine ( _threadargs_ ) ;
   concentration = acetylcholine ( _threadargs_ ) ;
   }
}}
 dt = _dtsav;
}

static void terminal(){}

static void _initlists(){
 double _x; double* _p = &_x;
 int _i; static int _first = 1;
  if (!_first) return;
 _slist1[0] = &(Ach_M4R_Giabg) - _p;  _dlist1[0] = &(DAch_M4R_Giabg) - _p;
 _slist1[1] = &(Ach_M4R) - _p;  _dlist1[1] = &(DAch_M4R) - _p;
 _slist1[2] = &(Ach) - _p;  _dlist1[2] = &(DAch) - _p;
 _slist1[3] = &(Gbg) - _p;  _dlist1[3] = &(DGbg) - _p;
 _slist1[4] = &(GiaGDP) - _p;  _dlist1[4] = &(DGiaGDP) - _p;
 _slist1[5] = &(GiaGTP) - _p;  _dlist1[5] = &(DGiaGTP) - _p;
 _slist1[6] = &(Giabg_M4R) - _p;  _dlist1[6] = &(DGiabg_M4R) - _p;
 _slist1[7] = &(Giabg) - _p;  _dlist1[7] = &(DGiabg) - _p;
 _slist1[8] = &(M4R) - _p;  _dlist1[8] = &(DM4R) - _p;
_first = 0;
}

#if defined(__cplusplus)
} /* extern "C" */
#endif

#if NMODL_TEXT
static const char* nmodl_filename = "/home/jofrony/Documents/Repositories/BasalGangliaExperiments/Neuromodulation-software/local/adaptive/Experiment-Simulation/mechanisms-ptr/M4.mod";
static const char* nmodl_file_text = 
  "TITLE Mod file for component: Component(id=M4)\n"
  "\n"
  "COMMENT \n"
  "	Subcellular cascade automatically generated from SBML.\n"
  "		Generated using sbml2mod_converter.py and manually corrected for concentrations\n"
  "		date: 2019-09-20 \n"
  "ENDCOMMENT\n"
  "\n"
  "NEURON { \n"
  "	THREADSAFE\n"
  "	POINT_PROCESS M4 \n"
  "	RANGE Ca,tau1, tau2, Ach\n"
  "	RANGE conc_acetylcholine\n"
  "	RANGE concentration			  \n"
  "\n"
  "}\n"
  "\n"
  "PARAMETER {\n"
  "\n"
  "	\n"
  "	kf_AchxM4R            =  3.38e-4 \n"
  "	kb_AchxM4R            =  2.5\n"
  "	kf_AchxM4R_Gi         =  0.036\n"
  "	kbAchxM4R_Gi          =  20.0\n"
  "	kf_M4RxGiabg          =  0.00178\n"
  "	kb_M4RxGiabg          =  0.42\n"
  "	kf_AchM4RxGiabg       =  0.192\n"
  "	kb_AchM4RxGiabg       =  3.36\n"
  "	kf_Ach_M4R_Gi         =  8.0\n"
  "	kb_Ach_M4R_Gi         =  0\n"
  "	kf_GiaGTP             =  4.0\n"
  "	kb_GiaGTP             =  0\n"
  "	kf_GiaGDP             =  2.0\n"
  "	kb_GiaGDP             =  0\n"
  "	init_AChE	      =  1 \n"
  "	init_Ach              =  105 \n"
  "	init_M4R              =  120 \n"
  "	init_Ach_M4R          =  0 \n"
  "	init_Giabg            =  1680 \n"
  "	init_Giabg_M4R        =  80 \n"
  "	init_Ach_M4R_Giabg    =  0 \n"
  "	init_GiaGTP           =  80 \n"
  "	init_GiaGDP           =  0\n"
  "	init_Gbg              =  120 \n"
  "\n"
  "	: --------- concentration converter (cc): nM -> mM; time converter s -> ms\n"
  "	cc       = 1e-6      \n"
  "	two_s_rs = 1e3  (kHz)\n"
  "	one_s_rs = 1e-3 (kHz)\n"
  "	tau1 = 100 (ms) <1e-9,1e9>\n"
  "	tau2 = 500 (ms) <1e-9,1e9>\n"
  "	e=0	(mV)\n"
  "	concentration = 0\n"
  "}\n"
  "\n"
  "STATE {\n"
  "\n"
  "	Ach\n"
  "	M4R\n"
  "	Ach_M4R\n"
  "	Giabg\n"
  "	Giabg_M4R\n"
  "	Ach_M4R_Giabg\n"
  "	GiaGTP\n"
  "	GiaGDP\n"
  "	Gbg\n"
  "	A\n"
  "	B\n"
  "\n"
  "}\n"
  "ASSIGNED {\n"
  "	v (mV)\n"
  "	i (nA)\n"
  "	g (uS)\n"
  "	factor\n"
  "	conc_acetylcholine (1)\n"
  "}\n"
  "\n"
  "\n"
  "BREAKPOINT { 	\n"
  "	SOLVE kin METHOD sparse\n"
  "	total_M4R()\n"
  "	Total_Gi()\n"
  "	\n"
  "	 \n"
  "	Ach = acetylcholine()\n"
  "	concentration = acetylcholine()\n"
  "				\n"
  "}\n"
  "\n"
  "INITIAL {\n"
  "\n"
  "	LOCAL tp\n"
  "	if (tau1/tau2 > 0.9999) {\n"
  "		tau1 = 0.9999*tau2\n"
  "	}\n"
  "	if (tau1/tau2 < 1e-9) {\n"
  "		tau1 = tau2*1e-9\n"
  "	}\n"
  "	A = 0\n"
  "	B = 0\n"
  "	tp = (tau1*tau2)/(tau2 - tau1) * log(tau2/tau1)\n"
  "	factor = -exp(-tp/tau1) + exp(-tp/tau2)\n"
  "	factor = 1/factor\n"
  "\n"
  "	Ach                   = init_Ach * cc\n"
  "	M4R                   = init_M4R * cc\n"
  "	Ach_M4R               = init_Ach_M4R * cc\n"
  "	Giabg                 = init_Giabg * cc\n"
  "	Giabg_M4R             = init_Giabg_M4R * cc\n"
  "	Ach_M4R_Giabg         = init_Ach_M4R_Giabg * cc\n"
  "	GiaGTP                = init_GiaGTP * cc\n"
  "	GiaGDP                = init_GiaGDP * cc\n"
  "	Gbg                   = init_Gbg * cc\n"
  "\n"
  "	\n"
  "\n"
  "}\n"
  "\n"
  "KINETIC kin {\n"
  "\n"
  "	~ Ach + M4R           <->  Ach_M4R                   		(kf_AchxM4R*two_s_rs,         kb_AchxM4R*one_s_rs)\n"
  "	~ Ach_M4R + Giabg     <->  Ach_M4R_Giabg             		(kf_AchM4RxGiabg*two_s_rs,    kb_AchM4RxGiabg*one_s_rs)\n"
  "	~ Ach_M4R_Giabg       <->  GiaGTP + Ach_M4R + Gbg    		(kf_Ach_M4R_Gi*one_s_rs,      kb_Ach_M4R_Gi)\n"
  "	~ M4R + Giabg         <->  Giabg_M4R                 		(kf_M4RxGiabg*two_s_rs,       kb_M4RxGiabg*one_s_rs)\n"
  "	~ GiaGTP              <->  GiaGDP                    		(kf_GiaGTP*one_s_rs,          kb_GiaGTP)\n"
  "	~ GiaGDP + Gbg        <->  Giabg                     		(kf_GiaGDP*one_s_rs,          kb_GiaGDP)\n"
  "	~ Ach + Giabg_M4R     <->  Ach_M4R_Giabg             		(kf_AchxM4R_Gi*two_s_rs,      kbAchxM4R_Gi*one_s_rs)\n"
  "\n"
  "}\n"
  "\n"
  "FUNCTION total_M4R() {\n"
  "	total_M4R = M4R + Ach_M4R + Ach_M4R_Giabg + Giabg_M4R\n"
  "}\n"
  "\n"
  "FUNCTION Total_Gi() {\n"
  "	Total_Gi = Giabg + Giabg_M4R + GiaGTP + GiaGDP + Ach_M4R_Giabg\n"
  "}\n"
  "\n"
  "FUNCTION acetylcholine() {\n"
  "     acetylcholine = conc_acetylcholine\n"
  "}\n"
  ;
#endif
