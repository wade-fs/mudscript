inherit ROOM;
void create() {
	set( "short", "$HIC$無言的山丘$NOR$" );
	set( "owner", "pony" );
	set( "object", ([
		"file2"    : "/open/mogi/castle/obj/ninepill",
		"amount10" : 1,
		"file4"    : "/open/killer/obj/atman_pill",
		"amount7"  : 1,
		"file9"    : "/obj/gift/hobowdan",
		"amount4"  : 86,
		"file1"    : "/open/capital/obj/blade2",
		"amount2"  : 151,
		"amount1"  : 1,
		"amount8"  : 1,
		"file5"    : "/open/mon/obj/ghost-claw",
		"file6"    : "/open/fire-hole/obj/p-pill",
		"file10"   : "/obj/stone/suipian",
		"amount6"  : 22,
		"amount3"  : 9,
		"amount5"  : 1,
		"file3"    : "/open/ping/obj/poison_pill",
		"amount9"  : 1,
		"file8"    : "/open/snow/obj/figring",
		"file7"    : "/open/wu/obj/figring",
	]) );
	set( "light_up", 1 );
	set( "build", 23466 );
	set( "exits", ([
		"west"      : "/open/clan/ou-cloud-club/room/room15.c",
		"east"      : "/open/clan/ou-cloud-club/room/room233",
	]) );
	set( "long", @LONG
這是一間小木屋，名家設計的典雅風格再加上高級的柚木建材，使得整
座小屋散發出自然的品味。這間小屋沒什麼裝潢，只有一張核桃木製方桌和
四張橡木椅靜靜的火爐旁邊，散發出木製品特有的溫暖感覺。正對門的牆上
掛著一幅極大的油畫，畫著一座盛開著油菜花的小山丘。畫的旁邊有一扇門
通往內室。
LONG);
	setup();
	replace_program(ROOM);
}
