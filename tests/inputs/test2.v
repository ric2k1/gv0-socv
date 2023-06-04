module test2(
   d,
   e,
   g,
   f
);

input d;
input e;
input g;
output f;

assign f = d & e | g;

endmodule