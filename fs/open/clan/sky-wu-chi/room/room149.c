inherit ROOM;
void create() {
	set( "short", "粉紅水晶結界" );
	set( "owner", "sski" );
	set( "outdoors", "/open/clan/sky-wu-chi" );
	set( "object", ([
		"file3"    : "/open/killer/obj/kill_yar_head",
		"amount2"  : 1,
		"file6"    : "/open/mon/obj/ghost-claw",
		"file8"    : "/open/mon/obj/ghost-legging",
		"amount5"  : 1,
		"file5"    : "/open/mon/obj/ghost-helmet",
		"amount3"  : 1,
		"file10"   : "/open/mon/obj/ghost-cloak",
		"file1"    : "/open/fire-hole/obj/g-pill",
		"amount10" : 1,
		"file9"    : "/open/gblade/obj/sa-head",
		"amount6"  : 1,
		"amount1"  : 11,
		"file2"    : "/open/mon/obj/ghost-legging",
		"amount8"  : 1,
		"amount9"  : 1,
	]) );
	set( "light_up", 1 );
	set( "build", 12000 );
	set( "exits", ([
		"north"     : "/open/clan/sky-wu-chi/room/room50.c",
		"west"      : "/open/clan/sky-wu-chi/room/room147.c",
		"south"     : "/open/clan/sky-wu-chi/room/room166.c",
		"east"      : "/open/clan/sky-wu-chi/room/room150.c",
	]) );
        set( "long", @LONG此地初建, 空無一物。
你走進來這裡,發現你的眼前突然有一股光照射著你這股光隨著
你的越走越近,也越來越強的照耀著....突然間你發現了你的頭頂出
現一顆有如太陽般大的水晶正照射著你...突然間你發現你在粉紅的
光線的照射之下,你的體力漸漸被無形的力量來把你給抽離你想要逃
但卻逃不出他對你的吞噬
LONG);
        setup();
        replace_program(ROOM);
}

