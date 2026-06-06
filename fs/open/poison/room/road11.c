// Room: /open/poison/room/road11
#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", "牌樓");
  set ("long", @LONG
眼前有一七間的高大牌樓，其氣勢非凡，牌樓上有一雕
刻精美的匾額(tablet)，道路兩種滿了各式各樣的花草，北
邊有一向北高升的石梯。
LONG);

  set("item_desc",([ /* sizeof() == 1 */
  "tablet" : HIR"
	這是一塊古色古香的匾額，上面題道﹕

	    冥  蠱  魔  教  聖  地

"NOR,
]));

  set("outdoors", "/open/poison");

  set("exits", ([ /* sizeof() == 2 */
  "southeast" : "/open/poison/room/road10",
  "northup" : "/open/poison/room/road12",
]));

  setup();
}
