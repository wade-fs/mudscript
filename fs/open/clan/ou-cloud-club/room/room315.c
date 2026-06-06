inherit ROOM;
void create() {
	set( "short", "理財聖經" );
	set( "object", ([
		"amount8"  : 1,
		"amount9"  : 1,
		"file10"   : "/open/magic-manor/water/obj/water-ribbon",
		"file2"    : "/open/capital/obj/4-4",
		"file5"    : "/open/ping/obj/neck0",
		"amount6"  : 15,
		"file4"    : "/open/fire-hole/obj/y-pill",
		"amount4"  : 55,
		"amount10" : 1,
		"amount2"  : 1,
		"amount1"  : 150,
		"file1"    : "/open/fire-hole/obj/y-pill",
		"file3"    : "/open/fire-hole/obj/r-pill",
		"amount3"  : 99,
		"file6"    : "/open/fire-hole/obj/b-pill",
		"amount5"  : 1,
		"amount7"  : 1,
		"file7"    : "/open/scholar/room/newplan/obj/s-shield",
		"file9"    : "/open/mogi/castle/obj/sspill",
		"file8"    : "/open/magic-manor/water/obj/water-ribbon",
	]) );
	set( "build", 10037 );
	set( "light_up", 1 );
	set( "exits", ([
		"west"      : "/open/clan/ou-cloud-club/room/room324.c",
		"down"      : "/open/clan/ou-cloud-club/room/room323",
	]) );
	set( "long", @LONG
許多人汲汲營營於賺錢，卻不得其門而入
許多人具備致富條件，但昧於理財以致於錯失良機
更甚者，因投資錯誤而傾家蕩產
本書融合實戰經驗與豐富學理
鑽研十二則理財鐵律
助妳「樂在理財，輕鬆致富」
從容躋身億萬富翁之列
LONG);
	setup();
	replace_program(ROOM);
}
