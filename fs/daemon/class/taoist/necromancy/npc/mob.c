//增加失去控制時的set_temp("apply/name")表達式 by blazakira 2011/9/26

#include <ansi.h>
#include <combat.h>
inherit NPC;

int limit = 15*60 ; // 差不多 18 分鐘左右

void create()
{
  set_name("殭屍",({ "vampire"}));
  set("combat_exp",10);
  set("age",100);
  set("no_learn",1);
  setup();
}

void init()
{
  add_action("do_order","order");
  ::init();
}

void greeting(object ob)
{
  object master,env;
  master = this_object()->query("master");
  env = environment();
  if(env->query("no_kill") || env->query("no_fight") )
    return ;
  if(master)
  {
    if( query_temp("apply/name") ) delete_temp("apply/name");
    if(environment(master) == environment(this_object())) return ;
    if(this_object()->is_fighting()) return ;
    if(!userp(ob)) return ;
  }
  // 這邊需要一個控制不住的訊息！
  message_vision(HIR"因為主人不在身邊，殭屍無法被控制，就開始攻擊附近的人。\n"NOR,this_object(),ob);
  set_temp("apply/name",({"(失去控制)"+query("name")}));
  this_object()->kill_ob(ob);
}

void heart_beat()
{
  object me=this_object();
  if(limit-- < 0)
  {
    message_vision(HIB"$N"HIB"快速腐爛了緊接著一陣風吹過，屍體就化成骨灰吹散了。\n"NOR,this_object());
    destruct(this_object());
    return ;
  }
  ::heart_beat();
}

int return_notify(string arg)
{
  write(arg);
  return 1;
}
// 殭屍是不會回血的
int heal_up()
{
  return 1;
}

int do_order(string arg)
{
  object mob;
  string id,command;
  object me = this_player();
  if(me->query("class") != "taoist")
    return 0;
  if(!arg || sscanf(arg,"%s to %s",id,command) != 2)
    return return_notify("請用 order id to command\n"); 
  if(!mob = present(id,environment(me)))
    return return_notify("這裡沒有這個殭屍！\n");
  if(mob->query("master") != me)
    return return_notify("你不是他的主人，你不能操控他！\n"); 

  if(me->is_fighting())
    me->start_busy(1);
  message_vision("$N拿著符，操控$n執行:"+command+"\n",me,mob);

  seteuid(ROOT_UID);

  switch(mob->find_command(explode(command," ")[0]))
  {
    case "/cmds/std/save":
    case "/cmds/std/team":
    case "/cmds/std/quit":
      tell_object(me,"他不能執行這個指令。\n");
      return 1;
      break;
    case "/cmds/std/kill":
    case "/cmds/std/fight":
      me->do_command(command);
      break;
    default:
  }
  if(!mob->force_me(command)) {
    mob->do_command(command);
  }
//  command(arg);
  return 1;
}

void die()
{
  message_vision("$N整個被打到魂飛迫散！\n",this_object());
  destruct(this_object());
}
