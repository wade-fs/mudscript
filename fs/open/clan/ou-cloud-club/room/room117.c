// Room : /open/clan/ou-cloud-club/room/room117.c
 inherit ROOM;

void create()
{
        seteuid(getuid());
	set( "long", @LONG

這裡是專門放置傲雲山莊人員專用的FORCE EQ，EQ列表如下：

   ( $HIY$1$NOR$) $HIR$夕霞紅紗$NOR$(sun_red_cloth)
   ( $HIY$2$NOR$) $HIC$魔法盾$NOR$(magic shield)
   ( $HIY$3$NOR$) $HIY$妖幻披掮$NOR$(ghost cloak)
   ( $HIY$4$NOR$) $HIY$妖幻頭帶$NOR$(ghost helmet)
   ( $HIY$5$NOR$) $HIY$狂龍翔天破$NOR$(crazy dragon)
   ( $HIY$6$NOR$) $HIY$神龍金環$NOR$(Dragon gold armband)
   ( $HIY$7$NOR$) $HIY$妖幻護膝$NOR$(ghost legging)
   ( $HIY$8$NOR$) $HIG$混沌腰帶$NOR$(chaos belt)
   ( $HIY$9$NOR$) $HIC$羅剎女飾$NOR$(gem)
   ($HIY$10$NOR$) $HIY$幸運草環$NOR$(lucky grasslink)

LONG);
	set( "no_clean_up", 0 );
	set( "light_up", 1 );
	set( "short", "FORCE EQ ROOM" );
	set( "owner", "eleven" );
	set( "object", ([
		"amount8"  : 1,
		"file9"    : "/open/mon/obj/ghost-helmet",
		"amount5"  : 1,
		"file6"    : "/open/tendo/obj/chaosbelt",
		"amount2"  : 1,
		"amount6"  : 1,
		"amount3"  : 1,
		"amount9"  : 1,
		"file4"    : "/open/wind-rain/obj/sun_red_cloth",
		"file2"    : "/open/mon/obj/ghost-cloak",
		"file3"    : "/open/sky/obj/lucky_grasslink",
		"amount1"  : 1,
		"amount10" : 1,
		"file8"    : "/open/mogi/castle/obj/lochagem",
		"amount4"  : 1,
		"file7"    : "/open/wu/obj/figring",
		"amount7"  : 1,
		"file5"    : "/daemon/class/blademan/obj/shield",
		"file1"    : "/open/mon/obj/ghost-legging",
		"file10"   : "/open/wu/npc/obj/armband",
	]) );
	set( "exits", ([
		"down"      : "/open/clan/ou-cloud-club/room/room6",
	]) );
	set( "build", 10416 );
	set( "cmkroom", 1 );
	set( "clan_room", "傲雲山莊" );
	set( "no_transmit", 1 );
	setup();

	}
