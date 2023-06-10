module top ( 2_x0 , 2_x1 , 2_y0 , 2_y1 , 2_z , 2_u0 , 2_u1 , 2_w0 , 2_w1 ) ;
    input 2_x0 , 2_x1 , 2_y0 , 2_y1 , 2_z ;
    output 2_u0 , 2_u1 , 2_w0 , 2_w1 ;
    wire 2_n1 , 2_n2 , 2_n3 ;
assign 2_n1 = ~(2_x1 & 2_y0);
assign 2_n2 = ~(2_x0 & 2_y1);
assign 2_n3 = ~(2_y0 & 2_z);
assign 2_u0 = 2_y0 & 2_x0;
assign 2_u1 = 2_n1 ^ 2_n2;
assign 2_w0 = ~(2_y1 ^ 2_n3);
assign 2_w1 = 2_y0 ^ 2_z;
endmodule
