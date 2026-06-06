// Room : /open/clan/sky-wu-chi/room/room84.c
 inherit ROOM;

void create()
{
        seteuid(getuid());
	set( "clan_room", "天道無極" );
	set( "short", "通道後段" );
	set( "owner", "herozero" );
	set( "light_up", 1 );
	set( "object", ([
		"amount2"  : 10,
		"amount3"  : 23,
		"amount6"  : 3,
		"amount4"  : 25,
		"file4"    : "/open/fire-hole/obj/y-pill",
		"file3"    : "/open/fire-hole/obj/g-pill",
		"file9"    : "/open/fire-hole/obj/r-pill",
		"amount7"  : 1,
		"amount1"  : 1,
		"amount9"  : 19,
		"amount8"  : 1,
		"file2"    : "/open/fire-hole/obj/b-pill",
		"file10"   : "/open/fire-hole/obj/p-pill",
		"amount5"  : 1,
		"amount10" : 4,
		"file6"    : "/open/fire-hole/obj/k-pill",
		"file5"    : "/open/scholar/obj/icefan",
		"file1"    : "/daemon/class/blademan/obj/shield",
		"file7"    : "/open/magic-manor/soil/obj/soil-claw",
		"file8"    : "/open/mogi/castle/obj/lochagem",
	]) );
	set( "build", 10240 );
	set( "long", @LONG
筆直的通道，一直通往盡頭的馬房，四周沒有任何物品 
地上卻鋪著高級的地毯。在你通過了通道前段後你便比較不
害怕這個通道了。似乎感覺它變得親切了許多，這下你不禁
膽大了起來，開始用手去摸摸通道的牆壁，看看是不是有什
麼暗門之類的會讓你發現。

LONG);
	set( "no_transmit", 1 );
	set( "no_clean_up", 0 );
	set( "exits", ([ /* sizeof() == 2 */
  "south" : "/open/clan/sky-wu-chi/room/room79",
  "north" : "/open/clan/sky-wu-chi/room/room88.c",
]) );
	set( "cmkroom", 1 );
	setup();

	}
