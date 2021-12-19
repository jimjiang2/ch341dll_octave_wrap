int    WINAPI    CH341OpenDevice(  ULONG    iIndex );  
VOID    WINAPI    CH341CloseDevice(  ULONG    iIndex ); 


BOOL    WINAPI    CH341InitParallel(  // ��λ����ʼ������,RST#����͵�ƽ����
    ULONG            iIndex,  // ָ��CH341�豸���
    ULONG            iMode );  // ָ������ģʽ: 0ΪEPPģʽ/EPPģʽV1.7, 1ΪEPPģʽV1.9, 2ΪMEMģʽ, >= 0x00000100 ���ֵ�ǰģʽ


BOOL    WINAPI    CH341ReadData0(  // ��0#�˿ڶ�ȡ���ݿ�
    ULONG            iIndex,  // ָ��CH341�豸���
    PVOID            oBuffer,  // ָ��һ���㹻��Ļ�����,���ڱ����ȡ������
    PULONG            ioLength );  // ָ�򳤶ȵ�Ԫ,����ʱΪ׼����ȡ�ĳ���,���غ�Ϊʵ�ʶ�ȡ�ĳ���


BOOL    WINAPI    CH341ReadData1(  // ��1#�˿ڶ�ȡ���ݿ�
    ULONG            iIndex,  // ָ��CH341�豸���
    PVOID            oBuffer,  // ָ��һ���㹻��Ļ�����,���ڱ����ȡ������
    PULONG            ioLength );  // ָ�򳤶ȵ�Ԫ,����ʱΪ׼����ȡ�ĳ���,���غ�Ϊʵ�ʶ�ȡ�ĳ���


BOOL    WINAPI    CH341AbortRead(  // �������ݿ������
    ULONG            iIndex );  // ָ��CH341�豸���


BOOL    WINAPI    CH341WriteData0(  // ��0#�˿�д�����ݿ�
    ULONG            iIndex,  // ָ��CH341�豸���
    PVOID            iBuffer,  // ָ��һ��������,����׼��д��������
    PULONG            ioLength );  // ָ�򳤶ȵ�Ԫ,����ʱΪ׼��д���ĳ���,���غ�Ϊʵ��д���ĳ���


BOOL    WINAPI    CH341WriteData1(  // ��1#�˿�д�����ݿ�
    ULONG            iIndex,  // ָ��CH341�豸���
    PVOID            iBuffer,  // ָ��һ��������,����׼��д��������
    PULONG            ioLength );  // ָ�򳤶ȵ�Ԫ,����ʱΪ׼��д���ĳ���,���غ�Ϊʵ��д���ĳ���


BOOL    WINAPI    CH341AbortWrite(  // �������ݿ�д����
    ULONG            iIndex );  // ָ��CH341�豸���


BOOL    WINAPI    CH341GetStatus(  // ͨ��CH341ֱ���������ݺ�״̬
    ULONG            iIndex,  // ָ��CH341�豸���
    PULONG            iStatus );  // ָ��һ��˫�ֵ�Ԫ,���ڱ���״̬����,�ο������λ˵��
// λ7-λ0��ӦCH341��D7-D0����
// λ8��ӦCH341��ERR#����, λ9��ӦCH341��PEMP����, λ10��ӦCH341��INT#����, λ11��ӦCH341��SLCT����, λ23��ӦCH341��SDA����
// λ13��ӦCH341��BUSY/WAIT#����, λ14��ӦCH341��AUTOFD#/DATAS#����,λ15��ӦCH341��SLCTIN#/ADDRS#����


BOOL    WINAPI    CH341ReadI2C(  // ��I2C�ӿڶ�ȡһ���ֽ�����
    ULONG            iIndex,  // ָ��CH341�豸���
    UCHAR            iDevice,  // ��7λָ��I2C�豸��ַ
    UCHAR            iAddr,  // ָ�����ݵ�Ԫ�ĵ�ַ
    PUCHAR            oByte );  // ָ��һ���ֽڵ�Ԫ,���ڱ����ȡ���ֽ�����


BOOL    WINAPI    CH341WriteI2C(  // ��I2C�ӿ�д��һ���ֽ�����
    ULONG            iIndex,  // ָ��CH341�豸���
    UCHAR            iDevice,  // ��7λָ��I2C�豸��ַ
    UCHAR            iAddr,  // ָ�����ݵ�Ԫ�ĵ�ַ
    UCHAR            iByte );  // ��д����ֽ�����


BOOL    WINAPI    CH341EppReadData(  // EPP��ʽ������: WR#=1, DS#=0, AS#=1, D0-D7=input
    ULONG            iIndex,  // ָ��CH341�豸���
    PVOID            oBuffer,  // ָ��һ���㹻��Ļ�����,���ڱ����ȡ������
    PULONG            ioLength );  // ָ�򳤶ȵ�Ԫ,����ʱΪ׼����ȡ�ĳ���,���غ�Ϊʵ�ʶ�ȡ�ĳ���


BOOL    WINAPI    CH341EppReadAddr(  // EPP��ʽ����ַ: WR#=1, DS#=1, AS#=0, D0-D7=input
    ULONG            iIndex,  // ָ��CH341�豸���
    PVOID            oBuffer,  // ָ��һ���㹻��Ļ�����,���ڱ����ȡ�ĵ�ַ����
    PULONG            ioLength );  // ָ�򳤶ȵ�Ԫ,����ʱΪ׼����ȡ�ĳ���,���غ�Ϊʵ�ʶ�ȡ�ĳ���


BOOL    WINAPI    CH341EppWriteData(  // EPP��ʽд����: WR#=0, DS#=0, AS#=1, D0-D7=output
    ULONG            iIndex,  // ָ��CH341�豸���
    PVOID            iBuffer,  // ָ��һ��������,����׼��д��������
    PULONG            ioLength );  // ָ�򳤶ȵ�Ԫ,����ʱΪ׼��д���ĳ���,���غ�Ϊʵ��д���ĳ���


BOOL    WINAPI    CH341EppWriteAddr(  // EPP��ʽд��ַ: WR#=0, DS#=1, AS#=0, D0-D7=output
    ULONG            iIndex,  // ָ��CH341�豸���
    PVOID            iBuffer,  // ָ��һ��������,����׼��д���ĵ�ַ����
    PULONG            ioLength );  // ָ�򳤶ȵ�Ԫ,����ʱΪ׼��д���ĳ���,���غ�Ϊʵ��д���ĳ���


BOOL    WINAPI    CH341EppSetAddr(  // EPP��ʽ���õ�ַ: WR#=0, DS#=1, AS#=0, D0-D7=output
    ULONG            iIndex,  // ָ��CH341�豸���
    UCHAR            iAddr );  // ָ��EPP��ַ


BOOL    WINAPI    CH341MemReadAddr0(  // MEM��ʽ����ַ0: WR#=1, DS#/RD#=0, AS#/ADDR=0, D0-D7=input
    ULONG            iIndex,  // ָ��CH341�豸���
    PVOID            oBuffer,  // ָ��һ���㹻��Ļ�����,���ڱ���ӵ�ַ0��ȡ������
    PULONG            ioLength );  // ָ�򳤶ȵ�Ԫ,����ʱΪ׼����ȡ�ĳ���,���غ�Ϊʵ�ʶ�ȡ�ĳ���


BOOL    WINAPI    CH341MemReadAddr1(  // MEM��ʽ����ַ1: WR#=1, DS#/RD#=0, AS#/ADDR=1, D0-D7=input
    ULONG            iIndex,  // ָ��CH341�豸���
    PVOID            oBuffer,  // ָ��һ���㹻��Ļ�����,���ڱ���ӵ�ַ1��ȡ������
    PULONG            ioLength );  // ָ�򳤶ȵ�Ԫ,����ʱΪ׼����ȡ�ĳ���,���غ�Ϊʵ�ʶ�ȡ�ĳ���


BOOL    WINAPI    CH341MemWriteAddr0(  // MEM��ʽд��ַ0: WR#=0, DS#/RD#=1, AS#/ADDR=0, D0-D7=output
    ULONG            iIndex,  // ָ��CH341�豸���
    PVOID            iBuffer,  // ָ��һ��������,����׼�����ַ0д��������
    PULONG            ioLength );  // ָ�򳤶ȵ�Ԫ,����ʱΪ׼��д���ĳ���,���غ�Ϊʵ��д���ĳ���


BOOL    WINAPI    CH341MemWriteAddr1(  // MEM��ʽд��ַ1: WR#=0, DS#/RD#=1, AS#/ADDR=1, D0-D7=output
    ULONG            iIndex,  // ָ��CH341�豸���
    PVOID            iBuffer,  // ָ��һ��������,����׼�����ַ1д��������
    PULONG            ioLength );  // ָ�򳤶ȵ�Ԫ,����ʱΪ׼��д���ĳ���,���غ�Ϊʵ��д���ĳ���


BOOL    WINAPI    CH341SetExclusive(  // ���ö�ռʹ�õ�ǰCH341�豸
    ULONG            iIndex,  // ָ��CH341�豸���
    ULONG            iExclusive );  // Ϊ0���豸���Թ���ʹ��,��0���ռʹ��


BOOL    WINAPI    CH341SetTimeout(  // ����USB���ݶ�д�ĳ�ʱ
    ULONG            iIndex,  // ָ��CH341�豸���
    ULONG            iWriteTimeout,  // ָ��USBд�����ݿ�ĳ�ʱʱ��,�Ժ���mSΪ��λ,0xFFFFFFFFָ������ʱ(Ĭ��ֵ)
    ULONG            iReadTimeout );  // ָ��USB��ȡ���ݿ�ĳ�ʱʱ��,�Ժ���mSΪ��λ,0xFFFFFFFFָ������ʱ(Ĭ��ֵ)


BOOL    WINAPI    CH341ReadData(  // ��ȡ���ݿ�
    ULONG            iIndex,  // ָ��CH341�豸���
    PVOID            oBuffer,  // ָ��һ���㹻��Ļ�����,���ڱ����ȡ������
    PULONG            ioLength );  // ָ�򳤶ȵ�Ԫ,����ʱΪ׼����ȡ�ĳ���,���غ�Ϊʵ�ʶ�ȡ�ĳ���


BOOL    WINAPI    CH341WriteData(  // д�����ݿ�
    ULONG            iIndex,  // ָ��CH341�豸���
    PVOID            iBuffer,  // ָ��һ��������,����׼��д��������
    PULONG            ioLength );  // ָ�򳤶ȵ�Ԫ,����ʱΪ׼��д���ĳ���,���غ�Ϊʵ��д���ĳ���


PVOID    WINAPI    CH341GetDeviceName(  // ����ָ��CH341�豸���ƵĻ�����,�����򷵻�NULL
    ULONG            iIndex );  // ָ��CH341�豸���,0��Ӧ��һ���豸


ULONG    WINAPI    CH341GetVerIC(  // ��ȡCH341оƬ�İ汾,����:0=�豸��Ч,0x10=CH341,0x20=CH341A
    ULONG            iIndex );  // ָ��CH341�豸���
#define        IC_VER_CH341A        0x20
#define        IC_VER_CH341A3        0x30


BOOL    WINAPI    CH341FlushBuffer(  // ���CH341�Ļ�����
    ULONG            iIndex );  // ָ��CH341�豸���


BOOL    WINAPI    CH341WriteRead(  // ִ������������,�����������
    ULONG            iIndex,  // ָ��CH341�豸���
    ULONG            iWriteLength,  // д����,׼��д���ĳ���
    PVOID            iWriteBuffer,  // ָ��һ��������,����׼��д��������
    ULONG            iReadStep,  // ׼����ȡ�ĵ�����ĳ���, ׼����ȡ���ܳ���Ϊ(iReadStep*iReadTimes)
    ULONG            iReadTimes,  // ׼����ȡ�Ĵ���
    PULONG            oReadLength,  // ָ�򳤶ȵ�Ԫ,���غ�Ϊʵ�ʶ�ȡ�ĳ���
    PVOID            oReadBuffer );  // ָ��һ���㹻��Ļ�����,���ڱ����ȡ������


BOOL    WINAPI    CH341SetStream(  // ���ô�����ģʽ
    ULONG            iIndex,  // ָ��CH341�豸���
    ULONG            iMode );  // ָ��ģʽ,������
// λ1-λ0: I2C�ӿ��ٶ�/SCLƵ��, 00=����/20KHz,01=��׼/100KHz(Ĭ��ֵ),10=����/400KHz,11=����/750KHz
// λ2:     SPI��I/O��/IO����, 0=���뵥��(D3ʱ��/D5��/D7��)(Ĭ��ֵ),1=˫��˫��(D3ʱ��/D5��D4��/D7��D6��)
// λ7:     SPI�ֽ��е�λ˳��, 0=��λ��ǰ, 1=��λ��ǰ
// ��������,����Ϊ0


BOOL    WINAPI    CH341SetDelaymS(  // ����Ӳ���첽��ʱ,���ú�ܿ췵��,������һ��������֮ǰ��ʱָ��������
    ULONG            iIndex,  // ָ��CH341�豸���
    ULONG            iDelay );  // ָ����ʱ�ĺ�����


BOOL    WINAPI    CH341StreamI2C(  // ����I2C������,2�߽ӿ�,ʱ����ΪSCL����,������ΪSDA����(׼˫��I/O),�ٶ�Լ56K�ֽ�
    ULONG            iIndex,  // ָ��CH341�豸���
    ULONG            iWriteLength,  // ׼��д���������ֽ���
    PVOID            iWriteBuffer,  // ָ��һ��������,����׼��д��������,���ֽ�ͨ����I2C�豸��ַ����д����λ
    ULONG            iReadLength,  // ׼����ȡ�������ֽ���
    PVOID            oReadBuffer );  // ָ��һ��������,���غ��Ƕ��������


BOOL    WINAPI    CH341SetOutput(  // ����CH341��I/O����,��ͨ��CH341ֱ���������
/* ***** ����ʹ�ø�API, ��ֹ�޸�I/O����ʹ�������ű�Ϊ������ŵ����������������֮���·����оƬ ***** */
    ULONG            iIndex,  // ָ��CH341�豸���
    ULONG            iEnable,  // ������Ч��־,�ο������λ˵��
// λ0Ϊ1˵��iSetDataOut��λ15-λ8��Ч,�������
// λ1Ϊ1˵��iSetDirOut��λ15-λ8��Ч,�������
// λ2Ϊ1˵��iSetDataOut��7-λ0��Ч,�������
// λ3Ϊ1˵��iSetDirOut��λ7-λ0��Ч,�������
// λ4Ϊ1˵��iSetDataOut��λ23-λ16��Ч,�������
    ULONG            iSetDirOut,  // ����I/O����,ĳλ��0���Ӧ����Ϊ����,ĳλ��1���Ӧ����Ϊ���,���ڷ�ʽ��Ĭ��ֵΪ0x000FC000,�ο������λ˵��
    ULONG            iSetDataOut );  // �������,���I/O����Ϊ���,��ôĳλ��0ʱ��Ӧ��������͵�ƽ,ĳλ��1ʱ��Ӧ��������ߵ�ƽ,�ο������λ˵��
// λ7-λ0��ӦCH341��D7-D0����
// λ8��ӦCH341��ERR#����, λ9��ӦCH341��PEMP����, λ10��ӦCH341��INT#����, λ11��ӦCH341��SLCT����
// λ13��ӦCH341��WAIT#����, λ14��ӦCH341��DATAS#/READ#����,λ15��ӦCH341��ADDRS#/ADDR/ALE����
// ��������ֻ�����,������I/O����: λ16��ӦCH341��RESET#����, λ17��ӦCH341��WRITE#����, λ18��ӦCH341��SCL����, λ29��ӦCH341��SDA����


BOOL    WINAPI    CH341Set_D5_D0(  // ����CH341��D5-D0���ŵ�I/O����,��ͨ��CH341��D5-D0����ֱ���������,Ч�ʱ�CH341SetOutput����
/* ***** ����ʹ�ø�API, ��ֹ�޸�I/O����ʹ�������ű�Ϊ������ŵ����������������֮���·����оƬ ***** */
    ULONG            iIndex,  // ָ��CH341�豸���
    ULONG            iSetDirOut,  // ����D5-D0�����ŵ�I/O����,ĳλ��0���Ӧ����Ϊ����,ĳλ��1���Ӧ����Ϊ���,���ڷ�ʽ��Ĭ��ֵΪ0x00ȫ������
    ULONG            iSetDataOut );  // ����D5-D0�����ŵ��������,���I/O����Ϊ���,��ôĳλ��0ʱ��Ӧ��������͵�ƽ,ĳλ��1ʱ��Ӧ��������ߵ�ƽ
// �������ݵ�λ5-λ0�ֱ��ӦCH341��D5-D0����


BOOL    WINAPI    CH341StreamSPI3(  // ��API��ʧЧ,����ʹ��
    ULONG            iIndex,
    ULONG            iChipSelect,
    ULONG            iLength,
    PVOID            ioBuffer );


BOOL    WINAPI    CH341StreamSPI4(  // ����SPI������,4�߽ӿ�,ʱ����ΪDCK/D3����,���������ΪDOUT/D5����,����������ΪDIN/D7����,Ƭѡ��ΪD0/D1/D2,�ٶ�Լ68K�ֽ�
/* SPIʱ��: DCK/D3����Ϊʱ�����, Ĭ��Ϊ�͵�ƽ, DOUT/D5������ʱ��������֮ǰ�ĵ͵�ƽ�ڼ����, DIN/D7������ʱ���½���֮ǰ�ĸߵ�ƽ�ڼ����� */
    ULONG            iIndex,  // ָ��CH341�豸���
    ULONG            iChipSelect,  // Ƭѡ����, λ7Ϊ0�����Ƭѡ����, λ7Ϊ1�������Ч: λ1λ0Ϊ00/01/10�ֱ�ѡ��D0/D1/D2������Ϊ�͵�ƽ��ЧƬѡ
    ULONG            iLength,  // ׼������������ֽ���
    PVOID            ioBuffer );  // ָ��һ��������,����׼����DOUTд��������,���غ��Ǵ�DIN���������


BOOL    WINAPI    CH341StreamSPI5(  // ����SPI������,5�߽ӿ�,ʱ����ΪDCK/D3����,���������ΪDOUT/D5��DOUT2/D4����,����������ΪDIN/D7��DIN2/D6����,Ƭѡ��ΪD0/D1/D2,�ٶ�Լ30K�ֽ�*2
/* SPIʱ��: DCK/D3����Ϊʱ�����, Ĭ��Ϊ�͵�ƽ, DOUT/D5��DOUT2/D4������ʱ��������֮ǰ�ĵ͵�ƽ�ڼ����, DIN/D7��DIN2/D6������ʱ���½���֮ǰ�ĸߵ�ƽ�ڼ����� */
    ULONG            iIndex,  // ָ��CH341�豸���
    ULONG            iChipSelect,  // Ƭѡ����, λ7Ϊ0�����Ƭѡ����, λ7Ϊ1�������Ч: λ1λ0Ϊ00/01/10�ֱ�ѡ��D0/D1/D2������Ϊ�͵�ƽ��ЧƬѡ
    ULONG            iLength,  // ׼������������ֽ���
    PVOID            ioBuffer,  // ָ��һ��������,����׼����DOUTд��������,���غ��Ǵ�DIN���������
    PVOID            ioBuffer2 );  // ָ��ڶ���������,����׼����DOUT2д��������,���غ��Ǵ�DIN2���������


BOOL    WINAPI    CH341BitStreamSPI(  // ����SPIλ������,4��/5�߽ӿ�,ʱ����ΪDCK/D3����,���������ΪDOUT/DOUT2����,����������ΪDIN/DIN2����,Ƭѡ��ΪD0/D1/D2,�ٶ�Լ8Kλ*2
    ULONG            iIndex,  // ָ��CH341�豸���
    ULONG            iLength,  // ׼�����������λ��,һ�����896,���鲻����256
    PVOID            ioBuffer );  // ָ��һ��������,����׼����DOUT/DOUT2/D2-D0д��������,���غ��Ǵ�DIN/DIN2���������
/* SPIʱ��: DCK/D3����Ϊʱ�����, Ĭ��Ϊ�͵�ƽ, DOUT/D5��DOUT2/D4������ʱ��������֮ǰ�ĵ͵�ƽ�ڼ����, DIN/D7��DIN2/D6������ʱ���½���֮ǰ�ĸߵ�ƽ�ڼ����� */
/* ioBuffer�е�һ���ֽڹ�8λ�ֱ��ӦD7-D0����, λ5�����DOUT, λ4�����DOUT2, λ2-λ0�����D2-D0, λ7��DIN����, λ6��DIN2����, λ3���ݺ��� */
/* �ڵ��ø�API֮ǰ,Ӧ���ȵ���CH341Set_D5_D0����CH341��D5-D0���ŵ�I/O����,���������ŵ�Ĭ�ϵ�ƽ */


BOOL    WINAPI    CH341SetBufUpload(  // �趨�ڲ������ϴ�ģʽ
    ULONG            iIndex,  // ָ��CH341�豸���,0��Ӧ��һ���豸
    ULONG            iEnableOrClear );  // Ϊ0���ֹ�ڲ������ϴ�ģʽ,ʹ��ֱ���ϴ�,��0�������ڲ������ϴ�ģʽ������������е���������
// ��������ڲ������ϴ�ģʽ,��ôCH341�������򴴽��߳��Զ�����USB�ϴ����ݵ��ڲ�������,ͬʱ����������е���������,��Ӧ�ó������CH341ReadData���������ػ������е���������


LONG    WINAPI    CH341QueryBufUpload(  // ��ѯ�ڲ��ϴ��������е��������ݰ�����,�ɹ��������ݰ�����,������-1
    ULONG            iIndex );  // ָ��CH341�豸���,0��Ӧ��һ���豸


BOOL    WINAPI    CH341SetBufDownload(  // �趨�ڲ������´�ģʽ
    ULONG            iIndex,  // ָ��CH341�豸���,0��Ӧ��һ���豸
    ULONG            iEnableOrClear );  // Ϊ0���ֹ�ڲ������´�ģʽ,ʹ��ֱ���´�,��0�������ڲ������´�ģʽ������������е���������
// ��������ڲ������´�ģʽ,��ô��Ӧ�ó������CH341WriteData�󽫽����ǽ�USB�´����ݷŵ��ڲ�����������������,����CH341�������򴴽����߳��Զ�����ֱ�����


LONG    WINAPI    CH341QueryBufDownload(  // ��ѯ�ڲ��´��������е�ʣ�����ݰ�����(��δ����),�ɹ��������ݰ�����,������-1
    ULONG            iIndex );  // ָ��CH341�豸���,0��Ӧ��һ���豸


BOOL    WINAPI    CH341ResetInter(  // ��λ�ж����ݶ�����
    ULONG            iIndex );  // ָ��CH341�豸���


BOOL    WINAPI    CH341ResetRead(  // ��λ���ݿ������
    ULONG            iIndex );  // ָ��CH341�豸���


BOOL    WINAPI    CH341ResetWrite(  // ��λ���ݿ�д����
    ULONG            iIndex );  // ָ��CH341�豸���


BOOL    WINAPI    CH341SetupSerial(  // �趨CH341�Ĵ�������,��APIֻ�����ڹ����ڴ��ڷ�ʽ��CH341оƬ
    ULONG                    iIndex,  // ָ��CH341�豸���,0��Ӧ��һ���豸
    ULONG                    iParityMode,  // ָ��CH341���ڵ�����У��ģʽ: NOPARITY/ODDPARITY/EVENPARITY/MARKPARITY/SPACEPARITY
    ULONG                    iBaudRate );  // ָ��CH341���ڵ�ͨѶ������ֵ,������50��3000000֮�������ֵ

