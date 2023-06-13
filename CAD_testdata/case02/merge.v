// Benchmark "top" written by ABC on Mon Jun 12 20:57:39 2023

module top ( 
    \1_n1 , \1_n11 , \1_n19 , \1_n24 , \1_n35 , \1_n39 , \1_n4 , \1_n45 ,
    \1_n46 , \1_n48 , \1_n49 , \1_n5 , \2_n13 , \2_n15 , \2_n3 , \2_n30 ,
    \2_n31 , \2_n38 , \2_n4 , \2_n40 , \2_n44 , \2_n48 , \2_n49 , \2_n9 ,
    \1_n16 , \1_n36 , \1_n44 , \1_n6 , \2_n10 , \2_n18 , \2_n33 , \2_n6   );
  input  \1_n1 , \1_n11 , \1_n19 , \1_n24 , \1_n35 , \1_n39 , \1_n4 ,
    \1_n45 , \1_n46 , \1_n48 , \1_n49 , \1_n5 , \2_n13 , \2_n15 , \2_n3 ,
    \2_n30 , \2_n31 , \2_n38 , \2_n4 , \2_n40 , \2_n44 , \2_n48 , \2_n49 ,
    \2_n9 ;
  output \1_n16 , \1_n36 , \1_n44 , \1_n6 , \2_n10 , \2_n18 , \2_n33 , \2_n6 ;
  wire new_n33_, new_n34_, new_n35_, new_n36_, new_n37_, new_n38_, new_n39_,
    new_n40_, new_n41_, new_n42_, new_n43_, new_n44_, new_n45_, new_n46_,
    new_n47_, new_n48_, new_n49_, new_n50_, new_n51_, new_n52_, new_n53_,
    new_n54_, new_n55_, new_n56_, new_n57_, new_n58_, new_n59_, new_n60_,
    new_n61_, new_n62_, new_n64_, new_n65_, new_n66_, new_n67_, new_n68_,
    new_n69_, new_n70_, new_n71_, new_n72_, new_n73_, new_n74_, new_n75_,
    new_n76_, new_n77_, new_n78_, new_n79_, new_n80_, new_n82_, new_n84_,
    new_n85_, new_n86_, new_n87_, new_n88_, new_n90_, new_n91_, new_n92_,
    new_n93_, new_n94_, new_n96_, new_n97_, new_n98_, new_n99_, new_n100_,
    new_n101_, new_n102_, new_n103_, new_n104_, new_n105_, new_n106_,
    new_n107_, new_n109_, new_n110_, new_n111_, new_n112_, new_n113_,
    new_n114_, new_n115_, new_n116_, new_n117_, new_n118_, new_n119_,
    new_n120_, new_n121_, new_n122_, new_n123_, new_n124_, new_n125_,
    new_n126_, new_n127_, new_n128_, new_n129_, new_n130_, new_n131_,
    new_n132_, new_n133_, new_n134_, new_n135_, new_n136_, new_n137_,
    new_n138_, new_n139_, new_n140_, new_n141_, new_n143_, new_n144_,
    new_n145_, new_n146_, new_n147_;
  assign new_n33_ = \1_n24  & \1_n39 ;
  assign new_n34_ = ~\1_n35  & \1_n48 ;
  assign new_n35_ = \1_n35  & ~\1_n48 ;
  assign new_n36_ = ~new_n34_ & ~new_n35_;
  assign new_n37_ = new_n33_ & new_n36_;
  assign new_n38_ = ~new_n33_ & ~new_n36_;
  assign new_n39_ = ~new_n37_ & ~new_n38_;
  assign new_n40_ = ~\1_n24  & \1_n39 ;
  assign new_n41_ = \1_n24  & ~\1_n39 ;
  assign new_n42_ = ~new_n40_ & ~new_n41_;
  assign new_n43_ = \1_n46  & ~new_n42_;
  assign new_n44_ = ~\1_n11  & ~new_n43_;
  assign new_n45_ = ~new_n39_ & ~new_n44_;
  assign new_n46_ = \1_n11  & new_n43_;
  assign new_n47_ = ~new_n45_ & ~new_n46_;
  assign new_n48_ = ~\1_n35  & ~\1_n48 ;
  assign new_n49_ = new_n33_ & ~new_n48_;
  assign new_n50_ = \1_n35  & \1_n48 ;
  assign new_n51_ = ~new_n49_ & ~new_n50_;
  assign new_n52_ = \1_n1  & ~\1_n45 ;
  assign new_n53_ = ~\1_n1  & \1_n45 ;
  assign new_n54_ = ~new_n52_ & ~new_n53_;
  assign new_n55_ = ~new_n51_ & new_n54_;
  assign new_n56_ = new_n51_ & ~new_n54_;
  assign new_n57_ = ~new_n55_ & ~new_n56_;
  assign new_n58_ = \1_n19  & ~new_n57_;
  assign new_n59_ = ~\1_n19  & new_n57_;
  assign new_n60_ = ~new_n58_ & ~new_n59_;
  assign new_n61_ = ~new_n47_ & new_n60_;
  assign new_n62_ = new_n47_ & ~new_n60_;
  assign \1_n6  = ~new_n61_ & ~new_n62_;
  assign new_n64_ = \1_n1  & \1_n45 ;
  assign new_n65_ = ~\1_n1  & ~\1_n45 ;
  assign new_n66_ = ~new_n51_ & ~new_n65_;
  assign new_n67_ = ~new_n64_ & ~new_n66_;
  assign new_n68_ = \1_n49  & new_n67_;
  assign new_n69_ = ~\1_n49  & ~new_n67_;
  assign new_n70_ = ~new_n68_ & ~new_n69_;
  assign new_n71_ = \1_n4  & ~\1_n5 ;
  assign new_n72_ = ~\1_n4  & \1_n5 ;
  assign new_n73_ = ~new_n71_ & ~new_n72_;
  assign new_n74_ = ~new_n47_ & ~new_n59_;
  assign new_n75_ = ~new_n58_ & ~new_n74_;
  assign new_n76_ = ~new_n73_ & ~new_n75_;
  assign new_n77_ = new_n73_ & new_n75_;
  assign new_n78_ = ~new_n76_ & ~new_n77_;
  assign new_n79_ = ~new_n70_ & new_n78_;
  assign new_n80_ = new_n70_ & ~new_n78_;
  assign \1_n16  = ~new_n79_ & ~new_n80_;
  assign new_n82_ = ~\1_n46  & new_n42_;
  assign \1_n36  = ~new_n43_ & ~new_n82_;
  assign new_n84_ = \1_n11  & ~new_n39_;
  assign new_n85_ = ~\1_n11  & new_n39_;
  assign new_n86_ = ~new_n84_ & ~new_n85_;
  assign new_n87_ = new_n43_ & new_n86_;
  assign new_n88_ = ~new_n43_ & ~new_n86_;
  assign \1_n44  = ~new_n87_ & ~new_n88_;
  assign new_n90_ = ~\2_n3  & \2_n4 ;
  assign new_n91_ = \2_n3  & ~\2_n4 ;
  assign new_n92_ = ~new_n90_ & ~new_n91_;
  assign new_n93_ = \2_n31  & ~new_n92_;
  assign new_n94_ = ~\2_n31  & new_n92_;
  assign \2_n10  = ~new_n93_ & ~new_n94_;
  assign new_n96_ = \2_n3  & \2_n4 ;
  assign new_n97_ = \2_n48  & ~\2_n49 ;
  assign new_n98_ = ~\2_n48  & \2_n49 ;
  assign new_n99_ = ~new_n97_ & ~new_n98_;
  assign new_n100_ = new_n96_ & new_n99_;
  assign new_n101_ = ~new_n96_ & ~new_n99_;
  assign new_n102_ = ~new_n100_ & ~new_n101_;
  assign new_n103_ = \2_n44  & ~new_n102_;
  assign new_n104_ = ~\2_n44  & new_n102_;
  assign new_n105_ = ~new_n103_ & ~new_n104_;
  assign new_n106_ = new_n93_ & new_n105_;
  assign new_n107_ = ~new_n93_ & ~new_n105_;
  assign \2_n18  = ~new_n106_ & ~new_n107_;
  assign new_n109_ = \2_n15  & \2_n38 ;
  assign new_n110_ = ~\2_n15  & ~\2_n38 ;
  assign new_n111_ = \2_n48  & \2_n49 ;
  assign new_n112_ = ~\2_n48  & ~\2_n49 ;
  assign new_n113_ = new_n96_ & ~new_n112_;
  assign new_n114_ = ~new_n111_ & ~new_n113_;
  assign new_n115_ = ~new_n110_ & ~new_n114_;
  assign new_n116_ = ~new_n109_ & ~new_n115_;
  assign new_n117_ = \2_n13  & new_n116_;
  assign new_n118_ = ~\2_n13  & ~new_n116_;
  assign new_n119_ = ~new_n117_ & ~new_n118_;
  assign new_n120_ = \2_n40  & ~\2_n9 ;
  assign new_n121_ = ~\2_n40  & \2_n9 ;
  assign new_n122_ = ~new_n120_ & ~new_n121_;
  assign new_n123_ = \2_n44  & new_n93_;
  assign new_n124_ = ~\2_n44  & ~new_n93_;
  assign new_n125_ = ~new_n102_ & ~new_n124_;
  assign new_n126_ = ~new_n123_ & ~new_n125_;
  assign new_n127_ = \2_n30  & ~new_n126_;
  assign new_n128_ = ~\2_n15  & \2_n38 ;
  assign new_n129_ = \2_n15  & ~\2_n38 ;
  assign new_n130_ = ~new_n128_ & ~new_n129_;
  assign new_n131_ = ~new_n114_ & new_n130_;
  assign new_n132_ = new_n114_ & ~new_n130_;
  assign new_n133_ = ~new_n131_ & ~new_n132_;
  assign new_n134_ = ~\2_n30  & new_n126_;
  assign new_n135_ = ~new_n133_ & ~new_n134_;
  assign new_n136_ = ~new_n127_ & ~new_n135_;
  assign new_n137_ = ~new_n122_ & ~new_n136_;
  assign new_n138_ = new_n122_ & new_n136_;
  assign new_n139_ = ~new_n137_ & ~new_n138_;
  assign new_n140_ = ~new_n119_ & new_n139_;
  assign new_n141_ = new_n119_ & ~new_n139_;
  assign \2_n33  = ~new_n140_ & ~new_n141_;
  assign new_n143_ = \2_n30  & ~new_n133_;
  assign new_n144_ = ~\2_n30  & new_n133_;
  assign new_n145_ = ~new_n143_ & ~new_n144_;
  assign new_n146_ = ~new_n126_ & new_n145_;
  assign new_n147_ = new_n126_ & ~new_n145_;
  assign \2_n6  = ~new_n146_ & ~new_n147_;
endmodule


