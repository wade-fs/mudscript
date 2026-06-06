inherit ROOM;
void create() {
	set( "short", "河馬的水池" );
	set( "object", ([
		"amount7"  : 1,
		"amount4"  : 1,
		"amount2"  : 47,
		"amount6"  : 1,
		"amount10" : 1,
		"file8"    : "/open/killer/weapon/k_boot3",
		"amount9"  : 1,
		"file9"    : "/obj/gift/hobowdan",
		"file4"    : "/open/mon/obj/ghost-legging",
		"file10"   : "/open/sky/obj/lucky_grasslink",
		"file3"    : "/open/mon/obj/ghost-claw",
		"file7"    : "/open/dancer/obj/yuawaist",
		"file6"    : "/open/mon/obj/ghost-cloak",
		"amount5"  : 1,
		"file1"    : "/open/mon/obj/mon-pill",
		"file5"    : "/open/mon/obj/ghost-helmet",
		"amount8"  : 1,
		"amount1"  : 8,
		"file2"    : "/open/mogi/castle/obj/ninepill",
		"amount3"  : 1,
	]) );
	set( "light_up", 1 );
	set( "build", 10139 );
	set( "owner", "juliet" );
	set( "exits", ([
		"west"      : "/open/clan/ou-cloud-club/room/room473",
	]) );
	set( "long", @LONG
《魔獸世界》OB開放測試伺服器列表  2005/10/04 
伺服器名稱　　伺服器類型
暗影之月　　　　　PVE
尖　　石　　　　　PVP
雷　　鱗　　　　　PVP
巨龍之喉　　　　　PVP
噬 骨 者　　　　　 PVP
火焰之樹　　　　　PVE
LONG);
	setup();
	replace_program(ROOM);
}
