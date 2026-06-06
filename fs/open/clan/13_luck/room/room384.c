inherit ROOM;
void create() {
	set( "short", "十三戰堂" );
	set( "object", ([
		"amount4"  : 1,
		"file7"    : "/obj/gift/shenliwan",
		"file10"   : "/open/magic-manor/obj/lin-cloud-fan",
		"amount10" : 1,
		"amount3"  : 1,
		"amount6"  : 1,
		"amount1"  : 1,
		"file6"    : "/obj/gift/xisuidan",
		"file4"    : "/open/magic-manor/obj/dark-soul-dagger",
		"file9"    : "/open/magic-manor/obj/dark-soul-dagger",
		"amount8"  : 1,
		"amount2"  : 1,
		"file5"    : "/obj/gift/unknowdan",
		"amount7"  : 1,
		"file2"    : "/obj/gift/lingzhi",
		"amount9"  : 1,
		"file3"    : "/obj/gift/xisuidan",
		"file8"    : "/obj/gift/xisuidan",
		"file1"    : "/obj/gift/bingtang",
		"amount5"  : 1,
	]) );
	set( "owner", "roar" );
	set( "build", 10191 );
	set( "light_up", 1 );
	set( "exits", ([
		"south"     : "/open/clan/13_luck/room/room383",
		"north"     : "/open/clan/13_luck/room/room385.c",
	]) );
	set( "long", @LONG

    來到這兒你不禁要大吃一驚，原來十三戰堂之所以為十三戰堂的主要
原因在於他不僅僅訓練堂內弟子的武術更訓練他們的戰技技能，所以從十
三戰堂出來的弟子對於戰爭的戰術應用也有相當的成就。而十三戰堂現任
堂主為了讓戰堂弟子能學有所成，每月最後一日都會舉辦戰堂技能檢驗，
讓出色的戰堂弟子能夠在十三吉祥內獲得更高的職務。

LONG);
	setup();
	replace_program(ROOM);
}
