// ~babe~(小雪球)^O^
//目前暫不開放幫派 因此關閉npc 幫派戰爭區域主持人 by blazakira 2011/7/9

#include <room.h>
#include <ansi.h>
inherit ROOM;

void create ()
{
  set( "short", HIW + "【" + HIY + "幫派" + HIW + "】【" + HIC + "討論廣場" + HIW + "】" + NOR );
  set( "build", 111 );
  set( "long", "
    這個小小的圓形廣場是狂想空間玩家抒發他們對幫派看法的地方。在廣
場上飄浮著一塊" + HIC + "玄天冰晶" + NOR + "(" + HIC + "Mysterious crystal" + NOR + ")，這塊耀眼的冰晶浮現出許\
多玩家的言論，還有幫派總管[babe]所發佈的消息，在廣場中央還有一座小
小的發言台，有任何意見，都可以登上發言台演講，babe對於玩家發言的權
力是相當民主的，你不用擔心自己的言論會招惹麻煩，而在廣場的旁邊，則
是放置了一座" + HIW + "金鋼石" + NOR + "(" + HIW + "Ｄiamond" + NOR + ")雕成的幫派資料和幫派律法規章等等文件。
" + HIG + "
	c_cmds		幫派指令集
	c_index		幫派文件索引
	c_list		幫派總覽
" + NOR + "
	Email: kjheng@gmail.com
");

  set("item_desc", ([ /* sizeof() == 2 */
  "diamond" : "

	c_cmds		幫派指令集
	c_index		幫派文件索引
	c_list		幫派總覽

						by ACKY 03/09/00
",
]));
  set("exits", ([ /* sizeof() == 1 */
    "down" : "/open/common/room/inn",
]));
  set("no_lyssa",1);
  set("light_up", 1);  
  set("no_kill", 1);
  set("no_transmit", 1);
  set("no_chome", 1);
  set("no_fight", 1);
  set("objects", ([ /* sizeof() == 1 */
    "/u/a/acky/npc/babe"  : 1,
//    "/open/clan/area/war/war_officer" : 1,
  ]));
  setup();
  call_other("/obj/board/clan_b","???");
}
