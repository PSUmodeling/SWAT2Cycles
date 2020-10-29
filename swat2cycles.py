#!/usr/bin/env python3

import argparse
import numpy as np
import pandas
import sys
from datetime import datetime

END_OF_YEAR     = 0
PLANTING        = 1
IRRIGATION      = 2
FERTILIZER      = 3
PESTICIDE       = 4
HARVEST_KILL    = 5
TILLAGE         = 6
HARVEST         = 7
KILL            = 8
GRAZING         = 9
AUTO_IRR        = 10
AUTO_FERT       = 11
STREET_SWEEP    = 12
RELEASE_IMPOUND = 13
CONT_FERT       = 14
CONT_PEST       = 15

def write_planting(op, cropnm, fp):
    '''
    Write planting operations to file
    '''
    dt = datetime(1999, int(op['MONTH']), int(op['DAY']))
    doy = dt.timetuple().tm_yday

    fp.write('%-32s# OID %-d\n'      % ('PLANTING', op['OID']))
    fp.write('%-20s%-d\n'            % ('YEAR', op['YEAR']))
    fp.write('%-20s%-d\n'            % ('DOY', doy))
    fp.write('%-20s%-d\n'            % ('END_DOY', -999))
    fp.write('%-20s%-12d# m3/m3\n'   % ('MAX_SMC', -999))
    fp.write('%-20s%-12.1f# m3/m3\n' % ('MIN_SMC', 0.0))
    fp.write('%-20s%-12.1f# C\n'     % ('MIN_SOIL_TEMP', 0.0))
    fp.write('%-20s%-s\n'            % ('CROP', cropnm))
    fp.write('%-20s%-s\n'            % ('USE_AUTO_IRR', '0'))
    fp.write('%-20s%-s\n'            % ('USE_AUTO_FERT', '0'))
    fp.write('%-20s%-.1f\n'          % ('FRACTION', 1.0))
    fp.write('%-20s%-d\n'            % ('CLIPPING_START', -999))
    fp.write('%-20s%-d\n'            % ('CLIPPING_END', -999))
    fp.write('\n')


def write_fert(op, fert, fp):
    '''
    Write fertilization operations to file
    '''
    dt = datetime(1999, int(op['MONTH']), int(op['DAY']))
    doy = dt.timetuple().tm_yday

    fp.write('%-32s# OID %-d\n'      % ('FIXED_FERTILIZATION', op['OID']))
    fp.write('%-20s%-d\n'            % ('YEAR', op['YEAR']))
    fp.write('%-20s%-d\n'            % ('DOY', doy))
    fp.write('%-20s%-s\n'            % ('SOURCE', fert['fertnm']))
    fp.write('%-20s%-12.2f# kg/ha\n' % ('MASS', op['FRT_KG']))
    fp.write('%-20s%-s\n'            % ('FORM', 'N/A'))
    fp.write('%-20s%-s\n'            % ('METHOD', 'N/A'))
    fp.write('%-20s%-d\n'            % ('LAYER', 1 if op['FRT_SURFACE'] > 0.5
                                        else 2))
    fp.write('%-20s%-12.2f# kg/kg\n' % ('C_ORGANIC', 0.0))
    fp.write('%-20s%-12.2f# kg/kg\n' % ('C_CHARCOAL', 0.0))
    fp.write('%-20s%-12.3f# kg/kg\n' % ('N_ORGANIC', fert['forgn']))
    fp.write('%-20s%-12.2f# kg/kg\n' % ('N_CHARCOAL', 0.0))
    fp.write('%-20s%-12.3f# kg/kg\n' % ('N_NH4', fert['fminn'] * fert['fnh3n']))
    fp.write('%-20s%-12.3f# kg/kg\n' % ('N_NO3',
                                        fert['fminn'] * (1.0 - fert['fnh3n'])))
    fp.write('%-20s%-12.3f# kg/kg\n' % ('P_ORGANIC', fert['forgp']))
    fp.write('%-20s%-12.2f# kg/kg\n' % ('P_CHARCOAL', 0.0))
    fp.write('%-20s%-12.3f# kg/kg\n' % ('P_INORGANIC', fert['fminp']))
    fp.write('%-20s%-12.2f# kg/kg\n' % ('K', 0.0))
    fp.write('%-20s%-12.2f# kg/kg\n' % ('S ', 0.0))
    fp.write('\n')


def write_irrig(op, fp):
    '''
    Write irrigation operations to file
    '''
    dt = datetime(1999, int(op['MONTH']), int(op['DAY']))
    doy = dt.timetuple().tm_yday

    fp.write('%-32s# OID %-d\n' % ('FIXED_IRRIGATION', op['OID']))
    fp.write('%-20s%-d\n'       % ('YEAR', op['YEAR']))
    fp.write('%-20s%-d\n'       % ('DOY', doy))
    fp.write('%-20s%-d\n\n'     % ('VOLUME', int(op['IRR_AMT'])))


def write_till(op, till, fp):
    '''
    Write tillage operations to file
    '''
    dt = datetime(1999, int(op['MONTH']), int(op['DAY']))
    doy = dt.timetuple().tm_yday

    fp.write('%-32s# OID %-d\n' % ('TILLAGE', op['OID']))
    fp.write('%-20s%-d\n'       % ('YEAR', op['YEAR']))
    fp.write('%-20s%-d\n'       % ('DOY', doy))
    fp.write('%-20s%-s\n'       % ('TOOL', till['tillnm']))
    fp.write('%-20s%-12s# m\n'  % ('DEPTH', till['deptil']))
    fp.write('%-20s%s\n'        % ('SOIL_DISTURB_RATIO', till['sdr']))
    fp.write('%-20s%-s\n'       % ('MIXING_EFFICIENCY', till['effmix']))
    fp.write('%-20s%-s\n'       % ('CROP_NAME', till['cropnm']))
    fp.write('%-20s%d\n'        % ('FRAC_THERMAL_TIME', -999))
    fp.write('%-20s%d\n'        % ('KILL_EFFICIENCY', -999))
    fp.write('\n')

def read_fert():
    '''
    Read fertilizer database
    '''
    try:
        ferts = pandas.read_csv(
            'data/fert.dat',
            sep=' ',
            skipinitialspace=True,
            header=None,
            usecols=list(range(10)),
            index_col=0,
            names=['', 'fertnm', 'fminn', 'fminp', 'forgn', 'forgp', 'fnh3n',
                   'bactpdb', 'bactlpdb', 'bactkddb'])
    except FileNotFoundError:
        sys.exit('Oops! Cannot find data/fert.dat')

    return ferts


def read_till():
    '''
    Read tillage database
    '''
    try:
        tills = pandas.read_csv(
            'data/till.dat',
            sep=' ',
            skipinitialspace=True,
            header=None,
            index_col=0,
            usecols=list(range(4)),
            names=['', 'tillnm', 'effmix', 'deptil'])
    except FileNotFoundError:
        sys.exit('Oops! Cannot find data/till.dat')

    return tills


def read_plant():
    '''
    Read planting database
    '''
    crops = []
    ind = []
    try:
        with open('data/plant.dat') as file:
            for line in file:
                strs = line.strip().split()
                if len(strs) == 3:
                    ind.append(int(strs[0]))
                    crops.append(strs[1])
    except FileNotFoundError:
        sys.exit('Oops! Cannot find data/till.dat')

    crops = pandas.DataFrame(crops, columns=['crop'])
    crops.index = ind

    return crops


def main():
    parser = argparse.ArgumentParser(
                description='Convert SWAT management files to '
                            'Cycles operation files')
    parser.add_argument(
        '-s',
        '--subbasin',
        type=int,
        required=True,
        help='Subbasin')
    parser.add_argument(
        '-u',
        '--hru',
        type=int,
        required=True,
        help='HRU')
    parser.add_argument(
        '-f',
        '--mgt-file',
        dest='mgt_file',
        required=True,
        help='Management file')

    args = parser.parse_args()

    # Read databases
    ferts = read_fert()
    crops = read_plant()
    tills = read_till()

    # Read management file
    try:
        mgt = pandas.read_csv(
            'data/%s' % (args.mgt_file),
            sep=',',
            skipinitialspace=True,
            index_col=False)
    except FileNotFoundError:
        sys.exit('Oops! Cannot find data/%s' % (args.mgt_file))

    # Filter management by subbasin and HRU
    mgt = mgt[(mgt['SUBBASIN'] == args.subbasin) & (mgt['HRU'] == args.hru)]

    if mgt.empty is True:
        sys.exit(
            'Cannot find operations for Subbasin %d HRU %d'
            % (args.subbasin, args.hru))

    # Sort management by time
    mgt = mgt.sort_values(by=['YEAR', 'MONTH', 'DAY'])

    # Cycles operation file name
    filen = 'SB%dHRU%d%s.operation' % (args.subbasin,
                                       args.hru,
                                       mgt['LANDUSE'].iloc[0].lower())

    # Loop through SWAT operations
    with open(filen, 'w') as fp:
        for _, row in mgt.iterrows():
            if row['MGT_OP'] == END_OF_YEAR:
                # Not needed by Cycles
                continue
            elif row['MGT_OP'] == PLANTING:
                # Planting operation
                # Save crop being planted which will be used when
                # harvesting/killing
                ccrop = crops['crop'].loc[row['PLANT_ID']]
                write_planting(row, ccrop, fp)
            elif row['MGT_OP'] == IRRIGATION:
                # Irrigation operation
                write_irrig(row, fp)
            elif row['MGT_OP'] == FERTILIZER:
                # Fertilization operation
                write_fert(row, ferts.loc[row['FERT_ID']], fp)
            elif row['MGT_OP'] == PESTICIDE:
                # Not supported
                print('Pesticide operations are not yet supported by Cycles. '
                    'OID %d was not written\ninto Cycles input.\n'
                    % (row['OID']))
            elif row['MGT_OP'] == HARVEST_KILL:
                # Equivalent to grain harvest and kill operations
                till = {'tillnm': 'Grain_Harvest',
                        'deptil': '0.0',
                        'sdr':    '0.0',
                        'effmix': '0.0',
                        'cropnm': ccrop}
                write_till(row, till, fp)

                till = {'tillnm': 'Kill_Crop',
                        'deptil': '0.0',
                        'sdr':    '0.0',
                        'effmix': '0.0',
                        'cropnm': ccrop}
                write_till(row, till, fp)
            elif row['MGT_OP'] == TILLAGE:
                # Tillage operation
                depth = tills['deptil'].loc[row['TILLAGE_ID']] / 1000.0
                mixing = tills['effmix'].loc[row['TILLAGE_ID']]
                till = {'tillnm': tills['tillnm'].loc[row['TILLAGE_ID']],
                        'deptil': '%.2f' % (depth),
                        'sdr':    '0.0',
                        'effmix': '%.2f' % (mixing),
                        'cropnm': 'N/A'}
                write_till(row, till, fp)
            elif row['MGT_OP'] == HARVEST:
                till = {'tillnm': 'Forage_Harvest',
                        'deptil': '0.0',
                        'sdr':    '0.0',
                        'effmix': '0.0',
                        'cropnm': ccrop}
                write_till(row, till, fp)
            elif row['MGT_OP'] == KILL:
                till = {'tillnm': 'Kill_Crop',
                        'deptil': '0.0',
                        'sdr':    '0.0',
                        'effmix': '0.0',
                        'cropnm': ccrop}
                write_till(row, till, fp)
            elif row['MGT_OP'] == GRAZING:
                print('Grazing operations are not yet supported by Cycles. '
                    'OID %d is not written\ninto Cycles input.\n'
                    % (row['OID']))
            elif row['MGT_OP'] == AUTO_IRR:
                print('SWAT auto irrigation operations are different from '
                      'Cycles auto irrigation\noperations. Please manually add '
                      'OID %d to the operation file.' % (row['OID']))
            elif row['MGT_OP'] == AUTO_FERT:
                print('Auto fertilization operations are not yet supported by '
                    'Cycles. OID %d is not\nwritten into Cycles input.\n'
                    % (row['OID']))
            elif row['MGT_OP'] == STREET_SWEEP:
                print('Street sweeping operations are not yet supported by '
                    'Cycles. OID %d is not\nwritten into Cycles input.\n'
                    % (row['OID']))
            elif row['MGT_OP'] == RELEASE_IMPOUND:
                print('Release/impound operations are not yet supported by '
                    'Cycles. OID %d is not\nwritten into Cycles input.\n'
                    % (row['OID']))
            elif row['MGT_OP'] == CONT_FERT:
                print('Continuous fertilization operations are not yet '
                      'supported by Cycles. OID %d is not\nwritten into Cycles '
                      'input.\n' % (row['OID']))
            elif row['MGT_OP'] == CONT_PEST:
                print('Continuous pesticides operations are not yet supported '
                    'by Cycles. OID %d is not\nwritten into Cycles input.\n'
                    % (row['OID']))


if __name__ == '__main__':
    main()
