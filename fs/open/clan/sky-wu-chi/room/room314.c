inherit ROOM;
void create() {
	set( "short", "中國廚藝技術學院" );
	set( "owner", "sweety" );
	set( "exits", ([
		"chome"     : "/open/clan/sky-wu-chi/room/hall.c",
		"west"      : "/open/clan/sky-wu-chi/room/room510.c",
	]) );
	set( "object", ([
		"file10"   : "/open/gsword/obj1/bpball",
		"amount9"  : 1,
		"file3"    : "/open/magic-manor/obj/master_snake_head",
		"file7"    : "/open/gblade/obj/sa-head",
		"amount10" : 1,
		"file8"    : "/open/gblade/obj/sa-head",
		"file5"    : "/u/p/pana/q/obj/lan-head",
		"file6"    : "/open/fire-hole/obj/y-pill",
		"file1"    : "/open/fire-hole/obj/r-pill",
		"amount7"  : 1,
		"amount6"  : 13,
		"amount1"  : 2032,
		"file9"    : "/u/p/pana/q/obj/lee-head",
		"amount2"  : 1,
		"amount4"  : 1,
		"amount5"  : 1,
		"file4"    : "/open/mogi/castle/obj/seven2-dark-head",
		"amount8"  : 1,
		"amount3"  : 1,
		"file2"    : "/open/gsword/obj1/bbladeball",
	]) );
	set( "build", 10072 );
	set( "light_up", 1 );
	set( "long", @LONG
你只聞到陣陣的香味撲鼻而來,放眼一看,此地原來是個
廚房,但為何人人是和尚,莫非到了廟裡,你不經意的往頭
上一瞧,斗大的三個字令你無法言語---少林寺,當你發覺來了不
該來的地方時,突然冒出18名大漢,大喊(少林寺18銅人),
還猶豫,快點跑吧!
LONG);
	setup();
	replace_program(ROOM);
}
