inherit ROOM;
void create() {
	set( "short", "$HIW$白色山脈$NOR$" );
	set( "light_up", 1 );
	set( "object", ([
		"amount7"  : 1,
		"file2"    : "/open/magic-manor/obj/master_snake_head",
		"file6"    : "/open/magic-manor/obj/master_snake_head",
		"file10"   : "/open/ghost-hole/obj/eq/ghost-leggings",
		"amount10" : 1,
		"amount5"  : 1,
		"file5"    : "/open/ghost-hole/obj/eq/ghost-gloves",
		"amount8"  : 1,
		"file1"    : "/open/magic-manor/obj/master_snake_head",
		"file8"    : "/open/ghost-hole/obj/eq/ghost-gloves",
		"amount2"  : 1,
		"file7"    : "/open/magic-manor/water/obj/water-ribbon",
		"amount4"  : 1,
		"amount6"  : 1,
		"file4"    : "/open/ghost-hole/obj/eq/ghost-ring",
		"amount1"  : 1,
	]) );
	set( "build", 10744 );
	set( "exits", ([
		"south"     : "/open/clan/dark-forest/room/room9.c",
		"eastup"    : "/open/clan/dark-forest/room/room12",
		"north"     : "/open/clan/dark-forest/room/hall.c",
	]) );
	set( "long", @LONG
矗立在眼前的是一座巨大的樹城，茂密的枝葉讓光線幾乎
無法透過，抬頭仰望可以看到無數由樹枝組成的平台，偶而還
能看到精靈們在上面走動，頂端則被無止境的深綠色掩蓋，當
中參雜著一些白色或金黃色的葉子。

  $HIM$精靈護衛$NOR$ 米爾汀(Myrddin)
  $HIG$精靈護衛$NOR$ 慕爾嘉(Muirgen)
LONG);
	setup();
	replace_program(ROOM);
}
