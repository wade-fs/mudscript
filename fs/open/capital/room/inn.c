// inn.c

#include "/open/capital/capital.h"

inherit ROOM;

string look_sign(object me);

void create ()
{
  set ("short", "悅來客棧");
  set ("long", @LONG
你現在京城南邊的悅來客棧裡﹐這家客棧是方圓五百里內最負盛名
的一家﹐客棧的主人乾通天在城內擁有許多的產業，據說連朝廷命官都
對他禮遇有加﹐如果你想在此地找他的碴話，那得先算算你的腦袋有幾
顆了。
    來自各地的旅人都喜歡聚集在這裡交換旅途上的見聞﹐你也可以在
裡打聽到許多有趣的消息。樓上是貴賓席，通常是給有錢有勢的大爺們
坐的。靠近門口的地方掛著一塊烏木雕成的招牌(sign)。

LONG);

  set("item_desc", ([ /* sizeof() == 1 */
  "sign" : (: look_sign :),
]));
  set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"h15",
]));
  set("objects", ([ /* sizeof() == 1 */
  "/open/capital/npc/waiter2" : 1,
]));

  setup();
}

string look_sign(object me)
{
		return "招牌寫著﹕悅來客棧。旁邊一排字﹕乾通天題。\n";
}
