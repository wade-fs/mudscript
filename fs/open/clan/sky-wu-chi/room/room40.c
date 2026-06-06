// Room : /open/clan/sky-wu-chi/room/room40.c
 inherit ROOM;

void create()
{
        seteuid(getuid());
	set( "light_up", 1 );
	set( "clan_room", "天道無極" );
	set( "long", @LONG
這裡又是一個天道無極的偉大建築物之一
「通天閣」其外觀真有如其名一樣，頂端直入
雲梢，眼不見頂，目不見其高，想要爬到最高
點，恐怕需要花費一些時間。不過這到也是個
觀賞風景的好地方。在這棟樓的下方，有個指
示牌(sign)，是否能對世事的感慨能有更深一
層的見解呢。

LONG);
	set( "short", "通天閣" );
	set( "owner", "conpse" );
	set( "object", ([
		"amount1"  : 1,
		"file3"    : "/daemon/class/blademan/obj/six-neck",
		"file6"    : "/open/mon/obj/ghost-helmet",
		"amount3"  : 1,
		"amount6"  : 1,
		"amount2"  : 1,
		"amount7"  : 1,
		"file1"    : "/open/sky/obj/lucky_grasslink",
		"file9"    : "/open/magic-manor/obj/dark-soul-dagger",
		"file8"    : "/open/magic-manor/obj/evil-gwe-blade",
		"amount9"  : 1,
		"file4"    : "/open/magic-manor/obj/evil-gwe-blade",
		"amount10" : 1,
		"file2"    : "/daemon/class/blademan/obj/skykey",
		"file7"    : "/open/mon/obj/ghost-legging",
		"amount4"  : 1,
		"file10"   : "/open/magic-manor/obj/dark-soul-dagger",
		"amount8"  : 1,
	]) );
	set( "build", 10004 );
	set( "exits", ([
		"chome"     : "/open/clan/sky-wu-chi/room/hall",
		"up"        : "/open/clan/sky-wu-chi/room/room52.c",
	]) );
	set( "no_transmit", 1 );
	set( "no_clean_up", 0 );
	set( "item_desc", ([ /* sizeof() == 1 */
  "sign" : "
有些層樓有設窗子(window)，看能不能看到些什麼。

",
]) );
	set( "cmkroom", 1 );
	setup();

	}
