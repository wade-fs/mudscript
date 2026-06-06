inherit ROOM;
void create() {
	set( "short", "東森幼幼台的房間" );
	set( "owner", "cong" );
	set( "light_up", 1 );
	set( "object", ([
		"file3"    : "/open/firedancer/npc/eq/r_pants",
		"amount6"  : 1,
		"file7"    : "/open/firedancer/npc/eq/r_hands",
		"file8"    : "/open/firedancer/npc/eq/r_boots",
		"amount3"  : 1,
		"amount1"  : 566,
		"file2"    : "/obj/stone/suipian",
		"amount8"  : 1,
		"amount4"  : 1,
		"file1"    : "/obj/stone/powder",
		"amount2"  : 59,
		"amount5"  : 1,
		"file6"    : "/open/gsword/obj1/bpball",
		"file4"    : "/obj/gift/lingzhi",
		"file5"    : "/obj/gift/hobowdan",
		"amount7"  : 1,
	]) );
	set( "build", 10111 );
	set( "exits", ([
		"takeroad"  : "/open/clan/sky-wu-chi/room/room627",
		"j1"        : "/open/clan/sky-wu-chi/room/room538",
		"east"      : "/open/clan/sky-wu-chi/room/room543.c",
		"west"      : "/open/clan/sky-wu-chi/room/room544.c",
		"chome"     : "/open/clan/sky-wu-chi/room/hall.c",
	]) );
	set( "long", @LONG
這裡是東森幼幼台的房間，房間四周相當零亂牆上還掛著幾張照片
你走過去仔細一看，原來這是東森幼幼台以前的好夥伴「超級壞馬」
你往第二張照片一看不自覺的一驚，這不是我們的老大路小嘉嗎!?
照片怎麼會是黑白的?旁邊還有一行小字「紀念前瀧山師父路小嘉」
你搖搖頭收起腦中的思緒，往四周一看東森幼幼台似乎不在房間裡
你想起本來的目的，趁東森幼幼台不在時來借他的珍藏地理錄影帶
傳說中已經絕版的「川道和侵蝕」，你順手從桌上拿起求學好青年
夢寐以求的寶物，想一想東西到手還是趕快離開吧。
LONG);
	setup();
	replace_program(ROOM);
}
