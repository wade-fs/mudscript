#include <ansi.h>
#include <combat.h>
#include "/open/open.h" 
inherit NPC;
inherit SSERVER;
object user;
string do_check1();
void create()
{
        set_name("小水滴",({"Hero Monk","hero"}));
        set("long","
三百年前，為對抗天下無敵的魔也佛，當時的天子聚齊武林正道最頂尖的
五大派，以各派武學精華，共同研發出驚世駭俗的武學『英雄真經』，並且以
灌頂、傳功\等不同方式，將各派絕頂高手的功\力盡傳給一天賦過人的少林弟子
，自此以後，此弟子法號即為英雄和尚。
\n" + NOR);
        set("attitude", "friendly");
        set("chat_chance", 10);
        set("gender","男性");
        set("combat_exp",20000000);
        set("score",9000000);
        set("sec_kee","god");
        set("max_s_kee",2000);
        set("s_kee",7000);
        set("age",318);
        set("no_kill",1);
        set("class","blademan");
        set("family/family_name","金刀門");
        set("title",HIY + "初代" + HIR + "『" + HIC + "英雄真經" + HIR + "』" + HIW + "傳人" + NOR);
        set("nickname",HIM + "英雄和尚" + NOR);
        set("potential",8000000);
        set("max_gin",100000);
        set("max_kee",950000);
        set("max_sen",100000);
        set("bellicosity",99999);
        set("max_force",96000);
        set("force",800000);
        set("max_atman",40000);
        set("max_mana",40000);
        set("atman",70000);
        set("mana",70000);
        set("force_factor",70);
        set("str",50);
        set("cor",50);
        set("cps",50);
        set("int",50);
        set("con",50);
        set("per",50);
        set("spi",50);
        set("kar",50);
        set("mk-blade",1);
        set_skill("hero",150);
        set_skill("unarmed",150);
        set_skill("superforce", 300);
        set_skill("literate",150);
        set_skill("winter-steps",150);
        set_skill("dodge",150);
        set_skill("parry",150);
        set_skill("force",500);
        map_skill("unarmed","hero");
        map_skill("parry","hero");
        map_skill("force", "superforce");
        map_skill("dodge", "winter-steps");
        set("functions/gold-dest/level",100);
        set("functions/fast-dest/level",100);
        set("functions/mk-blade/level",100);
        set("functions/busy/level",100);
        set("functions/powerup/level",100);
        set("functions/enforceup/level",100);
        set("functions/addbasic/level",100);
        set("functions/addblade/level",100);
        set("functions/badup/level",100);
        set("functions/hurtkee/level",100);
        set("functions/losehurt/level",100);
        set("functions/healup/level",100);
        set("functions/blood/level",150);
        set("functions/tengin/level",100);
        set("functions/bluesea/level",150);
        set("functions/black/level",150);
        set("functions/goldsun/level",150);
        set("functions/ice/level",150);
        set("functions/hwa_je/level",150);
        set("functions/purple/level",150);
        set("functions/gwe_jen/level",150);
        set("functions/green/level",150);
        set("env/superforce","green");
        set("env/連擊","YES");
        set("inquiry", ([
            "魔界金典"  :       (: do_check1 :),
            "英雄真經"  :       "那是五位恩師教我的。",
            "英雄新經"  :       "似乎不怎樣嘛。",

        ]) );
        setup();
        carry_object("/open/magic_palace/obj/icer");
        carry_object("/open/capital/obj/hero_hands");
}

void init()
{
   add_action("do_test","accept_test");
}
int do_test(string str)
{
user = this_player();
if(!str)
{
if(present("New_Hero Book",user))
{
   message_vision(HIW + "咦!?$N身上有英雄新經，是英雄新經傳人嗎!!很好，就看看新經真經哪個強吧!!\n" + NOR,user);
   user->start_busy(2);
   call_out("do_check",1,user); 
}else{
   message_vision(HIW + "$N看來也是武學行家，試著在英雄真經下撐過七回合吧!!\n" + NOR,user);
   user->start_busy(2);
   call_out("do_check",1,user); 
     }
}
     return 1;
}

void do_check()
{
	command("wear hands");
        command("sacrifice");
	this_object()->set_temp("hero_test",1);
	this_object()->fight_ob(this_player());
        this_player()->fight_ob(this_object());
}

string do_check1()
{
object ob1,ob2;
user = this_player();
ob1=present("New_Hero Book",user);
ob2=present("Gold_Magic Book",user);

if(present("New_Hero Book",user) && present("Gold_Magic Book",user) && !present("Real_Hero Book") && user->query_temp("kill_hero") )
{
new("/open/magic_palace/obj/real_book.c")->move(user);
call_out("do_check2",1,user);
return "小水滴說:『想不到魔也佛真的敗了，那麼貧僧也可以放心的去了，這本『英雄真經』就交給施主了。』\n";
}

if(present("New_Hero Book",user) && present("Gold_Magic Book",user) && !user->query_temp("kill_hero") )
{
destruct(ob1);
destruct(ob2);
message_vision(HIB + "小水滴說:『" + HIW + "你這廢材，一隻都沒打，還敢跟我問這是什麼書，沒收！" + HIB + "』\n" + NOR,user);
user->move("/open/wiz/courthouse");
user->set("startroom","/open/wiz/courthouse");
write_file("/log/magic_palace/destruct_books",sprintf("%s(%s) 被沒收兩本書於 %s\n",user->name(1),user->query("id"),ctime(time())));	    
return "小水滴說:『沒想到來了個天兵。』\n";
}

}

void do_check2()
{
user = this_player();
message_vision(HIB + "小水滴說:『" + HIW + "希望施主將" + HIC + "真經" + HIW + "、" + HIC + "新經" + HIW + "和" + HIY + "魔典" + HIW + "投入斷陽峰的烈日中焚燬(throw to sun)，畢竟這等驚世駭俗的武學是不該存在於世上的。』\n\n" + NOR,user);
call_out("do_check3",1,user); 
}

void do_check3()
{
user = this_player();
message_vision(HIM + "說罷，" + HIC + "英雄和尚" + HIM + "-" + HIB + "小水滴" + HIM + "便圓寂了...\n\n" + NOR,user);
user->set_temp("can_throw",1);
destruct(this_object());
}

void do_get_heart_beat()    //不知為何，在heart_beat裡remove_call_out("do_check")後會沒心跳 所以加這一行
{
        set_heart_beat(1);
}

void heart_beat()
{
object me,*target,victim,*player,eq1,*tester,room;
int i,j,b,kee,mkee,sen,msen,gin,mgin,chance,ekee,egin,esen,killair;
chance=random(100);
me=this_object();
room = environment(me);
kee=me->query("kee");
mkee=me->query("max_kee");
sen=me->query("max_sen");
msen=me->query("max_sen");
gin=me->query("max_gin");
mgin=me->query("max_gin");

if(me->is_fighting() || me->is_killing())
 {
if(living(me))
{
me->add_temp("hero_test",1);
if(me->query_temp("hero_test") > 7)
{
	tester = me->query_enemy();
	i=sizeof(tester);
	for(b=0;b<i;b++)
	{
	if(tester[b]->query("kee") > (tester[b]->query("max_kee"))/5)
        {
        message_vision(HIM + "
        
        小水滴說道:" + HIW + "『" + HIG + "很好，你果然有資格和魔也佛交手。" + HIW + "』\n\n" + NOR,tester[b]);
        tester[b]->delete_busy();
        tester[b]->set_temp("can_fight_final",1);
        }else{
        message_vision(HIM + "
        
        小水滴說道:" + HIW + "『" + HIR + "這點微末功\夫還想殺佛也魔，自不量力，$N再回去練十年吧!!\n\n" + NOR,tester[b]);
             }
        }     
	me->remove_all_killer();
        me->delete_temp("hero_test");
        call_out("do_get_heart_beat",1,me); 
        remove_call_out("do_check");
}
target=me->query_enemy();
i=sizeof(target);

 if(random(100) < 40 && !me->query_temp("unconcious")) //回精氣神
  {
    if(kee < mkee || sen < msen || gin < mgin)
    {
message_vision(HIB + "$N運起少林寺最高內功\心法" + HIW + "『" + BRED+HIY + "本來無一物" + NOR + "" + HIW + "』" + HIB + "
內勁變得如黑洞般深不可測，原本散發的凜冽鬥氣剎那間完全消失，
$N竟與自然化為一體，全身傷勢疾速復原。\n" + NOR,me);
          
          ekee=me->query("eff_kee");
          egin=me->query("eff_gin");
          esen=me->query("eff_sen");
          me->receive_curing("kee",900+(mkee-kee)/7);
          me->receive_heal("kee",900+(mkee-ekee)/7);
          me->receive_curing("gin",900+(mgin-gin)/5);
          me->receive_heal("gin",900+(mgin-egin)/5);
          me->receive_curing("sen",900+(msen-sen)/5);
          me->receive_heal("sen",900+(msen-esen)/5);
          COMBAT_D->report_status(me);
     }
  }
  if(me->is_busy() && !me->query_temp("unconcious"))
  {
message_vision(HIR + "$N潛運" + HIW + "ξ" + BRED+HIY + "本來無一物" + NOR + "" + HIW + "ξ" + HIR + "神功\，身形浮起，爆發無匹內勁掙脫束縛，
接著以閃電山莊的" + HIW + "ξ" + BRED+HIY + "閃電身法" + NOR + "" + HIW + "ξ" + HIR + "迅速脫離封鎖。\n" + NOR,me);
          me->delete_busy();
          if(me->is_fighting())
          {
           message_vision(HIG + "並且在電光石火間向每個人出招反擊!!\n" + NOR,me);
           for(j=0;j<i;j++)
           {
           if(target[j] && target[j]->is_character() && !target[j]->is_corpse() && room == environment(target[j])) 
           COMBAT_D->do_attack(me, target[j], me->query_temp("weapon"), TYPE_QUICK);
           }
          }
  }

}
}
if( !me->query_temp("hwa_je") )
	{
	set("class","prayer");
        set("family/family_name","聖火教");
	command("exert hwa_je");
	}
if( !me->query_temp("mixforce") )
	{
	set("class","prayer");
        set("family/family_name","聖火教");
	command("perform force.mixforce");
	}
if( !me->is_fighting() && !me->query_temp("secondary_weapon") )
	{
          set("class","blademan");
          set("family/family_name","金刀門");
          command("perform blade.mk-blade");
          command("wield all");
	  if( me->query("bellicosity") < 9000 )
	  {
	  me->set("bellicosity",9000);
	  }
	}
if( !me->is_fighting() && !me->query_temp("addblade") )
        {
        set("class","blademan");
        set("family/family_name","金刀門");
	command("addblade");
        command("losehurt");
	}
if( !me->is_fighting() && !me->query_temp("addbasic") )
	{
	set("class","blademan");
	set("family/family_name","金刀門");
	command("addbasic");
	command("powerup");
	}
me->clean_up_enemy();
set_heart_beat(1);
::heart_beat();
}

