/*
 * Written by jimjiang2
 *  thanks to  CARSTEN ARNHOLM:  https://arnholm.org/octave-plug-in-calling-msvc
 *      dac922: https://github.com/dac922 
 *      BH5HSV, https://www.cnblogs.com/lyuyangly/p/8709195.html
 * v0.1        
 */

#include <octave/oct.h>
#include <octave/parse.h>
#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include "CH341DLL_H_for_octave_windows.h"

// CH341DLL Functions Prototype
typedef int   WINAPI(*CH341OpenDevice_fn)(unsigned int iIndex);

typedef void (*CH341CloseDevice_fn)(unsigned int iIndex);

typedef BOOL WINAPI(*CH341SetStream_fn)(
        unsigned int     iIndex,
        unsigned int     iMode);

typedef BOOL WINAPI(*CH341StreamI2C_fn)(
        unsigned int    iIndex,
        unsigned int    iWriteLength,
        void *            iWriteBuffer,
        unsigned int    iReadLength,
        void *            oReadBuffer);

typedef BOOL    WINAPI(*CH341ReadI2C_fn) (  // 从I2C接口读取一个字节数据
        unsigned int     iIndex,  // 指定CH341设备序号
        uint8_t    iDevice,  // 低7位指定I2C设备地址
        uint8_t    iAddr,  // 指定数据单元的地址
        void *           oByte );  // 指向一个字节单元,用于保存读取的字节数据


typedef BOOL    WINAPI(*CH341WriteI2C_fn)(  // 向I2C接口写入一个字节数据
        unsigned int     iIndex,  // 指定CH341设备序号
        uint8_t    iDevice,  // 低7位指定I2C设备地址
        uint8_t     iAddr,  // 指定数据单元的地址
        uint8_t     iByte );  // 待写入的字节数据


//CH341OpenDevice_fn  USBIO_OpenDevice    = (CH341OpenDevice_fn)    GetProcAddress(hdll, "CH341OpenDevice");
//CH341CloseDevice_fn USBIO_CloseDevice   = (CH341CloseDevice_fn)    GetProcAddress(hdll, "CH341CloseDevice");
//CH341SetStream_fn   USBIO_SetStream     = (CH341SetStream_fn)    GetProcAddress(hdll, "CH341SetStream");
//CH341StreamI2C_fn   USBIO_StreamI2C     = (CH341StreamI2C_fn)    GetProcAddress(hdll, "CH341StreamI2C");


static int isinit=0;
static  HMODULE hdll; 
CH341OpenDevice_fn  USBIO_OpenDevice    ; //(CH341OpenDevice_fn)    GetProcAddress(hdll, "CH341OpenDevice");
CH341CloseDevice_fn USBIO_CloseDevice   ; //(CH341CloseDevice_fn)    GetProcAddress(hdll, "CH341CloseDevice");
CH341SetStream_fn   USBIO_SetStream     ; //(CH341SetStream_fn)    GetProcAddress(hdll, "CH341SetStream");
CH341StreamI2C_fn   USBIO_StreamI2C     ; //(CH341StreamI2C_fn)    GetProcAddress(hdll, "CH341StreamI2C");
CH341WriteI2C_fn    USBIO_I2CWrite     ; //(CH341StreamI2C_fn)    GetProcAddress(hdll, "CH341StreamI2C");
CH341ReadI2C_fn     USBIO_I2CRead; //(CH341StreamI2C_fn)    GetProcAddress(hdll, "CH341StreamI2C");

void ch341_init(void) {
    int i;
    if (isinit == 0) {
        octave_stdout << "############################################################# " <<  "\n";
        octave_stdout << "#  ch341dll  wrap for octave windows 32bits!!!!!!!!!        # " <<  "\n";
        octave_stdout << "############################################################# " <<  "\n";
    } else {
        return;
    }
    hdll = LoadLibrary("CH341DLL.DLL");

    if(NULL == hdll) {
        octave_stdout <<"USB_I2C CH341DLL Load Failed!" << std::endl;
        return;
    }    
    USBIO_OpenDevice    = (CH341OpenDevice_fn)   GetProcAddress(hdll, "CH341OpenDevice");
    USBIO_CloseDevice   = (CH341CloseDevice_fn)  GetProcAddress(hdll, "CH341CloseDevice");
    USBIO_SetStream     = (CH341SetStream_fn)    GetProcAddress(hdll, "CH341SetStream");
    USBIO_StreamI2C     = (CH341StreamI2C_fn)    GetProcAddress(hdll, "CH341StreamI2C");
    USBIO_I2CWrite      = (CH341WriteI2C_fn)    GetProcAddress(hdll, "CH341WriteI2C");
    USBIO_I2CRead       = (CH341ReadI2C_fn)    GetProcAddress(hdll, "CH341ReadI2C");
    isinit = 1;
}

DEFUN_DLD(ch341_open_device,args,,"open ch341 device")
{
    octave_value_list retval;
    int ch341_id = 0;
    int retv ;
    ch341_init();

    if ( args.length() > 0) {
        ch341_id = args(0).int_value();
    } else {
        octave_stdout << "You must set CH341 device index,START from 0 ... \n";
        retval.append(octave_value(-1));
        return retval;
    }

    // call function in dll:
    octave_stdout << "#try to open ch341 device index " << ch341_id  <<  "\n";
    if ( USBIO_OpenDevice(ch341_id) > 0) {    
        octave_stdout << "#open ch341 device index " << ch341_id  <<  " ok ----!!!\n";
        retval.append(octave_value(1));
    } else {
        retval.append(octave_value(-1));
        octave_stdout << "#open ch341 device index " << ch341_id  <<  " Fail , pls check your USB--ch341!!-Error\n";
    }
    return retval;
}

DEFUN_DLD(ch341_i2c_sw ,args,,"ch341 i2c single write")
{
    octave_value_list retval;
    unsigned int ch341_id = 0;
    unsigned int iDevice  = 0;
    unsigned int iAddr    = 0;
    unsigned int iByte = 0;
    unsigned int argindex = 0;
    int retv ;
    ch341_init();

    if ( args.length() > 3) {
        //ch341_id = 0xff & (args[argindex ++ ].int_value());
        //iDevice  = 0xff & (args[argindex ++ ].int_value());
        //iAddr    = 0xff & (args[argindex ++ ].int_value());
        //iByte    = 0xff & (args[argindex ++ ].int_value());
        ch341_id = 0xff & (args(0).int_value());
        iDevice  = 0xff & (args(1).int_value());
        iAddr    = 0xff & (args(2).int_value());
        iByte    = 0xff & (args(3).int_value());
    } else {
        octave_stdout << "i2c write need , ch341id, i2c_device_id , iAddr, wByte  ... \n";
        retval.append(octave_value(-1));
        return retval;
    }

    // call function in dll:
    retv = USBIO_I2CWrite(ch341_id,iDevice,iAddr,iByte); 
    if( retv >  0 ) {
        octave_stdout << "#i2c write done !\n";
        retval.append(octave_value(1));
    } else {
        octave_stdout << "i2c write i2c_id=" << iDevice << " iAddr=" << iAddr << " Wdata=" << iByte << " returnV=" << retv << "\n";
        octave_stdout << "#i2c write maybe fail ......  Error !\n";
        retval.append(octave_value(-1));
    }
    return retval;

}

DEFUN_DLD(ch341_i2c_sr ,args,,"ch341 i2c single read")
{
    octave_value_list retval;
    int ch341_id = 0;
    int iDevice  = 0;
    int iAddr    = 0;
    uint8_t oByte[3];
    int argindex = 0;
    int retv ;
    ch341_init();

    if ( args.length() > 2) {
        ch341_id = args(argindex ++ ).int_value();
        iDevice  = args(argindex ++ ).int_value();
        iAddr    = args(argindex ++ ).int_value();
    } else {
        //octave_stdout << "debug: i2c single read need , ch341id, i2c_device_id , iAddr 3args... \n";
        retval.append(octave_value(-1));
        return retval;
    }
    // call function in dll:
    if( USBIO_I2CRead(ch341_id,iDevice,iAddr,oByte) > 0 ) {
        octave_stdout << "#i2c read done RegAddr: " << iAddr << "get_rdata =" << int(oByte[0]) << "\n";
        retval.append(octave_value(oByte[0]));
    } else {
        retval.append(octave_value(-1));
    }
    return retval;

}

DEFUN_DLD(ch341_close_device,args,,"close ch341 device")
{
    octave_value_list retval;
    int ch341_id = 0;
    int retv ;
    ch341_init();

    if ( args.length() > 0) {
        ch341_id = args(0).int_value();
    } else {
        octave_stdout << "You must set CH341 device index,START from 0 ... \n";
        retval.append(octave_value(-1));
        return retval;
    }

    // call function in dll:
    USBIO_CloseDevice(ch341_id);
    octave_stdout << "#close ch341 device index " << ch341_id  <<  " Done ----!!!\n";
    retval.append(octave_value(1));
    return retval;
}

DEFUN_DLD(ch341_i2c_st ,args,,"ch341 i2c stream")
{
    octave_value_list retval;
    int ch341_id = 0;
    int wlen  = 0;
    int r_num    = 0;
    uint8_t iByte[4096];
    uint8_t oByte[4096];
    int32NDArray  wd_array;
    int argindex = 0;
    int retv ;
    int ii; 
    ch341_init();

    if ( args.length() > 3) {
        ch341_id = args(argindex ++ ).int_value();
        wlen     = args(argindex ++ ).int_value();
        wd_array = args(argindex ++ ).int32_array_value();
        r_num    = args(argindex ++ ).int_value();

        for(ii=0; ii < wlen; ii++) {
            iByte[ii] = uint8_t(0xff & wd_array(ii));
        }
    } else {
        //octave_stdout << "debug: i2c stream , ch341id, wlen , wdata_list, rnum --4args... \n";
        retval.append(octave_value(-1));
        return retval;
    }

    // call function in dll:
    //typedef BOOL WINAPI(*CH341StreamI2C_fn)(
    //    unsigned int    iIndex,
    //    unsigned int    iWriteLength,
    //    void *            iWriteBuffer,
    //    unsigned int    iReadLength,
    //    void *            oReadBuffer);
    if( USBIO_StreamI2C(ch341_id,wlen,iByte,r_num,oByte) > 0 ) {
        //octave_stdout << "#debug: i2c_stream Done ok: wlen=" << wlen << " rnum="<< r_num <<"\n";
        if (r_num == 0) 
            retval.append(octave_value(1));	
        for(ii=0; ii < r_num ; ii++) {
            retval.append(octave_value(oByte[ii]));
        }
    } else {
        octave_stdout << "#Error i2c read done RegAddr: " << r_num << "get_rdata =" << int(oByte[0]) << "\n";
        retval.append(octave_value(-1));
    }
    return retval;
}


//////DEFUN_DLD(ch341_close,args,,"close ch341 sessions")
////octave_value_list  ch341_close(octave_value_list args)
////{
////    octave_value_list retval;
////    int i;
////    int vid,nargin;
////    ViStatus vierr;
////
////    if (isinit) {
////            
////        nargin = args.length();
////        
////        if (nargin == 1) {
////            for (i=0;i<MAX_VISA;i++) {
////                if (VISA_device_session[i].init) {
////                    vierr = viClose(VISA_device_session[i].vid);
////                    dbgprintf("%s: device %d - %d\n",__func__,i,vierr);
////                    if (vierr == VI_SUCCESS) {
////                        VISA_device_session[i].vid = VI_NULL;
////                        VISA_device_session[i].init = 0;
////                        VISA_device_session[i].name.clear();
////                    }
////                }
////            }
////            vierr = viClose(VISA_session);
////            dbgprintf("%s: session %d\n",__func__,vierr);
////            isinit = 0;
////            
////        } else {
////        
////            vid = args(1).int_value();
////            
////            if (VISA_device_session[vid].init)
////                    vierr = viClose(VISA_device_session[vid].vid);
////                    dbgprintf("%s: device %d - %d\n",__func__,vid,vierr);
////                    if (vierr == VI_SUCCESS) {
////                        VISA_device_session[vid].vid = VI_NULL;
////                        VISA_device_session[vid].init = 0;
////                        VISA_device_session[vid].name.clear();
////                    }
////        }
////        
////        retval.append(octave_value(vierr));
////    } else {
////        dbgprintf("%s: ch341 not initialised\n",__func__);
////        //warning("ch341 not initialised");
////    }
////    
////    return retval;
////}
////
//////DEFUN_DLD(ch341_write,args,,"write ch341")
////octave_value_list ch341_write(octave_value_list args)
////{
////    octave_value_list retval;
////    charMatrix data;
////    char *cdata;
////    
////    int vid;
////    ViStatus vierr;
////    ViUInt32 actwrite;
////    
////    vid=args(1).int_value();
////
////    if (VISA_device_session[vid].init == 0) {
////        warning("ch341: nothing initialised");
////        octave_stdout << "in fuction ch341_write , this is not a valid vid = " << vid << "\n";
////        return retval;
////    }
////    
////    data = args(2).char_matrix_value();
////    cdata = (char*)malloc(sizeof(char)*data.cols());
////
////    for (int i=0;i<data.cols();i++)
////        cdata[i]=data.elem(0,i);
////
////    vierr = viWrite(VISA_device_session[vid].vid, (ViBuf) cdata, data.cols(), &actwrite);
////    dbgprintf("%s: vid %d - err %d - actwrite: %d\n",__func__,vid,vierr,actwrite);
////    
////    if (vierr == VI_SUCCESS) {
////        retval.append(octave_value(actwrite));
////        retval.append(octave_value(vierr));
////    }
////    
////    free(cdata);
////    
////    return retval;
////
////}
////
//////DEFUN_DLD(ch341_read,args,,"read ch341")
////octave_value_list ch341_read(octave_value_list args) 
////{
////    octave_value_list retval;
////
////    char *cdata;
////
////    int vid;
////    ViStatus vierr;
////    ViUInt32 readbytes,readcount,actread;
////
////    vid=args(1).int_value();
////    readbytes=args(2).int_value();
////
////    cdata = (char *)malloc(sizeof(char)*readbytes);
////    
////    readcount = 0;
////
////#if 0
////    while (readcount < readbytes) {    
////        vierr = viRead(VISA_device_session[vid].vid, (ViBuf) (cdata+readcount), readbytes-readcount, &actread);
////        dbgprintf("%s: vid %d - err %d - actread: %d\n",__func__,vid,vierr,actread);
////        if (vierr == VI_SUCCESS) {
////            readcount = readcount + actread;
////            //retval.append(octave_value(actwrite));
////            //retval.append(octave_value(vierr));
////            if (actread < 1) break;
////        } else
////            break;
////    }
////#else
////    vierr = viRead(VISA_device_session[vid].vid, (ViBuf) (cdata), readbytes, &actread);
////    dbgprintf("%s: vid %d - err %d - actread: %d\n",__func__,vid,vierr,actread);
////    readcount = actread;
////#endif
////
////    
////    if (readcount > 0) {
////
////        charMatrix values(1,readcount);
////    
////        for (int i=0;i<readcount;i++)
////            values(0,i) = *(cdata+i);
////            
////        retval.append(values);
////        
////    } else {
////        charMatrix values(0,0);
////        retval.append(values);
////    }
////    
////    //memcpy(values.data(),cdata,sizeof(char)*readcount);
////    
////    retval.append(octave_value(vierr));
////    retval.append(octave_value(actread));
////    
////    free(cdata);
////    
////    return retval;
////}
////
////DEFUN_DLD(ch341_windows_wrap,args,,"NI ch34132 windows wrap")
////{
////    octave_value_list retval;
////    int ch341_id = -1;
////    int i;
////    int func_ind;
////    int nargin;
////    ViStatus vierr;
////    ViSession vid;
////
////    ch341_init();
////
////    nargin = args.length();
////    if (nargin < 2 ) {
////        octave_stdout << "Hello World has " << args.length () << " input arguments and \n";    
////    }
////
////    func_ind              = args(0).int_value();
////    if (func_ind == 0) {
////        retval = ch341_open(args);
////        if (vierr == VI_SUCCESS) {
////            octave_stdout << "Open " << args(1).string_value() << " ok !!\n";    
////        } else {
////            retval.append(octave_value(-1));
////            octave_stdout << "Error ! " << args(1).string_value() << " Fail!!!!\n";    
////        }
////    } else if (func_ind == 1)  {
////        retval = ch341_write(args);
////    } else if (func_ind == 2)  {
////        retval = ch341_read(args);
////    } else if (func_ind == 3)  {
////        retval = ch341_close(args);
////    } else {
////        retval.append(octave_value(-1));
////    }
////
////    //    
////    //    dbgprintf("%s: %d\n",__func__,vierr);
////    return retval;
////}
