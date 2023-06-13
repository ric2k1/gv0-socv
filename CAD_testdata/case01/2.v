module top ( x0 , x1 , y0 , y1 , z , u0 , u1 , w0 , w1 ) ;
    input x0 , x1 , y0 , y1 , z ;
    output u0 , u1 , w0 , w1 ;
    wire n1 , n2 , n3 ;
assign n1 = ~(x1 & y0);
assign n2 = ~(x0 & y1);
assign n3 = ~(y0 & z);
assign u0 = y0 & x0;
assign u1 = n1 ^ n2;
assign w0 = ~(y1 ^ n3);
assign w1 = y0 ^ z;
endmodule
