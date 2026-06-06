inherit ROOM;
void create() {
	set( "short", "軍火庫大門" );
	set( "object", ([
		"amount10" : 1,
		"file1"    : "/open/mon/obj/ghost-claw",
		"file9"    : "/open/sky/obj/lucky_grasslink",
		"file6"    : "/open/mon/obj/ghost-claw",
		"file7"    : "/open/magic-manor/obj/dark-soul-dagger",
		"amount7"  : 1,
		"amount9"  : 1,
		"amount1"  : 1,
		"file2"    : "/open/mogi/castle/obj/ninepill",
		"file5"    : "/open/wu/obj/armband",
		"file3"    : "/open/mon/obj/mon-pill",
		"file4"    : "/open/sky/obj/lucky_grasslink",
		"file8"    : "/open/prayer/obj/boris-cloth",
		"amount4"  : 1,
		"amount8"  : 1,
		"amount5"  : 1,
		"amount6"  : 1,
		"file10"   : "/open/dancer/obj/yuawaist",
		"amount2"  : 236,
		"amount3"  : 15,
	]) );
	set( "owner", "bbsboss" );
	set( "build", 11679 );
	set( "exits", ([
		"west"      : "/open/clan/ou-cloud-club/room/room136.c",
		"east"      : "/open/clan/ou-cloud-club/room/room169.c",
	]) );
	set( "light_up", 1 );
	set( "long", @LONG
才一踏入此處...濃濃的殺氣籠罩在心頭....
抬頭一看...原來才知道這邊是小馬四處搜括來的強大軍火存放處
仔細一看...這全都是來自江湖各大門派的鎮派之寶
聖火..瀧山...風林山寨........
江湖的風風雨雨......
第一個房間是存放身體的防具....
LONG);
	setup();
	replace_program(ROOM);
}
