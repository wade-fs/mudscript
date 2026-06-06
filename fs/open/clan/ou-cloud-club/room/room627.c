inherit ROOM;
void create() {
	set( "short", "$HIY$Ｒａｙｋ$HIW$的$HIC$２樓中庭$NOR$" );
	set( "owner", "rayk" );
	set( "object", ([
		"file2"    : "/obj/gift/xisuidan",
		"file9"    : "/obj/gift/xisuidan",
		"amount3"  : 1,
		"amount1"  : 1,
		"file1"    : "/obj/gift/xisuidan",
		"file8"    : "/obj/gift/xisuidan",
		"file5"    : "/obj/gift/xisuidan",
		"amount6"  : 1,
		"amount8"  : 1,
		"amount4"  : 1,
		"amount10" : 1,
		"amount7"  : 1,
		"file4"    : "/obj/gift/xisuidan",
		"amount9"  : 1,
		"file10"   : "/obj/gift/shenliwan",
		"file6"    : "/obj/gift/xisuidan",
		"file3"    : "/obj/gift/xisuidan",
		"amount5"  : 1,
		"amount2"  : 1,
		"file7"    : "/obj/gift/xisuidan",
	]) );
	set( "build", 10020 );
	set( "exits", ([
		"up"        : "/open/clan/ou-cloud-club/room/room745",
		"down"      : "/open/clan/ou-cloud-club/room/room430.c",
		"west"      : "/open/clan/ou-cloud-club/room/room629.c",
		"south"     : "/open/clan/ou-cloud-club/room/room628",
		"east"      : "/open/clan/ou-cloud-club/room/room630.c",
		"north"     : "/open/clan/ou-cloud-club/room/room625.c",
	]) );
	set( "long", @LONG

    這裡是Ｒａｙｋ蒐集的戰利品存放之地，只要他打到的戰利品
都會拿到這邊來存放。只是他存放的方式，似乎....有點凌亂。讓
看的你眼花撩亂，目不暇給，亂成這副德行，真讓你不知道他存的
是戰利品，還是垃圾。

LONG);
	setup();
	replace_program(ROOM);
}
