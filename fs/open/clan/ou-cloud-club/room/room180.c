inherit ROOM;
void create() {
	set( "short", "$HIM$御書房$NOR$" );
	set( "owner", "enter" );
	set( "object", ([
		"amount5"  : 1,
		"amount1"  : 1,
		"amount2"  : 1,
		"amount4"  : 1,
		"file4"    : "/open/killer/headkill/obj/world_dag",
		"file1"    : "/open/ping/questsfan/obj/diamond_cloak",
		"file10"   : "/open/killer/headkill/obj/world_dag",
		"file3"    : "/open/ping/obj/poison_pill",
		"file9"    : "/open/mogi/castle/obj/ninepill",
		"file2"    : "/open/capital/obj/gold_pill",
		"amount9"  : 900,
		"file6"    : "/open/doctor/obj/d-mark",
		"file8"    : "/open/ping/questsfan/obj/diamond_armor",
		"amount3"  : 970,
		"amount6"  : 1,
		"amount7"  : 1,
		"amount10" : 1,
		"amount8"  : 1,
		"file7"    : "/open/ping/questsfan/obj/diamond_hairpin",
		"file5"    : "/open/capital/guard/gring",
	]) );
	set( "light_up", 1 );
	set( "build", 10149 );
	set( "exits", ([
		"west"      : "/open/clan/ou-cloud-club/room/room13.c",
		"north"     : "/open/clan/ou-cloud-club/room/room144.c",
	]) );
	set( "long", @LONG
幫主的御書房，牆上掛著另一幅上千張的狗
狗拼圖，右邊牆角擺著各式各樣的書架放置幫主
的武學心得及秘笈，中間擺著許多的木人樁跟銅
人以供幫主在此房練武之用，只見地上則躺著許
多的壞掉的木銅人，據說幫主一天可打壞上百的
木人樁及銅人像．

LONG);
	setup();
	replace_program(ROOM);
}
