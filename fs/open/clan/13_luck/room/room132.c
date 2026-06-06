inherit ROOM;
void create() {
	set( "short", "黃土揚" );
	set( "owner", "mill" );
	set( "object", ([
		"file6"    : "/open/mogi/dragon/obj/scale",
		"amount2"  : 50,
		"file5"    : "/open/mogi/dragon/obj/scale",
		"amount6"  : 1,
		"amount5"  : 1,
		"amount4"  : 1,
		"file2"    : "/open/ping/obj/poison_pill",
		"amount3"  : 60,
		"file4"    : "/open/mogi/dragon/obj/scale",
		"file3"    : "/open/fire-hole/obj/w-pill",
	]) );
	set( "build", 10066 );
	set( "light_up", 1 );
	set( "exits", ([
		"west"      : "/open/clan/13_luck/room/room254",
		"east"      : "/open/clan/13_luck/room/room134.c",
	]) );
	set( "long", @LONG

    這裡遍地黃土，還不時傳來陣陣強風，在一瞇眼的順間眼前升起了一
道狂爆龍捲風，心裡正想著不妙快逃時，卻發現風中似乎有道黑影，這不
就是那個十三幫主，眼看著他在風中似東似西的飄忽不定，好似一道影子
閃爍，果然有如世人所說一般這個人深具  狂      ，      影 。

LONG);
	setup();
	replace_program(ROOM);
}
