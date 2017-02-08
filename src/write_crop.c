#include "swat2cycles.h"

void WriteCrop (FILE *crop_file, plant_struct *plant, double heatunits,
    double hi_targ)
{
    fprintf (crop_file, "%-44s%s\n", "NAME", plant->cpnm);
    //FLOWERING_TT                                1164.05
    fprintf (crop_file, "%-44s%.2lf\n", "MATURITY_TT", heatunits);
    fprintf (crop_file, "%-44s%.2lf\n", "MAXIMUM_SOIL_COVERAGE", 100.0);
    fprintf (crop_file, "%-44s%.2lf\n", "MAXIMUM_ROOTING_DEPTH",
            plant->rdmx);
    //AVERAGE_EXPECTED_YIELD                      1.00
    //MAXIMUM_EXPECTED_YIELD                      1.00
    //MINIMUM_EXPECTED_YIELD                      1.00
    //COMMERCIAL_YIELD_MOISTURE                   0.00
    //STANDING_RESIDUE_AT_HARVEST                 40.00
    //RESIDUE_REMOVED                             0.00
    //CLIPPING_BIOMASS_THRESHOLD_UPPER            999.00
    //CLIPPING_BIOMASS_THRESHOLD_LOWER            0.50
    //HARVEST_TIMING                              -999
    //CLIPPING_BIOMASS_DESTINY                    REMOVE
    //MIN_TEMPERATURE_FOR_TRANSPIRATION           3.00
    //THRESHOLD_TEMPERATURE_FOR_TRANPIRATION      15.00
    //MIN_TEMPERATURE_FOR_COLD_DAMAGE             -5.00
    //THRESHOLD_TEMPERATURE_FOR_COLD_DAMAGE       3.00
    fprintf (crop_file, "%-44s%.2lf\n",
            "BASE_TEMPERATURE_FOR_DEVELOPMENT", plant->t_base);
    fprintf (crop_file, "%-44s%.2lf\n",
            "OPTIMUM_TEMPERATURE_FOR_DEVELOPEMENT", plant->t_opt);
    //MAX_TEMPERATURE_FOR_DEVELOPMENT             46.00
    //fprintf (crop_file, "%-44s%.2lf\n",
    //    "INITIAL_PARTITIONING_TO_SHOOT", 1.0 / (1.0 + plant->rsr1c));
    //fprintf (crop_file, "%-44s%.2lf\n",
    //    "FINAL_PARTITIONING_TO_SHOOT", 1.0 / (1.0 + plant->rsr2c));
    fprintf (crop_file, "%-44s%.2lf\n", "RADIATION_USE_EFFICIENCY",
            plant->bio_e / 10.0);
    //TRANSPIRATION_USE_EFFICIENCY                7.90
    //MAXIMUM_HARVEST_INDEX                       0.80
    fprintf (crop_file, "%-44s%.2lf\n", "MINIMUM_HARVEST_INDEX",
            plant->wsyf);
    fprintf (crop_file, "%-44s%.2lf\n", "HARVEST_INDEX",
            plant->hvsti);
    //THERMAL_TIME_TO_EMERGENCE                   65.00
    fprintf (crop_file, "%-44s%.3lf\n", "N_MAX_CONCENTRATION",
            plant->pltnfr[0]);
    //N_DILUTION_SLOPE                            0.40
    //KC                                          1.20
    //ANNUAL                                      1
    //LEGUME                                      0
    //C3                                          0
    //LWP_STRESS_ONSET                            -1100
    //LWP_WILTING_POINT                           -2000
    //TRANSPIRATION_MAX                           15
    fprintf (crop_file, "\n");
    plant->flag = 1;
}
