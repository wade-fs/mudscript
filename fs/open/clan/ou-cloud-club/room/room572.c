inherit ROOM;
void create() {
	set( "short", "$HIC$奇犽‧揍敵客$HIW$ソ$HIR$武技$HIY$訓練室$NOR$" );
	set( "object", ([
		"file2"    : "/open/mon/obj/mon-pill",
		"file8"    : "/open/fire-hole/obj/p-pill",
		"file6"    : "/open/killer/obj/s_pill",
		"file1"    : "/open/fire-hole/obj/y-pill",
		"amount2"  : 298,
		"amount1"  : 165,
		"file9"    : "/open/fire-hole/obj/r-pill",
		"file7"    : "/open/fire-hole/obj/k-pill",
		"amount3"  : 199,
		"amount7"  : 223,
		"amount5"  : 688,
		"amount4"  : 314,
		"amount6"  : 950,
		"file3"    : "/open/fire-hole/obj/b-pill",
		"amount8"  : 183,
		"file4"    : "/open/fire-hole/obj/g-pill",
		"amount9"  : 486,
		"file5"    : "/open/fire-hole/obj/w-pill",
	]) );
	set( "build", 10037 );
	set( "light_up", 1 );
	set( "owner", "killua" );
	set( "exits", ([
		"west"      : "/open/clan/ou-cloud-club/room/room453",
	]) );
	set( "long", @LONG

    奇犽‧揍敵客除了念能力外，當然還會其他的技巧囉。出身
於世界第一暗殺家族的奇犽‧揍敵客，從小就受著殺手的菁英式
教育及殺人的觀念灌輸，暗殺的技巧自然而然有著極高的造詣。
不過由於他不想繼承家業，所以他也很少修練這些技巧了。

LONG);
	setup();
	replace_program(ROOM);
}
