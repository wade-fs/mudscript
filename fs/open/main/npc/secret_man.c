//secret_vendor.c
//神秘小販...只賣替身
void do_patrol();
inherit NPC;
void create()
{
        set_name("神秘小販",({"vendor"}));
        set("gender", "男性" );
        set("age", 27);
set("long", @LONG
狂想傳說中的神秘小販,聽說他經營替身人偶(standby)的買賣,若你要的話可以打(want standby)跟他買!!!!
或是打(sell standby)把身上的替身人偶賣掉!!!!!

LONG
        );
        set("combat_exp",10000000);
        set("chat_chance",2000);
        set("chat_msg",({
            (: do_patrol :),
        }));
        set("attitude", "friendly");
        set("max_kee",7000);
        set("max_sen",6000);
        set("max_gin",5000);
        set("standby",99999);
        set_skill("dodge",500);
        set_skill("parry",500);
        set_skill("unarmed",500);
        set_skill("move",500);
        set_skill("force",500);
        set_skill("universe",500);
        set_skill("superforce",500);
        set_skill("ghost-steps",500);
        map_skill("unarmed", "universe");
        map_skill("parry","universe");
        map_skill("force", "superforce");
        map_skill("dodge", "ghost-steps");
        map_skill("move", "ghost-steps");
        setup();
}
void init()
{
  add_action("do_want","want");
  add_action("do_sell","sell");
  add_action("do_follow","follow");
  add_action("do_perform","perform");

}

/*

int do_want(string arg)
{
 object me,ob;
 me=this_player();
 if( arg!="standby")
  {
    write("你只能買替身(standby)!!\n");
    return 1;
  }
 if(me->query("bank/coin") < 2000000000)
  {
    write("你在錢莊的錢不夠,需要二十萬兩黃金!!\n");
    return 1;
  }
 else
  {
    me->set("bank/coin",0);
    write("你向神秘小販買到了一個保命金身(standby)!!!\n");
//    me->add("standby",1);
    return 1;
  }
}
int do_sell(string arg)
{
 object me,ob;
 me=this_player();
 if( arg!="standby")
  {
    write("你只能買替身(standby)!!\n");
    return 1;
  }
 if(me->query("standby") < 1)
  {
    write("你身上沒有替身人偶了說!!\n");
    return 1;
  }
 else
  {
    if( me->query("bank/coin") != 0)
      return notify_fail("請先將錢莊的 coco 都領出來，不然錢莊會暴掉喔!!!\n");
    me->add("bank/coin",2000000000);
    write("你賣了一個替身給小販,共二十萬兩黃金!!!\n");
    me->add("standby",-1);
    return 1;
  }
}

int do_follow(string arg)
{
 object me,ob;
 me=this_player();
 if( arg!="vendor")
    return 1;
 write("神秘小販使出超絕輕功......瞬間脫離你的視線了........!!\n");
 this_object()->move("/u/c/chan/workroom.c");
 return 1;
}
int accept_fight(object who)
{
 command("say ...偶!偶!偶!..討厭打架..。\n");
 return 0;
}
int accept_kill(object who)
{
  command("say 找死!!!\n");
  write("小販身上發出強大的真氣,壓迫你不知道如何是好\n");
  who->start_busy(2);
  kill_ob(who);
  return 1;
}
int do_perform(object who)
{
  who=this_player();
  command("say 找死!!!\n");
  write("小販身上發出強大的真氣,壓迫你不知道如何是好\n");
  who->start_busy(2);
  kill_ob(who);
  return 1;
}

void do_patrol()
{
  if( random(6) == 1)
        command("go north");
  else if( random(6) == 2)
        command("go south");
  else if( random(6) == 3)
        command("go east");
  else if( random(6) == 4)
        command("go up");
  else if( random(6) == 5)
        command("go down");
  else  command("go south");
return;
}

*/
