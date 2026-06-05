//--by falcon
//2002-12-28修改 --by frequency & kalin 
//2003-01-25新增穿齊全套後的附加功能 --by frequency
//排版 與增加物件存在與否的判斷 by blazakira 2011/10/24

inherit ITEM;
#include <ansi.h>
#include <mudlib.h>
#include <command.h>

object me;

void create()
{
  set_name(MAG + "ω" + CYN + "" + BBLU + "冥魔寶盒" + NOR + "" + MAG + "ω" + NOR,({"ghost-box"}));
  set("long",HIW + "死冥骨魔的戰甲(pray ghost) (explode) (summary)。\n" + NOR);
  set("unit","座");  
  set("no_auc",1);
  set("no_sell",1);
  set("no_put",1);
  set("no_give",1);
  set("no_drop",1);
  set("no_get",1);
  set("no_steal",1);
  set("no_save",1);
  setup();
}

void init() 
{
  me=environment();
  add_action("do_pray","pray");
  add_action("do_summary","summary");
  add_action("do_explode","explode");
  return;
}

int do_pray(string str) 
{
  object room,eq01,eq02,eq03,eq04,eq05,eq06,eq07,eq08,eq09,eq10,eq11,eq12;
  string name;

  if(!str||sscanf(str, "%s",name)!=1)
    return 0;
  if(name != "ghost")
    return 0;
  if(me->query_temp("pray_ghost"))
  {
    message_vision(HIW + "$N的冥魔戰甲已分解完畢。\n" + NOR,me);
    return 1;
  }
  message_vision (HIW + "$N讓自己的意識墮入黑暗深淵，誠心祈求邪靈庇護，" + CYN + "" + BBLU + "冥魔戰甲" + NOR + "" + HIW + "由盒中緩緩浮升。\n" + NOR,me);
  room=environment(me);
  eq01 = new("/open/ghost-hole/obj/eq/ghost-save-cloak");
  eq02 = new("/open/ghost-hole/obj/eq/ghost-save-armband");
  eq03 = new("/open/ghost-hole/obj/eq/ghost-save-boots");
  eq04 = new("/open/ghost-hole/obj/eq/ghost-save-armor");
  eq05 = new("/open/ghost-hole/obj/eq/ghost-save-gem");
  eq06 = new("/open/ghost-hole/obj/eq/ghost-save-gloves");
  eq07 = new("/open/ghost-hole/obj/eq/ghost-save-helmet");
  eq08 = new("/open/ghost-hole/obj/eq/ghost-save-leggings");
  eq09 = new("/open/ghost-hole/obj/eq/ghost-save-pants");
  eq10 = new("/open/ghost-hole/obj/eq/ghost-save-ring");
  eq11 = new("/open/ghost-hole/obj/eq/ghost-save-shield");
  eq12 = new("/open/ghost-hole/obj/eq/ghost-save-belt");
  eq01->move(me);
  eq02->move(me);
  eq03->move(me);
  eq04->move(me);
  eq05->move(me);
  eq06->move(me);
  eq07->move(me);
  eq08->move(me);
  eq09->move(me);
  eq10->move(me);
  eq11->move(me);
  eq12->move(me);
  //destruct(this_object());
  me->set_temp("pray_ghost",1);
  return 1;
}

int do_summary()
{
  if(!me->query_temp("pray_ghost"))
    return notify_fail("你並沒有開啟冥魔戰甲。\n");
  if(me->query_temp("ghost_explode"))
  {
    return notify_fail("請先將戰甲脫下來吧。\n");
  } else {
//    object ob01,ob02,ob03,ob04,ob05,ob06,ob07,ob08,ob09,ob10,ob11,ob12;
    message_vision (HIW + "$N以堅強鬥心召回邪靈陰魄，將" + CYN + "" + BBLU + "冥魔戰甲" + NOR + "" + HIW + "重新封印於盒中。\n" + NOR,me);
    if( present("ghost-cloak",me) ) destruct(present("ghost-cloak",me));
    if( present("ghost-armband",me) ) destruct(present("ghost-armband",me));
    if( present("ghost-boots",me) ) destruct(present("ghost-boots",me));
    if( present("ghost-armor",me) ) destruct(present("ghost-armor",me));
    if( present("ghost-gem",me) ) destruct(present("ghost-gem",me));
    if( present("ghost-gloves",me) ) destruct(present("ghost-gloves",me));
    if( present("ghost-helmet",me) ) destruct(present("ghost-helmet",me));
    if( present("ghost-leggings",me) ) destruct(present("ghost-leggings",me));
    if( present("ghost-pants",me) ) destruct(present("ghost-pants",me));
    if( present("ghost-ring",me) ) destruct(present("ghost-ring",me));
    if( present("ghost-shield",me) ) destruct(present("ghost-shield",me));
    if( present("ghost-belt",me) ) destruct(present("ghost-belt",me));
/*
    ob01 = present("ghost-cloak",me);
    ob02 = present("ghost-armband",me);
    ob03 = present("ghost-boots",me);
    ob04 = present("ghost-armor",me);
    ob05 = present("ghost-gem",me);
    ob06 = present("ghost-gloves",me);
    ob07 = present("ghost-helmet",me);
    ob08 = present("ghost-leggings",me);
    ob09 = present("ghost-pants",me);
    ob10 = present("ghost-ring",me);
    ob11 = present("ghost-shield",me);
    ob12 = present("ghost-belt",me);
    destruct(ob01);
    destruct(ob02);
    destruct(ob03);
    destruct(ob04);
    destruct(ob05);
    destruct(ob06);
    destruct(ob07);
    destruct(ob08);
    destruct(ob09);
    destruct(ob10);
    destruct(ob11);
    destruct(ob12);
*/
    me->delete_temp("pray_ghost");
    return 1;
  }
}

int do_explode()
{
  object o01,o02,o03,o04,o05,o06,o07,o08,o09,o10,o11,o12;
  if(!me->query_temp("pray_ghost")) return notify_fail("你還沒穿上冥魔戰甲呢。\n");
  o01 = present("ghost-cloak",me);
  o02 = present("ghost-armband",me);
  o03 = present("ghost-boots",me);
  o04 = present("ghost-armor",me);
  o05 = present("ghost-gem",me);
  o06 = present("ghost-gloves",me);
  o07 = present("ghost-helmet",me);
  o08 = present("ghost-leggings",me);
  o09 = present("ghost-pants",me);
  o10 = present("ghost-ring",me);
  o11 = present("ghost-shield",me);
  o12 = present("ghost-belt",me);
  if( o01 && o02 && o03 && o04 && o05 && o06 && o07 && o08 && o09 && o10 && o11 && o12
      && o01->query("equipped") && o02->query("equipped") && o03->query("equipped") && o04->query("equipped")
      && o05->query("equipped") && o06->query("equipped") && o07->query("equipped") && o08->query("equipped")
      && o09->query("equipped") && o10->query("equipped") && o11->query("equipped") && o12->query("equipped"))
  {
    if(me->query_temp("ghost_explode",1))
    {
      return notify_fail("你已經在用嘍。\n");
    }
    message_vision(HIM + "\n$N全力爆發冥魔戰甲的頂級力量，只見戰甲各部分均釋出無限妖力，注入$N體內。\n" + NOR,me);
    set_heart_beat(1);
    me->set_temp("ghost_explode",1);
    if(me->query("class")=="fighter") //fighter的功能
    {
      me->set("force_factor",100);
    } else                            //other class
    {
      me->set("eff_kee",(me->query("max_kee"))*3/2);
      me->set("max_kee",(me->query("max_kee"))*3/2);
    }
    return 1;
  } else { return notify_fail("不穿齊全套冥魔戰甲無法迫發頂級威力。\n"); }
}

void heart_beat()
{
  object v01,v02,v03,v04,v05,v06,v07,v08,v09,v10,v11,v12;
  v01 = present("ghost-cloak",me);
  v02 = present("ghost-armband",me);
  v03 = present("ghost-boots",me);
  v04 = present("ghost-armor",me);
  v05 = present("ghost-gem",me);
  v06 = present("ghost-gloves",me);
  v07 = present("ghost-helmet",me);
  v08 = present("ghost-leggings",me);
  v09 = present("ghost-pants",me);
  v10 = present("ghost-ring",me);
  v11 = present("ghost-shield",me);
  v12 = present("ghost-belt",me);
  if( v01->query("equipped") && v02->query("equipped") && v03->query("equipped") && v04->query("equipped")
      && v05->query("equipped") && v06->query("equipped") && v07->query("equipped") && v08->query("equipped")
      && v09->query("equipped") && v10->query("equipped") && v11->query("equipped") && v12->query("equipped"))
  {
    if(random(100)<20)
    {
      message_vision(HIB + "\n$N週身環繞著妖異的" + HIM + "紫" + HIR + "炎" + HIY + "鬥氣" + HIB + "，滾滾翻騰。\n" + NOR,me);
    }
    if(me->query("class")=="fighter")
    {
      if(me->query("force") < (me->query("max_force"))*5)
      {
        me->set("force",(me->query("max_force"))*5);
      }
    } else {
      if(me->query("force") < (me->query("max_force"))*3)
      {
        me->set("force",(me->query("max_force"))*3);
      }
    }
  } else {
    me->delete_temp("ghost_explode");
    if(me->query("class")=="fighter")
    {
      me->set("force_factor",10);
    } else {
      me->set("max_kee",(me->query("max_kee"))*2/3);
      me->set("eff_kee",me->query("max_kee"));
      if(me->query("kee") > me->query("max_kee"))
      {
        me->set("kee",me->query("max_kee"));
      }
    }
    set_heart_beat(0);
  }
}

int query_autoload()
{
  return 1;
}
