inherit ROOM;
void create() {
	set( "short", "$HIW$波-煉丹房(3)$NOR$" );
	set( "owner", "perth" );
	set( "object", ([
		"amount8"  : 1,
		"file8"    : "/obj/gift/hobowdan",
		"amount9"  : 1,
		"amount3"  : 1,
		"file6"    : "/obj/gift/xisuidan",
		"amount1"  : 1,
		"file1"    : "/obj/gift/xiandan",
		"amount7"  : 1,
		"amount10" : 1,
		"file5"    : "/open/gblade/obj/sa-head",
		"file4"    : "/obj/gift/xisuidan",
		"file2"    : "/obj/gift/xisuidan",
		"amount6"  : 1,
		"amount2"  : 1,
		"file7"    : "/obj/gift/xisuidan",
		"amount5"  : 1,
		"file9"    : "/obj/gift/shenliwan",
		"file10"   : "/obj/gift/shenliwan",
		"amount4"  : 1,
		"file3"    : "/open/ghost-hole/obj/light-spirit",
	]) );
	set( "exits", ([
		"south"     : "/open/clan/ou-cloud-club/room/room174.c",
		"west"      : "/open/clan/ou-cloud-club/room/room327",
		"east"      : "/open/clan/ou-cloud-club/room/room385",
		"north"     : "/open/clan/ou-cloud-club/room/room318.c",
	]) );
	set( "build", 10129 );
	set( "long", @LONG
一股難聞的藥味衝鼻而來，斷腸草、催心粉、五毒密藥及
數種未曾聽聞的毒藥，就擺在一進門的正前方，右邊牆上也掛
了幾具乾屍，房中數個火爐同時大火猛烈地提煉草藥，地上還
零星地擺置了十來種藥水及藥丸，與肩齊高的藥櫃貼滿了藥性
及用法，這是波在解決疑難雜症、及解毒之處，若你有啥小問
題，相信波也是幫得上忙的，而有啥好建議，波也會虛心受教
的。
         非  請  勿  動  ，  違  者  死  ！
                                
                                           殺手藥神-波

LONG);
	setup();
	replace_program(ROOM);
}
