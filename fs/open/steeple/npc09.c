#include <ansi.h>
inherit NPC;
void do_special1();
void do_special2();
void do_special3();
void do_special4();
void do_special5();
void do_special6();
void do_special7();
void do_special8();

void create()
{
        set_name("諸岡渡", ({"npc09","wataru"}));
        set("age",16);
        set("title",HIC"【玉帝】"NOR);
        set("gender","男性");
        set("class","killer");
        set("str",30);
        set("cps",30);
        set("kar",30);
        set("spi",30);
        set("int",30);
        set("cor",30);
        set("attitude","herosim");
        set("max_kee",20000);
        set("combat_exp",8000000);
        set("max_force",30000);
        set("force",30000);
        set("force_factor",30);
        set_skill("dodge",200);
        set_skill("unarmed",200);
        set("chat_chance_combat",40);
        set("chat_msg_combat",({
        (: do_special1 :),
        (: do_special2 :),
        (: do_special3 :),
        (: do_special4 :),
        (: do_special5 :),
        (: do_special6 :),
        (: do_special7 :),
        (: do_special8 :),
        }));
        set_temp("apply/armor",130);
        set_temp("apply/damage",110);
        setup();
carry_object("/autoload/killer/ski_dream");
}

void do_special1()
  {
    object *enemy,target;
    int i;

        enemy=this_object()->query_enemy();
        i=sizeof(enemy);
        target=enemy[random(i)];
        message_vision( HIG
        "諸岡渡閉上雙眼，喃喃的唸著咒文，四周的天氣似乎起了很大的變化\n"NOR,target);
        message_vision(
        "諸岡渡睜開雙眼大喝道:\n\n"+HIR"                          ***"+HIG"七"+HIR"**"+HIG"鍵"+HIR"**"+HIG"守"+HIR"**"+HIG"護"+HIR"**"+HIG"神"+HIR"***"NOR+"\n",target);
        message_vision(HIC
        "天空中出現了七個異空間，朝你圍了過來，你以無處可逃！！！\n"NOR,target);
        message_vision(HBGRN"$N全身上下似乎全部被空間分開了！，你的存在已不具任何意義！\n"NOR,target);
        target->receive_wound("kee",800+random(500));
        COMBAT_D->report_status(target);

  }

void do_special2()
  {
    object *enemy,target;
    int i;

        enemy=this_object()->query_enemy();
        i=sizeof(enemy);
        target=enemy[random(i)];
        message_vision( HIR
        "諸岡渡撥撥額頭的頭髮輕笑說：像你這種笨傢伙，也敢跟我挑戰！！\n"NOR,target);
        message_vision(
        "諸岡渡舉起右手大喝一聲 :\n\n"+HIR"                         ***"+HIW"怒"+HIR"**"+HIW"龍"+HIR"**"+HIW"爆"+HIR"**"+HIW"炎"+HIR"**"+HIW"獄"+HIR"*** "NOR+"\n",target);
        message_vision(HIR"你只看到身體被一陣紅白交錯之炎火所圍繞!\n"NOR,target);
        message_vision(RED
           "$N全身上下陷入一片火海之中，肌肉都已呈焦黑 !\n"NOR,target);

        target->receive_wound("kee",800+random(500));
        COMBAT_D->report_status(target);

  }

void do_special3()
  {
    object *enemy,target;
    int i;

        enemy=this_object()->query_enemy();
        i=sizeof(enemy);
        target=enemy[random(i)];
        message_vision( HIR"
        諸岡渡大叫著 : 小心哦，我不會控制劍法的強度耶。。。。\n"NOR,target);
        message_vision("
        諸岡渡往你眼前的空氣一刺 !你好像看到甚麼東西從劍中鑽出來似的!\n\n"
        "你看不清楚眼前到底出現了甚麼東西 !\n"
        ,target);
        message_vision(HIR"一股如噴泉般的血$N身上不停的噴出 !!\n\n"NOR
                       HIY"那個速度極快的東西仍然不停的以高速在噬咬$N的身體!!\n"NOR
                       "一條速度極快的"+HIW" 白龍"NOR+"在$N身邊不斷的飛舞著 !! 咬著纏著可憐的$N!
        \n"NOR,target);
        target->receive_wound("kee",800+random(500));
        target->start_busy(2);
                COMBAT_D->report_status(target);

  }

void do_special4()
  {
    object *enemy,target;
    int i;
        enemy=this_object()->query_enemy();
        i=sizeof(enemy);
        target=enemy[random(i)];
        message_vision( HIR "
        諸岡渡撥撥額頭的頭髮輕笑說：像你這種笨傢伙，也敢跟我挑戰！！\n" NOR ,target);
        message_vision( "
        諸岡渡舉起右手大喝一聲 :\n\n"+HIY"                         ***"+HIM"靈"+HIY"**"+HIM"界"+HIY"**"+HIM"皇"+HIY"**"+HIM"龍"+HIY"**"+HIM"破"+HIY"*** "NOR+"\n",target);
        message_vision(HIG"你看到一條巨大的金黃色火焰龍朝你衝了過來 !\n"NOR,target);
        message_vision(GRN"
$N你卻絲毫動彈不得，是死亡的恐懼還是對諸岡渡的恐懼？因為你發現你已經沒救了！\n"NOR,target);

        target->receive_wound("kee",800+random(500));

                COMBAT_D->report_status(target);

  }

void do_special5()
  {
    object *enemy,target;
    int i;

        enemy=this_object()->query_enemy();
        i=sizeof(enemy);
        target=enemy[random(i)];
         message_vision( HIG
        "我主之力，上天之力，為我之劍，滅我之敵！！\n" NOR ,target);
        message_vision(
        "回過身見諸岡渡手中聚合光球\n\n"+HIW"                   ***乾    坤    六    絕    光    彈"+HIW"***"NOR+"\n",target);
        message_vision(HIC
        "你根本不知道發生了什麼事情，只覺得身體遭光球無情的襲擊，無處可逃！\n"NOR,target);
        message_vision(HBGRN"$N全身上下似乎被光球衝擊的體無完膚。\n"NOR,target);
                target->receive_wound("kee",800+random(500));
                COMBAT_D->report_status(target);

  }

void do_special6()
  {
    object *enemy,target;
    int i;

        enemy=this_object()->query_enemy();
        i=sizeof(enemy);
        target=enemy[random(i)];
        message_vision( HIR
        "諸岡渡閉上了雙眼，淡淡的說著。\n" NOR ,target);
        message_vision(
        "傳說中的禁咒！！\n"+HIR"                  ***死    黑    核    爆    裂    地    獄"+HIR"*** "NOR+"\n",target);
        message_vision(HIR"你只看到身體被一陣黑光交錯之炎火所圍繞!\n"NOR,target);
        message_vision(RED
           "$N全身上下陷入一片炎獄之中，肌肉早已蒸發殆盡!\n"NOR,target);

                target->receive_wound("kee",800+random(500));
                COMBAT_D->report_status(target);

  }

void do_special7()
  {
    object *enemy,target;
    int i;

        enemy=this_object()->query_enemy();
        i=sizeof(enemy);
        target=enemy[random(i)];
        message_vision( HIR"
        諸岡渡的六對翅膀都豎立了起來！！一股強大的氣充斥在諸岡渡四周。\n" NOR,target);
        message_vision("這是屬於我的最終殺招!\n\n"NOR,target);
        message_vision(HBMAG"      ----超     原     子     崩     壞     屴     起------\n"NOR,target);
        message_vision(HIG
"粉碎，粉碎，一切都化成粉碎！！！你正努力使自己回復原形！！\n"NOR,target);
        target->receive_wound("kee",800+random(500));
        target->start_busy(3);
                COMBAT_D->report_status(target);

  }

void do_special8()
  {
    object *enemy,target;
    int i;

        enemy=this_object()->query_enemy();
        i=sizeof(enemy);
        target=enemy[random(i)];
        message_vision( HIR "諸岡渡化成一道光芒，射往天際！！，天空起了很大的變化！！！\n" NOR ,target);
        message_vision( "\n\n"+HIY"                         ***"+HIC"天"+HIY"**"+HIR"空"+HIY"**"+HIB"之"+HIY"**"+HIG"劍"+HIY"*** "NOR+"\n",target);
        message_vision(HIG"你看到由天空降下一道巨大的金黃色的光柱!\n"NOR,target);
        message_vision(GRN"
           $N你卻絲毫動彈不得，是死亡的恐懼還是對神的恐懼？\n"NOR,target);
        target->receive_wound("kee",800+random(500));

                COMBAT_D->report_status(target);

  }

int accept_kill(object who)
{
who=this_player();
kill_ob(who);
command("charge "+who->query("id"));
command("perform fireforce.gold-fire");
command("cmd usekee "+who->query("id"));

    return 1;
}
int accept_fight(object who)
{
who=this_player();
kill_ob(who);
command("charge "+who->query("id"));
command("perform fireforce.gold-fire");
command("cmd usekee "+who->query("id"));

    return 1;
}
void init()
{
 ::init();
 add_action("do_cmd","cmd");
}

int do_cmd(string str){                 //ok by chan
 object who=this_player();
 object ob,wataru;
 ob=this_object();
 wataru=present( "wataru",environment(ob) );
 if(str=="askgod wataru" || str=="askgod wataru"){
write(HIY"諸岡渡罵說：「對我使用求神問卜，真是活得不耐煩了。」!!\n"NOR);
 command("perform fireforce.gold-fire");
 wataru->kill_ob(who);
 return 1;
                  }
}

void heart_beat()
{
        object env, mob = this_object();
        int i;

        set_heart_beat(1);

        if( query("kee") < 0)
            mob->die();

        if( query_temp("heal") < 50 )
        {
            if( query("force") < 10000)
            {
               mob->add("force",10000);
            }
            if( query("kee") < 10000 )
            {
                mob->receive_curing("kee",1000);
                mob->receive_curing("gin",300);
                mob->receive_curing("sen",300);
                mob->receive_heal("kee",1000);
                add_temp("heal", 1);
                tell_room(environment(), HIY+name()+"呼喚出小嵐"+
                     "小嵐慢慢的運用仙術幫你療傷.\n"+NOR);
            }
        }
        ::heart_beat();
}


int heal_up()
{
        if (!is_fighting() ) {
             message_vision (HIW"系統：戰鬥停止，$N回收中，。\n"NOR, this_object ());
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
	if(me->query("quest/start_game")< 10)
        {
        tell_object(users(),HIY"
	恭喜"HIW+me->query("name")+HIY"挑戰"HIG"『"HIR"第九層試煉塔"HIG"』"HIY"通過！！

	"HIW"希望"+me->query("name")+"能不負眾望，勇闖"HIG"『"HIY"第十層試煉塔"HIG"』"HIW"。
	"NOR);
	me->set("quest/start_game",10);
        destruct (this_object ());
	return ;
        }
	{
	tell_object(me,HIW"系統：你已經通過測試，系統不做任何更改。\n"NOR);
	destruct(this_object());
	:: die();
	}
}
