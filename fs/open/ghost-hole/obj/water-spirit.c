//改進持有者的判斷 且receive_wound增加傷害者為本物品的參數 by blazakira 2011/8/4

inherit ITEM;
#include <ansi.h>

void create()
{
  set_name(HIB + "共工水之魂" + NOR,({"water-spirit"}));
  set("long","若有似無，藍色半透明的魂靈物體，夾帶著一股攝人心魄的神秘力\n"
    +"量，恍如所有生命的物體的精華正逐漸的被吸蝕著，連你也無法例\n"
    +"外正被它逐漸的侵蝕著。\n");
  set("unit","個");
  set("value",100000);
  set("spirit",1);
  set("no_sac",1);
  set("no_give",1);
  set_weight(1000);
  setup();
}

void init()
{
  object ob=this_object();
  set_heart_beat(1);
  if( environment(ob) && !ob->query("callout") )
  {
    call_out("hurt",1,ob);
    ob->set("callout",1);
  }
}

int hurt()
{
  object ob,me,ob1,ob2;
  ob=this_object();
  me=environment(ob);
  if( !ob || !me ) return 1;
  ob1=present("water-emblem",me);
  ob2=present("water-spirit",me);

  if( ob2 && userp(me) && !me->is_busy() )
  {
    if( ob1 )
    {
      if( random(7) == 1 )
      {
        me->receive_wound("kee",80+random(150),ob);
        me->receive_wound("gin",50+random(130),ob);
        me->receive_wound("sen",50+random(130),ob);
        me->add("force",-30);
        message_vision("$n" + BLU + "緩緩散開一股藍色的氣霧，卻被"NOR+ob1->query("name")+BLU+"緩緩的吸收一部份！\n" + NOR,me,ob);
      }
    } else {
      if( random(2) == 1 )
      {
        me->receive_wound("kee",150+random(250),ob);
        me->receive_wound("gin",100+random(150),ob);
        me->receive_wound("sen",100+random(150),ob);
        me->add("force",-50);
        message_vision("$n" + BLU + "緩緩散開一股藍色的氣霧，慢慢的吸蝕著" + HIY + "$N"NOR+BLU"的全身精元！\n" + NOR,me,ob);
      }
    }
  }
  call_out("hurt",3,ob);
  return 1;
}
