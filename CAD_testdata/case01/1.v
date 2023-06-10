module top ( 1_a0 , 1_a1 , 1_b0 , 1_b1 , 1_c , 1_h0 , 1_h1 , 1_m0 , 1_m1 ) ;
    input 1_a0 , 1_a1 , 1_b1 , 1_b0 , 1_c ;
    output 1_h0 , 1_h1 , 1_m0 , 1_m1 ;
    wire 1_n1 , 1_n2 , 1_n3 , 1_n4 , 1_n5 ;
assign 1_n1 = ~1_b1;
assign 1_n2 = ~1_a0;
assign 1_h0 = 1_a0 & 1_b0;
assign 1_n3 = ~(1_a1 & 1_b0);
assign 1_n4 = 1_n1 | 1_n2;
assign 1_n5 = ~(1_b0 & 1_c);
assign 1_h1 = 1_n3 ^ 1_n4;
assign 1_m0 = ~(1_b1 ^ 1_n5);
assign 1_m1 = 1_b0 ^ 1_c;
endmodule
