inherit ROOM;
void create() {
	set( "short", "藏經閣" );
	set( "object", ([
		"file1"    : "/open/wu/obj/haoforce_book",
		"amount3"  : 1,
		"file10"   : "/open/poison/obj/box_book",
		"file7"    : "/open/marksman/obj/book",
		"amount5"  : 1,
		"amount4"  : 1,
		"file3"    : "/open/snow/obj/book",
		"file5"    : "/open/gblade/obj/book",
		"amount8"  : 1,
		"file4"    : "/open/snow/obj/book",
		"file8"    : "/open/ping/obj/linpo_book",
		"file9"    : "/open/tendo/obj/book",
		"file6"    : "/open/gsword/obj/sword_book",
		"amount7"  : 1,
		"amount9"  : 1,
		"amount6"  : 1,
		"amount10" : 1,
		"amount1"  : 1,
		"amount2"  : 1,
		"file2"    : "/open/gblade/obj/blade-book",
	]) );
	set( "build", 10121 );
	set( "light_up", 1 );
	set( "exits", ([
		"north"     : "/open/clan/13_luck/room/room136.c",
		"up"        : "/open/clan/13_luck/room/room143",
	]) );
	set( "long", @LONG

　　一進房門，即看見正中央的壁上掛著一副書畫，上頭寫著一個斗
大的「靜」字，而其裝潢擺飾也不是普通的豪華，一點也沒有閣樓狹
隘的感覺，反而有一股舒適之感。這裡的藏書不下於一萬本，就是消
失於武林多時的武功，也可在這找到其祕笈心法。

LONG);
	setup();
	replace_program(ROOM);
}
