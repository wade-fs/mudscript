inherit ROOM;
void create() {
	set( "short", "leggings" );
	set( "owner", "hild" );
	set( "object", ([
		"amount2"  : 1,
		"amount4"  : 1,
		"file4"    : "/open/ghost-hole/obj/eq/ghost-leggings",
		"amount7"  : 1,
		"amount5"  : 1,
		"file5"    : "/open/ghost-hole/obj/eq/ghost-leggings",
		"file2"    : "/open/ghost-hole/obj/eq/ghost-leggings",
		"file6"    : "/open/ghost-hole/obj/eq/ghost-leggings",
		"file7"    : "/open/ghost-hole/obj/eq/ghost-leggings",
		"amount10" : 1,
		"amount6"  : 1,
		"file10"   : "/open/ghost-hole/obj/eq/ghost-leggings",
	]) );
	set( "build", 10004 );
	set( "exits", ([
		"enter"     : "/open/clan/sky-wu-chi/room/room259.c",
		"west"      : "/open/clan/sky-wu-chi/room/room42.c",
	]) );
	set( "light_up", 1 );
	set( "long", @LONG
你漫步欣賞著這湖美麗的風光美景,發現在不遠處有一條連接至
湖中小島的橋,止時的你急著前往小島去一探究竟是否為一個隱
居的好地方,正當你靠近橋時發現橋口有一塊大石,石上寫著不歡
迎外來客的拜訪,只歡迎要來止安度晚年的人,看到止你心中一慌
不知是否要就只隱居去.
LONG);
	setup();
	replace_program(ROOM);
}
