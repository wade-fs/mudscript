inherit ROOM;
void create() {
	set( "short", "$HIY$Ｒａｙｋ$HIW$的$HIC$戰利品部屋$NOR$" );
	set( "owner", "rayk" );
	set( "object", ([
		"file5"    : "/open/capital/obj/book",
		"file7"    : "/open/capital/obj/book",
		"file8"    : "/open/capital/obj/book",
		"amount1"  : 1,
		"file2"    : "/open/capital/obj/book",
		"amount9"  : 1,
		"amount5"  : 1,
		"amount3"  : 1,
		"file1"    : "/open/capital/obj/book",
		"amount8"  : 1,
		"amount6"  : 1,
		"file10"   : "/open/capital/obj/book",
		"file3"    : "/open/capital/obj/book",
		"amount10" : 1,
		"file9"    : "/open/capital/obj/book",
		"amount4"  : 1,
		"file4"    : "/open/capital/obj/book",
		"amount2"  : 1,
		"file6"    : "/open/capital/obj/book",
		"amount7"  : 1,
	]) );
	set( "build", 10002 );
	set( "exits", ([
		"south"     : "/open/clan/ou-cloud-club/room/room627",
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
