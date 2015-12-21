class Message(object):
    __slots__ = ['codemic', 'codeoia', 'imagefile', 'roi', 'roitype',
                 'roiaim', 'errormsg', 'changed', 'position', 'fcs']

    CODE_NOTHING = 'nothing'
    CODE_WAIT = 'wait'
    CODE_NEWIMAGE = 'newImage'
    CODE_ERROR = 'error'
    CODE_TRIGGER1 = 'trigger1'
    CODE_TRIGGER2 = 'trigger2'
    CODE_FCS1 = 'fcs1'
    CODE_FOCUS = 'focus'
    
    ROITYPE_RECT = 'rectangle'
    ROITYPE_CIRCLE = 'circle'
    ROITYPE_POLYGON = 'polyline'
    ROITYPE_ELLIPSE = 'ellipse'

    ROIAIM_BLEACH = 'bleach'
    ROIAIM_ACQUISITION = 'acquisition'
    ROIAIM_BLEACHANALYSIS = 'bleachAnalysis'
    ROIAIM_ACQUISITIONBLEACH = 'acquisitionBleach'
    ROIAIM_ACQUISITIONANALYSIS = 'acquisitionAnalysis'
    ROIAIM_ALL = 'acquisitionBleachAnalysis'
 

    def __init__(self):
        self.codemic = None
        self.codeoia = None
        self.position = None
        self.roitype = None
        self.roi = None
        self.fcs = None
        self.imagefile = None
        self.errormsg = None
        self.changed = None
        self.roiaim = None

    def pprint(self):
        for slot in self.__slots__:
            print slot, ": ", getattr(self, slot)

