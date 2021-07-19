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
 
#define nrn_init _nrn_init__kaf_ms_p
#define _nrn_initial _nrn_initial__kaf_ms_p
#define nrn_cur _nrn_cur__kaf_ms_p
#define _nrn_current _nrn_current__kaf_ms_p
#define nrn_jacob _nrn_jacob__kaf_ms_p
#define nrn_state _nrn_state__kaf_ms_p
#define _net_receive _net_receive__kaf_ms_p 
#define rates rates__kaf_ms_p 
#define states states__kaf_ms_p 
 
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
#define q _p[1]
#define modA _p[2]
#define maxModA _p[3]
#define modShift _p[4]
#define modB _p[5]
#define maxModB _p[6]
#define ik _p[7]
#define gk _p[8]
#define m _p[9]
#define h _p[10]
#define ek _p[11]
#define minf _p[12]
#define mtau _p[13]
#define hinf _p[14]
#define htau _p[15]
#define Dm _p[16]
#define Dh _p[17]
#define _g _p[18]
#define _ion_ek	*_ppvar[0]._pval
#define _ion_ik	*_ppvar[1]._pval
#define _ion_dikdv	*_ppvar[2]._pval
#define levelA	*_ppvar[3]._pval
#define _p_levelA	_ppvar[3]._pval
#define levelB	*_ppvar[4]._pval
#define _p_levelB	_ppvar[4]._pval
 
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
 static void _hoc_modulationB(void);
 static void _hoc_modulationA(void);
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
 "setdata_kaf_ms_p", _hoc_setdata,
 "modulationB_kaf_ms_p", _hoc_modulationB,
 "modulationA_kaf_ms_p", _hoc_modulationA,
 "rates_kaf_ms_p", _hoc_rates,
 0, 0
};
#define modulationB modulationB_kaf_ms_p
#define modulationA modulationA_kaf_ms_p
 extern double modulationB( );
 extern double modulationA( );
 /* declare global and static user variables */
 /* some parameters have upper and lower limits */
 static HocParmLimits _hoc_parm_limits[] = {
 0,0,0
};
 static HocParmUnits _hoc_parm_units[] = {
 "gbar_kaf_ms_p", "S/cm2",
 "ik_kaf_ms_p", "mA/cm2",
 "gk_kaf_ms_p", "S/cm2",
 0,0
};
 static double delta_t = 0.01;
 static double h0 = 0;
 static double m0 = 0;
 static double v = 0;
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
 
static int _ode_count(int);
static void _ode_map(int, double**, double**, double*, Datum*, double*, int);
static void _ode_spec(_NrnThread*, _Memb_list*, int);
static void _ode_matsol(_NrnThread*, _Memb_list*, int);
 
#define _cvode_ieq _ppvar[5]._i
 static void _ode_matsol_instance1(_threadargsproto_);
 /* connect range variables in _p that hoc is supposed to know about */
 static const char *_mechanism[] = {
 "7.7.0",
"kaf_ms_p",
 "gbar_kaf_ms_p",
 "q_kaf_ms_p",
 "modA_kaf_ms_p",
 "maxModA_kaf_ms_p",
 "modShift_kaf_ms_p",
 "modB_kaf_ms_p",
 "maxModB_kaf_ms_p",
 0,
 "ik_kaf_ms_p",
 "gk_kaf_ms_p",
 0,
 "m_kaf_ms_p",
 "h_kaf_ms_p",
 0,
 "levelA_kaf_ms_p",
 "levelB_kaf_ms_p",
 0};
 static Symbol* _k_sym;
 
extern Prop* need_memb(Symbol*);

static void nrn_alloc(Prop* _prop) {
	Prop *prop_ion;
	double *_p; Datum *_ppvar;
 	_p = nrn_prop_data_alloc(_mechtype, 19, _prop);
 	/*initialize range parameters*/
 	gbar = 0;
 	q = 1;
 	modA = 0;
 	maxModA = 1;
 	modShift = 0;
 	modB = 0;
 	maxModB = 1;
 	_prop->param = _p;
 	_prop->param_size = 19;
 	_ppvar = nrn_prop_datum_alloc(_mechtype, 6, _prop);
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

 void _kaf_ms_p_reg() {
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
  hoc_register_prop_size(_mechtype, 19, 6);
  hoc_register_dparam_semantics(_mechtype, 0, "k_ion");
  hoc_register_dparam_semantics(_mechtype, 1, "k_ion");
  hoc_register_dparam_semantics(_mechtype, 2, "k_ion");
  hoc_register_dparam_semantics(_mechtype, 3, "pointer");
  hoc_register_dparam_semantics(_mechtype, 4, "pointer");
  hoc_register_dparam_semantics(_mechtype, 5, "cvodeieq");
 	hoc_register_cvode(_mechtype, _ode_count, _ode_map, _ode_spec, _ode_matsol);
 	hoc_register_tolerance(_mechtype, _hoc_state_tol, &_atollist);
 	hoc_register_var(hoc_scdoub, hoc_vdoub, hoc_intfunc);
 	ivoc_help("help ?1 kaf_ms_p /home/jofrony/Documents/Repositories/BasalGangliaExperiments/Neuromodulation-software/local/adaptive/Experiment-Simulation/x86_64/kaf_ms_p.mod\n");
 hoc_register_limits(_mechtype, _hoc_parm_limits);
 hoc_register_units(_mechtype, _hoc_parm_units);
 }
static int _reset;
static char *modelname = "Fast A-type potassium current (Kv4.2)";

static int error;
static int _ninits = 0;
static int _match_recurse=1;
static void _modl_cleanup(){ _match_recurse=1;}
static int rates();
 
static int _ode_spec1(_threadargsproto_);
/*static int _ode_matsol1(_threadargsproto_);*/
 static int _slist1[2], _dlist1[2];
 static int states(_threadargsproto_);
 
/*CVODE*/
 static int _ode_spec1 () {_reset=0;
 {
   rates ( _threadargs_ ) ;
   Dm = ( minf - m ) / mtau * q ;
   Dh = ( hinf - h ) / htau * q ;
   }
 return _reset;
}
 static int _ode_matsol1 () {
 rates ( _threadargs_ ) ;
 Dm = Dm  / (1. - dt*( ( ( ( ( - 1.0 ) ) ) / mtau )*( q ) )) ;
 Dh = Dh  / (1. - dt*( ( ( ( ( - 1.0 ) ) ) / htau )*( q ) )) ;
  return 0;
}
 /*END CVODE*/
 static int states () {_reset=0;
 {
   rates ( _threadargs_ ) ;
    m = m + (1. - exp(dt*(( ( ( ( - 1.0 ) ) ) / mtau )*( q ))))*(- ( ( ( ( minf ) ) / mtau )*( q ) ) / ( ( ( ( ( - 1.0 ) ) ) / mtau )*( q ) ) - m) ;
    h = h + (1. - exp(dt*(( ( ( ( - 1.0 ) ) ) / htau )*( q ))))*(- ( ( ( ( hinf ) ) / htau )*( q ) ) / ( ( ( ( ( - 1.0 ) ) ) / htau )*( q ) ) - h) ;
   }
  return 0;
}
 
static int  rates (  ) {
    minf = 1.0 / ( 1.0 + exp ( ( v - ( - 10.0 + modShift ) ) / ( - 17.7 ) ) ) ;
   mtau = 0.9 + 1.1 / ( 1.0 + exp ( ( v - ( - 30.0 ) ) / 10.0 ) ) ;
   hinf = 1.0 / ( 1.0 + exp ( ( v - ( - 75.6 ) ) / 11.8 ) ) ;
   htau = 14.0 ;
     return 0; }
 
static void _hoc_rates(void) {
  double _r;
   _r = 1.;
 rates (  );
 hoc_retpushx(_r);
}
 
double modulationA (  ) {
   double _lmodulationA;
 _lmodulationA = 1.0 + modA * ( maxModA - 1.0 ) * levelA ;
   
return _lmodulationA;
 }
 
static void _hoc_modulationA(void) {
  double _r;
   _r =  modulationA (  );
 hoc_retpushx(_r);
}
 
double modulationB (  ) {
   double _lmodulationB;
 _lmodulationB = 1.0 + modB * ( maxModB - 1.0 ) * levelB ;
   
return _lmodulationB;
 }
 
static void _hoc_modulationB(void) {
  double _r;
   _r =  modulationB (  );
 hoc_retpushx(_r);
}
 
static int _ode_count(int _type){ return 2;}
 
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
	for (_i=0; _i < 2; ++_i) {
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
  h = h0;
  m = m0;
 {
   rates ( _threadargs_ ) ;
   m = minf ;
   h = hinf ;
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
   gk = gbar * m * m * h * modulationA ( _threadargs_ ) ;
   modShift = modulationB ( _threadargs_ ) ;
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
 if(error){fprintf(stderr,"at line 78 in file kaf_ms_p.mod:\n    SOLVE states METHOD cnexp\n"); nrn_complain(_p); abort_run(error);}
 } }}

}

static void terminal(){}

static void _initlists() {
 int _i; static int _first = 1;
  if (!_first) return;
 _slist1[0] = &(m) - _p;  _dlist1[0] = &(Dm) - _p;
 _slist1[1] = &(h) - _p;  _dlist1[1] = &(Dh) - _p;
_first = 0;
}

#if NMODL_TEXT
static const char* nmodl_filename = "/home/jofrony/Documents/Repositories/BasalGangliaExperiments/Neuromodulation-software/local/adaptive/Experiment-Simulation/mechanisms-ptr/kaf_ms_p.mod";
static const char* nmodl_file_text = 
  "TITLE Fast A-type potassium current (Kv4.2)\n"
  "\n"
  "COMMENT\n"
  "\n"
  "Neuromodulation is added as functions:\n"
  "    \n"
  "    modulationA = 1 + modA*(maxModA-1)*levelA\n"
  "\n"
  "where:\n"
  "    \n"
  "    modA  [0]: is a switch for turning modulation on or off {1/0}\n"
  "    maxModA [1]: is the maximum modulation for this specific channel (read from the param file)\n"
  "                    e.g. 10% increase would correspond to a factor of 1.1 (100% +10%) {0-inf}\n"
  "    levelA  [0]: is an additional parameter for scaling modulation. \n"
  "                Can be used simulate non static modulation by gradually changing the value from 0 to 1 {0-1}\n"
  "									\n"
  "	  Further neuromodulators can be added by for example:\n"
  "          modulationA = 1 + modA*(maxModA-1)\n"
  "	  modulationB = 1 + modB*(maxModB-1)\n"
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
  "\n"
  "\n"
  "NEURON {\n"
  "    SUFFIX kaf_ms_p\n"
  "    USEION k READ ek WRITE ik\n"
  "    RANGE gbar, gk, ik, q\n"
  "    RANGE modA, maxModA, modB, maxModB\n"
  "    RANGE modShift\n"
  "    POINTER levelA,levelB\n"
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
  "    q = 1	: room temperature (unspecified)\n"
  "    :q = 2	: body temperature 35 C (Du 2017)\n"
  "    :q = 3	: body temperature 35 C\n"
  "    modA = 0\n"
  "    maxModA = 1\n"
  "    levelA = 0\n"
  "    modShift = 0\n"
  "    modB = 0\n"
  "    maxModB = 1\n"
  "    levelB = 0\n"
  "\n"
  "\n"
  "\n"
  "}\n"
  "\n"
  "ASSIGNED {\n"
  "    v (mV)\n"
  "    ek (mV)\n"
  "    ik (mA/cm2)\n"
  "    gk (S/cm2)\n"
  "    minf\n"
  "    mtau (ms)\n"
  "    hinf\n"
  "    htau (ms)\n"
  "}\n"
  "\n"
  "STATE { m h }\n"
  "\n"
  "BREAKPOINT {\n"
  "    SOLVE states METHOD cnexp\n"
  "    gk = gbar*m*m*h*modulationA()\n"
  "    modShift = modulationB()				     \n"
  "    ik = gk*(v-ek)\n"
  "}\n"
  "\n"
  "DERIVATIVE states {\n"
  "    rates()\n"
  "    m' = (minf-m)/mtau*q\n"
  "    h' = (hinf-h)/htau*q\n"
  "}\n"
  "\n"
  "INITIAL {\n"
  "    rates()\n"
  "    m = minf\n"
  "    h = hinf\n"
  "}\n"
  "\n"
  "PROCEDURE rates() {\n"
  "    UNITSOFF\n"
  "    minf = 1/(1+exp((v-(-10+modShift))/(-17.7)))\n"
  "    mtau = 0.9+1.1/(1+exp((v-(-30))/10))\n"
  "    hinf = 1/(1+exp((v-(-75.6))/11.8))\n"
  "    htau = 14\n"
  "    UNITSON\n"
  "\n"
  "    :Du 2017\n"
  "    :LOCAL alpha, beta, sum\n"
  "    :UNITSOFF\n"
  "    :alpha = 1.5/(1+exp((v-4)/(-17)))\n"
  "    :beta = 0.6/(1+exp((v-10)/9))\n"
  "    :sum = alpha+beta\n"
  "    :minf = alpha/sum\n"
  "    :mtau = 1/sum\n"
  "    :\n"
  "    :alpha = 0.105/(1+exp((v-(-121))/22))\n"
  "    :beta = 0.065/(1+exp((v-(-55))/(-11)))\n"
  "    :sum = alpha+beta\n"
  "    :hinf = alpha/sum\n"
  "    :htau = 1/sum\n"
  "    :UNITSON\n"
  "}\n"
  "\n"
  "\n"
  "FUNCTION modulationA() {\n"
  "    : returns modulation factor\n"
  "    \n"
  "    modulationA = 1 + modA*(maxModA-1)*levelA \n"
  "}\n"
  "\n"
  "FUNCTION modulationB() {\n"
  "    : returns modulation factor\n"
  "    \n"
  "    modulationB = 1 + modB*(maxModB-1)*levelB \n"
  "}\n"
  "\n"
  "COMMENT\n"
  "\n"
  "Original data by Tkatch et al (2000) [1]. Neostriatal neurons were acutely\n"
  "dissociated from young adult rats, age P28-P42.  Electrophysiological\n"
  "recordings were done at unspecified temperature (room temperature 20-22 C\n"
  "assumed). Potentials were not corrected for the liquid junction potential\n"
  "(estimated 1-2 mV).\n"
  "\n"
  "Activation m^1 matches experimental data [1, Fig.2C]. Activation time\n"
  "constants fit tabulated data [1, Fig.2B].  Slope of inactivation function\n"
  "fitted to the data [1, Fig.3B] with half inactivation potential -75.6\n"
  "mV. Temperature factor q between 1.5 [3] and 3 [2] was used for body\n"
  "temperature.  Conductance kinetics of m2h type is used [2], no corrections\n"
  "for m^2 applied. Later modification by Du [4] is close to this model.\n"
  "\n"
  "[1] Tkatch T, Baranauskas G, Surmeier DJ (2000) Kv4.2 mRNA abundance and\n"
  "A-type K(+) current amplitude are linearly related in basal ganglia and\n"
  "basal forebrain neurons. J Neurosci 20(2):579-88.\n"
  "\n"
  "[2] Wolf JA, Moyer JT, Lazarewicz MT, Contreras D, Benoit-Marand M,\n"
  "O'Donnell P, Finkel LH (2005) NMDA/AMPA ratio impacts state transitions\n"
  "and entrainment to oscillations in a computational model of the nucleus\n"
  "accumbens medium spiny projection neuron. J Neurosci 25(40):9080-95.\n"
  "\n"
  "[3]  Evans RC, Morera-Herreras T, Cui Y, Du K, Sheehan T, Kotaleski JH,\n"
  "Venance L, Blackwell KT (2012) The effects of NMDA subunit composition on\n"
  "calcium influx and spike timing-dependent plasticity in striatal medium\n"
  "spiny neurons. PLoS Comput Biol 8(4):e1002493.\n"
  "\n"
  "[4] Du K, Wu YW, Lindroos R, Liu Y, R\n"
  "\n"
  "zsa B, Katona G, Ding JB,\n"
  "Kotaleski JH (2017) Cell-type-specific inhibition of the dendritic\n"
  "plateau potential in striatal spiny projection neurons. Proc Natl Acad\n"
  "Sci USA 114:E7612-E7621.\n"
  "\n"
  "ENDCOMMENT\n"
  ;
#endif
