#include <ansi.h>
string ask_me(object who);
string do_mention(object who);
inherit NPC;
void do_specialatt();
void do_specialatt2();
void do_specialatt3();
void create()
{
	set_name("豪鬼", ({ "akuma"}) );
	set("gender", "男性" );
        set("age",35);
        set("str",50+random(30));
        set("cps",33+random(20));
        set("cor",36+random(30));
        set("per",39+random(30));
        set("int",31+random(30));
        set("spi",30+random(30));
        set("con",36+random(30));
        set("kar",30+random(40));
	set("long","相貌極粗曠, 英挺俊美, 心高氣傲的男子,\n"+
	"他是上代仙劍掌門的關門弟子, 也就是鄭士欣的師弟.\n");
        set("force",5000);
        set("max_kee",9000);
        set("kee",9000);
        set_skill("literate",10);
        set_skill("shasword",130);
        set_skill("shaforce",100);
        set_skill("sha-array",140);
        map_skill("array","sha-array");
        set_skill("sha-steps",100);
        set("max_force",5000);
        set_skill("array",120);
        set_skill("move",150);
        set_skill("force",100);
        set_skill("dodge",100);
        set_skill("parry",150);
        map_skill("dodge","sha-steps");
        map_skill("move","sha-steps");
        set_skill("sword",190);
        map_skill("force","shaforce");
        map_skill("sword","shasword");
        set_skill("unarmed",140);
        set_skill("shasword",190);
        map_skill("sword","shasword");
        map_skill("parry","shasword");
        set_skill("cure",100);
        set("force_factor",50);
        set("chat_chance_combat",60);
        set("chat_msg_combat",({
        (:exert_function,"swordkee":),
        (: do_specialatt3 :),
        }));  
        set("chat_chance",90);
 set("chat_msg", ({
                "你感覺豪鬼的強氣壓迫著你 .\n",
		"豪鬼邪著眼瞪著你 . \n",
		"豪鬼的身邊隱隱約約的冒出了一股金黃的氣 .\n",
                "豪鬼緊緊的壓住背後的劍 ..似乎是在忍耐甚麼 ..\n",
	}) );  
	set("inquiry", ([
		"鄭士欣": "他是我師兄 .\n",
                "bigcat" : "啊..啊...啊 ...師父 ..\n",
                "本門最強的人" : "我一定會比誰都強 ..",
		"比試": (: ask_me :),
		"關門弟子": "我是師父最後一個弟子 ..就這樣 ..",
                "無精打采" : "師父過逝前我答應過他老人家 ..不輕易動劍 ..",
	]) );
        
        set("combat_exp", 900000+random(900000));
        set("attitude", "heroism");
        set("title","劍士");
	setup();
        add_money("silver",4);
        carry_object("/u/u/urd/obj/firerobe.c")->wear();
	carry_object("/u/u/urd/obj/hasword.c")->wield();
}

string ask_me(object who)
{
        set_name("邪豪鬼" , ({"akuma"}));
        set("id","evil akuma");
        set("chat_chance_combat", 190),
	set("chat_msg_combat", ({
                (: do_specialatt2 :),
                "豪鬼低聲說道 : 別想跑 ...\n",
                (: exert_function,"swordkee" :),
	        "豪鬼喝道 : 哈哈哈 !好久沒有人敢來跟我較量較量了!\n",
	        (: do_specialatt3 :),
	        "豪鬼低聲說道 : 小鬼 ,對抗我的下場只有兩條路 ..生......死 !\n",
                "豪鬼全身散發出一股攝人的氣魄 !\n",
                (: do_specialatt :),
                "豪鬼大笑道 : 今天我要大大的殺一場 !\n",
	                       })); 
        kill_ob(this_player()); 
        set("inquiry", ([
                "bigcat" : (: do_mention :)
             ]));  
	message("vision",
		HIY " \n"
		"豪鬼兩眼透出一股詭異的紅光 .\n\n\n"
		"豪鬼低聲的說著 : 來吧 ..忠於基本劍法的正統的劍客 ..\n"
                "豪鬼說道 : 好久沒有殺人了 ...我可控制不住了 ..\n\n"
                "豪鬼慢慢的抽出了背後的豪劍 ..一把血紅劍身的豪劍 .\n"
		,environment(), this_object() );
        set("attitude","aggressive");
	set("pursuer", 1);
        set("force", 9000);
        set("max_force", 9000);
	set("combat_exp", 1000000+random(1000000));
        set("revealed", 1);
       message("vision","豪鬼左手朝天一指 ..手上隱隱約約的飄起了一陣煙\n"
           "煙散去時 ...豪鬼的手中多了一把仙劍"+HIC" 波仙藍劍"NOR+"\n",
      environment(), this_object());
        command("unwield sword");
        carry_object("/u/u/urd/obj/testsword.c")->wield();
        return HIC"你納命來吧!\n"NOR;
	 
 }
void do_specialatt()
{
        object *me,one;
        int i,before,after;
        me=this_player()->query_enemy();
        i=sizeof(me);
        one=enemy[random(i)];
        before = me->query("kee");
        message_vision( HIR "
        豪鬼大叫道 : 嘗嘗仙劍之極意 !接招了 !
        \n" NOR ,one);
        message_vision( " 
        豪鬼平舉劍喝道 :\n\n"+HIR"                         ***"+HIG"仙"+HIR"**"+HIG"氣"+HIR"**"+HIG"斬"+HIR"**"+HIG"虎"+HIR"**"+HIG"劍"+HIR"*** "NOR+"\n",one);
        message_vision(HIC"
        劍氣如海浪般的飛過來 !\n"NOR,one);
        message_vision(RED"
        $N全身的血管都被劍氣割破了 !\n"NOR,one);
        after = me->query("kee");
        one->receive_wound("kee",200+random(300));
         COMBAT_D->report_status(one);
return ;
}
void do_specialatt2()
{
        object *me,one;
        int i,before,after;
        me=this_player()->query_enemy();
        i=sizeof(me);
        one=enemy[random(i)];
        before = me->query("kee");
        message_vision( HIR "
        豪鬼大叫道 : 嘗嘗仙劍之極意 !接招了 !
        \n" NOR ,one);
        message_vision( "
        豪鬼斜舉劍喝道 :\n\n"+HIR"                         ***"+HIW"白"+HIR"**"+HIW"龍"+HIR"**"+HIW"飛"+HIR"**"+HIW"舞"+HIR"**"+HIW"呀"+HIR"*** "NOR+"\n",one);
        message_vision(HIR"
        你只看到眼前一片紅白交錯之光 !\n"NOR,one);
        message_vision(RED"
        $N全身上下佈滿著滿是像被凶獸啃掉了的大小不等的傷口 !\n"NOR,one);
        after = me->query("kee");
        one->receive_wound("kee",200+random(300));
         COMBAT_D->report_status(one);
return ;
}
void do_specialatt3()
{
	object *me,one;
	int i;
	me=this_player()->query_enemy();
	i=sizeof(me);
	one=enemy[random(i)];
	message_vision( HIR"
	豪鬼大叫著 : 嘗嘗仙劍之極意 !接招了 !
	\n\n" NOR,one);
	message_vision("						
	豪鬼迅速的往你眼前的空氣一刺 !你好像看到甚麼東西從劍中鑽出來似的 !\n\n"
	"你看不清楚眼前到底出現了甚麼東西 !\n"
	,one);
	message_vision(HIR"一股如噴泉般的血$N身上不停的噴出 !!\n\n"NOR
	               HIY"那個速度極快的東西仍然不停的以高速在噬咬$N的身體!!\n"NOR
	               "一條速度極快的"+HIW" 白龍 "NOR+"在$N身邊不斷的飛舞著 !! 咬著纏著可憐的$N!
	\n"NOR,one);
	one->receive_wound("kee",50+random(100));
	one->apply_condition("bleeding",10);
	one->start_busy(3);
	COMBAT_D->report_status(one);
return ;
}
string do_mention(object who)
{ 
      /*
        object *me,one;
        int i;
        me = this_player()->query_enemy();
        i = sizeof(me);
        one = enemy[random(i)]; 
        */
           if( this_player()->query_temp("passkill",1) )
           {
           message_vision("豪鬼大叫道 : 放你一馬你還敢惹我 !我宰了你!\n",this_player());
           set("attitude","aggressive");
           command("follow "+this_player()->name());
           kill_ob(this_player()); 
           }
	   else
           {
     message_vision("豪鬼慚愧\的說道: 師父 ,弟子錯了..\n",this_player());

           set("attitude", "heroism");
           command("surrender");
           command("follow none");
           this_player()->set_temp("passkill",1);
           }
	return HIC"........嗚...\n"NOR;
}
void die()
{
	object *me,one;
        int i;
        me = this_player()->query_enemy();
        i = sizeof(me);
        one = enemy[random(i)];
        one->set("sp_title","天下第一");
        message_vision(HIR"
  	最強的劍客豪鬼被打倒了!\n"NOR,
                one);
 	message("system",HIY"
 	最強的劍客豪鬼被"+one->name()+"打倒了 !\n\n"NOR,users());
 	message("system",HIY"
 	在此宣布 "+one->name()+"是天下最強 !!帶種的可以來砍他!!\n\n"NOR,users());
return ::die();
}
	                
