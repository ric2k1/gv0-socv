// Benchmark "top" written by ABC on Mon Jun 12 20:57:39 2023

module top ( 
    \1_n0 , \1_n11 , \1_n15 , \1_n21 , \1_n3 , \1_n35 , \1_n36 , \1_n37 ,
    \1_n41 , \1_n61 , \1_n73 , \1_n80 , \2_n12 , \2_n18 , \2_n2 , \2_n22 ,
    \2_n34 , \2_n35 , \2_n4 , \2_n51 , \2_n57 , \2_n67 , \2_n72 , \2_n75 ,
    \2_n78 , \2_n80 ,
    \1_n10 , \1_n33 , \1_n39 , \1_n4 , \1_n66 , \1_n70 , \1_n71 , \1_n79 ,
    \2_n42 , \2_n48 , \2_n56 , \2_n6 , \2_n65 , \2_n68 , \2_n77 , \2_n9   );
  input  \1_n0 , \1_n11 , \1_n15 , \1_n21 , \1_n3 , \1_n35 , \1_n36 ,
    \1_n37 , \1_n41 , \1_n61 , \1_n73 , \1_n80 , \2_n12 , \2_n18 , \2_n2 ,
    \2_n22 , \2_n34 , \2_n35 , \2_n4 , \2_n51 , \2_n57 , \2_n67 , \2_n72 ,
    \2_n75 , \2_n78 , \2_n80 ;
  output \1_n10 , \1_n33 , \1_n39 , \1_n4 , \1_n66 , \1_n70 , \1_n71 ,
    \1_n79 , \2_n42 , \2_n48 , \2_n56 , \2_n6 , \2_n65 , \2_n68 , \2_n77 ,
    \2_n9 ;
  wire new_n43_, new_n44_, new_n45_, new_n46_, new_n47_, new_n48_, new_n49_,
    new_n50_, new_n51_, new_n52_, new_n53_, new_n54_, new_n55_, new_n56_,
    new_n57_, new_n58_, new_n59_, new_n60_, new_n61_, new_n62_, new_n63_,
    new_n64_, new_n65_, new_n66_, new_n67_, new_n68_, new_n69_, new_n70_,
    new_n71_, new_n72_, new_n73_, new_n74_, new_n75_, new_n76_, new_n77_,
    new_n79_, new_n80_, new_n81_, new_n82_, new_n83_, new_n84_, new_n85_,
    new_n86_, new_n87_, new_n88_, new_n92_, new_n93_, new_n94_, new_n96_,
    new_n97_, new_n98_, new_n101_, new_n102_, new_n104_, new_n105_,
    new_n106_, new_n107_, new_n108_, new_n109_, new_n110_, new_n111_,
    new_n112_, new_n113_, new_n114_, new_n115_, new_n116_, new_n117_,
    new_n118_, new_n119_, new_n120_, new_n121_, new_n122_, new_n123_,
    new_n124_, new_n125_, new_n126_, new_n127_, new_n129_, new_n130_,
    new_n131_, new_n132_, new_n133_, new_n134_, new_n135_, new_n136_,
    new_n137_, new_n138_, new_n139_, new_n140_, new_n141_, new_n142_,
    new_n143_, new_n144_, new_n145_, new_n146_, new_n147_, new_n148_,
    new_n149_, new_n151_, new_n152_, new_n153_, new_n154_, new_n155_,
    new_n156_, new_n158_, new_n159_, new_n160_, new_n161_, new_n162_,
    new_n163_, new_n164_, new_n165_, new_n166_, new_n168_, new_n169_,
    new_n170_, new_n171_, new_n172_, new_n173_, new_n174_, new_n175_,
    new_n177_, new_n179_, new_n180_, new_n182_;
  assign new_n43_ = ~\1_n3  & ~\1_n21 ;
  assign new_n44_ = \1_n3  & ~\1_n73 ;
  assign new_n45_ = ~new_n43_ & ~new_n44_;
  assign new_n46_ = \1_n37  & new_n45_;
  assign new_n47_ = \1_n3  & \1_n80 ;
  assign new_n48_ = ~\1_n3  & \1_n41 ;
  assign new_n49_ = ~new_n47_ & ~new_n48_;
  assign new_n50_ = ~\1_n37  & new_n49_;
  assign new_n51_ = ~new_n46_ & ~new_n50_;
  assign new_n52_ = \1_n41  & ~\1_n61 ;
  assign new_n53_ = \1_n61  & \1_n80 ;
  assign new_n54_ = ~new_n52_ & ~new_n53_;
  assign new_n55_ = ~\1_n36  & new_n54_;
  assign new_n56_ = ~\1_n0  & \1_n41 ;
  assign new_n57_ = \1_n0  & \1_n80 ;
  assign new_n58_ = ~new_n56_ & ~new_n57_;
  assign new_n59_ = ~\1_n15  & new_n58_;
  assign new_n60_ = ~\1_n21  & ~\1_n35 ;
  assign new_n61_ = \1_n35  & ~\1_n73 ;
  assign new_n62_ = ~new_n60_ & ~new_n61_;
  assign new_n63_ = \1_n11  & new_n62_;
  assign new_n64_ = ~\1_n0  & ~\1_n21 ;
  assign new_n65_ = \1_n0  & ~\1_n73 ;
  assign new_n66_ = ~new_n64_ & ~new_n65_;
  assign new_n67_ = \1_n15  & new_n66_;
  assign new_n68_ = ~new_n63_ & ~new_n67_;
  assign new_n69_ = ~new_n59_ & ~new_n68_;
  assign new_n70_ = ~\1_n21  & ~\1_n61 ;
  assign new_n71_ = \1_n61  & ~\1_n73 ;
  assign new_n72_ = ~new_n70_ & ~new_n71_;
  assign new_n73_ = \1_n36  & new_n72_;
  assign new_n74_ = ~new_n69_ & ~new_n73_;
  assign new_n75_ = ~new_n55_ & ~new_n74_;
  assign new_n76_ = ~new_n51_ & ~new_n75_;
  assign new_n77_ = new_n51_ & new_n75_;
  assign \1_n4  = ~new_n76_ & ~new_n77_;
  assign new_n79_ = ~new_n46_ & new_n55_;
  assign new_n80_ = ~new_n46_ & ~new_n73_;
  assign new_n81_ = ~\1_n35  & \1_n41 ;
  assign new_n82_ = \1_n35  & \1_n80 ;
  assign new_n83_ = ~new_n81_ & ~new_n82_;
  assign new_n84_ = ~\1_n11  & new_n83_;
  assign new_n85_ = ~new_n67_ & new_n84_;
  assign new_n86_ = ~new_n59_ & ~new_n85_;
  assign new_n87_ = new_n80_ & ~new_n86_;
  assign new_n88_ = ~new_n79_ & ~new_n87_;
  assign \1_n33  = ~new_n50_ & new_n88_;
  assign \1_n71  = ~new_n68_ | ~new_n80_;
  assign \1_n10  = ~\1_n33  | ~\1_n71 ;
  assign new_n92_ = ~new_n55_ & ~new_n73_;
  assign new_n93_ = new_n69_ & new_n92_;
  assign new_n94_ = ~new_n69_ & ~new_n92_;
  assign \1_n39  = ~new_n93_ & ~new_n94_;
  assign new_n96_ = ~new_n59_ & ~new_n67_;
  assign new_n97_ = new_n63_ & new_n96_;
  assign new_n98_ = ~new_n63_ & ~new_n96_;
  assign \1_n66  = ~new_n97_ & ~new_n98_;
  assign \1_n70  = ~new_n63_ & ~new_n84_;
  assign new_n101_ = \1_n66  & \1_n70 ;
  assign new_n102_ = \1_n39  & new_n101_;
  assign \1_n79  = \1_n4  & new_n102_;
  assign new_n104_ = \2_n67  & \2_n72 ;
  assign new_n105_ = ~\2_n67  & \2_n75 ;
  assign new_n106_ = ~\2_n22  & ~new_n105_;
  assign new_n107_ = ~new_n104_ & new_n106_;
  assign new_n108_ = \2_n67  & ~\2_n78 ;
  assign new_n109_ = ~\2_n67  & ~\2_n80 ;
  assign new_n110_ = \2_n22  & ~new_n109_;
  assign new_n111_ = ~new_n108_ & new_n110_;
  assign new_n112_ = \2_n51  & ~new_n111_;
  assign new_n113_ = ~new_n107_ & ~new_n112_;
  assign new_n114_ = ~\2_n12  & ~new_n113_;
  assign new_n115_ = \2_n2  & ~\2_n78 ;
  assign new_n116_ = ~\2_n2  & ~\2_n80 ;
  assign new_n117_ = \2_n18  & ~new_n116_;
  assign new_n118_ = ~new_n115_ & new_n117_;
  assign new_n119_ = \2_n2  & \2_n72 ;
  assign new_n120_ = ~\2_n2  & \2_n75 ;
  assign new_n121_ = ~\2_n18  & ~new_n120_;
  assign new_n122_ = ~new_n119_ & new_n121_;
  assign new_n123_ = new_n118_ & new_n122_;
  assign new_n124_ = ~new_n118_ & ~new_n122_;
  assign new_n125_ = ~new_n123_ & ~new_n124_;
  assign new_n126_ = ~new_n114_ & new_n125_;
  assign new_n127_ = new_n114_ & ~new_n125_;
  assign \2_n42  = new_n126_ | new_n127_;
  assign new_n129_ = \2_n4  & \2_n72 ;
  assign new_n130_ = ~\2_n4  & \2_n75 ;
  assign new_n131_ = ~\2_n35  & ~new_n130_;
  assign new_n132_ = ~new_n129_ & new_n131_;
  assign new_n133_ = \2_n4  & ~\2_n78 ;
  assign new_n134_ = ~\2_n4  & ~\2_n80 ;
  assign new_n135_ = \2_n35  & ~new_n134_;
  assign new_n136_ = ~new_n133_ & new_n135_;
  assign new_n137_ = \2_n57  & \2_n72 ;
  assign new_n138_ = ~\2_n57  & \2_n75 ;
  assign new_n139_ = ~\2_n34  & ~new_n138_;
  assign new_n140_ = ~new_n137_ & new_n139_;
  assign new_n141_ = \2_n57  & ~\2_n78 ;
  assign new_n142_ = ~\2_n57  & ~\2_n80 ;
  assign new_n143_ = \2_n34  & ~new_n142_;
  assign new_n144_ = ~new_n141_ & new_n143_;
  assign new_n145_ = new_n107_ & ~new_n118_;
  assign new_n146_ = ~new_n122_ & ~new_n145_;
  assign new_n147_ = ~new_n144_ & ~new_n146_;
  assign new_n148_ = ~new_n140_ & ~new_n147_;
  assign new_n149_ = ~new_n136_ & ~new_n148_;
  assign \2_n48  = ~new_n132_ & ~new_n149_;
  assign new_n151_ = ~\2_n12  & \2_n51 ;
  assign new_n152_ = ~new_n107_ & ~new_n111_;
  assign new_n153_ = new_n107_ & new_n111_;
  assign new_n154_ = ~new_n152_ & ~new_n153_;
  assign new_n155_ = new_n151_ & new_n154_;
  assign new_n156_ = ~new_n151_ & ~new_n154_;
  assign \2_n6  = ~new_n155_ & ~new_n156_;
  assign new_n158_ = \2_n42  & \2_n6 ;
  assign new_n159_ = new_n112_ & ~new_n118_;
  assign new_n160_ = new_n146_ & ~new_n159_;
  assign new_n161_ = ~\2_n12  & ~new_n160_;
  assign new_n162_ = ~new_n140_ & ~new_n144_;
  assign new_n163_ = new_n140_ & new_n144_;
  assign new_n164_ = ~new_n162_ & ~new_n163_;
  assign new_n165_ = ~new_n161_ & new_n164_;
  assign new_n166_ = new_n161_ & ~new_n164_;
  assign \2_n9  = new_n165_ | new_n166_;
  assign new_n168_ = ~new_n144_ & new_n159_;
  assign new_n169_ = new_n148_ & ~new_n168_;
  assign new_n170_ = ~\2_n12  & ~new_n169_;
  assign new_n171_ = new_n132_ & ~new_n136_;
  assign new_n172_ = ~new_n132_ & new_n136_;
  assign new_n173_ = ~new_n171_ & ~new_n172_;
  assign new_n174_ = ~new_n170_ & ~new_n173_;
  assign new_n175_ = new_n170_ & new_n173_;
  assign \2_n65  = new_n174_ | new_n175_;
  assign new_n177_ = \2_n9  & \2_n65 ;
  assign \2_n56  = new_n158_ & new_n177_;
  assign new_n179_ = ~new_n136_ & ~new_n144_;
  assign new_n180_ = ~new_n111_ & ~new_n118_;
  assign \2_n77  = ~new_n179_ | ~new_n180_;
  assign new_n182_ = \2_n51  & ~\2_n77 ;
  assign \2_n68  = ~\2_n48  | new_n182_;
endmodule

