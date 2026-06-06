inherit ROOM;
void create() {
	set( "short", "小志的房間" );
	set( "owner", "panhermes" );
	set( "object", ([
		"file4"    : "/open/mon/obj/ghost-cloak",
		"file3"    : "/open/mon/obj/ghost-legging",
		"amount2"  : 1,
		"amount4"  : 1,
		"amount8"  : 6,
		"amount7"  : 4,
		"file2"    : "/obj/gift/shenliwan",
		"file7"    : "/obj/stone/suipian",
		"file8"    : "/obj/stone/powder",
		"amount3"  : 1,
	]) );
	set( "build", 10026 );
	set( "exits", ([
		"east"      : "/open/clan/sky-wu-chi/room/room357",
		"north"     : "/open/clan/sky-wu-chi/room/room210.c",
		"up"        : "/open/clan/sky-wu-chi/room/room175.c",
		"chome"     : "/open/clan/sky-wu-chi/room/hall.c",
	]) );
	set( "light_up", 1 );
	set( "long", @LONG
      此處到處佈滿了劍氣，在地上充滿了劍痕，好像有
  人在這修練了很久的樣子，仔細一看原來是天道無極的
             「劍落飄楓」小志專屬區域
  在地上有一塊石碑上面寫著：
        非請勿入者...只有一條路  
                 『死』
              *^_^*..小志..

LONG);
	setup();
	replace_program(ROOM);
}
