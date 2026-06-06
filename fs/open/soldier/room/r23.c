
#include "/open/open.h"
inherit ROOM;
void create()
{
  set ("short", "閒居");
  set ("long","
    聽說這裡就是這組織頭頭的住處了﹐不過怎麼沒看到
呢??在這裡絲毫感覺不到人和氣息﹐相當閒淡的樣子﹐在
右邊有個書桌(table),上面堆滿了一些唐詩﹐在書桌旁有
一個櫃子(cabinet),在地上好像還有移動過的痕跡。。。

 ");
   set("exits", ([
   "west"   : __DIR__"r24.c",
  ]));
  set("light_up", 1);
  set("item_desc", ([ /* sizeof() == 2 */
  "table" : "這桌子好像是用上等木頭彫刻出來的。\n",
  "cabinet" : "這桌子好像被動過你可以深入調查(search)看看。\n",
]));
  set("search_desc", ([ /* sizeof() == 3 */
  "table" : "在你努力不懈的情況下,你發現在桌底下有一圓盤(disc)....。\n",
  "cabinet" : "在你仔細調查後，你並沒發現任何線索。\n",
  "disc" : "你發現這個圓盤可以轉動(turn) :D\n",
]));

  setup();
}

void init()
{
       add_action("do_turn","turn");
}
int do_turn(string str)
{
  object me;

  me=this_player();
  if( str != "disc" )
    return notify_fail("你在轉啥??，不要亂轉好不好？\n");
  tell_room(this_object(),"$n用力的把圓盤往逆向轉了過去。。。\n",me);
  message_vision("突然桌子跟你一起迴轉，$n瞬間被甩進去一個房間了!!\n",me,me);
  me->move(__DIR__"r33.c");
  return 1;
}

