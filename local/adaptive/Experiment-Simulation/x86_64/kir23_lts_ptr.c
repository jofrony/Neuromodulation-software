/* Created by Language version: 7.7.0 */
/* NOT VECTORIZED */
#define NRN_VECTORIZED 0
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
 
#define nrn_init _nrn_init__kir23_lts_ptr
#define _nrn_initial _nrn_initial__kir23_lts_ptr
#define nrn_cur _nrn_cur__kir23_lts_ptr
#define _nrn_current _nrn_current__kir23_lts_ptr
#define nrn_jacob _nrn_jacob__kir23_lts_ptr
#define nrn_state _nrn_state__kir23_lts_ptr
#define _net_receive _net_receive__kir23_lts_ptr 
#define rates rates__kir23_lts_ptr 
#define states states__kir23_lts_ptr 
 
#define _threadargscomma_ /**/
#define _threadargsprotocomma_ /**/
#define _threadargs_ /**/
#define _threadargsproto_ /**/
 	/*SUPPRESS 761*/
	/*SUPPRESS 762*/
	/*SUPPRESS 763*/
	/*SUPPRESS 765*/
	 extern double *getarg();
 static double *_p; static Datum *_ppvar;
 
#define t nrn_threads->_t
#define dt nrn_threads->_dt
#define gbar _p[0]
#define modACh _p[1]
#define maxModACh _p[2]
#define ik _p[3]
#define gk _p[4]
#define m _p[5]
#define ek _p[6]
#define minf _p[7]
#define mtau _p[8]
#define Dm _p[9]
#define _g _p[10]
#define _ion_ek	*_ppvar[0]._pval
#define _ion_ik	*_ppvar[1]._pval
#define _ion_dikdv	*_ppvar[2]._pval
#define levelACh	*_ppvar[3]._pval
#define _p_levelACh	_ppvar[3]._pval
 
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
 static int hoc_nrnpointerindex =  3;
 /* external NEURON variables */
 /* declaration of user functions */
 static void _hoc_modulationACh(void);
 static void _hoc_rates(void);
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

 extern void _nrn_setdata_reg(int, void(*)(Prop*));
 static void _setdata(Prop* _prop) {
 _p = _prop->param; _ppvar = _prop->dparam;
 }
 static void _hoc_setdata() {
 Prop *_prop, *hoc_getdata_range(int);
 _prop = hoc_getdata_range(_mechtype);
   _setdata(_prop);
 hoc_retpushx(1.);
}
 /* connect user functions to hoc names */
 static VoidFunc hoc_intfunc[] = {
 "setdata_kir23_lts_ptr", _hoc_setdata,
 "modulationACh_kir23_lts_ptr", _hoc_modulationACh,
 "rates_kir23_lts_ptr", _hoc_rates,
 0, 0
};
#define modulationACh modulationACh_kir23_lts_ptr
 extern double modulationACh( );
 /* declare global and static user variables */
#define q q_kir23_lts_ptr
 double q = 1;
 /* some parameters have upper and lower limits */
 static HocParmLimits _hoc_parm_limits[] = {
 0,0,0
};
 static HocParmUnits _hoc_parm_units[] = {
 "gbar_kir23_lts_ptr", "S/cm2",
 "ik_kir23_lts_ptr", "mA/cm2",
 "gk_kir23_lts_ptr", "S/cm2",
 0,0
};
 static double delta_t = 0.01;
 static double m0 = 0;
 static double v = 0;
 /* connect global user variables to hoc */
 static DoubScal hoc_scdoub[] = {
 "q_kir23_lts_ptr", &q_kir23_lts_ptr,
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
 
static int _ode_count(int);
static void _ode_map(int, double**, double**, double*, Datum*, double*, int);
static void _ode_spec(_NrnThread*, _Memb_list*, int);
static void _ode_matsol(_NrnThread*, _Memb_list*, int);
 
#define _cvode_ieq _ppvar[4]._i
 static void _ode_matsol_instance1(_threadargsproto_);
 /* connect range variables in _p that hoc is supposed to know about */
 static const char *_mechanism[] = {
 "7.7.0",
"kir23_lts_ptr",
 "gbar_kir23_lts_ptr",
 "modACh_kir23_lts_ptr",
 "maxModACh_kir23_lts_ptr",
 0,
 "ik_kir23_lts_ptr",
 "gk_kir23_lts_ptr",
 0,
 "m_kir23_lts_ptr",
 0,
 "levelACh_kir23_lts_ptr",
 0};
 static Symbol* _k_sym;
 
extern Prop* need_memb(Symbol*);

static void nrn_alloc(Prop* _prop) {
	Prop *prop_ion;
	double *_p; Datum *_ppvar;
 	_p = nrn_prop_data_alloc(_mechtype, 11, _prop);
 	/*initialize range parameters*/
 	gbar = 0;
 	modACh = 0;
 	maxModACh = 1;
 	_prop->param = _p;
 	_prop->param_size = 11;
 	_ppvar = nrn_prop_datum_alloc(_mechtype, 5, _prop);
 	_prop->dparam = _ppvar;
 	/*connect ionic variables to this model*/
 prop_ion = need_memb(_k_sym);
 nrn_promote(prop_ion, 0, 1);
 	_ppvar[0]._pval = &prop_ion->param[0]; /* ek */
 	_ppvar[1]._pval = &prop_ion->param[3]; /* ik */
 	_ppvar[2]._pval = &prop_ion->param[4]; /* _ion_dikdv */
 
}
 static void _initlists();
  /* some states have an absolute tolerance */
 static Symbol** _atollist;
 static HocStateTolerance _hoc_state_tol[] = {
 0,0
};
 static void _update_ion_pointer(Datum*);
 extern Symbol* hoc_lookup(const char*);
extern void _nrn_thread_reg(int, int, void(*)(Datum*));
extern void _nrn_thread_table_reg(int, void(*)(double*, Datum*, Datum*, _NrnThread*, int));
extern void hoc_register_tolerance(int, HocStateTolerance*, Symbol***);
extern void _cvode_abstol( Symbol**, double*, int);

 void _kir23_lts_ptr_reg() {
	int _vectorized = 0;
  _initlists();
 	ion_reg("k", -10000.);
 	_k_sym = hoc_lookup("k_ion");
 	register_mech(_mechanism, nrn_alloc,nrn_cur, nrn_jacob, nrn_state, nrn_init, hoc_nrnpointerindex, 0);
 _mechtype = nrn_get_mechtype(_mechanism[1]);
     _nrn_setdata_reg(_mechtype, _setdata);
     _nrn_thread_reg(_mechtype, 2, _update_ion_pointer);
 #if NMODL_TEXT
  hoc_reg_nmodl_text(_mechtype, nmodl_file_text);
  hoc_reg_nmodl_filename(_mechtype, nmodl_filename);
#endif
  hoc_register_prop_size(_mechtype, 11, 5);
  hoc_register_dparam_semantics(_mechtype, 0, "k_ion");
  hoc_register_dparam_semantics(_mechtype, 1, "k_ion");
  hoc_register_dparam_semantics(_mechtype, 2, "k_ion");
  hoc_register_dparam_semantics(_mechtype, 3, "pointer");
  hoc_register_dparam_semantics(_mechtype, 4, "cvodeieq");
 	hoc_register_cvode(_mechtype, _ode_count, _ode_map, _ode_spec, _ode_matsol);
 	hoc_register_tolerance(_mechtype, _hoc_state_tol, &_atollist);
 	hoc_register_var(hoc_scdoub, hoc_vdoub, hoc_intfunc);
 	ivoc_help("help ?1 kir23_lts_ptr /home/jofrony/Documents/Repositories/BasalGangliaExperiments/Neuromodulation/striatal_network/synapse-wide/Experiment-Simulation/x86_64/kir23_lts_ptr.mod\n");
 hoc_register_limits(_mechtype, _hoc_parm_limits);
 hoc_register_units(_mechtype, _hoc_parm_units);
 }
static int _reset;
static char *modelname = "Noninactivating inwardly rectifying potassium current (Kir2.3)";

static int error;
static int _ninits = 0;
static int _match_recurse=1;
static void _modl_cleanup(){ _match_recurse=1;}
static int rates();
 
static int _ode_spec1(_threadargsproto_);
/*static int _ode_matsol1(_threadargsproto_);*/
 static int _slist1[1], _dlist1[1];
 static int states(_threadargsproto_);
 
/*CVODE*/
 static int _ode_spec1 () {_reset=0;
 {
   rates ( _threadargs_ ) ;
   Dm = ( minf - m ) / mtau * q ;
   }
 return _reset;
}
 static int _ode_matsol1 () {
 rates ( _threadargs_ ) ;
 Dm = Dm  / (1. - dt*( ( ( ( ( - 1.0 ) ) ) / mtau )*( q ) )) ;
  return 0;
}
 /*END CVODE*/
 static int states () {_reset=0;
 {
   rates ( _threadargs_ ) ;
    m = m + (1. - exp(dt*(( ( ( ( - 1.0 ) ) ) / mtau )*( q ))))*(- ( ( ( ( minf ) ) / mtau )*( q ) ) / ( ( ( ( ( - 1.0 ) ) ) / mtau )*( q ) ) - m) ;
   }
  return 0;
}
 
static int  rates (  ) {
    minf = 1.0 / ( 1.0 + exp ( ( v - ( - 82.0 ) ) / 13.0 ) ) ;
   mtau = 1.0 / ( exp ( ( v - ( - 97.3 ) ) / ( - 12.6 ) ) + exp ( ( v - 96.3 ) / 47.0 ) ) ;
     return 0; }
 
static void _hoc_rates(void) {
  double _r;
   _r = 1.;
 rates (  );
 hoc_retpushx(_r);
}
 
double modulationACh (  ) {
   double _lmodulationACh;
 _lmodulationACh = 1.0 + modACh * ( maxModACh - 1.0 ) * levelACh ;
   
return _lmodulationACh;
 }
 
static void _hoc_modulationACh(void) {
  double _r;
   _r =  modulationACh (  );
 hoc_retpushx(_r);
}
 
static int _ode_count(int _type){ return 1;}
 
static void _ode_spec(_NrnThread* _nt, _Memb_list* _ml, int _type) {
   Datum* _thread;
   Node* _nd; double _v; int _iml, _cntml;
  _cntml = _ml->_nodecount;
  _thread = _ml->_thread;
  for (_iml = 0; _iml < _cntml; ++_iml) {
    _p = _ml->_data[_iml]; _ppvar = _ml->_pdata[_iml];
    _nd = _ml->_nodelist[_iml];
    v = NODEV(_nd);
  ek = _ion_ek;
     _ode_spec1 ();
  }}
 
static void _ode_map(int _ieq, double** _pv, double** _pvdot, double* _pp, Datum* _ppd, double* _atol, int _type) { 
 	int _i; _p = _pp; _ppvar = _ppd;
	_cvode_ieq = _ieq;
	for (_i=0; _i < 1; ++_i) {
		_pv[_i] = _pp + _slist1[_i];  _pvdot[_i] = _pp + _dlist1[_i];
		_cvode_abstol(_atollist, _atol, _i);
	}
 }
 
static void _ode_matsol_instance1(_threadargsproto_) {
 _ode_matsol1 ();
 }
 
static void _ode_matsol(_NrnThread* _nt, _Memb_list* _ml, int _type) {
   Datum* _thread;
   Node* _nd; double _v; int _iml, _cntml;
  _cntml = _ml->_nodecount;
  _thread = _ml->_thread;
  for (_iml = 0; _iml < _cntml; ++_iml) {
    _p = _ml->_data[_iml]; _ppvar = _ml->_pdata[_iml];
    _nd = _ml->_nodelist[_iml];
    v = NODEV(_nd);
  ek = _ion_ek;
 _ode_matsol_instance1(_threadargs_);
 }}
 extern void nrn_update_ion_pointer(Symbol*, Datum*, int, int);
 static void _update_ion_pointer(Datum* _ppvar) {
   nrn_update_ion_pointer(_k_sym, _ppvar, 0, 0);
   nrn_update_ion_pointer(_k_sym, _ppvar, 1, 3);
   nrn_update_ion_pointer(_k_sym, _ppvar, 2, 4);
 }

static void initmodel() {
  int _i; double _save;_ninits++;
 _save = t;
 t = 0.0;
{
  m = m0;
 {
   rates ( _threadargs_ ) ;
   m = minf ;
   }
  _sav_indep = t; t = _save;

}
}

static void nrn_init(_NrnThread* _nt, _Memb_list* _ml, int _type){
Node *_nd; double _v; int* _ni; int _iml, _cntml;
#if CACHEVEC
    _ni = _ml->_nodeindices;
#endif
_cntml = _ml->_nodecount;
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
  ek = _ion_ek;
 initmodel();
 }}

static double _nrn_current(double _v){double _current=0.;v=_v;{ {
   gk = gbar * m * modulationACh ( _threadargs_ ) ;
   ik = gk * ( v - ek ) ;
   }
 _current += ik;

} return _current;
}

static void nrn_cur(_NrnThread* _nt, _Memb_list* _ml, int _type){
Node *_nd; int* _ni; double _rhs, _v; int _iml, _cntml;
#if CACHEVEC
    _ni = _ml->_nodeindices;
#endif
_cntml = _ml->_nodecount;
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
  ek = _ion_ek;
 _g = _nrn_current(_v + .001);
 	{ double _dik;
  _dik = ik;
 _rhs = _nrn_current(_v);
  _ion_dikdv += (_dik - ik)/.001 ;
 	}
 _g = (_g - _rhs)/.001;
  _ion_ik += ik ;
#if CACHEVEC
  if (use_cachevec) {
	VEC_RHS(_ni[_iml]) -= _rhs;
  }else
#endif
  {
	NODERHS(_nd) -= _rhs;
  }
 
}}

static void nrn_jacob(_NrnThread* _nt, _Memb_list* _ml, int _type){
Node *_nd; int* _ni; int _iml, _cntml;
#if CACHEVEC
    _ni = _ml->_nodeindices;
#endif
_cntml = _ml->_nodecount;
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
 
}}

static void nrn_state(_NrnThread* _nt, _Memb_list* _ml, int _type){
Node *_nd; double _v = 0.0; int* _ni; int _iml, _cntml;
#if CACHEVEC
    _ni = _ml->_nodeindices;
#endif
_cntml = _ml->_nodecount;
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
  ek = _ion_ek;
 { error =  states();
 if(error){fprintf(stderr,"at line 66 in file kir23_lts_ptr.mod:\n    SOLVE states METHOD cnexp\n"); nrn_complain(_p); abort_run(error);}
 } }}

}

static void terminal(){}

static void _initlists() {
 int _i; static int _first = 1;
  if (!_first) return;
 _slist1[0] = &(m) - _p;  _dlist1[0] = &(Dm) - _p;
_first = 0;
}

#if NMODL_TEXT
static const char* nmodl_filename = "/home/jofrony/Documents/Repositories/BasalGangliaData/mod-ptr-files/kir23_lts_ptr.mod";
static const char* nmodl_file_text = 
  "TITLE Noninactivating inwardly rectifying potassium current (Kir2.3)\n"
  "\n"
  "COMMENT\n"
  "\n"
  "Neuromodulation is added as functions:\n"
  "    \n"
  "    modulationDA = 1 + modDA*(maxModDA-1)*levelDA\n"
  "\n"
  "where:\n"
  "    \n"
  "    modDA  [0]: is a switch for turning modulation on or off {1/0}\n"
  "    maxModDA [1]: is the maximum modulation for this specific channel (read from the param file)\n"
  "                    e.g. 10% increase would correspond to a factor of 1.1 (100% +10%) {0-inf}\n"
  "    levelDA  [0]: is an additional parameter for scaling modulation. \n"
  "                Can be used simulate non static modulation by gradually changing the value from 0 to 1 {0-1}\n"
  "									\n"
  "	  Further neuromodulators can be added by for example:\n"
  "          modulationDA = 1 + modDA*(maxModDA-1)\n"
  "	  modulationACh = 1 + modACh*(maxModACh-1)\n"
  "	  ....\n"
  "\n"
  "	  etc. for other neuromodulators\n"
  "	  \n"
  "	   \n"
  "								     \n"
  "[] == default values\n"
  "{} == ranges\n"
  "    \n"
  "ENDCOMMENT\n"
  "      \n"
  "NEURON {\n"
  "\n"
  "    SUFFIX kir23_lts_ptr\n"
  "    USEION k READ ek WRITE ik\n"
  "    RANGE gbar, gk, ik\n"
  "    POINTER levelACh\n"
  "    RANGE modACh,maxModACh\n"
  "}\n"
  "\n"
  "UNITS {\n"
  "    (S) = (siemens)\n"
  "    (mV) = (millivolt)\n"
  "    (mA) = (milliamp)\n"
  "}\n"
  "\n"
  "PARAMETER {\n"
  "    gbar = 0.0 (S/cm2) \n"
  "    q = 1	: body temperature 35 C\n"
  "    modACh = 0\n"
  "    maxModACh = 1 \n"
  "    levelACh = 0\n"
  "}\n"
  "\n"
  "ASSIGNED {\n"
  "    v (mV)\n"
  "    ek (mV)\n"
  "    ik (mA/cm2)\n"
  "    gk (S/cm2)\n"
  "    minf\n"
  "    mtau (ms)\n"
  "}\n"
  "\n"
  "STATE { m }\n"
  "\n"
  "BREAKPOINT {\n"
  "    SOLVE states METHOD cnexp\n"
  "    gk = gbar*m*modulationACh()\n"
  "    ik = gk*(v-ek)\n"
  "}\n"
  "\n"
  "DERIVATIVE states {\n"
  "    rates()\n"
  "    m' = (minf-m)/mtau*q\n"
  "}\n"
  "\n"
  "INITIAL {\n"
  "    rates()\n"
  "    m = minf\n"
  "}\n"
  "\n"
  "PROCEDURE rates() {\n"
  "    UNITSOFF\n"
  "    minf = 1/(1+exp((v-(-82))/13))\n"
  "    :mtau = 1/(2*exp((v-(-106))/(-12.6))+0.086*exp((v-(-19))/47))  : Steephen (2009)\n"
  "    mtau = 1/(exp((v-(-97.3))/(-12.6))+exp((v-96.3)/47))  : Steephen (2009)\n"
  "    UNITSON\n"
  "}\n"
  "\n"
  "FUNCTION modulationACh() {\n"
  "    : returns modulation factor\n"
  "    \n"
  "    modulationACh = 1 + modACh*(maxModACh-1)*levelACh \n"
  "}\n"
  "\n"
  "COMMENT\n"
  "\n"
  "Original model by Wolf et al (2005) [1] for the rat MSN cells from the\n"
  "nucleus accumbens.  The activation curve was fitted to a mouse Kir2.1\n"
  "channel expressed in HEK cells [2] and shifted to match extracellular\n"
  "concentration of K in rat.  Time constants were derived from Aplysia\n"
  "data [3] and adjusted to match the rat experiments [1]. Time constant\n"
  "was further tuned [4] to fit the rat data below -80 mV [5].\n"
  "\n"
  "Non-inactivating component of the Kir channel with m1 kinetics is used\n"
  "[1,4].  Kinetics is corrected to the body temperature 35 C.\n"
  "\n"
  "Smooth fit of the time constants by Alexander Kozlov <akozlov@kth.se>.\n"
  "\n"
  "[1] Wolf JA, Moyer JT, Lazarewicz MT, Contreras D, Benoit-Marand M,\n"
  "O'Donnell P, Finkel LH (2005) NMDA/AMPA ratio impacts state transitions\n"
  "and entrainment to oscillations in a computational model of the nucleus\n"
  "accumbens medium spiny projection neuron. J Neurosci 25(40):9080-95.\n"
  "\n"
  "[2] Kubo Y, Murata Y (2001) Control of rectification and permeation by\n"
  "two distinct sites after the second transmembrane region in Kir2.1 K+\n"
  "channel. J Physiol 531, 645-660.\n"
  "\n"
  "[3] Hayashi H, Fishman HM (1988) Inward rectifier K+ channel kinetics\n"
  "from analysis of the complex conductance of aplysia neuronal membrane.\n"
  "Biophys J 53, 747-757.\n"
  "\n"
  "[4] Steephen JE, Manchanda R (2009) Differences in biophysical properties\n"
  "of nucleus accumbens medium spiny neurons emerging from inactivation of\n"
  "inward rectifying potassium currents. J Comput Neurosci 27(3):453-70\n"
  "\n"
  "[5] Mermelstein PG, Song WJ, Tkatch T, Yan Z, Surmeier DJ (1998)\n"
  "Inwardly rectifying potassium (IRK) currents are correlated with IRK\n"
  "subunit expression in rat nucleus accumbens medium spiny neurons. J\n"
  "Neurosci 18(17):6650-61.\n"
  "\n"
  "ENDCOMMENT\n"
  ;
#endif