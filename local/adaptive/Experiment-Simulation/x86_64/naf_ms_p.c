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
 
#define nrn_init _nrn_init__naf_ms_p
#define _nrn_initial _nrn_initial__naf_ms_p
#define nrn_cur _nrn_cur__naf_ms_p
#define _nrn_current _nrn_current__naf_ms_p
#define nrn_jacob _nrn_jacob__naf_ms_p
#define nrn_state _nrn_state__naf_ms_p
#define _net_receive _net_receive__naf_ms_p 
#define rates rates__naf_ms_p 
#define states states__naf_ms_p 
 
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
#define modA _p[1]
#define maxModA _p[2]
#define modB _p[3]
#define maxModB _p[4]
#define ina _p[5]
#define gna _p[6]
#define m _p[7]
#define h _p[8]
#define ena _p[9]
#define minf _p[10]
#define mtau _p[11]
#define hinf _p[12]
#define htau _p[13]
#define Dm _p[14]
#define Dh _p[15]
#define _g _p[16]
#define _ion_ena	*_ppvar[0]._pval
#define _ion_ina	*_ppvar[1]._pval
#define _ion_dinadv	*_ppvar[2]._pval
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
 "setdata_naf_ms_p", _hoc_setdata,
 "modulationB_naf_ms_p", _hoc_modulationB,
 "modulationA_naf_ms_p", _hoc_modulationA,
 "rates_naf_ms_p", _hoc_rates,
 0, 0
};
#define modulationB modulationB_naf_ms_p
#define modulationA modulationA_naf_ms_p
 extern double modulationB( );
 extern double modulationA( );
 /* declare global and static user variables */
#define q q_naf_ms_p
 double q = 1.8;
 /* some parameters have upper and lower limits */
 static HocParmLimits _hoc_parm_limits[] = {
 0,0,0
};
 static HocParmUnits _hoc_parm_units[] = {
 "gbar_naf_ms_p", "S/cm2",
 "ina_naf_ms_p", "mA/cm2",
 "gna_naf_ms_p", "S/cm2",
 0,0
};
 static double delta_t = 0.01;
 static double h0 = 0;
 static double m0 = 0;
 static double v = 0;
 /* connect global user variables to hoc */
 static DoubScal hoc_scdoub[] = {
 "q_naf_ms_p", &q_naf_ms_p,
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
"naf_ms_p",
 "gbar_naf_ms_p",
 "modA_naf_ms_p",
 "maxModA_naf_ms_p",
 "modB_naf_ms_p",
 "maxModB_naf_ms_p",
 0,
 "ina_naf_ms_p",
 "gna_naf_ms_p",
 0,
 "m_naf_ms_p",
 "h_naf_ms_p",
 0,
 "levelA_naf_ms_p",
 "levelB_naf_ms_p",
 0};
 static Symbol* _na_sym;
 
extern Prop* need_memb(Symbol*);

static void nrn_alloc(Prop* _prop) {
	Prop *prop_ion;
	double *_p; Datum *_ppvar;
 	_p = nrn_prop_data_alloc(_mechtype, 17, _prop);
 	/*initialize range parameters*/
 	gbar = 0;
 	modA = 0;
 	maxModA = 1;
 	modB = 0;
 	maxModB = 1;
 	_prop->param = _p;
 	_prop->param_size = 17;
 	_ppvar = nrn_prop_datum_alloc(_mechtype, 6, _prop);
 	_prop->dparam = _ppvar;
 	/*connect ionic variables to this model*/
 prop_ion = need_memb(_na_sym);
 nrn_promote(prop_ion, 0, 1);
 	_ppvar[0]._pval = &prop_ion->param[0]; /* ena */
 	_ppvar[1]._pval = &prop_ion->param[3]; /* ina */
 	_ppvar[2]._pval = &prop_ion->param[4]; /* _ion_dinadv */
 
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

 void _naf_ms_p_reg() {
	int _vectorized = 0;
  _initlists();
 	ion_reg("na", -10000.);
 	_na_sym = hoc_lookup("na_ion");
 	register_mech(_mechanism, nrn_alloc,nrn_cur, nrn_jacob, nrn_state, nrn_init, hoc_nrnpointerindex, 0);
 _mechtype = nrn_get_mechtype(_mechanism[1]);
     _nrn_setdata_reg(_mechtype, _setdata);
     _nrn_thread_reg(_mechtype, 2, _update_ion_pointer);
 #if NMODL_TEXT
  hoc_reg_nmodl_text(_mechtype, nmodl_file_text);
  hoc_reg_nmodl_filename(_mechtype, nmodl_filename);
#endif
  hoc_register_prop_size(_mechtype, 17, 6);
  hoc_register_dparam_semantics(_mechtype, 0, "na_ion");
  hoc_register_dparam_semantics(_mechtype, 1, "na_ion");
  hoc_register_dparam_semantics(_mechtype, 2, "na_ion");
  hoc_register_dparam_semantics(_mechtype, 3, "pointer");
  hoc_register_dparam_semantics(_mechtype, 4, "pointer");
  hoc_register_dparam_semantics(_mechtype, 5, "cvodeieq");
 	hoc_register_cvode(_mechtype, _ode_count, _ode_map, _ode_spec, _ode_matsol);
 	hoc_register_tolerance(_mechtype, _hoc_state_tol, &_atollist);
 	hoc_register_var(hoc_scdoub, hoc_vdoub, hoc_intfunc);
 	ivoc_help("help ?1 naf_ms_p /home/jofrony/Documents/Repositories/BasalGangliaExperiments/Neuromodulation-software/local/adaptive/Experiment-Simulation/x86_64/naf_ms_p.mod\n");
 hoc_register_limits(_mechtype, _hoc_parm_limits);
 hoc_register_units(_mechtype, _hoc_parm_units);
 }
static int _reset;
static char *modelname = "Fast transient sodium current";

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
    minf = 1.0 / ( 1.0 + exp ( ( v - ( - 25.0 ) ) / ( - 10.0 ) ) ) ;
   mtau = 0.33 + 1.0 / ( exp ( ( v - ( - 62.0 ) ) / 14.0 ) + exp ( ( v - ( - 60.0 ) ) / ( - 17.0 ) ) ) ;
   hinf = 1.0 / ( 1.0 + exp ( ( v - ( - 62.0 ) ) / 6.0 ) ) ;
   htau = 0.6 + 1.0 / ( exp ( ( v - ( - 44.0 ) ) / 8.0 ) + exp ( ( v - ( - 99.0 ) ) / ( - 44.0 ) ) ) ;
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
  ena = _ion_ena;
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
  ena = _ion_ena;
 _ode_matsol_instance1(_threadargs_);
 }}
 extern void nrn_update_ion_pointer(Symbol*, Datum*, int, int);
 static void _update_ion_pointer(Datum* _ppvar) {
   nrn_update_ion_pointer(_na_sym, _ppvar, 0, 0);
   nrn_update_ion_pointer(_na_sym, _ppvar, 1, 3);
   nrn_update_ion_pointer(_na_sym, _ppvar, 2, 4);
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
  ena = _ion_ena;
 initmodel();
 }}

static double _nrn_current(double _v){double _current=0.;v=_v;{ {
   gna = gbar * m * m * m * h * modulationA ( _threadargs_ ) * modulationB ( _threadargs_ ) ;
   ina = gna * ( v - ena ) ;
   }
 _current += ina;

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
  ena = _ion_ena;
 _g = _nrn_current(_v + .001);
 	{ double _dina;
  _dina = ina;
 _rhs = _nrn_current(_v);
  _ion_dinadv += (_dina - ina)/.001 ;
 	}
 _g = (_g - _rhs)/.001;
  _ion_ina += ina ;
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
  ena = _ion_ena;
 { error =  states();
 if(error){fprintf(stderr,"at line 71 in file naf_ms_p.mod:\n    SOLVE states METHOD cnexp\n"); nrn_complain(_p); abort_run(error);}
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
static const char* nmodl_filename = "/home/jofrony/Documents/Repositories/BasalGangliaExperiments/Neuromodulation-software/local/adaptive/Experiment-Simulation/mechanisms-ptr/naf_ms_p.mod";
static const char* nmodl_file_text = 
  "TITLE Fast transient sodium current\n"
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
  "\n"
  "ENDCOMMENT\n"
  "\n"
  "NEURON {\n"
  "    SUFFIX naf_ms_p\n"
  "    USEION na READ ena WRITE ina\n"
  "    RANGE gbar, gna, ina\n"
  "    RANGE modA, maxModA, modB, maxModB\n"
  "    POINTER levelA, levelB\n"
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
  "    :q = 1	: room temperature 22 C\n"
  "    q = 1.8	: body temperature 35 C\n"
  "    modA = 0\n"
  "    maxModA = 1\n"
  "    levelA = 0\n"
  "    modB = 0\n"
  "    maxModB = 1 \n"
  "    levelB = 0\n"
  "}\n"
  "\n"
  "ASSIGNED {\n"
  "    v (mV)\n"
  "    ena (mV)\n"
  "    ina (mA/cm2)\n"
  "    gna (S/cm2)\n"
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
  "    gna = gbar*m*m*m*h*modulationA()*modulationB()\n"
  "    ina = gna*(v-ena)\n"
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
  "    :minf = 1/(1+exp((v-(-25.5))/(-9.2)))\n"
  "    :mtau = 0.33+1/(exp((v-(-62))/14)+exp((v-(-60))/(-17)))\n"
  "    :hinf = 1/(1+exp((v-(-63.2))/6))\n"
  "    :htau = 0.6+1/(exp((v-(-44))/8)+exp((v-(-99))/(-44)))\n"
  "    minf = 1/(1+exp((v-(-25))/(-10)))\n"
  "    mtau = 0.33+1/(exp((v-(-62))/14)+exp((v-(-60))/(-17)))\n"
  "    hinf = 1/(1+exp((v-(-62))/6))\n"
  "    htau = 0.6+1/(exp((v-(-44))/8)+exp((v-(-99))/(-44)))\n"
  "    UNITSON\n"
  "}\n"
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
  "Original data by Ogata and Tatebayashi (1990) [1]. Neostriatal neurons\n"
  "of medium size (putative medium spiny neurons) freshly isolated from\n"
  "the adult guinea pig brain (either sex, 200 g). Data compensated for\n"
  "the liquid junction potential (-13 mV). Experiments carried out at room\n"
  "temperature (22 C). Conductance fitted by m3h kinetics.\n"
  "\n"
  "Smooth fit of mtau and htau data [1] by Alexander Kozlov <akozlov@kth.se>\n"
  "assuming natural logarithm of tau values [1, Figs. 5 and 9] and\n"
  "temperature correction factor of 1.8 [2] as suggested by Robert Lindroos\n"
  "<robert.lindroos@ki.se>.\n"
  "\n"
  "[1] Ogata N, Tatebayashi H (1990) Sodium current kinetics in freshly\n"
  "isolated neostriatal neurones of the adult guinea pig. Pflugers Arch\n"
  "416(5):594-603.\n"
  "\n"
  "[2] Schwarz JR (1986) The effect of temperature on Na currents in rat\n"
  "myelinated nerve fibres. Pflugers Arch. 406(4):397-404.\n"
  "\n"
  "ENDCOMMENT\n"
  ;
#endif
