inherit ROOM;
void create() {
	set( "short", "『石板小路』" );
	set( "owner", "poll" );
	set( "object", ([
		"amount3"  : 1,
		"file5"    : "/open/magic-manor/obj/fire-ball",
		"amount1"  : 1,
		"amount8"  : 1,
		"amount2"  : 1,
		"amount4"  : 1,
		"file4"    : "/open/mogi/dragon/obj/scale",
		"amount9"  : 1,
		"file6"    : "/open/magic-manor/obj/fire-ball",
		"file2"    : "/open/magic-manor/obj/soil-ball",
		"amount7"  : 1,
		"file9"    : "/open/mogi/dragon/obj/scale",
		"amount10" : 1,
		"file3"    : "/open/magic-manor/obj/soil-ball",
		"amount5"  : 1,
		"file10"   : "/open/magic-manor/obj/golden-ball",
		"amount6"  : 1,
		"file8"    : "/open/magic-manor/obj/fire-ball",
		"file7"    : "/open/magic-manor/obj/golden-ball",
		"file1"    : "/open/magic-manor/obj/water-ball",
	]) );
	set( "build", 10218 );
	set( "light_up", 1 );
	set( "exits", ([
		"west"      : "/open/clan/13_luck/room/room249",
	]) );
	set( "long", @LONG
爬到了山頂上面來，你雖然很累，可是內功調息過後卻感覺舒服多了。
在這平靜的時刻，往四方望去，只見大地踩在你腳底下，讓你的心胸開闊了
許多，使得你原本的雄心壯志，更加的堅定了。而在你旁邊有個浪人，看起
來似乎不怎麼樣，你想他也是來這邊看風景的吧。往東邊看過去，東邊有個
涼亭，而來這邊遊玩的人都會在那個涼亭休憩一下，讓自己的精神回復。
LONG);
	setup();
	replace_program(ROOM);
}
