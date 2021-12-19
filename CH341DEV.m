 classdef CH341DEV
    properties
      usbid = 0;
    endproperties
    
    methods
      function obj = CH341DEV(id)
        obj.usbid = id;
        %dev_open(id);
      endfunction
      
      function rlst = swi2c(obj,i2c_id,reg_addr,wdata)
          if (isreal(i2c_id))
            id = i2c_id;
          else 
            id = hex2dec(i2c_id);
          endif
          
          if (isreal(reg_addr))
            raddr  = reg_addr;
          else 
            raddr = hex2dec(reg_addr);
          endif
          
          if (isreal(wdata))
            wd  = wdata;
          else 
            wd = hex2dec(wdata);
          endif       
          rlst = ch341_i2c_sw(obj.usbid,id,raddr,wd);
          if (rlst < 1)
            printf('i2c_id: %d, i2c_reg_addr: %x, wdata:%x\n',id,raddr,wd);    
        endif     
      endfunction
      
      function rlst = sri2c(obj,i2c_id,reg_addr)
          if (isreal(i2c_id))
            id = i2c_id;
          else 
            id = hex2dec(i2c_id);
          endif
          
          if (isreal(reg_addr))
            raddr  = reg_addr;
          else 
            raddr = hex2dec(reg_addr);
          endif  
          rlst = ch341_i2c_sr(obj.usbid,id,raddr);
      endfunction      
      
     function rlst = i2c_st2 (obj,i2c_id,wdata,read_num)
          if (isreal(i2c_id))
            id = i2c_id;
          else 
            id = hex2dec(i2c_id);
          endif
                   
          if (isreal(read_num))
            rnum  = read_num;
          else 
            rnum = hex2dec(read_num);
          endif  
          
          if(length(wdata) == 0) 
             wd_list = [];
          else 
            if (isreal(wdata) & isvector(wdata))
              wd_list  = wdata;
            else 
              disp("Error Wdata must be real & invector ...");
              rlst =  (-1);
            endif  
          endif          
          wd_len = length(wd_list) + 1;                   
          wd     = [id wd_list];
          
          rlst = ch341_i2c_st(obj.usbid,wd_len,wd,rnum);
      endfunction   
      
      
      function rlst = i2c_st(obj,i2c_id,reg_addr,wdata,read_num)
          if (isreal(i2c_id))
            id = i2c_id;
          else 
            id = hex2dec(i2c_id);
          endif
          
          if (isreal(reg_addr))
            raddr  = reg_addr;
          else 
            raddr = hex2dec(reg_addr);
          endif  
          
          if (isreal(read_num))
            rnum  = read_num;
          else 
            rnum = hex2dec(read_num);
          endif  
          
          if(length(wdata) == 0) 
             wd_list = [];
          else 
            if (isreal(wdata) & isvector(wdata))
              wd_list  = wdata;
            else 
              disp("Error Wdata must be real & invector ...");
              rlst =  (-1);
            endif  
          endif          
          wd_len = length(wd_list) + 2;                   
          wd     = [id raddr wd_list];
          
          rlst = ch341_i2c_st(obj.usbid,wd_len,wd,rnum);
      endfunction         
      
      function rlst = dev_open(obj)
          rlst = ch341_open_device(obj.usbid);
      endfunction
      
        
    endmethods
 endclassdef
