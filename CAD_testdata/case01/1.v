module top ( a0 , a1 , b0 , b1 , c , h0 , h1 , m0 , m1 ) ;
    input a0 , a1 , b1 , b0 , c ;
    output h0 , h1 , m0 , m1 ;
    wire n1 , n2 , n3 , n4 , n5 ;
assign n1 = ~b1;
assign n2 = ~a0;
assign h0 = a0 & b0;
assign n3 = ~(a1 & b0);
assign n4 = n1 | n2;
assign n5 = ~(b0 & c);
assign h1 = n3 ^ n4;
assign m0 = ~(b1 ^ n5);
assign m1 = b0 ^ c;
endmodule
