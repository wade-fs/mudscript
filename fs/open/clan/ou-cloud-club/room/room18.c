inherit ROOM;
void create() {
	set( "short", "$HIY$地震帶$NOR$" );
	set( "object", ([
		"file2"    : "/open/killer/obj/bellstar",
		"file8"    : "/open/killer/obj/bellstar",
		"file6"    : "/open/killer/obj/bellstar",
		"file3"    : "/open/killer/obj/bellstar",
		"amount7"  : 99999,
		"amount10" : 99999,
		"amount2"  : 99999,
		"file7"    : "/open/killer/obj/bellstar",
		"file5"    : "/open/killer/obj/bellstar",
		"amount4"  : 99999,
		"file10"   : "/open/killer/obj/bellstar",
		"file4"    : "/open/killer/obj/bellstar",
		"file9"    : "/open/killer/obj/bellstar",
		"amount8"  : 99999,
		"amount9"  : 99999,
		"amount3"  : 99999,
		"amount6"  : 99999,
		"amount5"  : 99999,
	]) );
	set( "build", 10088 );
	set( "light_up", 1 );
	set( "exits", ([
		"west"      : "/open/clan/ou-cloud-club/room/room138.c",
		"north"     : "/open/clan/ou-cloud-club/room/room197.c",
		"east"      : "/open/clan/ou-cloud-club/room/room134.c",
		"south"     : "/open/clan/ou-cloud-club/room/room16.c",
	]) );
	set( "long", @LONG
巨大的身形矗立在遠方，遠古的力量之神『泰坦』正守護著
這裡，寬闊的背影讓人心中湧現一股安定的感覺，你不禁想著要
盡快變強能夠去守護別人，隨手抓起一把泥土灑向空中，霎時間
變成無數的光點落在你的身上，一股莫名的力量在體內湧現。

左邊是黯夜殘海(cowboy)的房間，右邊則是天涯舞劍塵(left)之房．

LONG);
	setup();
	replace_program(ROOM);
}
