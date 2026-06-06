// Room : /open/clan/ou-cloud-club/room/room45.c
 inherit ROOM;

void create()
{
        seteuid(getuid());
	set( "short", "神秘實驗室" );
	set( "owner", "snowy" );
	set( "object", ([
		"amount10" : 1,
		"amount4"  : 1,
		"file3"    : "/open/magic-manor/obj/sun-heart",
		"amount9"  : 1,
		"amount5"  : 1,
		"amount6"  : 1,
		"file4"    : "/open/magic-manor/obj/lunar-heart",
		"file6"    : "/open/magic-manor/obj/sun-heart",
		"file2"    : "/open/magic-manor/obj/lunar-heart",
		"file10"   : "/open/magic-manor/obj/sun-heart",
		"amount2"  : 1,
		"file9"    : "/open/magic-manor/obj/lunar-heart",
		"file5"    : "/open/magic-manor/obj/lunar-heart",
		"file1"    : "/open/magic-manor/obj/sun-heart",
		"amount3"  : 1,
		"amount1"  : 1,
	]) );
	set( "build", 10009 );
	set( "light_up", 1 );
	set( "no_clean_up", 0 );
	set( "exits", ([ /* sizeof() == 2 */
  "west" : "/open/clan/ou-cloud-club/room/room3",
  "east" : "/open/clan/ou-cloud-club/room/room43",
]) );
	set( "clan_room", "傲雲山莊" );
	set( "long", @LONG
天花板滴著幾許未知的液體,你突然想試著了解它的成分,
但隨即想到德古拉伯爵的殘暴血腥,或許這些東西是腐屍的屍水
或著是用來凌遲受害者的毒液,還是少碰為妙吧!!不過,這裡終
歸是個實驗室,觸手可及的,就是瓶瓶罐罐的各種化學試樣,還有
許多不知名的金屬材料,這就是典型煉金術的基本配備吧!?
LONG);
	set( "no_transmit", 1 );
	set( "cmkroom", 1 );
	setup();

	}
