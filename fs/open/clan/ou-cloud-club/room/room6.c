// Room : /open/clan/ou-cloud-club/room/room6.c
 inherit "/open/clan/claneqshop.c";

void create()
{
        seteuid(getuid());
	set( "long", @LONG
這裡是山莊的eq房，牆壁上掛滿了許多武器跟防具，仔細一瞧
，啊!!這不是任正晴的$HIY$狂龍翔天破$NOR$，劉全書的$HIC$金鋼指環$NOR$，鄭士欣的
$HIR$連陽劍$NOR$，段雲的$HIC$飄雲扇$NOR$‧‧‧等人的傲世兵器，天ㄚ！竟然連焚天
魔王的$HIR$極火裝備$NOR$、獨孤嵊的$HIB$魔龍裝備$NOR$都有！原來這裡是讓幫眾們在
外面打來的戰利品存放的地方，除了炫耀本莊的威名外，一方面也
為了讓新進幫眾有好的武器可為本幫效力。
(想知道使用方法請look eq room)

LONG);
	set( "objects", ([ /* sizeof() == 1 */
  "/open/clan/ou-cloud-club/npc/npc4" : 1,
]) );
	set( "short", "$HIY$傲$NOR$武$HIC$雲$NOR$防$HIR$地$NOR$" );
	set( "object", ([
		"amount8"  : 1,
		"file6"    : "/open/magic-manor/wood/obj/wood-sword",
		"amount3"  : 1,
		"amount1"  : 1,
		"amount7"  : 1,
		"file3"    : "/open/magic-manor/wood/obj/wood-sword",
		"file8"    : "/open/magic-manor/wood/obj/wood-sword",
		"amount10" : 1,
		"amount2"  : 1,
		"file5"    : "/open/magic-manor/wood/obj/wood-sword",
		"file7"    : "/open/magic-manor/wood/obj/wood-sword",
		"amount5"  : 1,
		"file10"   : "/open/fire-hole/obj/universe_book",
		"file1"    : "/open/magic-manor/wood/obj/wood-sword",
		"file2"    : "/open/magic-manor/wood/obj/wood-sword",
		"file9"    : "/open/magic-manor/wood/obj/wood-sword",
		"amount9"  : 1,
		"amount4"  : 1,
		"file4"    : "/open/magic-manor/wood/obj/wood-sword",
		"amount6"  : 1,
	]) );
	set( "build", 17840 );
	set( "cmkroom", 1 );
	set( "clan_room", "傲雲山莊" );
	set( "have_reborn", 1 );
	set( "no_clean_up", 1 );
	set( "item_desc", ([ /* sizeof() == 1 */
  "eq room" : "  在此eq室，你可以用 list 武器種類 來知道有什麼你想要的武器，
用 list 防具種類 來知道有什麼你想要的護具，
用 list another  來知道有什麼你想要的雜物，
用 take + 物品名   來取得你想要的物品，
用 put  + 物品名   來存放你不要的物品 .
",
]) );
	set( "exits", ([ /* sizeof() == 1 */
		"west"      : "/open/clan/ou-cloud-club/room/hall.c",
		"up"        : "/open/clan/ou-cloud-club/room/room117",
]) );
	set( "no_transmit", 1 );
	set( "eqroom", 1 );
	set( "light_up", 1 );
	setup();

	}
