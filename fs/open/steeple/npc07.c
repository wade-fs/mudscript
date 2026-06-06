#include <ansi.h>
inherit NPC;
void do_special1();
void do_special2();
void create()
{
        object ob,who;
        who=this_player();
        set_name("沖田總司", ({"npc07","okita souji","okita","souji"}));
        set("title", "" + HIW + "【新撰組一番組長】" + NOR + "");
        set("long", "新選組副長助勤、新選組一番組長、新選組擊劍師範、試衛館教頭.\n");
        set("age", 20);
        set("str", 50);
        set("cor", 50);
        set("int", 50);
        set("spi", 50);
        set("cps", 50);
        set("kar", 50);
        set("force", 120000);
        set("max_force", 6000);
        set("force_factor", 60);
        set("combat_exp", 9000000);
        set("max_kee",20000);
        set("kee",20000);
        set("max_gin",30000);
        set("gin",30000);
        set("max_sen",30000);
        set("sen",30000);
        set("race", "人類");
        set("gender", "男性");
        set_skill("dodge", 120);
        set_skill("move", 100);
        set_skill("parry", 100);
        set("bellicosity",10000);
        set("s_kee",400);
        set("quest/rain",1);
        set("quests/get_tiger",1);
        set("quest/memory",1);
        set("quest/head-kill",1);
        set("class","killer");
        set("max_s_kee",400);
        set("family/family_name","黑牙聯");
        set("sec_kee","tiger");
        set_skill("force", 300);
        set_skill("fireforce",300);
        set_skill("blade", 120);
        set_skill("dagger", 60);
        set_skill("dragon-blade",120);
        set_skill("shadow-kill", 30);
        set_skill("shade-steps", 120);
        set_skill("throwing", 120);
        set_skill("rain-throwing", 120);
        map_skill("throwing","rain-throwing");
        map_skill("blade","dragon-blade");
        map_skill("dagger", "shadow-kill");
        map_skill("dodge", "nine-steps");
        map_skill("parry","wind-rain");
        map_skill("force","fireforce");
        set_temp("apply/damage", 90);
        set_temp("apply/armor", 90);
        set("functions/gold-fire/level",100);
        set("functions/manakee/level",200);
        set("quest/gold-fire",1);
        set("chat_chance_combat", 35);
        set("chat_msg_combat", ({
        (: do_special1 :),
        (: do_special2 :),
        }));
        setup();
        carry_object("/u/u/unfinished/sb");
        ob=carry_object("/u/u/unfinished/bomb.c");
        ob->set_amount(1000);
        ob->wield();
        carry_object("/open/killer/weapon/k_cloth3.c")->wear();
        carry_object("/open/killer/weapon/k_arm3.c")->wear();
        carry_object("/open/killer/weapon/k_head3.c")->wear();
        add_money("gold",25);
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


void die ()
{
 object me=query_temp("last_damage_from");
	if(!present("fight_card",me))
	{
	tell_object(me,"\n\n系統：由於你沒攜帶晶片，所以無法記錄戰績。\n");
	destruct (this_object ());
	return ;
	}
	if(!me->query("quest/start_game"))
	{
	tell_object(me,"\n\n系統：由於你沒有正式登記，資料無法傳輸。\n");
	destruct (this_object ());
	return ;
	}
	if(me->query("quest/start_game")< 8)
        {
        tell_object(users(),HIY + "
	恭喜"HIW+me->query("name")+HIY"挑戰" + HIG + "『" + HIR + "第六層試煉塔" + HIG + "』" + HIY + "通過！！

	" + HIW + "希望"+me->query("name")+"能不負眾望，勇闖" + HIG + "『" + HIY + "第七層試煉塔" + HIG + "』" + HIW + "。
	" + NOR);
	me->set("quest/start_game",8);
        destruct (this_object ());
	return ;
        }
	{
	tell_object(me,HIW + "系統：你已經通過測試，系統不做任何更改。\n" + NOR);
	destruct(this_object());
        :: die();
	}
}

int accept_kill(object who)
{
who=this_player();
command("say 哼!!來吧!!\n");
command("cmd bellup");
command("perform fireforce.gold-fire");
command("charge "+who->query("id"));
command("split "+who->query("id"));
kill_ob(who);
    return 1;
}
int accept_fight(object who)
{
who=this_player();
command("say 新撰組成員戰鬥是不會手下留情的!!\n");
command("cmd bellup");
command("perform fireforce.gold-fire");
command("charge "+who->query("id"));
command("split "+who->query("id"));
kill_ob(who);
    return 1;
}

int do_cmd(string str)
{
 object who=this_player();
 object ob,anmy;
 ob=this_object();
 anmy=present( "anmy",environment(ob) );
 if(str=="askgod souji" || str=="askgod souji"){
write(HIY + "沖田總司偷笑說：「對天神求神問卜，真笑死我了。」!!\n"
NOR);
command("cmd bellup");
command("perform fireforce.gold-fire");
command("charge "+who->query("id"));
command("split "+who->query("id"));
kill_ob(who);
 return 1;
                  }
}
void do_special1()
  {
    object *enemy,target;
    int i;

        enemy=this_object()->query_enemy();
        i=sizeof(enemy);
        target=enemy[random(i)];
        message_vision( HIG
        "沖田總司突然眼現殺氣, 全身散發出驚人的殺氣, 你當場被其殺氣給震攝住!!\n" + NOR,target);
        message_vision(
        "沖田總司放聲大喝道:\n
        "+HIC"                   天  然  理  心  流\n
        "+HIR"                ***"+HIR"**"+HIG"三"+HIR"**"+HIG"段"+HIR"**"+HIG"刺"+HIR"**"+HIG"法"+HIR"**"+HIR"***"NOR+"\n\n",target);
        message_vision(HIC
        "沖田總司拔出" + HIY + "菊一文字則宗" + HIC + "頓時刀光漫天, 全身被刀器所籠罩！！！\n" + NOR,target);
        message_vision(HBGRN + "\n沖田總司以驚人的速度在$N身上猛一劈刀, $N的鮮血狂噴而出！\n" + NOR,target);
        target->receive_wound("kee",400+random(200));
        COMBAT_D->report_status(target);
        COMBAT_D->report_status(target);
        message_vision(HBGRN + "沖田總司以驚人的速度在$N身上猛一劈刀, $N的鮮血狂噴而出！\n" + NOR,target);
        target->receive_wound("kee",200+random(100));
        COMBAT_D->report_status(target);
        COMBAT_D->report_status(target);
        message_vision(HBGRN + "沖田總司以驚人的速度在$N身上猛一劈刀, $N的鮮血狂噴而出！\n" + NOR,target);
        target->receive_wound("kee",200+random(100));
        COMBAT_D->report_status(target);
        COMBAT_D->report_status(target);
  }

void do_special2()
  {
    object *enemy,target;
    int i;

        enemy=this_object()->query_enemy();
        i=sizeof(enemy);
        target=enemy[random(i)];
        message_vision( HIG
        "沖田總司突然眼現殺氣, 全身散發出驚人的殺氣, 你當場被其殺氣給震攝住!!\n" + NOR,target);
        message_vision(
        "沖田總司放聲大喝道:\n
        "+HIC"                   天  然  理  心  流\n
        "+HIR"                ***"+HIR"**"+HIG"一"+HIR"**"+HIG"文"+HIR"**"+HIG"字"+HIR"**"+HIG"斬"+HIR"**"+HIR"***"NOR+"\n\n",target);
        message_vision(HIC
        "沖田總司拔出" + HIY + "菊一文字則宗" + HIC + "頓時刀光漫天, $N全身被刀器所籠罩！！！\n" + NOR,target);
        message_vision(HIW + "\n菊一文字則宗發出不可逼視的強光奪去$N的視覺, $N頓時失去行動能力！\n" + NOR,target);
        COMBAT_D->report_status(target);
        COMBAT_D->report_status(target);
        target->start_busy(1);
  }
void heart_beat()
{
 object env,mob,*enemy,target,obj;
 int i,j;
 mob = this_object();
 env = environment(mob);
 if( query("kee") < 0)
 mob->die();
 if( random(100) < 30)
 {
    enemy=mob->query_enemy();
    i=sizeof(enemy);
    target=enemy[random(i)];
    if( env == environment(target) )
    {
        message_vision( HIG
        "沖田總司突然眼現殺氣, 全身散發出驚人的殺氣, 你當場被其殺氣給震攝住!!\n" + NOR,target);
        message_vision(
        "沖田總司放聲大喝道:\n
        "+HIW"                   獨  門  禁  斷  技\n
        "+HIY"                ***"+HIY"**"+HIY""NOR+HIB"青"+HIY"****"NOR+HIB"平"+HIY"****"NOR+HIB"眼"+HIY""NOR+HIY"**"+HIY"***"NOR+"\n\n",target);
        message_vision(HIG
        "沖田總司激發出全身鬥氣, 以劍尖對住$N的眼睛，劍尖下沉而向右微傾！！！\n" + NOR,target);
        message_vision(HIC + "當沖田總司的刀快與$N接觸時，沖田總司的刀以電光火石般地速度滑向$N，一刀斬斃$N！\n" + NOR,target);
        target->receive_wound("kee",500+random(400));
        COMBAT_D->report_status(target);
        message_vision(HIC + "一擊命中, 沖田總司立刻回身, 使出拿手的突刺朝著驚愕住的$N胸口刺去！\n" + NOR,target);
        target->receive_wound("kee",300+random(100));
        COMBAT_D->report_status(target);  
        COMBAT_D->report_status(target);
        target->start_busy(1);  
 }
 }
 
 if((mob->query("kee")<mob->query("max_kee")*0.5) && (random(100) < 20) )
 {
    tell_room(environment(), HIY+name()+"運起天然理心流療法,為自己"
               +"療傷.\n"+NOR);
    mob->receive_curing("kee",2000);
    mob->receive_heal("kee",1000);
 }

   
   set_heart_beat(1);
   ::heart_beat();
   
}
