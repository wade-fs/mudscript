inherit ROOM;
void create() {
	set( "short", "gk eq-gloves" );
	set( "owner", "cong" );
	set( "light_up", 1 );
	set( "object", ([
		"amount6"  : 1,
		"amount5"  : 1,
		"amount3"  : 1,
		"amount7"  : 1,
		"amount8"  : 1,
		"amount10" : 1,
		"file2"    : "/open/ghost-hole/obj/eq/ghost-gloves",
		"amount2"  : 1,
		"file5"    : "/open/ghost-hole/obj/eq/ghost-gloves",
		"file10"   : "/open/ghost-hole/obj/eq/ghost-gloves",
		"file3"    : "/open/ghost-hole/obj/eq/ghost-gloves",
		"file7"    : "/open/ghost-hole/obj/eq/ghost-gloves",
		"amount4"  : 1,
		"file1"    : "/open/ghost-hole/obj/eq/ghost-gloves",
		"file4"    : "/open/ghost-hole/obj/eq/ghost-gloves",
		"amount1"  : 1,
		"file6"    : "/open/ghost-hole/obj/eq/ghost-gloves",
		"file8"    : "/open/ghost-hole/obj/eq/ghost-gloves",
	]) );
	set( "build", 10023 );
	set( "exits", ([
		"west"      : "/open/clan/sky-wu-chi/room/room95",
	]) );
	set( "long", @LONG

藤床紙帳朝眠起．說不盡無佳思．

沈香煙斷玉爐寒．伴我情懷如水．

笛聲三弄．梅心驚破．多少春情意

小風疏雨蕭蕭地．又催下千行淚．

吹簫人去玉樓空．腸斷與誰同倚．

一枝折得．人間天上．沒個人堪寄



LONG);
	setup();
	replace_program(ROOM);
}
