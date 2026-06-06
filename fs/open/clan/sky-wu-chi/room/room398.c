inherit ROOM;
void create() {
	set( "short", "【山澗雲深】" );
	set( "owner", "working" );
	set( "object", ([
		"amount8"  : 1,
		"file9"    : "/open/killer/obj/fire-knife",
		"amount3"  : 1055,
		"amount10" : 1,
		"file4"    : "/open/killer/obj/soul-hands",
		"amount6"  : 1,
		"file6"    : "/open/killer/headkill/obj/world_dag",
		"file5"    : "/open/killer/headkill/obj/world_dag",
		"amount5"  : 1,
		"file8"    : "/open/magic-manor/obj/dark-soul-dagger",
		"file7"    : "/open/magic-manor/obj/dark-soul-dagger",
		"amount1"  : 1,
		"file2"    : "/open/killer/headkill/obj/i_dag",
		"file3"    : "/open/killer/obj/s_pill",
		"amount4"  : 1,
		"amount9"  : 1,
		"file10"   : "/open/killer/obj/fire-knife",
		"amount7"  : 1,
		"amount2"  : 1,
		"file1"    : "/open/killer/obj/dagger",
	]) );
	set( "build", 11099 );
	set( "exits", ([
		"down"      : "/open/clan/sky-wu-chi/room/room397.c",
		"east"      : "/open/clan/sky-wu-chi/room/room412.c",
	]) );
	set( "long", @LONG

        這裡就快到縹緲峰絕頂了，越往上走，山勢越高，繚繞在你身邊
    的白霧越來越濃，往南則是下山的路。沿著山道沒走幾步，山道突然
    消失，在你面前是一條山澗，山澗之中雲霧繚繞，你根本無法看清對
    面。一條鐵索深入雲中，旁邊有一塊石碑在你眼前，上書『仙愁門』
    三個大字，蓋因上山之艱辛吧。

    時值隆冬，天上的雲嚴嚴實實的，雪下個不停，天地已是一片潔白了。

LONG);
	setup();
	replace_program(ROOM);
}
