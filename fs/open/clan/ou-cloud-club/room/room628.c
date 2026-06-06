inherit ROOM;
void create() {
	set( "short", "$HIY$Ｒａｙｋ$HIW$的$HIC$戰利品部屋$NOR$" );
	set( "object", ([
		"amount1"  : 1,
		"file5"    : "/obj/gift/shenliwan",
		"file6"    : "/obj/gift/shenliwan",
		"amount6"  : 1,
		"amount5"  : 1,
		"amount3"  : 1,
		"amount10" : 1,
		"file8"    : "/obj/gift/shenliwan",
		"file7"    : "/obj/gift/shenliwan",
		"file3"    : "/obj/gift/shenliwan",
		"file9"    : "/obj/gift/shenliwan",
		"amount4"  : 1,
		"file4"    : "/obj/gift/shenliwan",
		"file1"    : "/obj/gift/shenliwan",
		"file2"    : "/obj/gift/shenliwan",
		"amount2"  : 1,
		"file10"   : "/obj/gift/shenliwan",
		"amount8"  : 1,
		"amount7"  : 1,
		"amount9"  : 1,
	]) );
	set( "build", 10404 );
	set( "owner", "rayk" );
	set( "exits", ([
		"north"     : "/open/clan/ou-cloud-club/room/room627",
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
