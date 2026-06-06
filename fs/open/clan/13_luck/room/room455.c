inherit ROOM;
void create() {
	set( "short", "『大愛亭』" );
	set( "owner", "poll" );
	set( "object", ([
		"amount3"  : 1,
		"file5"    : "/open/magic-manor/fire/obj/fire-fan",
		"file3"    : "/open/magic-manor/fire/obj/fire-fan",
		"amount8"  : 1,
		"file2"    : "/open/magic-manor/gold/obj/golden-blade",
		"amount5"  : 1,
		"amount6"  : 1,
		"amount7"  : 1,
		"file1"    : "/open/magic-manor/wood/obj/wood-sword",
		"amount4"  : 1,
		"amount2"  : 1,
		"file7"    : "/open/magic-manor/gold/obj/golden-blade",
		"file4"    : "/open/magic-manor/wood/obj/wood-sword",
		"file6"    : "/open/magic-manor/fire/obj/fire-fan",
		"file8"    : "/open/magic-manor/wood/obj/wood-sword",
		"amount1"  : 1,
	]) );
	set( "build", 10106 );
	set( "light_up", 1 );
	set( "exits", ([
		"north"     : "/open/clan/13_luck/room/room456",
		"south"     : "/open/clan/13_luck/room/room454",
	]) );
	set( "long", @LONG
  
     你這時候來到了一處涼亭，上面寫著「大愛亭」，而眼前所看到的盡是
 一些雲海，還有很多的松柏，身在其境讓你的心神為之一振，跟前面的路真
 是有天壤之別，在這裡你可以看到太陽從雲海禮貌出來的情景，此景在墨教
 中是為人所津津樂道的。

LONG);
	setup();
	replace_program(ROOM);
}
