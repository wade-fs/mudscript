// Room : /open/clan/ou-cloud-club/room/room17.c
 inherit ROOM;

void create()
{
        seteuid(getuid());
	set( "long", @LONG

紫雲蝶的房間，房內擺著十二把劍，定睛一看不正是劍君
十二恨初出江湖的佩劍嗎？原來已經埋劍於此受有劍魔之稱的
紫雲蝶所保護，聽聞此人極崇拜劍君，所以自願代為保管．
近年來劍魔紫雲蝶已經逐漸退出江湖，為的是進一步提昇本身
之劍術達到手中無劍，心中有劍之劍道最高境界。

LONG);
	set( "no_transmit", 1 );
	set( "no_clean_up", 0 );
	set( "clan_room", "傲雲山莊" );
	set( "cmkroom", 1 );
	set( "short", "$HIY$魔劍塚$NOR$" );
	set( "owner", "mekyn" );
	set( "object", ([
		"file5"    : "/obj/gift/bingtang",
		"amount7"  : 1,
		"amount6"  : 1,
		"amount3"  : 1,
		"file3"    : "/obj/gift/unknowdan",
		"amount5"  : 1,
		"amount2"  : 1,
		"file8"    : "/open/capital/obj/4-4",
		"file4"    : "/obj/gift/xiandan",
		"file7"    : "/open/magic-manor/obj/sun-heart",
		"amount10" : 1,
		"file9"    : "/open/gsword/obj1/sball",
		"amount4"  : 1,
		"file2"    : "/open/magic-manor/obj/sun-heart",
		"amount9"  : 1,
		"file10"   : "/open/gsword/obj1/sadsword",
		"file1"    : "/obj/gift/unknowdan",
		"file6"    : "/open/magic-manor/obj/lunar-heart",
		"amount1"  : 1,
		"amount8"  : 1,
	]) );
	set( "build", 10501 );
	set( "exits", ([ /* sizeof() == 1 */
		"west"      : "/open/clan/ou-cloud-club/room/room199",
		"east"      : "/open/clan/ou-cloud-club/room/room15.c",
]) );
	set( "light_up", 1 );
	setup();

	}
