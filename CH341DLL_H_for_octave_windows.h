int    WINAPI    CH341OpenDevice(  ULONG    iIndex );  
VOID    WINAPI    CH341CloseDevice(  ULONG    iIndex ); 


BOOL    WINAPI    CH341InitParallel(  // 复位并初始化并口,RST#输出低电平脉冲
    ULONG            iIndex,  // 指定CH341设备序号
    ULONG            iMode );  // 指定并口模式: 0为EPP模式/EPP模式V1.7, 1为EPP模式V1.9, 2为MEM模式, >= 0x00000100 保持当前模式


BOOL    WINAPI    CH341ReadData0(  // 从0#端口读取数据块
    ULONG            iIndex,  // 指定CH341设备序号
    PVOID            oBuffer,  // 指向一个足够大的缓冲区,用于保存读取的数据
    PULONG            ioLength );  // 指向长度单元,输入时为准备读取的长度,返回后为实际读取的长度


BOOL    WINAPI    CH341ReadData1(  // 从1#端口读取数据块
    ULONG            iIndex,  // 指定CH341设备序号
    PVOID            oBuffer,  // 指向一个足够大的缓冲区,用于保存读取的数据
    PULONG            ioLength );  // 指向长度单元,输入时为准备读取的长度,返回后为实际读取的长度


BOOL    WINAPI    CH341AbortRead(  // 放弃数据块读操作
    ULONG            iIndex );  // 指定CH341设备序号


BOOL    WINAPI    CH341WriteData0(  // 向0#端口写出数据块
    ULONG            iIndex,  // 指定CH341设备序号
    PVOID            iBuffer,  // 指向一个缓冲区,放置准备写出的数据
    PULONG            ioLength );  // 指向长度单元,输入时为准备写出的长度,返回后为实际写出的长度


BOOL    WINAPI    CH341WriteData1(  // 向1#端口写出数据块
    ULONG            iIndex,  // 指定CH341设备序号
    PVOID            iBuffer,  // 指向一个缓冲区,放置准备写出的数据
    PULONG            ioLength );  // 指向长度单元,输入时为准备写出的长度,返回后为实际写出的长度


BOOL    WINAPI    CH341AbortWrite(  // 放弃数据块写操作
    ULONG            iIndex );  // 指定CH341设备序号


BOOL    WINAPI    CH341GetStatus(  // 通过CH341直接输入数据和状态
    ULONG            iIndex,  // 指定CH341设备序号
    PULONG            iStatus );  // 指向一个双字单元,用于保存状态数据,参考下面的位说明
// 位7-位0对应CH341的D7-D0引脚
// 位8对应CH341的ERR#引脚, 位9对应CH341的PEMP引脚, 位10对应CH341的INT#引脚, 位11对应CH341的SLCT引脚, 位23对应CH341的SDA引脚
// 位13对应CH341的BUSY/WAIT#引脚, 位14对应CH341的AUTOFD#/DATAS#引脚,位15对应CH341的SLCTIN#/ADDRS#引脚


BOOL    WINAPI    CH341ReadI2C(  // 从I2C接口读取一个字节数据
    ULONG            iIndex,  // 指定CH341设备序号
    UCHAR            iDevice,  // 低7位指定I2C设备地址
    UCHAR            iAddr,  // 指定数据单元的地址
    PUCHAR            oByte );  // 指向一个字节单元,用于保存读取的字节数据


BOOL    WINAPI    CH341WriteI2C(  // 向I2C接口写入一个字节数据
    ULONG            iIndex,  // 指定CH341设备序号
    UCHAR            iDevice,  // 低7位指定I2C设备地址
    UCHAR            iAddr,  // 指定数据单元的地址
    UCHAR            iByte );  // 待写入的字节数据


BOOL    WINAPI    CH341EppReadData(  // EPP方式读数据: WR#=1, DS#=0, AS#=1, D0-D7=input
    ULONG            iIndex,  // 指定CH341设备序号
    PVOID            oBuffer,  // 指向一个足够大的缓冲区,用于保存读取的数据
    PULONG            ioLength );  // 指向长度单元,输入时为准备读取的长度,返回后为实际读取的长度


BOOL    WINAPI    CH341EppReadAddr(  // EPP方式读地址: WR#=1, DS#=1, AS#=0, D0-D7=input
    ULONG            iIndex,  // 指定CH341设备序号
    PVOID            oBuffer,  // 指向一个足够大的缓冲区,用于保存读取的地址数据
    PULONG            ioLength );  // 指向长度单元,输入时为准备读取的长度,返回后为实际读取的长度


BOOL    WINAPI    CH341EppWriteData(  // EPP方式写数据: WR#=0, DS#=0, AS#=1, D0-D7=output
    ULONG            iIndex,  // 指定CH341设备序号
    PVOID            iBuffer,  // 指向一个缓冲区,放置准备写出的数据
    PULONG            ioLength );  // 指向长度单元,输入时为准备写出的长度,返回后为实际写出的长度


BOOL    WINAPI    CH341EppWriteAddr(  // EPP方式写地址: WR#=0, DS#=1, AS#=0, D0-D7=output
    ULONG            iIndex,  // 指定CH341设备序号
    PVOID            iBuffer,  // 指向一个缓冲区,放置准备写出的地址数据
    PULONG            ioLength );  // 指向长度单元,输入时为准备写出的长度,返回后为实际写出的长度


BOOL    WINAPI    CH341EppSetAddr(  // EPP方式设置地址: WR#=0, DS#=1, AS#=0, D0-D7=output
    ULONG            iIndex,  // 指定CH341设备序号
    UCHAR            iAddr );  // 指定EPP地址


BOOL    WINAPI    CH341MemReadAddr0(  // MEM方式读地址0: WR#=1, DS#/RD#=0, AS#/ADDR=0, D0-D7=input
    ULONG            iIndex,  // 指定CH341设备序号
    PVOID            oBuffer,  // 指向一个足够大的缓冲区,用于保存从地址0读取的数据
    PULONG            ioLength );  // 指向长度单元,输入时为准备读取的长度,返回后为实际读取的长度


BOOL    WINAPI    CH341MemReadAddr1(  // MEM方式读地址1: WR#=1, DS#/RD#=0, AS#/ADDR=1, D0-D7=input
    ULONG            iIndex,  // 指定CH341设备序号
    PVOID            oBuffer,  // 指向一个足够大的缓冲区,用于保存从地址1读取的数据
    PULONG            ioLength );  // 指向长度单元,输入时为准备读取的长度,返回后为实际读取的长度


BOOL    WINAPI    CH341MemWriteAddr0(  // MEM方式写地址0: WR#=0, DS#/RD#=1, AS#/ADDR=0, D0-D7=output
    ULONG            iIndex,  // 指定CH341设备序号
    PVOID            iBuffer,  // 指向一个缓冲区,放置准备向地址0写出的数据
    PULONG            ioLength );  // 指向长度单元,输入时为准备写出的长度,返回后为实际写出的长度


BOOL    WINAPI    CH341MemWriteAddr1(  // MEM方式写地址1: WR#=0, DS#/RD#=1, AS#/ADDR=1, D0-D7=output
    ULONG            iIndex,  // 指定CH341设备序号
    PVOID            iBuffer,  // 指向一个缓冲区,放置准备向地址1写出的数据
    PULONG            ioLength );  // 指向长度单元,输入时为准备写出的长度,返回后为实际写出的长度


BOOL    WINAPI    CH341SetExclusive(  // 设置独占使用当前CH341设备
    ULONG            iIndex,  // 指定CH341设备序号
    ULONG            iExclusive );  // 为0则设备可以共享使用,非0则独占使用


BOOL    WINAPI    CH341SetTimeout(  // 设置USB数据读写的超时
    ULONG            iIndex,  // 指定CH341设备序号
    ULONG            iWriteTimeout,  // 指定USB写出数据块的超时时间,以毫秒mS为单位,0xFFFFFFFF指定不超时(默认值)
    ULONG            iReadTimeout );  // 指定USB读取数据块的超时时间,以毫秒mS为单位,0xFFFFFFFF指定不超时(默认值)


BOOL    WINAPI    CH341ReadData(  // 读取数据块
    ULONG            iIndex,  // 指定CH341设备序号
    PVOID            oBuffer,  // 指向一个足够大的缓冲区,用于保存读取的数据
    PULONG            ioLength );  // 指向长度单元,输入时为准备读取的长度,返回后为实际读取的长度


BOOL    WINAPI    CH341WriteData(  // 写出数据块
    ULONG            iIndex,  // 指定CH341设备序号
    PVOID            iBuffer,  // 指向一个缓冲区,放置准备写出的数据
    PULONG            ioLength );  // 指向长度单元,输入时为准备写出的长度,返回后为实际写出的长度


PVOID    WINAPI    CH341GetDeviceName(  // 返回指向CH341设备名称的缓冲区,出错则返回NULL
    ULONG            iIndex );  // 指定CH341设备序号,0对应第一个设备


ULONG    WINAPI    CH341GetVerIC(  // 获取CH341芯片的版本,返回:0=设备无效,0x10=CH341,0x20=CH341A
    ULONG            iIndex );  // 指定CH341设备序号
#define        IC_VER_CH341A        0x20
#define        IC_VER_CH341A3        0x30


BOOL    WINAPI    CH341FlushBuffer(  // 清空CH341的缓冲区
    ULONG            iIndex );  // 指定CH341设备序号


BOOL    WINAPI    CH341WriteRead(  // 执行数据流命令,先输出再输入
    ULONG            iIndex,  // 指定CH341设备序号
    ULONG            iWriteLength,  // 写长度,准备写出的长度
    PVOID            iWriteBuffer,  // 指向一个缓冲区,放置准备写出的数据
    ULONG            iReadStep,  // 准备读取的单个块的长度, 准备读取的总长度为(iReadStep*iReadTimes)
    ULONG            iReadTimes,  // 准备读取的次数
    PULONG            oReadLength,  // 指向长度单元,返回后为实际读取的长度
    PVOID            oReadBuffer );  // 指向一个足够大的缓冲区,用于保存读取的数据


BOOL    WINAPI    CH341SetStream(  // 设置串口流模式
    ULONG            iIndex,  // 指定CH341设备序号
    ULONG            iMode );  // 指定模式,见下行
// 位1-位0: I2C接口速度/SCL频率, 00=低速/20KHz,01=标准/100KHz(默认值),10=快速/400KHz,11=高速/750KHz
// 位2:     SPI的I/O数/IO引脚, 0=单入单出(D3时钟/D5出/D7入)(默认值),1=双入双出(D3时钟/D5出D4出/D7入D6入)
// 位7:     SPI字节中的位顺序, 0=低位在前, 1=高位在前
// 其它保留,必须为0


BOOL    WINAPI    CH341SetDelaymS(  // 设置硬件异步延时,调用后很快返回,而在下一个流操作之前延时指定毫秒数
    ULONG            iIndex,  // 指定CH341设备序号
    ULONG            iDelay );  // 指定延时的毫秒数


BOOL    WINAPI    CH341StreamI2C(  // 处理I2C数据流,2线接口,时钟线为SCL引脚,数据线为SDA引脚(准双向I/O),速度约56K字节
    ULONG            iIndex,  // 指定CH341设备序号
    ULONG            iWriteLength,  // 准备写出的数据字节数
    PVOID            iWriteBuffer,  // 指向一个缓冲区,放置准备写出的数据,首字节通常是I2C设备地址及读写方向位
    ULONG            iReadLength,  // 准备读取的数据字节数
    PVOID            oReadBuffer );  // 指向一个缓冲区,返回后是读入的数据


BOOL    WINAPI    CH341SetOutput(  // 设置CH341的I/O方向,并通过CH341直接输出数据
/* ***** 谨慎使用该API, 防止修改I/O方向使输入引脚变为输出引脚导致与其它输出引脚之间短路而损坏芯片 ***** */
    ULONG            iIndex,  // 指定CH341设备序号
    ULONG            iEnable,  // 数据有效标志,参考下面的位说明
// 位0为1说明iSetDataOut的位15-位8有效,否则忽略
// 位1为1说明iSetDirOut的位15-位8有效,否则忽略
// 位2为1说明iSetDataOut的7-位0有效,否则忽略
// 位3为1说明iSetDirOut的位7-位0有效,否则忽略
// 位4为1说明iSetDataOut的位23-位16有效,否则忽略
    ULONG            iSetDirOut,  // 设置I/O方向,某位清0则对应引脚为输入,某位置1则对应引脚为输出,并口方式下默认值为0x000FC000,参考下面的位说明
    ULONG            iSetDataOut );  // 输出数据,如果I/O方向为输出,那么某位清0时对应引脚输出低电平,某位置1时对应引脚输出高电平,参考下面的位说明
// 位7-位0对应CH341的D7-D0引脚
// 位8对应CH341的ERR#引脚, 位9对应CH341的PEMP引脚, 位10对应CH341的INT#引脚, 位11对应CH341的SLCT引脚
// 位13对应CH341的WAIT#引脚, 位14对应CH341的DATAS#/READ#引脚,位15对应CH341的ADDRS#/ADDR/ALE引脚
// 以下引脚只能输出,不考虑I/O方向: 位16对应CH341的RESET#引脚, 位17对应CH341的WRITE#引脚, 位18对应CH341的SCL引脚, 位29对应CH341的SDA引脚


BOOL    WINAPI    CH341Set_D5_D0(  // 设置CH341的D5-D0引脚的I/O方向,并通过CH341的D5-D0引脚直接输出数据,效率比CH341SetOutput更高
/* ***** 谨慎使用该API, 防止修改I/O方向使输入引脚变为输出引脚导致与其它输出引脚之间短路而损坏芯片 ***** */
    ULONG            iIndex,  // 指定CH341设备序号
    ULONG            iSetDirOut,  // 设置D5-D0各引脚的I/O方向,某位清0则对应引脚为输入,某位置1则对应引脚为输出,并口方式下默认值为0x00全部输入
    ULONG            iSetDataOut );  // 设置D5-D0各引脚的输出数据,如果I/O方向为输出,那么某位清0时对应引脚输出低电平,某位置1时对应引脚输出高电平
// 以上数据的位5-位0分别对应CH341的D5-D0引脚


BOOL    WINAPI    CH341StreamSPI3(  // 该API已失效,请勿使用
    ULONG            iIndex,
    ULONG            iChipSelect,
    ULONG            iLength,
    PVOID            ioBuffer );


BOOL    WINAPI    CH341StreamSPI4(  // 处理SPI数据流,4线接口,时钟线为DCK/D3引脚,输出数据线为DOUT/D5引脚,输入数据线为DIN/D7引脚,片选线为D0/D1/D2,速度约68K字节
/* SPI时序: DCK/D3引脚为时钟输出, 默认为低电平, DOUT/D5引脚在时钟上升沿之前的低电平期间输出, DIN/D7引脚在时钟下降沿之前的高电平期间输入 */
    ULONG            iIndex,  // 指定CH341设备序号
    ULONG            iChipSelect,  // 片选控制, 位7为0则忽略片选控制, 位7为1则参数有效: 位1位0为00/01/10分别选择D0/D1/D2引脚作为低电平有效片选
    ULONG            iLength,  // 准备传输的数据字节数
    PVOID            ioBuffer );  // 指向一个缓冲区,放置准备从DOUT写出的数据,返回后是从DIN读入的数据


BOOL    WINAPI    CH341StreamSPI5(  // 处理SPI数据流,5线接口,时钟线为DCK/D3引脚,输出数据线为DOUT/D5和DOUT2/D4引脚,输入数据线为DIN/D7和DIN2/D6引脚,片选线为D0/D1/D2,速度约30K字节*2
/* SPI时序: DCK/D3引脚为时钟输出, 默认为低电平, DOUT/D5和DOUT2/D4引脚在时钟上升沿之前的低电平期间输出, DIN/D7和DIN2/D6引脚在时钟下降沿之前的高电平期间输入 */
    ULONG            iIndex,  // 指定CH341设备序号
    ULONG            iChipSelect,  // 片选控制, 位7为0则忽略片选控制, 位7为1则参数有效: 位1位0为00/01/10分别选择D0/D1/D2引脚作为低电平有效片选
    ULONG            iLength,  // 准备传输的数据字节数
    PVOID            ioBuffer,  // 指向一个缓冲区,放置准备从DOUT写出的数据,返回后是从DIN读入的数据
    PVOID            ioBuffer2 );  // 指向第二个缓冲区,放置准备从DOUT2写出的数据,返回后是从DIN2读入的数据


BOOL    WINAPI    CH341BitStreamSPI(  // 处理SPI位数据流,4线/5线接口,时钟线为DCK/D3引脚,输出数据线为DOUT/DOUT2引脚,输入数据线为DIN/DIN2引脚,片选线为D0/D1/D2,速度约8K位*2
    ULONG            iIndex,  // 指定CH341设备序号
    ULONG            iLength,  // 准备传输的数据位数,一次最多896,建议不超过256
    PVOID            ioBuffer );  // 指向一个缓冲区,放置准备从DOUT/DOUT2/D2-D0写出的数据,返回后是从DIN/DIN2读入的数据
/* SPI时序: DCK/D3引脚为时钟输出, 默认为低电平, DOUT/D5和DOUT2/D4引脚在时钟上升沿之前的低电平期间输出, DIN/D7和DIN2/D6引脚在时钟下降沿之前的高电平期间输入 */
/* ioBuffer中的一个字节共8位分别对应D7-D0引脚, 位5输出到DOUT, 位4输出到DOUT2, 位2-位0输出到D2-D0, 位7从DIN输入, 位6从DIN2输入, 位3数据忽略 */
/* 在调用该API之前,应该先调用CH341Set_D5_D0设置CH341的D5-D0引脚的I/O方向,并设置引脚的默认电平 */


BOOL    WINAPI    CH341SetBufUpload(  // 设定内部缓冲上传模式
    ULONG            iIndex,  // 指定CH341设备序号,0对应第一个设备
    ULONG            iEnableOrClear );  // 为0则禁止内部缓冲上传模式,使用直接上传,非0则启用内部缓冲上传模式并清除缓冲区中的已有数据
// 如果启用内部缓冲上传模式,那么CH341驱动程序创建线程自动接收USB上传数据到内部缓冲区,同时清除缓冲区中的已有数据,当应用程序调用CH341ReadData后将立即返回缓冲区中的已有数据


LONG    WINAPI    CH341QueryBufUpload(  // 查询内部上传缓冲区中的已有数据包个数,成功返回数据包个数,出错返回-1
    ULONG            iIndex );  // 指定CH341设备序号,0对应第一个设备


BOOL    WINAPI    CH341SetBufDownload(  // 设定内部缓冲下传模式
    ULONG            iIndex,  // 指定CH341设备序号,0对应第一个设备
    ULONG            iEnableOrClear );  // 为0则禁止内部缓冲下传模式,使用直接下传,非0则启用内部缓冲下传模式并清除缓冲区中的已有数据
// 如果启用内部缓冲下传模式,那么当应用程序调用CH341WriteData后将仅仅是将USB下传数据放到内部缓冲区并立即返回,而由CH341驱动程序创建的线程自动发送直到完毕


LONG    WINAPI    CH341QueryBufDownload(  // 查询内部下传缓冲区中的剩余数据包个数(尚未发送),成功返回数据包个数,出错返回-1
    ULONG            iIndex );  // 指定CH341设备序号,0对应第一个设备


BOOL    WINAPI    CH341ResetInter(  // 复位中断数据读操作
    ULONG            iIndex );  // 指定CH341设备序号


BOOL    WINAPI    CH341ResetRead(  // 复位数据块读操作
    ULONG            iIndex );  // 指定CH341设备序号


BOOL    WINAPI    CH341ResetWrite(  // 复位数据块写操作
    ULONG            iIndex );  // 指定CH341设备序号


BOOL    WINAPI    CH341SetupSerial(  // 设定CH341的串口特性,该API只能用于工作于串口方式的CH341芯片
    ULONG                    iIndex,  // 指定CH341设备序号,0对应第一个设备
    ULONG                    iParityMode,  // 指定CH341串口的数据校验模式: NOPARITY/ODDPARITY/EVENPARITY/MARKPARITY/SPACEPARITY
    ULONG                    iBaudRate );  // 指定CH341串口的通讯波特率值,可以是50至3000000之间的任意值

