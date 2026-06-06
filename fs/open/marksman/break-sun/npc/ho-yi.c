#include <ansi.h>
#include <combat.h>
#include "marksman.h"
inherit NPC;
inherit F_MASTER;
string sun9();
string sun10();
string sun11();
void create()
{
        set("class", "marksman");
        set_name("后羿", ({ "ho yi", "ho", "yi" }) );
        set("title","東夷族首領");
        set("nickname",HIW + "箭" + HIY + "神" + NOR);
        set("gender", "男性");
        set("max_kee",5000);
        set("age", 53);
        set("attitude", "heroism");
        set("long","夏代部落東夷族有窮氏首領，傳聞為天帝指派至地上界解救凡人的神祇，身負高超箭技，
正為了天上的「太陽」而煩惱不已...\n");
        set("str", 18);
        set("cps", 30);
        set("per", 10);
set("cor",30);
set("int", 40);
set("kar", 16);
set("combat_exp",2000000);
set("bellicosity",5000);
set("force",8000);
set("max_force",8000);
set("max_atman",5000);
set("atman",5000);
set("force_factor",30);
set("score",200000);
set("break-sun",2);
set_skill("force",300);
set_skill("archery",320);
set_skill("god-shooting",100);
set_skill("magic",120);
set_skill("move",120);
set_skill("parry",120);
set("functions/ten_kee/level",100);
set("functions/super-shooting/level",100);
set("functions/m-archery/level",100);
set("functions/break-sun/level",100);
        set_skill("dodge",170);
        set_skill("literate",140);
        set_skill("unarmed",120);
        set_skill("iceforce",100);
        set("no_lyssa",1);
        set_skill("rain-steps",100);
        set_skill("riding",180);
        map_skill("force", "iceforce");
        map_skill("dodge", "rain-steps");
        map_skill("parry", "rain-steps");
        map_skill("archery","god-shooting");
        map_skill("move","rain-steps");
        create_family("射日派", 2, "創始人");
        setup();
        carry_object("/open/marksman/break-sun/obj/water-arrow");
        carry_object(C_OBJ"/dragon_bow")->wield();   
        set("inquiry", ([
			"太陽":  (: sun9 :),
			"絕世箭法":  (: sun10 :),
			"不過":  (: sun11 :),
        ]));
        add_money("coin",1);
}

void init()
{
 add_action("do_shoot","shoot");
 add_action("do_answer","answer");
::init();
}


int accept_kill(object ob)
{
 command("say 老夫最近沒練武了，那就來動一動吧!");
 command("say 死吧!!");
 command("cmd holdup arrow with bow");
 kill_ob(ob);
command("perform archery.break-sun");
command("supershoot");
return 1;
}
int accept_fight(object ob)
{
command("say 那好吧!!老夫就來會會你");
command("cmd holdup arrow with bow");
 fight_ob(ob);
command("perform archery.break-sun");
command("supershoot");
return 1;
}

string sun9()
{
 object me = this_player();
 int k;
 k = me->query_temp("ask-break-sun");
 if(!me) return"";
 if(me->query("family/family_name") != "射日派") return "聽不懂啦!!";
 if(k>8) return "我的箭法很強喔!!";
 if(me->query("break-sun")) return "我已經教過你了!!";
 if(!k || k<8) return "我又不是太陽，你找我做啥!?";
 else {
       command("snort");
       command("say 你也是來嘲笑我的嗎？如果是的話，那就儘管笑吧，但最好先看看我的絕世箭法！");
       me->set_temp("ask-break-sun",9);
      }
  return "";
}

string sun10()
{
 object me = this_player();
 int k;
 k = me->query_temp("ask-break-sun");
 if(!me) return"";
 if(me->query("family/family_name") != "射日派") return "聽不懂啦!!";
 if(k>9) return "我的箭法很強喔!!";
 if(me->query("break-sun")) return "我已經教過你了!!";
 if(!k || k<9) return "對啊，那是我的得意技!!";
 else {
       command("snort");
       command("say 嘿嘿～這招我取名為破日驚天，其實兩年前天上是有十一顆太陽的，被我這絕招給射下一顆，不過......");
       me->set_temp("ask-break-sun",10);
      }
  return "";
}

string sun11()
{
 object me = this_player();
 int k;
 k = me->query_temp("ask-break-sun");
 if(!me) return"";
 if(me->query("family/family_name") != "射日派") return "聽不懂啦!!";
 if(k>10) return "去找老張吧!!";
 if(me->query("break-sun")) return "事情都解決啦，沒什麼不過啦!!";
 if(!k || k<10) return "還沒輪到你問!!";
 else {
       command("think");
       command("say 
要擊落太陽，箭枝必需熾熱難熔才行，而製作方法不是我這一介武夫能通曉的，
村裡的張鐵匠是兵器高手，只有他才能做出耐熱的箭。");
       me->set_temp("ask-break-sun",11);
      }
  return "";
}

int accept_object(object me,object ob)
{
 int k;
 me = this_player();
 k = me->query_temp("ask-break-sun");
 if(!ob || !me) return 0;
 if(!k || k!=19) command("say 太好了!!");
 else if(k == 19 && ob->query("id") == "color-arrow")
 {
  command("wa");
  command("say 唉...我今年也五十好幾了，要在懸崖上使破日驚天真的是非常困難的一件事，不如我將破日驚天傳授給你，由你來將太陽射下好了！不知你意下如何？（answer y/n)。");
  me->set_temp("ask-break-sun",20);
  destruct(ob);
  } else command("say 太好了!!");
 return 1;
}

int do_answer(string str)
{
 object me;
 int k;
 me = this_player();
 k = me->query_temp("ask-break-sun");
 if(!me || !str) return 0;
 if(!k || k!=20) command("say 我有叫你回答嗎?");
 else if(k == 20)
       {
	    if(str == "yes" || str == "y")
		{
		command("say 好！那你看清楚了，弓要這樣握，箭要這樣架‧‧‧！＠＃＄％︿＆‧‧‧");
        message_vision(HIW + "\n\n就在后羿解釋如何使出破日驚天的時候，五道不尋常的彩光注入$N的身體。\n\n" + NOR,me);
        command("say 那五道光芒是我的好朋友，都靠它們的力量才有我的破日驚天呢！");
		command("say 看來它們也接受你了。就試著運用這五道彩光來射日吧！(shoot sun)");
		me->set_temp("ask-break-sun",21);
		}
        else if(str == "no" || str == "n")
        {
         command("sigh");
		 command("say 真遺憾啊，我們就當作沒見過面吧!!");
		 me->set_temp("ask-break-sun",200);
        } else command("say 你到底想回答甚麼!? 我聽不懂啦!!");
	   }
 return 1;
}

int do_shoot(string str)
{
 object me;
 int k;
 me = this_player();
 k = me->query_temp("ask-break-sun");
 if(!me || !str) return 0;
 if(!k || k!=21) command("say 沒事不要射那麼多啦，身體會變虛喔!!");
 if(me->query_temp("shooting-sun"))
 {
   command("say 連續射那麼多次會馬上風喔，休息一下吧!!");
   return 1;
 }
 else if(k==21 && str == "sun")
 {
  message_vision(HIY + "\n$N運起五道彩光，聚集成箭，架上弓之後，往你頭上斗大的太陽射去......\n" + NOR,me);
  me->set_temp("shooting-sun",1);
  call_out("do_shootsun",5,me);
 } else command("你想射在哪裡??");
 return 1;
}

int do_shootsun()
{
 object me;
 int j;
 me = this_player(); 
 j = me->query_skill("archery");
 remove_call_out("do_shootsun");
 if(!j) j=2;
 j = random(j);
 me = this_player();
 me->delete_temp("shooting-sun");
 if(j>99)
 {
  message_vision(HIY + "\n$N瞄準的那顆太陽被射中之後瞬間墜下，天空霎時少了些許\陽光......\n" + NOR,me);
  me->add_temp("sun-down",1);
  me->receive_damage("gin",100+(me->query("max_gin"))/2);
  me->receive_damage("kee",100+(me->query("max_kee"))/2);
  me->receive_damage("sen",100+(me->query("max_sen"))/2);
  COMBAT_D->report_status(me);
 }else{
       message_vision(HIR + "\n$N的彩光之箭迅速飛向被瞄準的太陽，但是彩光的威力不及太陽的能量，竟被反射回來，將$N擊落山下......\n" + NOR,me);
	   me->move("/open/marksman/break-sun/mount01");
       me->unconcious();
      }
 if(me->query_temp("sun-down") > 8)
 {
   me->set("title","$HBBLU$$HIB$破$HIY$日$HIC$驚$BLK$天$HIW$傳人$NOR$");
   me->set("break-sun",1);
   me->delete_temp("ask-break-sun");
   me->delete_temp("sun-down");
/*   message_vision(HIG + "
 ～亙古歌謠，傳頌英雄史蹟\n
    九陽殞落，先民為之歡呼～\n
	
" + HIC + "遠古英雄" + HIB + "‧" + HIR + "箭" + HIY + "神" + HIW + "后羿" + HIM + "曾說過：" + HIY + "\n
　　　　　　　　　　　　"+me->query("name")+"為吾等解決久旱不雨之苦\n

　　　　　　　　　　　　為表謝意，特將吾畢生絕學\n

　　　　　　　　　　　　　　" + HIM + "《" + HBYEL + "" + HIB + "破" + NOR + "　" + HBBLU + "" + HIY + "日" + NOR + "　" + HBGRN + "" + HIW + "驚" + NOR + "　" + BRED + "" + HIC + "天" + NOR + "" + HIM + "》\n

　　　　　　　　　　　　" + HIY + "傾囊相授於彼！！\n\n" + NOR,me);*/
   tell_object(users(),HIG + "
 ～亙古歌謠，傳頌英雄史蹟\n
    九陽殞落，先民為之歡呼～\n
	
" + HIC + "遠古英雄" + HIB + "‧" + HIR + "箭" + HIY + "神" + HIW + "后羿" + HIM + "曾說過：" + HIY + "\n
　　　　　　　　　　　　"+me->query("name")+"為吾等解決久旱不雨之苦\n

　　　　　　　　　　　　為表謝意，特將吾畢生絕學\n

　　　　　　　　　　　　　　" + HIM + "《" + HBYEL + "" + HIB + "破" + NOR + "　" + HBBLU + "" + HIY + "日" + NOR + "　" + HBGRN + "" + HIW + "驚" + NOR + "　" + BRED + "" + HIC + "天" + NOR + "" + HIM + "》\n

　　　　　　　　　　　　" + HIY + "傾囊相授於彼！！\n\n" + NOR);
   command("say 我感到村外魔法之力即將油盡燈枯\，你應該不是我們這時代的人，趕快回去吧，再不走就太遲了！");
   command("say 如果忘記怎麼使用我教你的招式，可利用(help 破日驚天)來查看，再見了!!");
   me->move("/open/marksman/break-sun/transmit-old");
   me->set_temp("break-sun/transmit",2);
 }
   
 return 1;
}
