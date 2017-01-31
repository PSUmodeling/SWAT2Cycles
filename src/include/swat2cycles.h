#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sllist.h"

#define MAXSTRING   1024
#define AHEAD       0
#define BEHIND      1

typedef struct mgt_struct
{
    int         oid;
    int         subbasin;
    int         hru;
    char        landuse[5];
    char        soil[MAXSTRING];
    char        slope_cd[MAXSTRING];
    char        crop[5];
    int         year;
    int         month;
    int         day;
    double      husc;
    int         mgt_op;
    int         headunits;
    int         plant_id;
    int         curyr_mat;
    double      lai_init;
    double      bio_init;
    double      hi_targ;
    double      bio_targ;
    double      cnop;
    double      irr_amt;
    int         fert_id;
    double      frt_kg;
    double      frt_surface;
    int         pest_id;
    double      pst_kg;
    int         tillage_id;
    double      harveff;
    double      hi_ovr;
    int         grz_days;
    int         manure_id;
    double      bio_eat;
    double      bio_trmp;
    double      manure_kg;
    int         wstrs_id;
    double      auto_wstrs;
    int         afert_id;
    double      auto_nstrs;
    double      auto_napp;
    double      auto_nyr;
    double      auto_eff;
    double      afrt_surface;
    double      sweepeff;
    double      fr_curb;
    int         imp_trig;
    int         fert_days;
    int         cfrt_id;
    int         ifrt_freq;
    double      cfrt_kg;
    double      pst_dep;
    int         ihv_gbm;
    double      irr_salt;
    double      irr_efm;
    double      irr_sq;
    double      irr_eff;
    double      irr_mx;
    double      irr_asq;
    int         cpst_id;
    int         pest_days;
    int         ipest_freq;
    double      cpst_kg;
    double      burn_frlb;
    int         op_num;
    int         irr_sc;
    int         irr_no;
    int         irr_sca;
    int         irr_noa;
}               mgt_struct;

int             AddMgt (sllist_struct *, mgt_struct *);
int             SortMgt (mgt_struct *, mgt_struct *);
char            FirstNonWhite (char *);
void            NextLine (FILE *, char *);
void            ReadMgt (char *, mgt_struct *);
int             Readable (char *);
