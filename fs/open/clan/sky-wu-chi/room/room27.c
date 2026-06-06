// Room : /open/clan/sky-wu-chi/room/room27.c
 inherit ROOM;

void create()
{
        seteuid(getuid());
	set( "long", @LONG

當你一進入我想上的房間，不禁慾火焚身，開始想要起來了，真是奇怪，
平時都起不來，現在變成這樣。就好像我都踢了你一下你怎麼可能還站的起來。

其不傳絕學小宇宙拳三式『星　雲　風　暴』『鑽  石  巨  拳』『鳳  翼  天  翔』
及最終式「天  馬  流  星  拳」為其無敵絕學。

其最強養身心法《性情心法》之春宮養眼功 『鳥絕功』更是令人聞風喪膽。

但是我想上成天心事重重不知怎麼了。
或許只有你可以結束我想上心中的寂寞。

LONG);
	set( "exits", ([ /* sizeof() == 1 */
		"up"        : "/open/clan/sky-wu-chi/room/room194",
		"out"       : "/open/clan/sky-wu-chi/room/room15.c",
]) );
	set( "short", "【我想上的房間裡頭】" );
	set( "owner", "cong" );
	set( "object", ([
		"file6"    : "/open/magic-manor/soil/obj/soil-claw",
		"file1"    : "/open/capital/obj/gold_pill",
		"amount6"  : 1,
		"file2"    : "/open/gsword/obj/silver_sword",
		"amount7"  : 1,
		"file7"    : "/open/magic-manor/soil/obj/soil-claw",
		"amount1"  : 1,
		"amount5"  : 1,
		"amount3"  : 15,
		"file9"    : "/open/magic-manor/soil/obj/soil-claw",
		"file8"    : "/open/magic-manor/soil/obj/soil-claw",
		"file10"   : "/open/magic-manor/soil/obj/soil-claw",
		"file3"    : "/open/fire-hole/obj/p-pill",
		"amount9"  : 1,
		"amount8"  : 1,
		"amount10" : 1,
		"file5"    : "/open/magic-manor/soil/obj/soil-claw",
		"amount2"  : 1,
		"file4"    : "/open/fire-hole/obj/y-pill",
		"amount4"  : 80,
	]) );
	set( "light_up", 1 );
	set( "build", 10187 );
	set( "no_clean_up", 0 );
	set( "clan_room", "天道無極" );
	set( "no_transmit", 1 );
	set( "cmkroom", 1 );
	setup();

	}
