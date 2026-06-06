inherit ROOM;
void create() {
	set( "short", "神秘芭樂園" );
	set( "owner", "bladewind" );
	set( "object", ([
		"amount6"  : 419,
		"amount3"  : 256,
		"amount4"  : 36,
		"amount5"  : 427,
		"amount2"  : 11,
		"file4"    : "/open/fire-hole/obj/b-pill",
		"file5"    : "/open/fire-hole/obj/g-pill",
		"file3"    : "/open/fire-hole/obj/w-pill",
		"file6"    : "/open/mon/obj/mon-pill",
		"amount8"  : 46,
		"amount7"  : 371,
		"file2"    : "/open/fire-hole/obj/y-pill",
		"amount1"  : 16,
		"file7"    : "/open/fire-hole/obj/r-pill",
		"file8"    : "/open/mogi/castle/obj/ninepill",
		"file1"    : "/open/fire-hole/obj/k-pill",
	]) );
	set( "light_up", 1 );
	set( "build", 10887 );
	set( "exits", ([
		"east"      : "/open/clan/ou-cloud-club/room/room150",
	]) );
	set( "long", @LONG
這裡是小雯埋一些難得的寶物的地方,外表看起來是一般的芭樂園實際
尚在地下有小雯四處蒐集來的寶物,只有在火焰鴨和小雯要去挑戰焚天
魔王的時候才有可能用到,此處受到非常嚴密的看守,若是沒有火焰鴨
和小雯的允許,還是快離開吧.

LONG);
	setup();
	replace_program(ROOM);
}
