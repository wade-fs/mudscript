inherit ROOM;
void create() {
	set( "short", "雜具室" );
	set( "owner", "ganwunaa" );
	set( "object", ([
		"amount10" : 1,
		"file10"   : "/open/mon/obj/ghost-cloak",
		"file2"    : "/open/quests/snake/npc/obj/snake_gem",
		"amount7"  : 1,
		"amount9"  : 1,
		"amount3"  : 1,
		"amount2"  : 1,
		"file4"    : "/open/mon/obj/ghost-helmet",
		"amount6"  : 1,
		"file3"    : "/open/gsword/obj/may_ring",
		"amount5"  : 1,
		"file7"    : "/daemon/class/blademan/obj/shield",
		"amount8"  : 1,
		"file8"    : "/open/mon/obj/ghost-legging",
		"amount1"  : 1,
		"file6"    : "/open/wu/npc/obj/armband",
		"file5"    : "/daemon/class/fighter/figring",
		"amount4"  : 1,
		"file1"    : "/open/sky/obj/lucky_grasslink",
		"file9"    : "/open/wind-rain/obj/sun_red_cloth",
	]) );
	set( "build", 10646 );
	set( "light_up", 1 );
	set( "exits", ([
		"out"       : "/open/clan/13_luck/room/room146",
	]) );
	set( "long", @LONG
    你被掛像放行走到這裡,四處一片漆黑,當你再走近一步
天花板突然變成一片銀河,四周也跟著亮了起來,這裡只有一
張小桌子,桌上放著一頂帽子,帽子裡藏著一把破破爛爛的劍
桌下堆著一些破破爛爛的武器和裝備,突然一隻貓頭鷹從你
頭上飛了過去並丟下一張紙,撿起來一看上面寫著歡迎光臨

LONG);
	setup();
	replace_program(ROOM);
}
