"""
zeiss.py

Registry specific keys for Zeiss microscope macros
"""

__author__ = 'rudolf.hoefler@gmail.com'
__licence__ = 'LGPL'


class ZeissKeys(object):
    # Configurable parameters
    regkey = "SOFTWARE\\VB and VBA Program Settings\\OnlineImageAnalysis\\macro"
    #subkey_changed = "has_changed"
    subkey_codemic = "codeMic"
    subkey_codeoia = "codeOia"
    subkey_filename = "filepath"
    subkey_xpos = "X"
    subkey_ypos = "Y"
    subkey_zpos = "Z"
    subkey_fcsx = "fcsX"
    subkey_fcsy = "fcsY"
    subkey_fcsz = "fcsZ"
    subkey_roix = "roiX"
    subkey_roiy = "roiY"
    subkey_roitype = "roiType"
    subkey_roiaim = "roiAim"
    subkey_errormsg = "errorMsg"
