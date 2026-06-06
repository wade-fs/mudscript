#include "/open/open.h"
#include <ansi.h>
inherit ROOM;

void create ()
{
set("short", "葉秀殺的臥室");
	set( "build", 25 );
set("long", @LONG
   此處乃葉秀殺的專屬臥室，一般時候可不是隨便可以進來的。
   房間中，並沒有特別的裝飾品，只不過有幾盆花與字畫（word)。
   除此之外，大概也只有一旁的書櫃比較顯眼一點罷了。

LONG 
);
  set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"masterm.c",
]) );
  set("item_desc", ([ /* sizeof() == 2 */
  "word":"一張平凡的字畫，不過倒是令你注意到一旁的（花盆）\n",
  "sign":"按照它握了一下發現可以轉動(turn),你是否該考慮(think)，以免誤觸陷阱\n",
]));
  set("search_desc", ([ /* sizeof() == 1 */
  "花盆" : "好像沒什麼特別的，但卻有人的指印（sign)。\n",
  "mark" : "你調查暗扣之後，你按住暗扣，決定轉（turn)了\n",
]));
  set("objects",([
  "/open/killer/npc/spy3.c":1,]));
  setup();
}
void init()
{
	add_action("do_think","think");
	add_action("do_turn","turn");
}

int do_think(string str)
{
  object me;
  
  me=this_player();
  message_vision("根據經驗你決定，還是仔細觀察一下，果然發現握柄處有暗扣（mark)\n",me);
  me->set_temp("diray",2);
  return 1;
}

int do_turn(string str)
{
	object me=this_player();
        
  if( str != "花盆" )
    return notify_fail("轉什麼？需要配附眼鏡嗎？？\n");
  if(me->query_temp("diray") != 2)
  {
    message_vision("不小心觸動機關，一支花針射中$N。\n",me);
    me->add("kee",-30);
    return 0;
   }
  if(me->query_temp("diray") == 2)
  {
    message_vision(HIG"隨著花盆的轉動，字畫捲了起來，密門打開。\n",me);
    message_vision("出現了一本葉秀殺的日記，正好翻到某一頁\n",me);
    message_vision("內容『唉。。。真是不小心，居然因為殺意魔戒放出太多殺氣\n",me);
    message_vision("對招中，使因在密道中躲避不及的柴榮受了傷。\n",me);
    message_vision("可惡，把它封印在（專用兵器室）好了，希望外甥不要說出去\n",me);
    message_vision("不過兵器室的鑰匙，好像上次掉在一樓了，都找不到。。。\n",me);
    message_vision("正當你想在看下去時，發現外面似乎有人來了，於是急忙退了出去\n\n"NOR,me);
    me->set_temp("diray",1);
    me->move(__DIR__"masterm.c");
    return 1;
  }
}
