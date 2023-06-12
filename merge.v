module test1 ( 
    a, b, d, e, g,
    c, f  );
  input  a, b, d, e, g;
  output c, f;
  wire new_n9_;
  assign c = a & b;
  assign new_n9_ = d & e;
  assign f = g | new_n9_;
endmodule