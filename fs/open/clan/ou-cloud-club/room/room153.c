inherit ROOM;
void create() {
	set( "short", "小燕的7-ELEVEN" );
	set( "owner", "pigdevil" );
	set( "exits", ([
		"out"       : "/open/clan/ou-cloud-club/room/room479",
		"north"     : "/open/clan/ou-cloud-club/room/room221",
	]) );
	set( "light_up", 1 );
	set( "object", ([
		"file4"    : "/open/magic-manor/ghost/obj/trigram-pill",
		"amount1"  : 41,
		"amount7"  : 1,
		"amount10" : 1,
		"amount8"  : 5,
		"file10"   : "/open/magic-manor/obj/soil-ball",
		"file9"    : "/open/magic-manor/water/obj/water-ribbon",
		"amount9"  : 1,
		"file2"    : "/open/killer/headkill/obj/world_dag",
		"file1"    : "/open/fire-hole/obj/w-pill",
		"amount3"  : 1,
		"file7"    : "/open/magic-manor/water/obj/water-ribbon",
		"amount6"  : 15,
		"file6"    : "/open/killer/obj/s_pill",
		"amount5"  : 439,
		"file3"    : "/open/capital/obj/blade2",
		"file8"    : "/open/mogi/castle/obj/ninepill",
		"file5"    : "/open/mogi/castle/obj/sspill",
		"amount2"  : 1,
		"amount4"  : 5,
	]) );
	set( "build", 16000 );
	set( "long", @LONG

       火焰鴨在傲雲的第一個家,他的好朋友小雯就住在隔壁,損友slayer住在斜對
 面火焰鴨是一隻相當有義氣的鴨子,雖然被他的損友slayer殺了很多腦細胞,但是仍
 然相當照顧他,雖然火焰鴨已經很老了,不過他傳授了他的技能給小敏讓小敏在天道
 派發揚光大.目前正在閉關中,有朝一日將會重出江湖.

LONG);
	setup();
	replace_program(ROOM);
}
