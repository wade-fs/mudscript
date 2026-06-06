#include <ansi.h>
inherit ITEM;

void create()
{
  set_name(YEL"古老捲軸"NOR, ({ "oldnote" }) );
  set("long", "一張陳舊羊毛紙，上面寫著奇奇怪怪的未知符號，看來是上個文明紀元的產物。\n");
  set("value",1234);
  set("no_sec",1);
  set("no_auc",1);
  set("no_sell",1);
  set("no_drop",1);
  set("no_put",1);
  set("no_get",1);
  setup();
}

void init()
{
        add_action("do_read","read");
}

int do_read(string arg)
{
       object me = this_player();
       if(arg == "oldnote")
       {
         tell_object(me,"你完全無法理解紙上到底在說些什麼東西，看來得找個古文學家來幫你翻譯\n");
       }
}

