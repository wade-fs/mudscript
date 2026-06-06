// spirit_blade_v1.c
#include <ansi.h>
inherit ITEM;

void create()
{
  set_name(HIB + "神農氏靈魂珠" + NOR, ({ "ball of shen nongshi spirit","ball","shen nongshi spirit" }) );
  set_weight(100);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("unit", "顆");
    set("long", "這是存有神農靈魂的神秘珠子，充滿著浩瀚且強大的神力。\n");
    set("value",100000000);
    set("no_auc",1);
    set("no_sell",1);
    set("no_give",1);
    set("no_sec",1);
    set("no_put",1);
//    set("no_drop",1); //可以丟 但是得重打:p
    set("no_steal",1);
    set("no_save",1);
    set("no_get",1);
  }
  setup();
}

void init()
{
  add_action("do_give","gi");
  add_action("do_give","giv");
  add_action("do_give","give");
}

int do_give(string arg)
{
  string target,item;
  object who,ob=this_object(),me=environment(ob);
  if(!arg)
    return 0;
  if( sscanf(arg,"%s to %s",item,target)==2 || //保留這個判斷是為了指定target參數的存在
      sscanf(arg,"%s %s",target,item)==2 ); //需保留此分號 否則會與下方衝突
  else return notify_fail("你要給誰什麼東西﹖\n");
  if(!objectp(who = present(target,environment(me))) || !living(who)) //使用這個判斷是為了確定與目標同一間房間
    return notify_fail("這裡沒有這個人。\n");
  if(item==query("id") && who->query("id")=="master tor")
  {
    set("no_give",0); //關閉本物件的no_give 以便於在下方的return 0中 接著使用原指令give的判斷跟動作==交給對方
  }
  return 0;
}

int query_autoload()
{
  return 1;
}
