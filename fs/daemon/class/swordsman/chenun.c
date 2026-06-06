//補上殺手的quest人頭任務 by blazakira 2011/8/5

#include "/open/gsword/npc/attack_bloodsword.h"
#include <ansi.h>
#include "/open/open.h"
inherit NPC;
inherit F_MASTER;

object ob1=this_object();
object ob2;
int have_say;

void create()
{
  set_name("張乘雲", ({"chen un","un"}));
  set("long","鄭士欣二弟子，與其兄乘風同時進入仙劍派，乘雲在劍法上雖已明顯落
後於乘風，但說到內力深厚，仙劍派中除了掌門人鄭士欣，無人能及乘
雲項背，兄弟兩因行俠於江湖，而並稱風雲雙俠。乘雲平時負責看管藏
經閣。\n");
  set("gender","男性");
  set("class","swordsman");
  set("combat_exp",500000);
  set("attitude","heroism");
  set("age",43);
  set("nickname","風雲雙俠");
  set("title","仙劍派第四代二弟子");
//  set("kee",1500);
  set("max_kee",1500);
//  set("gin",1500);
  set("max_gin",1500);
//  set("sen",1500);
  set("max_sen",1500);
  set("force",1800);
  set("max_force",1800);
  set("force_factor",10);
  set("sha-stop-2",1);
  set_skill("array",80);
  set_skill("sha-array",80);
  set_skill("sword",80);
  set_skill("dodge",70);
  set_skill("shaforce",50);
  set_skill("shasword",80);
  set_skill("move",80);
  set_skill("parry",100);
  set_skill("sha-steps",70);
  set_skill("force",50);
  map_skill("sword","shasword");
  map_skill("array","sha-array");
  map_skill("parry","shasword");
  map_skill("force","shaforce");
  map_skill("dodge","sha-steps");
  set("str", 30);
  set("con", 30);
  set("int",20);
  set("per",40);
  setup();
  carry_object("/open/gsword/obj/sword-2")->wield();
  create_family("仙劍派",4,"弟子");
  add_money("gold",5);
}

int accept_fight(object me)
{
  if((int)me->query("combat_exp")<=80000)
  {
    command("say 刀劍無眼,傷了你就不好了");
    return 0;
  }
  command("say 出招吧!");
  ob2=this_player();  
  return 1;
 }

int accept_kill(object me)
{
   ob2=this_player();
   return 1;
 } 

void attempt_apprentice(object ob)
{
  if(!ob->query_temp("allow_2"))
  {
    command("say 沒有師父的同意，我不敢擅自收徒!");
    return 0;
  }
  command("smile");
  command("say 既然是師父的意思，以後你就跟我好好學吧!");
  command("recruit "+ob->query("id"));
  ob->set("marks/仙劍七俠",1);
}

int accept_object(object who,object ob)
{
  if( ob->query("id")!= "pass" )
  {
    write("張乘雲說 你給我這個做什麼??不過 ,看在你一份心意上 ,我還是接受了吧 \n");
    return 0;
  }
  else 
  {
    write("張乘雲說: 看來你已經得到掌門得許\可了，你就進去藏經閣吧!\n");
    write("不過.....我懷疑掌門人是否看錯人了...讓我來領教一下你的武功吧!\n");
    command("drop pass");
    command("kill "+who->query("id")); 
    have_say=0;
    return 1;
  }
}

void heart_beat()
{
  int kee;
  if(!ob1 || !ob2) return ;
  kee= ob1->query("max_kee");
  if(this_object()->query("kee") < 0)
  {
    this_object()->die();
    return ;
  }
  if( ob1->query("kee") < 0.4*ob1->query("max_kee") && ob2->query_temp("allow_pass",1) )
  {
    ob1->remove_all_killer();
    if(have_say==0)
    {
      message_vision("張乘雲說: 等一下～～我認輸了..............\n",this_object());
      if(!ob2) return ;
      if( ob2->query_temp("allow_pass",1) )
      {
        message_vision("看來你的確有這個實力，希望你學成之後能對仙劍做些有益的事，光大仙劍的武功n",ob2);
        message_vision("好了，你可以進去了\n",ob2); 
        have_say=1;
        ob1->set("kee",kee);
        ob1->set("eff_kee",kee);
        ob2->set_temp("allow_read",1);
      }
    }
  } 
  if(this_object()->query("kee") < 0) this_object()->die();
  ::heart_beat();
}

void die()
{
  object head,winner = query_temp("last_damage_from");
  int j;
  if(!winner)
  {
    ::die();
    return ;
  }

  if( winner->query_temp("allow_pass",1) )
  {
    write("張乘雲說: 看來你的確有這個實力，希望你學成之後能對仙劍做些有益的事，光大仙劍的武功!\n");
    write("好了，你可以進去了!\n");
    winner->set_temp("allow_read",1);
  }

  if(winner->query_temp("head") == 3 )
  { //要求解第三進職的玩家，一定要自己殺死七子之一
    //所以設下head 4，如果不是在解第三進職的玩家，並不會拿到人頭
    message_vision(HIY + "可惡！居然會敗在你的手下,看來武林將有一陣腥風血雨\n" + NOR,this_object());
    message_vision("說完之後他就倒下了。。。。\n",this_object());
    winner->set_temp("head",4);
    head=new("/open/killer/headkill/obj/sword_head.c");
    head->move(this_object());
  }
  if ((winner->query("class") == "killer") && (winner->query_temp("head") != 4))
  { //避免條件連續兩次成立（因為解headkill之謎的一定是殺手）
    //想將七子的人頭加在殺人名單中，所以是殺手來砍七子，亦可以得到人頭
    //但是因為不是在解第三進職，所以並不會設定步驟值
    message_vision(HIY + "可惡！居然會敗在你的手下,看來武林將有一陣腥風血雨\n" + NOR,this_object());
    message_vision("說完之後他就倒下了。。。。\n",this_object());
    head=new("/open/killer/headkill/obj/sword_head.c");
    head->move(this_object());
  }
  if(userp(winner) && winner->query_temp("not_robot") > time() )
  {
    if ( winner->query_temp("bless")==1 )
    {
      j=random(-1);
      if( j==7 || j==77 || j== 777 || j==1111 || j==55 || j==555 || j==1000 || j==4000 || j==3333 || j==2222 )
      {
        new("/open/sky/obj6/prairie_diamond")->move(environment(winner));
        message_vision(HIM + "\n從張乘雲的身上掉下了一件奇怪的東西!!\n" + NOR,winner);
        write_file("/log/sky/obj6/prairie_diamond",sprintf("%s(%s) 讓張乘雲掉下了草原之青鑽於 %s\n",
        winner->name(1),winner->query("id"),ctime(time())));
      }
    } else {
      j=random(-1);
      if( j==5 || j==15 || j== 150 || j==1500 || j==10 || j==100 || j==1000 || j==4000 || j==6666 || j==7777 ) 
      {
        new("/open/sky/obj6/prairie_diamond")->move(environment(winner));
        message_vision(HIM + "\n從張乘雲的身上掉下了一件奇怪的東西!!\n" + NOR,winner);
        write_file("/log/sky/obj6/prairie_diamond",sprintf("%s(%s) 讓張乘雲掉下了草原之青鑽於 %s\n",
        winner->name(1),winner->query("id"),ctime(time())));
      }
    }
  }
  ::die();
}
