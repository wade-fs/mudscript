//改變使用者的判定為me = environment(this_object()) 與 wear形式為int wear() (參考殺意魔戒) by blazakira 2011/7/20
//避免玩家非正常途徑取得本物品 因此設限 by blazakira 2011/7/20

#include <ansi.h>
#include <armor.h>
inherit EQUIP;

void create()
{
  set_name(HBBLU+HIC + "幻彩靈戒" + NOR ,({ "color-ring" }));
  set_weight(2500);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("long","封印在天靈地界中的神奇戒指，裏面蘊含著四隻靈獸，盡其一切生命也要守護所擁有的主人。\n");
    set("unit", "件");
    set("value",500000);
    set("no_auc",1);
    set("no_sell",1);
    set("no_give",1);
    set("no_sec",1);
    set("no_put",1);
    set("no_drop",1);
    set("no_steal",1);
    set("no_save",1);
    set("no_get",1);
    set("material","gold");
    set("armor_type","finger2");
    set("armor_prop/armor",7);
    set("wear_msg","");
    set("unequip_msg","");
  }
  setup();
}

void init()
{
  object ob,user;
  ob = this_object();
  user=environment();
  if( !ob || !user ) return;
  if( !ob->query("boss") ) ob->set("boss",user->query("id"));
}

int wear()
{
  object me;
  int result = ::wear();
  if( query("equipped"))
  {
    me=environment();
    message_vision(HIW + "$N戴上了$n" + HIW + "，四道靈光由戒指中隱隱透出光茫！！\n" + NOR,me,this_object());
    set_heart_beat(1);
  }
  return result;
}

int unequip()
{
  object me=environment();
  int result = ::unequip();
  if( !query("equipped") )
  {
    message_vision(HIW + "$N御下了$n" + HIW + "，四道靈光由戒指中漸漸消散！！\n" + NOR,me,this_object());
    set_heart_beat(0);
  }
  return result;
}

void heart_beat()
{
  object mob,me,user;
  int i,j;
  user=environment();
  me=environment(user);
  if( !this_object() || !user || !objectp(user) )
  {
    set_heart_beat(0);
    return;
  }

  i=random(100);
  if( user->is_fighting() && query("equipped") )
  {
    if(user->query("allring"))
    {
      if( !user->query_temp("have_guard") && !present("fire guard",me) && !present("dragon guard",me) && !present("butterfly guard",me) && !present("phoenix guard",me) )
      {
        mob=new("/open/sky/guard/phoenix");
        mob->set("title",user->query("name")+"的守護靈獸");
        mob->set("combat_exp",user->query("combat_exp"));
        mob->move(environment(user));
        mob->invocation(user);
        mob=new("/open/sky/guard/butterfly");
        mob->set("title",user->query("name")+"的守護靈獸");
        mob->set("combat_exp",user->query("combat_exp"));
        mob->move(environment(user));
        mob->invocation(user);
        mob=new("/open/sky/guard/dragon");
        mob->set("title",user->query("name")+"的守護靈獸");
        mob->set("combat_exp",user->query("combat_exp"));
        mob->move(environment(user));
        mob->invocation(user);
        mob=new("/open/sky/guard/fire");
        mob->set("title",user->query("name")+"的守護靈獸");
        mob->set("combat_exp",user->query("combat_exp"));
        mob->move(environment(user));
        mob->invocation(user);
      }
    } else {
      if( !user->query_temp("have_guard") && !present("fire guard",me) && !present("dragon guard",me) && !present("butterfly guard",me) && !present("phoenix guard",me) )
      {
        if( i > 20 || i == 20)
        {
          switch(random(4))
          {
            case 0:
              mob=new("/open/sky/guard/phoenix");
              mob->set("title",user->query("name")+"的守護靈獸");
              mob->set("combat_exp",user->query("combat_exp"));
              mob->move(environment(user));
              mob->invocation(user);
              break;
            case 1:
              mob=new("/open/sky/guard/butterfly");
              mob->set("title",user->query("name")+"的守護靈獸");
              mob->set("combat_exp",user->query("combat_exp"));
              mob->move(environment(user));
              mob->invocation(user);
              break;
            case 2:
              mob=new("/open/sky/guard/dragon");
              mob->set("title",user->query("name")+"的守護靈獸");
              mob->set("combat_exp",user->query("combat_exp"));
              mob->move(environment(user));
              mob->invocation(user);
              break;
            case 3:
              mob=new("/open/sky/guard/fire");
              mob->set("title",user->query("name")+"的守護靈獸");
              mob->set("combat_exp",user->query("combat_exp"));
              mob->move(environment(user));
              mob->invocation(user);
              break;
          }
        }
        else if( i < 20 && i > 5 || i == 5)
        {
          switch(random(6))
          {
            case 0:
              mob=new("/open/sky/guard/phoenix");
              mob->set("title",user->query("name")+"的守護靈獸");
              mob->set("combat_exp",user->query("combat_exp"));
              mob->move(environment(user));
              mob->invocation(user);
              mob=new("/open/sky/guard/butterfly");
              mob->set("title",user->query("name")+"的守護靈獸");
              mob->set("combat_exp",user->query("combat_exp"));
              mob->move(environment(user));
              mob->invocation(user);
              break;
            case 1:
              mob=new("/open/sky/guard/phoenix");
              mob->set("title",user->query("name")+"的守護靈獸");
              mob->set("combat_exp",user->query("combat_exp"));
              mob->move(environment(user));
              mob->invocation(user);
              mob=new("/open/sky/guard/dragon");
              mob->set("title",user->query("name")+"的守護靈獸");
              mob->set("combat_exp",user->query("combat_exp"));
              mob->move(environment(user));
              mob->invocation(user);
              break;
            case 2:
              mob=new("/open/sky/guard/phoenix");
              mob->set("title",user->query("name")+"的守護靈獸");
              mob->set("combat_exp",user->query("combat_exp"));
              mob->move(environment(user));
              mob->invocation(user);
              mob=new("/open/sky/guard/fire");
              mob->set("title",user->query("name")+"的守護靈獸");
              mob->set("combat_exp",user->query("combat_exp"));
              mob->move(environment(user));
              mob->invocation(user);
              break;
            case 3:
              mob=new("/open/sky/guard/butterfly");
              mob->set("title",user->query("name")+"的守護靈獸");
              mob->set("combat_exp",user->query("combat_exp"));
              mob->move(environment(user));
              mob->invocation(user);
              mob=new("/open/sky/guard/dragon");
              mob->set("title",user->query("name")+"的守護靈獸");
              mob->set("combat_exp",user->query("combat_exp"));
              mob->move(environment(user));
              mob->invocation(user);
              break;
            case 4:
              mob=new("/open/sky/guard/butterfly");
              mob->set("title",user->query("name")+"的守護靈獸");
              mob->set("combat_exp",user->query("combat_exp"));
              mob->move(environment(user));
              mob->invocation(user);
              mob=new("/open/sky/guard/fire");
              mob->set("title",user->query("name")+"的守護靈獸");
              mob->set("combat_exp",user->query("combat_exp"));
              mob->move(environment(user));
              mob->invocation(user);
              break;
            case 5:
              mob=new("/open/sky/guard/dragon");
              mob->set("title",user->query("name")+"的守護靈獸");
              mob->set("combat_exp",user->query("combat_exp"));
              mob->move(environment(user));
              mob->invocation(user);
              mob=new("/open/sky/guard/fire");
              mob->set("title",user->query("name")+"的守護靈獸");
              mob->set("combat_exp",user->query("combat_exp"));
              mob->move(environment(user));
              mob->invocation(user);
              break;
          }
        }
        else if( i < 6 && i > 1 || i == 1 )
        {
          switch(random(4))
          {
            case 0:
              mob=new("/open/sky/guard/phoenix");
              mob->set("title",user->query("name")+"的守護靈獸");
              mob->set("combat_exp",user->query("combat_exp"));
              mob->move(environment(user));
              mob->invocation(user);
              mob=new("/open/sky/guard/fire");
              mob->set("title",user->query("name")+"的守護靈獸");
              mob->set("combat_exp",user->query("combat_exp"));
              mob->move(environment(user));
              mob->invocation(user);
              mob=new("/open/sky/guard/butterfly");
              mob->set("title",user->query("name")+"的守護靈獸");
              mob->set("combat_exp",user->query("combat_exp"));
              mob->move(environment(user));
              mob->invocation(user);
              break;
            case 1:
              mob=new("/open/sky/guard/phoenix");
              mob->set("title",user->query("name")+"的守護靈獸");
              mob->set("combat_exp",user->query("combat_exp"));
              mob->move(environment(user));
              mob->invocation(user);
              mob=new("/open/sky/guard/fire");
              mob->set("title",user->query("name")+"的守護靈獸");
              mob->set("combat_exp",user->query("combat_exp"));
              mob->move(environment(user));
              mob->invocation(user);
              mob=new("/open/sky/guard/dragon");
              mob->set("title",user->query("name")+"的守護靈獸");
              mob->set("combat_exp",user->query("combat_exp"));
              mob->move(environment(user));
              mob->invocation(user);
              break;
            case 2:
              mob=new("/open/sky/guard/phoenix");
              mob->set("title",user->query("name")+"的守護靈獸");
              mob->set("combat_exp",user->query("combat_exp"));
              mob->move(environment(user));
              mob->invocation(user);
              mob=new("/open/sky/guard/dragon");
              mob->set("title",user->query("name")+"的守護靈獸");
              mob->set("combat_exp",user->query("combat_exp"));
              mob->move(environment(user));
              mob->invocation(user);
              mob=new("/open/sky/guard/butterfly");
              mob->set("title",user->query("name")+"的守護靈獸");
              mob->set("combat_exp",user->query("combat_exp"));
              mob->move(environment(user));
              mob->invocation(user);
              break;
            case 3:
              mob=new("/open/sky/guard/butterfly");
              mob->set("title",user->query("name")+"的守護靈獸");
              mob->set("combat_exp",user->query("combat_exp"));
              mob->move(environment(user));
              mob->invocation(user);
              mob=new("/open/sky/guard/dragon");
              mob->set("title",user->query("name")+"的守護靈獸");
              mob->set("combat_exp",user->query("combat_exp"));
              mob->move(environment(user));
              mob->invocation(user);
              mob=new("/open/sky/guard/fire");
              mob->set("title",user->query("name")+"的守護靈獸");
              mob->set("combat_exp",user->query("combat_exp"));
              mob->move(environment(user));
              mob->invocation(user);
              break;
          }
        }
        else if( i== 0 )
        {
          mob=new("/open/sky/guard/phoenix");
          mob->set("title",user->query("name")+"的守護靈獸");
          mob->set("combat_exp",user->query("combat_exp"));
          mob->move(environment(user));
          mob->invocation(user);
          mob=new("/open/sky/guard/butterfly");
          mob->set("title",user->query("name")+"的守護靈獸");
          mob->set("combat_exp",user->query("combat_exp"));
          mob->move(environment(user));
          mob->invocation(user);
          mob=new("/open/sky/guard/dragon");
          mob->set("title",user->query("name")+"的守護靈獸");
          mob->set("combat_exp",user->query("combat_exp"));
          mob->move(environment(user));
          mob->invocation(user);
          mob=new("/open/sky/guard/fire");
          mob->set("title",user->query("name")+"的守護靈獸");
          mob->set("combat_exp",user->query("combat_exp"));
          mob->move(environment(user));
          mob->invocation(user);
        }
      }
    }
  }
  return;
}

int query_autoload()
{
  return 0;
}
