//ggpill by smirk
//增加基礎單位base_unit來修正表達單位的錯誤 by blazakira 2011/4/3

#include "/open/open.h"
#include <ansi.h>

inherit COMBINED_ITEM;

void create()
{
  set_name("精精丸",({"pill"}));
  set("long","這是一顆鮮豔朱紅色的藥丸,看來真有些神奇功\效。\n");
  set("unit","顆");
  set("base_unit", "顆");
  set("value",100);
  set("base_weight",150);
  set_amount(1);
  setup();
}

void init()
{
  if( this_player()==environment() )
    add_action("swallow_pill","swallow");
}

int swallow_pill(string arg)
{
  if( arg=="ggpill" || arg=="pill")
  {
    int max1,now1,max2,now2,sen1;
    object ob;
    ob=this_player();
    message_vision("$N看了看藥丸,決定試試這顆所謂的靈丹是否真的神奇。\n",ob);
    message_vision("xxxx\n",ob); //不加ob..system會強迫所傳回的 0 值
    tell_object( ob ,"你感到全身發燙,一股興奮的感覺令你有如身在雲端。\n");
    tell_object( ob ,HIB + "你感到氣力增加了.......\n" + NOR);
    tell_object( ob ,HIG + "你感到精力變強了.......^_^\n" + NOR);
    max1=ob->query("max_gin");
    max2=ob->query("max_kee");
    sen1 = ob->query("sen");
    if( sen1 > 20 )
    {
      ob->set("sen",20);
      ob->add("gin",random(30));
      ob->add("kee",random(5));
    }
    else
    {
      ob->set("sen",sen1);
      ob->add("gin",random(15));
      ob->add("kee",random(5));
    }
    now1 = ob->query("gin");
    if( now1 > max1 )
    {
      ob->set("gin",max1);
      now1 = max1;
    }
    now2 = ob->query("kee");
    if( now2 > max2 )
    {
      ob->set("kee",max2);
      now2 = max2;
    }
    add_amount(-1);
    return 1;
  }
  return 0;
}  
