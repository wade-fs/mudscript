// Room : /open/clan/demon_castle/room/room2.c
 inherit "/open/clan/claneqshop.c";

void create()
{
        seteuid(getuid());
	set( "short", "魔˙裝備室" );
	set( "light_up", 1 );
	set( "no_clean_up", 0 );
	set( "exits", ([ /* sizeof() == 1 */
  "east" : "/open/clan/demon_castle/room/hall",
]) );
	set( "no_transmit", 1 );
	set( "long", @LONG

    走進此間石室，數道耀眼的光茫閃爍不定，原來此地便是收藏著
惡魔城主要武器裝備的EQ室，只見武器櫃上擺滿了許多稀世利器，無
論是劍、刀、棍、暗器、可謂是十八般武器樣樣齊全，可見幫主初創
惡魔城時亦花費了許多心血在於武器裝備的收集，難怪惡魔城能獨霸
天下，屹立不搖。
(想知道使用方法請look eq room)


LONG);
set( "item_desc", ([ /* sizeof() == 1 */
  "eq room" : "  在此eq室，你可以用 list 武器種類 來知道有什麼你想要的武器，
用 list 防具種類 來知道有什麼你想要的護具，
用 list another  來知道有什麼你想要的雜物，
用 take + 物品名   來取得你想要的物品，
用 put  + 物品名   來存放你不要的物品 .
",
]) );
set( "objects", ([ /* sizeof() == 1 */
  "/open/clan/demon_castle/npc/npc4" : 1,
]) );
	set( "clan_room", "傲雲山莊" );
	set( "no_transmit", 1 );
	set( "eqroom", 1 );
	setup();

	}
