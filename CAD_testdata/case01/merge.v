// Benchmark "top" written by ABC on Mon Jun 12 20:57:39 2023

module top ( 
    \1_a0 , \1_a1 , \1_b0 , \1_b1 , \1_c , \2_x0 , \2_x1 , \2_y0 , \2_y1 ,
    \2_z ,
    \1_h0 , \1_h1 , \1_m0 , \1_m1 , \2_u0 , \2_u1 , \2_w0 , \2_w1   );
  input  \1_a0 , \1_a1 , \1_b0 , \1_b1 , \1_c , \2_x0 , \2_x1 , \2_y0 ,
    \2_y1 , \2_z ;
  output \1_h0 , \1_h1 , \1_m0 , \1_m1 , \2_u0 , \2_u1 , \2_w0 , \2_w1 ;
  wire new_n20_, new_n21_, new_n22_, new_n23_, new_n25_, new_n26_, new_n27_,
    new_n29_, new_n30_, new_n33_, new_n34_, new_n35_, new_n36_, new_n38_,
    new_n39_, new_n40_, new_n42_, new_n43_;
  assign \1_h0  = \1_a0  & \1_b0 ;
  assign new_n20_ = \1_a1  & \1_b0 ;
  assign new_n21_ = \1_a0  & \1_b1 ;
  assign new_n22_ = new_n20_ & ~new_n21_;
  assign new_n23_ = ~new_n20_ & new_n21_;
  assign \1_h1  = new_n22_ | new_n23_;
  assign new_n25_ = \1_b0  & \1_c ;
  assign new_n26_ = ~\1_b1  & ~new_n25_;
  assign new_n27_ = \1_b1  & new_n25_;
  assign \1_m0  = ~new_n26_ & ~new_n27_;
  assign new_n29_ = ~\1_b0  & \1_c ;
  assign new_n30_ = \1_b0  & ~\1_c ;
  assign \1_m1  = new_n29_ | new_n30_;
  assign \2_u0  = \2_x0  & \2_y0 ;
  assign new_n33_ = \2_x1  & \2_y0 ;
  assign new_n34_ = \2_x0  & \2_y1 ;
  assign new_n35_ = new_n33_ & ~new_n34_;
  assign new_n36_ = ~new_n33_ & new_n34_;
  assign \2_u1  = new_n35_ | new_n36_;
  assign new_n38_ = \2_y0  & \2_z ;
  assign new_n39_ = ~\2_y1  & ~new_n38_;
  assign new_n40_ = \2_y1  & new_n38_;
  assign \2_w0  = ~new_n39_ & ~new_n40_;
  assign new_n42_ = ~\2_y0  & \2_z ;
  assign new_n43_ = \2_y0  & ~\2_z ;
  assign \2_w1  = new_n42_ | new_n43_;
endmodule


