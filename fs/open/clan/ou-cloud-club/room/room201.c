inherit ROOM;
void create() {
	set( "short", "掩光天" );
	set( "owner", "del" );
	set( "object", ([
		"amount10" : 29,
		"amount7"  : 145,
		"file6"    : "/open/fire-hole/obj/w-pill",
		"file10"   : "/open/fire-hole/obj/p-pill",
		"amount6"  : 48,
		"amount9"  : 14,
		"file3"    : "/open/mogi/castle/obj/ninepill",
		"file4"    : "/open/mon/obj/mon-pill",
		"amount4"  : 215,
		"file9"    : "/open/mogi/castle/obj/sspill",
		"amount1"  : 8,
		"amount5"  : 61,
		"amount8"  : 184,
		"file1"    : "/open/fire-hole/obj/y-pill",
		"file8"    : "/open/fire-hole/obj/g-pill",
		"amount3"  : 12,
		"file2"    : "/open/fire-hole/obj/k-pill",
		"file5"    : "/open/fire-hole/obj/b-pill",
		"file7"    : "/open/fire-hole/obj/r-pill",
		"amount2"  : 38,
	]) );
	set( "item_desc", ([
		"blade" : @ITEM
刀長七尺，全黑的刀身上有一火焰狀印記，散發一股霸氣‧
ITEM,
	]) );
	set( "light_up", 1 );
	set( "build", 10033 );
	set( "exits", ([
		"eastdown"  : "/open/clan/ou-cloud-club/room/room220",
		"south"     : "/open/clan/ou-cloud-club/room/room191.c",
	]) );
	set( "long", @LONG
你推開半掩的木門，一陣清淡的檀香迎面而來，眼前是
一間擺設簡單的屋子，但卻有一股無形的殺氣讓人有點喘不
過氣來，環顧四週，原來殺氣是來自橫掛在牆上的一把黝黑
的刀(Blade) ，左手邊有條往下的石梯，不曉得通往哪裡。
ˉ
ˉ鬼神至尊『惡霸連擊』小型惡人(Badman)
ˉ狂暴酷龍『浩瀚無垠』酷斯拉(Gozila)
LONG);
	setup();
	replace_program(ROOM);
}
