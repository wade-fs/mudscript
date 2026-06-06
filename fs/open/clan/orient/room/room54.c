inherit ROOM;
void create() {
	set( "short", "『$HIC$陵王居$NOR$』" );
	set( "owner", "working" );
	set( "object", ([
		"amount2"  : 1,
		"file4"    : "/obj/gift/hobowdan",
		"amount1"  : 1,
		"file1"    : "/open/gsword/obj1/karmor",
		"amount8"  : 1,
		"amount4"  : 1,
		"file2"    : "/open/magic-manor/obj/magic-sign",
		"file8"    : "/open/gsword/obj1/karmor",
	]) );
	set( "build", 12841 );
	set( "exits", ([
		"north"     : "/open/clan/orient/room/room7.c",
		"east"      : "/open/clan/orient/room/room37",
		"west"      : "/open/clan/orient/room/room11.c",
	]) );
	set( "long", @LONG
龍    鱗    丹    兵
     |     |     |     |
    龍    鱗    丹    兵
     |     |     |     |
    水    鱗    丹    兵
     |     |     |     |
    水    鱗    丹    兵
     |     |     |     |
    廊----廊----廊--『陵王居』

LONG);
	setup();
	replace_program(ROOM);
}
