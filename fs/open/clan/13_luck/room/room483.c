inherit ROOM;
void create() {
	set( "short", "彩釉拱橋" );
	set( "object", ([
		"amount4"  : 1,
		"file9"    : "/open/magic-manor/obj/sun-heart",
		"amount3"  : 1,
		"amount1"  : 627,
		"amount5"  : 1,
		"amount10" : 1,
		"file7"    : "/open/ping/obj/poison_pill",
		"file6"    : "/open/ping/obj/poison_pill",
		"file4"    : "/open/ghost-hole/obj/eq/ghost-belt",
		"amount2"  : 1,
		"amount7"  : 525,
		"file10"   : "/open/magic-manor/obj/sun-heart",
		"amount6"  : 663,
		"amount9"  : 1,
		"file5"    : "/open/mogi/dragon/obj/dragon-head",
		"file8"    : "/open/magic-manor/obj/sun-heart",
		"amount8"  : 1,
		"file2"    : "/open/ghost-hole/obj/eq/ghost-armor",
		"file1"    : "/open/ping/obj/poison_pill",
		"file3"    : "/open/ghost-hole/obj/eq/ghost-cloak",
	]) );
	set( "owner", "zmud" );
	set( "build", 10009 );
	set( "light_up", 1 );
	set( "exits", ([
		"north"     : "/open/clan/13_luck/room/room482.c",
		"east"      : "/open/clan/13_luck/room/room678.c",
	]) );
	set( "long", @LONG


    亮眼的彩釉拱橋，即是城內外的通道之一。邑陽城現址原是古華陽
大澤，幾番的滄海桑田，而今呈現於世的是座繁華熱鬧的城府。來到這
邊，可看見橋墩前豎立著一塊大石，石上刻記著橋的來由(story)。 而
過了橋就是邑陽城的中心廣場囉！

LONG);
	setup();
	replace_program(ROOM);
}
