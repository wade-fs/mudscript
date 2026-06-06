inherit ROOM;
void create() {
	set( "short", "澡堂" );
	set( "object", ([
		"amount7"  : 1,
		"file5"    : "/obj/gift/xiandan",
		"file3"    : "/obj/gift/hobowdan",
		"amount2"  : 1,
		"file6"    : "/open/ghost-hole/obj/eq/ghost-belt",
		"file2"    : "/obj/gift/hobowdan",
		"amount1"  : 1,
		"amount10" : 1,
		"amount4"  : 1,
		"file4"    : "/obj/gift/xisuidan",
		"amount3"  : 1,
		"file10"   : "/open/ghost-hole/obj/eq/ghost-gem",
		"file1"    : "/obj/gift/hobowdan",
		"amount8"  : 1,
		"file8"    : "/obj/gift/hobowdan",
		"file7"    : "/obj/gift/xiandan",
		"amount5"  : 1,
		"amount6"  : 1,
	]) );
	set( "build", 10013 );
	set( "owner", "djlh" );
	set( "exits", ([
		"west"      : "/open/clan/13_luck/room/room663.c",
		"north"     : "/open/clan/13_luck/room/room667.c",
		"south"     : "/open/clan/13_luck/room/room175",
	]) );
	set( "long", @LONG

◇‧◇‧◇‧無條件為你‧梁靜茹‧◇‧◇‧◇‧◇‧◇‧◇‧◇‧◇‧◇‧◇‧◇‧◇  
‧愛你等於擁有一片天空　任何風吹草動　都有你存在其中　自然而然的輕鬆        ‧  
◇一路到夏天的尾聲　無所謂到過於激動　我們有笑容  我們曾心動　不再是無動於衷◇  
‧無條件為你不顧明天的安穩　為你變堅強相信你的眼神            .    ．.*·﹡.‧  
◇不敢想不敢問　有一天壞的可能                      給最愛的豬  * ○  ○/ . ◇  
‧無條件為你放棄單獨的旅程　為你堅強就不怕犧牲  For forever     ．█\/█． *‧  
◇我的靈魂  如此沸騰　為我愛的人                                  /︳︱\    ◇  
‧喜歡複雜還是習慣單純　我願盡力完成　你在我心中幾分　難以形容的責任        ‧  
◇愛一個人付出才會完整　無條件  越愛就越深　永遠不分  啊....                ◇  
‧◇‧◇‧◇‧◇‧◇‧◇‧◇‧◇‧◇‧◇‧◇‧◇‧◇‧◇‧◇‧◇‧◇‧◇‧◇‧  
  
  
LONG);
	setup();
	replace_program(ROOM);
}
