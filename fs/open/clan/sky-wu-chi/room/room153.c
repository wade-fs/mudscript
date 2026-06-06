inherit ROOM;
void create() {
	set( "short", "shield" );
	set( "owner", "hild" );
	set( "object", ([
		"amount4"  : 1,
		"amount3"  : 1,
		"amount5"  : 1,
		"file7"    : "/open/ghost-hole/obj/eq/ghost-shield",
		"file9"    : "/open/ghost-hole/obj/eq/ghost-shield",
		"amount6"  : 1,
		"amount2"  : 1,
		"file4"    : "/open/ghost-hole/obj/eq/ghost-shield",
		"file3"    : "/open/ghost-hole/obj/eq/ghost-shield",
		"amount7"  : 1,
		"amount9"  : 1,
		"file5"    : "/open/ghost-hole/obj/eq/ghost-shield",
		"file2"    : "/open/ghost-hole/obj/eq/ghost-shield",
		"amount10" : 1,
		"file6"    : "/open/ghost-hole/obj/eq/ghost-shield",
		"file10"   : "/open/ghost-hole/obj/eq/ghost-shield",
	]) );
	set( "exits", ([
		"east"      : "/open/clan/sky-wu-chi/room/room49.c",
		"west"      : "/open/clan/sky-wu-chi/room/room269",
	]) );
	set( "build", 10059 );
	set( "light_up", 1 );
	set( "long", @LONG
剛步入此間，只見到房內竟然光線朦朦朧朧的，隱隱
約約之中，彷彿見到一個身材窈窕的女子，其站在房間的
中央翩翩起舞，只見在其舞動之間，其身旁瞬時出現陣陣
火光及閃雷，令人懼怕，又見此女子舞動愈漸激烈，四週
突然出現無數幻影，令人不敢輕易接近此間。
LONG);
	setup();
	replace_program(ROOM);
}
