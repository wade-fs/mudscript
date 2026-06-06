// Room: /u/g/guetenr/beggar/room/beg1/shop29.c
#include <room.h>
inherit SHOP;

void create ()
{
set ("short", "邱記雜舖店");
  set ("long", @LONG
略顯陳舊的店面連個招牌也無，僅在門首書小小『翁記』二字；進得門
來朝奉向你頷首致歡迎之意，撿了張椅坐下觀望，滿室金石古物令人嘖嘖稱
奇：上至商周鼎鼐河圖洛書，石雕青瓷漢玉寶塔，乃至歷代文墨典籍，無一
不有。一旁朝奉說起店史，算來至今已有百年光景，無怪乎收藏極豐。

             你可以打<list>來查看要買些什麼東西



LONG);

  set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"room24",
]));
  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/boss1.c" : 1,
]));

  setup();
}
