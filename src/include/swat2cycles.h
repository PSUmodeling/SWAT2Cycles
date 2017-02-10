#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sllist.h"

#define MAXSTRING   1024
#define AHEAD       0
#define BEHIND      1

/* Management operations */
#define END_OF_YEAR     0
#define PLANTING        1
#define IRRIGATION      2
#define FERTILIZER      3
#define PESTICIDE       4
#define HARVEST_KILL    5
#define TILLAGE         6
#define HARVEST         7
#define KILL            8
#define GRAZING         9
#define AUTO_IRR        10
#define AUTO_FERT       11
#define STREET_SWEEP    12
#define RELEASE_IMPOUND 13
#define CONT_FERT       14
#define CONT_PEST       15

/* Land cover/plant classification */
#define WARM_AN_LEGUME  1
#define COLD_AN_LEGUME  2
#define PER_LEGUME      3
#define WARM_AN         4
#define COLD_AN         5
#define PERENNIAL       6
#define TREE            7

typedef struct plant_struct
{
    int             icnum;
    char            cpnm[5];
    int             idc;
    double          bio_e;
    double          hvsti;
    double          blai;
    double          frgrw1;
    double          laimx1;
    double          frgrw2;
    double          laimx2;
    double          dlai;
    double          chtmx;
    double          rdmx;
    double          t_opt;
    double          t_base;
    double          cnyld;
    double          cpyld;
    double          pltnfr[3];
    double          pltpfr[3];
    double          wsyf;
    double          usle_c;
    double          gsi;
    double          vpdfr;
    double          frgmax;
    double          wavp;
    double          co2hi;
    double          bioehi;
    double          rsdco_pl;
    double          alai_min;
    double          bio_leaf;
    int             mat_yrs;
    double          bmx_trees;
    double          ext_coef;
    double          bmdieoff;
    int             flag;
}                   plant_struct;

typedef struct till_struct
{
    int             itnum;
    char            tillnm[9];
    double          effmix;
    double          deptil;
}                   till_struct;

typedef struct fert_struct
{
    int             ifnum;
    char            fertnm[9];
    double          fminn;
    double          fminp;
    double          forgn;
    double          forgp;
    double          fnh3n;
    double          bactpdb;
    double          bactlpdb;
    double          bactkddb;
}                   fert_struct;

typedef struct mgt_struct
{
    int             oid;
    int             subbasin;
    int             hru;
    char            landuse[5];
    char            soil[MAXSTRING];
    char            slope_cd[MAXSTRING];
    char            crop[5];
    int             year;
    int             month;
    int             day;
    double          husc;
    int             mgt_op;
    double          heatunits;
    int             plant_id;
    int             curyr_mat;
    double          lai_init;
    double          bio_init;
    double          hi_targ;
    double          bio_targ;
    double          cnop;
    double          irr_amt;
    int             fert_id;
    double          frt_kg;
    double          frt_surface;
    int             pest_id;
    double          pst_kg;
    int             tillage_id;
    double          harveff;
    double          hi_ovr;
    int             grz_days;
    int             manure_id;
    double          bio_eat;
    double          bio_trmp;
    double          manure_kg;
    int             wstrs_id;
    double          auto_wstrs;
    int             afert_id;
    double          auto_nstrs;
    double          auto_napp;
    double          auto_nyr;
    double          auto_eff;
    double          afrt_surface;
    double          sweepeff;
    double          fr_curb;
    int             imp_trig;
    int             fert_days;
    int             cfrt_id;
    int             ifrt_freq;
    double          cfrt_kg;
    double          pst_dep;
    int             ihv_gbm;
    double          irr_salt;
    double          irr_efm;
    double          irr_sq;
    double          irr_eff;
    double          irr_mx;
    double          irr_asq;
    int             cpst_id;
    int             pest_days;
    int             ipest_freq;
    double          cpst_kg;
    double          burn_frlb;
    int             op_num;
    int             irr_sc;
    int             irr_no;
    int             irr_sca;
    int             irr_noa;
}                   mgt_struct;

int                 AddMgt (sllist_struct *, mgt_struct *);
int                 DOY (int, int);
fert_struct*        FindFert (sllist_struct *, int);
plant_struct*       FindPlant (sllist_struct *, int);
till_struct*        FindTill (sllist_struct *, int);
char                FirstNonWhite (char *);
int                 NextLine (FILE *, char *, int *);
int                 ReadDlmtdLine (char *, char, void *, int *, int *);
void                ReadFert (FILE *, sllist_struct *);
void                ReadPlant (FILE *, sllist_struct *);
void                ReadTill (FILE *, sllist_struct *);
int                 ReadLine (char *, char, void *, int *, int *);
void                ReadMgt (FILE *, sllist_struct *);
int                 Readable (char *);
int                 SortMgt (mgt_struct *, mgt_struct *);
void                WriteCrop (FILE *, plant_struct *, double, double);
void                WriteFert (FILE *, mgt_struct *, fert_struct *);
void                WriteIrr (FILE *, mgt_struct *);
void                WriteOp (FILE *, sllist_struct *, FILE *,
    sllist_struct *, sllist_struct *, sllist_struct *);
void                WritePlanting (FILE *, mgt_struct *, plant_struct *);
void                WriteTill (FILE *, mgt_struct *, till_struct *);

int                 subbasin;
int                 hru;
