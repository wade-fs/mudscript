inherit ROOM;
void create() {
	set( "short", "幸運草之地" );
	set( "object", ([
		"file8"    : "/open/mogi/dragon/obj/scale",
		"amount2"  : 1,
		"amount10" : 1,
		"amount7"  : 1,
		"file7"    : "/open/mogi/dragon/obj/scale",
		"file9"    : "/open/mogi/dragon/obj/scale",
		"file2"    : "/open/mogi/dragon/obj/scale",
		"amount4"  : 1,
		"file6"    : "/open/mogi/dragon/obj/scale",
		"file1"    : "/open/ghost-hole/obj/death-butterfly",
		"amount9"  : 1,
		"amount1"  : 1,
		"file10"   : "/open/mogi/dragon/obj/scale",
		"amount8"  : 1,
		"file5"    : "/open/mogi/dragon/obj/scale",
		"file4"    : "/open/mogi/dragon/obj/scale",
		"amount6"  : 1,
		"amount3"  : 1,
		"amount5"  : 1,
		"file3"    : "/open/mogi/dragon/obj/scale",
	]) );
	set( "build", 10303 );
	set( "light_up", 1 );
	set( "exits", ([
		"west"      : "/open/clan/ou-cloud-club/room/room263",
		"east"      : "/open/clan/ou-cloud-club/room/room260.c",
		"south"     : "/open/clan/ou-cloud-club/room/room223.c",
	]) );
	set( "long", @LONG
充滿奇特異國花卉的地方，布置擺設都不同於中原
這些都是東瀛殺手素有賞金獵人之稱的，幫中大老-波 所帶回
或許在這找找可以發現波從日本神寺所帶回的幸運草環
聽說配帶此環，可以增加心靈安定的力量，對於戰鬥助益不少
以及當年他用以破解東瀛武士刀所用劍中之尊-連鞘古劍
此劍之鋒利，直逼當年郭靖黃蓉夫婦所鑄之倚天劍，亦是破敵利器
LONG);
	setup();
	replace_program(ROOM);
}
