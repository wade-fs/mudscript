#include <ansi.h>
inherit NPC;
string ask_soul()
{
  if(this_player()->query_temp("quests/confuse") != 6 &&
      this_player()->query_temp("quests/confuse") != 7
    )

  return "";

  if(base_name(environment(this_object())) == "/open/scholar/room/house")
  {
    if(!query_temp("empty") || !query_temp("follow"))
    {
      return "嗯？！我怎麼在這。";
    }

    message_vision("$N低頭看了一下陳平，並且說道：嗯，看來這只能用靈魂出竅大法，來進去他夢裡叫醒他才有用。\n",this_object());
    message_vision("$N說道：但是施行此術，所需材料如下：三葉芝蘭之草一份，蠍毒一份，與天靈丹一份。\n",this_object());
    message_vision("$N說道：準備好了就拿給我吧，所有東西都齊全了，就會開始施行靈魂出竅大法了。\n",this_object());
    this_player()->set_temp("quests/confuse",7);

    return "";
  }

  this_player()->set_temp("quests/confuse",7);
  return "你沒看到我這裡有很多的病人嘛？我跟本沒空過去幫你施行靈魂出竅。而且...病人也要在我身邊我才有辦法治吧！";
}
void create()
 {
        set_name("劉進泉",({"chuan liu","chuan","liu"}));
        set("long","
  他是銀針門掌門的大徒弟。對於醫術也津津樂道。
");
        set("gender","男性");
        set("class","doctor");
        set("nickname","無影針");
        set("combat_exp",550000);
        set("attitude","heroism");
        set("age",35);
        set("title","銀針門首徒");
        set("str",19);
        set("cor",24);
        set("cps",29);
        set("per",20);
        set("int",17);
        set("con",20);
        set("spi",26);
        set("kar",20);
        set("force",1200);
        set("max_force",1200);
        set("force_factor",10);
        set_skill("move",40);
        set_skill("literate",40);
        set_skill("cure",60);
        set_skill("godcure",70);
        set_skill("dagger",40);
        set_skill("poison",50);
        set_skill("force",50);
        set_skill("dodge",60);
        set_skill("parry",40);
        set_skill("unarmed",40);
        set_skill("hammer",40);
        set_skill("shinnoforce",50);
        set_skill("stabber",60);
        set_skill("yu-needle",80);
        map_skill("cure","godcure");
        map_skill("stabber","yu-needle");
        map_skill("parry","yu-needle");
        set_skill("seven-steps",60);
        map_skill("dodge","seven-steps");
        map_skill("move","seven-steps");
        map_skill("force","shinnoforce");
        set("chat_chance_combat",20);
        set("chat_msg_combat",({
            HIY + "劉進泉說道: 真的要打嗎? 你恐怕不是我的對手吧!\n" + NOR,
            HIY + "劉進泉說道: 就讓你嚐嚐苦頭吧! 好讓你知道天有多高地有多厚!\n" + NOR,
      }));
        set("inquiry",([
              "靈魂出竅"     : (: ask_soul:),
              "陳平" : "唔？你是指那位長睡不起儒門的長輩嘛？",
              ]));

        setup();

        carry_object("/open/doctor/obj/needle6.c")->wield();
        add_money("gold",5);
 }
void greeting(object ob)
{
        if( (string)ob->query("class") == "poisoner" )
{
        command("say 師父生平最恨毒害蒼生之人,今日我便為師除害,納命吧！");
        kill_ob(ob);
}
}
int accept_object(object me, object ob)
{
  if(me->query_temp("quests/confuse") == 7)
  {
    if(ob->query("id") == "three_leaf") 
    {
      add_temp("quests/confuse_get/three",1);
      command("say 沒錯，這正是靈魂出竅所需要的物品");
    }
    if(ob->query("id") == "sky pill") 
    {
      add_temp("quests/confuse_get/sky",1);
      command("say 沒錯，這正是靈魂出竅所需要的物品");
    }
    if(ob->query("id") == "scorpion poison") 
    {
      add_temp("quests/confuse_get/poison",1);
      command("say 沒錯，這正是靈魂出竅所需要的物品");

    }
    if(query_temp("quests/confuse_get/three") &&
      query_temp("quests/confuse_get/sky") &&
    query_temp("quests/confuse_get/poison"))
    {
      command("say 看來所需要的東西都有了，讓我來施行靈魂出竅之術吧。");
      me->set_temp("quests/confuse" ,8);
      call_out("do_soul",2,me,1);
    }

      return 1;
  }
}
void do_soul(object me,int step)
{
  if(!me) 
  {
    message_vision("$N說道：人勒人勒？怎麼不見了！\n",this_object());
    return ;
  }
  if(environment(this_object()) != environment(me))
  {
    message_vision("$N說道：人勒人勒？怎麼不見了！\n",this_object());
    return ;
  }
  switch(step)
  {
    case 1:
      message_vision(CYN + "$N把蠍毒與天靈丹放置於砵盤中攪碎，再加上一些水。\n" + NOR,this_object());
    break;
    case 2:
      message_vision(CYN + "$N把再把三葉芝蘭之草放置於砵盤中攪碎，再加上一些酒。\n" + NOR,this_object());
    break;
    case 3:
      message_vision(CYN + "$N把針沾上剛剛混合的藥物。\n" + NOR,this_object());
    break;
    case 4:
      message_vision(CYN + "接著，$N把針往$n的太陽穴一插，$n就突然就不醒人事了。\n" + NOR,this_object(),me);
      { 
        object * obs  = all_inventory(me);
        CHAR_D->make_corpse(me,this_object())->move(environment());
        me->unconcious();
        obs->move(me);
        step++;
        call_out("do_soul",15,me,step);
        me->start_busy(1000);
        return ;
      }
    break;
    case 5:
      me->revive();
      me->delete_busy();
      me->move(environment(me));
      message_vision(CYN + "$n看了一下地上的屍體，就直接進入陳平的夢中了。\n" + NOR,this_object(),me);
      step++;
      call_out("do_soul",1,me,step);
      return ;
    break;
    case 6:
      me->set_temp("quests/confuse",9);
      me->move("/open/scholar/magic_square/1-1",1);
      load_object("/open/scholar/magic_square/npc/man.c")->move(environment(me));
    break;
    default:
  }
  step++;
  call_out("do_soul",5,me,step);
}
