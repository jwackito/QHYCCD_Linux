class QHY5II
{
public:
	void  SetQHY5IIGain(unsigned short gain);
	void  QHY5II_DeNoise(bool on);
	void  CorrectQHY5IIWH(int *w,int *h);
	void  QHY5IIDeNoise(unsigned char *ImgData, int x, int y);
	void  initQHY5II_SXGA(void);
	void  initQHY5II_XGA(void);
	void  initQHY5II_SVGA(void);
	void  initQHY5II_VGA(void);
	void  initQHY5II_QVGA(void);
	void  initQHY5II_R1024(void);
	void  initQHY5II_R800(void);
	void  initQHY5II_R400(void);
	void  initQHY5II_1280X720(void);
	void  initQHY5II_960X720(void);
	void  QHY5IISetResolution(int x, int y);
	void  SetExposureTime_QHY5II(unsigned long i);

        QHY5II(void)
        {
            qhy5iiDeNoise = false;
            longExpMode = false;
        }
        ~QHY5II(void){}

	bool qhy5iiDeNoise;
	bool longExpMode;
private:

};

