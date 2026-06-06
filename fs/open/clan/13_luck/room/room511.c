inherit ROOM;
void create() {
	set( "short", "瑤光堂練武場" );
	set( "object", ([
		"amount1"  : 1,
		"file2"    : "/open/mon/obj/ghost-legging",
		"amount4"  : 1,
		"file4"    : "/open/mon/obj/ghost-cloak",
		"amount2"  : 1,
		"file1"    : "/open/mon/obj/ghost-helmet",
	]) );
	set( "owner", "aaabc" );
	set( "build", 12148 );
	set( "light_up", 1 );
	set( "exits", ([
		"south"     : "/open/clan/13_luck/room/room512",
	]) );
	set( "long", @LONG
你現在站在練武場中，你發現在這的殺氣遠不如其他的練武場，而
且在這裡練武的弟子們武功並不是很好，你向他們尋問了一下才知道他
們是剛加入的新成員，被送到這裡訓練，於是你在這觀看他們的訓練過
程，你突然發現有一部份的人在旁邊的角落裡練習所有武功中最基本的
沉馬，那是最新一批加入的成員。
LONG);
	setup();
	replace_program(ROOM);
}
