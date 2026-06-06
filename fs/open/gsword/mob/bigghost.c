inherit NPC;
object ob1=this_object();
object ob2=this_player();
int done=0;
void create()
{
	set_name("綠毛老祖",({"ru mou","ru"}));
	set("long","此人身長十尺 ,全身滿是綠色的毛髮 ,身上的肌肉因練功\之故
已糾結不清 ,長出類似鬚鬚之類的肉根 ,看起來十分的詭異。 .\n");
	set("gender","男性");
       set("combat_exp",100000);
        set("attitude","aggressive");
	set("age",51);
	set("title","血魔");
	set("force",1000);
	set("max_gin",1000);
        set("max_kee",4000);
	set("max_force",1000);
        set("force_factor",15);
        set("str",50);
        set("chat_chance_combat",20);
        set("chat_msg_combat",({
        (: this_object(),"special_attack" :),
        }));
        set("cor", 40);
	set("per", 10);
	set("int", 30);
	set("cps",40);
	set("con", 30);
	set("spi", 15);
	set("kar", 40);
        set_skill("unarmed",100);
        set_skill("dodge",60);
       set_skill("parry",60);
	set_skill("move",50);
	set_skill("force",50);
	setup();
}

         
void init()
{
add_action("do_show","show");
}

int do_show(string str)
{
 if(!this_player()->query_temp("allow_read",1))
   {
    write("你要作什麼??\n");
    return 1;
    }
 if(str!="blood_sword")
    {
    write("你要作什麼??\n");
    return 1;
    } 
 else
  {
    write("綠毛老祖道 : 等等......這把劍你是打哪來的??聰明的話 ,乖乖的把劍
    給我 ,我還可饒你不死 \n");
    this_player()->set_temp("have_show",1);
   return 1;
   }
 }   
    
       
 int special_attack()
 {
   object ob;
   ob=this_object()->query_enemy();
   message_vision("綠毛老祖眼露青光 ,手臂暴長向你而來 ,在你身上留下一道莫大的傷口.\n",this_object());
   ob->add("kee",-50);
  return 1;
  }
     
 void greeting(object ob)
 {
  if( !ob || environment(ob) != environment() ) return;
  if(ob->query("family/family_name","仙劍派") )
     say("綠毛老祖道:哈!哈!仙劍派子弟來的好 ,讓我送你上西天吧.\n ");
  else
    say("老祖不耐煩的說:這是我跟仙劍派之間的恩怨 ,小子少管閒事.\n");
  }
  
 int accept_object(object who,object ob)
 {
if( ob->query("id")!="blood_sword"||!who->query_temp("have_show",1) )
    {
      write("綠毛老祖道 :多謝你的禮物啊....這算是求饒嗎??我可是不會手下留情的\n");
      return 0;
    }
   else
     {
      who->remove_all_killer();
      set_heart_beat(1);
      write("老祖道:多謝你將這把劍還給我,你如打贏我的話我可告訴你一個祕密 ,來吧.\n");
      who->set_temp("have_fight",1);
      write("老祖說罷 ,將手中赤麟一握 ,不知是不是錯覺 ,你感到老祖氣勢已和剛剛
      大不相同 ,你感到些許的恐懼\n");
      ob1->set("combat_exp",500000);
      ob1->set_skill("shasword",80);
      ob1->set_skill("sword",80);
      ob1->map_skill("sword","shasword");
      command("wield blood_sword");
      ob2->set_temp("have_give",1);
      return 0;
      }
 }         
          
         
 void die()
  {
   object me;
   me = this_object()->query_temp("last_damage_from");
   if (me && userp(me))  {
     me->add("bounds",100); 
     tell_room(environment(),sprintf("%s從老祖身上除下100根綠毛.\n",me->name()));
   }
   ::die(); 
  }
       
  void heart_beat()
   {
     if(query("kee") <0)
        die();
        if(!ob2) return ;
     if(ob2->query_temp("have_give",1))
     if(done==0)
     if( ob1->query("kee") < ob1->query("max_kee")*0.2)
       {
         ob2->remove_all_killer();
         message_vision("小子...你本事不錯麻....,竟然能打贏我 ,今天 ,我就破例作個好人 ,
         跟你說一個天大的秘密吧\n",ob2);
         tell_object(ob2,"綠毛老祖以腹語告訴你 : 祕密就在前山的巖穴中,你如有緣的話自然會發現\n");
         message_vision("哈....這是回報你還劍之情 ,下次見面 ,可別怪我手下不留情啊..\n",ob2);
         done++;
         ob2->set_temp("have_win",1);
        }
     ::heart_beat();
   }               
