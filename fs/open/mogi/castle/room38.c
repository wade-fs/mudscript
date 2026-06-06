//將do_damage補上玩家是否存在（離線？）的判斷 與改變傷害為receive_wound的形式 by blazakira 2011/5/4


inherit ROOM;
#include <ansi.h>
#include <mudlib.h>
#include <command.h>

void create ()
{
  set ("short","古堡三樓");
  set ("long","牆壁上點著青綠色的鬼火，仔細一看是由酷似骷髏\的銀器作成燈座，綠
光便由骷髏\的兩隻眼睛裡射出，豪華中透著恐怖的氣息。地上也鋪著厚
厚的地毯，令人不禁驚奇地東張西望。四周的妖魔似乎也都披金戴銀，
性情也溫和的多，但一身武藝看起來比樓下的是有過之而無不及，你不
禁懷疑自己真是在魔界？
");
  set("evil", 1);
  set("no_auc", 1);
  set("no_transmit", 1);
  set("light_up",-1);
  set("exits", ([
    "east"  : __DIR__"room39",
    "west" : __DIR__"room37",
  ]));
  setup();
}

void init()
{
  call_out("do_damage",1,this_player());
}

void do_damage(object ob)
{
  mixed all;
  object obj,who,room;
  int kee1,i,j;

  if(!ob) return;
  room = environment(ob);
  all = all_inventory(room);
  for( i = 0 ; i < sizeof(all) ; i++)
  {
    obj = all[i];
    kee1=obj->query("eff_kee");
    if( random(500) > obj->query_skill("parry")+obj->query_skill("dodge") ) {
      message_vision(HIR"嗤嗤聲響處，幾枚毒蒺菱快速射出，$N閃躲不及被毒蒺菱給射中！\n"NOR,obj);
//      obj->add("eff_kee",-kee1/30);
      obj->receive_wound("kee",(int)kee1/30,obj);
      obj->apply_condition("dark_poison",random(20));
    }
    else message_vision(HIW"嗤嗤聲響處，幾枚毒蒺菱快速射出，$N連忙竄高伏低，並揮手擊落射來的暗器\n"NOR,obj);
  }
}
