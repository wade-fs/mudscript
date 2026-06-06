inherit ROOM;
void create() {
	set( "short", "自知喘息不歡心" );
	set( "owner", "matrix" );
	set( "object", ([
		"amount9"  : 1,
		"file6"    : "/open/gsword/obj/yubracelet",
		"file9"    : "/open/gsword/obj/ring-1",
		"amount6"  : 1,
		"file7"    : "/open/ping/obj/iceger",
		"file2"    : "/open/gsword/obj/yugem",
		"amount8"  : 1,
		"amount3"  : 1,
		"amount2"  : 1,
		"file1"    : "/open/port/obj/tiger_boots",
		"amount5"  : 125,
		"amount4"  : 100,
		"file4"    : "/open/killer/obj/s_pill",
		"amount1"  : 1,
		"file5"    : "/open/mon/obj/mon-pill",
		"file8"    : "/open/scholar/obj/icefan",
		"file3"    : "/open/ping/obj/chilin_legging",
		"amount7"  : 1,
	]) );
	set( "build", 10040 );
	set( "light_up", 1 );
	set( "exits", ([
		"east"      : "/open/clan/sky-wu-chi/room/room351.c",
		"west"      : "/open/clan/sky-wu-chi/room/room267.c",
		"chome"     : "/open/clan/sky-wu-chi/room/hall.c",
	]) );
	set( "long", @LONG
行者數息、隨息得定，入心之覺受，因內氣入頭部甚深部位，誘發根本煩惱起故
心生不歡喜(憂受)，行者自知之。惟知一切法均妄而不實，何煩惱之有。
第十個自知喘息不歡心，在數息得定後，進入心的狀態，因內氣入頭部甚深部位
時，會掃到阿賴耶識的種子，會誘發根本煩惱起。妄想念起，會想我以前打坐心
好像很清淨，沒有妄想，現在為什麼會起煩惱法？剛打坐時，心亂七八糟，坐不
下去，後用數息法把它控制了。
LONG);
	setup();
	replace_program(ROOM);
}
