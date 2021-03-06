(EMBEDDED HYPERTHERM PATENT-PENDING TRUE HOLE TECHNOLOGY)
(TrueHole test program; 130amp, 10mm Mild steel, 120mm flange with 8 16mm holes)
//N1 G21
N2 G91
(CutPro Wizard - Load Material: Mild Steel;120.mm x 125.mm;10.mm)
//N3 M36 T1
//N4 M37 T1
N5 G00X600Y269

(Seq 1 - Bolt Hole Circle.vsp)

//N6 G59 V502 F34

N7 G59 V503 F1.98
N8 G59 V504 F130
N9 G59 V505 F3
N10 G59 V507 F31

//N11 G59 V600 F130

//N12 G59 V601 F0.3
//N13 G59 V602 F200
//N14 G59 V603 F3
//N15 G59 V604 F200.
N16 D39     //G43 X39

N18 M71     //HS
N19 M45     //N
N20 F1120   //F840
N21 G03Y-99 I0 J-50  
N22 F1120
N23 G03I0J80 G41
N24 M46     //M50H-0.1
N25 G03 X54 Y21 I0 J80
N26 M74.1
N27 G40
//N28 M51
N29 G00X228Y195
//N30 G43X38


N18 M71     //HS
N19 M45     //N
N20 F1120   //F840
N21 G03Y-99 I0 J-50
N22 F1120
N23 G03I0J80   G41
N24 M46     //M50H-0.1
N25 G03 X54 Y21 I0 J80
N26 M74.1
N27 G40

N43 G00X62Y360

N18 M71     //HS
N19 M45     //N
N20 F1120   //F840
N21 G03Y-99 I0 J-50
N22 F1120
N23 G03I0J80  G41
N24 M46     //M50H-0.1
N25 G03 X54 Y21 I0 J80
N26 M74.1
N27 G40

N57 G00X-171Y360
N18 M71     //HS
N19 M45     //N
N20 F1120   //F840
N21 G03Y-99 I0 J-50
N22 F1120
N23 G03I0J80         G41
N24 M46     //M50H-0.1
N25 G03 X54 Y21 I0 J80
N26 M74.1
N27 G40

N71 G00X-337Y195
N18 M71     //HS
N19 M45     //N
N20 F1120   //F840
N21 G03Y-99 I0 J-50
N22 F1120
N23 G03I0J80        G41
N24 M46     //M50H-0.1
N25 G03 X54 Y21 I0 J80
N26 M74.1
N27 G40

N85 G00X-337Y-39

N18 M71     //HS
N19 M45     //N
N20 F1120   //F840
N21 G03Y-99 I0 J-50
N22 F1120
N23 G03I0J80     G41
N24 M46     //M50H-0.1
N25 G03 X54 Y21 I0 J80
N26 M74.1
N27 G40

N99 G00X-171Y-204

N18 M71     //HS
N19 M45     //N
N20 F1120   //F840
N21 G03Y-99 I0 J-50
N22 F1120
N23 G03I0J80   G41
N24 M46     //M50H-0.1
N25 G03 X54 Y21 I0 J80
N26 M74.1
N27 G40

N113 G00X62Y-204

N18 M71     //HS
N19 M45     //N
N20 F1120   //F840
N21 G03Y-99 I0 J-50
N22 F1120
N23 G03I0J80        G41
N24 M46     //M50H-0.1
N25 G03 X54 Y21 I0 J80
N26 M74.1
N27 G40

N127 G00X278Y-308


//N28 G59 V502 F34

//N133 G59 V601 F0.3
//N134 G59 V602 F200
//N135 G59 V603 F3.
//N136 G59 V604 F200.

//разметка
N129 G59 V503 F1
N130 G59 V504 F15
N131 G59 V505 F2
N132 G59 V507 F31

G00x199 y1250
M81g1x-498y-1200
M83g0x498
M81g1x-498y1200
m83g0x-351  y-351
m81g1x1200 y-498
m83g0y498 
m81g1x-1200 y-498
m83g0 x650 y-401


//внешний контур
N129 G59 V503 F1
N130 G59 V504 F130
N131 G59 V505 F2
N132 G59 V507 F31

N137 D20//G43X20
N139 M71
N140 F2680
N141 G03X-50Y50I-50J-0 
N142 G02I0J600	        G41
N143 G03X-50Y-50I0J-50
N144 M84
N145 G40
N150 M02
