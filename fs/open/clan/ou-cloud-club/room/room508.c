inherit ROOM;
void create() {
	set( "short", "魔法學徒-貝爾蒂娜" );
	set( "light_up", 1 );
	set( "object", ([
		"amount9"  : 1,
		"file6"    : "/obj/gift/unknowdan",
		"file5"    : "/obj/gift/unknowdan",
		"amount3"  : 1,
		"amount1"  : 1,
		"file9"    : "/obj/gift/unknowdan",
		"amount5"  : 1,
		"file3"    : "/obj/gift/unknowdan",
		"file7"    : "/obj/gift/unknowdan",
		"amount10" : 1,
		"amount8"  : 1,
		"file10"   : "/obj/gift/unknowdan",
		"file2"    : "/obj/gift/unknowdan",
		"amount7"  : 1,
		"file8"    : "/obj/gift/unknowdan",
		"file1"    : "/obj/gift/unknowdan",
		"amount2"  : 1,
		"file4"    : "/obj/gift/unknowdan",
		"amount6"  : 1,
		"amount4"  : 1,
	]) );
	set( "build", 10041 );
	set( "owner", "ctx" );
	set( "exits", ([
		"east"      : "/open/clan/ou-cloud-club/room/room506",
	]) );
	set( "long", @LONG
魔法學徒貝爾蒂娜,出身於神職家庭,但一開始本人並沒有對
於神職有相當的興趣,反倒是同於恩萊科,對魔法的使用相當有興
趣,在試練中經過克麗絲長公主的訓練時,練出一手強大的水系魔
法,同時也是強大的神聖魔法,也在經過主角恩萊科的影響後 ,重
新對於神職有新的想法,最終也成為一名聖女。

LONG);
	setup();
	replace_program(ROOM);
}
