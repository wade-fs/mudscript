
#include <ansi.h>
inherit NPC;
   
void create()
{
        set("long","
焚天魔王，魔界之統治者，他全身火焰繞身，火舌隨著他的情緒不停的奔騰著。
仔細一看他竟可以御氣凌空，內功\之深簡直不可思議。另外練就曠世絕學「極火功\」
，極火掌一發動更是烈焰奔騰，威不可擋。由極火功\所化成的「極火金身」護身
氣勁更能在四周形成堅硬火罩。
");
        set("gender","男性");
        set("nickname",HIR + "赤獄混沅" + NOR);
        set("title",HIW + "～幻影～" + NOR + "魔界之王");
        set_name("焚天魔王",({"fire king","king"}));
        set("combat_exp",20000000);
        set("attitude","aggressive");
        set("score",90000000);
        set("bellicosity",1000000);
        set("age",10000);
        set("max_force",1000000);
        set("force",5000000);
        set("max_kee",100000);
        set("kee",100000);
        set("max_gin",14000);
        set("max_sen",14000);
        set("str", 35);
        set("cor", 35);
        set("cps", 30);
        set("per", 30);
        set("int", 30);
        set("force_factor",45);
        set_skill("dodge",220);
        set_skill("force",250);
        set("clan_kill",1);     //不能派殺手追殺
        set("no_mount",1);
        set("no_plan_follow",1);
        set_skill("move",280);
        set_skill("parry",250);
        set_skill("mogi-steps",200);
        set_skill("firestrike",220);
        set_skill("unarmed",220);
        set_skill("literate",200);
        set_skill("fireforce",250);
        set_temp("armor_vs_force",5000);
        map_skill("force","fireforce");
        map_skill("unarmed","firestrike");
        map_skill("dodge","mogi-steps");
        map_skill("move","mogi-steps");
        map_skill("parry","firestrike");

        set("functions/gold-fire/level",100);
        set("quest/gold-fire",1);
        set("quest/new_gold_fire",1);
        setup();
        carry_object("/autoload/mogi/fire-armor")->wear();
        carry_object("/autoload/mogi/fire-cloud-boots")->wear();
        carry_object("/autoload/mogi/fire-belt")->wear();
        carry_object("/autoload/mogi/daemon-cloak")->wear();
        carry_object("/autoload/mogi/fire-dragon")->wield();
        carry_object("/autoload/mogi/sspill")->set_amount(7);
        carry_object("/open/killer/headkill/obj/world_dag.c");
        add_money("gold",1000);
}

void init()
{
 ::init();
 add_action("do_cmd","cmd");
 add_action("do_exert","exert");
}
int do_cmd(string str){                 //ok by chan
 object who=this_player();
 object ob,king;
 ob=this_object();
 king=present( "king",environment(ob) );
 if(str=="askgod king" || str=="askgod fire king"){
 write(HIY + "焚天魔王冷笑：「在本魔王面前求神問卜!?先問問我還差不多。」去死吧!!\n" + NOR);
 command("perform fireforce.gold-fire");
 king->kill_ob(who);
 return 1;                                                 
                  }
 if(str=="bak king"){
 write(HIY + "焚天魔王冷笑：想暗殺本魔王!!!也不打聽誰是暗殺之王呀!!!去死吧!!\n" + NOR);
 command("perform fireforce.gold-fire");
 king->kill_ob(who);
 return 1;
                  }
}


void greeting(object me)
{
 write(HIY + "焚天魔王發出懾人心神聲音：「來者是誰!?」
「能來到這裡，真不簡單！江湖之上的人物，算你一號！」
「不過若想找我比劃，你還差得太遠」
" + NOR); 
}
int accept_fight(object who)
{
 write(HIY + "焚天魔王冷冷的說：「要命的話就快走吧！」\n" + NOR);
 return 0;
}
int do_exert(string str){
 mixed all;
 int i=0;
 object king,room,me,obj;
 me=this_player();
 room = environment(me);
 all = all_inventory(room);
 king=present( "king",environment(me) );
 if(str=="roar"){
 say(HIC + "$N氣凝丹田，用力一吼企圖以內力震傷焚天魔王。\n",me);
 say(HIC + "焚天魔王冷笑說『你這也叫吼?讓你們見識一下真正的" + HIR + "天魔狂吼" + HIC + "吧!!\n");
 say(HIR + "\n焚天魔王大吼一聲，剎那間天驚地搖，魔界因此而震動!!周遭的生物剎那間非死即傷\n");
 for( i = 0 ; i < sizeof(all) ; i++){
 obj = all[i];
  if( obj->is_character() && !obj->is_corpse() && living(obj)
 && obj->query("id")!="fire king"){
 message_vision(HIR + "結果$N被這威力無比的天魔怒吼震傷，哇一聲吐出一大口鮮血!!\n" + NOR);
 obj->add("kee",-6000);
 king->kill_ob(obj); }
                                    }
 return 1;
                  }
}
int accept_kill(object who)
{
 who = this_player();
 write(HIY + "焚天魔王從寶座上豁然站起\n" + NOR);
 command("say 鼠輩無禮！嚐嚐我極火功\的厲害吧！");
 command("perform fireforce.gold-fire");
 kill_ob(who);
 return 1;
}

void heart_beat()
{

 mixed all;
 object me,room,obj;
 int maxkee,kee,i,count,maxforce;
 count = random(100);
 me = this_object();
 room = environment(me);
 all = all_inventory(room);
 maxforce=me->query("force");
 if(count < 50 && me->is_fighting())
 {
object who;
who=this_player();
if(maxforce < 1000000)
{
 message_vision(HIW + "\n                        ～幻～影～心～訣～

焚天魔王內力突受試煉塔系統影響，內力暴增為原來的兩倍，萬物頓時黯淡失色，一瞬間，
$N受到焚天魔王內力的影響，動彈不得。\n\n",who);
who->start_busy(3);
me->add("force",200000);
}
}
 if(count < 9 && me->is_fighting())
 {
  message_vision(HIR + "\n焚天魔王大喝一聲，剎那間天驚地搖，魔界因此而震動!!周遭的生物剎那間非死即碎!!\n" + NOR,me);
  for( i = 0 ; i < sizeof(all) ; i++)
   {
    obj = all[i];
    if( obj->is_character() && !obj->is_corpse() && living(obj)
    && obj->query("id")!="fire king")
     {
      message_vision(HIR + "結果所有人被這威力無比的天魔怒吼震傷，哇一聲吐出一大口鮮血!!\n" + NOR,obj);
      obj->add("kee",-4000);
      obj->start_busy(2);
      COMBAT_D->report_status(obj, 1);
     }
   }
 }
 if(count < 2 && me->is_fighting())
 {
  message_vision(HIR + "
       焚天魔王將全身業火暗運掌上，掌上業火蘊藏著無限吸勁
       眨眼間，焚天魔王叱喝迴盪" + HIR + "『魔道輪迴 業火橫行』" + HIW + "
       業火不斷向四周吸引氣勁\n" + NOR,me);
  for( i = 0 ; i < sizeof(all) ; i++)
   {
    obj = all[i];
    if( obj->is_character() && !obj->is_corpse() && living(obj)
    && obj->query("id")!="fire king")
     {
      message_vision(HIR + "結果所有人4/5內力全受業火吸引，洩向四周!!\n" + NOR,obj);
      obj->add("force",-((obj->query("force")/5))*4);
      COMBAT_D->report_status(obj, 1);
     }
   }
 }
 if(count <13 && me->is_fighting())
  {
  message_vision(HIW + "
       焚天魔王化身煉獄業火，妖氣在一瞬間變成沸騰血紅魔風，凡被其吹拂
       之物盡揮成汽，熔人口鼻令人窒息
       眨眼間，焚天魔王叱喝迴盪" + HIR + "『赤獄混沅  魔道遮天』" + HIW + "，熔融魔氣挾著蝕骨
       焚燄之風瘋狂的侵襲著一切\n" + NOR,me);
  for( i = 0 ; i < sizeof(all) ; i++)
   {
    obj = all[i];
    if( obj->is_character() && !obj->is_corpse() && living(obj)
         && obj->query("id")!="fire king")
     {
      message_vision(HIR + "結果$N被熔融極火捲到，哀嚎連連中渾身青煙直冒伴隨著陣陣焦肉味!\n" + NOR,obj);
      obj->receive_wound("kee",5000);
      COMBAT_D->report_status(obj, 1);
     }
   }
  }


 if( random(10) < 2 )
 {
  if( is_fighting() )
  {
   if( query("kee") < query("eff_kee") )
    message_vision(HIG + "\n焚天魔王身冒出熊熊火燄，傷口漸漸的癒合了\n" + NOR,me);
    me->receive_heal("kee",8000);
    me->receive_heal("gin",5000);
    me->receive_heal("sen",5000);
    me->delete_busy();
    me->clear_condition();
  }
  else
  {
   if( query("eff_kee") < query("max_kee") )
    command("exert heal");
    me->add("force",100000);
  }
 }
::heart_beat();
}

int heal_up()
{
        if (!is_fighting() ) {
             message_vision (HIW + "系統：戰鬥停止，$N回收中，。\n" + NOR, this_object ());
             destruct(this_object());
             return 1;
        }
        return ::heal_up() + 1;
}
void unconcious ()
{
 object me=query_temp("last_damage_from");
if(!present("fight_card",me))
{
tell_object(me,"\n\n系統：由於你沒攜帶晶片，所以無法記錄戰績。\n");
destruct (this_object ());
}
else
if(!me->query("quest/start_game"))
{
tell_object(me,"\n\n系統：由於你沒有正式登記，資料無法傳輸。\n");
destruct (this_object ());
}
else
if(me->query("quest/start_game")< 50)
       {
        tell_object(users(),HIY + "
恭喜" + HIW+me->query("name")+HIY + "挑戰" + HIG + "『" + HIR + "第四十九層試煉ソ塔" + HIG + "』" + HIY + "通過！！

" + HIW + "希望"+me->query("name")+"能不負眾望，勇闖" + HIG + "『" + HIY + "第五十層試煉ソ塔" + HIG + "』" + HIW + "。
	" + NOR);
	me->set("quest/start_game",50);
        destruct (this_object ());
       }
{
        :: unconcious();
	tell_object(me,HIW + "系統：你已經通過測試，系統不做任何更改。\n" + NOR);
	destruct(this_object());
}
}
