module test2(
   d,
   e,
   g,
   f
);

input d, e, g;
output f;

assign f = d & e | g;

endmodule