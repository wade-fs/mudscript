#include <ansi.h>
string ask_me(object who);
string do_angel(object who);
string do_mention(object who);
inherit NPC;
int j=0 ,k=1;
void create()
{
        set("title","天真活潑");
	set_name("魯協廉廉",({"rusie lenlen","rusie"}));
	set("gender", "男性" );
        set("age",14);
        set("str",99+random(30));
        set("cps",99+random(30));
        set("cor",99+random(30));
        set("per",99+random(30));
        set("int",99+random(99));
        set("spi",99+random(99));
        set("con",99+random(30));
        set("kar",99+random(30));
	set("long",
		"可憐的看著四周，好像快哭了。似乎在尋找什麼人....... \n");
        set("force",200);
        set("max_kee",9999);
        set("kee",9999);
        set_skill("literate",100);
        set_skill("shasword",230);
        set_skill("sword",230);
        set_skill("shaforce",150);
        set_skill("sha-steps",100);
        set("max_force",3000);
        set_skill("move",150);
        set_skill("force",200);
        set_skill("dodge",200);
        set_skill("parry",250);
        map_skill("dodge","sha-steps");
        map_skill("move","sha-steps");
        set_skill("sword",190);
        map_skill("force","shaforce");
        map_skill("sword","shasword");
        set_skill("unarmed",200);
        map_skill("sword","shasword");
        map_skill("parry","shasword");
        set_skill("cure",100);
        set("force_factor",10);
        set("chat_chance_combat",45);
        set("chat_msg_combat",({
        (:exert_function,"swordkee":),
        (: this_object(), "special_att3" :),
        }));  
        set("chat_chance",10);
        set("chat_msg", ({
                "洋子，洋子，妳在哪裡？ \n",
		"啊。。。。魯協跌倒了。。。。 \n",
                "你知道洋子在哪裡嗎？魯協一雙水汪汪的眼睛正純真的著你。。。\n",
	}) );  
	set("inquiry", ([
		"洋子": "人家跟她出來玩，但是跟丟了：~~\n",
                "魯協" : "就是我呀！！你要陪我去找洋子嗎？\n",
                "修耐達" : "人家不知道嘛！：~~~~~\\n",
		"變身": (: ask_me :),
		"仙劍": "鄭老師有親自教我劍術哦。。。。\n",
                "可愛" : "洋子比我更可愛呀！我最喜歡她了！！\n",
	]) );
        
        set("combat_exp", 500000);
        set("attitude", "heroism");
carry_object("/open/killer/obj/fire_s.c");
	setup();
}

string ask_me(object who)
{
        set("title","暗黑魔法師");
        set_name("修耐達" , ({"dark magic","ds"}));
        set("long",
           "相貌極為英挺俊美 ,心高氣傲的男子.他是傳說中的超級魔法師，
具有無敵的傳說，對於女孩子也是具有超級的吸引力。 \n");
        set("chat_msg", ({
                HIG + "洋子，洋子，妳在哪裡？....我愛妳！！\n" + NOR,
		HIG + "嘿。。。。小姐你有空嗎？我們去喝咖啡。\n" + NOR,
		HIG + "哈！！我是宇宙無敵天下第一的修耐達啦！！\n" + NOR,
                HIG + "妳望著DS的眼睛，妳發現妳快情不自盡的愛上他。\n" + NOR,
	}) );  
        set("chat_chance_combat",75);
	set("chat_msg_combat", ({
                (: this_object(), "special_att2" :),
                HIG + "DS說：呆子，讓你看看大爺我的魔法！！！\n" + NOR,
                (: exert_function,"swordkee" :),
	        HIG + "DS喝道 : 哈哈哈 !不要以為大爺我不會劍術！！看招！！\n" + NOR,
	        (: this_object(), "special_att4" :),
	        HIG + "DS說道 : 小鬼 ,對抗我的下場只有一條路，死！！\n",
                "DS全身佈滿令人難以相信的光芒 !\n" + NOR,
                (: this_object(), "special_att" :),
                HIG + "DS大笑道 : 真幸運，你可以看到我的超級殺招！！!\n" + NOR,
	                       })); 
        kill_ob(this_player()); 
        set("inquiry", ([
                "洋子" : (: do_mention :),
                "變身" : (: do_angel :),
             ]));  
	message("vision",
		HIY + " \n"
		"DS兩眼透出一股詭異的紅光 .\n\n\n"
		"DS不屑的說著 : 小鬼你也想殺我？ ..\n"
                "DS說道 : 好久沒有動手了 ...好吧！送你一程到地獄去 ..\n\n"
                "DS慢慢的抽出的火魔劍 ..一把血紅劍身的魔劍 .\n"
		,environment(), this_object() );
        set("attitude","friendly");
	set("pursuer", 1);
        set("bellicosity",500);
        set("force", 9999);
        set("max_force", 9999);
	set("combat_exp", 9999999+random(9999999));
        set("revealed", 1);
        message("vision","DS左手一探，手中多了一把魔劍"+HIC + " 幻炎火魔劍" + NOR+"\n",
        environment(), this_object());
command("wield iceger");
        return HIC + "你納命來吧!\n" + NOR;
 }

string do_angel (object who)
{
        set("title","暗黑墮天使");
        set_name("路西法" , ({"dark angel","rucy"}));
        set("long",
           "天啊！！你不禁懷疑你的眼睛與你的存在。在你眼前的他，居然擁有六對翅膀。
難不成他就是傳說中的大天使，站在所有天使的頂端，具有無比神力與魔力的路西法！。\n");
        set("chat_msg", ({
                HIG + "哈。。。我又再次出現了！！人類們等死吧\n" + NOR,
		HIG + "接招吧！！神的懲罰---天空ソ劍！！！\n" + NOR,
		HIG + "嘿。。。。誰要是敢對洋子下手你就完了！！\n" + NOR,
                HIG + "閉上你的眼睛吧！！早死晚死都是要死！！！\n" + NOR,
	}) );  
        set("chat_chance_combat",100);
	set("chat_msg_combat", ({
                (: this_object(), "special_att5" :),
                HIG + "你眼前一花，你已失去路西法的身影，只聽到喃喃咒文聲。\n" + NOR,
                (: this_object(), "special_att6" :),
	        HIG + "你感覺到渾身火熱了起來，四周似乎起了不一樣的變化！\n" + NOR,
	        (: this_object(), "special_att7" :),
	        HIG + "壓力，強大的重壓。你感覺到難以置信的壓力！！\n" + NOR,
                (: this_object(), "special_att8" :),
                HIG + "這是神最終的懲罰！！！你是無處可逃的！！！\n" + NOR,
	                       })); 
        kill_ob(this_player()); 
	message("mud",
		HIY + " \n"
		"哈。。愚蠢的人類！居然使我黑暗墮天使路西法再次重生！！\n\n"
		"所有幻想空間的玩家們，洗乾淨脖子吧！！\n"
"來自神的懲罰就要出現了---天空ソ劍！！\n\n"+this_player()->query("name")+"接招吧！！" + NOR,users() );
        set("attitude","heroism");
	set("pursuer", 1);
        set("bellicosity",600);
        set("force",99999);
        set("max_force", 99999);
        set("max_gin",9999);
        set("eff_gin",9999);
        set("gin",9999);
        set("max_kee",99999);
        set("eff_kee",99999);
        set("kee",99999);
        set("max_sen",9999);
        set("eff_sen",9999);
        set("sen",9999);
	set("combat_exp", 99999999);
        set("revealed", 1);
        message("vision","路西法左手一探，手中多了一把魔劍"+HIC + " 幻炎火魔劍" + NOR+"\n",
        environment(), this_object());
        return HIC + "你納命來吧!\n" + NOR;
}

int special_att()
{
        object *me,one;
        int i,before,after;
        me=this_player()->query_enemy();
        i=sizeof(me);
        one=enemy[random(i)];
        before = me->query("kee");
        message_vision( HIG 
        "DS閉上雙眼，喃喃的唸著咒文，四周的天氣似乎起了很大的變化\n" + NOR ,one);
        message_vision( 
        "DS睜開雙眼大喝道 :\n\n"+HIR + "                      ***"+HIG + "七"+HIR + "**"+HIG + "鍵"+HIR + "**"+HIG + "守"+HIR + "**"+HIG + "護"+HIR + "**"+HIG + "神"+HIR + "*** " + NOR+"\n",one);
        message_vision(HIC
        "天空中出現了七個異空間，朝你圍了過來，你以無處可逃！！！\n" + NOR,one);
        message_vision(HBGRN + "$N全身上下似乎全部被空間分開了！，你的存在已不具任何意義！\n" + NOR,one);
        after = me->query("kee");
        one->receive_wound("kee",99999+random(9999));
         COMBAT_D->report_status(one);
        return 1;
}

int special_att2()
{
        object *me,one;
        int i,before,after;
        me=this_player()->query_enemy();
        i=sizeof(me);
        one=enemy[random(i)];
        before = me->query("kee");
        message_vision( HIR 
        "DS撥撥額頭的頭髮輕笑說：像你這種笨傢伙，也敢跟我挑戰！！\n" + NOR ,one);
        message_vision( 
        "DS舉起右手大喝一聲 :\n\n"+HIR + "                         ***"+HIW + "怒"+HIR + "**"+HIW + "龍"+HIR + "**"+HIW + "爆"+HIR + "**"+HIW + "炎"+HIR + "**"+HIW + "獄"+HIR + "*** " + NOR+"\n",one);
        message_vision(HIR + "你只看到身體被一陣紅白交錯之炎火所圍繞 !\n" + NOR,one);
        message_vision(RED
           "$N全身上下陷入一片火海之中，肌肉都已呈焦黑 !\n" + NOR,one);
        after = me->query("kee");
        one->receive_wound("kee",2000+random(1300));
         COMBAT_D->report_status(one);
        return 1;
}
int special_att3()
{
	object *me,one;
	int i;
	me=this_player()->query_enemy();
	i=sizeof(me);
	one=enemy[random(i)];
	message_vision( HIR + "
	魯協大叫著 : 小心哦，我不會控制劍法的強度耶。。。。\n" + NOR,one);
	message_vision("						
	魯協往你眼前的空氣一刺 !你好像看到甚麼東西從劍中鑽出來似的 !\n\n"
	"你看不清楚眼前到底出現了甚麼東西 !\n"
	,one);
	message_vision(HIR + "一股如噴泉般的血$N身上不停的噴出 !!\n\n" + NOR
	               HIY + "那個速度極快的東西仍然不停的以高速在噬咬$N的身體!!\n" + NOR
	               "一條速度極快的"+HIW + " 白龍 " + NOR+"在$N身邊不斷的飛舞著 !! 咬著纏著可憐的$N!
	\n" + NOR,one);
	one->receive_wound("kee",500+random(9999));
	one->apply_condition("bleeding",10);
	one->start_busy(2);
	COMBAT_D->report_status(one);
	return 1;
}
int special_att4()
{
        object *me,one;
        int i,before,after;
        me=this_player()->query_enemy();
        i=sizeof(me);
        one=enemy[random(i)];
        before = me->query("kee");
        message_vision( HIR + "
        DS撥撥額頭的頭髮輕笑說：像你這種笨傢伙，也敢跟我挑戰！！\n" + NOR ,one);
        message_vision( "
        DS舉起右手大喝一聲 :\n\n"+HIY + "                         ***"+HIM + "靈"+HIY + "**"+HIM + "界"+HIY + "**"+HIM + "皇"+HIY + "**"+HIM + "龍"+HIY + "**"+HIM + "破"+HIY + "*** " + NOR+"\n",one);
        message_vision(HIG + "你看到一條巨大的金黃色火焰龍朝你衝了過來 !\n" + NOR,one);
        message_vision(GRN + "
           $N你卻絲毫動彈不得，是死亡的恐懼還是對DS的恐懼？!，但已不重要！！，因為你發現你已經沒救了！\n" + NOR,one);
        after = me->query("kee");
        one->receive_wound("kee",5000+random(-1));
         COMBAT_D->report_status(one);
        return 1;
}

int special_att5()
{
        object *me,one;
        int i,before,after;
        me=this_player()->query_enemy();
        i=sizeof(me);
        one=enemy[random(i)];
        before = me->query("kee");
        message_vision( HIG 
        "我主之力，上天之力，為我之劍，滅我之敵！！\n" + NOR ,one);
        message_vision( 
        "回過身見路西法手中聚合光球\n\n"+HIW + "                   ***"+HBMAG + "乾    坤    六    絕    光    彈"+HIW + "***" + NOR+"\n",one);
        message_vision(HIC
        "你根本不知道發生了什麼事情，只覺得身體遭光球無情的襲擊，無處可逃！\n" + NOR,one);
        message_vision(HBGRN + "$N全身上下似乎被光球衝擊的體無完膚。\n" + NOR,one);
        after = me->query("kee");
        one->receive_wound("kee",9999+random(9999));
         COMBAT_D->report_status(one);
        return 1;
}

int special_att6()
{
        object *me,one;
        int i,before,after;
        me=this_player()->query_enemy();
        i=sizeof(me);
        one=enemy[random(i)];
        before = me->query("kee");
        message_vision( HIR 
        "路西法閉上了雙眼，淡淡的說著。\n" + NOR ,one);
        message_vision( 
        "傳說中的禁咒！！\n"+HIR + "                  ***"+HBMAG + "死    黑    核    爆    裂    地    獄"+HIR + "*** " + NOR+"\n",one);
        message_vision(HIR + "你只看到身體被一陣黑光交錯之炎火所圍繞 !\n" + NOR,one);
        message_vision(RED
           "$N全身上下陷入一片炎獄之中，肌肉早已蒸發殆盡!\n" + NOR,one);
        after = me->query("kee");
        one->receive_wound("kee",20000+random(-1));
         COMBAT_D->report_status(one);
        return 1;
}

int special_att7()
{
	object *me,one;
	int i;
	me=this_player()->query_enemy();
	i=sizeof(me);
	one=enemy[random(i)];
	message_vision( HIR + "
	路西法的六對翅膀都豎立了起來！！一股強大的氣充斥在路西法四周。\n" + NOR,one);
	message_vision("這是屬於我的最終殺招!\n\n" + NOR,one);
	message_vision(HBMAG + "      ----超     原     子     崩       壞      屴     起------" + NOR,one);
        message_vision(HIG + "粉碎，粉碎，一切都化成粉碎！！！你正努力使自己回復原形！！\n" + NOR,one);
	one->receive_wound("kee",50000+random(30000));
	one->apply_condition("bleeding",10);
	one->start_busy(3);
	COMBAT_D->report_status(one);
	return 1;
}

int special_att8()
{
        object *me,one;
        int i,before,after;
        me=this_player()->query_enemy();
        i=sizeof(me);
        one=enemy[random(i)];
        before = me->query("kee");
        message_vision( HIR + "路西法化成一道光芒，射往天際！！，天空起了很大的變化！！！\n" + NOR ,one);
        message_vision( "\n\n"+HIC + "                         ***"+HIM + "天"+HIY + "**"+HIR + "空"+HIY + "**"+HIB + "之"+HIY + "**"+HIG + "劍"+HIY + "*** " + NOR+"\n",one);
        message_vision(HIG + "你看到由天空降下一道巨大的金黃色的光柱 !\n" + NOR,one);
        message_vision(GRN + "
           $N你卻絲毫動彈不得，是死亡的恐懼還是對神的恐懼？\n" + NOR,one);
        after = me->query("kee");
        one->receive_wound("kee",99999+random(99999));
         COMBAT_D->report_status(one);
        return 1;
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
           message_vision("DS大叫道 : 放你一馬你還敢惹我 !我宰了你!\n",this_player());
           set("attitude","aggressive");
           command("follow "+this_player()->name());
           kill_ob(this_player()); 
           }
	   else
           {
           message_vision("洋子，我愛你！！ ..\n",this_player());
           set("attitude", "heroism");
           command("surrender");
           command("follow none");
           this_player()->set_temp("passkill",1);
           }
	return HIC + "........嗚...\n" + NOR;
}
void die()
{
	object *me,one;
        int i;
        me = this_player()->query_enemy();
        i = sizeof(me);
        one = enemy[random(i)];
        if (this_object()->query("name") == "ds")
        {
          one->set("sp_title","天下第一");
          message_vision(HIR + "傳說中的魔人DS被打倒了!\n" + NOR,one);
   	  message("system",HIY + "傳說中的魔人DS被"+one->name()+"打倒了 !\n\n" + NOR,users());
 	  message("system",HIY + "在此宣布 "+one->name()+"是天下最強 !!帶種的可以來砍他!!\n\n" + NOR,users());
        }
        if (this_object()->query("name") == "rucy")
        {
          message_vision(HIR + "你以為我被你打倒了嗎？\n" + NOR,one);
          message_vision(HIR + "別忘了，我是神的代理人！！我會再次出現的！！\n" + NOR,one);
  	  message("system",HIY + "
 	  暗黑大天使路西法被"+one->name()+"以生命將其封印住了 !\n\n" + NOR,users());
          this_player()->move("/open/death/start");
        }
return ::die();
}
	                
