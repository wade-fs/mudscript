// 平南將軍
#include "/open/open.h"
#include <ansi.h>
inherit NPC;
void create()
{
	set("title","正五品督軍");
	set_name("張淵",({"officer zhang","officer","zhang"}));
	set("long","朝庭派來平南督軍的欽命大臣,他正為苗人的入侵(煩惱).\n");
	set("gender","男性");
        set("attitude","heroism");
	set("chat_chance", 15);
	set("chat_msg", ({
	" 張淵說: 苗軍入侵聯綿不斷,如何是好??\n",
	" 張淵說: 來此督軍,真是個苦差事啊!!\n",
	" 張淵說: 有能人俠士願意伸出(援手)哉??\n"
	}));
	set("inquiry",([
	"煩惱" : "本朝與苗軍對抗已數年了,如今騎虎難下,不知如何收場,唉...\n",
	"援手" : "擒賊先擒王,本官欲徵一壯士,買(苗王)頸上人頭!!\n",
	"苗王" : "壯士欲效力朝廷嗎? 必有(重賞)!\n",
	"重賞" : "壯士請先殺掉苗軍隊長,拿其配刀來證明汝之忠誠,後話再敘.\n",
	]) );
	set("age",32);
	set("int",30);
	set("per",30);
	set("str", 15);
	set("con", 30);
	set("force",1500);
	set("max_force",1500);
        set("combat_exp", 37500);
	set_skill("literate",40);
	set_skill("force",60);
        set_skill("dodge", 1);
        set_skill("parry", 1);
        set_skill("unarmed",45);
        set_skill("linpo-steps",1);
        set_skill("six-fingers",45);
	map_skill("dodge","linpo-steps");
	map_skill("parry","six-fingers");
        map_skill("unarmed","six-fingers");
        map_skill("stabber","six-fingers");
        set("functions/handwriting/level",10);
        set("chat_chance_combat", 20);
        set("chat_msg_combat", ({
           (: perform_action("stabber.handwriting") :),
           }));        
        set("force_factor", 3);
	setup();
	carry_object("/open/ping/obj/fan-1")->wield();
	carry_object("/open/ping/obj/robe-1")->wear();
	carry_object("/open/ping/obj/wrists-1")->wear();
	add_money("silver",50);
}
int accept_object(object who, object ob)
{
  object mid;
  if( ob->query("id") == "maiu blade")
  { 
    destruct(ob);
    who->set_temp("maiu",1);
    say("正五品督軍 張淵對苗刀詳細審視,說道: 果真是苗軍隊長的配刀.\n"+
        "那...這是我方忍者盜得的信物,拿這個給苗人軍師,便可見到苗王,\n"+
        "至時,殺了苗王,取其人頭來見我即可,本朝必然不會虧待你.\n");
    mid=new("/open/ping/obj/mid");
    mid->move(who);
  }      
  else if( ob->query("id") == "maiu-head" && who->query_temp("maiu") )
  { 
   destruct(ob);
   say("正五品督軍 張淵審視人頭一番,大笑曰: 終於死了,你這老頭...哈哈哈!!!\n"+
       "那...這是給你的謝禮.\n正五品督軍給你一些藥丸.\n");  
   mid=new("/daemon/class/doctor/medicine/curesick");
   mid->add_amount( who->query_per() );
   mid->move(who);
   who->delete_temp("maiu");
   who->delete_temp("k_m"); 
  }
   return 1;  
}
int accept_kill(object who)
{
  object head;
  if( who->query_temp("maiu") && !query("change"))
  {
   say("正五品督軍大怒: 你這個賤民,竟敢背叛我!!看我怎麼收拾你!!!\n"
        +"正五品督軍的頭上冒出騰騰紫氣!\n");
   set("title","- 紫氣 -");
   set("combat_exp", 180000);
   set("max_kee",3000);
   set("change",1);
   set("kee",3000);
   set("force_factor", 15);     
   set_skill("six-fingers",70);
   set_skill("linpo-steps",60); 
   head=new("/open/ping/obj/zhang-head");
   head->move(this_object());
   setup();
  }
  command("wield all");
  return 1;
}
int accept_fight(object who)
{
  if( who->query_temp("maiu") )
      return notify_fail("正五品督軍說: 壯士別開玩笑了...要殺的是苗王啊!\n");
  command("wield all");
  return 1;
}                        

void die()
{    
	object winner = query_temp("last_damage_from");
	int j;
	if(!winner)
	{
	::die();
	return ;
	}
    if(userp(winner) && winner->query_temp("not_robot") > time() )
    {
	if( winner->query_temp("bless")==1 )
	{
	j=random(-1);
	  if( j==7 || j==77 || j== 777 || j==1111 || j==55 || j==555 || j==1000 || j==4000 || j==3333 || j==2222 )
	  {
	  new("/open/sky/obj11/green-crystal")->move(environment(winner));
	  message_vision(HIM + "\n從張淵的身上掉下了一件奇怪的東西!!\n" + NOR,winner);
          write_file("/log/sky/obj11/green_crystal",sprintf("%s(%s) 讓張淵掉下了綠色光晶於 %s\n",
	  winner->name(1),winner->query("id"),ctime(time())));
	  }
	}else{
	j=random(-1);
	  if( j==5 || j==15 || j== 150 || j==1500 || j==10 || j==100 || j==1000 || j==4000 || j==6666 || j==7777 )
	  {
	  new("/open/sky/obj11/green-crystal")->move(environment(winner));
	  message_vision(HIM + "\n從張淵的身上掉下了一件奇怪的東西!!\n" + NOR,winner);
          write_file("/log/sky/obj11/green_crystal",sprintf("%s(%s) 讓張淵掉下了綠色光晶於 %s\n",
	  winner->name(1),winner->query("id"),ctime(time())));
	  }
	}
	}
	::die();
}
