#include "qhy9.h"
#include "qhycam.h"
#include <stdio.h>


extern QUsb *qhyusb;
QHY9 *qhy9;

void QHY9::CorrectQHY9WH(int *w,int *h)
{
        if(*w <= 896 && *h <= 644)
	{
		*w = 896;
		*h = 644;
		initQHY9_896x644();
	}
	else if(*w <= 1792 && *h <= 1287)
	{
		*w = 1792;
		*h = 1287;
		initQHY9_1792x1287();
	}
	else
	{
		*w = 3584;
		*h = 2574;
		initQHY9_3584x2574();
	}
}

void QHY9::initQHY9_regs(void)
{
    qhyusb->ccdreg.devname = (char *)"QHY9-0";
    qhyusb->ccdreg.Gain = qhyusb->QCam.camGain;
    qhyusb->ccdreg.Offset = qhyusb->QCam.camOffset;
    qhyusb->ccdreg.Exptime = qhyusb->QCam.camTime;       //unit: ms
    qhyusb->ccdreg.DownloadSpeed = qhyusb->QCam.transferspeed;
    qhyusb->ccdreg.SKIP_TOP = 0;
    qhyusb->ccdreg.SKIP_BOTTOM = 0;
    qhyusb->ccdreg.AMPVOLTAGE = 1;
    qhyusb->ccdreg.LiveVideo_BeginLine = 0;
    qhyusb->ccdreg.AnitInterlace = 0;
    qhyusb->ccdreg.MultiFieldBIN = 0;
    qhyusb->ccdreg.TgateMode = 0;
    qhyusb->ccdreg.ShortExposure = 0;
    qhyusb->ccdreg.VSUB = 0;
    qhyusb->ccdreg.TransferBIT = 0;
    qhyusb->ccdreg.TopSkipNull = 30;
    qhyusb->ccdreg.TopSkipPix = 0;
    qhyusb->ccdreg.MechanicalShutterMode = 0;
    qhyusb->ccdreg.DownloadCloseTEC = 0;
    qhyusb->ccdreg.SDRAM_MAXSIZE = 100;
    qhyusb->ccdreg.ClockADJ = 0x0000;
    qhyusb->ccdreg.CLAMP = 0;
    qhyusb->ccdreg.MotorHeating = 2;
}

void QHY9::initQHY9_896x644(void)
{
    qhyusb->ccdreg.HBIN = 4;
    qhyusb->ccdreg.VBIN = 4;
    qhyusb->ccdreg.LineSize = 896;
    qhyusb->ccdreg.VerticalSize = 644;
    qhyusb->QCam.cameraW = 896;
    qhyusb->QCam.cameraH = 644;
    
}

void QHY9::initQHY9_1792x1287(void)
{
    qhyusb->ccdreg.HBIN = 2;
    qhyusb->ccdreg.VBIN = 2;
    qhyusb->ccdreg.LineSize = 1792;
    qhyusb->ccdreg.VerticalSize = 1287;
    qhyusb->QCam.cameraW = 1792;
    qhyusb->QCam.cameraH = 1287;

}
void QHY9::initQHY9_3584x2574(void)
{
    qhyusb->ccdreg.HBIN = 1;
    qhyusb->ccdreg.VBIN = 1;
    qhyusb->ccdreg.LineSize = 3584;
    qhyusb->ccdreg.VerticalSize = 2574;
    qhyusb->QCam.cameraW = 3584;
    qhyusb->QCam.cameraH = 2574;

}
