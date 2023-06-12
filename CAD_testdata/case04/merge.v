// Benchmark "top" written by ABC on Sun Jun 11 02:15:05 2023

module top ( 
    \1_n1 , \1_n10 , \1_n13 , \1_n27 , \1_n32 , \1_n4 , \1_n46 , \1_n58 ,
    \1_n61 , \1_n64 , \1_n65 , \1_n66 , \2_n23 , \2_n25 , \2_n28 , \2_n32 ,
    \2_n38 , \2_n4 , \2_n50 , \2_n55 , \2_n58 , \2_n60 , \2_n63 , \2_n65 ,
    \1_n26 , \1_n34 , \1_n52 , \1_n54 , \2_n14 , \2_n34 , \2_n40 , \2_n59   );
  input  \1_n1 , \1_n10 , \1_n13 , \1_n27 , \1_n32 , \1_n4 , \1_n46 ,
    \1_n58 , \1_n61 , \1_n64 , \1_n65 , \1_n66 , \2_n23 , \2_n25 , \2_n28 ,
    \2_n32 , \2_n38 , \2_n4 , \2_n50 , \2_n55 , \2_n58 , \2_n60 , \2_n63 ,
    \2_n65 ;
  output \1_n26 , \1_n34 , \1_n52 , \1_n54 , \2_n14 , \2_n34 , \2_n40 ,
    \2_n59 ;
  wire new_n33_, new_n34_, new_n35_, new_n36_, new_n37_, new_n38_, new_n39_,
    new_n40_, new_n41_, new_n42_, new_n43_, new_n44_, new_n45_, new_n47_,
    new_n48_, new_n49_, new_n50_, new_n51_, new_n52_, new_n53_, new_n54_,
    new_n55_, new_n56_, new_n57_, new_n58_, new_n59_, new_n60_, new_n61_,
    new_n62_, new_n63_, new_n64_, new_n65_, new_n66_, new_n68_, new_n69_,
    new_n70_, new_n71_, new_n72_, new_n73_, new_n74_, new_n75_, new_n76_,
    new_n77_, new_n78_, new_n79_, new_n80_, new_n81_, new_n82_, new_n83_,
    new_n84_, new_n85_, new_n86_, new_n87_, new_n88_, new_n89_, new_n90_,
    new_n91_, new_n92_, new_n93_, new_n94_, new_n95_, new_n96_, new_n97_,
    new_n98_, new_n100_, new_n102_, new_n103_, new_n104_, new_n105_,
    new_n106_, new_n107_, new_n108_, new_n109_, new_n110_, new_n111_,
    new_n112_, new_n113_, new_n114_, new_n115_, new_n116_, new_n117_,
    new_n118_, new_n119_, new_n120_, new_n121_, new_n122_, new_n123_,
    new_n124_, new_n125_, new_n126_, new_n127_, new_n128_, new_n129_,
    new_n131_, new_n132_, new_n133_, new_n134_, new_n135_, new_n137_,
    new_n139_, new_n140_, new_n141_, new_n142_, new_n143_, new_n144_,
    new_n145_, new_n146_, new_n147_, new_n148_, new_n149_, new_n150_,
    new_n151_, new_n152_, new_n153_, new_n154_, new_n155_, new_n156_,
    new_n157_, new_n158_, new_n159_, new_n160_, new_n161_, new_n162_,
    new_n163_, new_n164_, new_n165_, new_n166_, new_n167_, new_n168_,
    new_n169_, new_n170_;
  assign new_n33_ = ~\1_n61  & ~\1_n66 ;
  assign new_n34_ = ~\1_n4  & new_n33_;
  assign new_n35_ = ~\1_n32  & ~\1_n61 ;
  assign new_n36_ = ~\1_n13  & ~\1_n66 ;
  assign new_n37_ = ~new_n35_ & ~new_n36_;
  assign new_n38_ = ~\1_n13  & ~\1_n32 ;
  assign new_n39_ = new_n33_ & new_n38_;
  assign new_n40_ = ~new_n37_ & ~new_n39_;
  assign new_n41_ = \1_n1  & new_n40_;
  assign new_n42_ = ~\1_n1  & ~new_n40_;
  assign new_n43_ = ~new_n41_ & ~new_n42_;
  assign new_n44_ = ~new_n34_ & new_n43_;
  assign new_n45_ = new_n34_ & ~new_n43_;
  assign \1_n26  = ~new_n44_ & ~new_n45_;
  assign new_n47_ = \1_n1  & ~new_n34_;
  assign new_n48_ = new_n40_ & ~new_n47_;
  assign new_n49_ = ~\1_n1  & new_n34_;
  assign new_n50_ = ~new_n48_ & ~new_n49_;
  assign new_n51_ = \1_n10  & ~\1_n61 ;
  assign new_n52_ = \1_n65  & ~\1_n66 ;
  assign new_n53_ = ~new_n38_ & ~new_n52_;
  assign new_n54_ = new_n38_ & new_n52_;
  assign new_n55_ = ~new_n53_ & ~new_n54_;
  assign new_n56_ = ~new_n51_ & new_n55_;
  assign new_n57_ = new_n51_ & ~new_n55_;
  assign new_n58_ = ~new_n56_ & ~new_n57_;
  assign new_n59_ = new_n39_ & new_n58_;
  assign new_n60_ = ~new_n39_ & ~new_n58_;
  assign new_n61_ = ~new_n59_ & ~new_n60_;
  assign new_n62_ = \1_n27  & ~new_n61_;
  assign new_n63_ = ~\1_n27  & new_n61_;
  assign new_n64_ = ~new_n62_ & ~new_n63_;
  assign new_n65_ = ~new_n50_ & new_n64_;
  assign new_n66_ = new_n50_ & ~new_n64_;
  assign \1_n34  = ~new_n65_ & ~new_n66_;
  assign new_n68_ = \1_n46  & ~\1_n61 ;
  assign new_n69_ = \1_n58  & ~\1_n66 ;
  assign new_n70_ = new_n68_ & ~new_n69_;
  assign new_n71_ = ~new_n68_ & new_n69_;
  assign new_n72_ = ~new_n70_ & ~new_n71_;
  assign new_n73_ = ~\1_n32  & \1_n65 ;
  assign new_n74_ = \1_n10  & ~\1_n13 ;
  assign new_n75_ = ~new_n73_ & ~new_n74_;
  assign new_n76_ = new_n73_ & new_n74_;
  assign new_n77_ = ~new_n75_ & ~new_n76_;
  assign new_n78_ = ~new_n72_ & new_n77_;
  assign new_n79_ = new_n72_ & ~new_n77_;
  assign new_n80_ = ~new_n78_ & ~new_n79_;
  assign new_n81_ = new_n38_ & new_n51_;
  assign new_n82_ = ~new_n38_ & ~new_n51_;
  assign new_n83_ = new_n52_ & ~new_n82_;
  assign new_n84_ = ~new_n81_ & ~new_n83_;
  assign new_n85_ = new_n39_ & ~new_n58_;
  assign new_n86_ = ~new_n84_ & new_n85_;
  assign new_n87_ = new_n84_ & ~new_n85_;
  assign new_n88_ = ~new_n86_ & ~new_n87_;
  assign new_n89_ = ~new_n50_ & ~new_n63_;
  assign new_n90_ = ~new_n62_ & ~new_n89_;
  assign new_n91_ = \1_n64  & ~new_n90_;
  assign new_n92_ = ~\1_n64  & new_n90_;
  assign new_n93_ = ~new_n91_ & ~new_n92_;
  assign new_n94_ = ~new_n88_ & new_n93_;
  assign new_n95_ = new_n88_ & ~new_n93_;
  assign new_n96_ = ~new_n94_ & ~new_n95_;
  assign new_n97_ = ~new_n80_ & new_n96_;
  assign new_n98_ = new_n80_ & ~new_n96_;
  assign \1_n52  = ~new_n97_ & ~new_n98_;
  assign new_n100_ = \1_n4  & ~new_n33_;
  assign \1_n54  = ~new_n34_ & ~new_n100_;
  assign new_n102_ = \2_n25  & \2_n50 ;
  assign new_n103_ = \2_n4  & new_n102_;
  assign new_n104_ = \2_n23  & new_n103_;
  assign new_n105_ = ~\2_n23  & ~new_n103_;
  assign new_n106_ = \2_n38  & \2_n50 ;
  assign new_n107_ = \2_n25  & \2_n32 ;
  assign new_n108_ = ~new_n106_ & ~new_n107_;
  assign new_n109_ = new_n106_ & new_n107_;
  assign new_n110_ = ~new_n108_ & ~new_n109_;
  assign new_n111_ = ~new_n105_ & new_n110_;
  assign new_n112_ = ~new_n104_ & ~new_n111_;
  assign new_n113_ = \2_n25  & \2_n63 ;
  assign new_n114_ = \2_n32  & \2_n38 ;
  assign new_n115_ = \2_n50  & \2_n60 ;
  assign new_n116_ = new_n114_ & ~new_n115_;
  assign new_n117_ = ~new_n114_ & new_n115_;
  assign new_n118_ = ~new_n116_ & ~new_n117_;
  assign new_n119_ = new_n113_ & new_n118_;
  assign new_n120_ = ~new_n113_ & ~new_n118_;
  assign new_n121_ = ~new_n119_ & ~new_n120_;
  assign new_n122_ = ~new_n109_ & new_n121_;
  assign new_n123_ = new_n109_ & ~new_n121_;
  assign new_n124_ = ~new_n122_ & ~new_n123_;
  assign new_n125_ = \2_n65  & ~new_n124_;
  assign new_n126_ = ~\2_n65  & new_n124_;
  assign new_n127_ = ~new_n125_ & ~new_n126_;
  assign new_n128_ = new_n112_ & new_n127_;
  assign new_n129_ = ~new_n112_ & ~new_n127_;
  assign \2_n14  = ~new_n128_ & ~new_n129_;
  assign new_n131_ = \2_n23  & new_n110_;
  assign new_n132_ = ~\2_n23  & ~new_n110_;
  assign new_n133_ = ~new_n131_ & ~new_n132_;
  assign new_n134_ = new_n103_ & new_n133_;
  assign new_n135_ = ~new_n103_ & ~new_n133_;
  assign \2_n34  = ~new_n134_ & ~new_n135_;
  assign new_n137_ = ~\2_n4  & ~new_n102_;
  assign \2_n40  = ~new_n103_ & ~new_n137_;
  assign new_n139_ = \2_n32  & \2_n60 ;
  assign new_n140_ = \2_n38  & \2_n63 ;
  assign new_n141_ = new_n139_ & ~new_n140_;
  assign new_n142_ = ~new_n139_ & new_n140_;
  assign new_n143_ = ~new_n141_ & ~new_n142_;
  assign new_n144_ = \2_n50  & \2_n58 ;
  assign new_n145_ = \2_n25  & \2_n55 ;
  assign new_n146_ = new_n144_ & ~new_n145_;
  assign new_n147_ = ~new_n144_ & new_n145_;
  assign new_n148_ = ~new_n146_ & ~new_n147_;
  assign new_n149_ = ~new_n143_ & new_n148_;
  assign new_n150_ = new_n143_ & ~new_n148_;
  assign new_n151_ = ~new_n149_ & ~new_n150_;
  assign new_n152_ = new_n113_ & new_n114_;
  assign new_n153_ = ~new_n113_ & ~new_n114_;
  assign new_n154_ = new_n115_ & ~new_n153_;
  assign new_n155_ = ~new_n152_ & ~new_n154_;
  assign new_n156_ = ~new_n123_ & ~new_n155_;
  assign new_n157_ = new_n123_ & new_n155_;
  assign new_n158_ = ~new_n156_ & ~new_n157_;
  assign new_n159_ = \2_n65  & new_n124_;
  assign new_n160_ = ~\2_n65  & ~new_n124_;
  assign new_n161_ = ~new_n112_ & ~new_n160_;
  assign new_n162_ = ~new_n159_ & ~new_n161_;
  assign new_n163_ = \2_n28  & ~new_n162_;
  assign new_n164_ = ~\2_n28  & new_n162_;
  assign new_n165_ = ~new_n163_ & ~new_n164_;
  assign new_n166_ = ~new_n158_ & new_n165_;
  assign new_n167_ = new_n158_ & ~new_n165_;
  assign new_n168_ = ~new_n166_ & ~new_n167_;
  assign new_n169_ = ~new_n151_ & new_n168_;
  assign new_n170_ = new_n151_ & ~new_n168_;
  assign \2_n59  = ~new_n169_ & ~new_n170_;
endmodule


