// Et-sword.c by Casey
//由於會因為戰功eq增加的天賦而造成系統溢位，所以強化裝備時的判斷 by blazakira 2011/6/22

#include <weapon.h>
#include <ansi.h>
inherit SWORD;

void create()
{
  set_name(HIB"連鞘古劍"NOR,({"old sword","sword"}) );
  set_weight(5000);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("long","\n這是一柄連鞘的古劍，古樸的劍鞘中閃爍著異樣的寒光。\n");
    set("unit", "把");
    set("sharp",1);
    set("value",100000);
    set("no_steal",1);
    set("no_save", 1);
    set("no_sell",1);
    set("no_put",1);
    set("material","cloth");
    set("rigidity",200);
  }
  init_sword(110);
  setup();
}

void init()
{
  add_action("do_wield","wield");
  add_action("do_unwield","drop");
  add_action("do_unwield","auc");
  add_action("do_unwield","give");
  add_action("do_unwield","unwield");
}

int do_wield(string str)
{
  int my_spi,my_exp;
  object user = environment(this_object());

  if( str=="all" || str=="sword" || str=="old sword" && !query_temp("changed") || str=="et-sword" && query_temp("changed")==1 ) {
    ::wield();
    if( query("equipped") )
    {
      my_spi = user->query_spi(1);
      my_exp = user->query("combat_exp");
      if( my_exp > 1000000 ) my_exp = 1000000;
      // 表示神兵利器 ,所以提高條件...Daniel
      if( my_exp * my_spi < 10000000 )
      {
        message_vision("$N的靈性與經驗，並不足以使用此劍。\n",user);
        set_temp("changed",0);
      }else{
        message_vision(HIW"鞘中之劍感受到$N"HIW"的靈性，隨著一道青光灑然揚出，原來正是聞名天下的"HIC"倚天劍"HIW"。\n"NOR,user);
        set_name(HIC"倚天劍"NOR,({"et-sword","sword"}) );
        set("long","\n倚天劍傳聞是以寒湖玄鐵打製，其鋒芒足可分金斷玉，在武林與屠龍刀並列。\n");
        set_temp("changed",1);
      }
    }
  }
}

int do_unwield(string str)
{
  object user = environment(this_object());
  if( str=="all" || str=="sword" || str=="et-sword")
    if( query("equipped") )
    {
      message_vision("$N輕輕巧巧的把劍收回腰際。\n",user);
      set("long","\n這是一柄連鞘的古劍，古樸的劍鞘中閃爍著異樣的寒光。\n");
      set_name(HIB"連鞘古劍"NOR,({"old sword","sword"}) );
      set_temp("changed",0);
    }
}
/*
int do_drop(string str)
{
  object user = environment(this_object());
  if( str=="all" || str=="sword" || str=="et-sword")
    if( query("equipped") )
    {    
      message_vision("$N輕輕巧巧的把劍收回腰際。\n",user);
      set_name(HIB"連鞘古劍"NOR,({"old sword","sword"}) );
      set("long","\n這是一柄連鞘的古劍，古樸的劍鞘中閃爍著異樣的寒光。\n");
      set_temp("changed",0);
    }
}

int do_give(string str)
{
  object user = environment(this_object());
  if( str=="all" || str=="sword" || str=="et-sword")
    if( query("equipped") )
    {  
      message_vision("$N輕輕巧巧的把劍收回腰際。\n",user);
      set_name(HIB"連鞘古劍"NOR,({"old sword","sword"}) );
      set("long","\n這是一柄連鞘的古劍，古樸的劍鞘中閃爍著異樣的寒光。\n");
      set_temp("changed",0);
    }
}

int do_auc(string str)
{
  object user = environment(this_object());
  if( str=="all" || str=="sword" || str=="et-sword")
    if( query("equipped") )
    {
      message_vision("$N輕輕巧巧的把劍收回腰際。\n",user);
      set_name(HIB"連鞘古劍"NOR,({"old sword","sword"}) );
      set("long","\n這是一柄連鞘的古劍，古樸的劍鞘中閃爍著異樣的寒光。\n");
      set_temp("changed",0);
    }
}
*/
