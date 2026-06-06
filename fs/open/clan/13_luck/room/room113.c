inherit ROOM;
void create() {
	set( "short", "小志的家" );
	set( "owner", "roar" );
	set( "object", ([
		"amount3"  : 1,
		"file7"    : "/open/ping/obj/gold_hand",
		"amount7"  : 1,
		"file3"    : "/daemon/class/bonze/puty_pullium",
		"file4"    : "/open/ping/obj/cloud",
		"file8"    : "/open/port/obj/wolf_ring",
		"amount4"  : 1,
		"amount2"  : 1,
		"file2"    : "/open/ping/obj/chilin_legging",
		"file9"    : "/open/magic-manor/obj/master_snake_head",
		"amount8"  : 1,
		"amount5"  : 1,
		"file5"    : "/open/wu/npc/obj/armband",
		"amount9"  : 1,
	]) );
	set( "build", 12169 );
	set( "light_up", 1 );
	set( "exits", ([
		"east"      : "/open/clan/13_luck/room/room94",
		"enter"     : "/open/clan/13_luck/room/room147",
	]) );
	set( "long", @LONG

    此處到處佈滿了劍氣，在地上充滿了劍痕，好像有
人在這修練了很久的樣子，仔細一看原來是十三吉祥的
           「劍落飄楓」小志專屬區域
在地上有一塊石碑上面寫著：
      非請勿入者...只有一條路  
               『死』
            *^_^*..小志..

LONG);
	setup();
	replace_program(ROOM);
}
