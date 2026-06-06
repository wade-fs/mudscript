inherit ROOM;
void create() {
	set( "short", "小南家大門" );
	set( "owner", "amdxp" );
	set( "object", ([
		"file5"    : "/open/fire-hole/obj/b-pill",
		"amount1"  : 1000,
		"file8"    : "/obj/gift/xiandan",
		"amount8"  : 1,
		"file2"    : "/open/fire-hole/obj/w-pill",
		"amount6"  : 2,
		"amount5"  : 3,
		"file4"    : "/open/mon/obj/mon-pill",
		"file9"    : "/open/mogi/castle/obj/ninepill",
		"amount4"  : 400,
		"file3"    : "/open/fire-hole/obj/r-pill",
		"amount9"  : 10,
		"amount2"  : 111,
		"file1"    : "/open/killer/obj/atman_pill",
		"file7"    : "/open/ping/obj/poison_pill",
		"file6"    : "/open/fire-hole/obj/p-pill",
		"amount7"  : 423,
		"amount3"  : 131,
	]) );
	set( "build", 10200 );
	set( "exits", ([
		"north"     : "/open/clan/13_luck/room/room54.c",
		"enter"     : "/open/clan/13_luck/room/room67",
	]) );
	set( "light_up", 1 );
	set( "long", @LONG

    自FS於兩千零一年七月重開後，小南就下定決心要重振當年雄風
將在此閉關修練，直到提昇自己的基本內功修為到達無可匹敵境界。
待出關後，挑戰各門各派的英雄豪傑，誓在奪回天下武林盟主之位，
尋得天下間的屠龍刀倚天劍，方可號令天下，唯我獨尊....

LONG);
	setup();
	replace_program(ROOM);
}
