inherit ROOM;
void create() {
	set( "short", "小豬頭的主臥房" );
	set( "object", ([
		"file3"    : "/open/magic-manor/fire/obj/fire-fan",
		"file1"    : "/open/ghost-hole/obj/eq/ghost-leggings",
		"amount8"  : 1,
		"amount6"  : 1,
		"amount9"  : 1,
		"amount2"  : 1,
		"file10"   : "/open/fire-hole/obj/y-pill",
		"amount4"  : 1,
		"file8"    : "/open/magic-manor/wood/obj/wood-sword",
		"amount10" : 5,
		"file5"    : "/open/magic-manor/fire/obj/fire-fan",
		"amount3"  : 1,
		"amount5"  : 1,
		"file7"    : "/open/magic-manor/wood/obj/wood-sword",
		"file2"    : "/open/ghost-hole/obj/eq/ghost-gloves",
		"file9"    : "/open/magic-manor/wood/obj/wood-sword",
		"amount1"  : 1,
		"file4"    : "/open/magic-manor/fire/obj/fire-fan",
		"amount7"  : 1,
		"file6"    : "/open/magic-manor/fire/obj/fire-fan",
	]) );
	set( "owner", "pighead" );
	set( "build", 10074 );
	set( "light_up", 1 );
	set( "exits", ([
		"west"      : "/open/clan/13_luck/room/room412",
	]) );
	set( "long", @LONG

    這裡是可愛小豬頭的主臥房，因為小豬頭在外面累了一天，洗完
澡後，看完自己喜歡的動作片，就到了該睡覺的時候，在這旋轉彈簧
床上，不但可以讓自己好好的休息，也提供了小豬頭和女人大戰的場
所，藉由許多的外加功能，可以嘗試許多從未體驗過的姿勢。

LONG);
	setup();
	replace_program(ROOM);
}
