inherit ROOM;
void create() {
	set( "short", "血痕居-大號叫地獄" );
	set( "owner", "holeman" );
	set( "object", ([
		"amount6"  : 1,
		"amount5"  : 1,
		"amount3"  : 1,
		"amount9"  : 1,
		"amount10" : 1,
		"file4"    : "/open/ghost-hole/obj/eq/ghost-gem",
		"file9"    : "/open/magic-manor/obj/master_snake_head",
		"file2"    : "/open/ghost-hole/obj/eq/ghost-armband",
		"amount2"  : 1,
		"file5"    : "/open/ghost-hole/obj/eq/ghost-belt",
		"file10"   : "/open/magic-manor/obj/master_snake_head",
		"file3"    : "/open/ghost-hole/obj/eq/ghost-king-tooth",
		"amount4"  : 1,
		"file1"    : "/open/ghost-hole/obj/eq/ghost-boots",
		"amount1"  : 1,
		"file6"    : "/open/ghost-hole/obj/eq/ghost-shield",
	]) );
	set( "build", 11663 );
	set( "exits", ([
		"southeast" : "/open/clan/sky-wu-chi/room/room528",
		"east"      : "/open/clan/sky-wu-chi/room/room529.c",
		"south"     : "/open/clan/sky-wu-chi/room/room530",
	]) );
	set( "long", @LONG

    閻羅的獄卒把墮入這裏的眾生抓起來，放在門內、門外有雙重
炙熱鐵門的鐵屋中。在這裡他們無法得到解脫，而且受的痛苦比號
號叫地獄多一倍，還要受獄卒用棒杵搗打，因此他們都大聲號叫，
所以叫做大號叫地獄。

    這個地獄眾生的壽命是：人間八百年是樂化天的一天，樂化天
的八千年是大號叫地獄的一天，他們要在此受苦八千年。


LONG);
	setup();
	replace_program(ROOM);
}
