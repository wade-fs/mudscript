// Room : /open/clan/ou-cloud-club/room/room22.c
 inherit ROOM;

void create()
{
        seteuid(getuid());
	set( "long", @LONG
通往惡魔城的道路，是傲雲山莊內的主要道路，兩
邊的牆壁是以$HIC$玄離冰$NOR$打造而成的，不時透發出一股清透
涼意，火把更是以火龍幻境內的$HIR$火龍膽$NOR$點燃，據說可以
永不熄滅．而地板則是使用無堅不摧的金剛石所鋪設而
成，一眼望去光芒萬千．

LONG);
	set( "short", "傲雲道" );
	set( "object", ([
		"file1"    : "/open/capital/obj/icer",
		"amount5"  : 1,
		"file10"   : "/open/magic-manor/obj/hwa-je-icer",
		"amount2"  : 1,
		"file5"    : "/open/gsword/obj1/bbladeball",
		"amount1"  : 1,
		"amount9"  : 1,
		"file6"    : "/open/gsword/obj1/bbladeball",
		"amount8"  : 1,
		"file9"    : "/open/gsword/obj1/bbladeball",
		"amount6"  : 1,
		"amount7"  : 1,
		"file2"    : "/open/magic-manor/obj/hwa-je-icer",
		"amount10" : 1,
		"file8"    : "/open/gsword/obj1/bbladeball",
		"file7"    : "/open/magic-manor/obj/hwa-je-icer",
	]) );
	set( "build", 10026 );
	set( "light_up", 1 );
	set( "item_desc", ([
		"兵營" : @ITEM
傲雲莊內的兵營．
ITEM,
	]) );
set( "exits", ([         
		"up"        : "/open/clan/ou-cloud-club/room/room24",
		"south"     : "/open/clan/ou-cloud-club/room/room21.c",
	]) );

	}
